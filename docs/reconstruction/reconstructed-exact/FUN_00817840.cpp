// =============================================================================
// FUN_00817840
// -----------------------------------------------------------------------------
// Stable ID: aa_00817840
// Address:   0x00817840  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00817840 @ 0x00817840
// Stable ID: aa_00817840
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~95 non-empty decompiler lines.
//  - Control keywords: if×10, while×2, do×1, return×1.
//  - Notable callees: FUN_00418690, FUN_00419880, FUN_007b5dd0, FUN_00817840.
//  - Return sites: 1.

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

void FUN_00817840(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  char cVar2;

  int iVar3;

  int *piVar4;

  int *unaff_EBX;

  int iVar5;

  int *piVar6;

  int iVar7;

  int iVar8;

  int iStack_48;

  int *piStack_44;

  int iStack_40;

  int iStack_3c;

  uint8_t auStack_34 [32];

  void *pvStack_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ uStack_c;

  

  uStack_c = 0xffffffff;

  puStack_10 = &LAB_009b330a;

  pvStack_14 = ExceptionList;

  ExceptionList = &pvStack_14;

  cVar2 = (**(code **)(*unaff_EBX + 0x3d8))();

  if ((cVar2 != '\0') && ((char)unaff_EBX[0x1c3] != '\0')) {

    if ((unaff_EBX[0x205] != 0) &&

       (piStack_44 = (int *)(unaff_EBX[0x206] - unaff_EBX[0x205] >> 2), piStack_44 != (int *)0x0)) {

      iVar5 = 0;

      while( true ) {

        if (unaff_EBX[0x205] == 0) {

          iVar3 = 0;

        }

        else {

          iVar3 = unaff_EBX[0x206] - unaff_EBX[0x205] >> 2;

        }

        if (iVar3 <= iVar5) break;

        (**(code **)(*unaff_EBX + 0xb0))(*(uint32_t /* width from decompiler */ *)(unaff_EBX[0x205] + iVar5 * 4));

        puVar1 = *(uint32_t /* width from decompiler */ **)(unaff_EBX[0x205] + iVar5 * 4);

        if (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

          (**(code **)*puVar1)(1);

        }

        iVar5 = iVar5 + 1;

      }

      FUN_00418690(0);

    }

    iStack_48 = 0;

    if (0 < param_1) {

      do {

        piStack_44 = operator_new(0x488);

        piVar6 = (int *)0x0;

        uStack_c = 0;

        if (piStack_44 != (int *)0x0) {

          piVar6 = (int *)FUN_007b5dd0(piStack_44,0);

        }

        uStack_c = 0xffffffff;

        piStack_44 = piVar6;

        (**(code **)(*unaff_EBX + 0xa8))(piVar6);

        (**(code **)(*piVar6 + 0x28))(unaff_EBX + 0x1c3);

        (**(code **)(*piVar6 + 0xfc))(1,0x3f000000);

        if (unaff_EBX[0x1c2] != 0) {

          iVar8 = 0;

          iVar7 = 1;

          piVar4 = &iStack_40;

          (**(code **)(*(int *)unaff_EBX[0x1c2] + 0x120))(piVar4,1,0);

          iVar3 = 1;

          (**(code **)(*(int *)unaff_EBX[0x1c2] + 0x140))(auStack_34,1);

          iVar5 = 0;

          (**(code **)(*piVar6 + 0x120))(&stack0xffffffb4,1,0);

          if (*(char *)(unaff_EBX[0x1c2] + 0x4fd) == '\0') {

            iStack_40 = iVar3 + iVar7;

            iStack_3c = (int)piVar4 + iVar8 + ((int)piStack_44 * iVar5) / (param_1 + -1);

            piVar4 = &iStack_40;

          }

          else {

            piVar4 = (int *)&stack0xffffffb0;

          }

          (**(code **)(*piVar6 + 0x110))(piVar4);

        }

        iVar5 = unaff_EBX[0x205];

        if ((iVar5 == 0) ||

           ((uint)(unaff_EBX[0x207] - iVar5 >> 2) <= (uint)(unaff_EBX[0x206] - iVar5 >> 2))) {

          FUN_00419880(unaff_EBX + 0x204,unaff_EBX[0x206],&piStack_44);

        }

        else {

          puVar1 = (uint32_t /* width from decompiler */ *)unaff_EBX[0x206];

          *puVar1 = piVar6;

          unaff_EBX[0x206] = (int)(puVar1 + 1);

        }

        iStack_48 = iStack_48 + 1;

      } while (iStack_48 < param_1);

    }

  }

  ExceptionList = pvStack_14;

  return;

}
