// =============================================================================
// FUN_008ec320
// -----------------------------------------------------------------------------
// Stable ID: aa_008ec320
// Address:   0x008ec320  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008ec320 @ 0x008ec320
// Stable ID: aa_008ec320
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~134 non-empty decompiler lines.
//  - Control keywords: if×5, return×2, while×1.
//  - Notable callees: FUN_0040e490×2, EnterCriticalSection, FUN_0040e230, FUN_0040e340, FUN_008ec080, FUN_008ec320, LeaveCriticalSection.
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

void FUN_008ec320(void)



{

  int iVar1;

  int iVar2;

  float fVar3;

  int in_EAX;

  int *piVar4;

  int *piVar5;

  int iVar6;

  int unaff_EBX;

  int unaff_EDI;

  float fVar7;

  float fVar8;

  int iVar9;

  uint8_t *puVar10;

  uint8_t *puStack_a4;

  int iStack_a0;

  int *piStack_9c;

  int *piStack_98;

  uint8_t *puStack_94;

  uint32_t /* width from decompiler */ uStack_90;

  int iStack_8c;

  uint8_t *puStack_88;

  int iStack_84;

  uint8_t *puStack_80;

  int iStack_7c;

  int iStack_78;

  uint8_t *puStack_74;

  int iStack_70;

  int iStack_6c;

  uint8_t auStack_5c [4];

  uint8_t auStack_58 [16];

  uint8_t local_48 [8];

  uint8_t auStack_40 [12];

  uint32_t /* width from decompiler */ local_34;

  uint8_t auStack_2c [40];

  

  if ((*(int *)(in_EAX + 0x574) != 0) &&

     (piVar4 = *(int **)(*(int *)(in_EAX + 0x574) + 0x294), piVar4 != (int *)0x0)) {

    iVar1 = *piVar4;

    iVar9 = *(int *)(iVar1 + 0x1c);

    local_34 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x20);

    iStack_6c = 0;

    iStack_70 = 1;

    puStack_74 = local_48;

    iStack_78 = 0x8ec370;

    (**(code **)(**(int **)(in_EAX + 0x574) + 0x120))();

    iStack_78 = 0;

    iStack_7c = 1;

    puStack_80 = auStack_2c;

    iStack_84 = 0x8ec387;

    piVar4 = (int *)(**(code **)(**(int **)(in_EAX + 0x578) + 0x120))();

    iStack_84 = 1;

    puStack_88 = auStack_58;

    iStack_8c = 0x8ec39e;

    piVar5 = (int *)(**(code **)(**(int **)(in_EAX + 0x578) + 0x140))();

    iVar1 = *piVar4;

    iStack_8c = 0;

    iVar2 = *piVar5;

    piVar4 = *(int **)(in_EAX + 0x578);

    uStack_90 = 1;

    puStack_94 = auStack_40;

    piStack_98 = (int *)0x8ec3c9;

    iVar6 = (**(code **)(*piVar4 + 0x120))();

    iStack_84 = (iStack_70 - *(int *)(iVar6 + 4)) * unaff_EBX;

    piStack_98 = (int *)0x1;

    piStack_9c = &iStack_6c;

    iStack_a0 = 0x8ec3ea;

    iVar6 = (**(code **)(*piVar4 + 0x140))();

    iStack_78 = iStack_8c / *(int *)(iVar6 + 4);

    iStack_a0 = 1;

    puStack_a4 = &stack0xffffff9c;

    (**(code **)(**(int **)(in_EAX + 0x574) + 0x140))();

    puVar10 = &stack0xffffff9c;

    (**(code **)(**(int **)(in_EAX + 0x578) + 0x140))(puVar10,1);

    fVar3 = g_flLevelUpUiBase_Inferred;

    fVar7 = (float)(int)(((float)(int)puStack_74 / (float)iStack_6c) * (float)iVar9);

    fVar8 = (float)(int)(((float)iStack_70 / (float)(((unaff_EDI - iVar1) * iVar9) / iVar2)) *

                        (float)iStack_78);

    *(int *)(*(int *)(in_EAX + 0x574) + 0x180) =

         (int)(*(float *)(in_EAX + 0x528) * fVar7 -

              fVar7 / (*(float *)(in_EAX + 0x524) * g_flLevelUpUiBase_Inferred)) + iStack_8c;

    iVar1 = in_EAX + 0x5b0;

    *(uint8_t **)(*(int *)(in_EAX + 0x574) + 0x184) =

         puStack_88 +

         (int)(*(float *)(in_EAX + 0x52c) * fVar8 - fVar8 / (*(float *)(in_EAX + 0x524) * fVar3));

    *(int *)(*(int *)(in_EAX + 0x574) + 0x188) =

         (int)((float)*(int *)(*(int *)(in_EAX + 0x574) + 0x180) +

              fVar7 / *(float *)(in_EAX + 0x524));

    *(int *)(*(int *)(in_EAX + 0x574) + 0x18c) =

         (int)((float)*(int *)(*(int *)(in_EAX + 0x574) + 0x184) +

              fVar8 / *(float *)(in_EAX + 0x524));

    piStack_98 = (int *)FUN_0040e340();

    piVar4 = (int *)FUN_0040e490(iVar1);

    while (piVar4 != (int *)0x0) {

      FUN_008ec080(&puStack_94,piVar4[0x8d],piVar4[0x8f]);

      if (*(int *)(in_EAX + 0x5a8) != 0) {

        iVar9 = 0;

        (**(code **)(**(int **)(in_EAX + 0x5a8) + 0x120))(&iStack_7c,1);

        (**(code **)(**(int **)(in_EAX + 0x5a8) + 0x140))(&iStack_70,1);

        (**(code **)(*piVar4 + 0x140))(&piStack_98,1);

        iStack_a0 = iStack_a0 / 2;

        piStack_9c = (int *)((int)piStack_9c / 2);

        if ((((iVar9 - iStack_a0 < (int)piStack_98) ||

             ((int)puVar10 - (int)piStack_9c < (int)puStack_94)) ||

            ((int)(puStack_80 + (int)piStack_98) < iVar9 + iStack_a0)) ||

           ((int)(puStack_94 + iStack_7c) < (int)(puVar10 + iStack_a0))) {

          (**(code **)(*piVar4 + 0xcc))(0);

        }

        else {

          (**(code **)(*piVar4 + 0xcc))(1);

        }

      }

      piVar5 = (int *)(**(code **)(*piVar4 + 0x140))(auStack_5c,1);

      piStack_9c = (int *)((int)piStack_9c - *piVar5 / 2);

      iVar9 = (**(code **)(*piVar4 + 0x140))(auStack_5c,1);

      iStack_a0 = iStack_a0 - *(int *)(iVar9 + 4) / 2;

      (**(code **)(*piVar4 + 0x118))(&puStack_a4);

      FUN_0040e230(iVar1);

      EnterCriticalSection((LPCRITICAL_SECTION)(in_EAX + 0x5d8));

      if (*(int *)(in_EAX + 0x5b4) == 0) {

        piStack_9c = (int *)0x0;

      }

      else {

        piStack_9c = *(int **)(*(int *)(in_EAX + 0x5b4) + 4);

      }

      LeaveCriticalSection((LPCRITICAL_SECTION)(in_EAX + 0x5d8));

      if (piStack_9c == piStack_98) {

        return;

      }

      piVar4 = (int *)FUN_0040e490(iVar1);

    }

  }

  return;

}
