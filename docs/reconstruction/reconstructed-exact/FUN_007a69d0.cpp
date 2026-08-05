// =============================================================================
// Locale_GetInstance_Inferred (FUN_007a69d0)
// -----------------------------------------------------------------------------
// Stable ID: aa_007a69d0
// Address:   0x007a69d0–0x007a6a29  (autoassault.exe, image base 0x400000)
// System:    locale / string-table (cross-cutting)
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE:
//   Meyers-style singleton getter for the process-wide locale/language string-table
//   object at DAT_00d1f660. First call sets DAT_00d1f728 bit0, constructs via
//   FUN_007a6910, registers atexit → FUN_007a6890 dtor. Always returns &DAT_00d1f660.
//
//   NOT a chat/toast/message API — no string args. Localization is FUN_007a6de0
//   (thiscall). Locale code is *(obj+0x2c) (0 default; 1/2/3 = FR/DE/UK consumers).
//
// Dual A/B: reviews/A_aa_007a69d0_Locale_GetInstance_Inferred.md
//           reviews/B_aa_007a69d0_Locale_GetInstance_Inferred.md

// READABILITY:
//  - Body size: ~90 bytes; if×1, return×1.
//  - Callees: FUN_007a6910, _atexit.
//  - Return: always &DAT_00d1f660 in EAX.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile + read_memory seal 2026-07-29.
 * - SEH frame is MSVC once-init scaffolding; does not change return.
 * - Runtime / differential verification: OPEN.
 */

// void* Locale_GetInstance_Inferred(void);
undefined * FUN_007a69d0(void)
{
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;

  puStack_8 = &LAB_009ab5de;
  local_c = ExceptionList;
  if ((DAT_00d1f728 & 1) == 0) {
    DAT_00d1f728 = DAT_00d1f728 | 1;
    local_4 = 0;
    ExceptionList = &local_c;
    FUN_007a6910(&DAT_00d1f660);
    _atexit((_func_4879 *)&LAB_009c30b0);
  }
  ExceptionList = local_c;
  return &DAT_00d1f660;
}
