namespace nidcpowerSharp.Wrapper.Events
{
    /// <summary>
    /// Provides access to the various event configurations for a channel.
    /// </summary>
    public class EventCollection
    {
        internal EventCollection(NiDCPowerChannel channel)
        {
            SourceComplete = new SourceCompleteEvent(channel);
            // Other event types can be initialized here
        }

        /// <summary>
        /// Gets the Source Complete event configuration. This event is generated when the source unit has settled at its new output level.
        /// </summary>
        public SourceCompleteEvent SourceComplete { get; }
    }
}
