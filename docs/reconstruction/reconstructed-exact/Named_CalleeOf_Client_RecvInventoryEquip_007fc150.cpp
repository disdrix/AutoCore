// =============================================================================
// Named_CalleeOf_Client_RecvInventoryEquip_007fc150
// -----------------------------------------------------------------------------
// Stable ID: aa_007fc150
// Callee of Client_RecvInventoryEquip (+2 other named callers)
// Address:   0x007fc150  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_RecvInventoryEquip: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Client_RecvInventoryEquip (+2 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×12, return×1.
//  - Notable callees: FUN_0085e890×2, FUN_008c26c0×2, FUN_0051f4e0, FUN_007fc150.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_RecvInventoryEquip (+2 other named callers)
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

void Named_CalleeOf_Client_RecvInventoryEquip_007fc150(void)



{

  int *piVar1;

  char cVar2;

  int unaff_ESI;

  

  if ((*(int *)(unaff_ESI + 0xf40) != 0) && (*(int *)(unaff_ESI + 0x9b8) != 0)) {

    if (*(int *)(unaff_ESI + 0x1168) != 0) {

      (**(code **)(**(int **)(unaff_ESI + 0x1168) + 4))(1);

    }

    piVar1 = *(int **)(*(int *)(unaff_ESI + 0x1040) + 0x50c);

    if (piVar1 != (int *)0x0) {

      cVar2 = (**(code **)(*piVar1 + 0x3d8))();

      if (cVar2 != '\0') {

        FUN_008c26c0();

      }

    }

    piVar1 = *(int **)(*(int *)(unaff_ESI + 0x1034) + 0x510);

    if (piVar1 != (int *)0x0) {

      cVar2 = (**(code **)(*piVar1 + 0x3d8))();

      if (cVar2 != '\0') {

        FUN_008c26c0();

      }

    }

    piVar1 = *(int **)(unaff_ESI + 0x105c);

    if (piVar1 != (int *)0x0) {

      cVar2 = (**(code **)(*piVar1 + 0x3d8))();

      if ((cVar2 != '\0') && (piVar1[0x16b] != 0)) {

        FUN_0085e890();

      }

    }

    piVar1 = *(int **)(unaff_ESI + 0x1060);

    if (piVar1 != (int *)0x0) {

      cVar2 = (**(code **)(*piVar1 + 0x3d8))();

      if ((cVar2 != '\0') && (piVar1[0x183] != 0)) {

        FUN_0085e890();

      }

    }

    if (**(int **)(unaff_ESI + 0xf40) != 0) {

      (**(code **)(*(int *)**(int **)(unaff_ESI + 0xf40) + 0xb0))

                (*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x9b8));

    }

    *(uint32_t /* width from decompiler */ *)(*(int *)(unaff_ESI + 0x9b8) + 0x494) = 0;

    (**(code **)(**(int **)(unaff_ESI + 0x9b8) + 0x3b0))(0);

    if (*(int *)(unaff_ESI + 0xe98) != 0) {

      FUN_0051f4e0(0);

    }

  }

  return;

}
