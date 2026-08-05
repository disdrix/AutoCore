// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_008fc740
// -----------------------------------------------------------------------------
// Stable ID: aa_008fc740
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mis
// Address:   0x008fc740  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mis: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~70 non-empty decompiler lines.
//  - Control keywords: if×14, do×3, while×3, return×2.
//  - Notable callees: FUN_008fc740.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mis
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_008fc740(void)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  void *pvVar3;

  int *unaff_ESI;

  int iVar4;

  

  if (unaff_ESI[0x1cf] != 0) {

    iVar4 = 0;

    if (0 < unaff_ESI[0x147]) {

      do {

        iVar1 = *(int *)(unaff_ESI[0x1cf] + iVar4 * 4);

        if (iVar1 != 0) {

          (**(code **)(*unaff_ESI + 0xb0))(iVar1);

          puVar2 = *(uint32_t /* width from decompiler */ **)(unaff_ESI[0x1cf] + iVar4 * 4);

          if (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {

            (**(code **)*puVar2)(1);

          }

          *(uint32_t /* width from decompiler */ *)(unaff_ESI[0x1cf] + iVar4 * 4) = 0;

        }

        iVar4 = iVar4 + 1;

      } while (iVar4 < unaff_ESI[0x147]);

    }

    if ((void *)unaff_ESI[0x1cf] != (void *)0x0) {

      operator_delete__((void *)unaff_ESI[0x1cf]);

    }

    unaff_ESI[0x1cf] = 0;

  }

  if (unaff_ESI[0x1cb] != 0) {

    iVar4 = 0;

    if (0 < unaff_ESI[0x147]) {

      do {

        iVar1 = *(int *)(unaff_ESI[0x1cb] + iVar4 * 4);

        if (iVar1 != 0) {

          (**(code **)(*unaff_ESI + 0xb0))(iVar1);

          puVar2 = *(uint32_t /* width from decompiler */ **)(unaff_ESI[0x1cb] + iVar4 * 4);

          if (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {

            (**(code **)*puVar2)(1);

          }

          *(uint32_t /* width from decompiler */ *)(unaff_ESI[0x1cb] + iVar4 * 4) = 0;

        }

        iVar4 = iVar4 + 1;

      } while (iVar4 < unaff_ESI[0x147]);

    }

    if ((void *)unaff_ESI[0x1cb] != (void *)0x0) {

      operator_delete__((void *)unaff_ESI[0x1cb]);

    }

    unaff_ESI[0x1cb] = 0;

  }

  if (unaff_ESI[0x180] != 0) {

    iVar4 = 0;

    if (0 < unaff_ESI[0x145]) {

      do {

        pvVar3 = *(void **)(unaff_ESI[0x180] + iVar4 * 4);

        if (pvVar3 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

          operator_delete(pvVar3);

        }

        *(uint32_t /* width from decompiler */ *)(unaff_ESI[0x180] + iVar4 * 4) = 0;

        iVar4 = iVar4 + 1;

      } while (iVar4 < unaff_ESI[0x145]);

    }

    if ((void *)unaff_ESI[0x180] != (void *)0x0) {

      operator_delete__((void *)unaff_ESI[0x180]);

    }

    unaff_ESI[0x180] = 0;

  }

  unaff_ESI[0x145] = 0;

  return;

}
