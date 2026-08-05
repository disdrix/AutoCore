// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_gfxDeviceVB_00997a10
// -----------------------------------------------------------------------------
// Stable ID: aa_00997a10
// Callee of Named_CalleeOf_Named_gfxDeviceVB
// Address:   0x00997a10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_gfxDeviceVB: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00456780×2, FUN_00437b60, FUN_00447ea0, FUN_00748430, FUN_00997a10.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_gfxDeviceVB
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

int __fastcall Named_CalleeOf_Named_CalleeOf_Named_gfxDeviceVB_00997a10(int param_1)



{

  int in_EAX;

  

  FUN_00748430(in_EAX);

  FUN_00437b60();

  FUN_00447ea0();

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xd4) = *(uint32_t /* width from decompiler */ *)(in_EAX + 0xd4);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xd8) = *(uint32_t /* width from decompiler */ *)(in_EAX + 0xd8);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x60) = 0xffffffff;

  FUN_00456780(0);

  FUN_00456780(0);

  return param_1;

}
