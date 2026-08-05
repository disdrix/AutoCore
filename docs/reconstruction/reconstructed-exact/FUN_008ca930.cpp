// =============================================================================
// FUN_008ca930
// -----------------------------------------------------------------------------
// Stable ID: aa_008ca930
// Address:   0x008ca930  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008ca930 @ 0x008ca930
// Stable ID: aa_008ca930
// Embedded strings (evidence for future rename):
//   - "The Unknown %d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~217 non-empty decompiler lines.
//  - Control keywords: return×33, switch×1.
//  - Notable callees: FUN_008ca930, sprintf.
//  - Strings: "The Unknown %d".
//  - Return sites: 33.

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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ __fastcall FUN_008ca930(uint param_1)



{

  char *in_EAX;

  

  switch(param_1 & 0xff) {

  case 1:

    *(uint32_t /* width from decompiler */ *)in_EAX = s_Apocalypse__East__00a41e90._0_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 4) = s_Apocalypse__East__00a41e90._4_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 8) = s_Apocalypse__East__00a41e90._8_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc) = s_Apocalypse__East__00a41e90._12_4_;

    *(uint16_t *)(in_EAX + 0x10) = s_Apocalypse__East__00a41e90._16_2_;

    return 1;

  case 2:

    *(uint32_t /* width from decompiler */ *)in_EAX = s_Breakdown__West__00a41e7c._0_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 4) = s_Breakdown__West__00a41e7c._4_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 8) = s_Breakdown__West__00a41e7c._8_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc) = s_Breakdown__West__00a41e7c._12_4_;

    in_EAX[0x10] = s_Breakdown__West__00a41e7c[0x10];

    return 1;

  case 3:

    *(uint32_t /* width from decompiler */ *)in_EAX = s_Carnage__East__00a41e6c._0_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 4) = s_Carnage__East__00a41e6c._4_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 8) = s_Carnage__East__00a41e6c._8_4_;

    *(uint16_t *)(in_EAX + 0xc) = s_Carnage__East__00a41e6c._12_2_;

    in_EAX[0xe] = s_Carnage__East__00a41e6c[0xe];

    return 1;

  case 4:

    *(uint32_t /* width from decompiler */ *)in_EAX = s_Wastelands___RP_West__00a41ea4._0_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 4) = s_Wastelands___RP_West__00a41ea4._4_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 8) = s_Wastelands___RP_West__00a41ea4._8_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc) = s_Wastelands___RP_West__00a41ea4._12_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x10) = s_Wastelands___RP_West__00a41ea4._16_4_;

    *(uint16_t *)(in_EAX + 0x14) = s_Wastelands___RP_West__00a41ea4._20_2_;

    return 1;

  case 5:

    *(uint32_t /* width from decompiler */ *)in_EAX = s_Extinction__East__00a41e58._0_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 4) = s_Extinction__East__00a41e58._4_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 8) = s_Extinction__East__00a41e58._8_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc) = s_Extinction__East__00a41e58._12_4_;

    *(uint16_t *)(in_EAX + 0x10) = s_Extinction__East__00a41e58._16_2_;

    return 1;

  case 6:

    *(uint32_t /* width from decompiler */ *)in_EAX = s_Flashpoint__West__00a41e44._0_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 4) = s_Flashpoint__West__00a41e44._4_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 8) = s_Flashpoint__West__00a41e44._8_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc) = s_Flashpoint__West__00a41e44._12_4_;

    *(uint16_t *)(in_EAX + 0x10) = s_Flashpoint__West__00a41e44._16_2_;

    return 1;

  case 7:

    *(uint32_t /* width from decompiler */ *)in_EAX = s_Hazard__East__00a41e34._0_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 4) = s_Hazard__East__00a41e34._4_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 8) = s_Hazard__East__00a41e34._8_4_;

    *(uint16_t *)(in_EAX + 0xc) = s_Hazard__East__00a41e34._12_2_;

    return 1;

  case 8:

    *(uint32_t /* width from decompiler */ *)in_EAX = s_Isolation__West__00a41e20._0_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 4) = s_Isolation__West__00a41e20._4_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 8) = s_Isolation__West__00a41e20._8_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc) = s_Isolation__West__00a41e20._12_4_;

    in_EAX[0x10] = s_Isolation__West__00a41e20[0x10];

    return 1;

  case 9:

    *(uint32_t /* width from decompiler */ *)in_EAX = s_Obliteration__East__00a41e0c._0_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 4) = s_Obliteration__East__00a41e0c._4_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 8) = s_Obliteration__East__00a41e0c._8_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc) = s_Obliteration__East__00a41e0c._12_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x10) = s_Obliteration__East__00a41e0c._16_4_;

    return 1;

  case 10:

    *(uint32_t /* width from decompiler */ *)in_EAX = s_Meltdown__West__00a41dfc._0_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 4) = s_Meltdown__West__00a41dfc._4_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 8) = s_Meltdown__West__00a41dfc._8_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc) = s_Meltdown__West__00a41dfc._12_4_;

    return 1;

  case 0xb:

    *(uint32_t /* width from decompiler */ *)in_EAX = s_Napalm__East__00a41dec._0_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 4) = s_Napalm__East__00a41dec._4_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 8) = s_Napalm__East__00a41dec._8_4_;

    *(uint16_t *)(in_EAX + 0xc) = s_Napalm__East__00a41dec._12_2_;

    return 1;

  case 0xc:

    *(uint32_t /* width from decompiler */ *)in_EAX = s_Shambles__West__00a41ddc._0_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 4) = s_Shambles__West__00a41ddc._4_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 8) = s_Shambles__West__00a41ddc._8_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc) = s_Shambles__West__00a41ddc._12_4_;

    return 1;

  case 0xd:

    *(uint32_t /* width from decompiler */ *)in_EAX = s_Radiation__East__00a41dc8._0_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 4) = s_Radiation__East__00a41dc8._4_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 8) = s_Radiation__East__00a41dc8._8_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc) = s_Radiation__East__00a41dc8._12_4_;

    in_EAX[0x10] = s_Radiation__East__00a41dc8[0x10];

    return 1;

  case 0xe:

    *(uint32_t /* width from decompiler */ *)in_EAX = s_Underground__West__00a41db4._0_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 4) = s_Underground__West__00a41db4._4_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 8) = s_Underground__West__00a41db4._8_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc) = s_Underground__West__00a41db4._12_4_;

    *(uint16_t *)(in_EAX + 0x10) = s_Underground__West__00a41db4._16_2_;

    in_EAX[0x12] = s_Underground__West__00a41db4[0x12];

    return 1;

  case 0xf:

    *(uint32_t /* width from decompiler */ *)in_EAX = s_Damnation__East__00a41da0._0_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 4) = s_Damnation__East__00a41da0._4_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 8) = s_Damnation__East__00a41da0._8_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc) = s_Damnation__East__00a41da0._12_4_;

    in_EAX[0x10] = s_Damnation__East__00a41da0[0x10];

    return 1;

  case 0x10:

    *(uint32_t /* width from decompiler */ *)in_EAX = s_Desolation__EN__00a41d90._0_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 4) = s_Desolation__EN__00a41d90._4_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 8) = s_Desolation__EN__00a41d90._8_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc) = s_Desolation__EN__00a41d90._12_4_;

    return 1;

  case 0x11:

    *(uint32_t /* width from decompiler */ *)in_EAX = _DAT_00a41d84;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 4) = s_dland__DE__00a41d85._3_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 8) = s_dland__DE__00a41d85._7_4_;

    return 1;

  case 0x12:

    *(uint32_t /* width from decompiler */ *)in_EAX = s_Cataclysme__FR__00a41d74._0_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 4) = s_Cataclysme__FR__00a41d74._4_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 8) = s_Cataclysme__FR__00a41d74._8_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc) = s_Cataclysme__FR__00a41d74._12_4_;

    return 1;

  case 0x13:

    *(uint32_t /* width from decompiler */ *)in_EAX = s_Downfall__UK__00a41d64._0_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 4) = s_Downfall__UK__00a41d64._4_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 8) = s_Downfall__UK__00a41d64._8_4_;

    *(uint16_t *)(in_EAX + 0xc) = s_Downfall__UK__00a41d64._12_2_;

    return 1;

  case 0x14:

    *(uint32_t /* width from decompiler */ *)in_EAX = s_Kernschmelze__DE__00a41d50._0_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 4) = s_Kernschmelze__DE__00a41d50._4_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 8) = s_Kernschmelze__DE__00a41d50._8_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc) = s_Kernschmelze__DE__00a41d50._12_4_;

    *(uint16_t *)(in_EAX + 0x10) = s_Kernschmelze__DE__00a41d50._16_2_;

    return 1;

  case 0x15:

    *(uint32_t /* width from decompiler */ *)in_EAX = s_Contamination__FR__00a41d3c._0_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 4) = s_Contamination__FR__00a41d3c._4_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 8) = s_Contamination__FR__00a41d3c._8_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc) = s_Contamination__FR__00a41d3c._12_4_;

    *(uint16_t *)(in_EAX + 0x10) = s_Contamination__FR__00a41d3c._16_2_;

    in_EAX[0x12] = s_Contamination__FR__00a41d3c[0x12];

    return 1;

  case 0x16:

    *(uint32_t /* width from decompiler */ *)in_EAX = s_Atomic_00a41d34._0_4_;

    *(uint16_t *)(in_EAX + 4) = s_Atomic_00a41d34._4_2_;

    in_EAX[6] = s_Atomic_00a41d34[6];

    return 1;

  case 0x17:

    *(uint32_t /* width from decompiler */ *)in_EAX = s_Ruination_00a41d28._0_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 4) = s_Ruination_00a41d28._4_4_;

    *(uint16_t *)(in_EAX + 8) = s_Ruination_00a41d28._8_2_;

    return 1;

  case 0x18:

    *(uint32_t /* width from decompiler */ *)in_EAX = s_Wreckage_00a41d1c._0_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 4) = s_Wreckage_00a41d1c._4_4_;

    in_EAX[8] = s_Wreckage_00a41d1c[8];

    return 1;

  case 0x19:

    *(uint32_t /* width from decompiler */ *)in_EAX = s_ND_Internal_00a41d10._0_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 4) = s_ND_Internal_00a41d10._4_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 8) = s_ND_Internal_00a41d10._8_4_;

    return 1;

  case 0x1a:

    *(uint32_t /* width from decompiler */ *)in_EAX = s_ND_Test1_00a41d04._0_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 4) = s_ND_Test1_00a41d04._4_4_;

    in_EAX[8] = s_ND_Test1_00a41d04[8];

    return 1;

  case 0x1b:

    *(uint32_t /* width from decompiler */ *)in_EAX = DAT_00a41cfc;

    *(uint16_t *)(in_EAX + 4) = DAT_00a41d00;

    return 1;

  case 0x1c:

    *(uint32_t /* width from decompiler */ *)in_EAX = s_NC_Staging_00a41cf0._0_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 4) = s_NC_Staging_00a41cf0._4_4_;

    *(uint16_t *)(in_EAX + 8) = s_NC_Staging_00a41cf0._8_2_;

    in_EAX[10] = s_NC_Staging_00a41cf0[10];

    return 1;

  case 0x1d:

    *(uint32_t /* width from decompiler */ *)in_EAX = s_US_Public_Test_Server_00a41cd8._0_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 4) = s_US_Public_Test_Server_00a41cd8._4_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 8) = s_US_Public_Test_Server_00a41cd8._8_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc) = s_US_Public_Test_Server_00a41cd8._12_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x10) = s_US_Public_Test_Server_00a41cd8._16_4_;

    *(uint16_t *)(in_EAX + 0x14) = s_US_Public_Test_Server_00a41cd8._20_2_;

    return 1;

  case 0x1e:

    *(uint32_t /* width from decompiler */ *)in_EAX = s_The_Proving_Grounds_00a41cc0._0_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 4) = s_The_Proving_Grounds_00a41cc0._4_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 8) = s_The_Proving_Grounds_00a41cc0._8_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc) = s_The_Proving_Grounds_00a41cc0._12_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x10) = s_The_Proving_Grounds_00a41cc0._16_4_;

    in_EAX[0x14] = s_The_Proving_Grounds_00a41cc0[0x14];

    return 1;

  case 0x1f:

    *(uint32_t /* width from decompiler */ *)in_EAX = s_Public_Test_Server_00a41cac._0_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 4) = s_Public_Test_Server_00a41cac._4_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 8) = s_Public_Test_Server_00a41cac._8_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc) = s_Public_Test_Server_00a41cac._12_4_;

    *(uint16_t *)(in_EAX + 0x10) = s_Public_Test_Server_00a41cac._16_2_;

    in_EAX[0x12] = s_Public_Test_Server_00a41cac[0x12];

    return 1;

  case 0x20:

    *(uint32_t /* width from decompiler */ *)in_EAX = s_Outpost_Battle_00a41c9c._0_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 4) = s_Outpost_Battle_00a41c9c._4_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 8) = s_Outpost_Battle_00a41c9c._8_4_;

    *(uint16_t *)(in_EAX + 0xc) = s_Outpost_Battle_00a41c9c._12_2_;

    in_EAX[0xe] = s_Outpost_Battle_00a41c9c[0xe];

    return 1;

  default:

    sprintf(in_EAX,"The Unknown %d",param_1 & 0xff);

    return 1;

  }

}
