// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_gfxDevice_00757ff0
// -----------------------------------------------------------------------------
// Stable ID: aa_00757ff0
// Callee of Named_CalleeOf_Named_gfxDevice
// Address:   0x00757ff0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_gfxDevice: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~184 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_00440450×4, FUN_00440560×4, FUN_00757050×4, FUN_004148e0, FUN_00440230, FUN_00757ff0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_gfxDevice
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __fastcall

Named_CalleeOf_Named_CalleeOf_Named_gfxDevice_00757ff0(int *param_1,uint32_t /* width from decompiler */ param_2,int param_3,int *param_4,uint32_t /* width from decompiler */ param_5,

            uint32_t /* width from decompiler */ param_6)



{

  int iVar1;

  bool bVar2;

  float fVar3;

  uint32_t /* width from decompiler */ local_98;

  uint8_t local_94;

  uint8_t local_93;

  uint8_t local_92;

  uint32_t /* width from decompiler */ local_90;

  uint32_t /* width from decompiler */ local_8c;

  float local_88;

  float local_84;

  float local_80;

  uint32_t /* width from decompiler */ local_78;

  uint32_t /* width from decompiler */ local_74;

  uint32_t /* width from decompiler */ local_70;

  float local_6c;

  float local_68;

  uint32_t /* width from decompiler */ local_60;

  uint32_t /* width from decompiler */ local_5c;

  uint32_t /* width from decompiler */ local_58;

  float local_54;

  float local_50;

  uint32_t /* width from decompiler */ local_48;

  uint32_t /* width from decompiler */ local_44;

  uint32_t /* width from decompiler */ local_40;

  float local_3c;

  float local_38;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  float local_24;

  float local_20;

  float local_1c;

  float local_18;

  float local_14;

  float local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009b1c0f;

  local_c = ExceptionList;

  bVar2 = (byte)((byte)((uint)param_5 >> 0x18) & (byte)((uint)param_6 >> 0x18)) == 0xff;

  local_98 = 0;

  local_94 = 0;

  local_93 = 0;

  local_92 = 0;

  local_90 = 0;

  local_8c = 0;

  local_4 = 0;

  ExceptionList = &local_c;

  FUN_004148e0(param_2);

  fVar3 = (float)param_4[3];

  local_84 = (float)*param_4;

  local_80 = (float)param_4[1];

  local_6c = (float)param_4[2];

  local_3c = (float)*param_1;

  local_54 = (float)param_1[2];

  local_88 = (float)param_1[3];

  local_50 = (float)param_1[1];

  local_74 = 0;

  local_70 = 0;

  local_78 = param_5;

  local_5c = 0;

  local_58 = 0;

  local_60 = param_5;

  local_44 = 0;

  local_40 = 0;

  local_48 = param_6;

  local_2c = 0;

  local_28 = 0;

  local_30 = param_6;

  local_38 = local_50;

  local_24 = local_3c;

  local_20 = local_84;

  local_1c = local_54;

  local_18 = local_80;

  local_14 = local_6c;

  local_10 = local_50;

  if (bVar2) {

    iVar1 = param_3 + 4;

    local_68 = local_80;

  }

  else {

    local_68 = local_80;

    iVar1 = FUN_00440560(param_3 + 0x68);

  }

  FUN_00440450(iVar1);

  FUN_00757050(param_3,4);

  local_84 = local_20;

  local_80 = local_18;

  local_6c = local_24;

  local_54 = local_24;

  local_3c = local_20;

  local_74 = 0;

  local_70 = 0;

  local_78 = param_5;

  local_68 = local_10;

  local_5c = 0;

  local_58 = 0;

  local_60 = param_6;

  local_50 = local_88;

  local_44 = 0;

  local_40 = 0;

  local_48 = param_6;

  local_2c = 0;

  local_28 = 0;

  local_30 = param_5;

  if (bVar2) {

    iVar1 = param_3 + 4;

    local_38 = fVar3;

  }

  else {

    local_38 = fVar3;

    iVar1 = FUN_00440560(param_3 + 0x68);

  }

  FUN_00440450(iVar1);

  FUN_00757050(param_3,4);

  local_6c = local_14;

  local_54 = local_14;

  local_80 = local_10;

  local_84 = local_1c;

  local_74 = 0;

  local_70 = 0;

  local_78 = param_6;

  local_68 = local_18;

  local_5c = 0;

  local_58 = 0;

  local_60 = param_5;

  local_44 = 0;

  local_40 = 0;

  local_48 = param_5;

  local_3c = local_1c;

  local_38 = local_88;

  local_2c = 0;

  local_28 = 0;

  local_30 = param_6;

  local_50 = fVar3;

  if (bVar2) {

    iVar1 = param_3 + 4;

  }

  else {

    iVar1 = FUN_00440560(param_3 + 0x68);

  }

  FUN_00440450(iVar1);

  FUN_00757050(param_3,4);

  local_80 = local_88;

  local_68 = local_88;

  local_84 = local_24;

  local_6c = local_1c;

  local_54 = local_14;

  local_74 = 0;

  local_70 = 0;

  local_78 = param_6;

  local_5c = 0;

  local_58 = 0;

  local_60 = param_6;

  local_44 = 0;

  local_40 = 0;

  local_48 = param_5;

  local_3c = local_20;

  local_2c = 0;

  local_28 = 0;

  local_30 = param_5;

  if (bVar2) {

    iVar1 = param_3 + 4;

    local_50 = fVar3;

    local_38 = fVar3;

  }

  else {

    local_50 = fVar3;

    local_38 = fVar3;

    iVar1 = FUN_00440560(param_3 + 0x68);

  }

  FUN_00440450(iVar1);

  FUN_00757050(param_3,4);

  local_4 = 0xffffffff;

  FUN_00440230(&local_98);

  ExceptionList = local_c;

  return 0;

}
