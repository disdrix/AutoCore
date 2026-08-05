// =============================================================================
// FUN_004048c0  (scaffold alias → Win32_ThrowLastErrorAsHresult_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_004048c0
// Address:   0x004048c0  (autoassault.exe, image base 0x400000)
// Body:      0x004048c0–0x004048d9 (26 bytes)
// System:    crt-com
// Generated: 2026-07-23 scaffold; refined 2026-07-29 W22-G dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// Canonical clean: Win32_ThrowLastErrorAsHresult_Inferred.cpp
// =============================================================================

// PURPOSE: GetLastError → HRESULT_FROM_WIN32 (if signed > 0) → throw via FUN_004048e0.
// READABILITY: control flow preserved from Ghidra decompile; names cleaned.

#include <stdint.h>
#include <windows.h>

extern void FUN_004048e0(uint32_t code); /* noreturn */

void FUN_004048c0(void)
{
  DWORD DVar1;

  DVar1 = GetLastError();
  if (0 < (int)DVar1) {
    DVar1 = DVar1 & 0xffff | 0x80070000;
  }
  /* WARNING: Subroutine does not return */
  FUN_004048e0(DVar1);
}
