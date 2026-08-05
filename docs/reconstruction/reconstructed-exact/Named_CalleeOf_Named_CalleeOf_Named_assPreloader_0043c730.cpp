// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_assPreloader_0043c730
// -----------------------------------------------------------------------------
// Stable ID: aa_0043c730
// Callee of Named_CalleeOf_Named_assPreloader
// Address:   0x0043c730  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_assPreloader: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: FUN_0043ce90×2, FUN_0040d9c0, FUN_0043c730, FUN_0043c8c0, FUN_0043cec0.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_assPreloader
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

void Named_CalleeOf_Named_CalleeOf_Named_assPreloader_0043c730(void)



{

  uint uVar1;

  int iVar2;

  int in_EAX;

  int unaff_EDI;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  if (unaff_EDI != in_EAX) {

    if (*(uint *)(in_EAX + 0x10) == 0) {

      FUN_0040d9c0();

      return;

    }

    uVar1 = *(uint *)(unaff_EDI + 0x10);

    iVar2 = *(int *)(in_EAX + 0xc);

    if (*(uint *)(in_EAX + 0x10) <= uVar1) {

      FUN_0043ce90();

      FUN_0043c8c0(&local_8,local_8,local_4,unaff_EDI,

                   *(int *)(unaff_EDI + 0x10) + *(int *)(unaff_EDI + 0xc));

      return;

    }

    FUN_0043ce90();

    FUN_0043cec0(unaff_EDI,unaff_EDI,*(int *)(unaff_EDI + 0x10) + *(int *)(unaff_EDI + 0xc),in_EAX,

                 iVar2 + uVar1,in_EAX,*(int *)(in_EAX + 0x10) + *(int *)(in_EAX + 0xc));

  }

  return;

}
