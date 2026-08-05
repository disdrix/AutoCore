// =============================================================================
// FUN_004b09d0
// -----------------------------------------------------------------------------
// Stable ID: aa_004b09d0
// Address:   0x004b09d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004b09d0 @ 0x004b09d0
// Stable ID: aa_004b09d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: block×3, FUN_004b0010, FUN_004b09d0.
//  - Return sites: 1.

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

/* WARNING: Removing unreachable block (ram,0x004b09e1) */

/* WARNING: Removing unreachable block (ram,0x004b09e2) */

/* WARNING: Removing unreachable block (ram,0x004b09f6) */



void __thiscall FUN_004b09d0(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  if (*(int *)(param_1 + 4) != *(int *)(param_1 + 8)) {

    *(int *)(param_1 + 8) = *(int *)(param_1 + 4);

  }

  FUN_004b0010(*(uint32_t /* width from decompiler */ *)(param_1 + 4),param_2,param_3,param_3);

  return;

}
