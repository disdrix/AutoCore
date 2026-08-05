// =============================================================================
// FUN_0061d930
// -----------------------------------------------------------------------------
// Stable ID: aa_0061d930
// Address:   0x0061d930  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0061d930 @ 0x0061d930
// Stable ID: aa_0061d930
// Embedded strings (evidence for future rename):
//   - "op_scalar_1] (# charges)\n"
//   - "(Following Skill is OnCollision)\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~66 non-empty decompiler lines.
//  - Control keywords: if×3, do×3, while×3, for×2, return×2.
//  - Notable callees: CONCAT22, FUN_00552180, FUN_00578190, FUN_005781b0, FUN_0061d930.
//  - Strings: "op_scalar_1] (# charges)\n"; "(Following Skill is OnCollision)\n".
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

void __fastcall

FUN_0061d930(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,int param_3,char *param_4,int param_5)



{

  char cVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  uint16_t uVar4;

  uint16_t extraout_var;

  char *pcVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ *puVar7;

  uint8_t local_20c [4];

  char local_208 [2];

  uint32_t /* width from decompiler */ uStack_206;

  

  uVar4 = (uint16_t)((uint)param_2 >> 0x10);

  if (*(float *)(param_3 + 0x160) != g_flZero) {

    FUN_005781b0(param_5,param_4,"op_scalar_1] (# charges)\n",1);

    uVar4 = extraout_var;

  }

  if (*(void **)(param_3 + 0x150) != (void *)0x0) {

    puVar2 = CVOGReaction_ResolveSkillTargets

                       (*(void **)(param_3 + 0x150),

                        CONCAT22(uVar4,*(short *)(param_3 + 0x5f6) + *(short *)(param_3 + 0x174)));

    local_20c = (uint8_t  [4])puVar2;

    if (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {

      local_208[0] = '\0';

      local_208[1] = '\0';

      puVar6 = &uStack_206;

      for (iVar3 = 0x7f; iVar3 != 0; iVar3 = iVar3 + -1) {

        *puVar6 = 0;

        puVar6 = puVar6 + 1;

      }

      *(uint16_t *)puVar6 = 0;

      puVar6 = (uint32_t /* width from decompiler */ *)(param_5 + -1);

      do {

        pcVar5 = (char *)((int)puVar6 + 1);

        puVar6 = (uint32_t /* width from decompiler */ *)((int)puVar6 + 1);

      } while (*pcVar5 != '\0');

      pcVar5 = "(Following Skill is OnCollision)\n";

      for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {

        *puVar6 = *(uint32_t /* width from decompiler */ *)pcVar5;

        pcVar5 = pcVar5 + 4;

        puVar6 = puVar6 + 1;

      }

      *(uint16_t *)puVar6 = *(uint16_t *)pcVar5;

      iVar3 = -(int)param_4;

      do {

        cVar1 = *param_4;

        param_4[(int)(local_208 + iVar3)] = cVar1;

        param_4 = param_4 + 1;

      } while (cVar1 != '\0');

      puVar6 = (uint32_t /* width from decompiler */ *)(local_20c + 3);

      do {

        puVar7 = puVar6;

        puVar6 = (uint32_t /* width from decompiler */ *)((int)puVar7 + 1);

      } while (*(char *)((int)puVar7 + 1) != '\0');

      *(uint32_t /* width from decompiler */ *)((int)puVar7 + 1) = DAT_009e1d68;

      *(uint8_t *)((int)puVar7 + 5) = DAT_009e1d6c;

      FUN_00552180(local_208,param_5);

                    /* WARNING: Subroutine does not return */

      operator_delete(puVar2);

    }

  }

  FUN_00578190(param_3,param_4,param_5);

  return;

}
