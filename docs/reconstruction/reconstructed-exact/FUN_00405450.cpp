// =============================================================================
// FUN_00405450
// -----------------------------------------------------------------------------
// Stable ID: aa_00405450
// Address:   0x00405450  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00405450 @ 0x00405450
// Stable ID: aa_00405450
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00405450, FUN_00405490.
//  - Return sites: 1.

// READABILITY:
// Control-flow (from raw @ 0x00405450; evidence only — no invented semantics):
//  - Entry: `void __fastcall FUN_00405450(undefined4 param_1)`.
//  - Calls: FUN_00405490(param_1).
//  - Returns (1 site(s)): `void`.
//  - Assign `local_c = ExceptionList`.
//  - Assign `local_4 = 0xffffffff`.




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

void __fastcall FUN_00405450(uint32_t /* width from decompiler */ param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009bc168;

  local_c = ExceptionList;

  local_4 = 0xffffffff;

  ExceptionList = &local_c;

  FUN_00405490(param_1);

  ExceptionList = local_c;

  return;

}
