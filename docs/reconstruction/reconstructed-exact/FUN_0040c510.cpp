// =============================================================================
// FUN_0040c510
// -----------------------------------------------------------------------------
// Stable ID: aa_0040c510
// Address:   0x0040c510  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0040c510 @ 0x0040c510
// Stable ID: aa_0040c510
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0040c510.
//  - Return sites: 1.

// READABILITY:
// Control-flow (from raw @ 0x0040c510; evidence only — no invented semantics):
//  - Entry: `void __fastcall FUN_0040c510(undefined4 *param_1)`.
//  - Branches: if (-1 < param_1[6]).
//  - Writes: *param_1 = &PTR_LAB_00a2f538; *param_1 = &PTR_LAB_00a2f52c.
//  - Returns (1 site(s)): `void`.




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

void __fastcall FUN_0040c510(uint32_t /* width from decompiler */ *param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009bc4ed;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_1 = &PTR_LAB_00a2f538;

  local_4 = 0;

  if (-1 < (int)param_1[6]) {

    (**(code **)(*DAT_00b05060 + 0x14))(param_1[4],(param_1[6] & 0x7fffffff) * 0x30,0x12);

  }

  *param_1 = &PTR_LAB_00a2f52c;

  ExceptionList = local_c;

  return;

}
