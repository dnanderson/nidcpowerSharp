/****************************************************************************
 *              National Instruments DC Power Supplies and SMUs
 *--------------------------------------------------------------------------*
 *      Copyright (c) National Instruments 2025.  All Rights Reserved.      *
 *--------------------------------------------------------------------------*
 *
 * Title:    nidcpower.h
 * Purpose:  National Instruments DC Power Supplies and SMUs Instrument
 *           Driver declarations
 *
 ****************************************************************************/

#ifndef __NIDCPOWER_HEADER
#define __NIDCPOWER_HEADER

#define IVI_DO_NOT_INCLUDE_VISA_HEADERS
#include <ivi.h>
#include <IviDCPwr.h>
#undef IVI_DO_NOT_INCLUDE_VISA_HEADERS

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

/* Pragma used in CVI to indicate that functions in this file have
 * user protection associated with them */
#ifdef _CVI_
 #pragma EnableLibraryRuntimeChecking
#endif


/****************************************************************************
 *----------------- Instrument Driver Revision Information -----------------*
 ****************************************************************************/
#define NIDCPOWER_MAJOR_VERSION                                                         25                                                // Instrument driver major version
#define NIDCPOWER_MINOR_VERSION                                                         5                                                 // Instrument driver minor version
#define NIDCPOWER_UPDATE_VERSION                                                        0                                                 // Instrument driver update version


/****************************************************************************
 *---------------------------- Attribute Defines ---------------------------*
 ****************************************************************************/
#define NIDCPOWER_CLASS_SPEC_MAJOR_VERSION                                              3                                                 // 3 (0x3)
#define NIDCPOWER_CLASS_SPEC_MINOR_VERSION                                              0                                                 // 0 (0x0)
#define NIDCPOWER_ATTR_BASE                                                             IVI_SPECIFIC_PUBLIC_ATTR_BASE                     // 1150000 (0x118c30)
#define NIDCPOWER_ATTR_PRIVATE_BASE                                                     IVI_SPECIFIC_PRIVATE_ATTR_BASE                    // 1200000 (0x124f80)
#define NIDCPOWER_VAL_BASE                                                              1000                                              // 1000 (0x3e8)

#define NIDCPOWER_ERROR_BASE                                                            IVI_SPECIFIC_ERROR_BASE                           // 3220848640 (0xbffa4000)
#define NIDCPOWER_WARN_BASE                                                             IVI_SPECIFIC_WARN_BASE                            // 1073364992 (0x3ffa4000)


/****************************************************************************
 *------------------------------- Attributes -------------------------------*
 ****************************************************************************/
 /*- NOTE: multi channel denotes an attribute specified on a per channel basis -*/

// -- Inherent IVI Attributes::User Options --
#define NIDCPOWER_ATTR_RANGE_CHECK                                                      IVI_ATTR_RANGE_CHECK                              // 1050002 (0x100592), ViBoolean
#define NIDCPOWER_ATTR_QUERY_INSTRUMENT_STATUS                                          IVI_ATTR_QUERY_INSTRUMENT_STATUS                  // 1050003 (0x100593), ViBoolean
#define NIDCPOWER_ATTR_CACHE                                                            IVI_ATTR_CACHE                                    // 1050004 (0x100594), ViBoolean
#define NIDCPOWER_ATTR_SIMULATE                                                         IVI_ATTR_SIMULATE                                 // 1050005 (0x100595), ViBoolean
#define NIDCPOWER_ATTR_RECORD_COERCIONS                                                 IVI_ATTR_RECORD_COERCIONS                         // 1050006 (0x100596), ViBoolean
#define NIDCPOWER_ATTR_INTERCHANGE_CHECK                                                IVI_ATTR_INTERCHANGE_CHECK                        // 1050021 (0x1005a5), ViBoolean

// -- Inherent IVI Attributes::Driver Capabilities --
#define NIDCPOWER_ATTR_CHANNEL_COUNT                                                    IVI_ATTR_CHANNEL_COUNT                            // 1050203 (0x10065b), ViInt32,    read-only
#define NIDCPOWER_ATTR_SUPPORTED_INSTRUMENT_MODELS                                      IVI_ATTR_SUPPORTED_INSTRUMENT_MODELS              // 1050327 (0x1006d7), ViString,   read-only
#define NIDCPOWER_ATTR_GROUP_CAPABILITIES                                               IVI_ATTR_GROUP_CAPABILITIES                       // 1050401 (0x100721), ViString,   read-only

// -- Inherent IVI Attributes::Driver Identification --
#define NIDCPOWER_ATTR_SPECIFIC_DRIVER_PREFIX                                           IVI_ATTR_SPECIFIC_DRIVER_PREFIX                   // 1050302 (0x1006be), ViString,   read-only
#define NIDCPOWER_ATTR_SPECIFIC_DRIVER_REVISION                                         IVI_ATTR_SPECIFIC_DRIVER_REVISION                 // 1050551 (0x1007b7), ViString,   read-only
#define NIDCPOWER_ATTR_SPECIFIC_DRIVER_VENDOR                                           IVI_ATTR_SPECIFIC_DRIVER_VENDOR                   // 1050513 (0x100791), ViString,   read-only
#define NIDCPOWER_ATTR_SPECIFIC_DRIVER_DESCRIPTION                                      IVI_ATTR_SPECIFIC_DRIVER_DESCRIPTION              // 1050514 (0x100792), ViString,   read-only
#define NIDCPOWER_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION                         IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION // 1050515 (0x100793), ViInt32,    read-only
#define NIDCPOWER_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION                         IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION // 1050516 (0x100794), ViInt32,    read-only

// -- Inherent IVI Attributes::Instrument Identification --
#define NIDCPOWER_ATTR_INSTRUMENT_MANUFACTURER                                          IVI_ATTR_INSTRUMENT_MANUFACTURER                  // 1050511 (0x10078f), ViString,   read-only
#define NIDCPOWER_ATTR_INSTRUMENT_MODEL                                                 IVI_ATTR_INSTRUMENT_MODEL                         // 1050512 (0x100790), ViString,   read-only
#define NIDCPOWER_ATTR_INSTRUMENT_FIRMWARE_REVISION                                     IVI_ATTR_INSTRUMENT_FIRMWARE_REVISION             // 1050510 (0x10078e), ViString,   read-only
#define NIDCPOWER_ATTR_SERIAL_NUMBER                                                    (NIDCPOWER_ATTR_BASE + 152L)                      // 1150152 (0x118cc8), ViString,   read-only

// -- Inherent IVI Attributes::Advanced Session Information --
#define NIDCPOWER_ATTR_LOGICAL_NAME                                                     IVI_ATTR_LOGICAL_NAME                             // 1050305 (0x1006c1), ViString,   read-only
#define NIDCPOWER_ATTR_IO_RESOURCE_DESCRIPTOR                                           IVI_ATTR_IO_RESOURCE_DESCRIPTOR                   // 1050304 (0x1006c0), ViString,   read-only
#define NIDCPOWER_ATTR_DRIVER_SETUP                                                     IVI_ATTR_DRIVER_SETUP                             // 1050007 (0x100597), ViString,   read-only

// -- Source --
#define NIDCPOWER_ATTR_SOURCE_MODE                                                      (NIDCPOWER_ATTR_BASE + 54L)                       // 1150054 (0x118c66), ViInt32,    multi-channel
#define NIDCPOWER_ATTR_OUTPUT_FUNCTION                                                  (NIDCPOWER_ATTR_BASE + 8L)                        // 1150008 (0x118c38), ViInt32,    multi-channel
#define NIDCPOWER_ATTR_OUTPUT_ENABLED                                                   IVIDCPWR_ATTR_OUTPUT_ENABLED                      // 1250006 (0x1312d6), ViBoolean,  multi-channel
#define NIDCPOWER_ATTR_OUTPUT_CONNECTED                                                 (NIDCPOWER_ATTR_BASE + 60L)                       // 1150060 (0x118c6c), ViBoolean,  multi-channel
#define NIDCPOWER_ATTR_OUTPUT_RESISTANCE                                                (NIDCPOWER_ATTR_BASE + 61L)                       // 1150061 (0x118c6d), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_TRANSIENT_RESPONSE                                               (NIDCPOWER_ATTR_BASE + 62L)                       // 1150062 (0x118c6e), ViInt32,    multi-channel

// -- Source::Custom Transient Response::Voltage --
#define NIDCPOWER_ATTR_VOLTAGE_GAIN_BANDWIDTH                                           (NIDCPOWER_ATTR_BASE + 67L)                       // 1150067 (0x118c73), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_VOLTAGE_COMPENSATION_FREQUENCY                                   (NIDCPOWER_ATTR_BASE + 68L)                       // 1150068 (0x118c74), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_VOLTAGE_POLE_ZERO_RATIO                                          (NIDCPOWER_ATTR_BASE + 69L)                       // 1150069 (0x118c75), ViReal64,   multi-channel

// -- Source::Custom Transient Response::Current --
#define NIDCPOWER_ATTR_CURRENT_GAIN_BANDWIDTH                                           (NIDCPOWER_ATTR_BASE + 70L)                       // 1150070 (0x118c76), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_CURRENT_COMPENSATION_FREQUENCY                                   (NIDCPOWER_ATTR_BASE + 71L)                       // 1150071 (0x118c77), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_CURRENT_POLE_ZERO_RATIO                                          (NIDCPOWER_ATTR_BASE + 72L)                       // 1150072 (0x118c78), ViReal64,   multi-channel

// -- Source::Custom Transient Response::Constant Power --
#define NIDCPOWER_ATTR_CONSTANT_POWER_COMPENSATION_FREQUENCY                            (NIDCPOWER_ATTR_BASE + 360L)                      // 1150360 (0x118d98), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_CONSTANT_POWER_GAIN_BANDWIDTH                                    (NIDCPOWER_ATTR_BASE + 362L)                      // 1150362 (0x118d9a), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_CONSTANT_POWER_POLE_ZERO_RATIO                                   (NIDCPOWER_ATTR_BASE + 365L)                      // 1150365 (0x118d9d), ViReal64,   multi-channel

// -- Source::Custom Transient Response::Constant Resistance --
#define NIDCPOWER_ATTR_CONSTANT_RESISTANCE_COMPENSATION_FREQUENCY                       (NIDCPOWER_ATTR_BASE + 366L)                      // 1150366 (0x118d9e), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_CONSTANT_RESISTANCE_GAIN_BANDWIDTH                               (NIDCPOWER_ATTR_BASE + 368L)                      // 1150368 (0x118da0), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_CONSTANT_RESISTANCE_POLE_ZERO_RATIO                              (NIDCPOWER_ATTR_BASE + 371L)                      // 1150371 (0x118da3), ViReal64,   multi-channel

// -- Source::DC Voltage --
#define NIDCPOWER_ATTR_VOLTAGE_LEVEL                                                    IVIDCPWR_ATTR_VOLTAGE_LEVEL                       // 1250001 (0x1312d1), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_CURRENT_LIMIT                                                    IVIDCPWR_ATTR_CURRENT_LIMIT                       // 1250005 (0x1312d5), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_VOLTAGE_LEVEL_RANGE                                              (NIDCPOWER_ATTR_BASE + 5L)                        // 1150005 (0x118c35), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_CURRENT_LIMIT_RANGE                                              (NIDCPOWER_ATTR_BASE + 4L)                        // 1150004 (0x118c34), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_CURRENT_LIMIT_BEHAVIOR                                           IVIDCPWR_ATTR_CURRENT_LIMIT_BEHAVIOR              // 1250004 (0x1312d4), ViInt32,    multi-channel
#define NIDCPOWER_ATTR_VOLTAGE_LEVEL_AUTORANGE                                          (NIDCPOWER_ATTR_BASE + 15L)                       // 1150015 (0x118c3f), ViInt32,    multi-channel
#define NIDCPOWER_ATTR_CURRENT_LIMIT_AUTORANGE                                          (NIDCPOWER_ATTR_BASE + 16L)                       // 1150016 (0x118c40), ViInt32,    multi-channel
#define NIDCPOWER_ATTR_CURRENT_LIMIT_HIGH                                               (NIDCPOWER_ATTR_BASE + 187L)                      // 1150187 (0x118ceb), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_CURRENT_LIMIT_LOW                                                (NIDCPOWER_ATTR_BASE + 188L)                      // 1150188 (0x118cec), ViReal64,   multi-channel

// -- Source::DC Current --
#define NIDCPOWER_ATTR_CURRENT_LEVEL                                                    (NIDCPOWER_ATTR_BASE + 9L)                        // 1150009 (0x118c39), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_VOLTAGE_LIMIT                                                    (NIDCPOWER_ATTR_BASE + 10L)                       // 1150010 (0x118c3a), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_CURRENT_LEVEL_RANGE                                              (NIDCPOWER_ATTR_BASE + 11L)                       // 1150011 (0x118c3b), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_VOLTAGE_LIMIT_RANGE                                              (NIDCPOWER_ATTR_BASE + 12L)                       // 1150012 (0x118c3c), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_CURRENT_LEVEL_AUTORANGE                                          (NIDCPOWER_ATTR_BASE + 17L)                       // 1150017 (0x118c41), ViInt32,    multi-channel
#define NIDCPOWER_ATTR_VOLTAGE_LIMIT_AUTORANGE                                          (NIDCPOWER_ATTR_BASE + 18L)                       // 1150018 (0x118c42), ViInt32,    multi-channel
#define NIDCPOWER_ATTR_VOLTAGE_LIMIT_HIGH                                               (NIDCPOWER_ATTR_BASE + 185L)                      // 1150185 (0x118ce9), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_VOLTAGE_LIMIT_LOW                                                (NIDCPOWER_ATTR_BASE + 186L)                      // 1150186 (0x118cea), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_CURRENT_LEVEL_RISING_SLEW_RATE                                   (NIDCPOWER_ATTR_BASE + 343L)                      // 1150343 (0x118d87), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_CURRENT_LEVEL_FALLING_SLEW_RATE                                  (NIDCPOWER_ATTR_BASE + 344L)                      // 1150344 (0x118d88), ViReal64,   multi-channel

// -- Source::Pulse Voltage --
#define NIDCPOWER_ATTR_PULSE_VOLTAGE_LEVEL                                              (NIDCPOWER_ATTR_BASE + 80L)                       // 1150080 (0x118c80), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_PULSE_CURRENT_LIMIT                                              (NIDCPOWER_ATTR_BASE + 81L)                       // 1150081 (0x118c81), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_PULSE_BIAS_VOLTAGE_LEVEL                                         (NIDCPOWER_ATTR_BASE + 82L)                       // 1150082 (0x118c82), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_PULSE_BIAS_CURRENT_LIMIT                                         (NIDCPOWER_ATTR_BASE + 83L)                       // 1150083 (0x118c83), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_PULSE_VOLTAGE_LEVEL_RANGE                                        (NIDCPOWER_ATTR_BASE + 84L)                       // 1150084 (0x118c84), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_PULSE_CURRENT_LIMIT_RANGE                                        (NIDCPOWER_ATTR_BASE + 85L)                       // 1150085 (0x118c85), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_PULSE_CURRENT_LIMIT_HIGH                                         (NIDCPOWER_ATTR_BASE + 193L)                      // 1150193 (0x118cf1), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_PULSE_CURRENT_LIMIT_LOW                                          (NIDCPOWER_ATTR_BASE + 194L)                      // 1150194 (0x118cf2), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_PULSE_BIAS_CURRENT_LIMIT_HIGH                                    (NIDCPOWER_ATTR_BASE + 195L)                      // 1150195 (0x118cf3), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_PULSE_BIAS_CURRENT_LIMIT_LOW                                     (NIDCPOWER_ATTR_BASE + 196L)                      // 1150196 (0x118cf4), ViReal64,   multi-channel

// -- Source::Pulse Current --
#define NIDCPOWER_ATTR_PULSE_CURRENT_LEVEL                                              (NIDCPOWER_ATTR_BASE + 86L)                       // 1150086 (0x118c86), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_PULSE_VOLTAGE_LIMIT                                              (NIDCPOWER_ATTR_BASE + 87L)                       // 1150087 (0x118c87), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_PULSE_BIAS_CURRENT_LEVEL                                         (NIDCPOWER_ATTR_BASE + 88L)                       // 1150088 (0x118c88), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_PULSE_BIAS_VOLTAGE_LIMIT                                         (NIDCPOWER_ATTR_BASE + 89L)                       // 1150089 (0x118c89), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_PULSE_CURRENT_LEVEL_RANGE                                        (NIDCPOWER_ATTR_BASE + 90L)                       // 1150090 (0x118c8a), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_PULSE_VOLTAGE_LIMIT_RANGE                                        (NIDCPOWER_ATTR_BASE + 91L)                       // 1150091 (0x118c8b), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_PULSE_VOLTAGE_LIMIT_HIGH                                         (NIDCPOWER_ATTR_BASE + 189L)                      // 1150189 (0x118ced), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_PULSE_VOLTAGE_LIMIT_LOW                                          (NIDCPOWER_ATTR_BASE + 190L)                      // 1150190 (0x118cee), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_PULSE_BIAS_VOLTAGE_LIMIT_HIGH                                    (NIDCPOWER_ATTR_BASE + 191L)                      // 1150191 (0x118cef), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_PULSE_BIAS_VOLTAGE_LIMIT_LOW                                     (NIDCPOWER_ATTR_BASE + 192L)                      // 1150192 (0x118cf0), ViReal64,   multi-channel

// -- Source::Advanced --
#define NIDCPOWER_ATTR_SOURCE_DELAY                                                     (NIDCPOWER_ATTR_BASE + 51L)                       // 1150051 (0x118c63), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_OVERRANGING_ENABLED                                              (NIDCPOWER_ATTR_BASE + 7L)                        // 1150007 (0x118c37), ViBoolean,  multi-channel
#define NIDCPOWER_ATTR_OUTPUT_CAPACITANCE                                               (NIDCPOWER_ATTR_BASE + 14L)                       // 1150014 (0x118c3e), ViInt32,    multi-channel
#define NIDCPOWER_ATTR_SEQUENCE_LOOP_COUNT                                              (NIDCPOWER_ATTR_BASE + 25L)                       // 1150025 (0x118c49), ViInt32,    multi-channel
#define NIDCPOWER_ATTR_SEQUENCE_LOOP_COUNT_IS_FINITE                                    (NIDCPOWER_ATTR_BASE + 78L)                       // 1150078 (0x118c7e), ViBoolean,  multi-channel
#define NIDCPOWER_ATTR_COMPLIANCE_LIMIT_SYMMETRY                                        (NIDCPOWER_ATTR_BASE + 184L)                      // 1150184 (0x118ce8), ViInt32,    multi-channel
#define NIDCPOWER_ATTR_SEQUENCE_STEP_DELTA_TIME                                         (NIDCPOWER_ATTR_BASE + 198L)                      // 1150198 (0x118cf6), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_SEQUENCE_STEP_DELTA_TIME_ENABLED                                 (NIDCPOWER_ATTR_BASE + 199L)                      // 1150199 (0x118cf7), ViBoolean,  multi-channel
#define NIDCPOWER_ATTR_ACTUAL_POWER_ALLOCATION                                          (NIDCPOWER_ATTR_BASE + 205L)                      // 1150205 (0x118cfd), ViReal64,   multi-channel, read-only
#define NIDCPOWER_ATTR_REQUESTED_POWER_ALLOCATION                                       (NIDCPOWER_ATTR_BASE + 206L)                      // 1150206 (0x118cfe), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_POWER_ALLOCATION_MODE                                            (NIDCPOWER_ATTR_BASE + 207L)                      // 1150207 (0x118cff), ViInt32,    multi-channel
#define NIDCPOWER_ATTR_MERGED_CHANNELS                                                  (NIDCPOWER_ATTR_BASE + 249L)                      // 1150249 (0x118d29), ViString,   multi-channel
#define NIDCPOWER_ATTR_OUTPUT_SHORTED                                                   (NIDCPOWER_ATTR_BASE + 372L)                      // 1150372 (0x118da4), ViBoolean,  multi-channel
#define NIDCPOWER_ATTR_PULSE_BIAS_DELAY                                                 (NIDCPOWER_ATTR_BASE + 92L)                       // 1150092 (0x118c8c), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_PULSE_ON_TIME                                                    (NIDCPOWER_ATTR_BASE + 93L)                       // 1150093 (0x118c8d), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_PULSE_OFF_TIME                                                   (NIDCPOWER_ATTR_BASE + 94L)                       // 1150094 (0x118c8e), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_OVP_ENABLED                                                      IVIDCPWR_ATTR_OVP_ENABLED                         // 1250002 (0x1312d2), ViBoolean,  multi-channel
#define NIDCPOWER_ATTR_OVP_LIMIT                                                        IVIDCPWR_ATTR_OVP_LIMIT                           // 1250003 (0x1312d3), ViReal64,   multi-channel

// -- Source::Advanced::Conduction Voltage --
#define NIDCPOWER_ATTR_CONDUCTION_VOLTAGE_MODE                                          (NIDCPOWER_ATTR_BASE + 350L)                      // 1150350 (0x118d8e), ViInt32,    multi-channel
#define NIDCPOWER_ATTR_CONDUCTION_VOLTAGE_ON_THRESHOLD                                  (NIDCPOWER_ATTR_BASE + 351L)                      // 1150351 (0x118d8f), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_CONDUCTION_VOLTAGE_OFF_THRESHOLD                                 (NIDCPOWER_ATTR_BASE + 352L)                      // 1150352 (0x118d90), ViReal64,   multi-channel

// -- Measure --
#define NIDCPOWER_ATTR_SENSE                                                            (NIDCPOWER_ATTR_BASE + 13L)                       // 1150013 (0x118c3d), ViInt32,    multi-channel
#define NIDCPOWER_ATTR_AUTO_ZERO                                                        (NIDCPOWER_ATTR_BASE + 55L)                       // 1150055 (0x118c67), ViInt32,    multi-channel
#define NIDCPOWER_ATTR_APERTURE_TIME                                                    (NIDCPOWER_ATTR_BASE + 58L)                       // 1150058 (0x118c6a), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_APERTURE_TIME_UNITS                                              (NIDCPOWER_ATTR_BASE + 59L)                       // 1150059 (0x118c6b), ViInt32,    multi-channel
#define NIDCPOWER_ATTR_POWER_LINE_FREQUENCY                                             (NIDCPOWER_ATTR_BASE + 20L)                       // 1150020 (0x118c44), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_SAMPLES_TO_AVERAGE                                               (NIDCPOWER_ATTR_BASE + 3L)                        // 1150003 (0x118c33), ViInt32,    multi-channel
#define NIDCPOWER_ATTR_FETCH_BACKLOG                                                    (NIDCPOWER_ATTR_BASE + 56L)                       // 1150056 (0x118c68), ViInt32,    multi-channel, read-only
#define NIDCPOWER_ATTR_APERTURE_TIME_AUTO_MODE                                          (NIDCPOWER_ATTR_BASE + 314L)                      // 1150314 (0x118d6a), ViInt32,    multi-channel
#define NIDCPOWER_ATTR_MEASURE_RECORD_LENGTH                                            (NIDCPOWER_ATTR_BASE + 63L)                       // 1150063 (0x118c6f), ViInt32,    multi-channel
#define NIDCPOWER_ATTR_MEASURE_RECORD_LENGTH_IS_FINITE                                  (NIDCPOWER_ATTR_BASE + 64L)                       // 1150064 (0x118c70), ViBoolean,  multi-channel
#define NIDCPOWER_ATTR_MEASURE_RECORD_DELTA_TIME                                        (NIDCPOWER_ATTR_BASE + 65L)                       // 1150065 (0x118c71), ViReal64,   multi-channel, read-only

// -- Measure::Advanced --
#define NIDCPOWER_ATTR_AUTORANGE                                                        (NIDCPOWER_ATTR_BASE + 244L)                      // 1150244 (0x118d24), ViInt32,    multi-channel
#define NIDCPOWER_ATTR_MEASURE_WHEN                                                     (NIDCPOWER_ATTR_BASE + 57L)                       // 1150057 (0x118c69), ViInt32,    multi-channel
#define NIDCPOWER_ATTR_RESET_AVERAGE_BEFORE_MEASUREMENT                                 (NIDCPOWER_ATTR_BASE + 6L)                        // 1150006 (0x118c36), ViBoolean,  multi-channel
#define NIDCPOWER_ATTR_DC_NOISE_REJECTION                                               (NIDCPOWER_ATTR_BASE + 66L)                       // 1150066 (0x118c72), ViInt32,    multi-channel
#define NIDCPOWER_ATTR_MEASURE_BUFFER_SIZE                                              (NIDCPOWER_ATTR_BASE + 77L)                       // 1150077 (0x118c7d), ViInt32,    multi-channel
#define NIDCPOWER_ATTR_AUTORANGE_BEHAVIOR                                               (NIDCPOWER_ATTR_BASE + 245L)                      // 1150245 (0x118d25), ViInt32,    multi-channel
#define NIDCPOWER_ATTR_AUTORANGE_APERTURE_TIME_MODE                                     (NIDCPOWER_ATTR_BASE + 246L)                      // 1150246 (0x118d26), ViInt32,    multi-channel
#define NIDCPOWER_ATTR_AUTORANGE_MINIMUM_APERTURE_TIME                                  (NIDCPOWER_ATTR_BASE + 247L)                      // 1150247 (0x118d27), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_AUTORANGE_MINIMUM_APERTURE_TIME_UNITS                            (NIDCPOWER_ATTR_BASE + 248L)                      // 1150248 (0x118d28), ViInt32,    multi-channel
#define NIDCPOWER_ATTR_AUTORANGE_MINIMUM_CURRENT_RANGE                                  (NIDCPOWER_ATTR_BASE + 255L)                      // 1150255 (0x118d2f), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_AUTORANGE_MINIMUM_VOLTAGE_RANGE                                  (NIDCPOWER_ATTR_BASE + 256L)                      // 1150256 (0x118d30), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_AUTORANGE_THRESHOLD_MODE                                         (NIDCPOWER_ATTR_BASE + 257L)                      // 1150257 (0x118d31), ViInt32,    multi-channel
#define NIDCPOWER_ATTR_AUTORANGE_MAXIMUM_DELAY_AFTER_RANGE_CHANGE                       (NIDCPOWER_ATTR_BASE + 322L)                      // 1150322 (0x118d72), ViReal64,   multi-channel

// -- Advanced --
#define NIDCPOWER_ATTR_SELF_CALIBRATION_PERSISTENCE                                     (NIDCPOWER_ATTR_BASE + 73L)                       // 1150073 (0x118c79), ViInt32
#define NIDCPOWER_ATTR_INTERLOCK_INPUT_OPEN                                             (NIDCPOWER_ATTR_BASE + 105L)                      // 1150105 (0x118c99), ViBoolean,  read-only
#define NIDCPOWER_ATTR_POWER_SOURCE                                                     (NIDCPOWER_ATTR_BASE + 0L)                        // 1150000 (0x118c30), ViInt32
#define NIDCPOWER_ATTR_POWER_SOURCE_IN_USE                                              (NIDCPOWER_ATTR_BASE + 1L)                        // 1150001 (0x118c31), ViInt32,    read-only
#define NIDCPOWER_ATTR_AUXILIARY_POWER_SOURCE_AVAILABLE                                 (NIDCPOWER_ATTR_BASE + 2L)                        // 1150002 (0x118c32), ViBoolean,  read-only
#define NIDCPOWER_ATTR_ISOLATION_STATE                                                  (NIDCPOWER_ATTR_BASE + 302L)                      // 1150302 (0x118d5e), ViInt32,    multi-channel

// -- Triggers::Start Trigger --
#define NIDCPOWER_ATTR_START_TRIGGER_TYPE                                               (NIDCPOWER_ATTR_BASE + 21L)                       // 1150021 (0x118c45), ViInt32,    multi-channel
#define NIDCPOWER_ATTR_EXPORTED_START_TRIGGER_OUTPUT_TERMINAL                           (NIDCPOWER_ATTR_BASE + 24L)                       // 1150024 (0x118c48), ViString,   multi-channel

// -- Triggers::Start Trigger::Digital Edge --
#define NIDCPOWER_ATTR_DIGITAL_EDGE_START_TRIGGER_EDGE                                  (NIDCPOWER_ATTR_BASE + 22L)                       // 1150022 (0x118c46), ViInt32,    multi-channel
#define NIDCPOWER_ATTR_DIGITAL_EDGE_START_TRIGGER_INPUT_TERMINAL                        (NIDCPOWER_ATTR_BASE + 23L)                       // 1150023 (0x118c47), ViString,   multi-channel

// -- Triggers::Source Trigger --
#define NIDCPOWER_ATTR_SOURCE_TRIGGER_TYPE                                              (NIDCPOWER_ATTR_BASE + 30L)                       // 1150030 (0x118c4e), ViInt32,    multi-channel
#define NIDCPOWER_ATTR_EXPORTED_SOURCE_TRIGGER_OUTPUT_TERMINAL                          (NIDCPOWER_ATTR_BASE + 33L)                       // 1150033 (0x118c51), ViString,   multi-channel

// -- Triggers::Source Trigger::Digital Edge --
#define NIDCPOWER_ATTR_DIGITAL_EDGE_SOURCE_TRIGGER_EDGE                                 (NIDCPOWER_ATTR_BASE + 31L)                       // 1150031 (0x118c4f), ViInt32,    multi-channel
#define NIDCPOWER_ATTR_DIGITAL_EDGE_SOURCE_TRIGGER_INPUT_TERMINAL                       (NIDCPOWER_ATTR_BASE + 32L)                       // 1150032 (0x118c50), ViString,   multi-channel

// -- Triggers::Measure Trigger --
#define NIDCPOWER_ATTR_MEASURE_TRIGGER_TYPE                                             (NIDCPOWER_ATTR_BASE + 34L)                       // 1150034 (0x118c52), ViInt32,    multi-channel
#define NIDCPOWER_ATTR_EXPORTED_MEASURE_TRIGGER_OUTPUT_TERMINAL                         (NIDCPOWER_ATTR_BASE + 37L)                       // 1150037 (0x118c55), ViString,   multi-channel

// -- Triggers::Measure Trigger::Digital Edge --
#define NIDCPOWER_ATTR_DIGITAL_EDGE_MEASURE_TRIGGER_EDGE                                (NIDCPOWER_ATTR_BASE + 35L)                       // 1150035 (0x118c53), ViInt32,    multi-channel
#define NIDCPOWER_ATTR_DIGITAL_EDGE_MEASURE_TRIGGER_INPUT_TERMINAL                      (NIDCPOWER_ATTR_BASE + 36L)                       // 1150036 (0x118c54), ViString,   multi-channel

// -- Triggers::Sequence Advance Trigger --
#define NIDCPOWER_ATTR_SEQUENCE_ADVANCE_TRIGGER_TYPE                                    (NIDCPOWER_ATTR_BASE + 26L)                       // 1150026 (0x118c4a), ViInt32,    multi-channel
#define NIDCPOWER_ATTR_EXPORTED_SEQUENCE_ADVANCE_TRIGGER_OUTPUT_TERMINAL                (NIDCPOWER_ATTR_BASE + 29L)                       // 1150029 (0x118c4d), ViString,   multi-channel

// -- Triggers::Sequence Advance Trigger::Digital Edge --
#define NIDCPOWER_ATTR_DIGITAL_EDGE_SEQUENCE_ADVANCE_TRIGGER_EDGE                       (NIDCPOWER_ATTR_BASE + 27L)                       // 1150027 (0x118c4b), ViInt32,    multi-channel
#define NIDCPOWER_ATTR_DIGITAL_EDGE_SEQUENCE_ADVANCE_TRIGGER_INPUT_TERMINAL             (NIDCPOWER_ATTR_BASE + 28L)                       // 1150028 (0x118c4c), ViString,   multi-channel

// -- Events::Source Complete Event --
#define NIDCPOWER_ATTR_SOURCE_COMPLETE_EVENT_OUTPUT_TERMINAL                            (NIDCPOWER_ATTR_BASE + 43L)                       // 1150043 (0x118c5b), ViString,   multi-channel
#define NIDCPOWER_ATTR_SOURCE_COMPLETE_EVENT_OUTPUT_BEHAVIOR                            (NIDCPOWER_ATTR_BASE + 331L)                      // 1150331 (0x118d7b), ViInt32,    multi-channel

// -- Events::Source Complete Event::Pulse --
#define NIDCPOWER_ATTR_SOURCE_COMPLETE_EVENT_PULSE_POLARITY                             (NIDCPOWER_ATTR_BASE + 41L)                       // 1150041 (0x118c59), ViInt32,    multi-channel
#define NIDCPOWER_ATTR_SOURCE_COMPLETE_EVENT_PULSE_WIDTH                                (NIDCPOWER_ATTR_BASE + 42L)                       // 1150042 (0x118c5a), ViReal64,   multi-channel

// -- Events::Source Complete Event::Toggle --
#define NIDCPOWER_ATTR_SOURCE_COMPLETE_EVENT_TOGGLE_INITIAL_STATE                       (NIDCPOWER_ATTR_BASE + 332L)                      // 1150332 (0x118d7c), ViInt32,    multi-channel

// -- Events::Measure Complete Event --
#define NIDCPOWER_ATTR_MEASURE_COMPLETE_EVENT_OUTPUT_TERMINAL                           (NIDCPOWER_ATTR_BASE + 47L)                       // 1150047 (0x118c5f), ViString,   multi-channel
#define NIDCPOWER_ATTR_MEASURE_COMPLETE_EVENT_DELAY                                     (NIDCPOWER_ATTR_BASE + 46L)                       // 1150046 (0x118c5e), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_MEASURE_COMPLETE_EVENT_OUTPUT_BEHAVIOR                           (NIDCPOWER_ATTR_BASE + 333L)                      // 1150333 (0x118d7d), ViInt32,    multi-channel

// -- Events::Measure Complete Event::Pulse --
#define NIDCPOWER_ATTR_MEASURE_COMPLETE_EVENT_PULSE_POLARITY                            (NIDCPOWER_ATTR_BASE + 44L)                       // 1150044 (0x118c5c), ViInt32,    multi-channel
#define NIDCPOWER_ATTR_MEASURE_COMPLETE_EVENT_PULSE_WIDTH                               (NIDCPOWER_ATTR_BASE + 45L)                       // 1150045 (0x118c5d), ViReal64,   multi-channel

// -- Events::Measure Complete Event::Toggle --
#define NIDCPOWER_ATTR_MEASURE_COMPLETE_EVENT_TOGGLE_INITIAL_STATE                      (NIDCPOWER_ATTR_BASE + 334L)                      // 1150334 (0x118d7e), ViInt32,    multi-channel

// -- Events::Sequence Iteration Complete Event --
#define NIDCPOWER_ATTR_SEQUENCE_ITERATION_COMPLETE_EVENT_OUTPUT_TERMINAL                (NIDCPOWER_ATTR_BASE + 40L)                       // 1150040 (0x118c58), ViString,   multi-channel
#define NIDCPOWER_ATTR_SEQUENCE_ITERATION_COMPLETE_EVENT_OUTPUT_BEHAVIOR                (NIDCPOWER_ATTR_BASE + 335L)                      // 1150335 (0x118d7f), ViInt32,    multi-channel

// -- Events::Sequence Iteration Complete Event::Pulse --
#define NIDCPOWER_ATTR_SEQUENCE_ITERATION_COMPLETE_EVENT_PULSE_POLARITY                 (NIDCPOWER_ATTR_BASE + 38L)                       // 1150038 (0x118c56), ViInt32,    multi-channel
#define NIDCPOWER_ATTR_SEQUENCE_ITERATION_COMPLETE_EVENT_PULSE_WIDTH                    (NIDCPOWER_ATTR_BASE + 39L)                       // 1150039 (0x118c57), ViReal64,   multi-channel

// -- Events::Sequence Iteration Complete Event::Toggle --
#define NIDCPOWER_ATTR_SEQUENCE_ITERATION_COMPLETE_EVENT_TOGGLE_INITIAL_STATE           (NIDCPOWER_ATTR_BASE + 336L)                      // 1150336 (0x118d80), ViInt32,    multi-channel

// -- Events::Sequence Engine Done Event --
#define NIDCPOWER_ATTR_SEQUENCE_ENGINE_DONE_EVENT_OUTPUT_TERMINAL                       (NIDCPOWER_ATTR_BASE + 50L)                       // 1150050 (0x118c62), ViString,   multi-channel
#define NIDCPOWER_ATTR_SEQUENCE_ENGINE_DONE_EVENT_OUTPUT_BEHAVIOR                       (NIDCPOWER_ATTR_BASE + 345L)                      // 1150345 (0x118d89), ViInt32,    multi-channel

// -- Events::Sequence Engine Done Event::Pulse --
#define NIDCPOWER_ATTR_SEQUENCE_ENGINE_DONE_EVENT_PULSE_POLARITY                        (NIDCPOWER_ATTR_BASE + 48L)                       // 1150048 (0x118c60), ViInt32,    multi-channel
#define NIDCPOWER_ATTR_SEQUENCE_ENGINE_DONE_EVENT_PULSE_WIDTH                           (NIDCPOWER_ATTR_BASE + 49L)                       // 1150049 (0x118c61), ViReal64,   multi-channel

// -- Events::Sequence Engine Done Event::Toggle --
#define NIDCPOWER_ATTR_SEQUENCE_ENGINE_DONE_EVENT_TOGGLE_INITIAL_STATE                  (NIDCPOWER_ATTR_BASE + 346L)                      // 1150346 (0x118d8a), ViInt32,    multi-channel

// -- Source::Advanced Sequencing --
#define NIDCPOWER_ATTR_ACTIVE_ADVANCED_SEQUENCE                                         (NIDCPOWER_ATTR_BASE + 74L)                       // 1150074 (0x118c7a), ViString,   multi-channel
#define NIDCPOWER_ATTR_ACTIVE_ADVANCED_SEQUENCE_STEP                                    (NIDCPOWER_ATTR_BASE + 75L)                       // 1150075 (0x118c7b), ViInt64,    multi-channel

// -- Triggers::Pulse Trigger --
#define NIDCPOWER_ATTR_PULSE_TRIGGER_TYPE                                               (NIDCPOWER_ATTR_BASE + 95L)                       // 1150095 (0x118c8f), ViInt32,    multi-channel
#define NIDCPOWER_ATTR_EXPORTED_PULSE_TRIGGER_OUTPUT_TERMINAL                           (NIDCPOWER_ATTR_BASE + 98L)                       // 1150098 (0x118c92), ViString,   multi-channel

// -- Triggers::Pulse Trigger::Digital Edge --
#define NIDCPOWER_ATTR_DIGITAL_EDGE_PULSE_TRIGGER_EDGE                                  (NIDCPOWER_ATTR_BASE + 96L)                       // 1150096 (0x118c90), ViInt32,    multi-channel
#define NIDCPOWER_ATTR_DIGITAL_EDGE_PULSE_TRIGGER_INPUT_TERMINAL                        (NIDCPOWER_ATTR_BASE + 97L)                       // 1150097 (0x118c91), ViString,   multi-channel

// -- Events::Pulse Complete Event --
#define NIDCPOWER_ATTR_PULSE_COMPLETE_EVENT_OUTPUT_TERMINAL                             (NIDCPOWER_ATTR_BASE + 99L)                       // 1150099 (0x118c93), ViString,   multi-channel

// -- Events::Pulse Complete Event::Pulse --
#define NIDCPOWER_ATTR_PULSE_COMPLETE_EVENT_PULSE_POLARITY                              (NIDCPOWER_ATTR_BASE + 100L)                      // 1150100 (0x118c94), ViInt32,    multi-channel
#define NIDCPOWER_ATTR_PULSE_COMPLETE_EVENT_PULSE_WIDTH                                 (NIDCPOWER_ATTR_BASE + 101L)                      // 1150101 (0x118c95), ViReal64,   multi-channel

// -- Events::Ready for Pulse Trigger Event --
#define NIDCPOWER_ATTR_READY_FOR_PULSE_TRIGGER_EVENT_OUTPUT_TERMINAL                    (NIDCPOWER_ATTR_BASE + 102L)                      // 1150102 (0x118c96), ViString,   multi-channel

// -- Events::Ready for Pulse Trigger Event::Pulse --
#define NIDCPOWER_ATTR_READY_FOR_PULSE_TRIGGER_EVENT_PULSE_POLARITY                     (NIDCPOWER_ATTR_BASE + 103L)                      // 1150103 (0x118c97), ViInt32,    multi-channel
#define NIDCPOWER_ATTR_READY_FOR_PULSE_TRIGGER_EVENT_PULSE_WIDTH                        (NIDCPOWER_ATTR_BASE + 104L)                      // 1150104 (0x118c98), ViReal64,   multi-channel

// -- Triggers::Shutdown Trigger --
#define NIDCPOWER_ATTR_SHUTDOWN_TRIGGER_TYPE                                            (NIDCPOWER_ATTR_BASE + 275L)                      // 1150275 (0x118d43), ViInt32,    multi-channel

// -- Triggers::Shutdown Trigger::Digital Edge --
#define NIDCPOWER_ATTR_DIGITAL_EDGE_SHUTDOWN_TRIGGER_EDGE                               (NIDCPOWER_ATTR_BASE + 276L)                      // 1150276 (0x118d44), ViInt32,    multi-channel
#define NIDCPOWER_ATTR_DIGITAL_EDGE_SHUTDOWN_TRIGGER_INPUT_TERMINAL                     (NIDCPOWER_ATTR_BASE + 277L)                      // 1150277 (0x118d45), ViString,   multi-channel

// -- LCR --
#define NIDCPOWER_ATTR_INSTRUMENT_MODE                                                  (NIDCPOWER_ATTR_BASE + 208L)                      // 1150208 (0x118d00), ViInt32,    multi-channel
#define NIDCPOWER_ATTR_LCR_MEASUREMENT_TIME                                             (NIDCPOWER_ATTR_BASE + 218L)                      // 1150218 (0x118d0a), ViInt32,    multi-channel
#define NIDCPOWER_ATTR_LCR_CUSTOM_MEASUREMENT_TIME                                      (NIDCPOWER_ATTR_BASE + 258L)                      // 1150258 (0x118d32), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_LCR_SOURCE_DELAY_MODE                                            (NIDCPOWER_ATTR_BASE + 315L)                      // 1150315 (0x118d6b), ViInt32,    multi-channel

// -- LCR::AC Stimulus --
#define NIDCPOWER_ATTR_LCR_STIMULUS_FUNCTION                                            (NIDCPOWER_ATTR_BASE + 209L)                      // 1150209 (0x118d01), ViInt32,    multi-channel
#define NIDCPOWER_ATTR_LCR_FREQUENCY                                                    (NIDCPOWER_ATTR_BASE + 210L)                      // 1150210 (0x118d02), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_LCR_VOLTAGE_AMPLITUDE                                            (NIDCPOWER_ATTR_BASE + 211L)                      // 1150211 (0x118d03), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_LCR_CURRENT_AMPLITUDE                                            (NIDCPOWER_ATTR_BASE + 212L)                      // 1150212 (0x118d04), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_LCR_AUTOMATIC_LEVEL_CONTROL                                      (NIDCPOWER_ATTR_BASE + 290L)                      // 1150290 (0x118d52), ViInt32,    multi-channel

// -- LCR::DC Bias --
#define NIDCPOWER_ATTR_LCR_DC_BIAS_SOURCE                                               (NIDCPOWER_ATTR_BASE + 213L)                      // 1150213 (0x118d05), ViInt32,    multi-channel
#define NIDCPOWER_ATTR_LCR_DC_BIAS_VOLTAGE_LEVEL                                        (NIDCPOWER_ATTR_BASE + 214L)                      // 1150214 (0x118d06), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_LCR_DC_BIAS_CURRENT_LEVEL                                        (NIDCPOWER_ATTR_BASE + 215L)                      // 1150215 (0x118d07), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_LCR_DC_BIAS_AUTOMATIC_LEVEL_CONTROL                              (NIDCPOWER_ATTR_BASE + 291L)                      // 1150291 (0x118d53), ViInt32,    multi-channel

// -- LCR::Impedance Range --
#define NIDCPOWER_ATTR_LCR_IMPEDANCE_AUTO_RANGE                                         (NIDCPOWER_ATTR_BASE + 216L)                      // 1150216 (0x118d08), ViInt32,    multi-channel
#define NIDCPOWER_ATTR_LCR_IMPEDANCE_RANGE                                              (NIDCPOWER_ATTR_BASE + 217L)                      // 1150217 (0x118d09), ViReal64,   multi-channel

// -- LCR::Compensation::Open --
#define NIDCPOWER_ATTR_LCR_OPEN_COMPENSATION_ENABLED                                    (NIDCPOWER_ATTR_BASE + 220L)                      // 1150220 (0x118d0c), ViBoolean,  multi-channel
#define NIDCPOWER_ATTR_LCR_OPEN_CONDUCTANCE                                             (NIDCPOWER_ATTR_BASE + 261L)                      // 1150261 (0x118d35), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_LCR_OPEN_SUSCEPTANCE                                             (NIDCPOWER_ATTR_BASE + 262L)                      // 1150262 (0x118d36), ViReal64,   multi-channel

// -- LCR::Compensation::Short --
#define NIDCPOWER_ATTR_LCR_SHORT_COMPENSATION_ENABLED                                   (NIDCPOWER_ATTR_BASE + 221L)                      // 1150221 (0x118d0d), ViBoolean,  multi-channel
#define NIDCPOWER_ATTR_LCR_SHORT_RESISTANCE                                             (NIDCPOWER_ATTR_BASE + 263L)                      // 1150263 (0x118d37), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_LCR_SHORT_REACTANCE                                              (NIDCPOWER_ATTR_BASE + 264L)                      // 1150264 (0x118d38), ViReal64,   multi-channel

// -- LCR::Compensation::Load --
#define NIDCPOWER_ATTR_LCR_LOAD_COMPENSATION_ENABLED                                    (NIDCPOWER_ATTR_BASE + 222L)                      // 1150222 (0x118d0e), ViBoolean,  multi-channel
#define NIDCPOWER_ATTR_LCR_MEASURED_LOAD_RESISTANCE                                     (NIDCPOWER_ATTR_BASE + 268L)                      // 1150268 (0x118d3c), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_LCR_MEASURED_LOAD_REACTANCE                                      (NIDCPOWER_ATTR_BASE + 269L)                      // 1150269 (0x118d3d), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_LCR_ACTUAL_LOAD_RESISTANCE                                       (NIDCPOWER_ATTR_BASE + 270L)                      // 1150270 (0x118d3e), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_LCR_ACTUAL_LOAD_REACTANCE                                        (NIDCPOWER_ATTR_BASE + 271L)                      // 1150271 (0x118d3f), ViReal64,   multi-channel

// -- LCR::Compensation --
#define NIDCPOWER_ATTR_LCR_OPEN_SHORT_LOAD_COMPENSATION_DATA_SOURCE                     (NIDCPOWER_ATTR_BASE + 223L)                      // 1150223 (0x118d0f), ViInt32,    multi-channel
#define NIDCPOWER_ATTR_LCR_SHORT_CUSTOM_CABLE_COMPENSATION_ENABLED                      (NIDCPOWER_ATTR_BASE + 299L)                      // 1150299 (0x118d5b), ViBoolean,  multi-channel
#define NIDCPOWER_ATTR_LCR_AC_ELECTRICAL_CABLE_LENGTH_DELAY                             (NIDCPOWER_ATTR_BASE + 309L)                      // 1150309 (0x118d65), ViReal64,   multi-channel

// -- LCR::AC Stimulus::Advanced --
#define NIDCPOWER_ATTR_LCR_VOLTAGE_RANGE                                                (NIDCPOWER_ATTR_BASE + 265L)                      // 1150265 (0x118d39), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_LCR_CURRENT_RANGE                                                (NIDCPOWER_ATTR_BASE + 267L)                      // 1150267 (0x118d3b), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_LCR_AC_DITHER_ENABLED                                            (NIDCPOWER_ATTR_BASE + 348L)                      // 1150348 (0x118d8c), ViBoolean,  multi-channel
#define NIDCPOWER_ATTR_LCR_SOURCE_APERTURE_TIME                                         (NIDCPOWER_ATTR_BASE + 349L)                      // 1150349 (0x118d8d), ViReal64,   multi-channel

// -- LCR::DC Bias::Advanced --
#define NIDCPOWER_ATTR_LCR_DC_BIAS_VOLTAGE_RANGE                                        (NIDCPOWER_ATTR_BASE + 266L)                      // 1150266 (0x118d3a), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_LCR_DC_BIAS_CURRENT_RANGE                                        (NIDCPOWER_ATTR_BASE + 274L)                      // 1150274 (0x118d42), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_LCR_DC_BIAS_TRANSIENT_RESPONSE                                   (NIDCPOWER_ATTR_BASE + 347L)                      // 1150347 (0x118d8b), ViInt32,    multi-channel

// -- Device Specific::LCR --
#define NIDCPOWER_ATTR_CABLE_LENGTH                                                     (NIDCPOWER_ATTR_BASE + 278L)                      // 1150278 (0x118d46), ViInt32,    multi-channel

// -- LCR::Impedance Range::Advanced --
#define NIDCPOWER_ATTR_LCR_LOAD_RESISTANCE                                              (NIDCPOWER_ATTR_BASE + 318L)                      // 1150318 (0x118d6e), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_LCR_LOAD_INDUCTANCE                                              (NIDCPOWER_ATTR_BASE + 319L)                      // 1150319 (0x118d6f), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_LCR_LOAD_CAPACITANCE                                             (NIDCPOWER_ATTR_BASE + 320L)                      // 1150320 (0x118d70), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_LCR_IMPEDANCE_RANGE_SOURCE                                       (NIDCPOWER_ATTR_BASE + 321L)                      // 1150321 (0x118d71), ViInt32,    multi-channel

// -- Source::Output Cutoff --
#define NIDCPOWER_ATTR_OUTPUT_CUTOFF_ENABLED                                            (NIDCPOWER_ATTR_BASE + 235L)                      // 1150235 (0x118d1b), ViBoolean,  multi-channel
#define NIDCPOWER_ATTR_OUTPUT_CUTOFF_VOLTAGE_OUTPUT_LIMIT_HIGH                          (NIDCPOWER_ATTR_BASE + 236L)                      // 1150236 (0x118d1c), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_OUTPUT_CUTOFF_CURRENT_MEASURE_LIMIT_HIGH                         (NIDCPOWER_ATTR_BASE + 237L)                      // 1150237 (0x118d1d), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_OUTPUT_CUTOFF_VOLTAGE_CHANGE_LIMIT_LOW                           (NIDCPOWER_ATTR_BASE + 238L)                      // 1150238 (0x118d1e), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_OUTPUT_CUTOFF_CURRENT_CHANGE_LIMIT_LOW                           (NIDCPOWER_ATTR_BASE + 239L)                      // 1150239 (0x118d1f), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_OUTPUT_CUTOFF_CURRENT_OVERRANGE_ENABLED                          (NIDCPOWER_ATTR_BASE + 240L)                      // 1150240 (0x118d20), ViBoolean,  multi-channel
#define NIDCPOWER_ATTR_OUTPUT_CUTOFF_VOLTAGE_OUTPUT_LIMIT_LOW                           (NIDCPOWER_ATTR_BASE + 292L)                      // 1150292 (0x118d54), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_OUTPUT_CUTOFF_CURRENT_MEASURE_LIMIT_LOW                          (NIDCPOWER_ATTR_BASE + 293L)                      // 1150293 (0x118d55), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_OUTPUT_CUTOFF_VOLTAGE_CHANGE_LIMIT_HIGH                          (NIDCPOWER_ATTR_BASE + 294L)                      // 1150294 (0x118d56), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_OUTPUT_CUTOFF_CURRENT_CHANGE_LIMIT_HIGH                          (NIDCPOWER_ATTR_BASE + 295L)                      // 1150295 (0x118d57), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_OUTPUT_CUTOFF_DELAY                                              (NIDCPOWER_ATTR_BASE + 300L)                      // 1150300 (0x118d5c), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_OUTPUT_CUTOFF_VOLTAGE_MEASURE_LIMIT_HIGH                         (NIDCPOWER_ATTR_BASE + 357L)                      // 1150357 (0x118d95), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_OUTPUT_CUTOFF_VOLTAGE_MEASURE_LIMIT_LOW                          (NIDCPOWER_ATTR_BASE + 358L)                      // 1150358 (0x118d96), ViReal64,   multi-channel

// -- Source::Constant Power --
#define NIDCPOWER_ATTR_CONSTANT_POWER_CURRENT_LIMIT                                     (NIDCPOWER_ATTR_BASE + 361L)                      // 1150361 (0x118d99), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_CONSTANT_POWER_LEVEL                                             (NIDCPOWER_ATTR_BASE + 363L)                      // 1150363 (0x118d9b), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_CONSTANT_POWER_LEVEL_RANGE                                       (NIDCPOWER_ATTR_BASE + 364L)                      // 1150364 (0x118d9c), ViReal64,   multi-channel

// -- Source::Constant Resistance --
#define NIDCPOWER_ATTR_CONSTANT_RESISTANCE_CURRENT_LIMIT                                (NIDCPOWER_ATTR_BASE + 367L)                      // 1150367 (0x118d9f), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_CONSTANT_RESISTANCE_LEVEL                                        (NIDCPOWER_ATTR_BASE + 369L)                      // 1150369 (0x118da1), ViReal64,   multi-channel
#define NIDCPOWER_ATTR_CONSTANT_RESISTANCE_LEVEL_RANGE                                  (NIDCPOWER_ATTR_BASE + 370L)                      // 1150370 (0x118da2), ViReal64,   multi-channel


/****************************************************************************
 *------------------ Attribute and Parameter Value Defines -----------------*
 ****************************************************************************/
// Values used by
//     NIDCPOWER_ATTR_CURRENT_LIMIT_BEHAVIOR
#define NIDCPOWER_VAL_CURRENT_REGULATE                                                  IVIDCPWR_VAL_CURRENT_REGULATE                     // 0 (0x0)
#define NIDCPOWER_VAL_CURRENT_TRIP                                                      IVIDCPWR_VAL_CURRENT_TRIP                         // 1 (0x1)

// Values used by
//     niDCPower_QueryOutputState
#define NIDCPOWER_VAL_OUTPUT_CONSTANT_VOLTAGE                                           IVIDCPWR_VAL_OUTPUT_CONSTANT_VOLTAGE              // 0 (0x0)
#define NIDCPOWER_VAL_OUTPUT_CONSTANT_CURRENT                                           IVIDCPWR_VAL_OUTPUT_CONSTANT_CURRENT              // 1 (0x1)
#define NIDCPOWER_VAL_OUTPUT_OVER_VOLTAGE                                               IVIDCPWR_VAL_OUTPUT_OVER_VOLTAGE                  // 2 (0x2)
#define NIDCPOWER_VAL_OUTPUT_OVER_CURRENT                                               IVIDCPWR_VAL_OUTPUT_OVER_CURRENT                  // 3 (0x3)
#define NIDCPOWER_VAL_OUTPUT_UNREGULATED                                                IVIDCPWR_VAL_OUTPUT_UNREGULATED                   // 4 (0x4)
#define NIDCPOWER_VAL_OUTPUT_INHIBITED                                                  (NIDCPOWER_VAL_BASE + 163L)                       // 1163 (0x48b)

// Values used by
//     niDCPower_Measure
#define NIDCPOWER_VAL_MEASURE_CURRENT                                                   IVIDCPWR_VAL_MEASURE_CURRENT                      // 0 (0x0)
#define NIDCPOWER_VAL_MEASURE_VOLTAGE                                                   IVIDCPWR_VAL_MEASURE_VOLTAGE                      // 1 (0x1)

// Values used by
//     niDCPower_CloseExtCal
#define NIDCPOWER_VAL_CANCEL                                                            (NIDCPOWER_VAL_BASE + 1L)                         // 1001 (0x3e9)
#define NIDCPOWER_VAL_COMMIT                                                            (NIDCPOWER_VAL_BASE + 2L)                         // 1002 (0x3ea)

// Values used by
//     NIDCPOWER_ATTR_POWER_SOURCE
#define NIDCPOWER_VAL_INTERNAL                                                          (NIDCPOWER_VAL_BASE + 3L)                         // 1003 (0x3eb)
#define NIDCPOWER_VAL_AUXILIARY                                                         (NIDCPOWER_VAL_BASE + 4L)                         // 1004 (0x3ec)
#define NIDCPOWER_VAL_AUTOMATIC                                                         (NIDCPOWER_VAL_BASE + 5L)                         // 1005 (0x3ed)

// Values used by
//     NIDCPOWER_ATTR_OUTPUT_FUNCTION
#define NIDCPOWER_VAL_DC_VOLTAGE                                                        (NIDCPOWER_VAL_BASE + 6L)                         // 1006 (0x3ee)
#define NIDCPOWER_VAL_DC_CURRENT                                                        (NIDCPOWER_VAL_BASE + 7L)                         // 1007 (0x3ef)
#define NIDCPOWER_VAL_PULSE_VOLTAGE                                                     (NIDCPOWER_VAL_BASE + 49L)                        // 1049 (0x419)
#define NIDCPOWER_VAL_PULSE_CURRENT                                                     (NIDCPOWER_VAL_BASE + 50L)                        // 1050 (0x41a)
#define NIDCPOWER_VAL_CONSTANT_RESISTANCE                                               (NIDCPOWER_VAL_BASE + 161L)                       // 1161 (0x489)
#define NIDCPOWER_VAL_CONSTANT_POWER                                                    (NIDCPOWER_VAL_BASE + 162L)                       // 1162 (0x48a)

// Values used by
//     NIDCPOWER_ATTR_SENSE
#define NIDCPOWER_VAL_LOCAL                                                             (NIDCPOWER_VAL_BASE + 8L)                         // 1008 (0x3f0)
#define NIDCPOWER_VAL_REMOTE                                                            (NIDCPOWER_VAL_BASE + 9L)                         // 1009 (0x3f1)

// Values used by
//     NIDCPOWER_ATTR_OUTPUT_CAPACITANCE
#define NIDCPOWER_VAL_LOW                                                               (NIDCPOWER_VAL_BASE + 10L)                        // 1010 (0x3f2)
#define NIDCPOWER_VAL_HIGH                                                              (NIDCPOWER_VAL_BASE + 11L)                        // 1011 (0x3f3)

// Values used by
//     NIDCPOWER_ATTR_MEASURE_TRIGGER_TYPE, NIDCPOWER_ATTR_PULSE_TRIGGER_TYPE,
//     NIDCPOWER_ATTR_SEQUENCE_ADVANCE_TRIGGER_TYPE, NIDCPOWER_ATTR_SHUTDOWN_TRIGGER_TYPE,
//     NIDCPOWER_ATTR_SOURCE_TRIGGER_TYPE, NIDCPOWER_ATTR_START_TRIGGER_TYPE
#define NIDCPOWER_VAL_NONE                                                              (NIDCPOWER_VAL_BASE + 12L)                        // 1012 (0x3f4)
#define NIDCPOWER_VAL_DIGITAL_EDGE                                                      (NIDCPOWER_VAL_BASE + 14L)                        // 1014 (0x3f6)
#define NIDCPOWER_VAL_SOFTWARE_EDGE                                                     (NIDCPOWER_VAL_BASE + 15L)                        // 1015 (0x3f7)

// Values used by
//     NIDCPOWER_ATTR_DIGITAL_EDGE_MEASURE_TRIGGER_EDGE, NIDCPOWER_ATTR_DIGITAL_EDGE_PULSE_TRIGGER_EDGE,
//     NIDCPOWER_ATTR_DIGITAL_EDGE_SEQUENCE_ADVANCE_TRIGGER_EDGE,
//     NIDCPOWER_ATTR_DIGITAL_EDGE_SHUTDOWN_TRIGGER_EDGE, NIDCPOWER_ATTR_DIGITAL_EDGE_SOURCE_TRIGGER_EDGE,
//     NIDCPOWER_ATTR_DIGITAL_EDGE_START_TRIGGER_EDGE
#define NIDCPOWER_VAL_RISING                                                            (NIDCPOWER_VAL_BASE + 16L)                        // 1016 (0x3f8)
#define NIDCPOWER_VAL_FALLING                                                           (NIDCPOWER_VAL_BASE + 17L)                        // 1017 (0x3f9)

// Values used by
//     NIDCPOWER_ATTR_MEASURE_COMPLETE_EVENT_PULSE_POLARITY,
//     NIDCPOWER_ATTR_PULSE_COMPLETE_EVENT_PULSE_POLARITY,
//     NIDCPOWER_ATTR_READY_FOR_PULSE_TRIGGER_EVENT_PULSE_POLARITY,
//     NIDCPOWER_ATTR_SEQUENCE_ENGINE_DONE_EVENT_PULSE_POLARITY,
//     NIDCPOWER_ATTR_SEQUENCE_ITERATION_COMPLETE_EVENT_PULSE_POLARITY,
//     NIDCPOWER_ATTR_SOURCE_COMPLETE_EVENT_PULSE_POLARITY
#define NIDCPOWER_VAL_ACTIVE_HIGH                                                       (NIDCPOWER_VAL_BASE + 18L)                        // 1018 (0x3fa)
#define NIDCPOWER_VAL_ACTIVE_LOW                                                        (NIDCPOWER_VAL_BASE + 19L)                        // 1019 (0x3fb)

// Values used by
//     NIDCPOWER_ATTR_SOURCE_MODE
#define NIDCPOWER_VAL_SINGLE_POINT                                                      (NIDCPOWER_VAL_BASE + 20L)                        // 1020 (0x3fc)
#define NIDCPOWER_VAL_SEQUENCE                                                          (NIDCPOWER_VAL_BASE + 21L)                        // 1021 (0x3fd)

// Values used by
//     NIDCPOWER_ATTR_AUTO_ZERO, niDCPower_ConfigureAutoZero
#define NIDCPOWER_VAL_OFF                                                               0                                                 // 0 (0x0)
#define NIDCPOWER_VAL_ONCE                                                              (NIDCPOWER_VAL_BASE + 24L)                        // 1024 (0x400)
#define NIDCPOWER_VAL_ON                                                                1                                                 // 1 (0x1)

// Values used by
//     NIDCPOWER_ATTR_MEASURE_WHEN
#define NIDCPOWER_VAL_AUTOMATICALLY_AFTER_SOURCE_COMPLETE                               (NIDCPOWER_VAL_BASE + 25L)                        // 1025 (0x401)
#define NIDCPOWER_VAL_ON_DEMAND                                                         (NIDCPOWER_VAL_BASE + 26L)                        // 1026 (0x402)
#define NIDCPOWER_VAL_ON_MEASURE_TRIGGER                                                (NIDCPOWER_VAL_BASE + 27L)                        // 1027 (0x403)

// Values used by
//     NIDCPOWER_ATTR_POWER_LINE_FREQUENCY
#define NIDCPOWER_VAL_50_HERTZ                                                          50.0
#define NIDCPOWER_VAL_60_HERTZ                                                          60.0

// Values used by
//     NIDCPOWER_ATTR_APERTURE_TIME_UNITS, NIDCPOWER_ATTR_AUTORANGE_MINIMUM_APERTURE_TIME_UNITS,
//     niDCPower_ConfigureApertureTime
#define NIDCPOWER_VAL_SECONDS                                                           (NIDCPOWER_VAL_BASE + 28L)                        // 1028 (0x404)
#define NIDCPOWER_VAL_POWER_LINE_CYCLES                                                 (NIDCPOWER_VAL_BASE + 29L)                        // 1029 (0x405)

// Values used by
//     niDCPower_ExportSignal, niDCPower_ExportSignalWithChannels
#define NIDCPOWER_VAL_SOURCE_COMPLETE_EVENT                                             (NIDCPOWER_VAL_BASE + 30L)                        // 1030 (0x406)
#define NIDCPOWER_VAL_MEASURE_COMPLETE_EVENT                                            (NIDCPOWER_VAL_BASE + 31L)                        // 1031 (0x407)
#define NIDCPOWER_VAL_SEQUENCE_ITERATION_COMPLETE_EVENT                                 (NIDCPOWER_VAL_BASE + 32L)                        // 1032 (0x408)
#define NIDCPOWER_VAL_SEQUENCE_ENGINE_DONE_EVENT                                        (NIDCPOWER_VAL_BASE + 33L)                        // 1033 (0x409)
#define NIDCPOWER_VAL_PULSE_COMPLETE_EVENT                                              (NIDCPOWER_VAL_BASE + 51L)                        // 1051 (0x41b)
#define NIDCPOWER_VAL_READY_FOR_PULSE_TRIGGER_EVENT                                     (NIDCPOWER_VAL_BASE + 52L)                        // 1052 (0x41c)
#define NIDCPOWER_VAL_START_TRIGGER                                                     (NIDCPOWER_VAL_BASE + 34L)                        // 1034 (0x40a)
#define NIDCPOWER_VAL_SOURCE_TRIGGER                                                    (NIDCPOWER_VAL_BASE + 35L)                        // 1035 (0x40b)
#define NIDCPOWER_VAL_MEASURE_TRIGGER                                                   (NIDCPOWER_VAL_BASE + 36L)                        // 1036 (0x40c)
#define NIDCPOWER_VAL_SEQUENCE_ADVANCE_TRIGGER                                          (NIDCPOWER_VAL_BASE + 37L)                        // 1037 (0x40d)
#define NIDCPOWER_VAL_PULSE_TRIGGER                                                     (NIDCPOWER_VAL_BASE + 53L)                        // 1053 (0x41d)
#define NIDCPOWER_VAL_SHUTDOWN_TRIGGER                                                  (NIDCPOWER_VAL_BASE + 118L)                       // 1118 (0x45e)

// Values used by
//     niDCPower_WaitForEvent, niDCPower_WaitForEventWithChannels
// #define NIDCPOWER_VAL_SOURCE_COMPLETE_EVENT                                          DEFINED ABOVE ((NIDCPOWER_VAL_BASE + 30L))        // 1030 (0x406)
// #define NIDCPOWER_VAL_MEASURE_COMPLETE_EVENT                                         DEFINED ABOVE ((NIDCPOWER_VAL_BASE + 31L))        // 1031 (0x407)
// #define NIDCPOWER_VAL_SEQUENCE_ITERATION_COMPLETE_EVENT                              DEFINED ABOVE ((NIDCPOWER_VAL_BASE + 32L))        // 1032 (0x408)
// #define NIDCPOWER_VAL_SEQUENCE_ENGINE_DONE_EVENT                                     DEFINED ABOVE ((NIDCPOWER_VAL_BASE + 33L))        // 1033 (0x409)
// #define NIDCPOWER_VAL_PULSE_COMPLETE_EVENT                                           DEFINED ABOVE ((NIDCPOWER_VAL_BASE + 51L))        // 1051 (0x41b)
// #define NIDCPOWER_VAL_READY_FOR_PULSE_TRIGGER_EVENT                                  DEFINED ABOVE ((NIDCPOWER_VAL_BASE + 52L))        // 1052 (0x41c)

// Values used by
//     niDCPower_SendSoftwareEdgeTrigger, niDCPower_SendSoftwareEdgeTriggerWithChannels
// #define NIDCPOWER_VAL_START_TRIGGER                                                  DEFINED ABOVE ((NIDCPOWER_VAL_BASE + 34L))        // 1034 (0x40a)
// #define NIDCPOWER_VAL_SOURCE_TRIGGER                                                 DEFINED ABOVE ((NIDCPOWER_VAL_BASE + 35L))        // 1035 (0x40b)
// #define NIDCPOWER_VAL_MEASURE_TRIGGER                                                DEFINED ABOVE ((NIDCPOWER_VAL_BASE + 36L))        // 1036 (0x40c)
// #define NIDCPOWER_VAL_SEQUENCE_ADVANCE_TRIGGER                                       DEFINED ABOVE ((NIDCPOWER_VAL_BASE + 37L))        // 1037 (0x40d)
// #define NIDCPOWER_VAL_PULSE_TRIGGER                                                  DEFINED ABOVE ((NIDCPOWER_VAL_BASE + 53L))        // 1053 (0x41d)
// #define NIDCPOWER_VAL_SHUTDOWN_TRIGGER                                               DEFINED ABOVE ((NIDCPOWER_VAL_BASE + 118L))       // 1118 (0x45e)

// Values used by
//     NIDCPOWER_ATTR_TRANSIENT_RESPONSE
#define NIDCPOWER_VAL_NORMAL                                                            (NIDCPOWER_VAL_BASE + 38L)                        // 1038 (0x40e)
#define NIDCPOWER_VAL_FAST                                                              (NIDCPOWER_VAL_BASE + 39L)                        // 1039 (0x40f)
#define NIDCPOWER_VAL_SLOW                                                              (NIDCPOWER_VAL_BASE + 41L)                        // 1041 (0x411)
#define NIDCPOWER_VAL_CUSTOM                                                            (NIDCPOWER_VAL_BASE + 42L)                        // 1042 (0x412)

// Values used by
//     NIDCPOWER_ATTR_DC_NOISE_REJECTION
#define NIDCPOWER_VAL_DC_NOISE_REJECTION_SECOND_ORDER                                   (NIDCPOWER_VAL_BASE + 43L)                        // 1043 (0x413)
#define NIDCPOWER_VAL_DC_NOISE_REJECTION_NORMAL                                         (NIDCPOWER_VAL_BASE + 44L)                        // 1044 (0x414)

// Values used by
//     NIDCPOWER_ATTR_SELF_CALIBRATION_PERSISTENCE
#define NIDCPOWER_VAL_KEEP_IN_MEMORY                                                    (NIDCPOWER_VAL_BASE + 45L)                        // 1045 (0x415)
#define NIDCPOWER_VAL_WRITE_TO_EEPROM                                                   (NIDCPOWER_VAL_BASE + 46L)                        // 1046 (0x416)

// Values used by
//     niDCPower_CalAdjustInternalReference, niDCPower_ConnectInternalReference
#define NIDCPOWER_VAL_INTERNAL_REFERENCE_5V                                             (NIDCPOWER_VAL_BASE + 54L)                        // 1054 (0x41e)
#define NIDCPOWER_VAL_INTERNAL_REFERENCE_100KOHM                                        (NIDCPOWER_VAL_BASE + 55L)                        // 1055 (0x41f)
#define NIDCPOWER_VAL_INTERNAL_REFERENCE_GROUND                                         (NIDCPOWER_VAL_BASE + 56L)                        // 1056 (0x420)
#define NIDCPOWER_VAL_INTERNAL_REFERENCE_NONE                                           (NIDCPOWER_VAL_BASE + 57L)                        // 1057 (0x421)
#define NIDCPOWER_VAL_INTERNAL_REFERENCE_7V                                             (NIDCPOWER_VAL_BASE + 119L)                       // 1119 (0x45f)
#define NIDCPOWER_VAL_INTERNAL_REFERENCE_1KOHM                                          (NIDCPOWER_VAL_BASE + 120L)                       // 1120 (0x460)

// Values used by
//     NIDCPOWER_ATTR_COMPLIANCE_LIMIT_SYMMETRY
#define NIDCPOWER_VAL_COMPLIANCE_LIMIT_SYMMETRY_SYMMETRIC                               0                                                 // 0 (0x0)
#define NIDCPOWER_VAL_COMPLIANCE_LIMIT_SYMMETRY_ASYMMETRIC                              1                                                 // 1 (0x1)

// Values used by
//     NIDCPOWER_ATTR_POWER_ALLOCATION_MODE
#define NIDCPOWER_VAL_POWER_ALLOCATION_MODE_DISABLED                                    (NIDCPOWER_VAL_BASE + 58L)                        // 1058 (0x422)
#define NIDCPOWER_VAL_POWER_ALLOCATION_MODE_AUTOMATIC                                   (NIDCPOWER_VAL_BASE + 59L)                        // 1059 (0x423)
#define NIDCPOWER_VAL_POWER_ALLOCATION_MODE_MANUAL                                      (NIDCPOWER_VAL_BASE + 60L)                        // 1060 (0x424)

// Values used by
//     NIDCPOWER_ATTR_INSTRUMENT_MODE
#define NIDCPOWER_VAL_SMU_PS                                                            (NIDCPOWER_VAL_BASE + 61L)                        // 1061 (0x425)
#define NIDCPOWER_VAL_LCR                                                               (NIDCPOWER_VAL_BASE + 62L)                        // 1062 (0x426)
#define NIDCPOWER_VAL_E_LOAD                                                            (NIDCPOWER_VAL_BASE + 154L)                       // 1154 (0x482)

// Values used by
//     NIDCPOWER_ATTR_LCR_STIMULUS_FUNCTION
#define NIDCPOWER_VAL_AC_VOLTAGE                                                        (NIDCPOWER_VAL_BASE + 63L)                        // 1063 (0x427)
#define NIDCPOWER_VAL_AC_CURRENT                                                        (NIDCPOWER_VAL_BASE + 64L)                        // 1064 (0x428)

// Values used by
//     NIDCPOWER_ATTR_LCR_DC_BIAS_SOURCE
#define NIDCPOWER_VAL_DC_BIAS_OFF                                                       (NIDCPOWER_VAL_BASE + 65L)                        // 1065 (0x429)
#define NIDCPOWER_VAL_DC_BIAS_VOLTAGE                                                   (NIDCPOWER_VAL_BASE + 66L)                        // 1066 (0x42a)
#define NIDCPOWER_VAL_DC_BIAS_CURRENT                                                   (NIDCPOWER_VAL_BASE + 67L)                        // 1067 (0x42b)

// Values used by
//     NIDCPOWER_ATTR_LCR_IMPEDANCE_AUTO_RANGE
#define NIDCPOWER_VAL_AUTO_RANGE_OFF                                                    (NIDCPOWER_VAL_BASE + 68L)                        // 1068 (0x42c)
#define NIDCPOWER_VAL_AUTO_RANGE_ON                                                     (NIDCPOWER_VAL_BASE + 70L)                        // 1070 (0x42e)

// Values used by
//     NIDCPOWER_ATTR_LCR_MEASUREMENT_TIME
#define NIDCPOWER_VAL_MEASUREMENT_TIME_SHORT                                            (NIDCPOWER_VAL_BASE + 71L)                        // 1071 (0x42f)
#define NIDCPOWER_VAL_MEASUREMENT_TIME_MEDIUM                                           (NIDCPOWER_VAL_BASE + 72L)                        // 1072 (0x430)
#define NIDCPOWER_VAL_MEASUREMENT_TIME_LONG                                             (NIDCPOWER_VAL_BASE + 73L)                        // 1073 (0x431)
#define NIDCPOWER_VAL_MEASUREMENT_TIME_CUSTOM                                           (NIDCPOWER_VAL_BASE + 117L)                       // 1117 (0x45d)

// Values used by
//     NIDCPOWER_ATTR_LCR_OPEN_SHORT_LOAD_COMPENSATION_DATA_SOURCE
#define NIDCPOWER_VAL_ONBOARD_STORAGE                                                   (NIDCPOWER_VAL_BASE + 74L)                        // 1074 (0x432)
#define NIDCPOWER_VAL_AS_DEFINED                                                        (NIDCPOWER_VAL_BASE + 75L)                        // 1075 (0x433)
#define NIDCPOWER_VAL_AS_CONFIGURED                                                     (NIDCPOWER_VAL_BASE + 146L)                       // 1146 (0x47a)

// Lcr Reference Value Type
#define NIDCPOWER_VAL_LCR_LOAD_COMPENSATION_SPOT_REFERENCE_VALUE_TYPE_IMPEDANCE         (NIDCPOWER_VAL_BASE + 76L)                        // 1076 (0x434)
#define NIDCPOWER_VAL_LCR_LOAD_COMPENSATION_SPOT_REFERENCE_VALUE_TYPE_IDEAL_CAPACITANCE (NIDCPOWER_VAL_BASE + 77L)                        // 1077 (0x435)
#define NIDCPOWER_VAL_LCR_LOAD_COMPENSATION_SPOT_REFERENCE_VALUE_TYPE_IDEAL_INDUCTANCE  (NIDCPOWER_VAL_BASE + 78L)                        // 1078 (0x436)
#define NIDCPOWER_VAL_LCR_LOAD_COMPENSATION_SPOT_REFERENCE_VALUE_TYPE_IDEAL_RESISTANCE  (NIDCPOWER_VAL_BASE + 79L)                        // 1079 (0x437)

// Values used by
//     niDCPower_ClearLatchedOutputCutoffState, niDCPower_QueryLatchedOutputCutoffState
#define NIDCPOWER_VAL_OUTPUT_CUTOFF_REASON_ALL                                          -1                                                // -1 (-0x1)
#define NIDCPOWER_VAL_OUTPUT_CUTOFF_REASON_VOLTAGE_OUTPUT_HIGH                          1                                                 // 1 (0x1)
#define NIDCPOWER_VAL_OUTPUT_CUTOFF_REASON_VOLTAGE_OUTPUT_LOW                           2                                                 // 2 (0x2)
#define NIDCPOWER_VAL_OUTPUT_CUTOFF_REASON_CURRENT_MEASURE_HIGH                         4                                                 // 4 (0x4)
#define NIDCPOWER_VAL_OUTPUT_CUTOFF_REASON_CURRENT_MEASURE_LOW                          8                                                 // 8 (0x8)
#define NIDCPOWER_VAL_OUTPUT_CUTOFF_REASON_VOLTAGE_CHANGE_HIGH                          16                                                // 16 (0x10)
#define NIDCPOWER_VAL_OUTPUT_CUTOFF_REASON_VOLTAGE_CHANGE_LOW                           32                                                // 32 (0x20)
#define NIDCPOWER_VAL_OUTPUT_CUTOFF_REASON_CURRENT_CHANGE_HIGH                          64                                                // 64 (0x40)
#define NIDCPOWER_VAL_OUTPUT_CUTOFF_REASON_CURRENT_CHANGE_LOW                           128                                               // 128 (0x80)
#define NIDCPOWER_VAL_OUTPUT_CUTOFF_REASON_VOLTAGE_SATURATED                            256                                               // 256 (0x100)
#define NIDCPOWER_VAL_OUTPUT_CUTOFF_REASON_CURRENT_SATURATED                            512                                               // 512 (0x200)
#define NIDCPOWER_VAL_OUTPUT_CUTOFF_REASON_VOLTAGE_MEASURE_HIGH                         1024                                              // 1024 (0x400)
#define NIDCPOWER_VAL_OUTPUT_CUTOFF_REASON_VOLTAGE_MEASURE_LOW                          2048                                              // 2048 (0x800)
#define NIDCPOWER_VAL_OUTPUT_CUTOFF_REASON_SELF_TEST_MEASUREMENT_HIGH                   4096                                              // 4096 (0x1000)
#define NIDCPOWER_VAL_OUTPUT_CUTOFF_REASON_SELF_TEST_MEASUREMENT_LOW                    8192                                              // 8192 (0x2000)

// Values used by
//     NIDCPOWER_ATTR_AUTORANGE_BEHAVIOR
#define NIDCPOWER_VAL_RANGE_UP_TO_LIMIT_THEN_DOWN                                       (NIDCPOWER_VAL_BASE + 107L)                       // 1107 (0x453)
#define NIDCPOWER_VAL_RANGE_UP                                                          (NIDCPOWER_VAL_BASE + 108L)                       // 1108 (0x454)
#define NIDCPOWER_VAL_RANGE_UP_AND_DOWN                                                 (NIDCPOWER_VAL_BASE + 109L)                       // 1109 (0x455)

// Values used by
//     NIDCPOWER_ATTR_AUTORANGE_APERTURE_TIME_MODE
#define NIDCPOWER_VAL_APERTURE_TIME_AUTO                                                (NIDCPOWER_VAL_BASE + 110L)                       // 1110 (0x456)
#define NIDCPOWER_VAL_APERTURE_TIME_CUSTOM                                              (NIDCPOWER_VAL_BASE + 111L)                       // 1111 (0x457)

// Values used by
//     NIDCPOWER_ATTR_AUTORANGE_THRESHOLD_MODE
#define NIDCPOWER_VAL_THRESHOLD_MODE_NORMAL                                             (NIDCPOWER_VAL_BASE + 112L)                       // 1112 (0x458)
#define NIDCPOWER_VAL_THRESHOLD_MODE_FAST_STEP                                          (NIDCPOWER_VAL_BASE + 113L)                       // 1113 (0x459)
#define NIDCPOWER_VAL_THRESHOLD_MODE_HIGH_HYSTERESIS                                    (NIDCPOWER_VAL_BASE + 114L)                       // 1114 (0x45a)
#define NIDCPOWER_VAL_THRESHOLD_MODE_MEDIUM_HYSTERESIS                                  (NIDCPOWER_VAL_BASE + 115L)                       // 1115 (0x45b)
#define NIDCPOWER_VAL_THRESHOLD_MODE_HOLD                                               (NIDCPOWER_VAL_BASE + 116L)                       // 1116 (0x45c)

// Values used by
//     NIDCPOWER_ATTR_CABLE_LENGTH
#define NIDCPOWER_VAL_ZERO_M                                                            (NIDCPOWER_VAL_BASE + 121L)                       // 1121 (0x461)
#define NIDCPOWER_VAL_NI_STANDARD_0_5M                                                  (NIDCPOWER_VAL_BASE + 153L)                       // 1153 (0x481)
#define NIDCPOWER_VAL_NI_STANDARD_1M                                                    (NIDCPOWER_VAL_BASE + 122L)                       // 1122 (0x462)
#define NIDCPOWER_VAL_NI_STANDARD_2M                                                    (NIDCPOWER_VAL_BASE + 123L)                       // 1123 (0x463)
#define NIDCPOWER_VAL_NI_STANDARD_4M                                                    (NIDCPOWER_VAL_BASE + 124L)                       // 1124 (0x464)
#define NIDCPOWER_VAL_NI_STANDARD_TRIAXIAL_1M                                           (NIDCPOWER_VAL_BASE + 139L)                       // 1139 (0x473)
#define NIDCPOWER_VAL_NI_STANDARD_TRIAXIAL_2M                                           (NIDCPOWER_VAL_BASE + 140L)                       // 1140 (0x474)
#define NIDCPOWER_VAL_NI_STANDARD_TRIAXIAL_4M                                           (NIDCPOWER_VAL_BASE + 141L)                       // 1141 (0x475)
#define NIDCPOWER_VAL_CUSTOM_ONBOARD_STORAGE                                            (NIDCPOWER_VAL_BASE + 125L)                       // 1125 (0x465)
#define NIDCPOWER_VAL_CUSTOM_AS_CONFIGURED                                              (NIDCPOWER_VAL_BASE + 126L)                       // 1126 (0x466)

// Values used by
//     NIDCPOWER_ATTR_ISOLATION_STATE
#define NIDCPOWER_VAL_ISOLATED                                                          (NIDCPOWER_VAL_BASE + 128L)                       // 1128 (0x468)
#define NIDCPOWER_VAL_NON_ISOLATED                                                      (NIDCPOWER_VAL_BASE + 129L)                       // 1129 (0x469)

// Values used by
//     niDCPower_GetLCRCompensationLastDateAndTime
#define NIDCPOWER_VAL_OPEN_COMPENSATION                                                 (NIDCPOWER_VAL_BASE + 130L)                       // 1130 (0x46a)
#define NIDCPOWER_VAL_SHORT_COMPENSATION                                                (NIDCPOWER_VAL_BASE + 131L)                       // 1131 (0x46b)
#define NIDCPOWER_VAL_LOAD_COMPENSATION                                                 (NIDCPOWER_VAL_BASE + 132L)                       // 1132 (0x46c)
#define NIDCPOWER_VAL_OPEN_CUSTOM_CABLE_COMPENSATION                                    (NIDCPOWER_VAL_BASE + 133L)                       // 1133 (0x46d)
#define NIDCPOWER_VAL_SHORT_CUSTOM_CABLE_COMPENSATION                                   (NIDCPOWER_VAL_BASE + 134L)                       // 1134 (0x46e)

// Values used by
//     NIDCPOWER_ATTR_APERTURE_TIME_AUTO_MODE
#define NIDCPOWER_VAL_APERTURE_TIME_AUTO_MODE_OFF                                       (NIDCPOWER_VAL_BASE + 135L)                       // 1135 (0x46f)
#define NIDCPOWER_VAL_APERTURE_TIME_AUTO_MODE_SHORT                                     (NIDCPOWER_VAL_BASE + 136L)                       // 1136 (0x470)
#define NIDCPOWER_VAL_APERTURE_TIME_AUTO_MODE_NORMAL                                    (NIDCPOWER_VAL_BASE + 137L)                       // 1137 (0x471)
#define NIDCPOWER_VAL_APERTURE_TIME_AUTO_MODE_LONG                                      (NIDCPOWER_VAL_BASE + 138L)                       // 1138 (0x472)

// Values used by
//     NIDCPOWER_ATTR_LCR_SOURCE_DELAY_MODE
#define NIDCPOWER_VAL_LCR_SOURCE_DELAY_MODE_AUTOMATIC                                   (NIDCPOWER_VAL_BASE + 144L)                       // 1144 (0x478)
#define NIDCPOWER_VAL_LCR_SOURCE_DELAY_MODE_MANUAL                                      (NIDCPOWER_VAL_BASE + 145L)                       // 1145 (0x479)

// Values used by
//     NIDCPOWER_ATTR_LCR_IMPEDANCE_RANGE_SOURCE
#define NIDCPOWER_VAL_LCR_IMPEDANCE_RANGE                                               (NIDCPOWER_VAL_BASE + 142L)                       // 1142 (0x476)
#define NIDCPOWER_VAL_LCR_LOAD_CONFIGURATION                                            (NIDCPOWER_VAL_BASE + 143L)                       // 1143 (0x477)

// Values used by
//     NIDCPOWER_ATTR_MEASURE_COMPLETE_EVENT_OUTPUT_BEHAVIOR,
//     NIDCPOWER_ATTR_SEQUENCE_ENGINE_DONE_EVENT_OUTPUT_BEHAVIOR,
//     NIDCPOWER_ATTR_SEQUENCE_ITERATION_COMPLETE_EVENT_OUTPUT_BEHAVIOR,
//     NIDCPOWER_ATTR_SOURCE_COMPLETE_EVENT_OUTPUT_BEHAVIOR
#define NIDCPOWER_VAL_EVENT_OUTPUT_BEHAVIOR_PULSE                                       (NIDCPOWER_VAL_BASE + 147L)                       // 1147 (0x47b)
#define NIDCPOWER_VAL_EVENT_OUTPUT_BEHAVIOR_TOGGLE                                      (NIDCPOWER_VAL_BASE + 148L)                       // 1148 (0x47c)

// Values used by
//     NIDCPOWER_ATTR_MEASURE_COMPLETE_EVENT_TOGGLE_INITIAL_STATE,
//     NIDCPOWER_ATTR_SEQUENCE_ENGINE_DONE_EVENT_TOGGLE_INITIAL_STATE,
//     NIDCPOWER_ATTR_SEQUENCE_ITERATION_COMPLETE_EVENT_TOGGLE_INITIAL_STATE,
//     NIDCPOWER_ATTR_SOURCE_COMPLETE_EVENT_TOGGLE_INITIAL_STATE
#define NIDCPOWER_VAL_EVENT_TOGGLE_INITIAL_STATE_LOW                                    (NIDCPOWER_VAL_BASE + 149L)                       // 1149 (0x47d)
#define NIDCPOWER_VAL_EVENT_TOGGLE_INITIAL_STATE_HIGH                                   (NIDCPOWER_VAL_BASE + 150L)                       // 1150 (0x47e)

// Values used by
//     NIDCPOWER_ATTR_LCR_DC_BIAS_TRANSIENT_RESPONSE
#define NIDCPOWER_VAL_LCR_DC_BIAS_TRANSIENT_RESPONSE_NORMAL                             (NIDCPOWER_VAL_BASE + 151L)                       // 1151 (0x47f)
#define NIDCPOWER_VAL_LCR_DC_BIAS_TRANSIENT_RESPONSE_CUSTOM                             (NIDCPOWER_VAL_BASE + 152L)                       // 1152 (0x480)

// Values used by
//     NIDCPOWER_ATTR_AUTORANGE
// #define NIDCPOWER_VAL_OFF                                                            DEFINED ABOVE (0)                                 // 0 (0x0)
// #define NIDCPOWER_VAL_ON                                                             DEFINED ABOVE (1)                                 // 1 (0x1)

// Values used by
//     NIDCPOWER_ATTR_CURRENT_LEVEL_AUTORANGE
// #define NIDCPOWER_VAL_OFF                                                            DEFINED ABOVE (0)                                 // 0 (0x0)
// #define NIDCPOWER_VAL_ON                                                             DEFINED ABOVE (1)                                 // 1 (0x1)

// Values used by
//     NIDCPOWER_ATTR_CURRENT_LIMIT_AUTORANGE
// #define NIDCPOWER_VAL_OFF                                                            DEFINED ABOVE (0)                                 // 0 (0x0)
// #define NIDCPOWER_VAL_ON                                                             DEFINED ABOVE (1)                                 // 1 (0x1)

// Values used by
//     NIDCPOWER_ATTR_LCR_AUTOMATIC_LEVEL_CONTROL, NIDCPOWER_ATTR_LCR_DC_BIAS_AUTOMATIC_LEVEL_CONTROL
// #define NIDCPOWER_VAL_OFF                                                            DEFINED ABOVE (0)                                 // 0 (0x0)
// #define NIDCPOWER_VAL_ON                                                             DEFINED ABOVE (1)                                 // 1 (0x1)

// Values used by
//     NIDCPOWER_ATTR_VOLTAGE_LEVEL_AUTORANGE
// #define NIDCPOWER_VAL_OFF                                                            DEFINED ABOVE (0)                                 // 0 (0x0)
// #define NIDCPOWER_VAL_ON                                                             DEFINED ABOVE (1)                                 // 1 (0x1)

// Values used by
//     NIDCPOWER_ATTR_VOLTAGE_LIMIT_AUTORANGE
// #define NIDCPOWER_VAL_OFF                                                            DEFINED ABOVE (0)                                 // 0 (0x0)
// #define NIDCPOWER_VAL_ON                                                             DEFINED ABOVE (1)                                 // 1 (0x1)

// Values used by
//     NIDCPOWER_ATTR_POWER_SOURCE_IN_USE
// #define NIDCPOWER_VAL_INTERNAL                                                       DEFINED ABOVE ((NIDCPOWER_VAL_BASE + 3L))         // 1003 (0x3eb)
// #define NIDCPOWER_VAL_AUXILIARY                                                      DEFINED ABOVE ((NIDCPOWER_VAL_BASE + 4L))         // 1004 (0x3ec)

// Values used by
//     NIDCPOWER_ATTR_CONDUCTION_VOLTAGE_MODE
#define NIDCPOWER_VAL_CONDUCTION_VOLTAGE_MODE_AUTOMATIC                                 (NIDCPOWER_VAL_BASE + 155L)                       // 1155 (0x483)
#define NIDCPOWER_VAL_CONDUCTION_VOLTAGE_MODE_ENABLED                                   (NIDCPOWER_VAL_BASE + 156L)                       // 1156 (0x484)
#define NIDCPOWER_VAL_CONDUCTION_VOLTAGE_MODE_DISABLED                                  (NIDCPOWER_VAL_BASE + 157L)                       // 1157 (0x485)


/****************************************************************************
 *------------------- Instrument Driver Type Definitions -------------------*
 ****************************************************************************/
#if !defined(_NIComplexNumber)
#define _NIComplexNumber
typedef struct NIComplexNumber_struct
{
    ViReal64 real;
    ViReal64 imaginary;
} NIComplexNumber;
#endif // !defined(_NIComplexNumber)

#pragma pack(push,8)
#if !defined(_NILCRMeasurement)
#define _NILCRMeasurement
typedef struct NILCRMeasurement_struct
{
    // -- DC Bias Values --
    ViReal64 Vdc;
    ViReal64 Idc;
    // -- Stimulus Frequency --
    ViReal64 stimulusFrequency;
    // -- Raw Measurements --
    NIComplexNumber ACVoltage;
    NIComplexNumber ACCurrent;
    // -- Z Values --
    NIComplexNumber Z;
    ViReal64 ZMagnitude;
    ViReal64 ZPhase;
    // -- Y Values --
    NIComplexNumber Y;
    ViReal64 YMagnitude;
    ViReal64 YPhase;
    // -- Series Model Values --
    ViReal64 Ls;
    ViReal64 Cs;
    ViReal64 Rs;
    // -- Parallel Model Values --
    ViReal64 Lp;
    ViReal64 Cp;
    ViReal64 Rp;
    // -- Dissipation Factor & Q Factor --
    ViReal64 D;
    ViReal64 Q;
    // -- Measurement Metadata --
    ViUInt16 measurementMode;
    ViBoolean dcInCompliance;
    ViBoolean acInCompliance;
    ViBoolean unbalanced;
    // -- Reserved for Future Use --
    ViReal64 reserved1;
    ViReal64 reserved2;
    ViReal64 reserved3;
    ViReal64 reserved4;
    ViReal64 reserved5;
    ViReal64 reserved6;
    ViReal64 reserved7;
} NILCRMeasurement;
#endif // !defined(_NILCRMeasurement)

#pragma pack(pop)
#if defined(_WIN64) || defined(__linux__)
#pragma pack(push,8)
#else
#pragma pack(push,1)
#endif
#if !defined(_NILCRLoadCompensationSpot)
#define _NILCRLoadCompensationSpot
typedef struct NILCRLoadCompensationSpot_struct
{
    ViReal64 frequency;
    ViInt32 referenceValueType;
    ViReal64 referenceValueA;
    ViReal64 referenceValueB;
} NILCRLoadCompensationSpot;
#endif // !defined(_NILCRLoadCompensationSpot)

#pragma pack(pop)



/****************************************************************************
 *---------------- Instrument Driver Function Declarations -----------------*
 ****************************************************************************/
// -- Initialize/Close --
ViStatus _VI_FUNC niDCPower_InitializeWithChannels(
   ViRsrc resourceName,
   ViConstString channels,
   ViBoolean reset,
   ViConstString optionString,
   ViSession* vi);

ViStatus _VI_FUNC niDCPower_InitializeWithIndependentChannels(
   ViRsrc resourceName,
   ViBoolean reset,
   ViConstString optionString,
   ViSession* vi);

ViStatus _VI_FUNC niDCPower_close(
   ViSession vi);

// -- Source --
ViStatus _VI_FUNC niDCPower_ConfigureSourceMode(
   ViSession vi,
   ViInt32 sourceMode);

ViStatus _VI_FUNC niDCPower_ConfigureSourceModeWithChannels(
   ViSession vi,
   ViConstString channelName,
   ViInt32 sourceMode);

ViStatus _VI_FUNC niDCPower_ConfigureOutputFunction(
   ViSession vi,
   ViConstString channelName,
   ViInt32 function);

ViStatus _VI_FUNC niDCPower_ConfigureOutputEnabled(
   ViSession vi,
   ViConstString channelName,
   ViBoolean enabled);

ViStatus _VI_FUNC niDCPower_SetSequence(
   ViSession vi,
   ViConstString channelName,
   const ViReal64 values[],
   const ViReal64 sourceDelays[],
   ViUInt32 size);

// -- Source::DC Voltage --
ViStatus _VI_FUNC niDCPower_ConfigureVoltageLevel(
   ViSession vi,
   ViConstString channelName,
   ViReal64 level);

ViStatus _VI_FUNC niDCPower_ConfigureCurrentLimit(
   ViSession vi,
   ViConstString channelName,
   ViInt32 behavior,
   ViReal64 limit);

ViStatus _VI_FUNC niDCPower_ConfigureVoltageLevelRange(
   ViSession vi,
   ViConstString channelName,
   ViReal64 range);

ViStatus _VI_FUNC niDCPower_ConfigureCurrentLimitRange(
   ViSession vi,
   ViConstString channelName,
   ViReal64 range);

ViStatus _VI_FUNC niDCPower_ConfigureOutputResistance(
   ViSession vi,
   ViConstString channelName,
   ViReal64 resistance);

// -- Source::DC Current --
ViStatus _VI_FUNC niDCPower_ConfigureCurrentLevel(
   ViSession vi,
   ViConstString channelName,
   ViReal64 level);

ViStatus _VI_FUNC niDCPower_ConfigureCurrentLevelRange(
   ViSession vi,
   ViConstString channelName,
   ViReal64 range);

ViStatus _VI_FUNC niDCPower_ConfigureVoltageLimit(
   ViSession vi,
   ViConstString channelName,
   ViReal64 limit);

ViStatus _VI_FUNC niDCPower_ConfigureVoltageLimitRange(
   ViSession vi,
   ViConstString channelName,
   ViReal64 range);

// -- Source::Pulse Voltage --
ViStatus _VI_FUNC niDCPower_ConfigurePulseVoltageLevel(
   ViSession vi,
   ViConstString channelName,
   ViReal64 level);

ViStatus _VI_FUNC niDCPower_ConfigurePulseCurrentLimit(
   ViSession vi,
   ViConstString channelName,
   ViReal64 limit);

ViStatus _VI_FUNC niDCPower_ConfigurePulseBiasVoltageLevel(
   ViSession vi,
   ViConstString channelName,
   ViReal64 level);

ViStatus _VI_FUNC niDCPower_ConfigurePulseBiasCurrentLimit(
   ViSession vi,
   ViConstString channelName,
   ViReal64 limit);

ViStatus _VI_FUNC niDCPower_ConfigurePulseVoltageLevelRange(
   ViSession vi,
   ViConstString channelName,
   ViReal64 range);

ViStatus _VI_FUNC niDCPower_ConfigurePulseCurrentLimitRange(
   ViSession vi,
   ViConstString channelName,
   ViReal64 range);

// -- Source::Pulse Current --
ViStatus _VI_FUNC niDCPower_ConfigurePulseCurrentLevel(
   ViSession vi,
   ViConstString channelName,
   ViReal64 level);

ViStatus _VI_FUNC niDCPower_ConfigurePulseVoltageLimit(
   ViSession vi,
   ViConstString channelName,
   ViReal64 limit);

ViStatus _VI_FUNC niDCPower_ConfigurePulseBiasCurrentLevel(
   ViSession vi,
   ViConstString channelName,
   ViReal64 level);

ViStatus _VI_FUNC niDCPower_ConfigurePulseBiasVoltageLimit(
   ViSession vi,
   ViConstString channelName,
   ViReal64 limit);

ViStatus _VI_FUNC niDCPower_ConfigurePulseCurrentLevelRange(
   ViSession vi,
   ViConstString channelName,
   ViReal64 range);

ViStatus _VI_FUNC niDCPower_ConfigurePulseVoltageLimitRange(
   ViSession vi,
   ViConstString channelName,
   ViReal64 range);

// -- Source::Advanced Sequencing --
ViStatus _VI_FUNC niDCPower_CreateAdvancedSequence(
   ViSession vi,
   ViConstString sequenceName,
   ViInt32 attributeIdCount,
   const ViInt32 attributeIds[],
   ViBoolean setAsActiveSequence);

ViStatus _VI_FUNC niDCPower_CreateAdvancedSequenceWithChannels(
   ViSession vi,
   ViConstString channelName,
   ViConstString sequenceName,
   ViInt32 attributeIdCount,
   const ViInt32 attributeIds[],
   ViBoolean setAsActiveSequence);

ViStatus _VI_FUNC niDCPower_CreateAdvancedSequenceStep(
   ViSession vi,
   ViBoolean setAsActiveStep);

ViStatus _VI_FUNC niDCPower_CreateAdvancedSequenceStepWithChannels(
   ViSession vi,
   ViConstString channelName,
   ViBoolean setAsActiveStep);

ViStatus _VI_FUNC niDCPower_CreateAdvancedSequenceCommitStepWithChannels(
   ViSession vi,
   ViConstString channelName,
   ViBoolean setAsActiveStep);

ViStatus _VI_FUNC niDCPower_DeleteAdvancedSequence(
   ViSession vi,
   ViConstString sequenceName);

ViStatus _VI_FUNC niDCPower_DeleteAdvancedSequenceWithChannels(
   ViSession vi,
   ViConstString channelName,
   ViConstString sequenceName);

// -- Measure --
ViStatus _VI_FUNC niDCPower_ConfigureApertureTime(
   ViSession vi,
   ViConstString channelName,
   ViReal64 apertureTime,
   ViInt32 units);

ViStatus _VI_FUNC niDCPower_ConfigureAutoZero(
   ViSession vi,
   ViConstString channelName,
   ViInt32 autoZero);

ViStatus _VI_FUNC niDCPower_ConfigurePowerLineFrequency(
   ViSession vi,
   ViReal64 powerlineFrequency);

ViStatus _VI_FUNC niDCPower_ConfigureSense(
   ViSession vi,
   ViConstString channelName,
   ViInt32 sense);

ViStatus _VI_FUNC niDCPower_Measure(
   ViSession vi,
   ViConstString channelName,
   ViInt32 measurementType,
   ViReal64* measurement);

ViStatus _VI_FUNC niDCPower_MeasureMultiple(
   ViSession vi,
   ViConstString channelName,
   ViReal64 voltageMeasurements[],
   ViReal64 currentMeasurements[]);

ViStatus _VI_FUNC niDCPower_FetchMultiple(
   ViSession vi,
   ViConstString channelName,
   ViReal64 timeout,
   ViInt32 count,
   ViReal64 voltageMeasurements[],
   ViReal64 currentMeasurements[],
   ViBoolean inCompliance[],
   ViInt32* actualCount);

ViStatus _VI_FUNC niDCPower_MeasureMultipleLCR(
   ViSession vi,
   ViConstString channelName,
   NILCRMeasurement measurements[]);

ViStatus _VI_FUNC niDCPower_FetchMultipleLCR(
   ViSession vi,
   ViConstString channelName,
   ViReal64 timeout,
   ViInt32 count,
   NILCRMeasurement measurements[],
   ViInt32* actualCount);

// -- Query --
ViStatus _VI_FUNC niDCPower_QueryInCompliance(
   ViSession vi,
   ViConstString channelName,
   ViBoolean* inCompliance);

ViStatus _VI_FUNC niDCPower_QueryOutputState(
   ViSession vi,
   ViConstString channelName,
   ViInt32 outputState,
   ViBoolean* inState);

ViStatus _VI_FUNC niDCPower_QueryLatchedOutputCutoffState(
   ViSession vi,
   ViConstString channelName,
   ViInt32 outputCutoffReason,
   ViBoolean* outputCutoffState);

ViStatus _VI_FUNC niDCPower_ClearLatchedOutputCutoffState(
   ViSession vi,
   ViConstString channelName,
   ViInt32 outputCutoffReason);

ViStatus _VI_FUNC niDCPower_QueryMaxCurrentLimit(
   ViSession vi,
   ViConstString channelName,
   ViReal64 voltageLevel,
   ViReal64* maxCurrentLimit);

ViStatus _VI_FUNC niDCPower_QueryMaxVoltageLevel(
   ViSession vi,
   ViConstString channelName,
   ViReal64 currentLimit,
   ViReal64* maxVoltageLevel);

ViStatus _VI_FUNC niDCPower_QueryMinCurrentLimit(
   ViSession vi,
   ViConstString channelName,
   ViReal64 voltageLevel,
   ViReal64* minCurrentLimit);

// -- Control --
ViStatus _VI_FUNC niDCPower_Commit(
   ViSession vi);

ViStatus _VI_FUNC niDCPower_CommitWithChannels(
   ViSession vi,
   ViConstString channelName);

ViStatus _VI_FUNC niDCPower_Initiate(
   ViSession vi);

ViStatus _VI_FUNC niDCPower_InitiateWithChannels(
   ViSession vi,
   ViConstString channelName);

ViStatus _VI_FUNC niDCPower_Abort(
   ViSession vi);

ViStatus _VI_FUNC niDCPower_AbortWithChannels(
   ViSession vi,
   ViConstString channelName);

// -- Calibration::External Calibration --
ViStatus _VI_FUNC niDCPower_InitExtCal(
   ViRsrc resourceName,
   ViConstString password,
   ViSession* vi);

ViStatus _VI_FUNC niDCPower_CloseExtCal(
   ViSession vi,
   ViInt32 action);

ViStatus _VI_FUNC niDCPower_CalAdjustVoltageLevel(
   ViSession vi,
   ViConstString channelName,
   ViReal64 range,
   ViUInt32 numberOfMeasurements,
   const ViReal64 requestedOutputs[],
   const ViReal64 measuredOutputs[]);

ViStatus _VI_FUNC niDCPower_CalAdjustVoltageMeasurement(
   ViSession vi,
   ViConstString channelName,
   ViReal64 range,
   ViUInt32 numberOfMeasurements,
   const ViReal64 reportedOutputs[],
   const ViReal64 measuredOutputs[]);

ViStatus _VI_FUNC niDCPower_CalAdjustCurrentLimit(
   ViSession vi,
   ViConstString channelName,
   ViReal64 range,
   ViUInt32 numberOfMeasurements,
   const ViReal64 requestedOutputs[],
   const ViReal64 measuredOutputs[]);

ViStatus _VI_FUNC niDCPower_CalAdjustCurrentMeasurement(
   ViSession vi,
   ViConstString channelName,
   ViReal64 range,
   ViUInt32 numberOfMeasurements,
   const ViReal64 reportedOutputs[],
   const ViReal64 measuredOutputs[]);

ViStatus _VI_FUNC niDCPower_CalAdjustOutputResistance(
   ViSession vi,
   ViConstString channelName,
   ViUInt32 numberOfMeasurements,
   const ViReal64 requestedOutputs[],
   const ViReal64 measuredOutputs[]);

ViStatus _VI_FUNC niDCPower_CalAdjustResidualVoltageOffset(
   ViSession vi,
   ViConstString channelName);

ViStatus _VI_FUNC niDCPower_CalAdjustResidualCurrentOffset(
   ViSession vi,
   ViConstString channelName);

ViStatus _VI_FUNC niDCPower_ConnectInternalReference(
   ViSession vi,
   ViInt32 internalReference);

ViStatus _VI_FUNC niDCPower_CalAdjustInternalReference(
   ViSession vi,
   ViInt32 internalReference,
   ViReal64 adjustedInternalReference);

ViStatus _VI_FUNC niDCPower_CalBeginACFlatness(
   ViSession vi,
   ViConstString channelName,
   ViUInt32* totalNumberOfSteps);

ViStatus _VI_FUNC niDCPower_CalConfigACFlatness(
   ViSession vi,
   ViConstString channelName,
   ViReal64* generatedFrequency,
   ViReal64* generatedVoltageRMS);

ViStatus _VI_FUNC niDCPower_CalAdjustACFlatness(
   ViSession vi,
   ViConstString channelName,
   ViReal64 generatedFrequency,
   ViReal64 generatedVoltageRMS,
   ViReal64 measuredVoltageRMS,
   ViUInt32* numberOfStepsRemaining);

ViStatus _VI_FUNC niDCPower_CalEndACFlatness(
   ViSession vi,
   ViConstString channelName);

// -- Calibration --
ViStatus _VI_FUNC niDCPower_CalSelfCalibrate(
   ViSession vi,
   ViConstString channelName);

// -- Calibration::Calibration Utility --
ViStatus _VI_FUNC niDCPower_ChangeExtCalPassword(
   ViSession vi,
   ViConstString oldPassword,
   ViConstString newPassword);

ViStatus _VI_FUNC niDCPower_GetExtCalRecommendedInterval(
   ViSession vi,
   ViInt32* months);

ViStatus _VI_FUNC niDCPower_GetExtCalLastDateAndTime(
   ViSession vi,
   ViInt32* year,
   ViInt32* month,
   ViInt32* day,
   ViInt32* hour,
   ViInt32* minute);

ViStatus _VI_FUNC niDCPower_GetCalUserDefinedInfoMaxSize(
   ViSession vi,
   ViInt32* infoSize);

ViStatus _VI_FUNC niDCPower_SetCalUserDefinedInfo(
   ViSession vi,
   ViConstString info);

ViStatus _VI_FUNC niDCPower_GetCalUserDefinedInfo(
   ViSession vi,
   ViString info);

ViStatus _VI_FUNC niDCPower_ReadCurrentTemperature(
   ViSession vi,
   ViReal64* temperature);

ViStatus _VI_FUNC niDCPower_GetExtCalLastTemp(
   ViSession vi,
   ViReal64* temperature);

ViStatus _VI_FUNC niDCPower_GetSelfCalLastDateAndTime(
   ViSession vi,
   ViInt32* year,
   ViInt32* month,
   ViInt32* day,
   ViInt32* hour,
   ViInt32* minute);

ViStatus _VI_FUNC niDCPower_GetSelfCalLastTemp(
   ViSession vi,
   ViReal64* temperature);

// -- Calibration::LCR Compensation --
ViStatus _VI_FUNC niDCPower_GetLCRCompensationLastDateAndTime(
   ViSession vi,
   ViConstString channelName,
   ViInt32 compensationType,
   ViInt32* year,
   ViInt32* month,
   ViInt32* day,
   ViInt32* hour,
   ViInt32* minute);

ViStatus _VI_FUNC niDCPower_PerformLCROpenCompensation(
   ViSession vi,
   ViConstString channelName,
   ViInt32 numFrequencies,
   const ViReal64 additionalFrequencies[]);

ViStatus _VI_FUNC niDCPower_PerformLCRShortCompensation(
   ViSession vi,
   ViConstString channelName,
   ViInt32 numFrequencies,
   const ViReal64 additionalFrequencies[]);

ViStatus _VI_FUNC niDCPower_PerformLCRLoadCompensation(
   ViSession vi,
   ViConstString channelName,
   ViInt32 numCompensationSpots,
   const NILCRLoadCompensationSpot compensationSpots[]);

ViStatus _VI_FUNC niDCPower_ConfigureLCRCompensation(
   ViSession vi,
   ViConstString channelName,
   ViInt32 compensationDataSize,
   ViAddr compensationData);

// -- Triggers and Events::Start Trigger --
ViStatus _VI_FUNC niDCPower_ConfigureDigitalEdgeStartTrigger(
   ViSession vi,
   ViConstString inputTerminal,
   ViInt32 edge);

ViStatus _VI_FUNC niDCPower_ConfigureDigitalEdgeStartTriggerWithChannels(
   ViSession vi,
   ViConstString channelName,
   ViConstString inputTerminal,
   ViInt32 edge);

ViStatus _VI_FUNC niDCPower_ConfigureSoftwareEdgeStartTrigger(
   ViSession vi);

ViStatus _VI_FUNC niDCPower_ConfigureSoftwareEdgeStartTriggerWithChannels(
   ViSession vi,
   ViConstString channelName);

ViStatus _VI_FUNC niDCPower_DisableStartTrigger(
   ViSession vi);

ViStatus _VI_FUNC niDCPower_DisableStartTriggerWithChannels(
   ViSession vi,
   ViConstString channelName);

// -- Triggers and Events::Sequence Advance Trigger --
ViStatus _VI_FUNC niDCPower_ConfigureDigitalEdgeSequenceAdvanceTrigger(
   ViSession vi,
   ViConstString inputTerminal,
   ViInt32 edge);

ViStatus _VI_FUNC niDCPower_ConfigureDigitalEdgeSequenceAdvanceTriggerWithChannels(
   ViSession vi,
   ViConstString channelName,
   ViConstString inputTerminal,
   ViInt32 edge);

ViStatus _VI_FUNC niDCPower_ConfigureSoftwareEdgeSequenceAdvanceTrigger(
   ViSession vi);

ViStatus _VI_FUNC niDCPower_ConfigureSoftwareEdgeSequenceAdvanceTriggerWithChannels(
   ViSession vi,
   ViConstString channelName);

ViStatus _VI_FUNC niDCPower_DisableSequenceAdvanceTrigger(
   ViSession vi);

ViStatus _VI_FUNC niDCPower_DisableSequenceAdvanceTriggerWithChannels(
   ViSession vi,
   ViConstString channelName);

// -- Triggers and Events::Source Trigger --
ViStatus _VI_FUNC niDCPower_ConfigureDigitalEdgeSourceTrigger(
   ViSession vi,
   ViConstString inputTerminal,
   ViInt32 edge);

ViStatus _VI_FUNC niDCPower_ConfigureDigitalEdgeSourceTriggerWithChannels(
   ViSession vi,
   ViConstString channelName,
   ViConstString inputTerminal,
   ViInt32 edge);

ViStatus _VI_FUNC niDCPower_ConfigureSoftwareEdgeSourceTrigger(
   ViSession vi);

ViStatus _VI_FUNC niDCPower_ConfigureSoftwareEdgeSourceTriggerWithChannels(
   ViSession vi,
   ViConstString channelName);

ViStatus _VI_FUNC niDCPower_DisableSourceTrigger(
   ViSession vi);

ViStatus _VI_FUNC niDCPower_DisableSourceTriggerWithChannels(
   ViSession vi,
   ViConstString channelName);

// -- Triggers and Events::Measure Trigger --
ViStatus _VI_FUNC niDCPower_ConfigureDigitalEdgeMeasureTrigger(
   ViSession vi,
   ViConstString inputTerminal,
   ViInt32 edge);

ViStatus _VI_FUNC niDCPower_ConfigureDigitalEdgeMeasureTriggerWithChannels(
   ViSession vi,
   ViConstString channelName,
   ViConstString inputTerminal,
   ViInt32 edge);

ViStatus _VI_FUNC niDCPower_ConfigureSoftwareEdgeMeasureTrigger(
   ViSession vi);

ViStatus _VI_FUNC niDCPower_ConfigureSoftwareEdgeMeasureTriggerWithChannels(
   ViSession vi,
   ViConstString channelName);

// -- Triggers and Events::Pulse Trigger --
ViStatus _VI_FUNC niDCPower_ConfigureDigitalEdgePulseTrigger(
   ViSession vi,
   ViConstString inputTerminal,
   ViInt32 edge);

ViStatus _VI_FUNC niDCPower_ConfigureDigitalEdgePulseTriggerWithChannels(
   ViSession vi,
   ViConstString channelName,
   ViConstString inputTerminal,
   ViInt32 edge);

ViStatus _VI_FUNC niDCPower_ConfigureSoftwareEdgePulseTrigger(
   ViSession vi);

ViStatus _VI_FUNC niDCPower_ConfigureSoftwareEdgePulseTriggerWithChannels(
   ViSession vi,
   ViConstString channelName);

ViStatus _VI_FUNC niDCPower_DisablePulseTrigger(
   ViSession vi);

ViStatus _VI_FUNC niDCPower_DisablePulseTriggerWithChannels(
   ViSession vi,
   ViConstString channelName);

// -- Triggers and Events::Shutdown Trigger --
ViStatus _VI_FUNC niDCPower_ConfigureDigitalEdgeShutdownTriggerWithChannels(
   ViSession vi,
   ViConstString channelName,
   ViConstString inputTerminal,
   ViInt32 edge);

ViStatus _VI_FUNC niDCPower_ConfigureSoftwareEdgeShutdownTriggerWithChannels(
   ViSession vi,
   ViConstString channelName);

ViStatus _VI_FUNC niDCPower_DisableShutdownTriggerWithChannels(
   ViSession vi,
   ViConstString channelName);

// -- Triggers and Events --
ViStatus _VI_FUNC niDCPower_ExportSignal(
   ViSession vi,
   ViInt32 signal,
   ViConstString signalIdentifier,
   ViConstString outputTerminal);

ViStatus _VI_FUNC niDCPower_ExportSignalWithChannels(
   ViSession vi,
   ViConstString channelName,
   ViInt32 signal,
   ViConstString signalIdentifier,
   ViConstString outputTerminal);

ViStatus _VI_FUNC niDCPower_SendSoftwareEdgeTrigger(
   ViSession vi,
   ViInt32 trigger);

ViStatus _VI_FUNC niDCPower_SendSoftwareEdgeTriggerWithChannels(
   ViSession vi,
   ViConstString channelName,
   ViInt32 trigger);

ViStatus _VI_FUNC niDCPower_WaitForEvent(
   ViSession vi,
   ViInt32 eventId,
   ViReal64 timeout);

ViStatus _VI_FUNC niDCPower_WaitForEventWithChannels(
   ViSession vi,
   ViConstString channelName,
   ViInt32 eventId,
   ViReal64 timeout);

// -- Utility --
ViStatus _VI_FUNC niDCPower_Disable(
   ViSession vi);

ViStatus _VI_FUNC niDCPower_reset(
   ViSession vi);

ViStatus _VI_FUNC niDCPower_ResetWithChannels(
   ViSession vi,
   ViConstString channelName);

ViStatus _VI_FUNC niDCPower_ResetDevice(
   ViSession vi);

ViStatus _VI_FUNC niDCPower_self_test(
   ViSession vi,
   ViInt16* selfTestResult,
   ViChar selfTestMessage[IVI_MAX_MESSAGE_BUF_SIZE]);

// -- Utility::IVI Functions --
ViStatus _VI_FUNC niDCPower_revision_query(
   ViSession vi,
   ViChar instrumentDriverRevision[IVI_MAX_MESSAGE_BUF_SIZE],
   ViChar firmwareRevision[IVI_MAX_MESSAGE_BUF_SIZE]);

ViStatus _VI_FUNC niDCPower_ResetWithDefaults(
   ViSession vi);

ViStatus _VI_FUNC niDCPower_GetChannelName(
   ViSession vi,
   ViInt32 index,
   ViInt32 bufferSize,
   ViChar channelName[]);

ViStatus _VI_FUNC niDCPower_GetChannelNameFromString(
   ViSession vi,
   ViConstString index,
   ViInt32 bufferSize,
   ViChar channelName[]);

ViStatus _VI_FUNC niDCPower_GetNextCoercionRecord(
   ViSession vi,
   ViInt32 bufferSize,
   ViChar coercionRecord[]);

ViStatus _VI_FUNC niDCPower_ClearInterchangeWarnings(
   ViSession vi);

ViStatus _VI_FUNC niDCPower_ResetInterchangeCheck(
   ViSession vi);

ViStatus _VI_FUNC niDCPower_GetNextInterchangeWarning(
   ViSession vi,
   ViInt32 bufferSize,
   ViChar interchangeWarning[]);

ViStatus _VI_FUNC niDCPower_InvalidateAllAttributes(
   ViSession vi);

ViStatus _VI_FUNC niDCPower_ConfigureOVP(
   ViSession vi,
   ViConstString channelName,
   ViBoolean enabled,
   ViReal64 limit);

// -- Utility::Error Info --
ViStatus _VI_FUNC niDCPower_GetError(
   ViSession vi,
   ViStatus* code,
   ViInt32 bufferSize,
   ViChar description[]);

ViStatus _VI_FUNC niDCPower_ClearError(
   ViSession vi);

ViStatus _VI_FUNC niDCPower_error_message(
   ViSession vi,
   ViStatus errorCode,
   ViChar errorMessage[IVI_MAX_MESSAGE_BUF_SIZE]);

ViStatus _VI_FUNC niDCPower_error_query(
   ViSession vi,
   ViInt32* errorCode,
   ViChar errorMessage[IVI_MAX_MESSAGE_BUF_SIZE]);

// -- Utility::Locking --
ViStatus _VI_FUNC niDCPower_LockSession(
   ViSession vi,
   ViBoolean* callerHasLock);

ViStatus _VI_FUNC niDCPower_UnlockSession(
   ViSession vi,
   ViBoolean* callerHasLock);

// -- Set/Get Attribute::Set Attribute --
ViStatus _VI_FUNC niDCPower_SetAttributeViInt32(
   ViSession vi,
   ViConstString channelName,
   ViAttr attributeId,
   ViInt32 attributeValue);

ViStatus _VI_FUNC niDCPower_SetAttributeViInt64(
   ViSession vi,
   ViConstString channelName,
   ViAttr attributeId,
   ViInt64 attributeValue);

ViStatus _VI_FUNC niDCPower_SetAttributeViReal64(
   ViSession vi,
   ViConstString channelName,
   ViAttr attributeId,
   ViReal64 attributeValue);

ViStatus _VI_FUNC niDCPower_SetAttributeViString(
   ViSession vi,
   ViConstString channelName,
   ViAttr attributeId,
   ViConstString attributeValue);

ViStatus _VI_FUNC niDCPower_SetAttributeViSession(
   ViSession vi,
   ViConstString channelName,
   ViAttr attributeId,
   ViSession attributeValue);

ViStatus _VI_FUNC niDCPower_SetAttributeViBoolean(
   ViSession vi,
   ViConstString channelName,
   ViAttr attributeId,
   ViBoolean attributeValue);

// -- Set/Get Attribute::Get Attribute --
ViStatus _VI_FUNC niDCPower_GetAttributeViInt32(
   ViSession vi,
   ViConstString channelName,
   ViAttr attributeId,
   ViInt32* attributeValue);

ViStatus _VI_FUNC niDCPower_GetAttributeViInt64(
   ViSession vi,
   ViConstString channelName,
   ViAttr attributeId,
   ViInt64* attributeValue);

ViStatus _VI_FUNC niDCPower_GetAttributeViReal64(
   ViSession vi,
   ViConstString channelName,
   ViAttr attributeId,
   ViReal64* attributeValue);

ViStatus _VI_FUNC niDCPower_GetAttributeViString(
   ViSession vi,
   ViConstString channelName,
   ViAttr attributeId,
   ViInt32 bufferSize,
   ViChar attributeValue[]);

ViStatus _VI_FUNC niDCPower_GetAttributeViSession(
   ViSession vi,
   ViConstString channelName,
   ViAttr attributeId,
   ViSession* attributeValue);

ViStatus _VI_FUNC niDCPower_GetAttributeViBoolean(
   ViSession vi,
   ViConstString channelName,
   ViAttr attributeId,
   ViBoolean* attributeValue);

// -- Utility::Import/Export Attribute Configuration --
ViStatus _VI_FUNC niDCPower_ImportAttributeConfigurationFile(
   ViSession vi,
   ViConstString filePath);

ViStatus _VI_FUNC niDCPower_ExportAttributeConfigurationFile(
   ViSession vi,
   ViConstString filePath);

ViStatus _VI_FUNC niDCPower_ImportAttributeConfigurationBuffer(
   ViSession vi,
   ViInt32 size,
   ViAddr configuration);

ViStatus _VI_FUNC niDCPower_ExportAttributeConfigurationBuffer(
   ViSession vi,
   ViInt32 size,
   ViAddr configuration);

// -- Calibration::LCR Compensation::LCR Custom Cable Compensation --
ViStatus _VI_FUNC niDCPower_PerformLCROpenCustomCableCompensation(
   ViSession vi,
   ViConstString channelName);

ViStatus _VI_FUNC niDCPower_PerformLCRShortCustomCableCompensation(
   ViSession vi,
   ViConstString channelName);

ViStatus _VI_FUNC niDCPower_GetLCRCompensationData(
   ViSession vi,
   ViConstString channelName,
   ViInt32 compensationDataSize,
   ViAddr compensationData);


/*- nidcpowerObsolete.h included for backwards compatibility -*/
#include "nidcpowerObsolete.h"

/****************************************************************************
 *---------------------------- End Include File ----------------------------*
 ****************************************************************************/

#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif
#endif /* __NIDCPOWER_HEADER */
