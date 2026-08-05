// =============================================================================
// FUN_00445c30
// -----------------------------------------------------------------------------
// Stable ID: aa_00445c30
// Address:   0x00445c30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00445c30 @ 0x00445c30
// Stable ID: aa_00445c30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: CONCAT31, FUN_00445c30, block.
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

/* WARNING: Removing unreachable block (ram,0x00445c53) */



uint32_t /* width from decompiler */ __thiscall FUN_00445c30(int param_1,uint param_2)



{

  void *pvVar1;

  

  *(uint32_t /* width from decompiler */ *)(param_1 + 4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

  if (param_2 != 0) {

    pvVar1 = operator_new(param_2);

    *(void **)(param_1 + 4) = pvVar1;

    *(void **)(param_1 + 8) = pvVar1;

    *(uint *)(param_1 + 0xc) = (int)pvVar1 + param_2;

    return CONCAT31((int3)((int)pvVar1 + param_2 >> 8),1);

  }

  return 0;

}
