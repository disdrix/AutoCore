// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Inv_switched_vehicles_and_no_room_005a5410
// -----------------------------------------------------------------------------
// Stable ID: aa_005a5410
// Callee of Named_CalleeOf_Inv_switched_vehicles_and_no_room_for_old_vehicl
// Address:   0x005a5410  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Inv_switched_vehicles_and_no_room_for_old_vehicl: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_005a5410.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Inv_switched_vehicles_and_no_room_for_old_vehicl
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Inv_switched_vehicles_and_no_room_005a5410(uint32_t /* width from decompiler */ *param_1)



{

  float fVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  

  fVar1 = g_flOne;

  *param_1 = &PTR_LAB_009d81d8;

  param_1[4] = 0;

  param_1[8] = 0;

  param_1[9] = 0;

  param_1[10] = 0;

  param_1[0xb] = 0;

  param_1[0xc] = 0;

  param_1[0xd] = 0;

  param_1[0xe] = 0;

  param_1[0xf] = 0;

  param_1[0x10] = fVar1;

  fVar1 = g_flMultiKillCountBlend;

  param_1[0x11] = 0;

  param_1[0x12] = 0;

  param_1[0x13] = 0;

  param_1[0x15] = fVar1;

  uVar2 = DAT_00a0f704;

  param_1[0x16] = 0;

  param_1[0x18] = 0;

  param_1[0x19] = 0;

  uVar3 = DAT_00aaa690;

  *(uint8_t *)(param_1 + 0x14) = 0;

  *(uint8_t *)((int)param_1 + 0x51) = 0;

  param_1[0x17] = uVar2;

  param_1[0x1a] = uVar3;

  return;

}
