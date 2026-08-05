// =============================================================================
// FUN_00652f90
// -----------------------------------------------------------------------------
// Stable ID: aa_00652f90
// Address:   0x00652f90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00652f90 @ 0x00652f90
// Stable ID: aa_00652f90
// Embedded strings (evidence for future rename):
//   - "VisualDebugger: ["
//   - "ERROR: "
//   - "Unable to build display geometry from hkShape geometry data"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~71 non-empty decompiler lines.
//  - Control keywords: if×7, while×2, do×1, return×1.
//  - Notable callees: FUN_00631dc0×3, FUN_005b3370, FUN_00631da0, FUN_00631f80, FUN_00652f90, FUN_00661010, FUN_00661020, FUN_00662070.
//  - Strings: "VisualDebugger: ["; "ERROR: "; "Unable to build display geometry from hkShape geometry data".
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

void __thiscall FUN_00652f90(int param_1,int *param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  int iVar4;

  char *pcVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint8_t auStack_28 [8];

  int iStack_20;

  int iStack_1c;

  int iStack_18;

  

  iVar4 = param_2[3];

  iVar3 = (**(code **)(*param_2 + 0x14))();

  iStack_20 = 0;

  iStack_1c = 0;

  iStack_18 = -0x80000000;

  if (((iVar3 == 1) || (iVar3 == 2)) && (iVar4 != 0)) {

    FUN_00661010();

    FUN_00661020(auStack_28);

    FUN_00662070(iVar4,&iStack_20);

    iVar3 = iStack_20;

    iVar4 = iStack_1c;

    while (iVar4 = iVar4 + -1, -1 < iVar4) {

      iVar1 = *(int *)(iVar3 + iVar4 * 4);

      if ((*(int *)(iVar1 + 0x54) == 6) && (*(int *)(iVar1 + 0x50) == 0)) {

        if (-1 < DAT_00d030ec) {

          pcVar5 = "VisualDebugger: [";

          (**(code **)(*DAT_00d030e0 + 4))("VisualDebugger: [");

          FUN_00631dc0(pcVar5);

          pcVar5 = "ERROR: ";

          (**(code **)(*DAT_00d030e0 + 4))("ERROR: ");

          FUN_00631dc0(pcVar5);

          uVar6 = 0x5d;

          pcVar5 = "Unable to build display geometry from hkShape geometry data";

          (**(code **)(*DAT_00d030e0 + 4))

                    ("Unable to build display geometry from hkShape geometry data",0x5d);

          FUN_00631dc0(pcVar5);

          uVar6 = FUN_00631da0(uVar6);

          FUN_00631f80(uVar6);

          iVar3 = iStack_20;

        }

        iStack_1c = iStack_1c + -1;

        *(uint32_t /* width from decompiler */ *)(iVar3 + iVar4 * 4) = *(uint32_t /* width from decompiler */ *)(iVar3 + iStack_1c * 4);

        iVar3 = iStack_20;

      }

    }

    if (*(uint *)(param_1 + 0xc) == (*(uint *)(param_1 + 0x10) & 0x7fffffff)) {

      FUN_005b3370((int *)(param_1 + 8),4);

    }

    *(int **)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0xc) * 4) = param_2;

    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;

    iVar4 = DAT_00d034f8;

    (**(code **)(**(int **)(param_1 + -4) + 4))(&iStack_20,param_2[5] + 0x20,param_2 + 3,0);

    (**(code **)(**(int **)(iVar4 + -4) + 8))(DAT_00d034fc,param_2 + 3,0,DAT_00d034f8);

    iVar4 = 0;

    if (0 < iStack_1c) {

      do {

        puVar2 = *(uint32_t /* width from decompiler */ **)(iStack_20 + iVar4 * 4);

        if (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {

          (**(code **)*puVar2)(1);

        }

        iVar4 = iVar4 + 1;

      } while (iVar4 < iStack_1c);

    }

  }

  if (-1 < iStack_18) {

    (**(code **)(*DAT_00b05060 + 0x14))(iStack_20,iStack_18 * 4,0x12);

  }

  return;

}
