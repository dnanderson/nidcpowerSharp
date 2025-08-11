using System;

namespace nidcpowerSharp
{
    /// <summary>
    /// Represents an error that occurred in the NI-DCPower driver.
    /// </summary>
    public class NiDCPowerException : Exception
    {
        /// <summary>
        /// Gets the error code returned by the NI-DCPower driver.
        /// </summary>
        public int ErrorCode { get; }

        /// <summary>
        /// Initializes a new instance of the <see cref="NiDCPowerException"/> class.
        /// </summary>
        /// <param name="errorCode">The error code returned by the driver.</param>
        /// <param name="message">The error message.</param>
        public NiDCPowerException(int errorCode, string message) : base(message)
        {
            ErrorCode = errorCode;
        }
    }
}
