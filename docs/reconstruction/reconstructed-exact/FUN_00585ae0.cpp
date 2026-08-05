// =============================================================================
// FUN_00585ae0
// -----------------------------------------------------------------------------
// Stable ID: aa_00585ae0
// Address:   0x00585ae0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00585ae0 @ 0x00585ae0
// Stable ID: aa_00585ae0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: CONCAT11, CONCAT12, CONCAT31, FUN_005843b0, FUN_00585ae0.
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

void FUN_00585ae0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

                 uint32_t /* width from decompiler */ param_5,uint32_t /* width from decompiler */ param_6,uint32_t /* width from decompiler */ param_7)



{

  uint8_t local_8;

  uint8_t local_7;

  uint8_t local_6;

  uint8_t local_4;

  uint8_t local_3;

  uint8_t local_2;

  

  local_4 = (uint8_t)((uint)param_4 >> 0x10);

  local_3 = (uint8_t)((uint)param_4 >> 8);

  local_2 = (uint8_t)param_4;

  local_7 = (uint8_t)((uint)param_5 >> 8);

  local_6 = (uint8_t)param_5;

  local_8 = (uint8_t)((uint)param_5 >> 0x10);

  param_4 = CONCAT31(CONCAT12(param_4._3_1_,CONCAT11((char)param_6,(char)((uint)param_6 >> 8))),

                     (char)((uint)param_6 >> 0x10));

  FUN_005843b0(param_1,param_2,param_3,&local_4,&local_8,&param_4,param_7);

  return;

}
