// =============================================================================
// FUN_004912c0
// -----------------------------------------------------------------------------
// Stable ID: aa_004912c0
// Address:   0x004912c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004912c0 @ 0x004912c0
// Stable ID: aa_004912c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: if×4, switch×1, return×1.
//  - Notable callees: FUN_0079a110×2, FUN_00490820, FUN_00490af0, FUN_004912c0, FUN_00553cd0, FUN_00553dd0, FUN_0074e690, FUN_0074e910.
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



void __fastcall FUN_004912c0(int param_1)



{

  int iVar1;

  bool bVar2;

  float10 fVar3;

  float fVar4;

  float local_c;

  float local_4;

  

  if ((*(int *)(*(int *)(param_1 + 0xb8) + 0x78) == 0) || (*(int *)(param_1 + 0x180) == 0)) {

    local_4 = g_flOne;

  }

  else {

    fVar3 = (float10)FUN_00553cd0();

    local_4 = (float)fVar3;

    local_c = 0.0;

    fVar3 = (float10)FUN_00553dd0();

    fVar4 = (float)fVar3;

    switch(*(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 0xb8) + 0x78) + 0x154)) {

    case 0:

      local_c = fVar4 * DAT_00aaa6c0;

      break;

    case 1:

      local_c = (fVar4 + g_flOne) * DAT_00aaa6c0;

      break;

    case 2:

      local_c = fVar4 * DAT_00aaa6c0 + _DAT_00aaa684;

      break;

    case 3:

      local_c = g_flOne - fVar4;

    }

    fVar3 = (float10)FUN_0079a110();

    fVar4 = (float)fVar3;

    fVar3 = (float10)FUN_0074e690(fVar4);

    FUN_0074e910((float)(fVar3 * (float10)local_c),fVar4);

  }

  if ((*(int **)(param_1 + 0x188) != (int *)0x0) && (*(char *)(param_1 + 0x87) != '\0')) {

    iVar1 = **(int **)(param_1 + 0x188);

    fVar3 = (float10)FUN_0079a110(1);

    (**(code **)(iVar1 + 8))((float)fVar3);

  }

  local_c = 0.0;

  if ((*(short *)(param_1 + 0x98) < 0) && (*(short *)(param_1 + 0xa0) < 0)) {

    local_c = 1.4013e-45;

  }

  bVar2 = *(short *)(param_1 + 0xa8) < 0;

  if (((*(char *)(param_1 + 0x90) != '\0') && (*(int *)(param_1 + 0x94) != 0)) &&

     (FUN_00490af0(local_4,1,local_c,bVar2), g_flOne <= local_4)) {

    FUN_00490820(1,local_c,bVar2);

    *(uint8_t *)(param_1 + 0x90) = 0;

  }

  return;

}
