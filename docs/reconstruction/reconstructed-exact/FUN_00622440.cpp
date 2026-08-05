// =============================================================================
// FUN_00622440
// -----------------------------------------------------------------------------
// Stable ID: aa_00622440
// Address:   0x00622440  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00622440 @ 0x00622440
// Stable ID: aa_00622440
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: CONCAT22, CVOGReaction_RandomUnitScalar, FUN_00578270, FUN_00622440.
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

void __thiscall FUN_00622440(int param_1,uint32_t /* width from decompiler */ param_2)



{

  ushort uVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ uVar4;

  int iVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ uVar7;

  undefined *puVar8;

  uint32_t /* width from decompiler */ uVar9;

  uint32_t /* width from decompiler */ uVar10;

  uint32_t /* width from decompiler */ uVar11;

  uint32_t /* width from decompiler */ uVar12;

  

  iVar2 = CVOGReaction_RandomUnitScalar();

  if (0xfffff < *(int *)(iVar2 + 0xc)) {

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0xc) = 0;

  }

  uVar1 = *(ushort *)(*(int *)(iVar2 + 8) + *(int *)(iVar2 + 0xc) * 2);

  iVar5 = *(int *)(iVar2 + 0xc) + 1;

  *(int *)(iVar2 + 0xc) = iVar5;

  if (((float)uVar1 * DAT_00aaa638 <= *(float *)(param_1 + 0x108)) &&

     (puVar3 = CVOGReaction_ResolveSkillTargets

                         (*(void **)(param_1 + 0x174),

                          CONCAT22((short)((uint)iVar5 >> 0x10),

                                   *(short *)(param_1 + 0x61a) + *(short *)(param_1 + 0x198))),

     puVar3 != (uint32_t /* width from decompiler */ *)0x0)) {

    uVar12 = 0;

    uVar11 = 0;

    uVar10 = 0xffffffff;

    uVar9 = 0;

    puVar8 = &DAT_00d02b30;

    uVar7 = 0;

    uVar6 = 0;

    uVar4 = FUN_00578270(param_2,0,0,&DAT_00d02b30,0,0xffffffff,0,0);

    CVOGReaction_CastSkillOnTarget

              (puVar3,uVar4,param_2,uVar6,uVar7,puVar8,uVar9,uVar10,uVar11,uVar12);

                    /* WARNING: Subroutine does not return */

    operator_delete(puVar3);

  }

  return;

}
