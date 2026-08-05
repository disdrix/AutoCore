// =============================================================================
// FUN_00714310
// -----------------------------------------------------------------------------
// Stable ID: aa_00714310
// Address:   0x00714310  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00714310 @ 0x00714310
// Stable ID: aa_00714310
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00714310.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint FUN_00714310(uint *param_1,uint32_t /* width from decompiler */ param_2)



{

  uint uVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  puVar2 = (uint32_t /* width from decompiler */ *)(*(code *)PTR_calloc_00af8a48)(1,0xc);

  *param_1 = (uint)puVar2;

  if (puVar2 == (uint32_t /* width from decompiler */ *)0x0) {

    return 1;

  }

  *puVar2 = 0;

  uVar1 = *param_1;

  *(uint32_t /* width from decompiler */ *)(uVar1 + 4) = 0;

  *(uint32_t /* width from decompiler */ *)(*param_1 + 8) = param_2;

  return uVar1 & 0xffff0000;

}
