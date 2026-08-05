// =============================================================================
// FUN_005cb8f0
// -----------------------------------------------------------------------------
// Stable ID: aa_005cb8f0
// Address:   0x005cb8f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005cb8f0 @ 0x005cb8f0
// Stable ID: aa_005cb8f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~74 non-empty decompiler lines.
//  - Control keywords: if×6, return×3, do×1, while×1.
//  - Notable callees: block×9, CVOGReaction_RandomUnitScalar, CVOGReaction_ResolveSkillTargets, FUN_004ce940, FUN_00509940, FUN_005c96c0, FUN_005c9a00, FUN_005c9cc0.
//  - Return sites: 3.

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

/* WARNING: Removing unreachable block (ram,0x005cba86) */

/* WARNING: Removing unreachable block (ram,0x005cba9a) */

/* WARNING: Removing unreachable block (ram,0x005cbaa7) */

/* WARNING: Removing unreachable block (ram,0x005cbaad) */

/* WARNING: Removing unreachable block (ram,0x005cbabd) */

/* WARNING: Removing unreachable block (ram,0x005cbae0) */

/* WARNING: Removing unreachable block (ram,0x005cbae5) */

/* WARNING: Removing unreachable block (ram,0x005cbaed) */

/* WARNING: Removing unreachable block (ram,0x005cbb03) */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ __thiscall FUN_005cb8f0(int param_1,uint32_t /* width from decompiler */ param_2)



{

  ushort uVar1;

  int iVar2;

  uint uVar3;

  void *pSkillData;

  uint32_t /* width from decompiler */ *puVar4;

  int iVar5;

  uint uVar6;

  ushort unaff_retaddr;

  uint32_t /* width from decompiler */ uSkillID;

  uint8_t auStack_4 [4];

  

  auStack_4 = (uint8_t  [4])param_1;

  (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0xbc) + 4) + -0xbc + param_1) + 0x60))();

  uVar6 = 0;

  iVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0xbc) + 4) + -0xbc + param_1) + 0x60))

                    ();

  uVar1 = (ushort)param_2;

  if (iVar2 != 0) {

    do {

      uVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0xbc) + 4) + -0xbc + param_1) +

                          0x5c))(uVar6);

      if (uVar1 == unaff_retaddr) {

        return 0x80004005;

      }

      uVar6 = uVar6 + 1;

      uVar3 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0xbc) + 4) + -0xbc + param_1) +

                          0x60))();

      uVar1 = unaff_retaddr;

    } while (uVar6 < uVar3);

  }

  auStack_4[2] = 0;

  auStack_4._0_2_ = uVar1;

  iVar2 = FUN_004ce940();

  if (iVar2 == 0) {

    iVar5 = FUN_005c9a00();

    iVar2 = *(int *)(iVar5 + 4);

    if ((iVar2 == 0) ||

       ((uint)(*(int *)(iVar5 + 0xc) - iVar2 >> 2) <= (uint)(*(int *)(iVar5 + 8) - iVar2 >> 2))) {

      FUN_005c9cc0(*(uint32_t /* width from decompiler */ *)(iVar5 + 8),1,auStack_4);

    }

    else {

      iVar2 = *(int *)(iVar5 + 8);

      FUN_005c96c0(iVar2,1,auStack_4,iVar5,param_2);

      *(int *)(iVar5 + 8) = iVar2 + 4;

    }

    return 0;

  }

  uSkillID = 1;

  pSkillData = (void *)FUN_00509940(uVar1);

  puVar4 = CVOGReaction_ResolveSkillTargets(pSkillData,uSkillID);

  if ((puVar4 != (uint32_t /* width from decompiler */ *)0x0) && (*(char *)(puVar4 + 0x17d) != '\0')) {

    iVar2 = CVOGReaction_RandomUnitScalar();

    if (0xfffff < *(int *)(iVar2 + 0xc)) {

      *(uint32_t /* width from decompiler */ *)(iVar2 + 0xc) = 0;

    }

    uVar1 = *(ushort *)(*(int *)(iVar2 + 8) + *(int *)(iVar2 + 0xc) * 2);

    *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 1;

    auStack_4[2] = (char)((int)((float)uVar1 * _DAT_009cdcc0) % (int)(uint)*(byte *)(puVar4 + 0x17d)

                         ) + '\x01';

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(puVar4);

}
