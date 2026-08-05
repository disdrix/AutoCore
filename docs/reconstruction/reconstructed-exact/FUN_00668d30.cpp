// =============================================================================
// FUN_00668d30
// -----------------------------------------------------------------------------
// Stable ID: aa_00668d30
// Address:   0x00668d30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00668d30 @ 0x00668d30
// Stable ID: aa_00668d30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_005eb040×2, FUN_005d68f0, FUN_005d69a0, FUN_005d6ae0, FUN_0063a190, FUN_00668d30.
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

void __thiscall FUN_00668d30(int param_1,int *param_2)



{

  short *psVar1;

  int iVar2;

  int iVar3;

  float10 fVar4;

  float local_70;

  float local_6c;

  float local_68;

  float local_64;

  uint8_t local_60 [16];

  uint8_t local_50 [48];

  float local_20;

  float local_1c;

  float local_18;

  float local_14;

  

  FUN_005eb040(param_2 + 8);

  FUN_005eb040(param_2 + 0x18);

  iVar2 = param_2[4];

  *(int *)(param_1 + 0x20) = iVar2;

  psVar1 = (short *)(iVar2 + 6);

  *psVar1 = *psVar1 + 1;

  *(char *)(param_1 + 0xe0) = (char)param_2[3];

  *(int *)(param_1 + 0x28) = param_2[5];

  iVar2 = *(int *)(*param_2 + 0x3c);

  iVar3 = *(int *)(param_2[1] + 0x3c);

  FUN_0063a190(iVar3 + 0x80,param_1 + 0x70);

  FUN_005d6ae0(iVar3 + 0x80,param_1 + 0xa0);

  local_20 = *(float *)(iVar3 + 0xb0) + local_70;

  local_1c = *(float *)(iVar3 + 0xb4) + local_6c;

  local_18 = *(float *)(iVar3 + 0xb8) + local_68;

  local_14 = *(float *)(iVar3 + 0xbc) + local_64;

  FUN_005d68f0(iVar2 + 0x80,param_1 + 0x60);

  FUN_005d69a0(local_50,local_60);

  fVar4 = (float10)(**(code **)(**(int **)(param_1 + 0x20) + 0x18))(0,local_60,local_60);

  *(float *)(param_1 + 0x24) = (float)fVar4;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc0) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x30);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc4) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x34);

  *(uint32_t /* width from decompiler */ *)(param_1 + 200) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x38);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xcc) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xd0) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x50);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xd4) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x54);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xd8) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x58);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xdc) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x5c);

  return;

}
