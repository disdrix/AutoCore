// =============================================================================
// Named_CalleeOf_Named_phyBVWalkableSurface_0044ed70
// -----------------------------------------------------------------------------
// Stable ID: aa_0044ed70
// Callee of Named_phyBVWalkableSurface
// Address:   0x0044ed70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_phyBVWalkableSurface: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, do×1, while×1.
//  - Notable callees: FUN_00435f30, FUN_0044ed70, FUN_00768ee0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_phyBVWalkableSurface
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

uint32_t /* width from decompiler */ __fastcall Named_CalleeOf_Named_phyBVWalkableSurface_0044ed70(int param_1)



{

  int in_EAX;

  uint32_t /* width from decompiler */ uVar1;

  int unaff_EDI;

  

  if (*(int *)(unaff_EDI + 0x4044) != 0) {

    if (-1 < in_EAX + -1) {

      do {

        FUN_00768ee0(param_1);

        param_1 = param_1 + 2;

        in_EAX = in_EAX + -1;

      } while (in_EAX != 0);

    }

    return 0;

  }

  uVar1 = FUN_00435f30(param_1,in_EAX * 2);

  return uVar1;

}
