// =============================================================================
// FUN_006502d0
// -----------------------------------------------------------------------------
// Stable ID: aa_006502d0
// Address:   0x006502d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006502d0 @ 0x006502d0
// Stable ID: aa_006502d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, while×1, goto×1.
//  - Notable callees: FUN_006502d0.
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

uint32_t /* width from decompiler */ __thiscall FUN_006502d0(int *param_1,uint param_2,uint32_t /* width from decompiler */ *param_3)



{

  uint uVar1;

  int iVar2;

  uint uVar3;

  uint uVar4;

  

  uVar1 = param_1[2];

  iVar2 = *param_1;

  uVar4 = (param_2 >> 4) * -0x61c8864f & uVar1;

  uVar3 = *(uint *)(iVar2 + uVar4 * 4);

  while (uVar3 != 0) {

    if (uVar3 == param_2) goto LAB_00650303;

    uVar4 = uVar4 + 1 & uVar1;

    uVar3 = *(uint *)(iVar2 + uVar4 * 4);

  }

  uVar4 = uVar1 + 1;

LAB_00650303:

  if ((int)uVar1 < (int)uVar4) {

    return 1;

  }

  *param_3 = *(uint32_t /* width from decompiler */ *)(iVar2 + 4 + (uVar1 + uVar4) * 4);

  return 0;

}
