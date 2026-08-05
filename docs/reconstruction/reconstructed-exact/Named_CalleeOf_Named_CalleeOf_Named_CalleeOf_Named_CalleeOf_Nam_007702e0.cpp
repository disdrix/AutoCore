// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_007702e0
// -----------------------------------------------------------------------------
// Stable ID: aa_007702e0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_ecc_sys
// Address:   0x007702e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_ecc_sys: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×5, return×3, do×1, while×1.
//  - Notable callees: FUN_007702e0.
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

bool __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_007702e0(int *param_1)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  int iVar4;

  

  iVar1 = *param_1;

  if (iVar1 != 0) {

    if (iVar1 == 1) {

      return true;

    }

    if (1 < iVar1) {

      iVar4 = 0;

      if (0 < iVar1) {

        piVar2 = (int *)param_1[3];

        iVar3 = iVar1;

        do {

          if (*piVar2 == 0xfffffff) {

            iVar4 = iVar4 + 1;

          }

          piVar2 = piVar2 + 1;

          iVar3 = iVar3 + -1;

        } while (iVar3 != 0);

      }

      return iVar1 / 2 <= iVar4;

    }

  }

  return false;

}
