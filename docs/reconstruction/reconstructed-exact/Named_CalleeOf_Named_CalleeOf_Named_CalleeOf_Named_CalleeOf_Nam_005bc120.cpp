// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_005bc120
// -----------------------------------------------------------------------------
// Stable ID: aa_005bc120
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli
// Address:   0x005bc120  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~102 non-empty decompiler lines.
//  - Control keywords: if×14, do×4, while×4, return×2, goto×2.
//  - Notable callees: CVOGReaction_RandomUnitScalar×2, FUN_005be390×2, FUN_004b0be0, FUN_004b1100, FUN_004b18f0, FUN_004b2b90, FUN_004b3260, FUN_005b81e0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_005bc120(int *param_1,float *param_2,uint32_t /* width from decompiler */ param_3)



{

  float fVar1;

  float fVar2;

  char cVar3;

  ushort uVar4;

  short sVar5;

  int *piVar6;

  char *pcVar7;

  int iVar8;

  uint32_t /* width from decompiler */ uVar9;

  int iVar10;

  int local_10;

  int local_c;

  int local_4;

  

  param_1[0x24a] = (int)((float)param_1[0x24c] * *param_2 + (float)param_1[0x24a]);

  fVar1 = (float)param_1[0x201];

  fVar2 = *param_2;

  param_1[0x201] = (int)(fVar1 - fVar2);

  if (0.0 < fVar1 - fVar2) {

    return;

  }

  local_10 = 1;

  if (((*(byte *)(param_1 + 0x263) & 0x80) != 0) && (iVar10 = param_1[3], iVar10 != 0)) {

    if (*(int *)(iVar10 + 4) == 0) {

      local_10 = 0;

    }

    else {

      local_10 = (*(int *)(iVar10 + 8) - *(int *)(iVar10 + 4)) / 0xc;

    }

  }

  piVar6 = param_1 + 5;

  do {

    *(uint8_t *)((int)piVar6 + 0x2ee) = 0;

    piVar6 = (int *)piVar6[0xbd];

  } while (piVar6 != param_1 + 5);

  if (piVar6[0xd1] == 0) {

    pcVar7 = (char *)((int)piVar6 + 0x1ea);

    do {

      cVar3 = *pcVar7;

      pcVar7 = pcVar7 + 1;

    } while (cVar3 != '\0');

    if (pcVar7 == (char *)((int)piVar6 + 0x1eb)) goto LAB_005bc36a;

  }

  param_2 = (float *)0x0;

  if (0 < local_10) {

    do {

      local_c = param_1[0x25f];

      if (local_c == 0) {

        local_c = 0x7fffffff;

LAB_005bc228:

        sVar5 = 0;

        if (0 < (short)param_1[0x239]) {

          do {

            if (local_c <= param_1[0x28a]) break;

            iVar8 = FUN_005be390(param_1,param_2);

            iVar10 = param_1[0x289];

            local_4 = iVar8;

            local_4 = FUN_006759b0(iVar10,*(uint32_t /* width from decompiler */ *)(iVar10 + 4),&local_4);

            FUN_005bdd50(1);

            *(int *)(iVar10 + 4) = local_4;

            **(int **)(local_4 + 4) = local_4;

            FUN_004b3260(param_3);

            FUN_004b2b90(1,0);

            FUN_004b1100(param_3,1,0);

            if (*param_1 != 0) {

              uVar9 = FUN_005b81e0();

              *(uint32_t /* width from decompiler */ *)(iVar8 + 0x1a8) = uVar9;

            }

            if ((*(byte *)((int)param_1 + 0x98d) & 4) != 0) {

              iVar10 = FUN_005be390(param_1,param_2);

              FUN_004b0be0(iVar8);

              *(int *)(iVar8 + 8) = iVar10;

              iVar8 = CVOGReaction_RandomUnitScalar();

              if (0xfffff < *(int *)(iVar8 + 0xc)) {

                *(uint32_t /* width from decompiler */ *)(iVar8 + 0xc) = 0;

              }

              uVar4 = *(ushort *)(*(int *)(iVar8 + 8) + *(int *)(iVar8 + 0xc) * 2);

              *(int *)(iVar8 + 0xc) = *(int *)(iVar8 + 0xc) + 1;

              *(int *)(iVar10 + 0x80) =

                   param_1[(int)((longlong)(ulonglong)uVar4 % (longlong)param_1[0x255]) + 0x256];

              FUN_004b18f0(param_3);

            }

            sVar5 = sVar5 + 1;

          } while (sVar5 < (short)param_1[0x239]);

        }

      }

      else if (param_1[0x28a] < local_c) goto LAB_005bc228;

      param_2 = (float *)((int)param_2 + 1);

    } while ((int)param_2 < local_10);

  }

LAB_005bc36a:

  iVar10 = CVOGReaction_RandomUnitScalar();

  if (0xfffff < *(int *)(iVar10 + 0xc)) {

    *(uint32_t /* width from decompiler */ *)(iVar10 + 0xc) = 0;

  }

  uVar4 = *(ushort *)(*(int *)(iVar10 + 8) + *(int *)(iVar10 + 0xc) * 2);

  *(int *)(iVar10 + 0xc) = *(int *)(iVar10 + 0xc) + 1;

  param_1[0x201] =

       (int)((float)uVar4 * (float)param_1[0x238] * DAT_00aaa638 + (float)param_1[0x237]);

  return;

}
