// =============================================================================
// FUN_0056bf70
// -----------------------------------------------------------------------------
// Stable ID: aa_0056bf70
// Address:   0x0056bf70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0056bf70 @ 0x0056bf70
// Stable ID: aa_0056bf70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×2, while×1, return×1.
//  - Notable callees: FUN_004022a0×2, FUN_004294f0, FUN_0056bf70, FUN_0056f0b0, LeaveCriticalSection.
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

void __fastcall FUN_0056bf70(int param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ *local_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0;

  local_8 = (uint32_t /* width from decompiler */ *)0x0;

  FUN_004294f0();

  iVar1 = FUN_004022a0(&local_4,&local_8);

  while (iVar1 == 0) {

    if (local_8 != (uint32_t /* width from decompiler */ *)0x0) {

      (**(code **)*local_8)(1);

    }

    iVar1 = FUN_004022a0(&local_4,&local_8);

  }

  iVar1 = *(int *)(param_1 + 0x13c);

  if (*(char *)(iVar1 + 0x28) != '\0') {

    *(uint8_t *)(iVar1 + 0x28) = 0;

    LeaveCriticalSection((LPCRITICAL_SECTION)(iVar1 + 4));

  }

  FUN_0056f0b0();

  return;

}
