// =============================================================================
// Named_CalleeOf_Named_assPreloader_0043e970
// -----------------------------------------------------------------------------
// Stable ID: aa_0043e970
// Callee of Named_assPreloader
// Address:   0x0043e970  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_assPreloader: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_0043e970, FUN_0043ea60, FUN_0043ece0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_assPreloader
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

void Named_CalleeOf_Named_assPreloader_0043e970(void)



{

  int in_EAX;

  void *pvVar1;

  uint uVar2;

  

  if (((*(int *)(in_EAX + 0xc) + *(int *)(in_EAX + 0x10) & 1U) == 0) &&

     (*(uint *)(in_EAX + 8) <= *(int *)(in_EAX + 0x10) + 2U >> 1)) {

    FUN_0043ea60(1);

  }

  uVar2 = (uint)(*(int *)(in_EAX + 0xc) + *(int *)(in_EAX + 0x10)) >> 1;

  if (*(uint *)(in_EAX + 8) <= uVar2) {

    uVar2 = uVar2 - *(uint *)(in_EAX + 8);

  }

  if (*(int *)(*(int *)(in_EAX + 4) + uVar2 * 4) == 0) {

    pvVar1 = operator_new(0x10);

    *(void **)(*(int *)(in_EAX + 4) + uVar2 * 4) = pvVar1;

  }

  FUN_0043ece0();

  *(int *)(in_EAX + 0x10) = *(int *)(in_EAX + 0x10) + 1;

  return;

}
