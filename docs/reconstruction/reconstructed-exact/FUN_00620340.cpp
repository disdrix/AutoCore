// =============================================================================
// FUN_00620340
// -----------------------------------------------------------------------------
// Stable ID: aa_00620340
// Address:   0x00620340  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00620340 @ 0x00620340
// Stable ID: aa_00620340
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~48 non-empty decompiler lines.
//  - Control keywords: if×8, return×2.
//  - Notable callees: FUN_004c3700×2, FUN_00578b30×2, FUN_00578270, FUN_0058a5d0, FUN_00620340.
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

void __fastcall FUN_00620340(int param_1)



{

  short sVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  int *piVar4;

  int iVar5;

  

  iVar2 = (**(code **)(**(int **)(param_1 + 0x18) + 0x214))();

  iVar5 = iVar2;

  if (iVar2 != 0) {

    iVar5 = *(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2;

  }

  FUN_0058a5d0(iVar5,param_1 + 0x24,0x3f800000,0x3f800000);

  if (*(float *)(param_1 + 0x70) != 0.0) {

    (**(code **)(**(int **)(param_1 + 0x18) + 0x248))((int)*(float *)(param_1 + 0x70));

    iVar5 = **(int **)(param_1 + 0x18);

    uVar3 = (**(code **)(**(int **)(param_1 + 0x18) + 0x244))();

    (**(code **)(iVar5 + 0x240))(uVar3);

  }

  if (*(float *)(param_1 + 0x184) != 0.0) {

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0x1f0) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x184);

  }

  if (*(float *)(param_1 + 0x188) != 0.0) {

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0x1f8) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x188);

  }

  sVar1 = *(short *)(param_1 + 0x100);

  if (sVar1 != 0) {

    if (sVar1 == -1) {

      piVar4 = (int *)FUN_00578270();

      if (piVar4 != (int *)0x0) {

        iVar5 = (**(code **)(*piVar4 + 0x210))(0);

        if (iVar5 != 0) {

          iVar5 = (**(code **)(*piVar4 + 0x210))(0);

          uVar3 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5) + 0x27c))();

          FUN_004c3700(uVar3);

          FUN_00578b30();

          return;

        }

      }

    }

    else {

      iVar5 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2) + 0x27c))();

      FUN_004c3700(iVar5 + sVar1);

    }

  }

  FUN_00578b30();

  return;

}
