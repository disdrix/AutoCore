// =============================================================================
// Named_CalleeOf_Drive_driver_004b6850
// -----------------------------------------------------------------------------
// Stable ID: aa_004b6850
// Callee of Drive_driver
// Address:   0x004b6850  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Drive_driver: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: return×3, switch×1.
//  - Notable callees: FUN_004b6850.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Drive_driver
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

void __thiscall Named_CalleeOf_Drive_driver_004b6850(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  switch(*param_2) {

  case 0:

  case 9:

  case 10:

  case 0xb:

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x230) = 0;

    return;

  default:

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x230) = 2;

    return;

  case 2:

  case 0xc:

  case 0xd:

  case 0xf:

  case 0x16:

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x230) = 1;

    return;

  }

}
