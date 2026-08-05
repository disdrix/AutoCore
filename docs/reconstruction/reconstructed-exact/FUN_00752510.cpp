// =============================================================================
// FUN_00752510
// -----------------------------------------------------------------------------
// Stable ID: aa_00752510
// Address:   0x00752510  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00752510 @ 0x00752510
// Stable ID: aa_00752510
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00752510.
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

uint32_t /* width from decompiler */ __fastcall FUN_00752510(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  

  iVar1 = param_1 * 0x10 + 0x3c + *(int *)(param_2 + 8);

  iVar2 = *(int *)(iVar1 + 4);

  if ((iVar2 != 0) && (*(int *)(iVar1 + 8) - iVar2 >> 2 != 0)) {

    *(uint32_t /* width from decompiler */ *)(param_2 + 0x14) =

         **(uint32_t /* width from decompiler */ **)((param_1 + 4) * 0x10 + *(int *)(param_2 + 8));

    *(int *)(param_2 + 0x20) = param_1;

    return 0;

  }

  return 0xffffffff;

}
