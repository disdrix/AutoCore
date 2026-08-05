// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_gfxView_0043f4b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0043f4b0
// Callee of Named_CalleeOf_Named_gfxView
// Address:   0x0043f4b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_gfxView: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×6, return×2.
//  - Notable callees: FUN_0043b7d0, FUN_0043f4b0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_gfxView
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

void Named_CalleeOf_Named_CalleeOf_Named_gfxView_0043f4b0(void)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  int unaff_EBX;

  int unaff_EDI;

  bool bVar4;

  

  if (*(int *)(unaff_EBX + 0x10) != 0) {

    if (DAT_00d1f614 != 0) {

      piVar1 = (int *)(DAT_00d1f614 + 0xe8 + *(int *)(DAT_00d1f614 + 0xc4) * 0x4c);

      *piVar1 = *piVar1 + 1;

    }

    iVar2 = **(int **)(unaff_EBX + 0x10);

    if (DAT_00d1a555 != '\0') {

      if (((&DAT_00d0e0e8)[unaff_EDI] != *(int *)(unaff_EBX + 0x14)) ||

         ((&DAT_00d0e128)[unaff_EDI] != iVar2)) {

        (**(code **)(*(int *)*DAT_00d1f044 + 400))((int *)*DAT_00d1f044);

        iVar3 = DAT_00d1f614;

        bVar4 = DAT_00d1f614 != 0;

        (&DAT_00d0e128)[unaff_EDI] = iVar2;

        if (bVar4) {

          piVar1 = (int *)(iVar3 + (*(int *)(iVar3 + 0xc4) + 3) * 0x4c);

          *piVar1 = *piVar1 + 1;

        }

      }

      (&DAT_00d0e0e8)[unaff_EDI] = *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x14);

      DAT_00d1a55c = *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x18);

      return;

    }

    if ((&DAT_00d0e128)[unaff_EDI] != iVar2) {

      (**(code **)(*(int *)*DAT_00d1f044 + 400))((int *)*DAT_00d1f044);

      (&DAT_00d0e128)[unaff_EDI] = iVar2;

      FUN_0043b7d0(6);

    }

    DAT_00d1a558 = *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x14);

    DAT_00d1a55c = *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x18);

  }

  return;

}
