// =============================================================================
// FUN_007113d0
// -----------------------------------------------------------------------------
// Stable ID: aa_007113d0
// Address:   0x007113d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007113d0 @ 0x007113d0
// Stable ID: aa_007113d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~55 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1.
//  - Notable callees: FUN_00710fe0, FUN_007113d0, FUN_007116e0, FUN_00711790, FUN_00711840, FUN_00711c50, FUN_00713550, FUN_007137d0.
//  - Return sites: 2.

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

uint FUN_007113d0(short *param_1,uint32_t /* width from decompiler */ *param_2,int param_3)



{

  uint32_t /* width from decompiler */ uVar1;

  float *pfVar2;

  int iVar3;

  float10 fVar4;

  float local_c2c;

  uint32_t /* width from decompiler */ local_c28;

  uint32_t /* width from decompiler */ local_c24;

  uint32_t /* width from decompiler */ local_c20;

  uint32_t /* width from decompiler */ local_c1c;

  uint32_t /* width from decompiler */ local_c18;

  uint32_t /* width from decompiler */ local_c14;

  float local_c10 [257];

  uint8_t local_80c [2060];

  

  local_c18 = param_2[0x12];

  uVar1 = *param_2;

  local_c28 = 0;

  local_c20 = 0;

  if ((param_2[10] & param_2[8]) == 0) {

    return 1;

  }

  iVar3 = 0xa0;

  pfVar2 = local_c10;

  do {

    local_c2c = (float)(int)*param_1;

    param_1 = param_1 + 1;

    iVar3 = iVar3 + -1;

    *pfVar2 = (float)(int)local_c2c;

    pfVar2 = pfVar2 + 1;

  } while (iVar3 != 0);

  FUN_007137d0(uVar1,0,0xa0,local_c10);

  fVar4 = (float10)FUN_007116e0(uVar1,param_2[4],param_2 + 0xb);

  local_c2c = (float)fVar4;

  *(float *)(param_3 + 8) = (float)fVar4;

  FUN_00711790(local_c2c,param_2[6],uVar1,local_80c,local_c10,&local_c1c,&local_c20);

  FUN_00711840(uVar1,local_80c,local_c10,param_3,param_2,local_c1c,local_c20,&local_c28,&local_c14);

  FUN_00713550(param_2,param_3,0xe1,(int)*(short *)(param_2 + 10),local_c14,local_c28);

  param_2[0xd] = *(uint32_t /* width from decompiler */ *)(param_3 + 8);

  uVar1 = *(uint32_t /* width from decompiler */ *)(param_3 + 0xc);

  param_2[9] = param_2[10];

  param_2[0xc] = uVar1;

  if (param_2[0x13] != 0) {

    FUN_00710fe0(param_2[0x13],param_2[0xb],*(uint32_t /* width from decompiler */ *)(param_3 + 0xc));

  }

  local_c2c = 0.0;

  if (param_2[0x11] != 0) {

    local_c2c = *(float *)(param_3 + 0xc);

    local_c24 = *(uint32_t /* width from decompiler */ *)(param_3 + 8);

    FUN_00711c50(local_c18,&local_c2c,&local_c24);

    *(uint32_t /* width from decompiler */ *)(param_3 + 8) = local_c24;

    *(float *)(param_3 + 0xc) = local_c2c;

  }

  return (uint)local_c2c & 0xffff0000;

}
