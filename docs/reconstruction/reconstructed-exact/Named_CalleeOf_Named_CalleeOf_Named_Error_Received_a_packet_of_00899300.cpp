// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Error_Received_a_packet_of_00899300
// -----------------------------------------------------------------------------
// Stable ID: aa_00899300
// Callee of Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d
// Address:   0x00899300  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d: packet/network helper. Evidence string: "*%s %d". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "*%s %d"
//   - "*%s %d %d/%d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~80 non-empty decompiler lines.
//  - Control keywords: if×9, return×2, do×1, while×1.
//  - Notable callees: sprintf×5, CNDHash_LookupByKey, FUN_00541a80, FUN_00899300.
//  - Strings: "*%s"; "*%s %d"; "*%s %d %d/%d"; "%s %d".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d
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

void Named_CalleeOf_Named_CalleeOf_Named_Error_Received_a_packet_of_00899300(int *param_1)



{

  int iVar1;

  int iVar2;

  char cVar3;

  void *pvVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  uint key;

  int iStack_8c;

  int iStack_88;

  char acStack_80 [128];

  

  iVar6 = 0;

  if ((((DAT_00d1b6d8 != 0) && (param_1[0x14a] != 0)) &&

      (cVar3 = (**(code **)(*param_1 + 0x3d8))(), cVar3 != '\0')) &&

     ((DAT_00d1b644 != 0 && (*(int *)(DAT_00d1b644 + 0xe50c) != 0)))) {

    (**(code **)(*(int *)param_1[0x14a] + 0x450))();

    key = *(uint *)(DAT_00d1b644 + 0xfc);

    pvVar4 = (void *)FUN_00541a80();

    pvVar4 = CNDHash_LookupByKey(pvVar4,key);

    if (pvVar4 != (void *)0x0) {

      iStack_88 = *(int *)((int)pvVar4 + 0x144);

      if (iStack_88 == 0) {

        iStack_88 = 0x32;

      }

      if (DAT_00d1b4a8 < 1) {

        sprintf(acStack_80,"*%s",*(int *)(DAT_00d1b644 + 0xe50c) + 0xc);

        (**(code **)(*(int *)param_1[0x14a] + 0x448))(acStack_80);

      }

      else {

        iStack_8c = 0;

        iVar5 = DAT_00d1b6d8;

        iVar7 = DAT_00d1b4ac;

        do {

          iVar1 = *(int *)(iStack_8c + 0xc + iVar7);

          if ((iVar1 < iStack_88) || (0 < *(int *)(iVar5 + 0x6b4))) {

            iVar2 = *(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 0xa8 + iVar5);

            if ((*(int *)(iVar7 + iStack_8c) == *(int *)(iVar2 + 0x948)) &&

               (*(int *)(iVar7 + 4 + iStack_8c) == *(int *)(iVar2 + 0x94c))) {

              if (*(int *)(iVar5 + 0x6b4) < 1) {

                sprintf(acStack_80,"*%s %d",*(int *)(DAT_00d1b644 + 0xe50c) + 0xc,iVar6);

              }

              else {

                sprintf(acStack_80,"*%s %d %d/%d",*(int *)(DAT_00d1b644 + 0xe50c) + 0xc,iVar6,iVar1,

                        iStack_88);

              }

              (**(code **)(*(int *)param_1[0x14a] + 0x448))(acStack_80);

              iVar5 = DAT_00d1b6d8;

              iVar7 = DAT_00d1b4ac;

            }

            else {

              if (*(int *)(iVar5 + 0x6b4) < 1) {

                sprintf(acStack_80,"%s %d",*(int *)(DAT_00d1b644 + 0xe50c) + 0xc,iVar6);

              }

              else {

                sprintf(acStack_80,"%s %d %d/%d",*(int *)(DAT_00d1b644 + 0xe50c) + 0xc,iVar6,iVar1,

                        iStack_88);

              }

              (**(code **)(*(int *)param_1[0x14a] + 0x448))(acStack_80);

              iVar5 = DAT_00d1b6d8;

              iVar7 = DAT_00d1b4ac;

            }

          }

          iStack_8c = iStack_8c + 0x18;

          iVar6 = iVar6 + 1;

        } while (iVar6 < DAT_00d1b4a8);

      }

      (**(code **)(*(int *)param_1[0x14a] + 0x460))(0);

      iVar6 = (**(code **)(*(int *)param_1[0x14a] + 0x464))();

      param_1[0x150] = iVar6;

      if (iStack_88 == -1) {

        (**(code **)(*(int *)param_1[0x14a] + 0x460))(0);

        return;

      }

      (**(code **)(*(int *)param_1[0x14a] + 0x45c))(iStack_88);

    }

  }

  return;

}
