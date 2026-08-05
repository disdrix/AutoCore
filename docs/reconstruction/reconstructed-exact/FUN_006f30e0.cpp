// =============================================================================
// FUN_006f30e0
// -----------------------------------------------------------------------------
// Stable ID: aa_006f30e0
// Address:   0x006f30e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f30e0 @ 0x006f30e0
// Stable ID: aa_006f30e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~137 non-empty decompiler lines.
//  - Control keywords: if×15, do×4, while×4, return×2, for×1, goto×1.
//  - Notable callees: FUN_006f1cd0×2, FUN_006f30e0×2, FUN_00646a60, FUN_006f2180, FUN_006f2210, FUN_006f22e0, FUN_006f2660, FUN_006f28c0.
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

void __thiscall FUN_006f30e0(int param_1,int param_2,uint32_t /* width from decompiler */ param_3,int *param_4)



{

  int iVar1;

  char cVar2;

  int iVar3;

  int *piVar4;

  int iVar5;

  char cVar6;

  int iVar7;

  int iVar8;

  uint32_t /* width from decompiler */ *puVar9;

  int iVar10;

  int *piVar11;

  int local_94;

  int *local_90;

  int local_8c;

  int *local_88;

  int local_84;

  int local_80;

  int local_7c [3];

  uint8_t local_70;

  int aiStack_64 [10];

  int local_3c;

  uint32_t /* width from decompiler */ local_38;

  uint8_t local_14 [20];

  

  iVar1 = param_2 + 0x38;

  if (*(char *)(param_2 + 0x38) == '\0') {

    local_80 = param_1;

    if (*(char *)(param_2 + 4) != '\0') {

      FUN_006f1cd0();

      FUN_006f2660(param_2,param_4);

      return;

    }

    if (*(char *)(param_2 + 0x3c) == '\x01') {

      FUN_006f22e0(param_3,param_4,local_14);

    }

    FUN_006f1cd0();

    local_8c = FUN_006f28c0(*(uint32_t /* width from decompiler */ *)(param_2 + 0xb8));

    FUN_006f29f0(param_2,param_4,&local_94,&local_84);

    local_84 = *(int *)(param_2 + 0xf0);

    local_7c[1] = *(uint32_t /* width from decompiler */ *)(param_2 + 0xec);

    puVar9 = (uint32_t /* width from decompiler */ *)(param_2 + 0x50);

    iVar10 = 3;

    local_7c[0] = local_84;

    do {

      FUN_00646a60(*(float *)(param_1 + 0x3c) * *(float *)(param_1 + 0x54));

      puVar9[-3] = 0;

      *puVar9 = 0x7fffffff;

      puVar9 = puVar9 + 1;

      iVar10 = iVar10 + -1;

    } while (iVar10 != 0);

    local_94 = 0;

    do {

      iVar10 = local_7c[local_94];

      if (iVar10 != 0) {

        piVar4 = param_4;

        piVar11 = local_7c + 2;

        for (iVar5 = 0x12; iVar5 != 0; iVar5 = iVar5 + -1) {

          *piVar11 = *piVar4;

          piVar4 = piVar4 + 1;

          piVar11 = piVar11 + 1;

        }

        local_3c = *(int *)(iVar10 + 0x28) - *(int *)(iVar10 + 0x24);

        local_38 = *(uint32_t /* width from decompiler */ *)(iVar10 + 0x2c);

        iVar5 = 0;

        if (0 < *(int *)(iVar10 + 0x2c)) {

          piVar4 = (int *)(iVar10 + 0x30);

          do {

            *(int *)((int)aiStack_64 + -iVar10 + (int)piVar4) = *piVar4;

            iVar5 = iVar5 + 1;

            *(int *)((int)aiStack_64 + -iVar10 + 4 + (int)piVar4) = piVar4[1] - *piVar4;

            piVar4 = piVar4 + 1;

          } while (iVar5 < *(int *)(iVar10 + 0x2c));

        }

        FUN_006f2180(iVar10,local_80 + 0x30);

        local_7c[2] = *param_4 + 1;

        local_70 = 0;

        FUN_006f2210();

        FUN_006f30e0(iVar10,param_4,local_7c + 2);

        if (iVar10 == local_84) {

          if (local_8c < 3) {

            *(uint32_t /* width from decompiler */ *)(iVar10 + 0x44 + local_8c * 4) = 0;

          }

        }

        else if (local_8c < 3) {

          *(uint32_t /* width from decompiler */ *)(iVar10 + 0x50 + local_8c * 4) = 0x7fffffff;

        }

        local_90 = param_4 + 4;

        local_88 = param_4 + 0x15;

        iVar5 = 0;

        piVar11 = (int *)(param_2 + 0x50);

        piVar4 = (int *)(iVar10 + 0x44);

        iVar8 = iVar1 - (iVar10 + 0x38);

        do {

          cVar2 = *(char *)(iVar10 + 0x40 + iVar5);

          if (cVar2 == '\x01') {

            if ((*piVar4 <= local_88[-3]) && (*local_88 <= piVar4[3])) {

              cVar2 = *(char *)(iVar5 + 8 + iVar1);

              cVar6 = '\x01';

              if ('\0' < cVar2) {

                cVar6 = cVar2;

              }

              *(char *)(iVar5 + 8 + iVar1) = cVar6;

LAB_006f3317:

              *(uint8_t *)(iVar10 + 0x40 + iVar5) = 0;

            }

          }

          else if (((cVar2 == '\x02') && (*piVar4 <= local_90[-1])) && (*local_90 <= piVar4[3])) {

            *(uint8_t *)(iVar5 + 8 + iVar1) = 2;

            goto LAB_006f3317;

          }

          if (*(char *)(iVar10 + 0x40 + iVar5) == '\0') {

            iVar3 = *(int *)((int)piVar4 + iVar8);

            iVar7 = *piVar4;

            if (*piVar4 < iVar3) {

              iVar7 = iVar3;

            }

            iVar3 = *piVar11;

            *(int *)((int)piVar4 + iVar8) = iVar7;

            iVar7 = piVar4[3];

            if (iVar3 < piVar4[3]) {

              iVar7 = iVar3;

            }

            *piVar11 = iVar7;

          }

          iVar5 = iVar5 + 1;

          local_88 = local_88 + 1;

          local_90 = local_90 + 2;

          piVar4 = piVar4 + 1;

          piVar11 = piVar11 + 1;

        } while (iVar5 < 3);

      }

      local_94 = local_94 + 1;

    } while (local_94 < 2);

  }

  return;

}
