// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance_0083bf40
// -----------------------------------------------------------------------------
// Stable ID: aa_0083bf40
// Callee of Named_CalleeOf_Named_Client_InitInstance
// Address:   0x0083bf40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_Client_InitInstance: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: block×18, FUN_004158c0, FUN_007fc970, FUN_0083bf40.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_Client_InitInstance
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

/* WARNING: Removing unreachable block (ram,0x0083bf8e) */

/* WARNING: Removing unreachable block (ram,0x0083bfa0) */

/* WARNING: Removing unreachable block (ram,0x0083bfac) */

/* WARNING: Removing unreachable block (ram,0x0083bfb2) */

/* WARNING: Removing unreachable block (ram,0x0083bfcd) */

/* WARNING: Removing unreachable block (ram,0x0083bfde) */

/* WARNING: Removing unreachable block (ram,0x0083bff0) */

/* WARNING: Removing unreachable block (ram,0x0083c05e) */

/* WARNING: Removing unreachable block (ram,0x0083c062) */

/* WARNING: Removing unreachable block (ram,0x0083c068) */

/* WARNING: Removing unreachable block (ram,0x0083bff5) */

/* WARNING: Removing unreachable block (ram,0x0083bffc) */

/* WARNING: Removing unreachable block (ram,0x0083c0de) */

/* WARNING: Removing unreachable block (ram,0x0083c04a) */

/* WARNING: Removing unreachable block (ram,0x0083c0ea) */

/* WARNING: Removing unreachable block (ram,0x0083c078) */

/* WARNING: Removing unreachable block (ram,0x0083c0a7) */

/* WARNING: Removing unreachable block (ram,0x0083c0b1) */



void Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance_0083bf40(int param_1,int param_2)



{

  if (((*(int *)(param_1 + 0x4c0) != 0) && (*(int *)(param_1 + 0x538) != 0)) && (param_2 != 0)) {

    FUN_004158c0();

  }

  if ((DAT_00d1d8e0 != 0) && (*(int *)(DAT_00d1d8e0 + 0x514) == param_2)) {

    FUN_007fc970();

  }

  return;

}
