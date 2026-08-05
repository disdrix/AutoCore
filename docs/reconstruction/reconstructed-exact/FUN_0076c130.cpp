// =============================================================================
// FUN_0076c130  (twin of Debug_OutputDebugStringFmt_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0076c130
// Address:   0x0076c130  (autoassault.exe, image base 0x400000)
// Wave:      W38-Y OWN-ONLY dual
// Note:      Ghidra symbol twin; prefer Debug_OutputDebugStringFmt_Inferred.cpp
// =============================================================================

#include <cstdint>
#include <cstdarg>

extern "C" int __cdecl _vsnprintf(char *buffer, size_t count, const char *format, va_list argptr);
extern "C" void __stdcall OutputDebugStringA(const char *lpOutputString);

void FUN_0076c130(const char *format, ...)
{
  char local_800[0x800];

  if (format != nullptr) {
    va_list ap;
    va_start(ap, format);
    _vsnprintf(local_800, 0x800, format, ap);
    va_end(ap);
    OutputDebugStringA(local_800);
  }
}
