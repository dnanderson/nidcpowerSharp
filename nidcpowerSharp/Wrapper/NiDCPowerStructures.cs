using System.Runtime.InteropServices;

namespace nidcpowerSharp.Wrapper
{
    [StructLayout(LayoutKind.Sequential, Pack = 8)]
    public struct NIComplexNumber
    {
        public double real;
        public double imaginary;
    }

    [StructLayout(LayoutKind.Sequential, Pack = 8)]
    public struct NILCRMeasurement
    {
        public double Vdc;
        public double Idc;
        public double stimulusFrequency;
        public NIComplexNumber ACVoltage;
        public NIComplexNumber ACCurrent;
        public NIComplexNumber Z;
        public double ZMagnitude;
        public double ZPhase;
        public NIComplexNumber Y;
        public double YMagnitude;
        public double YPhase;
        public double Ls;
        public double Cs;
        public double Rs;
        public double Lp;
        public double Cp;
        public double Rp;
        public double D;
        public double Q;
        public ushort measurementMode;
        public ushort dcInCompliance;
        public ushort acInCompliance;
        public ushort unbalanced;
        public double reserved1;
        public double reserved2;
        public double reserved3;
        public double reserved4;
        public double reserved5;
        public double reserved6;
        public double reserved7;
    }

    [StructLayout(LayoutKind.Sequential, Pack = 8)]
    public struct NILCRLoadCompensationSpot
    {
        public double frequency;
        public int referenceValueType;
        public double referenceValueA;
        public double referenceValueB;
    }
}
