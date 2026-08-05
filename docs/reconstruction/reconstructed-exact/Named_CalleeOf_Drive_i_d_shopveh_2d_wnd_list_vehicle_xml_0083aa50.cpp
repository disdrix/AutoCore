// =============================================================================
// Named_CalleeOf_Drive_i_d_shopveh_2d_wnd_list_vehicle_xml_0083aa50
// -----------------------------------------------------------------------------
// Stable ID: aa_0083aa50
// Callee of Drive_i_d_shopveh_2d_wnd_list_vehicle_xml
// Address:   0x0083aa50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Drive_i_d_shopveh_2d_wnd_list_vehicle_xml: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~62 non-empty decompiler lines.
//  - Control keywords: if×8, while×2, do×1, goto×1, return×1.
//  - Notable callees: FUN_004022a0×2, FUN_00415c00, FUN_004294f0, FUN_0083aa50, LeaveCriticalSection.
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

void __fastcall Named_CalleeOf_Drive_i_d_shopveh_2d_wnd_list_vehicle_xml_0083aa50(int param_1)



{

  int iVar1;

  int *piVar2;

  char cVar3;

  int iVar4;

  int iVar5;

  int local_10;

  uint32_t /* width from decompiler */ local_c;

  int *local_8;

  int local_4;

  

  iVar1 = *(int *)(param_1 + 0x508);

  if ((iVar1 != 0) && (iVar1 != -0x2c)) {

    local_8 = (int *)(param_1 + 0x50c);

    local_4 = 5;

    do {

      piVar2 = (int *)*local_8;

      if (piVar2 != (int *)0x0) {

        if (piVar2[0x142] != 0) {

          iVar4 = piVar2[0x143];

          if (iVar4 == 0) {

            iVar4 = 0;

          }

          else {

            iVar4 = *(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4;

          }

          cVar3 = FUN_00415c00(iVar4);

          if (cVar3 != '\0') {

            iVar4 = 0;

            local_c = 0;

            local_10 = 0;

            FUN_004294f0();

            iVar5 = FUN_004022a0(&local_c,&local_10);

            while (iVar5 == 0) {

              iVar5 = piVar2[0x143];

              if (iVar5 == 0) {

                iVar5 = 0;

              }

              else {

                iVar5 = *(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5;

              }

              if (local_10 == iVar5) break;

              iVar4 = iVar4 + 1;

              iVar5 = FUN_004022a0(&local_c,&local_10);

            }

            if (*(char *)(iVar1 + 0x54) != '\0') {

              *(uint8_t *)(iVar1 + 0x54) = 0;

              LeaveCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0x30));

            }

            (**(code **)(*piVar2 + 0x74))(iVar4 + 0x9ca4);

            goto LAB_0083ab51;

          }

        }

        (**(code **)(*piVar2 + 0x74))(0xffffffff);

      }

LAB_0083ab51:

      local_8 = local_8 + 1;

      local_4 = local_4 + -1;

    } while (local_4 != 0);

  }

  return;

}
