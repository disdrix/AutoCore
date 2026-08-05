// =============================================================================
// FUN_004c5200
// -----------------------------------------------------------------------------
// Stable ID: aa_004c5200
// Address:   0x004c5200  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004c5200 @ 0x004c5200
// Stable ID: aa_004c5200
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×10, return×4.
//  - Notable callees: FUN_004c3690×2, FUN_004c5200, FUN_004cb3a0, FUN_0074e690, FUN_0074e6c0, FUN_0074e910, FUN_0079a110.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ __thiscall

FUN_004c5200(int *param_1,int param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5)



{

  int iVar1;

  char cVar2;

  float10 fVar3;

  float unaff_retaddr;

  

  (**(code **)(*param_1 + 0x68))(param_2,param_3,param_4,param_5);

  if (param_1[0x19] == 0) {

    param_1[0x2e] = param_2;

  }

  else if (param_1[param_2 + 0x1b] != 0) {

    if (((param_2 == param_1[0x2e]) && (g_flZero < *(float *)(param_1[param_2 + 0x1b] + 0x10))) &&

       (cVar2 = FUN_004c3690(param_2), cVar2 == '\0')) {

      return 0;

    }

    if (_DAT_00aaa608 < (double)unaff_retaddr) {

      fVar3 = (float10)FUN_0074e690();

      FUN_0074e6c0((float)((float10)unaff_retaddr / fVar3));

    }

    if ((char)param_4 != '\0') {

      fVar3 = (float10)FUN_0079a110();

      FUN_0074e910(0,(float)fVar3);

    }

    if ((*(char *)((int)param_1 + 0x305) == '\0') && (cVar2 = FUN_004c3690(param_2), cVar2 != '\0'))

    {

      if (param_1[0xb7] != -1) {

        (**(code **)(*(int *)param_1[0x19] + 0x18))(param_1[param_1[0xb7] + 0x1b],0,0);

      }

      param_1[0xb7] = param_2;

      (**(code **)(*(int *)param_1[0x19] + 0x18))(param_1[param_2 + 0x1b],param_3,0x40000000);

      *(uint8_t *)(param_1 + 0x13) = 1;

      return 1;

    }

    cVar2 = (**(code **)(*(int *)param_1[0x19] + 0x18))(param_1[param_2 + 0x1b],param_3,0x3f800000);

    if (cVar2 != '\0') {

      iVar1 = param_1[0x2e];

      if (param_2 != iVar1) {

        cVar2 = FUN_004cb3a0();

        if (cVar2 != '\0') {

          (**(code **)(*(int *)param_1[0x19] + 0x18))(param_1[iVar1 + 0x1b],param_3,0);

        }

        param_1[0x2e] = param_2;

      }

      *(uint8_t *)(param_1 + 0x13) = 1;

      return 1;

    }

  }

  return 0;

}
