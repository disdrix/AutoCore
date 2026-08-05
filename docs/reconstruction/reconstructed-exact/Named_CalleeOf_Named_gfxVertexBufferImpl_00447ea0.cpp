// =============================================================================
// Named_CalleeOf_Named_gfxVertexBufferImpl_00447ea0
// -----------------------------------------------------------------------------
// Stable ID: aa_00447ea0
// Callee of Named_gfxVertexBufferImpl (+1 other named callers)
// Address:   0x00447ea0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxVertexBufferImpl: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_gfxVertexBufferImpl (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~69 non-empty decompiler lines.
//  - Control keywords: if×11, return×7.
//  - Notable callees: FUN_004487d0×2, FUN_0044c2f0×2, FUN_00447ea0, FUN_004e2f20.
//  - Return sites: 7.

/*
 * Behavioral notes:
 * Callee of Named_gfxVertexBufferImpl (+1 other named callers)
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

void __fastcall Named_CalleeOf_Named_gfxVertexBufferImpl_00447ea0(uint32_t /* width from decompiler */ param_1)



{

  void *pvVar1;

  char cVar2;

  int in_EAX;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  uint uVar5;

  uint uVar6;

  int unaff_ESI;

  

  if (unaff_ESI != in_EAX) {

    if ((*(int *)(in_EAX + 4) == 0) ||

       (uVar5 = *(int *)(in_EAX + 8) - *(int *)(in_EAX + 4) >> 3, uVar5 == 0)) {

      if (*(void **)(unaff_ESI + 4) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(*(void **)(unaff_ESI + 4));

      }

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 4) = 0;

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 8) = 0;

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xc) = 0;

      return;

    }

    pvVar1 = *(void **)(unaff_ESI + 4);

    if (pvVar1 == (void *)0x0) {

      uVar6 = 0;

    }

    else {

      uVar6 = *(int *)(unaff_ESI + 8) - (int)pvVar1 >> 3;

    }

    if (uVar5 <= uVar6) {

      FUN_0044c2f0();

      if (*(int *)(in_EAX + 4) == 0) {

        *(uint32_t /* width from decompiler */ *)(unaff_ESI + 8) = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 4);

        return;

      }

      *(int *)(unaff_ESI + 8) =

           *(int *)(unaff_ESI + 4) + (*(int *)(in_EAX + 8) - *(int *)(in_EAX + 4) >> 3) * 8;

      return;

    }

    if (pvVar1 == (void *)0x0) {

      uVar6 = 0;

    }

    else {

      uVar6 = *(int *)(unaff_ESI + 0xc) - (int)pvVar1 >> 3;

    }

    if (uVar5 <= uVar6) {

      FUN_0044c2f0();

      uVar3 = FUN_004487d0(param_1);

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 8) = uVar3;

      return;

    }

    if (pvVar1 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar1);

    }

    if (*(int *)(in_EAX + 4) == 0) {

      iVar4 = 0;

    }

    else {

      iVar4 = *(int *)(in_EAX + 8) - *(int *)(in_EAX + 4) >> 3;

    }

    cVar2 = FUN_004e2f20(iVar4);

    if (cVar2 != '\0') {

      uVar3 = FUN_004487d0(param_1);

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 8) = uVar3;

    }

  }

  return;

}
