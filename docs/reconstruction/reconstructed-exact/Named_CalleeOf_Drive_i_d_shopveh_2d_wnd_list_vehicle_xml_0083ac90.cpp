// =============================================================================
// Named_CalleeOf_Drive_i_d_shopveh_2d_wnd_list_vehicle_xml_0083ac90
// -----------------------------------------------------------------------------
// Stable ID: aa_0083ac90
// Callee of Drive_i_d_shopveh_2d_wnd_list_vehicle_xml
// Address:   0x0083ac90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Drive_i_d_shopveh_2d_wnd_list_vehicle_xml: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~89 non-empty decompiler lines.
//  - Control keywords: if×13, do×4, while×4, goto×1, return×1.
//  - Notable callees: FUN_0083abf0×3, FUN_00833d50×2, FUN_0083a880×2, FUN_00833160, FUN_0083a860, FUN_0083ac90.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Drive_i_d_shopveh_2d_wnd_list_vehicle_xml
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

void Named_CalleeOf_Drive_i_d_shopveh_2d_wnd_list_vehicle_xml_0083ac90(uint32_t /* width from decompiler */ *param_1)



{

  int iVar1;

  char cVar2;

  int in_EAX;

  int iVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  int *piVar6;

  int iVar7;

  int iVar8;

  

  iVar1 = (int)param_1;

  if ((-1 < in_EAX) && (in_EAX <= *(int *)((int)param_1 + 0x4fc))) {

    iVar8 = in_EAX + -2;

    *(int *)((int)param_1 + 0x500) = in_EAX;

    if (iVar8 <= in_EAX + 2) {

      do {

        if ((((-1 < iVar8) && (iVar8 < *(int *)(iVar1 + 0x4fc))) &&

            (iVar7 = (iVar8 - *(int *)(iVar1 + 0x500)) + 2, -1 < iVar7)) &&

           ((iVar7 < 5 && (*(int *)(iVar1 + 0x50c + iVar7 * 4) != 0)))) {

          iVar3 = (**(code **)(**(int **)(iVar1 + 0x50c + iVar7 * 4) + 0x78))();

          if (iVar3 + -0x9ca4 == iVar8) {

            cVar2 = FUN_0083a860();

            if (cVar2 == '\0') {

              FUN_0083abf0(iVar1);

            }

            else {

              FUN_0083a880(0);

            }

          }

          else {

            param_1 = (uint32_t /* width from decompiler */ *)(iVar1 + 0x50c);

            iVar3 = 0;

            do {

              if ((iVar3 != iVar7) &&

                 (iVar4 = (**(code **)(*(int *)*param_1 + 0x78))(), iVar4 + -0x9ca4 == iVar8)) {

                FUN_00833160();

                iVar4 = **(int **)(iVar1 + 0x50c + iVar3 * 4);

                uVar5 = (**(code **)(**(int **)(iVar1 + 0x50c + iVar7 * 4) + 0x78))();

                (**(code **)(iVar4 + 0x74))(uVar5);

                FUN_0083a880(0);

                if (4 < iVar3) {

                  FUN_0083abf0(iVar1);

                }

                goto LAB_0083ade5;

              }

              param_1 = param_1 + 1;

              iVar3 = iVar3 + 1;

            } while (iVar3 < 5);

            FUN_0083abf0(iVar1);

          }

LAB_0083ade5:

          (**(code **)(**(int **)(iVar1 + 0x50c + iVar7 * 4) + 0x74))(iVar8 + 0x9ca4);

        }

        iVar8 = iVar8 + 1;

      } while (iVar8 <= *(int *)(iVar1 + 0x500) + 2);

    }

    iVar8 = 0;

    if (-*(int *)(iVar1 + 0x500) != -2 && -1 < -*(int *)(iVar1 + 0x500) + 2) {

      piVar6 = (int *)(iVar1 + 0x50c);

      do {

        if (*piVar6 != 0) {

          if (*(int *)(*piVar6 + 0x508) != 0) {

            FUN_00833d50();

          }

          (**(code **)(*(int *)*piVar6 + 0x74))(0xffffffff);

        }

        iVar8 = iVar8 + 1;

        piVar6 = piVar6 + 1;

      } while (iVar8 < 2 - *(int *)(iVar1 + 0x500));

    }

    iVar8 = (*(int *)(iVar1 + 0x4fc) - *(int *)(iVar1 + 0x500)) + 2;

    if (iVar8 < 5) {

      piVar6 = (int *)(iVar1 + 0x50c + iVar8 * 4);

      iVar8 = 5 - iVar8;

      do {

        if (*piVar6 != 0) {

          if (*(int *)(*piVar6 + 0x508) != 0) {

            FUN_00833d50();

          }

          (**(code **)(*(int *)*piVar6 + 0x74))(0xffffffff);

        }

        piVar6 = piVar6 + 1;

        iVar8 = iVar8 + -1;

      } while (iVar8 != 0);

    }

  }

  return;

}
