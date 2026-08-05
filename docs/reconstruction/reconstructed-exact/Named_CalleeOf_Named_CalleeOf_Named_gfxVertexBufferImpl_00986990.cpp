// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_gfxVertexBufferImpl_00986990
// -----------------------------------------------------------------------------
// Stable ID: aa_00986990
// Callee of Named_CalleeOf_Named_gfxVertexBufferImpl
// Address:   0x00986990  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_gfxVertexBufferImpl: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: if×5, return×3, while×1.
//  - Notable callees: FUN_0045f6e0, FUN_0045f800, FUN_0045f860, FUN_007465c0, FUN_009862f0, FUN_00986990.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_gfxVertexBufferImpl
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

void Named_CalleeOf_Named_CalleeOf_Named_gfxVertexBufferImpl_00986990(void)



{

  int *piVar1;

  char cVar2;

  int in_EAX;

  int iVar3;

  int *piVar4;

  uint local_4;

  

  local_4 = *(int *)(*(int *)(in_EAX + 0x10) + 4) << 0x10 | *(uint *)(*(int *)(in_EAX + 0x10) + 8);

  iVar3 = FUN_0045f6e0();

  piVar4 = *(int **)(iVar3 + 4);

  if (piVar4 != *(int **)(iVar3 + 8)) {

    while (*piVar4 != *(int *)(in_EAX + 0x10)) {

      piVar4 = piVar4 + 8;

      if (piVar4 == *(int **)(iVar3 + 8)) {

        return;

      }

    }

    cVar2 = FUN_009862f0();

    if (cVar2 != '\0') {

      piVar1 = (int *)*piVar4;

      if (piVar1 != (int *)0x0) {

        FUN_007465c0();

        piVar1[1] = -1;

        piVar1[2] = 0;

        piVar1[3] = 0;

        *piVar1 = (int)DAT_00d219c0;

        DAT_00d219c0 = piVar1;

      }

      *piVar4 = 0;

      FUN_0045f860(*(uint32_t /* width from decompiler */ *)(piVar4[2] + 4));

      *(int *)(piVar4[2] + 4) = piVar4[2];

      piVar4[3] = 0;

      *(int *)piVar4[2] = piVar4[2];

      *(int *)(piVar4[2] + 8) = piVar4[2];

      if ((void *)piVar4[5] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete((void *)piVar4[5]);

      }

      piVar4[5] = 0;

      piVar4[6] = 0;

      piVar4[7] = 0;

      FUN_0045f800(&local_4,piVar4);

    }

  }

  return;

}
