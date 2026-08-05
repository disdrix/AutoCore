// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_RecvInventoryAddItem_007fbd30
// -----------------------------------------------------------------------------
// Stable ID: aa_007fbd30
// Callee of Named_CalleeOf_Client_RecvInventoryAddItem (+2 other named callers)
// Address:   0x007fbd30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_RecvInventoryAddItem: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Client_RecvInventoryAddItem (+2 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, goto×1.
//  - Notable callees: FUN_007fbd30.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_RecvInventoryAddItem (+2 other named callers)
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

void Named_CalleeOf_Named_CalleeOf_Client_RecvInventoryAddItem_007fbd30(void)



{

  int *in_EAX;

  int iVar1;

  int iVar2;

  int iVar3;

  int *unaff_ESI;

  float unaff_EDI;

  uint32_t /* width from decompiler */ uVar4;

  

  if ((in_EAX == (int *)0x0) || (unaff_ESI == (int *)0x0)) {

    return;

  }

  iVar1 = (**(code **)(*in_EAX + 0x490))();

  iVar2 = (**(code **)(*in_EAX + 0x494))();

  iVar3 = (**(code **)(*in_EAX + 0x49c))();

  if (iVar2 < iVar1) {

    (**(code **)(*unaff_ESI + 0x460))(g_flOne / (float)(iVar1 - iVar2));

    (**(code **)(*unaff_ESI + 0x454))((float)iVar3 / unaff_EDI,0);

    uVar4 = 1;

  }

  else {

    if (0 < iVar3) {

      (**(code **)(*unaff_ESI + 0x460))(g_flOne / (float)iVar3);

      (**(code **)(*unaff_ESI + 0x454))(g_flOne - unaff_EDI,0);

      (**(code **)(*unaff_ESI + 0xd4))(1);

      goto LAB_007fbe36;

    }

    (**(code **)(*unaff_ESI + 0x460))(0x3f800000);

    (**(code **)(*unaff_ESI + 0x454))(0,1);

    uVar4 = 0;

  }

  (**(code **)(*unaff_ESI + 0xd4))(uVar4);

LAB_007fbe36:

                    /* WARNING: Could not recover jumptable at 0x007fbe40. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (**(code **)(*unaff_ESI + 0x34c))();

  return;

}
