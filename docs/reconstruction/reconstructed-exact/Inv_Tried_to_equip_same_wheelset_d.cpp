// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×6, return×3.
//  - Notable callees: FUN_007a4480×2, FUN_004fbb50, FUN_004ff510, Vehicle_SetWheelset.
//  - Strings: "Tried to equip same wheelset %d"; "Set wheelset2 of unhappy type: CBID:%d COID:%I64d".
//  - Return sites: 3.

// =============================================================================
// Inv_Tried_to_equip_same_wheelset_d
// -----------------------------------------------------------------------------
// Stable ID: aa_004ff510
// Address:   0x004ff510  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "Tried to equip same wheelset %d"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Inv_Tried_to_equip_same_wheelset_d(int param_1,int param_2,int *param_3)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  int iVar4;

  

  iVar4 = *(int *)(param_1 + 600);

  if ((param_2 == iVar4) && (param_2 != 0)) {

    FUN_007a4480(0,"Tried to equip same wheelset %d",

                 *(uint32_t /* width from decompiler */ *)

                  (*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 0xac + param_2) + 0x34));

    return;

  }

  if ((param_3 != (int *)0x0) && ((iVar4 != 0 && (*(char *)(iVar4 + 0xcc) == '\0')))) {

    *param_3 = iVar4;

  }

  iVar4 = *(int *)(param_1 + 600);

  if (iVar4 != 0) {

    if (*(int *)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 0xac + iVar4) + 0x38) != 0x10) {

      iVar1 = *(int *)(*(int *)(iVar4 + 4) + 4);

      iVar3 = iVar4 + iVar1;

      FUN_007a4480(1,"Set wheelset2 of unhappy type: CBID:%d COID:%I64d",

                   *(uint32_t /* width from decompiler */ *)(*(int *)(iVar3 + 0xac) + 0x34),*(uint32_t /* width from decompiler */ *)(iVar3 + 0x164),

                   *(uint32_t /* width from decompiler */ *)(iVar4 + 0x168 + iVar1));

    }

    iVar4 = *(int *)(param_1 + 600);

    if (iVar4 != 0) {

      iVar4 = *(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4;

    }

    FUN_004fbb50(iVar4);

    (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 600) + 4) + 4) + 4 +

                         *(int *)(param_1 + 600)) + 0x158))(0);

  }

  Vehicle_SetWheelset(param_2);

  if (param_2 != 0) {

    iVar4 = *(int *)(*(int *)(param_2 + 4) + 4);

    uVar2 = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x164 + param_2);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x62c) = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x168 + param_2);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x628) = uVar2;

    return;

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x62c) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x628) = 0xffffffff;

  return;

}
