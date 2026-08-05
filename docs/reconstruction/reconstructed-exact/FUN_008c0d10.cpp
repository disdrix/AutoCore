// =============================================================================
// FUN_008c0d10
// -----------------------------------------------------------------------------
// Stable ID: aa_008c0d10
// Address:   0x008c0d10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008c0d10 @ 0x008c0d10
// Stable ID: aa_008c0d10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~79 non-empty decompiler lines.
//  - Control keywords: if×13, return×1.
//  - Notable callees: FUN_00410420, FUN_008c02d0, FUN_008c0b10, FUN_008c0d10.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_008c0d10(void)



{

  int iVar1;

  float fVar2;

  float fVar3;

  int *in_EAX;

  int iVar4;

  

  FUN_00410420(0,0);

  if (in_EAX[0x155] != 0) {

    FUN_008c02d0();

  }

  if (in_EAX[0x15a] == 0) {

    iVar4 = 0;

  }

  else {

    iVar4 = in_EAX[0x15b] - in_EAX[0x15a] >> 2;

  }

  iVar1 = in_EAX[0x14c];

  if (iVar1 < iVar4) {

    if (in_EAX[0x15a] == 0) {

      iVar4 = 0;

    }

    else {

      iVar4 = in_EAX[0x15b] - in_EAX[0x15a] >> 2;

    }

    if ((uint)(iVar4 - iVar1) < (uint)in_EAX[0x158]) {

      if (in_EAX[0x15a] == 0) {

        iVar4 = 0;

      }

      else {

        iVar4 = in_EAX[0x15b] - in_EAX[0x15a] >> 2;

      }

      in_EAX[0x158] = iVar4 - iVar1;

    }

    if ((int *)in_EAX[0x156] != (int *)0x0) {

      if (in_EAX[0x15a] == 0) {

        iVar4 = 0;

      }

      else {

        iVar4 = in_EAX[0x15b] - in_EAX[0x15a] >> 2;

      }

      fVar2 = (float)(iVar4 - iVar1);

      if (iVar4 - iVar1 < 0) {

        fVar2 = fVar2 + _DAT_00aaa5dc;

      }

      (**(code **)(*(int *)in_EAX[0x156] + 0x460))(g_flOne / fVar2);

      (**(code **)(*(int *)in_EAX[0x156] + 0xd4))(1);

      if (in_EAX[0x15a] == 0) {

        iVar4 = 0;

      }

      else {

        iVar4 = in_EAX[0x15b] - in_EAX[0x15a] >> 2;

      }

      fVar2 = (float)in_EAX[0x158];

      if (in_EAX[0x158] < 0) {

        fVar2 = fVar2 + _DAT_00aaa5dc;

      }

      fVar3 = (float)(iVar4 - in_EAX[0x14c]);

      if (iVar4 - in_EAX[0x14c] < 0) {

        fVar3 = fVar3 + _DAT_00aaa5dc;

      }

      (**(code **)(*(int *)in_EAX[0x156] + 0x454))(fVar2 / fVar3,0);

    }

  }

  else {

    in_EAX[0x158] = 0;

    if ((int *)in_EAX[0x156] != (int *)0x0) {

      (**(code **)(*(int *)in_EAX[0x156] + 0x454))(0,0);

      (**(code **)(*(int *)in_EAX[0x156] + 0x460))(0x3f800000);

      (**(code **)(*(int *)in_EAX[0x156] + 0xd4))(0);

    }

  }

  FUN_008c0b10();

                    /* WARNING: Could not recover jumptable at 0x008c0e93. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (**(code **)(*in_EAX + 0x450))();

  return;

}
