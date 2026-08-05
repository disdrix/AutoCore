// =============================================================================
// Named_CalleeOf_Named_assPackManager_0076ad70
// -----------------------------------------------------------------------------
// Stable ID: aa_0076ad70
// Callee of Named_assPackManager
// Address:   0x0076ad70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_assPackManager: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~8 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0076ad70, stat.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_assPackManager
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

uint __fastcall Named_CalleeOf_Named_assPackManager_0076ad70(uint32_t /* width from decompiler */ param_1)



{

  int iVar1;

  uint8_t local_24 [28];

  uint local_8;

  

  iVar1 = stat(param_1,local_24);

  return ~-(uint)(iVar1 != 0) & local_8;

}
