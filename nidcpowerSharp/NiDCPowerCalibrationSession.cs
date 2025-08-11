using System;
using System.Text;
using nidcpowerSharp.Wrapper;

namespace nidcpowerSharp
{
    /// <summary>
    /// Represents an external calibration session with an NI-DCPower instrument.
    /// This class provides methods to adjust the calibration of the instrument.
    /// The session must be closed by calling Dispose() or CommitAndDispose().
    /// </summary>
    public class NiDCPowerCalibrationSession : IDisposable
    {
        private ViSession _handle;
        private bool _disposed;

        /// <summary>
        /// Gets the native handle for the session. This is intended for internal use by the wrapper.
        /// </summary>
        internal ViSession Handle => _handle;

        /// <summary>
        /// Initializes a new external calibration session with the NI-DCPower instrument.
        /// </summary>
        /// <param name="resourceName">The resource name of the instrument to calibrate.</param>
        /// <param name="password">The password required to open a calibration session.</param>
        public NiDCPowerCalibrationSession(string resourceName, string password)
        {
            var status = NiDCPower.niDCPower_InitExtCal(resourceName, password, out _handle);
            CheckStatus(status);
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="NiDCPowerCalibrationSession"/> class.
        /// </summary>
        ~NiDCPowerCalibrationSession()
        {
            Dispose(false);
        }

        /// <summary>
        /// Closes the calibration session and discards any calibration adjustments made during the session.
        /// To save adjustments, call <see cref="CommitAndDispose"/> instead.
        /// </summary>
        public void Dispose()
        {
            Dispose(true);
            GC.SuppressFinalize(this);
        }

        protected virtual void Dispose(bool disposing)
        {
            if (!_disposed)
            {
                if (disposing)
                {
                    // Dispose managed state (managed objects).
                }

                // Default action is to cancel calibration on dispose.
                // We don't check status here because Dispose should not throw exceptions.
                NiDCPower.niDCPower_CloseExtCal(Handle, (int)CalibrationAction.Cancel);
                _disposed = true;
            }
        }

        /// <summary>
        /// Commits all calibration adjustments to the instrument's EEPROM and closes the session.
        /// </summary>
        public void CommitAndDispose()
        {
            if (!_disposed)
            {
                CheckStatus(NiDCPower.niDCPower_CloseExtCal(Handle, (int)CalibrationAction.Commit));
                _disposed = true;
                GC.SuppressFinalize(this);
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
        /// Adjusts the DC voltage level calibration for a specific range.
        /// </summary>
        /// <param name="channelName">The name of the channel to calibrate.</param>
        /// <param name="range">The voltage range to calibrate, in volts.</param>
        /// <param name="requestedOutputs">An array of requested voltage levels.</param>
        /// <param name="measuredOutputs">An array of corresponding measured voltage levels.</param>
        public void CalAdjustVoltageLevel(string channelName, double range, double[] requestedOutputs, double[] measuredOutputs)
        {
            if (requestedOutputs.Length != measuredOutputs.Length)
            {
                throw new ArgumentException("The number of requested outputs must match the number of measured outputs.");
            }
            CheckStatus(NiDCPower.niDCPower_CalAdjustVoltageLevel(Handle, channelName, range, (uint)requestedOutputs.Length, requestedOutputs, measuredOutputs));
        }

        /// <summary>
        /// Adjusts the current limit calibration for a specific range.
        /// </summary>
        /// <param name="channelName">The name of the channel to calibrate.</param>
        /// <param name="range">The current range to calibrate, in amps.</param>
        /// <param name="requestedOutputs">An array of requested current limits.</param>
        /// <param name="measuredOutputs">An array of corresponding measured current limits.</param>
        public void CalAdjustCurrentLimit(string channelName, double range, double[] requestedOutputs, double[] measuredOutputs)
        {
            if (requestedOutputs.Length != measuredOutputs.Length)
            {
                throw new ArgumentException("The number of requested outputs must match the number of measured outputs.");
            }
            CheckStatus(NiDCPower.niDCPower_CalAdjustCurrentLimit(Handle, channelName, range, (uint)requestedOutputs.Length, requestedOutputs, measuredOutputs));
        }
    }
}
