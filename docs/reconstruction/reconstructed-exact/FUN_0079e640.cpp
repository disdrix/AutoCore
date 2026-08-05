// =============================================================================
// FUN_0079e640
// -----------------------------------------------------------------------------
// Stable ID: aa_0079e640
// Address:   0x0079e640  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0079e640 @ 0x0079e640
// Stable ID: aa_0079e640
// Embedded strings (evidence for future rename):
//   - "gShadowColor"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0079e640.
//  - Strings: "gShadowColor".
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

void FUN_0079e640(uint32_t /* width from decompiler */ param_1)



{

  int *piVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  

  iVar2 = DAT_00d1f05c;

  if (*(int *)(*(int *)(DAT_00d1f05c + 4) + 0xc) == 0) {

    uVar3 = 0;

  }

  else {

    piVar1 = *(int **)(*(int *)(DAT_00d1f05c + 4) + 0xc);

    uVar3 = (**(code **)(*piVar1 + 0x24))(piVar1,0,"gShadowColor");

  }

  piVar1 = *(int **)(*(int *)(iVar2 + 4) + 0xc);

  (**(code **)(*piVar1 + 0x50))(piVar1,uVar3,param_1,0xffffffff);

  return;

}
