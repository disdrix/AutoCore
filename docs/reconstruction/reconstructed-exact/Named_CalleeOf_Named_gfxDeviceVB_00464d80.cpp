// =============================================================================
// Named_CalleeOf_Named_gfxDeviceVB_00464d80
// -----------------------------------------------------------------------------
// Stable ID: aa_00464d80
// Callee of Named_gfxDeviceVB
// Address:   0x00464d80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxDeviceVB: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: FUN_00464ac0, FUN_00464d80, FUN_0096b280.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_gfxDeviceVB
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

void Named_CalleeOf_Named_gfxDeviceVB_00464d80(void)



{

  int iVar1;

  int in_EAX;

  int iVar2;

  

  FUN_0096b280(*(uint32_t /* width from decompiler */ *)(in_EAX + 0x5c));

  iVar1 = *(int *)(in_EAX + 0xf4);

  for (iVar2 = *(int *)(in_EAX + 0xf0); iVar2 != iVar1; iVar2 = iVar2 + 4) {

    FUN_00464ac0();

  }

  return;

}
