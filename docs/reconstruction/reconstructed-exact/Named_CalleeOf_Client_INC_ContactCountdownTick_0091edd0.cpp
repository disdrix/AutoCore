// =============================================================================
// Named_CalleeOf_Client_INC_ContactCountdownTick_0091edd0
// -----------------------------------------------------------------------------
// Stable ID: aa_0091edd0
// Callee of Client_INC_ContactCountdownTick
// Address:   0x0091edd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_INC_ContactCountdownTick: callee helper. Evidence string: "Contact Interrupted!". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "Contact Interrupted!"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_007a69d0, FUN_007a6de0, FUN_007fb640, FUN_008f8200, FUN_0091edd0.
//  - Strings: "Contact Interrupted!".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_INC_ContactCountdownTick
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

void Named_CalleeOf_Client_INC_ContactCountdownTick_0091edd0(int param_1)



{

  char *pcVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  uVar2 = 0xffffffff;

  pcVar1 = "Contact Interrupted!";

  FUN_007a69d0("Contact Interrupted!",0xffffffff);

  uVar2 = FUN_007a6de0(pcVar1,uVar2);

  if (DAT_00d1b8dc != 0) {

    FUN_008f8200(DAT_00d1b8dc,0x18,&DAT_00a156cc,uVar2,0);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc24) = 0;

  FUN_007fb640();

  return;

}
