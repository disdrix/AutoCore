// =============================================================================
// FUN_004c7fd0
// -----------------------------------------------------------------------------
// Stable ID: aa_004c7fd0
// Address:   0x004c7fd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004c7fd0 @ 0x004c7fd0
// Stable ID: aa_004c7fd0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_004c7fd0, FUN_004e2600.
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

void __fastcall FUN_004c7fd0(int param_1)



{

  int iVar1;

  char cVar2;

  int local_4;

  

  local_4 = 0;

  cVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x4fc + param_1) + 0x228

                      ))();

  if (cVar2 != '\0') {

    FUN_004e2600(&LAB_00513060,&local_4,0);

  }

  if (((local_4 == 0) && (iVar1 = *(int *)(param_1 + -0x2b0), iVar1 != 0)) &&

     (*(char *)(param_1 + -500) != '\0')) {

    (**(code **)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1) + 0x224))();

  }

  return;

}
