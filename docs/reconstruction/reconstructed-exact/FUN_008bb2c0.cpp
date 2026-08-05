// =============================================================================
// FUN_008bb2c0
// -----------------------------------------------------------------------------
// Stable ID: aa_008bb2c0
// Address:   0x008bb2c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008bb2c0 @ 0x008bb2c0
// Stable ID: aa_008bb2c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×2, while×1, return×1.
//  - Notable callees: FUN_004113b0×2, FUN_00410d60, FUN_004294f0, FUN_008bb2c0, LeaveCriticalSection.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void FUN_008bb2c0(void)



{

  int in_EAX;

  int iVar1;

  void *local_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0;

  FUN_004294f0();

  iVar1 = FUN_004113b0(in_EAX + 0x530,&local_8);

  while (iVar1 == 0) {

    if (local_8 != (void *)0x0) {

      operator_delete__(local_8);

    }

    local_8 = (void *)0x0;

    iVar1 = FUN_004113b0(in_EAX + 0x530,&local_8);

  }

  if (*(char *)(in_EAX + 0x558) != '\0') {

    *(uint8_t *)(in_EAX + 0x558) = 0;

    LeaveCriticalSection((LPCRITICAL_SECTION)(in_EAX + 0x534));

  }

  FUN_00410d60();

  return;

}
