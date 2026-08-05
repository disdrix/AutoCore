// =============================================================================
// FUN_00621980
// -----------------------------------------------------------------------------
// Stable ID: aa_00621980
// Address:   0x00621980  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00621980 @ 0x00621980
// Stable ID: aa_00621980
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: FUN_0058a5d0×2, FUN_00578270, FUN_005787a0, FUN_00621980.
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

uint32_t /* width from decompiler */ __thiscall FUN_00621980(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  int *piVar1;

  short sVar2;

  int iVar3;

  int iVar4;

  bool bVar5;

  int iVar6;

  uint32_t /* width from decompiler */ uVar7;

  float fVar8;

  

  if (((float)param_1[0x1b1] != g_flZero) && ((*(byte *)(param_1 + 0x192) & 0x40) != 0)) {

    FUN_0058a5d0(param_1[6],param_1 + 9,(float)param_1[0x1b1] * DAT_00aaa668,0x3f800000);

  }

  bVar5 = (float)param_1[99] * (float)param_1[0x1b0] != g_flZero;

  param_1[0x1b1] = (int)((float)param_1[99] * (float)param_1[0x1b0]);

  if (bVar5) {

    sVar2 = *(short *)((int)param_1 + 0x61a);

    iVar3 = param_1[0x188];

    iVar6 = param_1[0x66];

    iVar4 = *(int *)param_1[6];

    uVar7 = FUN_00578270(0,0,0);

    (**(code **)(iVar4 + 0x238))(0xf,iVar3,(int)(short)(sVar2 + (short)iVar6),0,uVar7);

    if ((*(byte *)(param_1 + 0x192) & 0x40) != 0) {

      FUN_0058a5d0(param_1[6],param_1 + 9,param_1[0x1b1],0x3f800000);

    }

  }

  fVar8 = (float)param_1[0x1b0] - ((float)param_1[0x1b0] - (float)param_1[0x62]);

  if (fVar8 < g_flOne) {

    fVar8 = g_flOne;

  }

  piVar1 = param_1 + 0x1b0;

  *piVar1 = *piVar1 - (int)fVar8;

  if (*piVar1 < 0) {

    param_1[0x1b0] = 0;

  }

  (**(code **)(*param_1 + 0x50))();

  FUN_005787a0(param_2);

  return param_2;

}
