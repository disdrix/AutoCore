// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_RecvInventoryUsePaint_00519d20
// -----------------------------------------------------------------------------
// Stable ID: aa_00519d20
// Callee of Named_CalleeOf_Client_RecvInventoryUsePaint (+2 other named callers)
// Address:   0x00519d20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_RecvInventoryUsePaint: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Client_RecvInventoryUsePaint (+2 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×5, goto×2, return×2, do×1, while×1.
//  - Notable callees: FUN_00519a30, FUN_00519d20.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_RecvInventoryUsePaint (+2 other named callers)
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_CalleeOf_Client_RecvInventoryUsePaint_00519d20(uint param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  if (DAT_00b042b8 < 1) {

    FUN_00519a30();

  }

  iVar1 = *(int *)(*(int *)(DAT_00b042bc + (DAT_00b042b4 & param_1) * 4) + 4);

  if (iVar1 == 0) {

LAB_00519d62:

    puVar2 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    do {

      if (param_1 == *(uint *)(iVar1 + 0x10)) {

        if (iVar1 == 0) goto LAB_00519d62;

        puVar2 = *(uint32_t /* width from decompiler */ **)(iVar1 + 8);

        goto LAB_00519d69;

      }

      iVar1 = *(int *)(iVar1 + 0xc);

    } while (iVar1 != 0);

    puVar2 = (uint32_t /* width from decompiler */ *)0x0;

  }

LAB_00519d69:

  if (puVar2 == (uint32_t /* width from decompiler */ *)0x0) {

    return 0;

  }

  return *puVar2;

}
