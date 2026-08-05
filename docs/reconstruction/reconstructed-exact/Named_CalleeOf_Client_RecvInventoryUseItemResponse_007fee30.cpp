// =============================================================================
// Named_CalleeOf_Client_RecvInventoryUseItemResponse_007fee30
// -----------------------------------------------------------------------------
// Stable ID: aa_007fee30
// Callee of Client_RecvInventoryUseItemResponse
// Address:   0x007fee30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_RecvInventoryUseItemResponse: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~68 non-empty decompiler lines.
//  - Control keywords: if×15, return×12.
//  - Notable callees: FUN_0085fd20×2, FUN_007fee30, FUN_008bf020.
//  - Return sites: 12.

/*
 * Behavioral notes:
 * Callee of Client_RecvInventoryUseItemResponse
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

void __fastcall Named_CalleeOf_Client_RecvInventoryUseItemResponse_007fee30(int param_1)



{

  int *piVar1;

  char cVar2;

  int in_EAX;

  int unaff_EBX;

  int iVar3;

  

  if (in_EAX == 4) {

    piVar1 = *(int **)(param_1 + 0x1040);

    if (piVar1 == (int *)0x0) {

      return;

    }

    cVar2 = (**(code **)(*piVar1 + 0x3d8))();

    if (cVar2 == '\0') {

      return;

    }

    if (piVar1[0x143] == 0) {

      return;

    }

    cVar2 = (**(code **)(*(int *)piVar1[0x143] + 0x3d8))();

    if (cVar2 == '\0') {

      return;

    }

    if ((*(int **)(param_1 + 0x1098) != (int *)0x0) &&

       (cVar2 = (**(code **)(**(int **)(param_1 + 0x1098) + 0x3d8))(), cVar2 != '\0')) {

      FUN_008bf020();

    }

    iVar3 = *(int *)(piVar1[0x143] + 0x580);

  }

  else {

    if (in_EAX != 0xb) {

      if (in_EAX != 0xc) {

        return;

      }

      piVar1 = *(int **)(param_1 + 0x1060);

      if (piVar1 == (int *)0x0) {

        return;

      }

      cVar2 = (**(code **)(*piVar1 + 0x3d8))();

      if (cVar2 == '\0') {

        return;

      }

      if (piVar1[0x183] != 0) {

        FUN_0085fd20();

      }

      if (piVar1[0x169] != unaff_EBX) {

        return;

      }

                    /* WARNING: Could not recover jumptable at 0x007fee8a. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      (**(code **)(*piVar1 + 0x448))();

      return;

    }

    piVar1 = *(int **)(param_1 + 0x105c);

    if (piVar1 == (int *)0x0) {

      return;

    }

    cVar2 = (**(code **)(*piVar1 + 0x3d8))();

    if (cVar2 == '\0') {

      return;

    }

    iVar3 = piVar1[0x16b];

  }

  if (iVar3 != 0) {

    FUN_0085fd20();

  }

  return;

}
