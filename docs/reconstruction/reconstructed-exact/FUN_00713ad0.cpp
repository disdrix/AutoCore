// =============================================================================
// FUN_00713ad0
// -----------------------------------------------------------------------------
// Stable ID: aa_00713ad0
// Address:   0x00713ad0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00713ad0 @ 0x00713ad0
// Stable ID: aa_00713ad0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00713ad0.
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

uint32_t /* width from decompiler */ FUN_00713ad0(int *param_1)



{

  int iVar1;

  

  iVar1 = (*(code *)PTR_calloc_00af8a48)(1,0x30);

  *param_1 = iVar1;

  if (iVar1 == 0) {

    return 1;

  }

  *(uint32_t /* width from decompiler */ *)(iVar1 + 0x2c) = 0;

  *(uint32_t /* width from decompiler */ *)(iVar1 + 0x20) = 0;

  *(uint32_t /* width from decompiler */ *)(iVar1 + 0x24) = 0;

  *(uint32_t /* width from decompiler */ *)(iVar1 + 0x28) = 0;

  (*(code *)PTR_memset_00af8a50)(iVar1,0,0x10);

  (*(code *)PTR_memset_00af8a50)(iVar1 + 0x10,0,0x10);

  return 0;

}
