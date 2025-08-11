using System;
using System.Runtime.InteropServices;

namespace nidcpowerSharp.Wrapper
{
    [StructLayout(LayoutKind.Sequential)]
    public struct ViSession
    {
        private readonly IntPtr _handle;

        public ViSession(IntPtr handle)
        {
            _handle = handle;
        }
    }

    public static class IviBoolean
    {
        public const ushort False = 0;
        public const ushort True = 1;
    }
}
