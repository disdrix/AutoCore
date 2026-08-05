// =============================================================================
// FUN_0072cd70
// -----------------------------------------------------------------------------
// Stable ID: aa_0072cd70
// Address:   0x0072cd70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0072cd70 @ 0x0072cd70
// Stable ID: aa_0072cd70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0043b500, FUN_0072cd70, stoChunkWriter_BeginChunk, stoChunkWriter_EndChunk.
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

uint32_t /* width from decompiler */ __fastcall FUN_0072cd70(int param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  void *local_c;

  undefined *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &DAT_009ad4ee;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  stoChunkWriter_BeginChunk(0x42564f4c,1);

  local_4 = 0;

  uVar1 = FUN_0043b500(param_1 + 4);

  local_4 = 0xffffffff;

  stoChunkWriter_EndChunk();

  ExceptionList = local_c;

  return uVar1;

}
