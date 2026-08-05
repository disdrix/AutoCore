// =============================================================================
// FUN_0082e290
// -----------------------------------------------------------------------------
// Stable ID: aa_0082e290
// Address:   0x0082e290  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0082e290 @ 0x0082e290
// Stable ID: aa_0082e290
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~121 non-empty decompiler lines.
//  - Control keywords: if×21, return×2.
//  - Notable callees: FUN_0082e290.
//  - Return sites: 2.

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

void __fastcall FUN_0082e290(int *param_1)



{

  int iVar1;

  int *piVar2;

  char cVar3;

  char cVar4;

  uint32_t /* width from decompiler */ uVar5;

  

  cVar3 = (**(code **)(*param_1 + 0x3d8))();

  if (cVar3 != '\0') {

    if (param_1[0x153] != 0) {

      cVar3 = (**(code **)(*(int *)param_1[0x153] + 0x3bc))();

      cVar4 = (**(code **)(*DAT_00d1b874 + 0x3d8))();

      if (cVar3 != cVar4) {

        iVar1 = *(int *)param_1[0x153];

        uVar5 = (**(code **)(*DAT_00d1b874 + 0x3d8))(1);

        (**(code **)(iVar1 + 0x3c8))(uVar5);

        (**(code **)(*(int *)param_1[0x153] + 0x34c))();

      }

    }

    if (param_1[0x154] != 0) {

      cVar3 = (**(code **)(*(int *)param_1[0x154] + 0x3bc))();

      cVar4 = (**(code **)(*DAT_00d1b870 + 0x3d8))();

      if (cVar3 != cVar4) {

        iVar1 = *(int *)param_1[0x154];

        uVar5 = (**(code **)(*DAT_00d1b870 + 0x3d8))(1);

        (**(code **)(iVar1 + 0x3c8))(uVar5);

        (**(code **)(*(int *)param_1[0x154] + 0x34c))();

      }

    }

    if (param_1[0x155] != 0) {

      piVar2 = (int *)param_1[0x155];

      cVar3 = (**(code **)(*DAT_00d1b878 + 0x3d8))();

      cVar4 = (**(code **)(*piVar2 + 0x3bc))();

      if (cVar4 != cVar3) {

        iVar1 = *(int *)param_1[0x155];

        uVar5 = (**(code **)(*DAT_00d1b878 + 0x3d8))(1);

        (**(code **)(iVar1 + 0x3c8))(uVar5);

        (**(code **)(*(int *)param_1[0x155] + 0x34c))();

      }

    }

    if (param_1[0x156] != 0) {

      piVar2 = (int *)param_1[0x156];

      cVar3 = (**(code **)(*DAT_00d1b8b8 + 0x3d8))();

      cVar4 = (**(code **)(*piVar2 + 0x3bc))();

      if (cVar4 != cVar3) {

        iVar1 = *(int *)param_1[0x156];

        uVar5 = (**(code **)(*DAT_00d1b8b8 + 0x3d8))(1);

        (**(code **)(iVar1 + 0x3c8))(uVar5);

        (**(code **)(*(int *)param_1[0x156] + 0x34c))();

      }

    }

    if (param_1[0x157] != 0) {

      piVar2 = (int *)param_1[0x157];

      cVar3 = (**(code **)(*DAT_00d1b8bc + 0x3d8))();

      cVar4 = (**(code **)(*piVar2 + 0x3bc))();

      if (cVar4 != cVar3) {

        iVar1 = *(int *)param_1[0x157];

        uVar5 = (**(code **)(*DAT_00d1b8bc + 0x3d8))(1);

        (**(code **)(iVar1 + 0x3c8))(uVar5);

        (**(code **)(*(int *)param_1[0x157] + 0x34c))();

      }

    }

    if (param_1[0x158] != 0) {

      piVar2 = (int *)param_1[0x158];

      cVar3 = (**(code **)(*DAT_00d1b8b4 + 0x3d8))();

      cVar4 = (**(code **)(*piVar2 + 0x3bc))();

      if (cVar4 != cVar3) {

        iVar1 = *(int *)param_1[0x158];

        uVar5 = (**(code **)(*DAT_00d1b8b4 + 0x3d8))(1);

        (**(code **)(iVar1 + 0x3c8))(uVar5);

        (**(code **)(*(int *)param_1[0x158] + 0x34c))();

      }

    }

    if (param_1[0x159] != 0) {

      cVar3 = (**(code **)(*(int *)param_1[0x159] + 0x3bc))();

      cVar4 = (**(code **)(*DAT_00d1b914 + 0x3d8))();

      if (cVar3 != cVar4) {

        iVar1 = *(int *)param_1[0x159];

        uVar5 = (**(code **)(*DAT_00d1b914 + 0x3d8))(1);

        (**(code **)(iVar1 + 0x3c8))(uVar5);

        (**(code **)(*(int *)param_1[0x159] + 0x34c))();

      }

    }

    if (param_1[0x15a] != 0) {

      cVar3 = (**(code **)(*(int *)param_1[0x15a] + 0x3bc))();

      cVar4 = (**(code **)(*DAT_00d1b880 + 0x3d8))();

      if (cVar3 != cVar4) {

        iVar1 = *(int *)param_1[0x15a];

        uVar5 = (**(code **)(*DAT_00d1b880 + 0x3d8))(1);

        (**(code **)(iVar1 + 0x3c8))(uVar5);

        (**(code **)(*(int *)param_1[0x15a] + 0x34c))();

      }

    }

    if (param_1[0x15b] != 0) {

      piVar2 = (int *)param_1[0x15b];

      cVar3 = (**(code **)(*DAT_00d1b87c + 0x3d8))();

      cVar4 = (**(code **)(*piVar2 + 0x3bc))();

      if (cVar4 != cVar3) {

        iVar1 = *(int *)param_1[0x15b];

        uVar5 = (**(code **)(*DAT_00d1b87c + 0x3d8))(1);

        (**(code **)(iVar1 + 0x3c8))(uVar5);

        (**(code **)(*(int *)param_1[0x15b] + 0x34c))();

      }

    }

    if (param_1[0x15c] != 0) {

      piVar2 = (int *)param_1[0x15c];

      cVar3 = (**(code **)(*DAT_00d1b884 + 0x3d8))();

      cVar4 = (**(code **)(*piVar2 + 0x3bc))();

      if (cVar4 != cVar3) {

        iVar1 = *(int *)param_1[0x15c];

        uVar5 = (**(code **)(*DAT_00d1b884 + 0x3d8))(1);

        (**(code **)(iVar1 + 0x3c8))(uVar5);

                    /* WARNING: Could not recover jumptable at 0x0082e65a. Too many branches */

                    /* WARNING: Treating indirect jump as call */

        (**(code **)(*(int *)param_1[0x15c] + 0x34c))();

        return;

      }

    }

  }

  return;

}
