// =============================================================================
// UI_body_trick_icon
// -----------------------------------------------------------------------------
// Stable ID: aa_008ff260
// Address:   0x008ff260  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for UI_body_trick_icon @ 0x008ff260
// Stable ID: aa_008ff260
// Embedded strings (evidence for future rename):
//   - "i_d_body_2d_btn_trick.xml"
//   - "i_d_body_2d_wnd_trick_icon.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~98 non-empty decompiler lines.
//  - Control keywords: if×9, do×3, while×3, return×2.
//  - Notable callees: FUN_0078caf0, FUN_0079c860, FUN_008fc890, FUN_008fd1e0, UI_body_trick_icon.
//  - Strings: "i_d_body_2d_btn_trick.xml"; "i_d_body_2d_wnd_trick_icon.xml".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_body_2d_wnd_trick_icon.xml"
 * Domain alias of FUN_008ff260 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void UI_body_trick_icon(void)



{

  char cVar1;

  void *pvVar2;

  uint32_t /* width from decompiler */ uVar3;

  char *pcVar4;

  int *piVar5;

  int iVar6;

  int *unaff_EDI;

  void *pvStack_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b7b79;

  local_c = ExceptionList;

  if ((DAT_00d1b6d8 != 0) && (unaff_EDI[0x130] != 0)) {

    ExceptionList = &local_c;

    FUN_008fc890();

    if ((*(int *)(DAT_00d1b6d8 + 0x250) != 0) && (FUN_008fd1e0(), 0 < unaff_EDI[0x143])) {

      pvVar2 = operator_new__(unaff_EDI[0x146] * 4);

      iVar6 = 0;

      unaff_EDI[0x1ce] = (int)pvVar2;

      if (0 < unaff_EDI[0x146]) {

        do {

          pvVar2 = operator_new(0x4cc);

          uVar3 = 0;

          local_4 = 0;

          if (pvVar2 != (void *)0x0) {

            uVar3 = FUN_0079c860();

          }

          local_4 = 0xffffffff;

          *(uint32_t /* width from decompiler */ *)(unaff_EDI[0x1ce] + iVar6 * 4) = uVar3;

          (**(code **)(*unaff_EDI + 0xa8))();

          (**(code **)(**(int **)(unaff_EDI[0x1ce] + iVar6 * 4) + 0x28))

                    ("i_d_body_2d_btn_trick.xml");

          (**(code **)(**(int **)(unaff_EDI[0x1ce] + iVar6 * 4) + 0x74))(iVar6 + 0xc35d);

          (**(code **)(**(int **)(unaff_EDI[0x1ce] + iVar6 * 4) + 0x3b4))(1);

          (**(code **)(**(int **)(unaff_EDI[0x1ce] + iVar6 * 4) + 8))(unaff_EDI + 0x16f);

          (**(code **)(**(int **)(unaff_EDI[0x1ce] + iVar6 * 4) + 0x118))(&stack0xffffffd8);

          (**(code **)(**(int **)(unaff_EDI[0x1ce] + iVar6 * 4) + 0xcc))(0);

          if (iVar6 == 0) {

            pcVar4 = (char *)(**(code **)(**(int **)unaff_EDI[0x1ce] + 0x3b0))();

            piVar5 = unaff_EDI + 0x181;

            do {

              cVar1 = *pcVar4;

              *(char *)piVar5 = cVar1;

              pcVar4 = pcVar4 + 1;

              piVar5 = (int *)((int)piVar5 + 1);

            } while (cVar1 != '\0');

          }

          iVar6 = iVar6 + 1;

        } while (iVar6 < unaff_EDI[0x146]);

      }

      iVar6 = unaff_EDI[0x1a] + 1;

      unaff_EDI[0x1a] = iVar6;

      unaff_EDI[0x1d] = (int)(float)-iVar6;

      if (unaff_EDI[0x1c] < iVar6) {

        unaff_EDI[0x1c] = iVar6;

      }

      (**(code **)(*unaff_EDI + 0x3f4))();

      pvVar2 = operator_new__(unaff_EDI[0x146] * 4);

      iVar6 = 0;

      unaff_EDI[0x1ca] = (int)pvVar2;

      if (0 < unaff_EDI[0x146]) {

        do {

          pvVar2 = operator_new(0x4fc);

          local_4 = 1;

          if (pvVar2 == (void *)0x0) {

            uVar3 = 0;

          }

          else {

            uVar3 = FUN_0078caf0(pvVar2,0);

          }

          local_4 = 0xffffffff;

          *(uint32_t /* width from decompiler */ *)(unaff_EDI[0x1ca] + iVar6 * 4) = uVar3;

          (**(code **)(*unaff_EDI + 0xa8))();

          (**(code **)(**(int **)(unaff_EDI[0x1ca] + iVar6 * 4) + 0x28))

                    ("i_d_body_2d_wnd_trick_icon.xml");

          (**(code **)(**(int **)(unaff_EDI[0x1ca] + iVar6 * 4) + 8))(unaff_EDI + 0x171);

          (**(code **)(**(int **)(unaff_EDI[0x1ca] + iVar6 * 4) + 0x118))(&stack0xffffffe0);

          (**(code **)(**(int **)(unaff_EDI[0x1ca] + iVar6 * 4) + 0xcc))(0);

          iVar6 = iVar6 + 1;

        } while (iVar6 < unaff_EDI[0x146]);

      }

    }

    unaff_EDI[0x144] = unaff_EDI[0x143];

    if (unaff_EDI[0x143] <= unaff_EDI[0x146]) {

      (**(code **)(*(int *)unaff_EDI[0x1d2] + 0xd4))();

      ExceptionList = pvStack_10;

      return;

    }

    (**(code **)(*(int *)unaff_EDI[0x1d2] + 0x460))();

    (**(code **)(*(int *)unaff_EDI[0x1d2] + 0xd4))();

  }

  ExceptionList = local_c;

  return;

}
