// =============================================================================
// FUN_00406e70
// -----------------------------------------------------------------------------
// Stable ID: aa_00406e70
// Address:   0x00406e70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00406e70 @ 0x00406e70
// Stable ID: aa_00406e70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×2, goto×1, return×1.
//  - Notable callees: FUN_00406e70, FUN_004082f0.
//  - Return sites: 1.

// READABILITY:
// Control-flow (from raw @ 0x00406e70; evidence only — no invented semantics):
//  - Entry: `int * FUN_00406e70(int *param_1,int param_2,undefined4 param_3)`.
//  - Branches: if (iVar1 != 0); if ((*(unaff_EDI + 8) - iVar1) / 0xc != 0).
//  - Calls: FUN_004082f0(param_2,1,param_3).
//  - Writes: *param_1 = *(unaff_EDI + 4) + iVar1 * 0xc.
//  - Goto: LAB_00406eb5.
//  - Returns (1 site(s)): `param_1`.




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

int * FUN_00406e70(int *param_1,int param_2,uint32_t /* width from decompiler */ param_3)



{

  int iVar1;

  int unaff_EDI;

  

  iVar1 = *(int *)(unaff_EDI + 4);

  if (iVar1 != 0) {

    if ((*(int *)(unaff_EDI + 8) - iVar1) / 0xc != 0) {

      iVar1 = (param_2 - iVar1) / 0xc;

      goto LAB_00406eb5;

    }

  }

  iVar1 = 0;

LAB_00406eb5:

  FUN_004082f0(param_2,1,param_3);

  *param_1 = *(int *)(unaff_EDI + 4) + iVar1 * 0xc;

  return param_1;

}
