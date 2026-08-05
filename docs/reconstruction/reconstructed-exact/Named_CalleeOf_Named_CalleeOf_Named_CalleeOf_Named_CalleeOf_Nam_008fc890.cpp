// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_008fc890
// -----------------------------------------------------------------------------
// Stable ID: aa_008fc890
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mis
// Address:   0x008fc890  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mis: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~55 non-empty decompiler lines.
//  - Control keywords: if×11, do×2, while×2, return×1.
//  - Notable callees: FUN_008fc890.
//  - Return sites: 1.

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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_008fc890(void)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int *unaff_ESI;

  int iVar3;

  

  if (unaff_ESI[0x1ce] != 0) {

    iVar3 = 0;

    if (0 < unaff_ESI[0x146]) {

      do {

        iVar1 = *(int *)(unaff_ESI[0x1ce] + iVar3 * 4);

        if (iVar1 != 0) {

          (**(code **)(*unaff_ESI + 0xb0))(iVar1);

          puVar2 = *(uint32_t /* width from decompiler */ **)(unaff_ESI[0x1ce] + iVar3 * 4);

          if (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {

            (**(code **)*puVar2)(1);

          }

          *(uint32_t /* width from decompiler */ *)(unaff_ESI[0x1ce] + iVar3 * 4) = 0;

        }

        iVar3 = iVar3 + 1;

      } while (iVar3 < unaff_ESI[0x146]);

    }

    if ((void *)unaff_ESI[0x1ce] != (void *)0x0) {

      operator_delete__((void *)unaff_ESI[0x1ce]);

    }

    unaff_ESI[0x1ce] = 0;

  }

  if (unaff_ESI[0x1ca] != 0) {

    iVar3 = 0;

    if (0 < unaff_ESI[0x146]) {

      do {

        iVar1 = *(int *)(unaff_ESI[0x1ca] + iVar3 * 4);

        if (iVar1 != 0) {

          (**(code **)(*unaff_ESI + 0xb0))(iVar1);

          puVar2 = *(uint32_t /* width from decompiler */ **)(unaff_ESI[0x1ca] + iVar3 * 4);

          if (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {

            (**(code **)*puVar2)(1);

          }

          *(uint32_t /* width from decompiler */ *)(unaff_ESI[0x1ca] + iVar3 * 4) = 0;

        }

        iVar3 = iVar3 + 1;

      } while (iVar3 < unaff_ESI[0x146]);

    }

    if ((void *)unaff_ESI[0x1ca] != (void *)0x0) {

      operator_delete__((void *)unaff_ESI[0x1ca]);

    }

    unaff_ESI[0x1ca] = 0;

  }

  if ((void *)unaff_ESI[0x17f] != (void *)0x0) {

    operator_delete__((void *)unaff_ESI[0x17f]);

  }

  unaff_ESI[0x17f] = 0;

  unaff_ESI[0x143] = 0;

  return;

}
