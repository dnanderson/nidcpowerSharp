using nidcpowerSharp.Wrapper;

namespace nidcpowerSharp
{
    /// <summary>
    /// Specifies the output function.
    /// </summary>
    public enum OutputFunction
    {
        /// <summary>
        /// The instrument sources a DC voltage.
        /// </summary>
        DCVoltage = NiDCPowerConstants.NIDCPOWER_VAL_DC_VOLTAGE,
        /// <summary>
        /// The instrument sources a DC current.
        /// </summary>
        DCCurrent = NiDCPowerConstants.NIDCPOWER_VAL_DC_CURRENT,
        /// <summary>
        /// The instrument sources a pulsed voltage.
        /// </summary>
        PulseVoltage = NiDCPowerConstants.NIDCPOWER_VAL_PULSE_VOLTAGE,
        /// <summary>
        /// The instrument sources a pulsed current.
        /// </summary>
        PulseCurrent = NiDCPowerConstants.NIDCPOWER_VAL_PULSE_CURRENT,
        /// <summary>
        /// The instrument operates as a constant resistance load.
        /// </summary>
        ConstantResistance = NiDCPowerConstants.NIDCPOWER_VAL_CONSTANT_RESISTANCE,
        /// <summary>
        /// The instrument operates as a constant power load.
        /// </summary>
        ConstantPower = NiDCPowerConstants.NIDCPOWER_VAL_CONSTANT_POWER
    }

    /// <summary>
    /// Specifies the source mode, which determines how the instrument generates output.
    /// </summary>
    public enum SourceMode
    {
        /// <summary>
        /// The instrument generates a single voltage or current level.
        /// </summary>
        SinglePoint = NiDCPowerConstants.NIDCPOWER_VAL_SINGLE_POINT,
        /// <summary>
        /// The instrument generates a sequence of voltage or current levels.
        /// </summary>
        Sequence = NiDCPowerConstants.NIDCPOWER_VAL_SEQUENCE
    }

    /// <summary>
    /// Specifies whether the instrument measures voltage at the output connectors (Local) or at the device under test (Remote).
    /// </summary>
    public enum Sense
    {
        /// <summary>
        /// Measures voltage at the output connectors.
        /// </summary>
        Local = NiDCPowerConstants.NIDCPOWER_VAL_LOCAL,
        /// <summary>
        /// Measures voltage at the device under test using remote sense connections.
        /// </summary>
        Remote = NiDCPowerConstants.NIDCPOWER_VAL_REMOTE
    }

    /// <summary>
    /// Specifies how the instrument behaves when the current limit is reached.
    /// </summary>
    public enum CurrentLimitBehavior
    {
        /// <summary>
        /// The output is clamped at the current limit, and the instrument operates in constant current mode.
        /// </summary>
        Regulate = NiDCPowerConstants.NIDCPOWER_VAL_CURRENT_REGULATE,
        /// <summary>
        /// The output is disabled when the current limit is reached.
        /// </summary>
        Trip = NiDCPowerConstants.NIDCPOWER_VAL_CURRENT_TRIP
    }

    /// <summary>
    /// Specifies the action to take when closing an external calibration session.
    /// </summary>
    public enum CalibrationAction
    {
        /// <summary>
        /// Discard any calibration adjustments made during the session.
        /// </summary>
        Cancel = NiDCPowerConstants.NIDCPOWER_VAL_CANCEL,
        /// <summary>
        /// Commit all calibration adjustments made during the session to the instrument's EEPROM.
        /// </summary>
        Commit = NiDCPowerConstants.NIDCPOWER_VAL_COMMIT
    }

    /// <summary>
    /// Specifies the units for the aperture time.
    /// </summary>
    public enum ApertureTimeUnits
    {
        /// <summary>
        /// Aperture time is specified in seconds.
        /// </summary>
        Seconds = NiDCPowerConstants.NIDCPOWER_VAL_SECONDS,
        /// <summary>
        /// Aperture time is specified in power line cycles.
        /// </summary>
        PowerLineCycles = NiDCPowerConstants.NIDCPOWER_VAL_POWER_LINE_CYCLES
    }

    /// <summary>
    /// Specifies the auto-zero mode.
    /// </summary>
    public enum AutoZero
    {
        /// <summary>
        /// Auto-zero is disabled.
        /// </summary>
        Off = NiDCPowerConstants.NIDCPOWER_VAL_OFF,
        /// <summary>
        /// Auto-zero is performed once before the first measurement.
        /// </summary>
        Once = NiDCPowerConstants.NIDCPOWER_VAL_ONCE,
        /// <summary>
        /// Auto-zero is performed before every measurement.
        /// </summary>
        On = NiDCPowerConstants.NIDCPOWER_VAL_ON
    }

    /// <summary>
    /// Specifies the type of measurement to perform.
    /// </summary>
    public enum MeasurementType
    {
        /// <summary>
        /// Measure voltage.
        /// </summary>
        Voltage = NiDCPowerConstants.NIDCPOWER_VAL_MEASURE_VOLTAGE,
        /// <summary>
        /// Measure current.
        /// </summary>
        Current = NiDCPowerConstants.NIDCPOWER_VAL_MEASURE_CURRENT
    }

    /// <summary>
    /// Specifies the type of trigger to configure.
    /// </summary>
    public enum TriggerType
    {
        /// <summary>
        /// No trigger is configured.
        /// </summary>
        None = NiDCPowerConstants.NIDCPOWER_VAL_NONE,
        /// <summary>
        /// The trigger is a digital edge on a physical line.
        /// </summary>
        DigitalEdge = NiDCPowerConstants.NIDCPOWER_VAL_DIGITAL_EDGE,
        /// <summary>
        /// The trigger is generated by a software command.
        /// </summary>
        SoftwareEdge = NiDCPowerConstants.NIDCPOWER_VAL_SOFTWARE_EDGE
    }

    /// <summary>
    /// Specifies the edge for a digital trigger.
    /// </summary>
    public enum DigitalEdge
    {
        /// <summary>
        /// Trigger on the rising edge.
        /// </summary>
        Rising = NiDCPowerConstants.NIDCPOWER_VAL_RISING,
        /// <summary>
        /// Trigger on the falling edge.
        /// </summary>
        Falling = NiDCPowerConstants.NIDCPOWER_VAL_FALLING
    }

    /// <summary>
    /// Specifies the event for which to wait.
    /// </summary>
    public enum EventId
    {
        /// <summary>
        /// The source engine has completed its operation.
        /// </summary>
        SourceComplete = NiDCPowerConstants.NIDCPOWER_VAL_SOURCE_COMPLETE_EVENT,
        /// <summary>
        /// The measure engine has completed its operation.
        /// </summary>
        MeasureComplete = NiDCPowerConstants.NIDCPOWER_VAL_MEASURE_COMPLETE_EVENT,
        /// <summary>
        /// The sequence engine has completed one iteration.
        /// </summary>
        SequenceIterationComplete = NiDCPowerConstants.NIDCPOWER_VAL_SEQUENCE_ITERATION_COMPLETE_EVENT,
        /// <summary>
        /// The sequence engine has completed its entire operation.
        /// </summary>
        SequenceEngineDone = NiDCPowerConstants.NIDCPOWER_VAL_SEQUENCE_ENGINE_DONE_EVENT,
        /// <summary>
        /// The pulse has completed.
        /// </summary>
        PulseComplete = NiDCPowerConstants.NIDCPOWER_VAL_PULSE_COMPLETE_EVENT,
        /// <summary>
        /// The instrument is ready to receive a pulse trigger.
        /// </summary>
        ReadyForPulseTrigger = NiDCPowerConstants.NIDCPOWER_VAL_READY_FOR_PULSE_TRIGGER_EVENT
    }

    /// <summary>
    /// Specifies the software trigger to send.
    /// </summary>
    public enum SoftwareTrigger
    {
        /// <summary>
        /// Sends a start trigger.
        /// </summary>
        Start = NiDCPowerConstants.NIDCPOWER_VAL_START_TRIGGER,
        /// <summary>
        /// Sends a source trigger.
        /// </summary>
        Source = NiDCPowerConstants.NIDCPOWER_VAL_SOURCE_TRIGGER,
        /// <summary>
        /// Sends a measure trigger.
        /// </summary>
        Measure = NiDCPowerConstants.NIDCPOWER_VAL_MEASURE_TRIGGER,
        /// <summary>
        /// Sends a sequence advance trigger.
        /// </summary>
        SequenceAdvance = NiDCPowerConstants.NIDCPOWER_VAL_SEQUENCE_ADVANCE_TRIGGER,
        /// <summary>
        /// Sends a pulse trigger.
        /// </summary>
        Pulse = NiDCPowerConstants.NIDCPOWER_VAL_PULSE_TRIGGER,
        /// <summary>
        /// Sends a shutdown trigger.
        /// </summary>
        Shutdown = NiDCPowerConstants.NIDCPOWER_VAL_SHUTDOWN_TRIGGER
    }
}
