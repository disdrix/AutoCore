// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_007705b0
// -----------------------------------------------------------------------------
// Stable ID: aa_007705b0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_ecc_sys
// Address:   0x007705b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_ecc_sys: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×3, return×3, do×1, while×1.
//  - Notable callees: FUN_007705b0.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_ecc_sys
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_007705b0(void)



{

  int iVar1;

  int *in_EAX;

  int *piVar2;

  int iVar3;

  

  iVar1 = *in_EAX;

  if (iVar1 < 2) {

    return 0;

  }

  iVar3 = 1;

  if (1 < iVar1) {

    piVar2 = (int *)in_EAX[3];

    do {

      piVar2 = piVar2 + 1;

      if (*piVar2 != 0xfffffff) {

        return 0;

      }

      iVar3 = iVar3 + 1;

    } while (iVar3 < iVar1);

  }

  return 1;

}
