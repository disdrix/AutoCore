// =============================================================================
// Named_CalleeOf_Drive_Packing_initial_update_for_vehicle_I64_005b1290
// -----------------------------------------------------------------------------
// Stable ID: aa_005b1290
// Callee of Drive_Packing_initial_update_for_vehicle_I64
// Address:   0x005b1290  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Drive_Packing_initial_update_for_vehicle_I64: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: BitStream_writeBits×3, BitStream_writeInt×2, BitStream_writeFlag, FUN_005b1290, Object_GetRootRaceId.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Drive_Packing_initial_update_for_vehicle_I64
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

void __thiscall Named_CalleeOf_Drive_Packing_initial_update_for_vehicle_I64_005b1290(int param_1,RACE_ID_INFERRED param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  RACE_ID_INFERRED RVar3;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_8 = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x50) + 0x160);

  local_4 = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x50) + 0x164);

  BitStream_writeBits(0x40,&local_8);

  BitStream_writeFlag(*(uint8_t *)(*(int *)(param_1 + 0x50) + 0x168));

  BitStream_writeInt(*(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 0x50) + 0xa8) + 0x34),0x14);

  iVar1 = (**(code **)(**(int **)(param_1 + 0x50) + 0x244))();

  if (iVar1 < 0) {

    uVar2 = 0;

  }

  else {

    uVar2 = (**(code **)(**(int **)(param_1 + 0x50) + 0x244))();

  }

  BitStream_writeInt(uVar2,0x12);

  RVar3 = Object_GetRootRaceId(*(void **)(param_1 + 0x50));

  param_2 = RVar3;

  BitStream_writeBits(0x10,&param_2);

  param_2 = (**(code **)(**(int **)(param_1 + 0x50) + 0x290))();

  if ((short)param_2 == (short)RVar3) {

    param_2 = 0;

  }

  BitStream_writeBits(0x10,&param_2);

  return;

}
