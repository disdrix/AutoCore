// =============================================================================
// Named_CalleeOf_Named_gfxView_0073f610
// -----------------------------------------------------------------------------
// Stable ID: aa_0073f610
// Callee of Named_gfxView
// Address:   0x0073f610  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxView: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, while×1.
//  - Notable callees: FUN_0073f400, FUN_0073f610.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_gfxView
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

int Named_CalleeOf_Named_gfxView_0073f610(void)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  int unaff_EBX;

  uint32_t /* width from decompiler */ *puVar3;

  

  puVar3 = *(uint32_t /* width from decompiler */ **)(unaff_EBX + 0x24);

  puVar1 = *(uint32_t /* width from decompiler */ **)(unaff_EBX + 0x28);

  while( true ) {

    if (puVar3 == puVar1) {

      FUN_0073f400(unaff_EBX);

      return 0;

    }

    iVar2 = (**(code **)(*(int *)*puVar3 + 0x1c))();

    if (iVar2 < 0) break;

    puVar3 = puVar3 + 1;

  }

  return iVar2;

}
