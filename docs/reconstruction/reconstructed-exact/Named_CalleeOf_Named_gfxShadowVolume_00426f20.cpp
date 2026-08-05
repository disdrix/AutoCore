// =============================================================================
// Named_CalleeOf_Named_gfxShadowVolume_00426f20
// -----------------------------------------------------------------------------
// Stable ID: aa_00426f20
// Callee of Named_gfxShadowVolume
// Address:   0x00426f20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxShadowVolume: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, while×1.
//  - Notable callees: FUN_00426f20.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_gfxShadowVolume
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

void Named_CalleeOf_Named_gfxShadowVolume_00426f20(void)



{

  int in_EAX;

  int unaff_EBX;

  

  while( true ) {

    if (in_EAX == unaff_EBX) {

      return;

    }

    if (*(void **)(in_EAX + 4) != (void *)0x0) break;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 4) = 0;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 8) = 0;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc) = 0;

    in_EAX = in_EAX + 0x10;

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(*(void **)(in_EAX + 4));

}
