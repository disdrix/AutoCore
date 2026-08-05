// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_005cc5b0, FUN_005d1990, FUN_005d7bb0, FUN_007a4480.
//  - Strings: "%d had no vehicle, disabled map: %s, spawn: %I64d".
//  - Return sites: 1.

// =============================================================================
// Drive_d_had_no_vehicle_disabled_map_s_spawn_I64d
// -----------------------------------------------------------------------------
// Stable ID: aa_005d7bb0
// Address:   0x005d7bb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "%d had no vehicle, disabled map: %s, spawn: %I64d"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ * __thiscall Drive_d_had_no_vehicle_disabled_map_s_spawn_I64d(uint32_t /* width from decompiler */ *param_1,int param_2)



{

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a71ab;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_005d1990(param_2);

  *param_1 = &PTR_FUN_009db02c;

  *(uint8_t *)(param_1 + 0x2c) = 0;

  *(uint8_t *)((int)param_1 + 0xb1) = 3;

  *(uint8_t *)((int)param_1 + 0xb2) = 0;

  *(uint8_t *)((int)param_1 + 0xb3) = 0;

  param_1[0x2d] = 0;

  *(uint8_t *)(param_1 + 0x2e) = 0;

  iVar1 = *(int *)(param_2 + 0x250);

  local_4 = 0;

  param_1[0x2f] = iVar1;

  if (iVar1 == 0) {

    iVar1 = *(int *)(param_2 + 600);

    if (iVar1 == 0) {

      uVar3 = 0xffffffff;

      uVar4 = 0xffffffff;

    }

    else {

      iVar2 = *(int *)(*(int *)(iVar1 + 4) + 4);

      uVar3 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x164 + iVar1);

      uVar4 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x168 + iVar1);

    }

    iVar1 = *(int *)(*(int *)(param_2 + 4) + 4);

    FUN_007a4480(1,"%d had no vehicle, disabled map: %s, spawn: %I64d",

                 *(uint32_t /* width from decompiler */ *)(*(int *)(iVar1 + 0xac + param_2) + 0x34),

                 *(int *)(iVar1 + 0xa8 + param_2) + 0xb4,uVar3,uVar4);

    FUN_005cc5b0(1,1);

  }

  param_1[9] = 0x96;

  ExceptionList = local_c;

  return param_1;

}
