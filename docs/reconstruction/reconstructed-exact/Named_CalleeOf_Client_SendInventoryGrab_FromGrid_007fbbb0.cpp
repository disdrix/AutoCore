// =============================================================================
// Named_CalleeOf_Client_SendInventoryGrab_FromGrid_007fbbb0
// -----------------------------------------------------------------------------
// Stable ID: aa_007fbbb0
// Callee of Client_SendInventoryGrab_FromGrid (+1 other named callers)
// Address:   0x007fbbb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_SendInventoryGrab_FromGrid: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Client_SendInventoryGrab_FromGrid (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_007fbbb0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_SendInventoryGrab_FromGrid (+1 other named callers)
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

void Named_CalleeOf_Client_SendInventoryGrab_FromGrid_007fbbb0(void)



{

  int iVar1;

  char cVar2;

  int unaff_ESI;

  

  if (*(int *)(unaff_ESI + 0x113c) != 0) {

    cVar2 = (**(code **)(**(int **)(unaff_ESI + 0x113c) + 0xd0))();

    if ((cVar2 != '\0') && (*(int *)(*(int *)(unaff_ESI + 0x113c) + 0x2b0) != 0)) {

      (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0xf40) + 0xb0))

                (*(int *)(unaff_ESI + 0x113c));

      (**(code **)(**(int **)(unaff_ESI + 0x113c) + 4))(0);

      (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0xf40) + 0x1c8))(0);

      (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0xf40) + 0x3c0))(0);

      if (0 < *(int *)(**(int **)(unaff_ESI + 0xf40) + 0x514)) {

        iVar1 = **(int **)(unaff_ESI + 0xf40);

        *(uint32_t /* width from decompiler */ *)(iVar1 + 0x498) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x514);

      }

      if (0 < *(int *)(**(int **)(unaff_ESI + 0xf40) + 0x518)) {

        iVar1 = **(int **)(unaff_ESI + 0xf40);

        *(uint32_t /* width from decompiler */ *)(iVar1 + 0x49c) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x518);

      }

    }

  }

  return;

}
