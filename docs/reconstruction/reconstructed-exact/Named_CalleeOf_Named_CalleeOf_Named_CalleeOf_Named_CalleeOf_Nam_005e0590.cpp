// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_005e0590
// -----------------------------------------------------------------------------
// Stable ID: aa_005e0590
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVO
// Address:   0x005e0590  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVO: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×6, return×4.
//  - Notable callees: CVOGReaction_RandomUnitScalar, FUN_005e0590.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVO
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

int Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_005e0590(void)



{

  ushort uVar1;

  int iVar2;

  int unaff_ESI;

  float fVar3;

  

  iVar2 = CVOGReaction_RandomUnitScalar();

  if (0xfffff < *(int *)(iVar2 + 0xc)) {

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0xc) = 0;

  }

  uVar1 = *(ushort *)(*(int *)(iVar2 + 8) + *(int *)(iVar2 + 0xc) * 2);

  *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 1;

  fVar3 = (float)uVar1 * DAT_00aaa638;

  if (1 < unaff_ESI) {

    if (unaff_ESI == 2) {

      if (fVar3 < DAT_00a0f298) {

        return 2;

      }

      return 1;

    }

    if (DAT_009dbf08 <= fVar3) {

      iVar2 = unaff_ESI + -1;

      if (DAT_009dbf04 <= fVar3) {

        iVar2 = unaff_ESI + -2;

      }

      return iVar2;

    }

  }

  return unaff_ESI;

}
