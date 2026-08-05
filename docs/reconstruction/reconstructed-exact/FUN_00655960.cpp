// =============================================================================
// FUN_00655960
// -----------------------------------------------------------------------------
// Stable ID: aa_00655960
// Address:   0x00655960  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00655960 @ 0x00655960
// Stable ID: aa_00655960
// Embedded strings (evidence for future rename):
//   - "VisualDebugger: ["
//   - "ERROR: "
//   - "Unable to build display geometry from hkShape geometry data"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~77 non-empty decompiler lines.
//  - Control keywords: if×8, while×2, do×1, return×1.
//  - Notable callees: FUN_00631dc0×3, FUN_005b3370, FUN_00631da0, FUN_00631f80, FUN_00655960, FUN_00661010, FUN_00661020, FUN_00662070.
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

void __thiscall FUN_00655960(int param_1,int param_2)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  char *pcVar4;

  uint32_t /* width from decompiler */ uVar5;

  int iVar6;

  uint8_t local_28 [8];

  int local_20;

  int local_1c;

  uint32_t /* width from decompiler */ local_18;

  

  piVar1 = (int *)(param_2 + 0xc);

  if (*piVar1 != 0) {

    local_20 = 0;

    local_1c = 0;

    local_18 = 0x80000000;

    FUN_00661010();

    FUN_00661020(local_28);

    FUN_00662070(*piVar1,&local_20);

    iVar3 = local_20;

    iVar6 = local_1c;

    while (iVar6 = iVar6 + -1, -1 < iVar6) {

      iVar2 = *(int *)(iVar3 + iVar6 * 4);

      if ((*(int *)(iVar2 + 0x54) == 6) && (*(int *)(iVar2 + 0x50) == 0)) {

        if (-1 < DAT_00d030ec) {

          pcVar4 = "VisualDebugger: [";

          (**(code **)(*DAT_00d030e0 + 4))("VisualDebugger: [");

          FUN_00631dc0(pcVar4);

          pcVar4 = "ERROR: ";

          (**(code **)(*DAT_00d030e0 + 4))("ERROR: ");

          FUN_00631dc0(pcVar4);

          uVar5 = 0x5d;

          pcVar4 = "Unable to build display geometry from hkShape geometry data";

          (**(code **)(*DAT_00d030e0 + 4))

                    ("Unable to build display geometry from hkShape geometry data",0x5d);

          FUN_00631dc0(pcVar4);

          uVar5 = FUN_00631da0(uVar5);

          FUN_00631f80(uVar5);

          iVar3 = local_20;

        }

        local_1c = local_1c + -1;

        *(uint32_t /* width from decompiler */ *)(iVar3 + iVar6 * 4) = *(uint32_t /* width from decompiler */ *)(iVar3 + local_1c * 4);

        iVar3 = local_20;

      }

    }

    if (*(uint *)(param_1 + 0xc) == (*(uint *)(param_1 + 0x10) & 0x7fffffff)) {

      FUN_005b3370((int *)(param_1 + 8),8);

    }

    iVar6 = *(int *)(param_1 + 0xc);

    iVar3 = *(int *)(param_1 + 8);

    *(int **)(iVar3 + iVar6 * 8) = piVar1;

    *(uint32_t /* width from decompiler */ *)(iVar3 + 4 + iVar6 * 8) = 0;

    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;

    iVar3 = 0;

    iVar6 = DAT_00d0351c;

    (**(code **)(**(int **)(param_1 + -4) + 4))(&local_20,*(int *)(param_2 + 0x3c) + 0x80);

    uVar5 = DAT_00d03520;

    if (*(char *)(param_2 + 0x40) == '\0') {

      uVar5 = DAT_00d03524;

    }

    (**(code **)(**(int **)(param_1 + -4) + 8))(uVar5,piVar1,0,DAT_00d0351c);

    iVar2 = 0;

    if (0 < iVar3) {

      do {

        if ((uint32_t /* width from decompiler */ *)piVar1[iVar2] != (uint32_t /* width from decompiler */ *)0x0) {

          (*(code *)**(uint32_t /* width from decompiler */ **)piVar1[iVar2])(1);

        }

        iVar2 = iVar2 + 1;

      } while (iVar2 < iVar3);

    }

    if (-1 < iVar6) {

      (**(code **)(*DAT_00b05060 + 0x14))(piVar1,iVar6 * 4,0x12);

    }

  }

  return;

}
