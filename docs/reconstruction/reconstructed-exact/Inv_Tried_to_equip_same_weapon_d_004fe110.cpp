// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_004fe110, FUN_00518630, FUN_007a4480, Vehicle_AttachWeapon.
//  - Strings: "Tried to equip same weapon %d".
//  - Return sites: 2.

// =============================================================================
// Inv_Tried_to_equip_same_weapon_d_004fe110
// -----------------------------------------------------------------------------
// Stable ID: aa_004fe110
// Address:   0x004fe110  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "Tried to equip same weapon %d"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Inv_Tried_to_equip_same_weapon_d_004fe110(int param_1,int param_2,int param_3,uint32_t /* width from decompiler */ *param_4)



{

  int iVar1;

  

  iVar1 = *(int *)(*(int *)(param_1 + 0x260) + param_3 * 4);

  if ((param_2 == iVar1) && (param_2 != 0)) {

    FUN_007a4480(0,"Tried to equip same weapon %d",

                 *(uint32_t /* width from decompiler */ *)

                  (*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 0xac + param_2) + 0x34));

    return;

  }

  if (iVar1 != 0) {

    FUN_00518630(100,0,0);

    iVar1 = *(int *)(*(int *)(param_1 + 0x260) + param_3 * 4);

    (**(code **)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1) + 0x158))(0);

  }

  *param_4 = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x260) + param_3 * 4);

  Vehicle_AttachWeapon(param_2,param_3,0);

  return;

}
