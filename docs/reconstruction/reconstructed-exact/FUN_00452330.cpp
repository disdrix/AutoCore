// =============================================================================
// FUN_00452330
// -----------------------------------------------------------------------------
// Stable ID: aa_00452330
// Address:   0x00452330  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00452330 @ 0x00452330
// Stable ID: aa_00452330
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×2, goto×1, return×1.
//  - Notable callees: FUN_00452330, FUN_00453110.
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

void __thiscall FUN_00452330(int param_1,int *param_2,int param_3,uint32_t /* width from decompiler */ param_4)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 4);

  if (iVar1 != 0) {

    if ((*(int *)(param_1 + 8) - iVar1) / 0xc != 0) {

      iVar1 = (param_3 - iVar1) / 0xc;

      goto LAB_00452373;

    }

  }

  iVar1 = 0;

LAB_00452373:

  FUN_00453110(param_3,1,param_4);

  *param_2 = *(int *)(param_1 + 4) + iVar1 * 0xc;

  return;

}
