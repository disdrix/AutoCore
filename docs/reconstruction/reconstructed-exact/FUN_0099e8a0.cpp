// =============================================================================
// FUN_0099e8a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0099e8a0
// Address:   0x0099e8a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0099e8a0 @ 0x0099e8a0
// Stable ID: aa_0099e8a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~72 non-empty decompiler lines.
//  - Control keywords: if×4, for×1, return×1.
//  - Notable callees: FUN_0043f4b0, FUN_00734550, FUN_00752df0, FUN_0076f240, FUN_00967150, FUN_00972b20, FUN_00972e50, FUN_0099e8a0.
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

void __thiscall FUN_0099e8a0(int param_1,int param_2)



{

  int *piVar1;

  float *pfVar2;

  int iVar3;

  float *pfVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fStack_60;

  float fStack_5c;

  float fStack_58;

  uint32_t /* width from decompiler */ uStack_54;

  float afStack_50 [4];

  float fStack_40;

  float fStack_3c;

  float fStack_38;

  float fStack_30;

  float fStack_2c;

  float fStack_28;

  float fStack_20;

  float fStack_1c;

  float fStack_18;

  

  if (*(int *)(param_1 + 0x14) != 0) {

    FUN_0043f4b0();

  }

  if (*(int *)(*(int *)(param_1 + 0x14) + 0x34) == 0) {

    FUN_00967150(*(int *)(param_1 + 0x14) + 0x24);

  }

  FUN_00734550();

  piVar1 = *(int **)(param_2 + 0x10);

  pfVar2 = (float *)(**(code **)(*piVar1 + 0xc))();

  if (((uint)pfVar2[0x2f] & 1) != 0) {

    pfVar2 = (float *)FUN_00972e50();

  }

  pfVar4 = afStack_50;

  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {

    *pfVar4 = *pfVar2;

    pfVar2 = pfVar2 + 1;

    pfVar4 = pfVar4 + 1;

  }

  iVar3 = (**(code **)(*piVar1 + 0x48))();

  fStack_60 = (*(float *)(iVar3 + 0x20) + *(float *)(iVar3 + 0x14)) * DAT_00a0f298;

  fStack_5c = (*(float *)(iVar3 + 0x24) + *(float *)(iVar3 + 0x18)) * DAT_00a0f298;

  fStack_58 = (*(float *)(iVar3 + 0x28) + *(float *)(iVar3 + 0x1c)) * DAT_00a0f298;

  uStack_54 = 0;

  FUN_0076f240(&fStack_60);

  fStack_20 = fStack_20 + fStack_60;

  fStack_1c = fStack_1c + fStack_5c;

  fStack_18 = fStack_18 + fStack_58;

  fVar6 = (*(float *)(iVar3 + 0x24) - *(float *)(iVar3 + 0x18)) * DAT_00a0f298;

  fVar7 = (*(float *)(iVar3 + 0x20) - *(float *)(iVar3 + 0x14)) * DAT_00a0f298;

  fVar5 = (*(float *)(iVar3 + 0x28) - *(float *)(iVar3 + 0x1c)) * DAT_00a0f298;

  afStack_50[0] = afStack_50[0] * fVar7;

  afStack_50[1] = afStack_50[1] * fVar7;

  afStack_50[2] = afStack_50[2] * fVar7;

  fStack_40 = fStack_40 * fVar6;

  fStack_3c = fStack_3c * fVar6;

  fStack_38 = fStack_38 * fVar6;

  fStack_30 = fStack_30 * fVar5;

  fStack_2c = fStack_2c * fVar5;

  fStack_28 = fStack_28 * fVar5;

  iVar3 = (**(code **)(*piVar1 + 0xc))();

  if ((*(uint *)(iVar3 + 0xbc) >> 2 & 1) == 0) {

    iVar3 = iVar3 + 0xa8;

  }

  else {

    iVar3 = FUN_00972b20();

  }

  FUN_00752df0(*(uint32_t /* width from decompiler */ *)(param_2 + 4),afStack_50,1,iVar3,0,0);

  return;

}
