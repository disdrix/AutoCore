// =============================================================================
// FUN_0099d780
// -----------------------------------------------------------------------------
// Stable ID: aa_0099d780
// Address:   0x0099d780  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0099d780 @ 0x0099d780
// Stable ID: aa_0099d780
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~76 non-empty decompiler lines.
//  - Control keywords: if×5, for×1, return×1.
//  - Notable callees: FUN_0043f4b0, FUN_0044b930, FUN_00734550, FUN_00752df0, FUN_0076f240, FUN_00967150, FUN_00972b20, FUN_00972e50.
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

void __thiscall FUN_0099d780(int param_1,int param_2)



{

  int *piVar1;

  int iVar2;

  float *pfVar3;

  int iVar4;

  float *pfVar5;

  float fVar6;

  float fVar7;

  float fVar8;

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

  

  if (*(int *)(param_1 + 0xc) != 0) {

    FUN_0044b930(0);

  }

  if (*(int *)(param_1 + 0x14) != 0) {

    FUN_0043f4b0();

  }

  if (*(int *)(*(int *)(param_1 + 0x14) + 0x34) == 0) {

    FUN_00967150(*(int *)(param_1 + 0x14) + 0x24);

  }

  FUN_00734550();

  piVar1 = *(int **)(param_2 + 0x10);

  iVar2 = (**(code **)(*piVar1 + 0x48))();

  pfVar3 = (float *)(**(code **)(*piVar1 + 0xc))();

  if (((uint)pfVar3[0x2f] & 1) != 0) {

    pfVar3 = (float *)FUN_00972e50();

  }

  pfVar5 = afStack_50;

  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {

    *pfVar5 = *pfVar3;

    pfVar3 = pfVar3 + 1;

    pfVar5 = pfVar5 + 1;

  }

  fStack_60 = (*(float *)(iVar2 + 0x20) + *(float *)(iVar2 + 0x14)) * DAT_00a0f298;

  fStack_5c = (*(float *)(iVar2 + 0x24) + *(float *)(iVar2 + 0x18)) * DAT_00a0f298;

  fStack_58 = (*(float *)(iVar2 + 0x28) + *(float *)(iVar2 + 0x1c)) * DAT_00a0f298;

  uStack_54 = 0;

  FUN_0076f240(&fStack_60);

  fStack_20 = fStack_20 + fStack_60;

  fStack_1c = fStack_1c + fStack_5c;

  fStack_18 = fStack_18 + fStack_58;

  fVar8 = *(float *)(iVar2 + 0x20) - *(float *)(iVar2 + 0x14);

  fVar6 = *(float *)(iVar2 + 0x28) - *(float *)(iVar2 + 0x1c);

  fVar7 = *(float *)(iVar2 + 0x24) - *(float *)(iVar2 + 0x18);

  afStack_50[0] = afStack_50[0] * fVar8;

  afStack_50[1] = afStack_50[1] * fVar8;

  afStack_50[2] = afStack_50[2] * fVar8;

  fStack_40 = fStack_40 * fVar7;

  fStack_3c = fStack_3c * fVar7;

  fStack_38 = fStack_38 * fVar7;

  fStack_30 = fStack_30 * fVar6;

  fStack_2c = fStack_2c * fVar6;

  fStack_28 = fStack_28 * fVar6;

  iVar2 = (**(code **)(*piVar1 + 0xc))();

  if ((*(uint *)(iVar2 + 0xbc) >> 2 & 1) == 0) {

    iVar2 = iVar2 + 0xa8;

  }

  else {

    iVar2 = FUN_00972b20();

  }

  FUN_00752df0(*(uint32_t /* width from decompiler */ *)(param_2 + 4),afStack_50,1,iVar2,0,0);

  return;

}
