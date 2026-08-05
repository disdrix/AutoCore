// =============================================================================
// FUN_005d8e30
// -----------------------------------------------------------------------------
// Stable ID: aa_005d8e30
// Address:   0x005d8e30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005d8e30 @ 0x005d8e30
// Stable ID: aa_005d8e30
// Embedded strings (evidence for future rename):
//   - "VisualDebugger: ["
//   - "Server deleted"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~74 non-empty decompiler lines.
//  - Control keywords: if×10, do×2, while×2, return×1.
//  - Notable callees: FUN_00631dc0×2, FUN_0055e370, FUN_0055e410, FUN_005d8710, FUN_005d8e30, FUN_00631da0, FUN_00631f80, FUN_00638180.
//  - Strings: "VisualDebugger: ["; "Server deleted".
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

void __fastcall FUN_005d8e30(uint32_t /* width from decompiler */ *param_1)



{

  int *piVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int *piVar3;

  int iVar4;

  int iVar5;

  char *pcVar6;

  uint32_t /* width from decompiler */ uVar7;

  

  *param_1 = &PTR_FUN_009db36c;

  param_1[1] = &PTR_LAB_009db364;

  param_1[2] = &PTR_LAB_009db35c;

  FUN_006646b0(param_1);

  puVar2 = (uint32_t /* width from decompiler */ *)param_1[0xc];

  if ((puVar2 != (uint32_t /* width from decompiler */ *)0x0) &&

     (*(short *)((int)puVar2 + 6) = *(short *)((int)puVar2 + 6) + -1,

     *(short *)((int)puVar2 + 6) == 0)) {

    (**(code **)*puVar2)(1);

  }

  if (param_1[3] != 0) {

    FUN_0055e410(param_1 + 1);

    FUN_0055e370(param_1 + 2);

  }

  iVar5 = param_1[6] + -1;

  if (-1 < iVar5) {

    iVar4 = iVar5 * 0x14;

    do {

      (**(code **)(**(int **)(param_1[5] + iVar4 + 4) + 0x34))(0x3e23d70a);

      FUN_005d8710(iVar5);

      iVar5 = iVar5 + -1;

      iVar4 = iVar4 + -0x14;

    } while (-1 < iVar5);

  }

  iVar5 = 0;

  if (0 < (int)param_1[9]) {

    do {

      piVar3 = *(int **)(param_1[8] + iVar5 * 4);

      if (piVar3 != (int *)0x0) {

        piVar1 = (int *)(*piVar3 + -4);

        *piVar1 = *piVar1 + -1;

        if (*piVar1 < 0) {

          FUN_00638180();

        }

        (**(code **)(*DAT_00b05060 + 0x14))(piVar3,4,0x11);

      }

      iVar5 = iVar5 + 1;

    } while (iVar5 < (int)param_1[9]);

  }

  param_1[9] = 0;

  if ((uint32_t /* width from decompiler */ *)param_1[4] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[4])(1);

  }

  if (0 < DAT_00d030ec) {

    pcVar6 = "VisualDebugger: [";

    (**(code **)(*DAT_00d030e0 + 4))("VisualDebugger: [");

    FUN_00631dc0(pcVar6);

    uVar7 = 0x5d;

    pcVar6 = "Server deleted";

    (**(code **)(*DAT_00d030e0 + 4))("Server deleted",0x5d);

    FUN_00631dc0(pcVar6);

    uVar7 = FUN_00631da0(uVar7);

    FUN_00631f80(uVar7);

  }

  if (-1 < (int)param_1[10]) {

    (**(code **)(*DAT_00b05060 + 0x14))(param_1[8],param_1[10] * 4,0x12);

  }

  if (-1 < (int)param_1[7]) {

    (**(code **)(*DAT_00b05060 + 0x14))(param_1[5],(param_1[7] & 0x7fffffff) * 0x14,0x12);

  }

  param_1[2] = &PTR_LAB_009db1d0;

  param_1[1] = &PTR_LAB_009db1d8;

  *param_1 = &PTR_LAB_009db1e0;

  return;

}
