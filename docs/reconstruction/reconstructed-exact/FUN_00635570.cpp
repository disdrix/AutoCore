// =============================================================================
// FUN_00635570
// -----------------------------------------------------------------------------
// Stable ID: aa_00635570
// Address:   0x00635570  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00635570 @ 0x00635570
// Stable ID: aa_00635570
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_005d68f0×2, FUN_00635570, FUN_006c2f30, FUN_006c2fb0, FUN_006c35e0, SQRT.
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

void __thiscall FUN_00635570(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  int iVar1;

  float fVar2;

  float local_40;

  float local_3c;

  float local_38;

  float local_34;

  float local_30;

  float local_2c;

  float local_28;

  float local_24;

  float local_20;

  float local_1c;

  float local_18;

  float local_14;

  

  FUN_006c2fb0(param_2,param_3,param_1 + 0x44,8);

  iVar1 = *(int *)(param_1 + 0x10);

  FUN_005d68f0(*(int *)(*(int *)(param_1 + 0xc) + 0x3c) + 0x80,param_1 + 0x20);

  FUN_005d68f0(*(int *)(iVar1 + 0x3c) + 0x80,param_1 + 0x30);

  local_38 = local_38 - local_28;

  local_3c = local_3c - local_2c;

  local_40 = local_40 - local_30;

  fVar2 = SQRT(local_40 * local_40 + local_3c * local_3c + local_38 * local_38);

  local_14 = g_flOne / fVar2;

  local_20 = local_14 * local_40;

  local_1c = local_3c * local_14;

  local_18 = local_38 * local_14;

  local_14 = (local_34 - local_24) * local_14;

  FUN_006c35e0(&local_40,param_2,param_3);

  FUN_006c2f30(*(float *)(param_1 + 0x40) - fVar2,param_2,param_3,1);

  return;

}
