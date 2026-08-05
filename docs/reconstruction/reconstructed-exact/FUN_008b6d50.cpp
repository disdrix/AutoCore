// =============================================================================
// FUN_008b6d50
// -----------------------------------------------------------------------------
// Stable ID: aa_008b6d50
// Address:   0x008b6d50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008b6d50 @ 0x008b6d50
// Stable ID: aa_008b6d50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~58 non-empty decompiler lines.
//  - Control keywords: if×10, return×3.
//  - Notable callees: FUN_008b6be0×3, FUN_008b6d50.
//  - Return sites: 3.

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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_008b6d50(uint param_1,uint param_2)



{

  int *piVar1;

  float fVar2;

  char cVar3;

  uint uVar4;

  int *unaff_ESI;

  int iVar5;

  

  cVar3 = (**(code **)(*unaff_ESI + 0x3d8))();

  if (cVar3 != '\0') {

    if ((param_1 & param_2) != 0xffffffff) {

      FUN_008b6be0(param_1,param_2);

      return;

    }

    if (*(int *)(DAT_00d1ad2c + 8) == 0) {

      iVar5 = 0;

    }

    else {

      iVar5 = *(int *)(DAT_00d1ad2c + 0xc) - *(int *)(DAT_00d1ad2c + 8) >> 2;

    }

    if (unaff_ESI[0x148] < iVar5) {

      uVar4 = iVar5 - unaff_ESI[0x148];

      if (uVar4 < (uint)unaff_ESI[0x14b]) {

        unaff_ESI[0x14b] = uVar4;

      }

      if ((int *)unaff_ESI[0x149] != (int *)0x0) {

        (**(code **)(*(int *)unaff_ESI[0x149] + 0x460))(g_flOne / (float)(int)uVar4);

        (**(code **)(*(int *)unaff_ESI[0x149] + 0xd4))(1);

        fVar2 = (float)unaff_ESI[0x14b];

        if (unaff_ESI[0x14b] < 0) {

          fVar2 = fVar2 + _DAT_00aaa5dc;

        }

        (**(code **)(*(int *)unaff_ESI[0x149] + 0x454))(fVar2 / (float)(iVar5 - unaff_ESI[0x148]),0)

        ;

      }

    }

    else {

      unaff_ESI[0x14b] = 0;

      if ((int *)unaff_ESI[0x149] != (int *)0x0) {

        (**(code **)(*(int *)unaff_ESI[0x149] + 0x454))(0,0);

        (**(code **)(*(int *)unaff_ESI[0x149] + 0x460))(0x3f800000);

        (**(code **)(*(int *)unaff_ESI[0x149] + 0xd4))(0);

      }

    }

    piVar1 = (int *)unaff_ESI[0x14e];

    if (piVar1 != (int *)0x0) {

      if (iVar5 == 0) {

        (**(code **)(*piVar1 + 4))(1);

        FUN_008b6be0(0xffffffff,0xffffffff);

        return;

      }

      (**(code **)(*piVar1 + 4))(0);

    }

    FUN_008b6be0(0xffffffff,0xffffffff);

  }

  return;

}
