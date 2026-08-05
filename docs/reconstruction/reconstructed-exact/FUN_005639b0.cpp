// =============================================================================
// FUN_005639b0
// -----------------------------------------------------------------------------
// Stable ID: aa_005639b0
// Address:   0x005639b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005639b0 @ 0x005639b0
// Stable ID: aa_005639b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: while×1, if×1, return×1.
//  - Notable callees: FUN_004022a0×2, FUN_004294f0, FUN_005639b0, LeaveCriticalSection.
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

void __thiscall FUN_005639b0(int param_1,int *param_2)



{

  int *piVar1;

  int iVar2;

  uint32_t /* width from decompiler */ local_4;

  

  piVar1 = param_2;

  *(int *)(param_1 + -0x140) = *param_2;

  *(int *)(param_1 + -0x13c) = param_2[1];

  local_4 = 0;

  FUN_004294f0();

  iVar2 = FUN_004022a0(&local_4,&param_2);

  while (iVar2 == 0) {

    (**(code **)(*param_2 + 0x14c))(piVar1);

    iVar2 = FUN_004022a0(&local_4,&param_2);

  }

  if (*(char *)(param_1 + -0x104) != '\0') {

    *(uint8_t *)(param_1 + -0x104) = 0;

    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + -0x128));

  }

  return;

}
