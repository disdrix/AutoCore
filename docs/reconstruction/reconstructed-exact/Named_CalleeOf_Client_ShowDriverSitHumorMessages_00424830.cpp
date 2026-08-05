// =============================================================================
// Named_CalleeOf_Client_ShowDriverSitHumorMessages_00424830
// -----------------------------------------------------------------------------
// Stable ID: aa_00424830
// Callee of Client_ShowDriverSitHumorMessages
// Address:   0x00424830  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_ShowDriverSitHumorMessages: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00424830, FUN_004248c0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_ShowDriverSitHumorMessages
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

uint Named_CalleeOf_Client_ShowDriverSitHumorMessages_00424830(void)



{

  int in_EAX;

  uint uVar1;

  

  if (*(int *)(in_EAX + 0x9c4) == 0) {

    FUN_004248c0();

  }

  *(int *)(in_EAX + 0x9c4) = *(int *)(in_EAX + 0x9c4) + -1;

  uVar1 = **(uint **)(in_EAX + 0x9c0);

  *(uint **)(in_EAX + 0x9c0) = *(uint **)(in_EAX + 0x9c0) + 1;

  uVar1 = uVar1 ^ uVar1 >> 0xb;

  uVar1 = uVar1 ^ (uVar1 & 0xff3a58ad) << 7;

  uVar1 = uVar1 ^ (uVar1 & 0xffffdf8c) << 0xf;

  return uVar1 >> 0x12 ^ uVar1;

}
