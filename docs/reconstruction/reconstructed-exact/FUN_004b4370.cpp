// =============================================================================
// FUN_004b4370
// -----------------------------------------------------------------------------
// Stable ID: aa_004b4370
// Address:   0x004b4370  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004b4370 @ 0x004b4370
// Stable ID: aa_004b4370
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~120 non-empty decompiler lines.
//  - Control keywords: return×6, for×3, if×2, switch×1.
//  - Notable callees: CVOGReaction_RandomUnitScalar, FUN_004b4370, FUN_004b49f0.
//  - Return sites: 6.

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

int * __thiscall FUN_004b4370(int *param_1,int param_2,int param_3)



{

  ushort uVar1;

  int iVar2;

  int *piVar3;

  float fVar4;

  

  piVar3 = (int *)(param_2 + 0x14);

  *param_1 = param_2;

  param_1[1] = (int)piVar3;

  param_1[2] = 0;

  param_1[3] = (int)FUN_004b1b50;

  FUN_004b49f0(param_2 + 0x30c);

  *(uint8_t *)((int)param_1 + 0xaa) = 0xff;

  *(uint8_t *)((int)param_1 + 0xa9) = 0xff;

  *(uint8_t *)(param_1 + 0x2a) = 0xff;

  *(uint8_t *)((int)param_1 + 0xab) = 0xff;

  *(uint8_t *)((int)param_1 + 0xae) = 0xff;

  *(uint8_t *)((int)param_1 + 0xad) = 0xff;

  *(uint8_t *)(param_1 + 0x2b) = 0xff;

  *(uint8_t *)((int)param_1 + 0xaf) = 0xff;

  *(uint8_t *)((int)param_1 + 0x11e) = 0xff;

  *(uint8_t *)((int)param_1 + 0x11d) = 0xff;

  *(uint8_t *)(param_1 + 0x47) = 0xff;

  *(uint8_t *)((int)param_1 + 0x11f) = 0xff;

  *(uint8_t *)((int)param_1 + 0x122) = 0xff;

  *(uint8_t *)((int)param_1 + 0x121) = 0xff;

  *(uint8_t *)(param_1 + 0x48) = 0xff;

  *(uint8_t *)((int)param_1 + 0x123) = 0xff;

  param_1[0x5b] = *(int *)(param_2 + 0x80c);

  param_1[0x5c] = *piVar3;

  param_1[0x5d] = *piVar3;

  param_1[0x5e] = 0;

  param_1[0x5f] = 0;

  param_1[0x60] = 0;

  param_1[0x61] = 0;

  param_1[0x62] = 0;

  param_1[99] = 0;

  param_1[100] = 0;

  param_1[0x65] = 0;

  param_1[0x66] = 0;

  param_1[0x67] = 0;

  param_1[0x68] = 0;

  param_1[0x69] = 0;

  param_1[0x6a] = param_3;

  *(uint8_t *)(param_1 + 0x90) = 1;

  *(byte *)((int)param_1 + 0x241) = *(byte *)(param_2 + 0x989) >> 6 & 1;

  *(uint8_t *)((int)param_1 + 0x242) = 0;

  piVar3 = param_1 + 0x21;

  for (iVar2 = 0x1d; iVar2 != 0; iVar2 = iVar2 + -1) {

    *piVar3 = 0;

    piVar3 = piVar3 + 1;

  }

  piVar3 = param_1 + 0x3e;

  for (iVar2 = 0x1d; iVar2 != 0; iVar2 = iVar2 + -1) {

    *piVar3 = 0;

    piVar3 = piVar3 + 1;

  }

  param_1[0x6c] = 0;

  param_1[0x6d] = 0;

  param_1[0x6e] = 0;

  param_1[0x6f] = 0;

  param_1[0x70] = 0;

  param_1[0x71] = 0;

  param_1[0x72] = 0;

  param_1[0x73] = 0;

  param_1[0x74] = 0;

  piVar3 = param_1 + 0x75;

  for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {

    *piVar3 = 0;

    piVar3 = piVar3 + 1;

  }

  param_1[0x81] = 0;

  param_1[0x82] = 0;

  param_1[0x83] = 0;

  param_1[0x84] = 0;

  param_1[0x85] = 0;

  param_1[0x86] = 0;

  param_1[0x87] = 0;

  param_1[0x88] = 0;

  param_1[0x89] = 0;

  param_1[0x8a] = 0;

  param_1[0x8b] = 0;

  param_1[0x8c] = 0;

  param_1[0x8d] = 0;

  param_1[0x8e] = 0;

  param_1[0x8f] = 0;

  iVar2 = *param_1;

  if ((*(byte *)(iVar2 + 0x1f8) & 4) != 0) {

    iVar2 = CVOGReaction_RandomUnitScalar();

    if (0xfffff < *(int *)(iVar2 + 0xc)) {

      *(uint32_t /* width from decompiler */ *)(iVar2 + 0xc) = 0;

    }

    uVar1 = *(ushort *)(*(int *)(iVar2 + 8) + *(int *)(iVar2 + 0xc) * 2);

    *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 1;

    iVar2 = *param_1;

    fVar4 = (float)uVar1 * *(float *)(iVar2 + 0x18) * DAT_00aaa638 + (float)param_1[0x5c];

    param_1[0x5c] = (int)fVar4;

    param_1[0x5d] = (int)fVar4;

  }

  switch(*(uint32_t /* width from decompiler */ *)(iVar2 + 0x8d4)) {

  case 0:

    param_1[3] = (int)FUN_004b1b50;

    return param_1;

  case 1:

    param_1[3] = (int)FUN_004b1cb0;

    return param_1;

  case 2:

    param_1[3] = (int)&LAB_004b1e30;

    return param_1;

  case 3:

    param_1[3] = (int)FUN_004b2370;

    return param_1;

  case 4:

    param_1[3] = (int)FUN_004b26e0;

    return param_1;

  case 5:

    param_1[3] = (int)&DAT_004b0d50;

  }

  return param_1;

}
