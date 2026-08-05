// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: InventoryGrid_SetOwnerFlag_Inferred×2, Client_LookupObjectByTfid_Inferred, FUN_007fca10, FUN_007fdfb0, FUN_0080a020, TradeComplete_Response.
//  - Strings: "Failed on TradeComplete_Response (Get a programmer).".
//  - Return sites: 1.

// =============================================================================
// Named_Failed_on_TradeComplete_Response_Get_a_programme_0080a020
// -----------------------------------------------------------------------------
// Stable ID: aa_0080a020
// Address:   0x0080a020  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "Failed on TradeComplete_Response (Get a programmer)."
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Named_Failed_on_TradeComplete_Response_Get_a_programme_0080a020(int param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  int in_EAX;

  void *pvVar3;

  

  if (*(char *)(in_EAX + 0x18) == '\0') {

    FUN_007fdfb0(param_1,"Failed on TradeComplete_Response (Get a programmer).",0xffffffff,1,0);

  }

  iVar1 = *(int *)(param_1 + 0xe98);

  uVar2 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0xce0);

  pvVar3 = Client_LookupObjectByTfid_Inferred(1,*(uint *)(iVar1 + 0xcd8),*(uint *)(iVar1 + 0xcdc));

  if (pvVar3 != (void *)0x0) {

    *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xe98) + 0xce0) = *(uint32_t /* width from decompiler */ *)((int)pvVar3 + 0xce0);

    *(uint32_t /* width from decompiler */ *)((int)pvVar3 + 0xce0) = uVar2;

    InventoryGrid_SetOwnerFlag_Inferred(*(void **)(*(int *)(param_1 + 0xe98) + 0xce0),5);

    InventoryGrid_SetOwnerFlag_Inferred(*(void **)((int)pvVar3 + 0xce0),6);

  }

  (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(param_1 + 0xf40) + 0x1c8))(0);

  (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(param_1 + 0xf40) + 0x3c0))(0);

  FUN_007fca10();

  return;

}
