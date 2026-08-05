// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00502180, FUN_007a4480, Vehicle_SetEquippedArmor.
//  - Strings: "Tried to equip same armor %d".
//  - Return sites: 2.

// =============================================================================
// Inv_Tried_to_equip_same_armor_d
// -----------------------------------------------------------------------------
// Stable ID: aa_00502180
// Address:   0x00502180  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "Tried to equip same armor %d"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Inv_Tried_to_equip_same_armor_d(void *param_1,void *param_2,int *param_3,char param_4)



{

  if ((param_2 == *(void **)((int)param_1 + 0x254)) && (param_2 != (void *)0x0)) {

    FUN_007a4480(0,"Tried to equip same armor %d",

                 *(uint32_t /* width from decompiler */ *)

                  (*(int *)(*(int *)(*(int *)((int)param_2 + 4) + 4) + 0xac + (int)param_2) + 0x34))

    ;

    return;

  }

  *param_3 = (int)*(void **)((int)param_1 + 0x254);

  Vehicle_SetEquippedArmor(param_1,param_2,param_4);

  return;

}
