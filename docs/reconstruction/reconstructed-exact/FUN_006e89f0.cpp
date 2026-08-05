// =============================================================================
// FUN_006e89f0
// -----------------------------------------------------------------------------
// Stable ID: aa_006e89f0
// Address:   0x006e89f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006e89f0 @ 0x006e89f0
// Stable ID: aa_006e89f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~58 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_006e8400×2, FUN_006e89f0.
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

void FUN_006e89f0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ *param_3,uint32_t /* width from decompiler */ param_4,

                 int param_5)



{

  uint32_t /* width from decompiler */ local_a0;

  uint32_t /* width from decompiler */ local_9c;

  uint32_t /* width from decompiler */ local_98;

  uint32_t /* width from decompiler */ local_94;

  float local_90;

  float local_8c;

  float local_88;

  float local_84;

  uint32_t /* width from decompiler */ local_80;

  uint32_t /* width from decompiler */ local_7c;

  undefined **local_70;

  uint32_t /* width from decompiler */ local_6c;

  uint32_t /* width from decompiler */ local_60;

  uint32_t /* width from decompiler */ local_5c;

  uint32_t /* width from decompiler */ local_58;

  uint32_t /* width from decompiler */ local_54;

  uint32_t /* width from decompiler */ local_50;

  undefined **local_40;

  uint32_t /* width from decompiler */ local_3c;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  int local_20;

  

  local_a0 = *param_3;

  local_90 = -(float)param_3[4];

  local_9c = param_3[1];

  local_8c = -(float)param_3[5];

  local_98 = param_3[2];

  local_94 = param_3[3];

  local_88 = -(float)param_3[6];

  local_7c = param_3[9];

  local_60 = param_3[4];

  local_84 = -(float)param_3[7];

  local_5c = param_3[5];

  local_58 = param_3[6];

  local_54 = param_3[7];

  local_80 = param_3[8];

  local_50 = param_4;

  local_6c = 0x7f7fffff;

  local_70 = &PTR_LAB_00a0e334;

  if (param_5 != 0) {

    local_40 = &PTR_LAB_00a0e334;

    local_30 = param_3[4];

    local_2c = param_3[5];

    local_28 = param_3[6];

    local_24 = param_3[7];

    local_20 = param_5;

    local_3c = 0x7f7fffff;

    FUN_006e8400(param_2,param_1,&local_a0,&local_70,&local_40);

    return;

  }

  FUN_006e8400(param_2,param_1,&local_a0,&local_70,0);

  return;

}
