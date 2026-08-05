// =============================================================================
// NDError_Log  (FUN_007a4480 / Named_NDError_007a4480)
// -----------------------------------------------------------------------------
// Stable ID: aa_007a4480
// Address:   0x007a4480 – 0x007a44d0  (autoassault.exe, image base 0x400000)
// System:    libND diagnostics (NDError.cpp)
// Generated: 2026-07-29 dual A/B seal (OWN-ONLY)
// Exactness: Behavior-preserving rewrite of decompiler + read_memory body.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Conditional error logger. Logs only when enable == 1 and fmt != NULL.
//   Formats with _vsnprintf into a 2048-byte stack buffer, then calls
//   vog_LogMessage with fixed source stamp:
//     path  = "...\\libND\\NDError.cpp"  @ 0x00a97124
//     line  = 0x65 (101)
//     level = 3
//
//   Common call sites pass enable=0 with "VOG_DEBUG_STOP" — pure no-ops here.
//   This is NOT a hard stop / DebugBreak / abort.
//
// ABI: __cdecl, varargs. Plain RET (caller cleans stack).
// Callees: _vsnprintf (IAT), vog_LogMessage.
// =============================================================================

#include <cstdio>   // _vsnprintf
#include <cstdarg>

// External logger (address recovered separately; name from Ghidra).
extern void vog_LogMessage(const char *path, int line, int level, const char *msg);

void NDError_Log(char enable, const char *fmt, ...)
{
    char local_800[0x800];

    if (enable == 1 && fmt != nullptr) {
        va_list ap;
        va_start(ap, fmt);
        _vsnprintf(local_800, 0x800, fmt, ap);
        va_end(ap);

        vog_LogMessage(
            "C:\\vog\\1_code\\vog_14_117_branch\\libND\\NDError.cpp",
            0x65,
            3,
            local_800);
    }
}
