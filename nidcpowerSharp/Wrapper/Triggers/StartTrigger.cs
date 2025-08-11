namespace nidcpowerSharp.Wrapper.Triggers
{
    /// <summary>
    /// Represents the start trigger configuration for a channel.
    /// </summary>
    public class StartTrigger
    {
        private readonly NiDCPowerChannel _channel;

        internal StartTrigger(NiDCPowerChannel channel)
        {
            _channel = channel;
        }

        /// <summary>
        /// Configures the start trigger to be a digital edge.
        /// </summary>
        /// <param name="inputTerminal">The input terminal for the digital edge. For example, "PXI_Trig0", "PXI_Trig1", etc.</param>
        /// <param name="edge">The edge on which to trigger.</param>
        public void ConfigureDigitalEdge(string inputTerminal, DigitalEdge edge)
        {
            _channel.Session.CheckStatus(NiDCPower.niDCPower_ConfigureDigitalEdgeStartTriggerWithChannels(_channel.Session.Handle, _channel.Name, inputTerminal, (int)edge));
        }

        /// <summary>
        /// Configures the start trigger to be a software command. The trigger will be sent by calling the <see cref="NiDCPowerChannel.SendSoftwareEdgeTrigger"/> method.
        /// </summary>
        public void ConfigureSoftwareEdge()
        {
            _channel.Session.CheckStatus(NiDCPower.niDCPower_ConfigureSoftwareEdgeStartTriggerWithChannels(_channel.Session.Handle, _channel.Name));
        }

        /// <summary>
        /// Disables the start trigger.
        /// </summary>
        public void Disable()
        {
            _channel.Session.CheckStatus(NiDCPower.niDCPower_DisableStartTriggerWithChannels(_channel.Session.Handle, _channel.Name));
        }

        /// <summary>
        /// Gets or sets the type of the start trigger.
        /// </summary>
        public TriggerType Type
        {
            get
            {
                _channel.Session.CheckStatus(NiDCPower.niDCPower_GetAttributeViInt32(_channel.Session.Handle, _channel.Name, NiDCPowerConstants.NIDCPOWER_ATTR_START_TRIGGER_TYPE, out int value));
                return (TriggerType)value;
            }
            set
            {
                _channel.Session.CheckStatus(NiDCPower.niDCPower_SetAttributeViInt32(_channel.Session.Handle, _channel.Name, NiDCPowerConstants.NIDCPOWER_ATTR_START_TRIGGER_TYPE, (int)value));
            }
        }
    }
}
