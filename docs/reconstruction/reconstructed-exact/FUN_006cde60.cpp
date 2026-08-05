// =============================================================================
// FUN_006cde60
// -----------------------------------------------------------------------------
// Stable ID: aa_006cde60
// Address:   0x006cde60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006cde60 @ 0x006cde60
// Stable ID: aa_006cde60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~52 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_006cde60.
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

float10 __thiscall FUN_006cde60(int *param_1,float *param_2)



{

  float fStack_7c;

  float fStack_78;

  float fStack_74;

  uint8_t local_70 [4];

  float fStack_6c;

  float fStack_68;

  float fStack_64;

  uint32_t /* width from decompiler */ local_50;

  uint32_t /* width from decompiler */ local_4c;

  uint32_t /* width from decompiler */ local_48;

  uint32_t /* width from decompiler */ local_44;

  uint32_t /* width from decompiler */ local_40;

  uint32_t /* width from decompiler */ local_3c;

  uint32_t /* width from decompiler */ local_38;

  uint32_t /* width from decompiler */ local_34;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  

  local_44 = 0;

  local_48 = 0;

  local_4c = 0;

  local_34 = 0;

  local_38 = 0;

  local_40 = 0;

  local_24 = 0;

  local_2c = 0;

  local_30 = 0;

  local_50 = 0x3f800000;

  local_3c = 0x3f800000;

  local_28 = 0x3f800000;

  local_14 = 0;

  local_18 = 0;

  local_1c = 0;

  local_20 = 0;

  (**(code **)(*param_1 + 0x18))(&local_50,0,local_70);

  return ((float10)(fStack_74 + fStack_64) * (float10)DAT_00a0f298 +

         (float10)(float)((uint)((fStack_64 - fStack_74) * DAT_00a0f298) ^

                         (uint)param_2[2] & 0x80000000)) * (float10)param_2[2] +

         (float10)((fStack_7c + fStack_6c) * DAT_00a0f298 +

                  (float)((uint)((fStack_6c - fStack_7c) * DAT_00a0f298) ^

                         (uint)*param_2 & 0x80000000)) * (float10)*param_2 +

         (float10)((fStack_78 + fStack_68) * DAT_00a0f298 +

                  (float)((uint)((fStack_68 - fStack_78) * DAT_00a0f298) ^

                         (uint)param_2[1] & 0x80000000)) * (float10)param_2[1];

}
