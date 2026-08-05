// =============================================================================
// Named_CalleeOf_Client_SendInventoryAddItem_004d4790
// -----------------------------------------------------------------------------
// Stable ID: aa_004d4790
// Callee of Client_SendInventoryAddItem (+2 other named callers)
// Address:   0x004d4790  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_SendInventoryAddItem: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Client_SendInventoryAddItem (+2 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_004024d0, FUN_00405920, FUN_004bcda0, FUN_004d4790, FUN_004e15a0, FUN_004e23d0, FUN_007a4480.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_SendInventoryAddItem (+2 other named callers)
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

void Named_CalleeOf_Client_SendInventoryAddItem_004d4790(int *param_1)



{

  int iVar1;

  int iVar2;

  char cVar3;

  int iVar4;

  

  iVar1 = param_1[0x59];

  iVar2 = param_1[0x58];

  iVar4 = FUN_004e23d0();

  if ((iVar4 != 0) && (*(int *)(iVar4 + 0xc) != 0)) {

    FUN_007a4480(1,

                 "##$$##$$##$$##$$## Object CBID:%i, Geo:%s, COID:%I64d, Global?:%i, Position: %.02f, %.02f, %.02f being added to delete cue, but still in InactiveObjectsHas.\n"

                 ,*(uint32_t /* width from decompiler */ *)(param_1[0x2a] + 0x34),*(int *)(param_1[0x2a] + 0x3c) + 0x10,iVar2,

                 iVar1,(char)param_1[0x5a],(double)(float)param_1[0x20],(double)(float)param_1[0x21]

                 ,(double)(float)param_1[0x22]);

    FUN_004bcda0();

  }

  cVar3 = FUN_004e15a0();

  if (cVar3 != '\0') {

    FUN_00405920(&LAB_004cd580,param_1);

  }

  (**(code **)(*param_1 + 0x2a8))();

  FUN_004024d0(param_1);

  param_1[0x5f] = param_1[0x5f] | 2;

  return;

}
