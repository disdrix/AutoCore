// =============================================================================
// Named_CalleeOf_Named_gfxVertexBufferImpl_0099a820
// -----------------------------------------------------------------------------
// Stable ID: aa_0099a820
// Callee of Named_gfxVertexBufferImpl
// Address:   0x0099a820  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxVertexBufferImpl: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×6, goto×2, return×1.
//  - Notable callees: FUN_0044c440, FUN_00986990, FUN_0099a820.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_gfxVertexBufferImpl
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

void Named_CalleeOf_Named_gfxVertexBufferImpl_0099a820(void)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  int unaff_ESI;

  

  iVar2 = DAT_00d1f614;

  iVar3 = *(int *)(unaff_ESI + 0x10);

  if (iVar3 == 0) goto LAB_0099a8a9;

  if ((*(byte *)(iVar3 + 4) & 1) == 0) {

    if (DAT_00d1f614 != 0) {

      *(int *)(DAT_00d1f614 + 0x388) =

           *(int *)(DAT_00d1f614 + 0x388) - *(int *)(iVar3 + 8) * *(int *)(unaff_ESI + 0x18);

      iVar3 = *(int *)(unaff_ESI + 0x18);

      goto LAB_0099a865;

    }

  }

  else if (DAT_00d1f614 != 0) {

    *(int *)(DAT_00d1f614 + 0x388) =

         *(int *)(DAT_00d1f614 + 0x388) - *(int *)(iVar3 + 0xc) * *(int *)(iVar3 + 8);

    iVar3 = *(int *)(*(int *)(unaff_ESI + 0x10) + 0xc);

LAB_0099a865:

    piVar1 = (int *)(iVar2 + 0x338);

    *piVar1 = *piVar1 - iVar3;

    piVar1 = (int *)(iVar2 + 0x334);

    *piVar1 = *piVar1 + -1;

  }

  if (DAT_00d1f634 != 0) {

    FUN_00986990();

    if (*(int *)(unaff_ESI + 8) != 0 || *(int *)(unaff_ESI + 0xc) != 0) {

      FUN_0044c440();

    }

  }

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x10) = 0;

LAB_0099a8a9:

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x14) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x18) = 0;

                    /* WARNING: Subroutine does not return */

  operator_delete(*(void **)(unaff_ESI + 0x1c));

}
