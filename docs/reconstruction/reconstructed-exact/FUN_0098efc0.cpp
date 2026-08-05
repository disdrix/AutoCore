// =============================================================================
// FUN_0098efc0
// -----------------------------------------------------------------------------
// Stable ID: aa_0098efc0
// Address:   0x0098efc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0098efc0 @ 0x0098efc0
// Stable ID: aa_0098efc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~70 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_0046c300, FUN_0046c380, FUN_0046c680, FUN_0076f5f0, FUN_0098efc0.
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

int __thiscall FUN_0098efc0(uint param_1,int param_2)



{

  float *pfVar1;

  uint in_EAX;

  int *piVar2;

  int iVar3;

  uint uVar4;

  int local_40;

  int local_3c;

  uint local_38;

  uint local_34;

  float local_30;

  float local_2c;

  float local_28;

  float local_24;

  float local_20;

  float local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  uVar4 = param_1;

  local_34 = in_EAX;

  if ((int)in_EAX < (int)param_1) {

    uVar4 = in_EAX;

    local_34 = param_1;

  }

  local_38 = uVar4;

  local_40 = FUN_0046c680();

  if ((local_40 == *(int *)(param_2 + 0x28)) ||

     ((int)(uVar4 << 0x10 | local_34) <

      (int)(*(int *)(local_40 + 0xc) << 0x10 | *(uint *)(local_40 + 0x10)))) {

    local_3c = *(int *)(param_2 + 0x28);

    piVar2 = &local_3c;

  }

  else {

    piVar2 = &local_40;

  }

  if (*piVar2 != *(int *)(param_2 + 0x28)) {

    return *(int *)(*piVar2 + 0x14);

  }

  iVar3 = *(int *)(param_2 + 8);

  pfVar1 = (float *)(iVar3 + in_EAX * 0x24);

  local_30 = *(float *)(iVar3 + param_1 * 0x24) + *pfVar1;

  iVar3 = iVar3 + param_1 * 0x24;

  local_2c = *(float *)(iVar3 + 4) + pfVar1[1];

  local_28 = *(float *)(iVar3 + 8) + pfVar1[2];

  FUN_0076f5f0(&local_30,&local_30);

  if (*(int *)(param_2 + 8) == 0) {

    iVar3 = 0;

  }

  else {

    iVar3 = (*(int *)(param_2 + 0xc) - *(int *)(param_2 + 8)) / 0x24;

  }

  local_24 = local_30;

  local_20 = local_2c;

  local_1c = local_28;

  local_18 = DAT_00d1a6c0;

  local_14 = DAT_00d1a6c4;

  local_10 = DAT_00d1a6c8;

  local_c = DAT_00afdf0c;

  local_8 = 0;

  local_4 = 0;

  FUN_0046c300();

  piVar2 = (int *)FUN_0046c380();

  *piVar2 = iVar3;

  return iVar3;

}
