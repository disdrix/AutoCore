// =============================================================================
// FUN_00582fb0
// -----------------------------------------------------------------------------
// Stable ID: aa_00582fb0
// Address:   0x00582fb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00582fb0 @ 0x00582fb0
// Stable ID: aa_00582fb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~69 non-empty decompiler lines.
//  - Control keywords: if×9, return×4.
//  - Notable callees: CONCAT31×2, FUN_005134e0×2, FUN_00492420, FUN_004962d0, FUN_00514d40, FUN_00581c10, FUN_00581dd0, FUN_00582570.
//  - Return sites: 4.

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

void __thiscall FUN_00582fb0(int param_1,char param_2)



{

  int *piVar1;

  bool bVar2;

  char extraout_AL;

  char cVar3;

  uint32_t /* width from decompiler */ in_EAX;

  uint3 uVar7;

  uint3 extraout_var;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint uStack_10;

  uint8_t auStack_c [12];

  

  uVar7 = (uint3)((uint)in_EAX >> 8);

  if ((*(char *)(param_1 + 0xe) == '\x03') || (*(char *)(param_1 + 0xe) != param_2)) {

    if ((param_2 == '\0') || (FUN_005134e0(), uVar7 = extraout_var, extraout_AL != '\0')) {

      iVar4 = (uint)uVar7 << 8;

    }

    else {

      iVar4 = CONCAT31(extraout_var,1);

    }

    FUN_00514d40(iVar4);

    if (param_2 == '\0') {

      if (*(char *)(param_1 + 0xe) != '\x03') {

        FUN_00582570();

      }

    }

    else {

      iVar4 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1);

      if ((iVar4 != 0) && (*(int *)(iVar4 + 0xe894) != 0)) {

        if ((*(char *)(iVar4 + 0x7d) == '\0') && (cVar3 = FUN_00581dd0(), cVar3 == '\0')) {

          return;

        }

        bVar2 = false;

        iVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x1d4))()

        ;

        if (((iVar4 != 0) &&

            (iVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) +

                                 0x1d4))(), *(char *)(iVar4 + 0x103) != '\0')) ||

           ((piVar1 = *(int **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1),

            piVar1 != (int *)0x0 &&

            ((iVar4 = (**(code **)(*piVar1 + 0x1d4))(), iVar4 != 0 &&

             (iVar4 = (**(code **)(**(int **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1)

                                  + 0x1d4))(), *(char *)(iVar4 + 0x103) != '\0')))))) {

          bVar2 = true;

        }

        cVar3 = FUN_005134e0();

        if ((cVar3 == '\0') || (bVar2)) {

          if (*(short *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + param_1 + 0xac) +

                                 0x3c) + 0x3f4) == 0xc) {

            FUN_00492420(param_1);

            *(char *)(param_1 + 0xe) = param_2;

            return;

          }

          iVar4 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1);

          uVar5 = CONCAT31((int3)((uint)iVar4 >> 8),*(int *)(param_1 + 8) == 0);

          uStack_10 = (uint)*(byte *)(iVar4 + 0xf5);

          uVar6 = FUN_00581c10(auStack_c);

          FUN_004962d0(param_1,uVar6,uStack_10,uVar5);

          *(char *)(param_1 + 0xe) = param_2;

          return;

        }

      }

    }

    *(char *)(param_1 + 0xe) = param_2;

  }

  return;

}
