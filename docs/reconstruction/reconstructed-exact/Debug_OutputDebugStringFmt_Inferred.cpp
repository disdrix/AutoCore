// =============================================================================
// Debug_OutputDebugStringFmt_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0076c130
// Address:   0x0076c130  (autoassault.exe, image base 0x400000)
// System:    debug / OutputDebugString
// Generated: 2026-08-04 W38-Y OWN-ONLY dual
// Exactness: Behavior-preserving rewrite of decompiler + byte-sealed ABI.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE: cdecl varargs printf-style wrapper around OutputDebugStringA.
//   - format == NULL → no-op
//   - formats into a 2048-byte stack buffer via _vsnprintf
//   - emits buffer with OutputDebugStringA
//   - plain RET; caller cleans vararg stack
//
// Body: 0x0076c130–0x0076c16b exclusive (59 B / 0x3B).
// Ghidra: FUN_0076c130. Reject Named_CalleeOf_Client_RecvLoginFail_0076c130.
// =============================================================================

#include <cstdint>
#include <cstdarg>

extern "C" int __cdecl _vsnprintf(char *buffer, size_t count, const char *format, va_list argptr);
extern "C" void __stdcall OutputDebugStringA(const char *lpOutputString);

// cdecl varargs; void
void Debug_OutputDebugStringFmt_Inferred(const char *format, ...)
{
  char buf[0x800];

  if (format == nullptr) {
    return;
  }

  va_list ap;
  va_start(ap, format);
  _vsnprintf(buf, 0x800, format, ap);
  va_end(ap);

  OutputDebugStringA(buf);
}
