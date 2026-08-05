// =============================================================================
// FUN_00905740
// -----------------------------------------------------------------------------
// Stable ID: aa_00905740
// Address:   0x00905740  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00905740 @ 0x00905740
// Stable ID: aa_00905740
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×8, return×3.
//  - Notable callees: FUN_00905530×3, FUN_00905740.
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



void __thiscall FUN_00905740(uint32_t /* width from decompiler */ param_1,uint param_2,uint param_3)



{

  float fVar1;

  char cVar2;

  uint uVar3;

  int *unaff_ESI;

  int iVar4;

  

  cVar2 = (**(code **)(*unaff_ESI + 0x3d8))(param_1);

  if (cVar2 != '\0') {

    if ((param_2 & param_3) != 0xffffffff) {

      FUN_00905530(param_2,param_3);

      return;

    }

    if (*(int *)(DAT_00d1ad2c + 0x18) == 0) {

      iVar4 = 0;

    }

    else {

      iVar4 = *(int *)(DAT_00d1ad2c + 0x1c) - *(int *)(DAT_00d1ad2c + 0x18) >> 2;

    }

    if (unaff_ESI[0x149] < iVar4) {

      uVar3 = iVar4 - unaff_ESI[0x149];

      if (uVar3 < (uint)unaff_ESI[0x14c]) {

        unaff_ESI[0x14c] = uVar3;

      }

      if ((int *)unaff_ESI[0x14a] != (int *)0x0) {

        fVar1 = (float)unaff_ESI[0x14c];

        if (unaff_ESI[0x14c] < 0) {

          fVar1 = fVar1 + _DAT_00aaa5dc;

        }

        (**(code **)(*(int *)unaff_ESI[0x14a] + 0x454))(fVar1 / (float)(int)uVar3,0);

        (**(code **)(*(int *)unaff_ESI[0x14a] + 0x460))(g_flOne / (float)(iVar4 - unaff_ESI[0x149]))

        ;

        (**(code **)(*(int *)unaff_ESI[0x14a] + 0xd4))(1);

        FUN_00905530(0xffffffff,0xffffffff);

        return;

      }

    }

    else {

      unaff_ESI[0x14c] = 0;

      if ((int *)unaff_ESI[0x14a] != (int *)0x0) {

        (**(code **)(*(int *)unaff_ESI[0x14a] + 0x454))(0,0);

        (**(code **)(*(int *)unaff_ESI[0x14a] + 0x460))(0x3f800000);

        (**(code **)(*(int *)unaff_ESI[0x14a] + 0xd4))(0);

      }

    }

    FUN_00905530(0xffffffff,0xffffffff);

  }

  return;

}
