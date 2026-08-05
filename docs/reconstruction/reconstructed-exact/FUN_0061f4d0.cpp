// =============================================================================
// FUN_0061f4d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0061f4d0
// Address:   0x0061f4d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0061f4d0 @ 0x0061f4d0
// Stable ID: aa_0061f4d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~69 non-empty decompiler lines.
//  - Control keywords: if×4, do×4, while×4, return×3, for×1.
//  - Notable callees: FUN_00552180×2, CONCAT22, FUN_00578190, FUN_0061f4d0.
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

void FUN_0061f4d0(int param_1,char *param_2,uint32_t /* width from decompiler */ param_3)



{

  char cVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  uint16_t extraout_var;

  uint16_t uVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint8_t auStack_209 [3];

  uint32_t /* width from decompiler */ uStack_206;

  

  auStack_209._1_2_ = 0;

  puVar3 = &uStack_206;

  for (iVar4 = 0x7f; iVar4 != 0; iVar4 = iVar4 + -1) {

    *puVar3 = 0;

    puVar3 = puVar3 + 1;

  }

  *(uint16_t *)puVar3 = 0;

  uVar5 = 0;

  if (*(void **)(param_1 + 0x150) != (void *)0x0) {

    puVar3 = CVOGReaction_ResolveSkillTargets

                       (*(void **)(param_1 + 0x150),

                        (uint)(ushort)(*(short *)(param_1 + 0x5f6) + *(short *)(param_1 + 0x174)));

    uVar5 = extraout_var;

    if (puVar3 != (uint32_t /* width from decompiler */ *)0x0) {

      iVar4 = 1 - (int)param_2;

      do {

        cVar1 = *param_2;

        param_2[(int)(auStack_209 + iVar4)] = cVar1;

        param_2 = param_2 + 1;

      } while (cVar1 != '\0');

      puVar2 = (uint32_t /* width from decompiler */ *)auStack_209;

      do {

        puVar6 = puVar2;

        puVar2 = (uint32_t /* width from decompiler */ *)((int)puVar6 + 1);

      } while (*(char *)((int)puVar6 + 1) != '\0');

      *(uint32_t /* width from decompiler */ *)((int)puVar6 + 1) = DAT_009e1d68;

      *(uint8_t *)((int)puVar6 + 5) = DAT_009e1d6c;

      FUN_00552180(auStack_209 + 1,param_3);

                    /* WARNING: Subroutine does not return */

      operator_delete(puVar3);

    }

  }

  if (*(void **)(param_1 + 0x154) != (void *)0x0) {

    puVar3 = CVOGReaction_ResolveSkillTargets

                       (*(void **)(param_1 + 0x154),

                        CONCAT22(uVar5,*(short *)(param_1 + 0x5f6) + *(short *)(param_1 + 0x174)));

    if (puVar3 != (uint32_t /* width from decompiler */ *)0x0) {

      iVar4 = 1 - (int)param_2;

      do {

        cVar1 = *param_2;

        param_2[(int)(auStack_209 + iVar4)] = cVar1;

        param_2 = param_2 + 1;

      } while (cVar1 != '\0');

      puVar2 = (uint32_t /* width from decompiler */ *)auStack_209;

      do {

        puVar6 = puVar2;

        puVar2 = (uint32_t /* width from decompiler */ *)((int)puVar6 + 1);

      } while (*(char *)((int)puVar6 + 1) != '\0');

      *(uint32_t /* width from decompiler */ *)((int)puVar6 + 1) = DAT_009e1d60;

      *(uint8_t *)((int)puVar6 + 5) = DAT_009e1d64;

      FUN_00552180(auStack_209 + 1,param_3);

                    /* WARNING: Subroutine does not return */

      operator_delete(puVar3);

    }

  }

  FUN_00578190(param_1,param_2,param_3);

  return;

}
