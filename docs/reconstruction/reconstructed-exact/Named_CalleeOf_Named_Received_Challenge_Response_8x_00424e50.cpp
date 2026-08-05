// =============================================================================
// Named_CalleeOf_Named_Received_Challenge_Response_8x_00424e50
// -----------------------------------------------------------------------------
// Stable ID: aa_00424e50
// Callee of Named_Received_Challenge_Response_8x (+1 other named callers)
// Address:   0x00424e50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Received_Challenge_Response_8x: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_Received_Challenge_Response_8x (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: CONCAT31, FUN_00424e50.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_Received_Challenge_Response_8x (+1 other named callers)
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

uint __fastcall Named_CalleeOf_Named_Received_Challenge_Response_8x_00424e50(int param_1)



{

  byte bVar1;

  uint uVar2;

  uint in_EAX;

  

  uVar2 = *(uint *)(param_1 + 0x18);

  if (*(uint *)(param_1 + 0x2c) < uVar2) {

    *(uint8_t *)(param_1 + 0x1c) = 1;

    return in_EAX & 0xffffff00;

  }

  bVar1 = *(byte *)((uVar2 >> 3) + *(int *)(param_1 + 0xc));

  *(uint *)(param_1 + 0x18) = uVar2 + 1;

  return CONCAT31((uint3)(uVar2 >> 0xb),(bVar1 & (byte)(1 << ((byte)uVar2 & 7))) != 0);

}
