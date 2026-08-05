// =============================================================================
// FUN_007a4480  →  NDError_Log
// -----------------------------------------------------------------------------
// Stable ID: aa_007a4480
// Address:   0x007a4480 – 0x007a44d0  (autoassault.exe, image base 0x400000)
// System:    libND diagnostics (NDError.cpp)
// Generated: 2026-07-29 dual A/B seal (OWN-ONLY); supersedes 2026-07-23 scaffold
// Exactness: Behavior-preserving rewrite of decompiler control flow + bytes.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================
//
// PURPOSE:
//   Conditional ND error logger (libND/NDError.cpp line 101 stamp).
//   enable==1 && fmt!=NULL → _vsnprintf(local[2048], fmt, va) then
//   vog_LogMessage(fixed path, 0x65, 3, local). Else no-op.
//   Call-site string "VOG_DEBUG_STOP" is NOT this function's identity;
//   FUN_007a4480(0,"VOG_DEBUG_STOP") is a pure no-op in this body.
//
// Canonical human name: NDError_Log  (see NDError_Log.cpp)
// Alias: Named_NDError_007a4480
//
// ABI: __cdecl varargs; plain RET.
// Callees: _vsnprintf, vog_LogMessage.
// =============================================================================

/* Prefer semantic export: */
/* void NDError_Log(char enable, const char *fmt, ...); */

void FUN_007a4480(char param_1, char *param_2, ...)
{
  char local_800[2048];

  if ((param_1 == '\x01') && (param_2 != (char *)0x0)) {
    /* Decompiler shows &stack0x0000000c as the va_list start (args after fmt). */
    _vsnprintf(local_800, 0x800, param_2, (char *)&param_2 + 4);
    vog_LogMessage(
        "C:\\vog\\1_code\\vog_14_117_branch\\libND\\NDError.cpp",
        0x65,
        3,
        local_800);
  }
  return;
}
