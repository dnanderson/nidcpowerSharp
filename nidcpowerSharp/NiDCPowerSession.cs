using System;
using System.Collections.Generic;
using System.Text;
using nidcpowerSharp.Wrapper;

namespace nidcpowerSharp
{
    /// <summary>
    /// Represents a session with an NI-DCPower instrument. This class is the entry point for interacting with the instrument.
    /// It handles the initialization and closing of the instrument session and provides access to the instrument's channels.
    /// </summary>
    public class NiDCPowerSession : IDisposable
    {
        private ViSession _handle;
        private bool _disposed;
        private readonly List<NiDCPowerChannel> _channels = new List<NiDCPowerChannel>();

        /// <summary>
        /// Gets the native handle for the session. This is intended for internal use by the wrapper.
        /// </summary>
        internal ViSession Handle => _handle;

        /// <summary>
        /// Gets the collection of channels available in this session.
        /// </summary>
        public IReadOnlyList<NiDCPowerChannel> Channels => _channels.AsReadOnly();

        /// <summary>
        /// Initializes a new session with the NI-DCPower instrument and creates channel objects for all specified channels.
        /// </summary>
        /// <param name="resourceName">
        /// The resource name of the instrument to initialize. You can get a list of available resources from NI-MAX.
        /// Example: "PXI1Slot2"
        /// </param>
        /// <param name="channels">
        /// The channel(s) to use for this session. This can be a comma-separated list of channel names or physical channel numbers.
        /// Specify null, an empty string, or "0" to initialize all channels on the instrument.
        /// Example: "0,1" or "Channel1,Channel2"
        /// </param>
        /// <param name="reset">Whether to reset the instrument during initialization.</param>
        /// <param name="optionString">
        /// An options string for configuring the session. The string has a comma-separated list of "Name=Value" pairs.
        /// Example: "Simulate=1, DriverSetup=Model:4141; BoardType:PXI"
        /// </param>
        public NiDCPowerSession(string resourceName, string channels, bool reset, string optionString = "")
        {
            var status = NiDCPower.niDCPower_InitializeWithChannels(resourceName, channels, reset ? IviBoolean.True : IviBoolean.False, optionString, out _handle);
            CheckStatus(status);

            PopulateChannels();
        }

        private void PopulateChannels()
        {
            CheckStatus(NiDCPower.niDCPower_GetAttributeViInt32(_handle, "", NiDCPowerConstants.NIDCPOWER_ATTR_CHANNEL_COUNT, out int channelCount));

            for (int i = 1; i <= channelCount; i++)
            {
                var channelNameBuilder = new StringBuilder(256);
                CheckStatus(NiDCPower.niDCPower_GetChannelName(_handle, i, channelNameBuilder.Capacity, channelNameBuilder));
                var channelName = channelNameBuilder.ToString();
                _channels.Add(new NiDCPowerChannel(this, channelName));
            }
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="NiDCPowerSession"/> class, ensuring the session is closed.
        /// </summary>
        ~NiDCPowerSession()
        {
            Dispose(false);
        }

        /// <summary>
        /// Releases the resources used by the session. This method closes the instrument session.
        /// </summary>
        public void Dispose()
        {
            Dispose(true);
            GC.SuppressFinalize(this);
        }

        /// <summary>
        /// Releases the unmanaged resources used by the <see cref="NiDCPowerSession"/>
        /// and optionally releases the managed resources.
        /// </summary>
        /// <param name="disposing">true to release both managed and unmanaged resources; false to release only unmanaged resources.</param>
        protected virtual void Dispose(bool disposing)
        {
            if (!_disposed)
            {
                if (disposing)
                {
                    // Dispose managed state (managed objects).
                }

                NiDCPower.niDCPower_close(_handle);
                _disposed = true;
            }
        }

        internal void CheckStatus(int status)
        {
            if (status < 0)
            {
                var errorBuilder = new StringBuilder(1024);
                NiDCPower.niDCPower_error_message(_handle, status, errorBuilder);
                throw new NiDCPowerException(status, errorBuilder.ToString());
            }
        }

        /// <summary>
        /// Applies previously configured settings for all channels in the session to the instrument.
        /// </summary>
        public void Commit()
        {
            CheckStatus(NiDCPower.niDCPower_Commit(Handle));
        }

        /// <summary>
        /// Starts the generation of power on all channels in the session.
        /// </summary>
        public void Initiate()
        {
            CheckStatus(NiDCPower.niDCPower_Initiate(Handle));
        }

        /// <summary>
        /// Stops the generation of power on all channels in the session.
        /// </summary>
        public void Abort()
        {
            CheckStatus(NiDCPower.niDCPower_Abort(Handle));
        }

        /// <summary>
        /// Gets or sets the power line frequency in Hertz. This property corresponds to the <see cref="NiDCPowerConstants.NIDCPOWER_ATTR_POWER_LINE_FREQUENCY"/> attribute.
        /// Common values are 50.0 or 60.0.
        /// </summary>
        public double PowerLineFrequency
        {
            get
            {
                CheckStatus(NiDCPower.niDCPower_GetAttributeViReal64(Handle, "", NiDCPowerConstants.NIDCPOWER_ATTR_POWER_LINE_FREQUENCY, out double value));
                return value;
            }
            set
            {
                CheckStatus(NiDCPower.niDCPower_SetAttributeViReal64(Handle, "", NiDCPowerConstants.NIDCPOWER_ATTR_POWER_LINE_FREQUENCY, value));
            }
        }
    }
}
