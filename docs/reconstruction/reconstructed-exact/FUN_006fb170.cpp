// =============================================================================
// FUN_006fb170
// -----------------------------------------------------------------------------
// Stable ID: aa_006fb170
// Address:   0x006fb170  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006fb170 @ 0x006fb170
// Stable ID: aa_006fb170
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_005d68f0, FUN_005d6a40, FUN_006fb170.
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

void __thiscall FUN_006fb170(uint16_t *param_1,int *param_2,int *param_3,uint32_t /* width from decompiler */ param_4)



{

  uint8_t uVar1;

  float fStack_80;

  float fStack_7c;

  float fStack_78;

  float fStack_74;

  float fStack_60;

  float fStack_5c;

  uint8_t auStack_58 [4];

  uint16_t uStack_54;

  float local_40;

  float fStack_3c;

  uint8_t auStack_38 [4];

  uint8_t auStack_34 [4];

  uint8_t auStack_30 [4];

  uint16_t uStack_2c;

  

  (**(code **)(*param_2 + 0x38))(&local_40);

  (**(code **)(*param_3 + 0x38))(auStack_34);

  FUN_005d68f0(param_4,auStack_38);

  fStack_80 = fStack_60 - local_40;

  fStack_7c = fStack_5c - fStack_3c;

  (**(code **)(*param_2 + 0x30))(&stack0xffffff78,auStack_58);

  *param_1 = uStack_54;

  FUN_005d6a40(param_4,&stack0xffffff70);

  fStack_80 = -fStack_80;

  fStack_7c = -fStack_7c;

  fStack_78 = -fStack_78;

  fStack_74 = -fStack_74;

  (**(code **)(*param_3 + 0x30))(&fStack_80,auStack_30);

  param_1[1] = uStack_2c;

  param_1[2] = 0xffff;

  param_1[3] = 0xffff;

  *(uint8_t *)(param_1 + 4) = 1;

  *(uint8_t *)((int)param_1 + 9) = 1;

  uVar1 = (**(code **)(*param_2 + 0x3c))();

  *(uint8_t *)(param_1 + 5) = uVar1;

  uVar1 = (**(code **)(*param_3 + 0x3c))();

  *(uint8_t *)((int)param_1 + 0xb) = uVar1;

  return;

}
