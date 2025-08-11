namespace nidcpowerSharp.Wrapper.Triggers
{
    /// <summary>
    /// Provides access to the various trigger configurations for a channel.
    /// </summary>
    public class TriggerCollection
    {
        internal TriggerCollection(NiDCPowerChannel channel)
        {
            Start = new StartTrigger(channel);
            Source = new SourceTrigger(channel);
            // Other trigger types can be initialized here
        }

        /// <summary>
        /// Gets the start trigger configuration. The start trigger is used to begin a measurement or generation.
        /// </summary>
        public StartTrigger Start { get; }

        /// <summary>
        /// Gets the source trigger configuration. The source trigger is used to transition from one source value to the next in a sequence.
        /// </summary>
        public SourceTrigger Source { get; }
    }
}
