using System;
using System.Runtime.InteropServices;
using System.Text;

namespace nidcpowerSharp
{
    public static partial class NiDCPower
    {
        private const string DllName = "nidcpower_64.dll";

        #region Initialize/Close

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_InitializeWithChannels(string resourceName, string channels, ushort reset, string optionString, out ViSession vi);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_InitializeWithIndependentChannels(string resourceName, ushort reset, string optionString, out ViSession vi);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_close(ViSession vi);

        #endregion

        #region Source

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ConfigureSourceMode(ViSession vi, int sourceMode);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ConfigureSourceModeWithChannels(ViSession vi, string channelName, int sourceMode);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ConfigureOutputFunction(ViSession vi, string channelName, int function);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ConfigureOutputEnabled(ViSession vi, string channelName, ushort enabled);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_SetSequence(ViSession vi, string channelName, ReadOnlySpan<double> values, ReadOnlySpan<double> sourceDelays, uint size);

        #endregion

        #region Source::DC Voltage

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ConfigureVoltageLevel(ViSession vi, string channelName, double level);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ConfigureCurrentLimit(ViSession vi, string channelName, int behavior, double limit);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ConfigureVoltageLevelRange(ViSession vi, string channelName, double range);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ConfigureCurrentLimitRange(ViSession vi, string channelName, double range);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ConfigureOutputResistance(ViSession vi, string channelName, double resistance);

        #endregion

        #region Source::DC Current

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ConfigureCurrentLevel(ViSession vi, string channelName, double level);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ConfigureCurrentLevelRange(ViSession vi, string channelName, double range);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ConfigureVoltageLimit(ViSession vi, string channelName, double limit);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ConfigureVoltageLimitRange(ViSession vi, string channelName, double range);

        #endregion

        #region Source::Pulse Voltage

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ConfigurePulseVoltageLevel(ViSession vi, string channelName, double level);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ConfigurePulseCurrentLimit(ViSession vi, string channelName, double limit);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ConfigurePulseBiasVoltageLevel(ViSession vi, string channelName, double level);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ConfigurePulseBiasCurrentLimit(ViSession vi, string channelName, double limit);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ConfigurePulseVoltageLevelRange(ViSession vi, string channelName, double range);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ConfigurePulseCurrentLimitRange(ViSession vi, string channelName, double range);

        #endregion

        #region Source::Pulse Current

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ConfigurePulseCurrentLevel(ViSession vi, string channelName, double level);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ConfigurePulseVoltageLimit(ViSession vi, string channelName, double limit);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ConfigurePulseBiasCurrentLevel(ViSession vi, string channelName, double level);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ConfigurePulseBiasVoltageLimit(ViSession vi, string channelName, double limit);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ConfigurePulseCurrentLevelRange(ViSession vi, string channelName, double range);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ConfigurePulseVoltageLimitRange(ViSession vi, string channelName, double range);

        #endregion

        #region Source::Advanced Sequencing

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_CreateAdvancedSequence(ViSession vi, string sequenceName, int attributeIdCount, ReadOnlySpan<int> attributeIds, ushort setAsActiveSequence);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_CreateAdvancedSequenceWithChannels(ViSession vi, string channelName, string sequenceName, int attributeIdCount, ReadOnlySpan<int> attributeIds, ushort setAsActiveSequence);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_CreateAdvancedSequenceStep(ViSession vi, ushort setAsActiveStep);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_CreateAdvancedSequenceStepWithChannels(ViSession vi, string channelName, ushort setAsActiveStep);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_CreateAdvancedSequenceCommitStepWithChannels(ViSession vi, string channelName, ushort setAsActiveStep);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_DeleteAdvancedSequence(ViSession vi, string sequenceName);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_DeleteAdvancedSequenceWithChannels(ViSession vi, string channelName, string sequenceName);

        #endregion

        #region Measure

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ConfigureApertureTime(ViSession vi, string channelName, double apertureTime, int units);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ConfigureAutoZero(ViSession vi, string channelName, int autoZero);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ConfigurePowerLineFrequency(ViSession vi, double powerlineFrequency);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ConfigureSense(ViSession vi, string channelName, int sense);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_Measure(ViSession vi, string channelName, int measurementType, out double measurement);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_MeasureMultiple(ViSession vi, string channelName, Span<double> voltageMeasurements, Span<double> currentMeasurements);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_FetchMultiple(ViSession vi, string channelName, double timeout, int count, Span<double> voltageMeasurements, Span<double> currentMeasurements, Span<ushort> inCompliance, out int actualCount);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_MeasureMultipleLCR(ViSession vi, string channelName, Span<NILCRMeasurement> measurements);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_FetchMultipleLCR(ViSession vi, string channelName, double timeout, int count, Span<NILCRMeasurement> measurements, out int actualCount);

        #endregion

        #region Query

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_QueryInCompliance(ViSession vi, string channelName, out ushort inCompliance);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_QueryOutputState(ViSession vi, string channelName, int outputState, out ushort inState);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_QueryLatchedOutputCutoffState(ViSession vi, string channelName, int outputCutoffReason, out ushort outputCutoffState);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ClearLatchedOutputCutoffState(ViSession vi, string channelName, int outputCutoffReason);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_QueryMaxCurrentLimit(ViSession vi, string channelName, double voltageLevel, out double maxCurrentLimit);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_QueryMaxVoltageLevel(ViSession vi, string channelName, double currentLimit, out double maxVoltageLevel);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_QueryMinCurrentLimit(ViSession vi, string channelName, double voltageLevel, out double minCurrentLimit);

        #endregion

        #region Control

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_Commit(ViSession vi);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_CommitWithChannels(ViSession vi, string channelName);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_Initiate(ViSession vi);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_InitiateWithChannels(ViSession vi, string channelName);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_Abort(ViSession vi);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_AbortWithChannels(ViSession vi, string channelName);

        #endregion

        #region Calibration::External Calibration

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_InitExtCal(string resourceName, string password, out ViSession vi);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_CloseExtCal(ViSession vi, int action);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_CalAdjustVoltageLevel(ViSession vi, string channelName, double range, uint numberOfMeasurements, ReadOnlySpan<double> requestedOutputs, ReadOnlySpan<double> measuredOutputs);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_CalAdjustVoltageMeasurement(ViSession vi, string channelName, double range, uint numberOfMeasurements, ReadOnlySpan<double> reportedOutputs, ReadOnlySpan<double> measuredOutputs);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_CalAdjustCurrentLimit(ViSession vi, string channelName, double range, uint numberOfMeasurements, ReadOnlySpan<double> requestedOutputs, ReadOnlySpan<double> measuredOutputs);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_CalAdjustCurrentMeasurement(ViSession vi, string channelName, double range, uint numberOfMeasurements, ReadOnlySpan<double> reportedOutputs, ReadOnlySpan<double> measuredOutputs);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_CalAdjustOutputResistance(ViSession vi, string channelName, uint numberOfMeasurements, ReadOnlySpan<double> requestedOutputs, ReadOnlySpan<double> measuredOutputs);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_CalAdjustResidualVoltageOffset(ViSession vi, string channelName);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_CalAdjustResidualCurrentOffset(ViSession vi, string channelName);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ConnectInternalReference(ViSession vi, int internalReference);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_CalAdjustInternalReference(ViSession vi, int internalReference, double adjustedInternalReference);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_CalBeginACFlatness(ViSession vi, string channelName, out uint totalNumberOfSteps);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_CalConfigACFlatness(ViSession vi, string channelName, out double generatedFrequency, out double generatedVoltageRMS);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_CalAdjustACFlatness(ViSession vi, string channelName, double generatedFrequency, double generatedVoltageRMS, double measuredVoltageRMS, out uint numberOfStepsRemaining);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_CalEndACFlatness(ViSession vi, string channelName);

        #endregion

        #region Calibration

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_CalSelfCalibrate(ViSession vi, string channelName);

        #endregion

        #region Calibration::Calibration Utility

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ChangeExtCalPassword(ViSession vi, string oldPassword, string newPassword);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_GetExtCalRecommendedInterval(ViSession vi, out int months);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_GetExtCalLastDateAndTime(ViSession vi, out int year, out int month, out int day, out int hour, out int minute);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_GetCalUserDefinedInfoMaxSize(ViSession vi, out int infoSize);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_SetCalUserDefinedInfo(ViSession vi, string info);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_GetCalUserDefinedInfo(ViSession vi, StringBuilder info);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ReadCurrentTemperature(ViSession vi, out double temperature);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_GetExtCalLastTemp(ViSession vi, out double temperature);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_GetSelfCalLastDateAndTime(ViSession vi, out int year, out int month, out int day, out int hour, out int minute);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_GetSelfCalLastTemp(ViSession vi, out double temperature);

        #endregion

        #region Calibration::LCR Compensation

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_GetLCRCompensationLastDateAndTime(ViSession vi, string channelName, int compensationType, out int year, out int month, out int day, out int hour, out int minute);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_PerformLCROpenCompensation(ViSession vi, string channelName, int numFrequencies, ReadOnlySpan<double> additionalFrequencies);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_PerformLCRShortCompensation(ViSession vi, string channelName, int numFrequencies, ReadOnlySpan<double> additionalFrequencies);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_PerformLCRLoadCompensation(ViSession vi, string channelName, int numCompensationSpots, ReadOnlySpan<NILCRLoadCompensationSpot> compensationSpots);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ConfigureLCRCompensation(ViSession vi, string channelName, int compensationDataSize, IntPtr compensationData);

        #endregion

        #region Triggers and Events

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ConfigureDigitalEdgeStartTrigger(ViSession vi, string inputTerminal, int edge);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ConfigureDigitalEdgeStartTriggerWithChannels(ViSession vi, string channelName, string inputTerminal, int edge);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ConfigureSoftwareEdgeStartTrigger(ViSession vi);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ConfigureSoftwareEdgeStartTriggerWithChannels(ViSession vi, string channelName);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_DisableStartTrigger(ViSession vi);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_DisableStartTriggerWithChannels(ViSession vi, string channelName);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ConfigureDigitalEdgeSequenceAdvanceTrigger(ViSession vi, string inputTerminal, int edge);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ConfigureDigitalEdgeSequenceAdvanceTriggerWithChannels(ViSession vi, string channelName, string inputTerminal, int edge);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ConfigureSoftwareEdgeSequenceAdvanceTrigger(ViSession vi);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ConfigureSoftwareEdgeSequenceAdvanceTriggerWithChannels(ViSession vi, string channelName);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_DisableSequenceAdvanceTrigger(ViSession vi);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_DisableSequenceAdvanceTriggerWithChannels(ViSession vi, string channelName);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ConfigureDigitalEdgeSourceTrigger(ViSession vi, string inputTerminal, int edge);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ConfigureDigitalEdgeSourceTriggerWithChannels(ViSession vi, string channelName, string inputTerminal, int edge);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ConfigureSoftwareEdgeSourceTrigger(ViSession vi);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ConfigureSoftwareEdgeSourceTriggerWithChannels(ViSession vi, string channelName);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_DisableSourceTrigger(ViSession vi);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_DisableSourceTriggerWithChannels(ViSession vi, string channelName);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ConfigureDigitalEdgeMeasureTrigger(ViSession vi, string inputTerminal, int edge);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ConfigureDigitalEdgeMeasureTriggerWithChannels(ViSession vi, string channelName, string inputTerminal, int edge);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ConfigureSoftwareEdgeMeasureTrigger(ViSession vi);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ConfigureSoftwareEdgeMeasureTriggerWithChannels(ViSession vi, string channelName);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ConfigureDigitalEdgePulseTrigger(ViSession vi, string inputTerminal, int edge);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ConfigureDigitalEdgePulseTriggerWithChannels(ViSession vi, string channelName, string inputTerminal, int edge);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ConfigureSoftwareEdgePulseTrigger(ViSession vi);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ConfigureSoftwareEdgePulseTriggerWithChannels(ViSession vi, string channelName);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_DisablePulseTrigger(ViSession vi);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_DisablePulseTriggerWithChannels(ViSession vi, string channelName);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ConfigureDigitalEdgeShutdownTriggerWithChannels(ViSession vi, string channelName, string inputTerminal, int edge);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ConfigureSoftwareEdgeShutdownTriggerWithChannels(ViSession vi, string channelName);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_DisableShutdownTriggerWithChannels(ViSession vi, string channelName);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ExportSignal(ViSession vi, int signal, string signalIdentifier, string outputTerminal);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ExportSignalWithChannels(ViSession vi, string channelName, int signal, string signalIdentifier, string outputTerminal);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_SendSoftwareEdgeTrigger(ViSession vi, int trigger);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_SendSoftwareEdgeTriggerWithChannels(ViSession vi, string channelName, int trigger);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_WaitForEvent(ViSession vi, int eventId, double timeout);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_WaitForEventWithChannels(ViSession vi, string channelName, int eventId, double timeout);

        #endregion

        #region Utility

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_Disable(ViSession vi);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_reset(ViSession vi);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ResetWithChannels(ViSession vi, string channelName);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ResetDevice(ViSession vi);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_self_test(ViSession vi, out short selfTestResult, StringBuilder selfTestMessage);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_revision_query(ViSession vi, StringBuilder instrumentDriverRevision, StringBuilder firmwareRevision);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ResetWithDefaults(ViSession vi);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_GetChannelName(ViSession vi, int index, int bufferSize, StringBuilder channelName);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_GetChannelNameFromString(ViSession vi, string index, int bufferSize, StringBuilder channelName);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_GetNextCoercionRecord(ViSession vi, int bufferSize, StringBuilder coercionRecord);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ClearInterchangeWarnings(ViSession vi);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ResetInterchangeCheck(ViSession vi);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_GetNextInterchangeWarning(ViSession vi, int bufferSize, StringBuilder interchangeWarning);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_InvalidateAllAttributes(ViSession vi);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ConfigureOVP(ViSession vi, string channelName, ushort enabled, double limit);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_GetError(ViSession vi, out int code, int bufferSize, StringBuilder description);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ClearError(ViSession vi);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_error_message(ViSession vi, int errorCode, StringBuilder errorMessage);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_error_query(ViSession vi, out int errorCode, StringBuilder errorMessage);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_LockSession(ViSession vi, out ushort callerHasLock);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_UnlockSession(ViSession vi, out ushort callerHasLock);

        #endregion

        #region Set/Get Attribute

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_SetAttributeViInt32(ViSession vi, string channelName, uint attributeId, int attributeValue);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_SetAttributeViInt64(ViSession vi, string channelName, uint attributeId, long attributeValue);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_SetAttributeViReal64(ViSession vi, string channelName, uint attributeId, double attributeValue);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_SetAttributeViString(ViSession vi, string channelName, uint attributeId, string attributeValue);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_SetAttributeViSession(ViSession vi, string channelName, uint attributeId, ViSession attributeValue);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_SetAttributeViBoolean(ViSession vi, string channelName, uint attributeId, ushort attributeValue);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_GetAttributeViInt32(ViSession vi, string channelName, uint attributeId, out int attributeValue);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_GetAttributeViInt64(ViSession vi, string channelName, uint attributeId, out long attributeValue);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_GetAttributeViReal64(ViSession vi, string channelName, uint attributeId, out double attributeValue);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_GetAttributeViString(ViSession vi, string channelName, uint attributeId, int bufferSize, StringBuilder attributeValue);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_GetAttributeViSession(ViSession vi, string channelName, uint attributeId, out ViSession attributeValue);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_GetAttributeViBoolean(ViSession vi, string channelName, uint attributeId, out ushort attributeValue);

        #endregion

        #region Utility::Import/Export Attribute Configuration

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ImportAttributeConfigurationFile(ViSession vi, string filePath);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ExportAttributeConfigurationFile(ViSession vi, string filePath);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ImportAttributeConfigurationBuffer(ViSession vi, int size, IntPtr configuration);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_ExportAttributeConfigurationBuffer(ViSession vi, int size, IntPtr configuration);

        #endregion

        #region Calibration::LCR Compensation::LCR Custom Cable Compensation

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_PerformLCROpenCustomCableCompensation(ViSession vi, string channelName);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_PerformLCRShortCustomCableCompensation(ViSession vi, string channelName);

        [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int niDCPower_GetLCRCompensationData(ViSession vi, string channelName, int compensationDataSize, IntPtr compensationData);

        #endregion
    }
}
