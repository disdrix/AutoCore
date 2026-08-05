// =============================================================================
// FUN_00663fc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00663fc0
// Address:   0x00663fc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00663fc0 @ 0x00663fc0
// Stable ID: aa_00663fc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_005d68f0×2, FUN_005d6ae0, FUN_00662140, FUN_00662230, FUN_00662280, FUN_00662510, FUN_00663fc0, FUN_0066dd00.
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

void __thiscall FUN_00663fc0(float *param_1,int param_2,int *param_3,uint32_t /* width from decompiler */ param_4)



{

  float *pfVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  float unaff_EBX;

  float unaff_ESI;

  float unaff_EDI;

  float fVar4;

  float fStack_c4;

  float fStack_c0;

  float fStack_bc;

  float fStack_b8;

  float fStack_b4;

  float fStack_b0;

  float fStack_ac;

  float fStack_a8;

  float fStack_a4;

  uint8_t local_90 [64];

  uint8_t local_50 [76];

  

  FUN_0066dd00(param_3);

  FUN_00662510(param_2,local_90,local_50);

  pfVar1 = param_1 + 0x14;

  FUN_005d68f0(local_90,param_2 + 0x50);

  FUN_005d68f0(local_50,param_2 + 0x20);

  FUN_00662280(param_4);

  FUN_00662230(param_4);

  (**(code **)(*param_3 + 0x1c))(param_1 + 0x10,pfVar1,0xffff0000,param_4);

  FUN_005d6ae0(param_1 + 0x24,param_2 + 0x60);

  fVar4 = *param_1 * DAT_00a0f298;

  fStack_b0 = *pfVar1 + unaff_EDI * fVar4;

  fStack_ac = param_1[0x15] + unaff_ESI * fVar4;

  fStack_a8 = param_1[0x16] + unaff_EBX * fVar4;

  fStack_a4 = param_1[0x17] + fStack_c4 * fVar4;

  fVar4 = *param_1 * DAT_00aaa6cc;

  fStack_c0 = *pfVar1 + fVar4 * unaff_EDI;

  fStack_bc = param_1[0x15] + unaff_ESI * fVar4;

  fStack_b8 = param_1[0x16] + unaff_EBX * fVar4;

  iVar2 = *param_3;

  fStack_b4 = param_1[0x17] + fStack_c4 * fVar4;

  uVar3 = FUN_00662140(0,0x3f000000,0x3f800000,0x3f800000,param_4);

  (**(code **)(iVar2 + 0x1c))(&fStack_c0,&fStack_b0,uVar3);

  return;

}
