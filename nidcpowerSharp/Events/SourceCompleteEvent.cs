using nidcpowerSharp.Wrapper;

namespace nidcpowerSharp.Events
{
    /// <summary>
    /// Represents the configuration for the Source Complete event.
    /// </summary>
    public class SourceCompleteEvent
    {
        private readonly NiDCPowerChannel _channel;

        internal SourceCompleteEvent(NiDCPowerChannel channel)
        {
            _channel = channel;
        }

        /// <summary>
        /// Gets or sets the terminal to which the Source Complete event is exported.
        /// </summary>
        public string OutputTerminal
        {
            get
            {
                var value = new System.Text.StringBuilder(256);
                _channel.Session.CheckStatus(NiDCPower.niDCPower_GetAttributeViString(_channel.Session.Handle, _channel.Name, NiDCPowerConstants.NIDCPOWER_ATTR_SOURCE_COMPLETE_EVENT_OUTPUT_TERMINAL, value.Capacity, value));
                return value.ToString();
            }
            set
            {
                _channel.Session.CheckStatus(NiDCPower.niDCPower_SetAttributeViString(_channel.Session.Handle, _channel.Name, NiDCPowerConstants.NIDCPOWER_ATTR_SOURCE_COMPLETE_EVENT_OUTPUT_TERMINAL, value));
            }
        }
    }
}
