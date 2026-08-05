// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_UI_InventoryDropToGrid_0085e820
// -----------------------------------------------------------------------------
// Stable ID: aa_0085e820
// Callee of Named_CalleeOf_Client_UI_InventoryDropToGrid
// Address:   0x0085e820  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_UI_InventoryDropToGrid: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0085e820.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_UI_InventoryDropToGrid
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __fastcall Named_CalleeOf_Named_CalleeOf_Client_UI_InventoryDropToGrid_0085e820(uint param_1,int param_2,byte param_3)



{

  int iVar1;

  int *in_EAX;

  float fVar2;

  

  iVar1 = *(int *)(param_2 + 0x508);

  fVar2 = (float)DAT_00d1e81c * (float)_DAT_00d1e510 * _DAT_00aaa6a8;

  *in_EAX = *(int *)(param_2 + 0x504) -

            (int)((float)DAT_00d1e818 * (float)_DAT_00d1e50c * _DAT_00aaa6ac) * (param_1 & 0xff);

  in_EAX[1] = iVar1 - (int)fVar2 * (uint)param_3;

  return;

}
