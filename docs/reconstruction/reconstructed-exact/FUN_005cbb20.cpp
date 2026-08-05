// =============================================================================
// FUN_005cbb20
// -----------------------------------------------------------------------------
// Stable ID: aa_005cbb20
// Address:   0x005cbb20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005cbb20 @ 0x005cbb20
// Stable ID: aa_005cbb20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: CVOGReaction_RandomUnitScalar, CVOGReaction_ResolveSkillTargets, FUN_00404d70, FUN_004ce940, FUN_00509940, FUN_005c9a60, FUN_005cb3d0, FUN_005cbb20.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ FUN_005cbb20(uint16_t param_1)



{

  ushort uVar1;

  uint16_t uVar2;

  int iVar3;

  void *pSkillData;

  uint32_t /* width from decompiler */ *puVar4;

  char cStack00000006;

  uint32_t /* width from decompiler */ uSkillID;

  uint16_t *puVar5;

  

  uVar2 = param_1;

  cStack00000006 = '\0';

  iVar3 = FUN_004ce940();

  if (iVar3 != 0) {

    iVar3 = FUN_00404d70(uVar2);

    if ((iVar3 != 0) && (*(int *)(iVar3 + 0x3c) != 0)) {

      uSkillID = 1;

      pSkillData = (void *)FUN_00509940(*(uint32_t /* width from decompiler */ *)(*(int *)(iVar3 + 0x3c) + 0x4c0));

      puVar4 = CVOGReaction_ResolveSkillTargets(pSkillData,uSkillID);

      if ((puVar4 != (uint32_t /* width from decompiler */ *)0x0) && (*(char *)(puVar4 + 0x17d) != '\0')) {

        iVar3 = CVOGReaction_RandomUnitScalar();

        if (0xfffff < *(int *)(iVar3 + 0xc)) {

          *(uint32_t /* width from decompiler */ *)(iVar3 + 0xc) = 0;

        }

        uVar1 = *(ushort *)(*(int *)(iVar3 + 8) + *(int *)(iVar3 + 0xc) * 2);

        *(int *)(iVar3 + 0xc) = *(int *)(iVar3 + 0xc) + 1;

        cStack00000006 =

             (char)((int)((float)uVar1 * _DAT_009cdcc0) % (int)(uint)*(byte *)(puVar4 + 0x17d)) +

             '\x01';

      }

                    /* WARNING: Subroutine does not return */

      operator_delete(puVar4);

    }

  }

  puVar5 = &param_1;

  FUN_005c9a60(puVar5);

  FUN_005cb3d0(puVar5);

  return 0;

}
