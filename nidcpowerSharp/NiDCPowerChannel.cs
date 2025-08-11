using System;
using nidcpowerSharp.Events;
using nidcpowerSharp.Triggers;
using nidcpowerSharp.Wrapper;

namespace nidcpowerSharp
{
    /// <summary>
    /// Represents a single channel on an NI-DCPower instrument. This class provides methods and properties for controlling a specific channel.
    /// </summary>
    public class NiDCPowerChannel
    {
        internal NiDCPowerSession Session { get; }
        internal string Name { get; }

        /// <summary>
        /// Gets the trigger configurations for this channel.
        /// </summary>
        public TriggerCollection Triggers { get; }

        /// <summary>
        /// Gets the event configurations for this channel.
        /// </summary>
        public EventCollection Events { get; }

        internal NiDCPowerChannel(NiDCPowerSession session, string channelName)
        {
            Session = session;
            Name = channelName;
            Triggers = new TriggerCollection(this);
            Events = new EventCollection(this);
        }

        /// <summary>
        /// Gets or sets the voltage level for the channel in volts. This property corresponds to the <see cref="NiDCPowerConstants.NIDCPOWER_ATTR_VOLTAGE_LEVEL"/> attribute.
        /// </summary>
        public double VoltageLevel
        {
            get
            {
                Session.CheckStatus(NiDCPower.niDCPower_GetAttributeViReal64(Session.Handle, Name, NiDCPowerConstants.NIDCPOWER_ATTR_VOLTAGE_LEVEL, out double value));
                return value;
            }
            set
            {
                Session.CheckStatus(NiDCPower.niDCPower_SetAttributeViReal64(Session.Handle, Name, NiDCPowerConstants.NIDCPOWER_ATTR_VOLTAGE_LEVEL, value));
            }
        }

        /// <summary>
        /// Gets or sets whether the output is enabled. This property corresponds to the <see cref="NiDCPowerConstants.NIDCPOWER_ATTR_OUTPUT_ENABLED"/> attribute.
        /// </summary>
        public bool OutputEnabled
        {
            get
            {
                Session.CheckStatus(NiDCPower.niDCPower_GetAttributeViBoolean(Session.Handle, Name, NiDCPowerConstants.NIDCPOWER_ATTR_OUTPUT_ENABLED, out ushort value));
                return value == IviBoolean.True;
            }
            set
            {
                Session.CheckStatus(NiDCPower.niDCPower_SetAttributeViBoolean(Session.Handle, Name, NiDCPowerConstants.NIDCPOWER_ATTR_OUTPUT_ENABLED, value ? IviBoolean.True : IviBoolean.False));
            }
        }

        /// <summary>
        /// Configures the voltage level that the instrument attempts to generate on the specified channel.
        /// </summary>
        /// <param name="level">The voltage level, in volts, that the instrument attempts to generate.</param>
        public void ConfigureVoltageLevel(double level)
        {
            Session.CheckStatus(NiDCPower.niDCPower_ConfigureVoltageLevel(Session.Handle, Name, level));
        }

        /// <summary>
        /// Enables or disables the output of the specified channel.
        /// </summary>
        /// <param name="enabled">Specify true to enable the output, or false to disable the output.</param>
        public void ConfigureOutputEnabled(bool enabled)
        {
            Session.CheckStatus(NiDCPower.niDCPower_ConfigureOutputEnabled(Session.Handle, Name, enabled ? IviBoolean.True : IviBoolean.False));
        }

        /// <summary>
        /// Gets or sets the output function. This property corresponds to the <see cref="NiDCPowerConstants.NIDCPOWER_ATTR_OUTPUT_FUNCTION"/> attribute.
        /// </summary>
        public OutputFunction OutputFunction
        {
            get
            {
                Session.CheckStatus(NiDCPower.niDCPower_GetAttributeViInt32(Session.Handle, Name, NiDCPowerConstants.NIDCPOWER_ATTR_OUTPUT_FUNCTION, out int value));
                return (OutputFunction)value;
            }
            set
            {
                Session.CheckStatus(NiDCPower.niDCPower_SetAttributeViInt32(Session.Handle, Name, NiDCPowerConstants.NIDCPOWER_ATTR_OUTPUT_FUNCTION, (int)value));
            }
        }

        /// <summary>
        /// Gets or sets the source mode. This property corresponds to the <see cref="NiDCPowerConstants.NIDCPOWER_ATTR_SOURCE_MODE"/> attribute.
        /// </summary>
        public SourceMode SourceMode
        {
            get
            {
                Session.CheckStatus(NiDCPower.niDCPower_GetAttributeViInt32(Session.Handle, Name, NiDCPowerConstants.NIDCPOWER_ATTR_SOURCE_MODE, out int value));
                return (SourceMode)value;
            }
            set
            {
                Session.CheckStatus(NiDCPower.niDCPower_SetAttributeViInt32(Session.Handle, Name, NiDCPowerConstants.NIDCPOWER_ATTR_SOURCE_MODE, (int)value));
            }
        }

        /// <summary>
        /// Gets or sets the sense setting. This property corresponds to the <see cref="NiDCPowerConstants.NIDCPOWER_ATTR_SENSE"/> attribute.
        /// </summary>
        public Sense Sense
        {
            get
            {
                Session.CheckStatus(NiDCPower.niDCPower_GetAttributeViInt32(Session.Handle, Name, NiDCPowerConstants.NIDCPOWER_ATTR_SENSE, out int value));
                return (Sense)value;
            }
            set
            {
                Session.CheckStatus(NiDCPower.niDCPower_SetAttributeViInt32(Session.Handle, Name, NiDCPowerConstants.NIDCPOWER_ATTR_SENSE, (int)value));
            }
        }

        /// <summary>
        /// Gets or sets the current limit in amps. This property corresponds to the <see cref="NiDCPowerConstants.NIDCPOWER_ATTR_CURRENT_LIMIT"/> attribute.
        /// </summary>
        public double CurrentLimit
        {
            get
            {
                Session.CheckStatus(NiDCPower.niDCPower_GetAttributeViReal64(Session.Handle, Name, NiDCPowerConstants.NIDCPOWER_ATTR_CURRENT_LIMIT, out double value));
                return value;
            }
            set
            {
                Session.CheckStatus(NiDCPower.niDCPower_SetAttributeViReal64(Session.Handle, Name, NiDCPowerConstants.NIDCPOWER_ATTR_CURRENT_LIMIT, value));
            }
        }

        /// <summary>
        /// Configures the current limit that the instrument enforces on the specified channel.
        /// </summary>
        /// <param name="behavior">The behavior of the output when the current limit is reached. See <see cref="CurrentLimitBehavior"/> for details.</param>
        /// <param name="limit">The current limit in amps.</param>
        public void ConfigureCurrentLimit(CurrentLimitBehavior behavior, double limit)
        {
            Session.CheckStatus(NiDCPower.niDCPower_ConfigureCurrentLimit(Session.Handle, Name, (int)behavior, limit));
        }

        /// <summary>
        /// Applies previously configured settings for this channel to the instrument.
        /// </summary>
        public void Commit()
        {
            Session.CheckStatus(NiDCPower.niDCPower_CommitWithChannels(Session.Handle, Name));
        }

        /// <summary>
        /// Starts the generation of power on this channel.
        /// </summary>
        public void Initiate()
        {
            Session.CheckStatus(NiDCPower.niDCPower_InitiateWithChannels(Session.Handle, Name));
        }

        /// <summary>
        /// Stops the generation of power on this channel.
        /// </summary>
        public void Abort()
        {
            Session.CheckStatus(NiDCPower.niDCPower_AbortWithChannels(Session.Handle, Name));
        }

        /// <summary>
        /// Performs a self-calibration on the channel. Self-calibration adjusts the instrument for temperature variations and minimizes measurement error.
        /// It is recommended to perform a self-calibration whenever the temperature changes by more than a few degrees Celsius.
        /// </summary>
        public void CalibrateSelf()
        {
            Session.CheckStatus(NiDCPower.niDCPower_CalSelfCalibrate(Session.Handle, Name));
        }

        /// <summary>
        /// Gets or sets the number of samples to average for each measurement. This property corresponds to the <see cref="NiDCPowerConstants.NIDCPOWER_ATTR_SAMPLES_TO_AVERAGE"/> attribute.
        /// </summary>
        public int SamplesToAverage
        {
            get
            {
                Session.CheckStatus(NiDCPower.niDCPower_GetAttributeViInt32(Session.Handle, Name, NiDCPowerConstants.NIDCPOWER_ATTR_SAMPLES_TO_AVERAGE, out int value));
                return value;
            }
            set
            {
                Session.CheckStatus(NiDCPower.niDCPower_SetAttributeViInt32(Session.Handle, Name, NiDCPowerConstants.NIDCPOWER_ATTR_SAMPLES_TO_AVERAGE, value));
            }
        }

        /// <summary>
        /// Gets or sets the auto-zero mode. This property corresponds to the <see cref="NiDCPowerConstants.NIDCPOWER_ATTR_AUTO_ZERO"/> attribute.
        /// </summary>
        public AutoZero AutoZero
        {
            get
            {
                Session.CheckStatus(NiDCPower.niDCPower_GetAttributeViInt32(Session.Handle, Name, NiDCPowerConstants.NIDCPOWER_ATTR_AUTO_ZERO, out int value));
                return (AutoZero)value;
            }
            set
            {
                Session.CheckStatus(NiDCPower.niDCPower_SetAttributeViInt32(Session.Handle, Name, NiDCPowerConstants.NIDCPOWER_ATTR_AUTO_ZERO, (int)value));
            }
        }

        /// <summary>
        /// Configures the aperture time for measurements on the specified channel.
        /// </summary>
        /// <param name="apertureTime">The aperture time. The units are specified in the <paramref name="units"/> parameter.</param>
        /// <param name="units">The units for the aperture time. See <see cref="ApertureTimeUnits"/> for values.</param>
        public void ConfigureApertureTime(double apertureTime, ApertureTimeUnits units)
        {
            Session.CheckStatus(NiDCPower.niDCPower_ConfigureApertureTime(Session.Handle, Name, apertureTime, (int)units));
        }

        /// <summary>
        /// Gets or sets the measure record length. This determines how many measurements are taken when MeasureMultiple is called.
        /// This property corresponds to the <see cref="NiDCPowerConstants.NIDCPOWER_ATTR_MEASURE_RECORD_LENGTH"/> attribute.
        /// </summary>
        public int MeasureRecordLength
        {
            get
            {
                Session.CheckStatus(NiDCPower.niDCPower_GetAttributeViInt32(Session.Handle, Name, NiDCPowerConstants.NIDCPOWER_ATTR_MEASURE_RECORD_LENGTH, out int value));
                return value;
            }
            set
            {
                Session.CheckStatus(NiDCPower.niDCPower_SetAttributeViInt32(Session.Handle, Name, NiDCPowerConstants.NIDCPOWER_ATTR_MEASURE_RECORD_LENGTH, value));
            }
        }

        /// <summary>
        /// Gets or sets whether the measure record length is finite.
        /// This property corresponds to the <see cref="NiDCPowerConstants.NIDCPOWER_ATTR_MEASURE_RECORD_LENGTH_IS_FINITE"/> attribute.
        /// </summary>
        public bool MeasureRecordLengthIsFinite
        {
            get
            {
                Session.CheckStatus(NiDCPower.niDCPower_GetAttributeViBoolean(Session.Handle, Name, NiDCPowerConstants.NIDCPOWER_ATTR_MEASURE_RECORD_LENGTH_IS_FINITE, out ushort value));
                return value == IviBoolean.True;
            }
            set
            {
                Session.CheckStatus(NiDCPower.niDCPower_SetAttributeViBoolean(Session.Handle, Name, NiDCPowerConstants.NIDCPOWER_ATTR_MEASURE_RECORD_LENGTH_IS_FINITE, value ? IviBoolean.True : IviBoolean.False));
            }
        }

        /// <summary>
        /// Performs a single measurement on the channel.
        /// </summary>
        /// <param name="measurementType">The type of measurement to perform (Voltage or Current).</param>
        /// <returns>The measured value.</returns>
        public double Measure(MeasurementType measurementType)
        {
            Session.CheckStatus(NiDCPower.niDCPower_Measure(Session.Handle, Name, (int)measurementType, out double measurement));
            return measurement;
        }

        /// <summary>
        /// Acquires and returns multiple measurements of voltage and current. The number of measurements is determined by the <see cref="MeasureRecordLength"/> property.
        /// </summary>
        /// <returns>A tuple containing arrays of voltage and current measurements.</returns>
        public (double[] voltage, double[] current) MeasureMultiple()
        {
            Session.CheckStatus(NiDCPower.niDCPower_GetAttributeViInt32(Session.Handle, Name, NiDCPowerConstants.NIDCPOWER_ATTR_MEASURE_RECORD_LENGTH, out int recordLength));

            var voltageMeasurements = new double[recordLength];
            var currentMeasurements = new double[recordLength];

            Session.CheckStatus(NiDCPower.niDCPower_MeasureMultiple(Session.Handle, Name, voltageMeasurements, currentMeasurements));

            return (voltageMeasurements, currentMeasurements);
        }

        /// <summary>
        /// Fetches multiple measurements that were previously acquired.
        /// </summary>
        /// <param name="timeout">The maximum time to wait for measurements to be available.</param>
        /// <param name="count">The number of measurements to fetch.</param>
        /// <returns>A tuple containing arrays of voltage measurements, current measurements, compliance status, and the actual number of measurements fetched.</returns>
        public (double[] voltage, double[] current, bool[] inCompliance, int actualCount) FetchMultiple(TimeSpan timeout, int count)
        {
            var voltageMeasurements = new double[count];
            var currentMeasurements = new double[count];
            var inComplianceUshort = new ushort[count];

            Session.CheckStatus(NiDCPower.niDCPower_FetchMultiple(Session.Handle, Name, timeout.TotalSeconds, count, voltageMeasurements, currentMeasurements, inComplianceUshort, out int actualCount));

            var inComplianceBool = new bool[actualCount];
            for (int i = 0; i < actualCount; i++)
            {
                inComplianceBool[i] = inComplianceUshort[i] == IviBoolean.True;
            }

            if (actualCount < count)
            {
                Array.Resize(ref voltageMeasurements, actualCount);
                Array.Resize(ref currentMeasurements, actualCount);
            }

            return (voltageMeasurements, currentMeasurements, inComplianceBool, actualCount);
        }

        /// <summary>
        /// Acquires and returns multiple LCR measurements. The number of measurements is determined by the <see cref="MeasureRecordLength"/> property.
        /// This functionality is only available on instruments that support LCR measurements.
        /// </summary>
        /// <returns>An array of LCR measurements.</returns>
        public NILCRMeasurement[] MeasureMultipleLCR()
        {
            Session.CheckStatus(NiDCPower.niDCPower_GetAttributeViInt32(Session.Handle, Name, NiDCPowerConstants.NIDCPOWER_ATTR_MEASURE_RECORD_LENGTH, out int recordLength));

            var measurements = new NILCRMeasurement[recordLength];
            Session.CheckStatus(NiDCPower.niDCPower_MeasureMultipleLCR(Session.Handle, Name, measurements));

            return measurements;
        }

        /// <summary>
        /// Fetches multiple LCR measurements that were previously acquired.
        /// This functionality is only available on instruments that support LCR measurements.
        /// </summary>
        /// <param name="timeout">The maximum time to wait for measurements to be available.</param>
        /// <param name="count">The number of measurements to fetch.</param>
        /// <returns>A tuple containing an array of LCR measurements and the actual number of measurements fetched.</returns>
        public (NILCRMeasurement[] measurements, int actualCount) FetchMultipleLCR(TimeSpan timeout, int count)
        {
            var measurements = new NILCRMeasurement[count];
            Session.CheckStatus(NiDCPower.niDCPower_FetchMultipleLCR(Session.Handle, Name, timeout.TotalSeconds, count, measurements, out int actualCount));

            if (actualCount < count)
            {
                Array.Resize(ref measurements, actualCount);
            }

            return (measurements, actualCount);
        }

        /// <summary>
        /// Sends a software-edge trigger.
        /// </summary>
        /// <param name="trigger">The type of software trigger to send.</param>
        public void SendSoftwareEdgeTrigger(SoftwareTrigger trigger)
        {
            Session.CheckStatus(NiDCPower.niDCPower_SendSoftwareEdgeTriggerWithChannels(Session.Handle, Name, (int)trigger));
        }

        /// <summary>
        /// Waits for a specific event to be generated.
        /// </summary>
        /// <param name="eventId">The ID of the event to wait for.</param>
        /// <param name="timeout">The maximum time to wait for the event.</param>
        public void WaitForEvent(EventId eventId, TimeSpan timeout)
        {
            Session.CheckStatus(NiDCPower.niDCPower_WaitForEventWithChannels(Session.Handle, Name, (int)eventId, timeout.TotalSeconds));
        }
    }
}
