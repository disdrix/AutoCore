// =============================================================================
// FUN_00512c60
// -----------------------------------------------------------------------------
// Stable ID: aa_00512c60
// Address:   0x00512c60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00512c60 @ 0x00512c60
// Stable ID: aa_00512c60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: CONCAT22×3, Skill_SetRankAndReevaluate×3, FUN_00512c60.
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

void __fastcall FUN_00512c60(int *param_1)



{

  byte bVar1;

  void *pvVar2;

  uint16_t extraout_var;

  uint16_t extraout_var_00;

  uint16_t extraout_var_01;

  short sVar3;

  

  sVar3 = (short)*(uint32_t /* width from decompiler */ *)(*(int *)(param_1[0x2a] + 0x3c) + 0x3bc);

  pvVar2 = (void *)(**(code **)(*param_1 + 0x234))();

  if (pvVar2 != (void *)0x0) {

    bVar1 = (**(code **)(*param_1 + 0x264))();

    Skill_SetRankAndReevaluate(pvVar2,(void *)CONCAT22(extraout_var,(ushort)bVar1),sVar3);

  }

  sVar3 = (short)*(uint32_t /* width from decompiler */ *)(*(int *)(param_1[0x2a] + 0x3c) + 0x3c0);

  pvVar2 = (void *)(**(code **)(*param_1 + 0x234))();

  if (pvVar2 != (void *)0x0) {

    bVar1 = (**(code **)(*param_1 + 0x268))();

    Skill_SetRankAndReevaluate(pvVar2,(void *)CONCAT22(extraout_var_00,(ushort)bVar1),sVar3);

  }

  sVar3 = (short)*(uint32_t /* width from decompiler */ *)(*(int *)(param_1[0x2a] + 0x3c) + 0x3c4);

  pvVar2 = (void *)(**(code **)(*param_1 + 0x234))();

  if (pvVar2 != (void *)0x0) {

    bVar1 = (**(code **)(*param_1 + 0x26c))();

    Skill_SetRankAndReevaluate(pvVar2,(void *)CONCAT22(extraout_var_01,(ushort)bVar1),sVar3);

  }

  return;

}
