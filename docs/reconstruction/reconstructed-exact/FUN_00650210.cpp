// =============================================================================
// FUN_00650210
// -----------------------------------------------------------------------------
// Stable ID: aa_00650210
// Address:   0x00650210  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00650210 @ 0x00650210
// Stable ID: aa_00650210
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×1, while×1, return×1.
//  - Notable callees: FUN_00650210, FUN_00650440.
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

void __thiscall FUN_00650210(int *param_1,uint param_2,uint32_t /* width from decompiler */ param_3)



{

  int iVar1;

  int iVar2;

  uint uVar3;

  

  if (param_1[2] < param_1[1] * 2) {

    FUN_00650440(param_1[2] * 2 + 2);

  }

  iVar1 = *param_1;

  uVar3 = (param_2 >> 4) * -0x61c8864f & param_1[2];

  iVar2 = *(int *)(iVar1 + uVar3 * 4);

  while ((iVar2 != 0 && (*(uint *)(iVar1 + uVar3 * 4) != param_2))) {

    uVar3 = uVar3 + 1 & param_1[2];

    iVar2 = *(int *)(*param_1 + uVar3 * 4);

  }

  param_1[1] = param_1[1] + (uint)(*(uint *)(iVar1 + uVar3 * 4) != param_2);

  *(uint *)(iVar1 + uVar3 * 4) = param_2;

  *(uint32_t /* width from decompiler */ *)(*param_1 + 4 + (param_1[2] + uVar3) * 4) = param_3;

  return;

}
