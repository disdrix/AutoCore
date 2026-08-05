// =============================================================================
// Named_CalleeOf_Client_RecvInventoryEquip_007fc270
// -----------------------------------------------------------------------------
// Stable ID: aa_007fc270
// Callee of Client_RecvInventoryEquip (+2 other named callers)
// Address:   0x007fc270  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_RecvInventoryEquip: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Client_RecvInventoryEquip (+2 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_0051f4e0, FUN_007fc270.
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

void Named_CalleeOf_Client_RecvInventoryEquip_007fc270(uint32_t /* width from decompiler */ param_1)



{

  int *piVar1;

  int iVar2;

  int unaff_ESI;

  int unaff_EDI;

  uint32_t /* width from decompiler */ *puStack_28;

  int iStack_24;

  uint8_t *puStack_20;

  uint32_t /* width from decompiler */ uStack_1c;

  uint32_t /* width from decompiler */ uStack_18;

  uint8_t auStack_10 [16];

  

  if (unaff_EDI != 0) {

    uStack_18 = 0x7fc287;

    FUN_0051f4e0();

    if (**(int **)(unaff_ESI + 0xf40) != 0) {

      uStack_18 = 0x7fc2a5;

      (**(code **)(*(int *)**(int **)(unaff_ESI + 0xf40) + 0xa8))();

    }

    *(uint32_t /* width from decompiler */ *)(*(int *)(unaff_ESI + 0x9b8) + 0x494) = param_1;

    uStack_18 = 0x7fc2c4;

    (**(code **)(**(int **)(unaff_ESI + 0x9b8) + 0x3b0))();

    uStack_18 = 4;

    uStack_1c = 0x7fc2d4;

    (**(code **)(**(int **)(unaff_ESI + 0x9b8) + 0x3bc))();

    uStack_1c = 1;

    puStack_20 = auStack_10;

    iStack_24 = 0x7fc2e9;

    piVar1 = (int *)(**(code **)(**(int **)(unaff_ESI + 0x9b8) + 0x140))();

    puStack_20 = (uint8_t *)(*(int *)(unaff_ESI + 0x302c) - *piVar1 / 2);

    iStack_24 = 1;

    puStack_28 = &uStack_18;

    iVar2 = (**(code **)(**(int **)(unaff_ESI + 0x9b8) + 0x140))();

    iStack_24 = *(int *)(unaff_ESI + 0x3030) - *(int *)(iVar2 + 4) / 2;

    (**(code **)(**(int **)(unaff_ESI + 0x9b8) + 0x11c))(&puStack_28);

    if (*(int *)(unaff_ESI + 0x1168) != 0) {

      (**(code **)(**(int **)(unaff_ESI + 0x1168) + 4))(0);

    }

  }

  return;

}
