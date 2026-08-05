// =============================================================================
// FUN_0057a200
// -----------------------------------------------------------------------------
// Stable ID: aa_0057a200
// Address:   0x0057a200  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0057a200 @ 0x0057a200
// Stable ID: aa_0057a200
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00579fb0, FUN_0057a200.
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

void __thiscall

FUN_0057a200(int param_1,int param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5)



{

  int *piVar1;

  int iVar2;

  

  if (*(int *)(param_1 + 0x1c) == 0) {

    iVar2 = 0;

  }

  else {

    iVar2 = *(int *)(param_1 + 0x20) - *(int *)(param_1 + 0x1c) >> 2;

  }

  if (param_2 < iVar2) {

    piVar1 = (int *)(*(int *)(param_1 + 0x1c) + param_2 * 4);

    FUN_00579fb0(param_3,*(uint32_t /* width from decompiler */ *)(*piVar1 + 8),*piVar1 + 0xc,param_4,param_5);

  }

  return;

}
