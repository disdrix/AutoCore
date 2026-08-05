// =============================================================================
// FUN_004c5350
// -----------------------------------------------------------------------------
// Stable ID: aa_004c5350
// Address:   0x004c5350  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004c5350 @ 0x004c5350
// Stable ID: aa_004c5350
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×7, return×5.
//  - Notable callees: FUN_004c3690×2, FUN_004c5350, FUN_004cb3a0, FUN_0074e690, FUN_0074e6c0, FUN_0074e910, FUN_0079a110.
//  - Return sites: 5.

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

FUN_004c5350(int param_1,int param_2,uint32_t /* width from decompiler */ param_3,char param_4,float param_5)



{

  int iVar1;

  char cVar2;

  float10 fVar3;

  

  if ((*(int *)(param_1 + 0x288) == 0) ||

     (iVar1 = *(int *)(param_1 + 0x290 + param_2 * 4), iVar1 == 0)) {

    return 0;

  }

  if ((param_2 == *(int *)(param_1 + 0xb8)) &&

     ((g_flZero < *(float *)(iVar1 + 0x10) && (cVar2 = FUN_004c3690(param_2), cVar2 == '\0')))) {

    return 0;

  }

  if (_DAT_00aaa608 < (double)param_5) {

    fVar3 = (float10)FUN_0074e690();

    FUN_0074e6c0((float)((float10)param_5 / fVar3));

  }

  if (param_4 != '\0') {

    fVar3 = (float10)FUN_0079a110();

    FUN_0074e910(0,(float)fVar3);

  }

  cVar2 = FUN_004c3690(param_2);

  if (cVar2 == '\0') {

    cVar2 = (**(code **)(**(int **)(param_1 + 0x288) + 0x18))

                      (*(uint32_t /* width from decompiler */ *)(param_1 + 0x290 + param_2 * 4),param_3,0x3f800000);

    if (cVar2 == '\0') {

      return 0;

    }

    iVar1 = *(int *)(param_1 + 0xb8);

    if (((param_2 != iVar1) && (cVar2 = FUN_004cb3a0(), cVar2 != '\0')) &&

       (iVar1 = *(int *)(param_1 + 0x290 + iVar1 * 4), iVar1 != 0)) {

      (**(code **)(**(int **)(param_1 + 0x288) + 0x18))(iVar1,param_3,0);

    }

    *(uint8_t *)(param_1 + 0x4c) = 1;

    return 1;

  }

  (**(code **)(**(int **)(param_1 + 0x288) + 0x18))

            (*(uint32_t /* width from decompiler */ *)(param_1 + 0x290 + param_2 * 4),param_3,0x3f800000);

  return 1;

}
