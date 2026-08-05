// =============================================================================
// Named_CalleeOf_Named_gfxBodyMassageMachine_0095d7b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0095d7b0
// Callee of Named_gfxBodyMassageMachine
// Address:   0x0095d7b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxBodyMassageMachine: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×3, while×1, return×1.
//  - Notable callees: FUN_0095d7b0, SQRT.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_gfxBodyMassageMachine
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

void Named_CalleeOf_Named_gfxBodyMassageMachine_0095d7b0(void)



{

  int iVar1;

  int iVar2;

  float fVar3;

  int iVar4;

  int unaff_EDI;

  

  if (*(int *)(unaff_EDI + 0xc) == 0) {

    iVar4 = 0;

  }

  else {

    iVar4 = *(int *)(unaff_EDI + 0x10) - *(int *)(unaff_EDI + 0xc) >> 2;

  }

  while (iVar4 = iVar4 + -1, -1 < iVar4) {

    iVar1 = *(int *)(*(int *)(unaff_EDI + 0xc) + iVar4 * 4);

    if (*(int *)(iVar1 + 0x148) != -1) {

      iVar2 = *(int *)(*(int *)(unaff_EDI + 0xc) + *(int *)(iVar1 + 0x148) * 4);

      if ((0.0 < *(float *)(iVar1 + 0x154)) &&

         (fVar3 = SQRT(*(float *)(iVar1 + 0x1c) * *(float *)(iVar1 + 0x1c) +

                       *(float *)(iVar1 + 0x18) * *(float *)(iVar1 + 0x18) +

                       *(float *)(iVar1 + 0x14) * *(float *)(iVar1 + 0x14)) +

                  *(float *)(iVar1 + 0x154), *(float *)(iVar2 + 0x154) < fVar3)) {

        *(float *)(iVar2 + 0x154) = fVar3;

      }

    }

  }

  return;

}
