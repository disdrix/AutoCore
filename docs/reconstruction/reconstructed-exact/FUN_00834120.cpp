// =============================================================================
// FUN_00834120
// -----------------------------------------------------------------------------
// Stable ID: aa_00834120
// Address:   0x00834120  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00834120 @ 0x00834120
// Stable ID: aa_00834120
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~147 non-empty decompiler lines.
//  - Control keywords: if×17, do×6, while×6, return×3, goto×2.
//  - Notable callees: FUN_0076c4d0×6, FUN_00755f10×4, FUN_004f5560×2, FUN_00755c30×2, FUN_007560a0×2, FUN_005a6e00, FUN_005a6e40, FUN_007afe80.
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

void __fastcall FUN_00834120(undefined **param_1)



{

  char cVar1;

  undefined *puVar2;

  char cVar3;

  byte bVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int *piVar8;

  uint uVar9;

  undefined **local_8;

  undefined *puStack_4;

  

  if (param_1[0xaa] != (undefined *)0x0) {

    local_8 = param_1;

    if (param_1[0x142] == (undefined *)0x0) {

      (**(code **)(*param_1 + 0x44))();

      puVar2 = param_1[0xaa];

      puVar2[0x48] = 1;

      *(uint32_t /* width from decompiler */ *)(puVar2 + 0x44) = *(uint32_t /* width from decompiler */ *)(puVar2 + 0x40);

      FUN_0076c4d0();

      local_8 = &PTR_LAB_00a9f4d8;

      puStack_4 = puVar2;

      (**(code **)(**(int **)(puVar2 + 8) + 0x20))(&local_8);

      (**(code **)(**(int **)(puVar2 + 8) + 0x10))(0);

      return;

    }

    (**(code **)(*param_1 + 0x54))(0,0,0,0);

    puVar2 = param_1[0xaa];

    puVar2[0x48] = 1;

    *(uint32_t /* width from decompiler */ *)(puVar2 + 0x44) = *(uint32_t /* width from decompiler */ *)(puVar2 + 0x40);

    FUN_0076c4d0();

    (**(code **)(**(int **)(puVar2 + 8) + 0x20))(&stack0xffffffe0);

    (**(code **)(**(int **)(puVar2 + 8) + 0x10))(0);

    piVar8 = (int *)param_1[0x142];

    (**(code **)(*(int *)(*(int *)(piVar8[1] + 4) + 4 + (int)piVar8) + 0x144))();

    if (piVar8[0x12] != 0) {

      FUN_007560a0();

    }

    (**(code **)(*piVar8 + 0x44))();

    iVar5 = piVar8[0x96];

    if (((iVar5 != 0) && (*(char *)(iVar5 + 0x11c) != '\0')) &&

       (*(char *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 0xac + iVar5) + 0x3c) +

                 0x4ce) != '\x04')) {

      uVar9 = 0;

      cVar3 = FUN_004f5560();

      if ('\0' < cVar3) {

        do {

          cVar3 = (char)uVar9;

          iVar5 = FUN_005a6e00(uVar9);

          if (iVar5 != 0) {

            FUN_007560a0();

          }

          uVar9 = (uint)(byte)(cVar3 + 1);

          cVar3 = FUN_004f5560();

        } while ((char)uVar9 < cVar3);

      }

      iVar5 = *(int *)(*(int *)(*(int *)(piVar8[1] + 4) + 0xac + (int)piVar8) + 0x3c);

      bVar4 = 0;

      uVar9 = 0;

      iVar7 = iVar5;

      if ('\0' < *(char *)(piVar8[0x96] + 0xf0)) {

        do {

          cVar3 = '\0';

          do {

            if (iVar5 == 0) {

LAB_008342a1:

              iVar6 = FUN_005a6e40(uVar9,cVar3);

              if (iVar6 != 0) {

                puVar2 = param_1[0xaa];

                puVar2[0x48] = 1;

                *(uint32_t /* width from decompiler */ *)(puVar2 + 0x44) = *(uint32_t /* width from decompiler */ *)(puVar2 + 0x40);

                FUN_0076c4d0();

                (**(code **)(**(int **)(puVar2 + 8) + 4))(iVar6);

                iVar5 = iVar7;

                FUN_00755f10(iVar6);

                iVar7 = iVar5;

              }

              bVar4 = (byte)uVar9;

            }

            else {

              if (cVar3 == '\0') {

                cVar1 = *(char *)(('\0' < (char)bVar4) + 0x680 + iVar5);

              }

              else {

                if (cVar3 < '\x01') goto LAB_008342a1;

                cVar1 = *(char *)(('\0' < (char)bVar4) + 0x682 + iVar5);

              }

              if (cVar1 != '\0') goto LAB_008342a1;

            }

            cVar3 = cVar3 + '\x01';

          } while (cVar3 < '\x03');

          bVar4 = bVar4 + 1;

          uVar9 = (uint)bVar4;

        } while ((char)bVar4 < *(char *)(piVar8[0x96] + 0xf0));

      }

    }

    cVar3 = '\0';

    do {

      iVar5 = piVar8[cVar3 + 0xd0];

      if (iVar5 == 0) break;

      puVar2 = param_1[0xaa];

      puVar2[0x48] = 1;

      *(uint32_t /* width from decompiler */ *)(puVar2 + 0x44) = *(uint32_t /* width from decompiler */ *)(puVar2 + 0x40);

      FUN_0076c4d0();

      (**(code **)(**(int **)(puVar2 + 8) + 4))(iVar5);

      FUN_00755f10(iVar5);

      cVar3 = cVar3 + '\x01';

    } while (cVar3 < '\x03');

    iVar5 = piVar8[0xe8];

    if (iVar5 != 0) {

      puVar2 = param_1[0xaa];

      puVar2[0x48] = 1;

      *(uint32_t /* width from decompiler */ *)(puVar2 + 0x44) = *(uint32_t /* width from decompiler */ *)(puVar2 + 0x40);

      FUN_0076c4d0();

      (**(code **)(**(int **)(puVar2 + 8) + 4))(iVar5);

      FUN_00755f10(iVar5);

    }

    piVar8 = piVar8 + 0xd3;

    iVar5 = 8;

    do {

      iVar7 = *piVar8;

      if (iVar7 != 0) {

        puVar2 = param_1[0xaa];

        puVar2[0x48] = 1;

        *(uint32_t /* width from decompiler */ *)(puVar2 + 0x44) = *(uint32_t /* width from decompiler */ *)(puVar2 + 0x40);

        FUN_0076c4d0();

        (**(code **)(**(int **)(puVar2 + 8) + 4))(iVar7);

        FUN_00755f10(iVar7);

      }

      piVar8 = piVar8 + 1;

      iVar5 = iVar5 + -1;

    } while (iVar5 != 0);

    iVar7 = FUN_00755c30();

    iVar5 = iVar7;

    if (iVar7 != 0) {

      do {

        FUN_007afe80(iVar5,1);

        iVar5 = FUN_00755c30();

        if (iVar5 == 0) {

          return;

        }

      } while (iVar5 != iVar7);

    }

  }

  return;

}
