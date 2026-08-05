// =============================================================================
// FUN_005124a0
// -----------------------------------------------------------------------------
// Stable ID: aa_005124a0
// Address:   0x005124a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005124a0 @ 0x005124a0
// Stable ID: aa_005124a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~57 non-empty decompiler lines.
//  - Control keywords: return×11, switch×1.
//  - Notable callees: FUN_005124a0.
//  - Return sites: 11.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void FUN_005124a0(char *param_1,uint32_t /* width from decompiler */ param_2)



{

  switch(param_2) {

  case 6:

    *(uint32_t /* width from decompiler */ *)param_1 = DAT_00a32888;

    param_1[4] = DAT_00a3288c;

    return;

  default:

    *(uint32_t /* width from decompiler */ *)param_1 = DAT_00a2d820;

    param_1[4] = DAT_00a2d824;

    return;

  case 8:

    *(uint32_t /* width from decompiler */ *)param_1 = s_Gadget_00a32880._0_4_;

    *(uint16_t *)(param_1 + 4) = s_Gadget_00a32880._4_2_;

    param_1[6] = s_Gadget_00a32880[6];

    return;

  case 10:

    *(uint32_t /* width from decompiler */ *)param_1 = s_Power_Plant_00a32874._0_4_;

    *(uint32_t /* width from decompiler */ *)(param_1 + 4) = s_Power_Plant_00a32874._4_4_;

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = s_Power_Plant_00a32874._8_4_;

    return;

  case 0xc:

    *(uint32_t /* width from decompiler */ *)param_1 = s_Weapon_00a32898._0_4_;

    *(uint16_t *)(param_1 + 4) = s_Weapon_00a32898._4_2_;

    param_1[6] = s_Weapon_00a32898[6];

    return;

  case 0xe:

    *(uint32_t /* width from decompiler */ *)param_1 = s_Vehicle_00a3286c._0_4_;

    *(uint32_t /* width from decompiler */ *)(param_1 + 4) = s_Vehicle_00a3286c._4_4_;

    return;

  case 0x10:

    *(uint32_t /* width from decompiler */ *)param_1 = s_Wheel_Set_00a69970._0_4_;

    *(uint32_t /* width from decompiler */ *)(param_1 + 4) = s_Wheel_Set_00a69970._4_4_;

    *(uint16_t *)(param_1 + 8) = s_Wheel_Set_00a69970._8_2_;

    return;

  case 0x1c:

    *(uint32_t /* width from decompiler */ *)param_1 = s_Armor_00a2e6a4._0_4_;

    *(uint16_t *)(param_1 + 4) = s_Armor_00a2e6a4._4_2_;

    return;

  case 0x32:

    *(uint32_t /* width from decompiler */ *)param_1 = s_Tinkering_Kit_00a32850._0_4_;

    *(uint32_t /* width from decompiler */ *)(param_1 + 4) = s_Tinkering_Kit_00a32850._4_4_;

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = s_Tinkering_Kit_00a32850._8_4_;

    *(uint16_t *)(param_1 + 0xc) = s_Tinkering_Kit_00a32850._12_2_;

    return;

  case 0x44:

    *(uint32_t /* width from decompiler */ *)param_1 = s_Ornament_00a2e670._0_4_;

    *(uint32_t /* width from decompiler */ *)(param_1 + 4) = s_Ornament_00a2e670._4_4_;

    param_1[8] = s_Ornament_00a2e670[8];

    return;

  case 0x46:

    *(uint32_t /* width from decompiler */ *)param_1 = s_Race_Item_00a327f8._0_4_;

    *(uint32_t /* width from decompiler */ *)(param_1 + 4) = s_Race_Item_00a327f8._4_4_;

    *(uint16_t *)(param_1 + 8) = s_Race_Item_00a327f8._8_2_;

    return;

  }

}
