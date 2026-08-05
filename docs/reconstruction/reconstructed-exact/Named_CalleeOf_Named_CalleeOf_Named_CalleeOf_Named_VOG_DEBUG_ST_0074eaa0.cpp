// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_0074eaa0
// -----------------------------------------------------------------------------
// Stable ID: aa_0074eaa0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x0074eaa0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_00449000×2, FUN_0074e9d0, FUN_0074eaa0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_0074eaa0(void)



{

  int iVar1;

  uint uVar2;

  int unaff_ESI;

  uint uVar3;

  float10 fVar4;

  

  if ((*(int *)(unaff_ESI + 4) != 0) &&

     (uVar2 = *(int *)(unaff_ESI + 8) - *(int *)(unaff_ESI + 4) >> 2, uVar2 != 0)) {

    FUN_00449000(uVar2,0);

    FUN_00449000(uVar2,0);

    uVar3 = 0;

    if (uVar2 != 0) {

      do {

        iVar1 = uVar3 * 4;

        *(float *)(*(int *)(unaff_ESI + 0x18) + iVar1) = g_flOne;

        (**(code **)(**(int **)(*(int *)(unaff_ESI + 4) + iVar1) + 0x10))

                  (*(int *)(unaff_ESI + 0x28) + iVar1);

        uVar3 = uVar3 + 1;

      } while (uVar3 < uVar2);

    }

    fVar4 = (float10)(**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 4) + 4))();

    *(float *)(unaff_ESI + 0x48) = (float)fVar4;

  }

  FUN_0074e9d0(0x3f800000);

  return;

}
