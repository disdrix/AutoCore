// =============================================================================
// FUN_00411b70
// -----------------------------------------------------------------------------
// Stable ID: aa_00411b70
// Address:   0x00411b70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00411b70 @ 0x00411b70
// Stable ID: aa_00411b70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00416c90×2, DeleteCriticalSection, FUN_00411b70.
//  - Return sites: 1.

// READABILITY:
// Control-flow (from raw @ 0x00411b70; evidence only — no invented semantics):
//  - Entry: `void __fastcall FUN_00411b70(undefined4 *param_1)`.
//  - Calls: FUN_00416c90().
//  - Writes: *param_1 = &PTR_FUN_00a51eec; *param_1 = &PTR_FUN_00a51ee0.
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

void __fastcall FUN_00411b70(uint32_t /* width from decompiler */ *param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009bd9a8;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_1 = &PTR_FUN_00a51eec;

  local_4 = 0;

  FUN_00416c90();

  local_4 = 0xffffffff;

  *param_1 = &PTR_FUN_00a51ee0;

  FUN_00416c90();

  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));

  ExceptionList = local_c;

  return;

}
