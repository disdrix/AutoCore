// =============================================================================
// Named_CalleeOf_CVOGCharacter_ApplyCreateFromPacket_00571d30
// -----------------------------------------------------------------------------
// Stable ID: aa_00571d30
// Callee of CVOGCharacter_ApplyCreateFromPacket
// Address:   0x00571d30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGCharacter_ApplyCreateFromPacket: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00571620, FUN_00571d30.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of CVOGCharacter_ApplyCreateFromPacket
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

uint Named_CalleeOf_CVOGCharacter_ApplyCreateFromPacket_00571d30(int *param_1)



{

  uint in_EAX;

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint uVar4;

  

  if (param_1 == (int *)0x0) {

    return in_EAX & 0xffffff00;

  }

  uVar1 = (**(code **)(*param_1 + 0x25c))();

  uVar2 = (**(code **)(*param_1 + 0x254))(uVar1);

  uVar3 = (**(code **)(*param_1 + 0x250))(uVar2);

  uVar4 = FUN_00571620(param_1,uVar3,uVar2,uVar1);

  return uVar4;

}
