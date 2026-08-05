// =============================================================================
// FUN_00827460
// -----------------------------------------------------------------------------
// Stable ID: aa_00827460
// Address:   0x00827460  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00827460 @ 0x00827460
// Stable ID: aa_00827460
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: CONCAT31, FUN_00826780, FUN_00827460.
//  - Return sites: 2.

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

uint8_t __fastcall FUN_00827460(int *param_1)



{

  int iVar1;

  char cVar2;

  uint8_t uVar3;

  

  iVar1 = param_1[0x152];

  if ((iVar1 != 0) && (iVar1 != 6)) {

    FUN_00826780(CONCAT31((int3)((uint)iVar1 >> 8),(char)param_1[0x13f] == '\0'));

  }

  cVar2 = (**(code **)(*param_1 + 0x3d8))();

  if ((cVar2 != '\0') && (param_1[0x12e] != 0)) {

                    /* WARNING: Could not recover jumptable at 0x008274a2. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    uVar3 = (**(code **)(*(int *)param_1[0x12e] + 0x394))();

    return uVar3;

  }

  return *(uint8_t *)((int)param_1 + 0x496);

}
