// =============================================================================
// Named_CalleeOf_Client_SendInventoryAddItem_004d2820
// -----------------------------------------------------------------------------
// Stable ID: aa_004d2820
// Callee of Client_SendInventoryAddItem (+1 other named callers)
// Address:   0x004d2820  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_SendInventoryAddItem: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Client_SendInventoryAddItem (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_004d0ed0, FUN_004d2820, FUN_00512160.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_SendInventoryAddItem (+1 other named callers)
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

void __thiscall Named_CalleeOf_Client_SendInventoryAddItem_004d2820(int param_1,int *param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  uint uVar1;

  int iVar2;

  

  (**(code **)(*param_2 + 0x218))(param_1);

  if ((param_2[0x58] & param_2[0x59]) == 0xffffffff) {

    uVar1 = *(uint *)(param_1 + 0xe6e0);

    iVar2 = *(int *)(param_1 + 0xe6e4);

    *(uint *)(param_1 + 0xe6e4) = iVar2 + (uint)(0xfffffffe < uVar1);

    *(uint *)(param_1 + 0xe6e0) = uVar1 + 1;

    FUN_00512160(uVar1,iVar2,1);

    (**(code **)(*param_2 + 0x2a4))(*(uint32_t /* width from decompiler */ *)(param_1 + 0xe4e8));

  }

  FUN_004d0ed0(param_2,param_2,param_3,param_4);

  iVar2 = (**(code **)(*param_2 + 0x1d4))();

  if (iVar2 != 0) {

    iVar2 = (**(code **)(*param_2 + 0x1d4))();

    *(uint8_t *)(iVar2 + 0x2ac) = 1;

  }

  return;

}
