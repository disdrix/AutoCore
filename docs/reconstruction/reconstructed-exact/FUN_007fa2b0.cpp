// =============================================================================
// FUN_007fa2b0
// -----------------------------------------------------------------------------
// Stable ID: aa_007fa2b0
// Address:   0x007fa2b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007fa2b0 @ 0x007fa2b0
// Stable ID: aa_007fa2b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×5, goto×1, return×1.
//  - Notable callees: ABS×2, ROUND×2, fsin×2, FUN_007f9e90, FUN_007fa2b0.
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



void __thiscall FUN_007fa2b0(int *param_1,float param_2)



{

  char cVar1;

  float10 fVar2;

  float fVar3;

  char local_8;

  char local_7;

  char local_6;

  uint8_t local_5;

  int local_4;

  

  fVar3 = param_2 + (float)param_1[0x13a];

  param_1[0x13a] = (int)fVar3;

  if (*(char *)((int)param_1 + 0x489) == '\x01') {

    FUN_007f9e90(param_1);

  }

  else {

    if (param_1[0x13b] == 1) {

      local_8 = -1;

      local_5 = 0xff;

      fVar2 = (float10)fsin((float10)fVar3 + (float10)fVar3);

      local_4 = (int)ROUND(ABS(fVar2) * (float10)_DAT_00aaab00);

      local_6 = *(char *)((int)param_1 + 0x4e6) - (char)local_4;

      local_7 = *(char *)((int)param_1 + 0x4e5) - (char)local_4;

      (**(code **)(*param_1 + 0x15c))(0,&local_8);

    }

    else {

      if (param_1[0x13b] != 5) goto LAB_007fa3d6;

      fVar2 = (float10)fsin((float10)fVar3 * (float10)DAT_00a0f6a4);

      local_5 = 0xff;

      local_4 = (int)ROUND(ABS(fVar2) * (float10)_DAT_00aaab00);

      local_8 = (char)param_1[0x139] - (char)local_4;

      local_7 = *(char *)((int)param_1 + 0x4e5) - (char)local_4;

      local_6 = *(char *)((int)param_1 + 0x4e6) - (char)local_4;

      (**(code **)(*param_1 + 0x15c))(0,&local_8);

    }

    (**(code **)(*param_1 + 0x34c))();

  }

LAB_007fa3d6:

  (**(code **)(*param_1 + 500))(param_2);

  cVar1 = (**(code **)(*param_1 + 0xf8))();

  if (cVar1 != '\0') {

    (**(code **)(*param_1 + 0x348))(param_2);

  }

  if ((int *)param_1[0xad] != (int *)0x0) {

    (**(code **)(*(int *)param_1[0xad] + 8))(param_2);

  }

  return;

}
