// READABILITY (auto CF):
//  - Body size: ~1 non-empty decompiler lines.

// =============================================================================
// Client_InitActionDisplayNames
// -----------------------------------------------------------------------------
// Stable ID: aa_007f7570
// Address:   0x007f7570  (autoassault.exe, image base 0x400000)
// System:    input-drive-control (ActionMap display-name table)
// Generated: 2026-07-23 from force_decompile (raw previously failed)
// Refined:   2026-07-23 human-refine — sectioned name groups; drive-axis names
//            called out (Accelerate/Reverse/Steer L/R/Soft/Brake).
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Runtime / differential: OPEN.
//
// Convention: ActionMap object pointer arrives in EAX (decomp in_EAX -> pActionMap).
// Slot stride: 0x34. Display-name field starts at slot-relative offsets used below.
//
// Called from: Client_ActionMap_Init @ 0x007f9110 (after zero-fill tables).
// Sibling:     Client_InitDefaultKeybinds @ 0x007f8720 (DIK defaults into same table).
// Consumers:   DriveControlTick reads held flags; UI shows these strings.
//
// Drive display-name offsets (ActionMap base):
//   +0x27d Accelerate · +0x2b1 Reverse · +0x2e5 Steer Left · +0x319 Steer Right
//   +0x34d Steer Left Soft · +0x381 Steer Right Soft · +0x3b5 Brake
// =============================================================================

/*
 * Behavioral notes:
 * - Pure string copies into ActionMap name fields; no key codes written here.
 * - String literals may appear as s_* globals or inline quotes (decomp variance).
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN -> fixed-width integers; in_EAX -> pActionMap.
 * - Section banners only; control flow and store order preserved from decompile.
 */

void Client_InitActionDisplayNames(void)

{
  int pActionMap; /* ActionMap* via EAX (caller/register) */
  int iVar1;
  char *pcVar2;
  uint32_t *puVar3;
  char *pcVar4;
  

  // SECTION 1: Core UI / system action names (Slash Command, Screenshot, windows)
  *(uint32_t *)(pActionMap + 0x41) = s_Slash_Command_00a85884._0_4_;
  *(uint32_t *)(pActionMap + 0x45) = s_Slash_Command_00a85884._4_4_;
  *(uint32_t *)(pActionMap + 0x49) = s_Slash_Command_00a85884._8_4_;
  *(uint16_t *)(pActionMap + 0x4d) = s_Slash_Command_00a85884._12_2_;
  *(uint32_t *)(pActionMap + 0x75) = s_Screenshot_00a85878._0_4_;
  *(uint32_t *)(pActionMap + 0x79) = s_Screenshot_00a85878._4_4_;
  *(uint16_t *)(pActionMap + 0x7d) = s_Screenshot_00a85878._8_2_;
  *(char *)(pActionMap + 0x7f) = s_Screenshot_00a85878[10];
  *(uint32_t *)(pActionMap + 0x5f1) = s_Toggle_Inventory_00a85864._0_4_;
  *(uint32_t *)(pActionMap + 0x5f5) = s_Toggle_Inventory_00a85864._4_4_;
  *(uint32_t *)(pActionMap + 0x5f9) = s_Toggle_Inventory_00a85864._8_4_;
  *(uint32_t *)(pActionMap + 0x5fd) = s_Toggle_Inventory_00a85864._12_4_;
  *(char *)(pActionMap + 0x601) = s_Toggle_Inventory_00a85864[0x10];
  pcVar2 = "Toggle Mission Inventory";
  pcVar4 = (char *)(pActionMap + 0x625);
  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
    *(uint32_t *)pcVar4 = *(uint32_t *)pcVar2;
    pcVar2 = pcVar2 + 4;
    pcVar4 = pcVar4 + 4;
  }
  *pcVar4 = *pcVar2;
  pcVar2 = "Toggle Character Profile";
  pcVar4 = (char *)(pActionMap + 0x6c1);
  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
    *(uint32_t *)pcVar4 = *(uint32_t *)pcVar2;
    pcVar2 = pcVar2 + 4;
    pcVar4 = pcVar4 + 4;
  }
  *pcVar4 = *pcVar2;
  *(uint32_t *)(pActionMap + 0x68d) = s_Toggle_Locker_00a8581c._0_4_;
  *(uint32_t *)(pActionMap + 0x691) = s_Toggle_Locker_00a8581c._4_4_;
  *(uint32_t *)(pActionMap + 0x695) = s_Toggle_Locker_00a8581c._8_4_;
  *(uint16_t *)(pActionMap + 0x699) = s_Toggle_Locker_00a8581c._12_2_;
  *(uint32_t *)(pActionMap + 0x6f5) = s_Toggle_Medals_00a8580c._0_4_;
  *(uint32_t *)(pActionMap + 0x6f9) = s_Toggle_Medals_00a8580c._4_4_;
  *(uint32_t *)(pActionMap + 0x6fd) = s_Toggle_Medals_00a8580c._8_4_;
  *(uint16_t *)(pActionMap + 0x701) = s_Toggle_Medals_00a8580c._12_2_;
  *(uint32_t *)(pActionMap + 0x729) = s_Toggle_Skill_Trees_00a857f8._0_4_;
  *(uint32_t *)(pActionMap + 0x72d) = s_Toggle_Skill_Trees_00a857f8._4_4_;
  *(uint32_t *)(pActionMap + 0x731) = s_Toggle_Skill_Trees_00a857f8._8_4_;
  *(uint32_t *)(pActionMap + 0x735) = s_Toggle_Skill_Trees_00a857f8._12_4_;
  *(uint16_t *)(pActionMap + 0x739) = s_Toggle_Skill_Trees_00a857f8._16_2_;
  *(char *)(pActionMap + 0x73b) = s_Toggle_Skill_Trees_00a857f8[0x12];
  pcVar2 = "Toggle Research Window";
  puVar3 = (uint32_t *)(pActionMap + 0x75d);
  for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *(uint32_t *)pcVar2;
    pcVar2 = pcVar2 + 4;
    puVar3 = puVar3 + 1;
  }
  *(uint16_t *)puVar3 = *(uint16_t *)pcVar2;
  *(char *)((int)puVar3 + 2) = pcVar2[2];
  pcVar2 = "Toggle Memorization Window";
  puVar3 = (uint32_t *)(pActionMap + 0x7c5);
  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *(uint32_t *)pcVar2;
    pcVar2 = pcVar2 + 4;
    puVar3 = puVar3 + 1;
  }
  *(uint16_t *)puVar3 = *(uint16_t *)pcVar2;
  *(char *)((int)puVar3 + 2) = pcVar2[2];
  *(uint32_t *)(pActionMap + 0x7f9) = s_Toggle_Help_Window_00a857b0._0_4_;
  *(uint32_t *)(pActionMap + 0x7fd) = s_Toggle_Help_Window_00a857b0._4_4_;
  *(uint32_t *)(pActionMap + 0x801) = s_Toggle_Help_Window_00a857b0._8_4_;
  *(uint32_t *)(pActionMap + 0x805) = s_Toggle_Help_Window_00a857b0._12_4_;
  *(uint16_t *)(pActionMap + 0x809) = s_Toggle_Help_Window_00a857b0._16_2_;
  *(char *)(pActionMap + 0x80b) = s_Toggle_Help_Window_00a857b0[0x12];
  pcVar2 = "Toggle Discipline Tree";
  puVar3 = (uint32_t *)(pActionMap + 0x791);
  for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *(uint32_t *)pcVar2;
    pcVar2 = pcVar2 + 4;
    puVar3 = puVar3 + 1;
  }
  *(uint16_t *)puVar3 = *(uint16_t *)pcVar2;
  *(char *)((int)puVar3 + 2) = pcVar2[2];
  pcVar2 = "Toggle Mission Journal";
  puVar3 = (uint32_t *)(pActionMap + 0x82d);
  for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *(uint32_t *)pcVar2;
    pcVar2 = pcVar2 + 4;
    puVar3 = puVar3 + 1;
  }
  *(uint16_t *)puVar3 = *(uint16_t *)pcVar2;
  *(char *)((int)puVar3 + 2) = pcVar2[2];
  *(uint32_t *)(pActionMap + 0x861) = s_Toggle_Trade_00a85770._0_4_;
  *(uint32_t *)(pActionMap + 0x865) = s_Toggle_Trade_00a85770._4_4_;
  *(uint32_t *)(pActionMap + 0x869) = s_Toggle_Trade_00a85770._8_4_;
  *(char *)(pActionMap + 0x86d) = s_Toggle_Trade_00a85770[0xc];
  *(uint32_t *)(pActionMap + 0x659) = s_Toggle_Vehicle_Window_00a85758._0_4_;
  *(uint32_t *)(pActionMap + 0x65d) = s_Toggle_Vehicle_Window_00a85758._4_4_;
  *(uint32_t *)(pActionMap + 0x661) = s_Toggle_Vehicle_Window_00a85758._8_4_;
  *(uint32_t *)(pActionMap + 0x665) = s_Toggle_Vehicle_Window_00a85758._12_4_;
  *(uint32_t *)(pActionMap + 0x669) = s_Toggle_Vehicle_Window_00a85758._16_4_;
  *(uint16_t *)(pActionMap + 0x66d) = s_Toggle_Vehicle_Window_00a85758._20_2_;
  *(uint32_t *)(pActionMap + 0x895) = s_Toggle_Objective_Window_00a85740._0_4_;
  *(uint32_t *)(pActionMap + 0x899) = s_Toggle_Objective_Window_00a85740._4_4_;
  *(uint32_t *)(pActionMap + 0x89d) = s_Toggle_Objective_Window_00a85740._8_4_;
  *(uint32_t *)(pActionMap + 0x8a1) = s_Toggle_Objective_Window_00a85740._12_4_;
  *(uint32_t *)(pActionMap + 0x8a5) = s_Toggle_Objective_Window_00a85740._16_4_;
  *(uint32_t *)(pActionMap + 0x8a9) = s_Toggle_Objective_Window_00a85740._20_4_;
  *(uint32_t *)(pActionMap + 0x8c9) = s_Toggle_World_Map_00a8572c._0_4_;
  *(uint32_t *)(pActionMap + 0x8cd) = s_Toggle_World_Map_00a8572c._4_4_;
  *(uint32_t *)(pActionMap + 0x8d1) = s_Toggle_World_Map_00a8572c._8_4_;
  *(uint32_t *)(pActionMap + 0x8d5) = s_Toggle_World_Map_00a8572c._12_4_;
  *(char *)(pActionMap + 0x8d9) = s_Toggle_World_Map_00a8572c[0x10];
  *(uint32_t *)(pActionMap + 0x8fd) = s_Toggle_Macro_Window_00a85718._0_4_;
  *(uint32_t *)(pActionMap + 0x901) = s_Toggle_Macro_Window_00a85718._4_4_;
  *(uint32_t *)(pActionMap + 0x905) = s_Toggle_Macro_Window_00a85718._8_4_;
  *(uint32_t *)(pActionMap + 0x909) = s_Toggle_Macro_Window_00a85718._12_4_;
  *(uint32_t *)(pActionMap + 0x90d) = s_Toggle_Macro_Window_00a85718._16_4_;
  *(uint32_t *)(pActionMap + 0x931) = s_Toggle_Friends_Window_00a85700._0_4_;
  *(uint32_t *)(pActionMap + 0x935) = s_Toggle_Friends_Window_00a85700._4_4_;
  *(uint32_t *)(pActionMap + 0x939) = s_Toggle_Friends_Window_00a85700._8_4_;
  *(uint32_t *)(pActionMap + 0x93d) = s_Toggle_Friends_Window_00a85700._12_4_;
  *(uint32_t *)(pActionMap + 0x941) = s_Toggle_Friends_Window_00a85700._16_4_;
  *(uint16_t *)(pActionMap + 0x945) = s_Toggle_Friends_Window_00a85700._20_2_;
  pcVar2 = "Toggle Friends Details Window";
  puVar3 = (uint32_t *)(pActionMap + 0x965);
  for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *(uint32_t *)pcVar2;
    pcVar2 = pcVar2 + 4;
    puVar3 = puVar3 + 1;
  }
  *(uint16_t *)puVar3 = *(uint16_t *)pcVar2;
  *(uint32_t *)(pActionMap + 0x999) = s_Toggle_Clan_Window_00a856cc._0_4_;
  *(uint32_t *)(pActionMap + 0x99d) = s_Toggle_Clan_Window_00a856cc._4_4_;
  *(uint32_t *)(pActionMap + 0x9a1) = s_Toggle_Clan_Window_00a856cc._8_4_;
  *(uint32_t *)(pActionMap + 0x9a5) = s_Toggle_Clan_Window_00a856cc._12_4_;
  *(uint16_t *)(pActionMap + 0x9a9) = s_Toggle_Clan_Window_00a856cc._16_2_;
  *(char *)(pActionMap + 0x9ab) = s_Toggle_Clan_Window_00a856cc[0x12];
  pcVar2 = "Toggle Clan Details Window";
  puVar3 = (uint32_t *)(pActionMap + 0x9cd);
  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *(uint32_t *)pcVar2;
    pcVar2 = pcVar2 + 4;
    puVar3 = puVar3 + 1;
  }
  *(uint16_t *)puVar3 = *(uint16_t *)pcVar2;
  *(char *)((int)puVar3 + 2) = pcVar2[2];
  *(uint32_t *)(pActionMap + 0xa01) = s_Toggle_Enemies_Window_00a85698._0_4_;
  *(uint32_t *)(pActionMap + 0xa05) = s_Toggle_Enemies_Window_00a85698._4_4_;
  *(uint32_t *)(pActionMap + 0xa09) = s_Toggle_Enemies_Window_00a85698._8_4_;
  *(uint32_t *)(pActionMap + 0xa0d) = s_Toggle_Enemies_Window_00a85698._12_4_;
  *(uint32_t *)(pActionMap + 0xa11) = s_Toggle_Enemies_Window_00a85698._16_4_;
  *(uint16_t *)(pActionMap + 0xa15) = s_Toggle_Enemies_Window_00a85698._20_2_;
  *(uint32_t *)(pActionMap + 0xa9d) = s_Toggle_HUD_Chat_00a85688._0_4_;
  *(uint32_t *)(pActionMap + 0xaa1) = s_Toggle_HUD_Chat_00a85688._4_4_;
  *(uint32_t *)(pActionMap + 0xaa5) = s_Toggle_HUD_Chat_00a85688._8_4_;
  *(uint32_t *)(pActionMap + 0xaa9) = s_Toggle_HUD_Chat_00a85688._12_4_;
  *(uint32_t *)(pActionMap + 0xad1) = s_Toggle_HUD_Convoy_00a85674._0_4_;
  *(uint32_t *)(pActionMap + 0xad5) = s_Toggle_HUD_Convoy_00a85674._4_4_;
  *(uint32_t *)(pActionMap + 0xad9) = s_Toggle_HUD_Convoy_00a85674._8_4_;
  *(uint32_t *)(pActionMap + 0xadd) = s_Toggle_HUD_Convoy_00a85674._12_4_;
  *(uint16_t *)(pActionMap + 0xae1) = s_Toggle_HUD_Convoy_00a85674._16_2_;
  *(uint32_t *)(pActionMap + 0xb05) = s_Toggle_HUD_Minimap_00a85660._0_4_;
  *(uint32_t *)(pActionMap + 0xb09) = s_Toggle_HUD_Minimap_00a85660._4_4_;
  *(uint32_t *)(pActionMap + 0xb0d) = s_Toggle_HUD_Minimap_00a85660._8_4_;
  *(uint32_t *)(pActionMap + 0xb11) = s_Toggle_HUD_Minimap_00a85660._12_4_;
  *(uint16_t *)(pActionMap + 0xb15) = s_Toggle_HUD_Minimap_00a85660._16_2_;
  *(char *)(pActionMap + 0xb17) = s_Toggle_HUD_Minimap_00a85660[0x12];
  *(uint32_t *)(pActionMap + 0xb6d) = s_Toggle_HUD_Gauges_00a8564c._0_4_;
  *(uint32_t *)(pActionMap + 0xb71) = s_Toggle_HUD_Gauges_00a8564c._4_4_;
  *(uint32_t *)(pActionMap + 0xb75) = s_Toggle_HUD_Gauges_00a8564c._8_4_;
  *(uint32_t *)(pActionMap + 0xb79) = s_Toggle_HUD_Gauges_00a8564c._12_4_;
  *(uint16_t *)(pActionMap + 0xb7d) = s_Toggle_HUD_Gauges_00a8564c._16_2_;
  *(uint32_t *)(pActionMap + 0xba1) = s_Toggle_HUD_Quickbar_00a85638._0_4_;
  *(uint32_t *)(pActionMap + 0xba5) = s_Toggle_HUD_Quickbar_00a85638._4_4_;
  *(uint32_t *)(pActionMap + 0xba9) = s_Toggle_HUD_Quickbar_00a85638._8_4_;
  *(uint32_t *)(pActionMap + 0xbad) = s_Toggle_HUD_Quickbar_00a85638._12_4_;
  *(uint32_t *)(pActionMap + 0xbb1) = s_Toggle_HUD_Quickbar_00a85638._16_4_;
  pcVar2 = "Toggle HUD Speedometer";
  puVar3 = (uint32_t *)(pActionMap + 0xbd5);
  for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *(uint32_t *)pcVar2;
    pcVar2 = pcVar2 + 4;
    puVar3 = puVar3 + 1;
  }
  *(uint16_t *)puVar3 = *(uint16_t *)pcVar2;
  *(char *)((int)puVar3 + 2) = pcVar2[2];
  *(uint32_t *)(pActionMap + 0xc09) = s_Toggle_HUD_Battle_Modes_00a85608._0_4_;
  *(uint32_t *)(pActionMap + 0xc0d) = s_Toggle_HUD_Battle_Modes_00a85608._4_4_;
  *(uint32_t *)(pActionMap + 0xc11) = s_Toggle_HUD_Battle_Modes_00a85608._8_4_;
  *(uint32_t *)(pActionMap + 0xc15) = s_Toggle_HUD_Battle_Modes_00a85608._12_4_;
  *(uint32_t *)(pActionMap + 0xc19) = s_Toggle_HUD_Battle_Modes_00a85608._16_4_;
  *(uint32_t *)(pActionMap + 0xc1d) = s_Toggle_HUD_Battle_Modes_00a85608._20_4_;
  pcVar2 = "Toggle HUD Summon Control";
  puVar3 = (uint32_t *)(pActionMap + 0xc3d);
  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *(uint32_t *)pcVar2;
    pcVar2 = pcVar2 + 4;
    puVar3 = puVar3 + 1;
  }
  *(uint16_t *)puVar3 = *(uint16_t *)pcVar2;
  *(uint32_t *)(pActionMap + 0xc71) = s_Toggle_HUD_All_00a855dc._0_4_;
  *(uint32_t *)(pActionMap + 0xc75) = s_Toggle_HUD_All_00a855dc._4_4_;
  *(uint32_t *)(pActionMap + 0xc79) = s_Toggle_HUD_All_00a855dc._8_4_;
  *(uint16_t *)(pActionMap + 0xc7d) = s_Toggle_HUD_All_00a855dc._12_2_;
  *(char *)(pActionMap + 0xc7f) = s_Toggle_HUD_All_00a855dc[0xe];
  *(uint32_t *)(pActionMap + 0x10b5) = s_Toggle_Player_Names_00a855c8._0_4_;
  *(uint32_t *)(pActionMap + 0x10b9) = s_Toggle_Player_Names_00a855c8._4_4_;
  *(uint32_t *)(pActionMap + 0x10bd) = s_Toggle_Player_Names_00a855c8._8_4_;
  *(uint32_t *)(pActionMap + 0x10c1) = s_Toggle_Player_Names_00a855c8._12_4_;
  *(uint32_t *)(pActionMap + 0x10c5) = s_Toggle_Player_Names_00a855c8._16_4_;
  *(uint32_t *)(pActionMap + 0x10e9) = s_Expand_Hide_Chat_00a855b4._0_4_;
  *(uint32_t *)(pActionMap + 0x10ed) = s_Expand_Hide_Chat_00a855b4._4_4_;
  *(uint32_t *)(pActionMap + 0x10f1) = s_Expand_Hide_Chat_00a855b4._8_4_;
  *(uint32_t *)(pActionMap + 0x10f5) = s_Expand_Hide_Chat_00a855b4._12_4_;
  *(char *)(pActionMap + 0x10f9) = s_Expand_Hide_Chat_00a855b4[0x10];
  *(uint32_t *)(pActionMap + 0x111d) = s_Toggle_TacArc_Display_00a8559c._0_4_;
  *(uint32_t *)(pActionMap + 0x1121) = s_Toggle_TacArc_Display_00a8559c._4_4_;
  *(uint32_t *)(pActionMap + 0x1125) = s_Toggle_TacArc_Display_00a8559c._8_4_;
  *(uint32_t *)(pActionMap + 0x1129) = s_Toggle_TacArc_Display_00a8559c._12_4_;
  *(uint32_t *)(pActionMap + 0x112d) = s_Toggle_TacArc_Display_00a8559c._16_4_;
  *(uint16_t *)(pActionMap + 0x1131) = s_Toggle_TacArc_Display_00a8559c._20_2_;
  *(uint32_t *)(pActionMap + 0x1151) = s_Activate_Hazard_Mode_00a43a34._0_4_;
  *(uint32_t *)(pActionMap + 0x1155) = s_Activate_Hazard_Mode_00a43a34._4_4_;
  *(uint32_t *)(pActionMap + 0x1159) = s_Activate_Hazard_Mode_00a43a34._8_4_;
  *(uint32_t *)(pActionMap + 0x115d) = s_Activate_Hazard_Mode_00a43a34._12_4_;
  *(uint32_t *)(pActionMap + 0x1161) = s_Activate_Hazard_Mode_00a43a34._16_4_;
  *(char *)(pActionMap + 0x1165) = s_Activate_Hazard_Mode_00a43a34[0x14];
  *(uint32_t *)(pActionMap + 0x11b9) = s_Close_All_UI_00a8558c._0_4_;
  *(uint32_t *)(pActionMap + 0x11bd) = s_Close_All_UI_00a8558c._4_4_;
  *(uint32_t *)(pActionMap + 0x11c1) = s_Close_All_UI_00a8558c._8_4_;
  *(char *)(pActionMap + 0x11c5) = s_Close_All_UI_00a8558c[0xc];
  *(uint32_t *)(pActionMap + 0x1a41) = s_Toggle_Voice_Chat_00a85578._0_4_;
  *(uint32_t *)(pActionMap + 0x1a45) = s_Toggle_Voice_Chat_00a85578._4_4_;
  *(uint32_t *)(pActionMap + 0x1a49) = s_Toggle_Voice_Chat_00a85578._8_4_;
  *(uint32_t *)(pActionMap + 0x1a4d) = s_Toggle_Voice_Chat_00a85578._12_4_;
  *(uint16_t *)(pActionMap + 0x1a51) = s_Toggle_Voice_Chat_00a85578._16_2_;
  *(uint32_t *)(pActionMap + 0x1a75) = s_Toggle_Battle_Summary_00a85560._0_4_;
  *(uint32_t *)(pActionMap + 0x1a79) = s_Toggle_Battle_Summary_00a85560._4_4_;
  *(uint32_t *)(pActionMap + 0x1a7d) = s_Toggle_Battle_Summary_00a85560._8_4_;
  *(uint32_t *)(pActionMap + 0x1a81) = s_Toggle_Battle_Summary_00a85560._12_4_;
  *(uint32_t *)(pActionMap + 0x1a85) = s_Toggle_Battle_Summary_00a85560._16_4_;
  *(uint16_t *)(pActionMap + 0x1a89) = s_Toggle_Battle_Summary_00a85560._20_2_;
  *(uint32_t *)(pActionMap + 0x589) = s_Autorun_00a85558._0_4_;
  *(uint32_t *)(pActionMap + 0x58d) = s_Autorun_00a85558._4_4_;
  *(uint32_t *)(pActionMap + 0x4b9) = s_Activate_00a8554c._0_4_;
  *(uint32_t *)(pActionMap + 0x4bd) = s_Activate_00a8554c._4_4_;
  *(char *)(pActionMap + 0x4c1) = s_Activate_00a8554c[8];
  *(uint32_t *)(pActionMap + 0x1185) = s_Toggle_Item_Names_00a85538._0_4_;
  *(uint32_t *)(pActionMap + 0x1189) = s_Toggle_Item_Names_00a85538._4_4_;
  *(uint32_t *)(pActionMap + 0x118d) = s_Toggle_Item_Names_00a85538._8_4_;
  *(uint32_t *)(pActionMap + 0x1191) = s_Toggle_Item_Names_00a85538._12_4_;
  *(uint16_t *)(pActionMap + 0x1195) = s_Toggle_Item_Names_00a85538._16_2_;

  // SECTION 2: QuickBar 1-10 + QuickBarPage 1-10 display names
  *(uint32_t *)(pActionMap + 0xca5) = s_QuickBar_1_00a8552c._0_4_;
  *(uint32_t *)(pActionMap + 0xca9) = s_QuickBar_1_00a8552c._4_4_;
  *(uint16_t *)(pActionMap + 0xcad) = s_QuickBar_1_00a8552c._8_2_;
  *(char *)(pActionMap + 0xcaf) = s_QuickBar_1_00a8552c[10];
  *(uint32_t *)(pActionMap + 0xcd9) = s_QuickBar_2_00a85520._0_4_;
  *(uint32_t *)(pActionMap + 0xcdd) = s_QuickBar_2_00a85520._4_4_;
  *(uint16_t *)(pActionMap + 0xce1) = s_QuickBar_2_00a85520._8_2_;
  *(char *)(pActionMap + 0xce3) = s_QuickBar_2_00a85520[10];
  *(uint32_t *)(pActionMap + 0xd0d) = s_QuickBar_3_00a85514._0_4_;
  *(uint32_t *)(pActionMap + 0xd11) = s_QuickBar_3_00a85514._4_4_;
  *(uint16_t *)(pActionMap + 0xd15) = s_QuickBar_3_00a85514._8_2_;
  *(char *)(pActionMap + 0xd17) = s_QuickBar_3_00a85514[10];
  *(uint32_t *)(pActionMap + 0xd41) = s_QuickBar_4_00a85508._0_4_;
  *(uint32_t *)(pActionMap + 0xd45) = s_QuickBar_4_00a85508._4_4_;
  *(uint16_t *)(pActionMap + 0xd49) = s_QuickBar_4_00a85508._8_2_;
  *(char *)(pActionMap + 0xd4b) = s_QuickBar_4_00a85508[10];
  *(uint32_t *)(pActionMap + 0xd75) = s_QuickBar_5_00a854fc._0_4_;
  *(uint32_t *)(pActionMap + 0xd79) = s_QuickBar_5_00a854fc._4_4_;
  *(uint16_t *)(pActionMap + 0xd7d) = s_QuickBar_5_00a854fc._8_2_;
  *(char *)(pActionMap + 0xd7f) = s_QuickBar_5_00a854fc[10];
  *(uint32_t *)(pActionMap + 0xda9) = s_QuickBar_6_00a854f0._0_4_;
  *(uint32_t *)(pActionMap + 0xdad) = s_QuickBar_6_00a854f0._4_4_;
  *(uint16_t *)(pActionMap + 0xdb1) = s_QuickBar_6_00a854f0._8_2_;
  *(char *)(pActionMap + 0xdb3) = s_QuickBar_6_00a854f0[10];
  *(uint32_t *)(pActionMap + 0xddd) = s_QuickBar_7_00a854e4._0_4_;
  *(uint32_t *)(pActionMap + 0xde1) = s_QuickBar_7_00a854e4._4_4_;
  *(uint16_t *)(pActionMap + 0xde5) = s_QuickBar_7_00a854e4._8_2_;
  *(char *)(pActionMap + 0xde7) = s_QuickBar_7_00a854e4[10];
  *(uint32_t *)(pActionMap + 0xe11) = s_QuickBar_8_00a854d8._0_4_;
  *(uint32_t *)(pActionMap + 0xe15) = s_QuickBar_8_00a854d8._4_4_;
  *(uint16_t *)(pActionMap + 0xe19) = s_QuickBar_8_00a854d8._8_2_;
  *(char *)(pActionMap + 0xe1b) = s_QuickBar_8_00a854d8[10];
  *(uint32_t *)(pActionMap + 0xe45) = s_QuickBar_9_00a854cc._0_4_;
  *(uint32_t *)(pActionMap + 0xe49) = s_QuickBar_9_00a854cc._4_4_;
  *(uint16_t *)(pActionMap + 0xe4d) = s_QuickBar_9_00a854cc._8_2_;
  *(char *)(pActionMap + 0xe4f) = s_QuickBar_9_00a854cc[10];
  *(uint32_t *)(pActionMap + 0xe79) = s_QuickBar_10_00a854c0._0_4_;
  *(uint32_t *)(pActionMap + 0xe7d) = s_QuickBar_10_00a854c0._4_4_;
  *(uint32_t *)(pActionMap + 0xe81) = s_QuickBar_10_00a854c0._8_4_;
  *(uint32_t *)(pActionMap + 0xead) = s_QuickBarPage_1_00a854b0._0_4_;
  *(uint32_t *)(pActionMap + 0xeb1) = s_QuickBarPage_1_00a854b0._4_4_;
  *(uint32_t *)(pActionMap + 0xeb5) = s_QuickBarPage_1_00a854b0._8_4_;
  *(uint16_t *)(pActionMap + 0xeb9) = s_QuickBarPage_1_00a854b0._12_2_;
  *(char *)(pActionMap + 0xebb) = s_QuickBarPage_1_00a854b0[0xe];
  *(uint32_t *)(pActionMap + 0xee1) = s_QuickBarPage_2_00a854a0._0_4_;
  *(uint32_t *)(pActionMap + 0xee5) = s_QuickBarPage_2_00a854a0._4_4_;
  *(uint32_t *)(pActionMap + 0xee9) = s_QuickBarPage_2_00a854a0._8_4_;
  *(uint16_t *)(pActionMap + 0xeed) = s_QuickBarPage_2_00a854a0._12_2_;
  *(char *)(pActionMap + 0xeef) = s_QuickBarPage_2_00a854a0[0xe];
  *(uint32_t *)(pActionMap + 0xf15) = s_QuickBarPage_3_00a85490._0_4_;
  *(uint32_t *)(pActionMap + 0xf19) = s_QuickBarPage_3_00a85490._4_4_;
  *(uint32_t *)(pActionMap + 0xf1d) = s_QuickBarPage_3_00a85490._8_4_;
  *(uint16_t *)(pActionMap + 0xf21) = s_QuickBarPage_3_00a85490._12_2_;
  *(char *)(pActionMap + 0xf23) = s_QuickBarPage_3_00a85490[0xe];
  *(uint32_t *)(pActionMap + 0xf49) = s_QuickBarPage_4_00a85480._0_4_;
  *(uint32_t *)(pActionMap + 0xf4d) = s_QuickBarPage_4_00a85480._4_4_;
  *(uint32_t *)(pActionMap + 0xf51) = s_QuickBarPage_4_00a85480._8_4_;
  *(uint16_t *)(pActionMap + 0xf55) = s_QuickBarPage_4_00a85480._12_2_;
  *(char *)(pActionMap + 0xf57) = s_QuickBarPage_4_00a85480[0xe];
  *(uint32_t *)(pActionMap + 0xf7d) = s_QuickBarPage_5_00a85470._0_4_;
  *(uint32_t *)(pActionMap + 0xf81) = s_QuickBarPage_5_00a85470._4_4_;
  *(uint32_t *)(pActionMap + 0xf85) = s_QuickBarPage_5_00a85470._8_4_;
  *(uint16_t *)(pActionMap + 0xf89) = s_QuickBarPage_5_00a85470._12_2_;
  *(char *)(pActionMap + 0xf8b) = s_QuickBarPage_5_00a85470[0xe];
  *(uint32_t *)(pActionMap + 0xfb1) = s_QuickBarPage_6_00a85460._0_4_;
  *(uint32_t *)(pActionMap + 0xfb5) = s_QuickBarPage_6_00a85460._4_4_;
  *(uint32_t *)(pActionMap + 0xfb9) = s_QuickBarPage_6_00a85460._8_4_;
  *(uint16_t *)(pActionMap + 0xfbd) = s_QuickBarPage_6_00a85460._12_2_;
  *(char *)(pActionMap + 0xfbf) = s_QuickBarPage_6_00a85460[0xe];
  *(uint32_t *)(pActionMap + 0xfe5) = s_QuickBarPage_7_00a85450._0_4_;
  *(uint32_t *)(pActionMap + 0xfe9) = s_QuickBarPage_7_00a85450._4_4_;
  *(uint32_t *)(pActionMap + 0xfed) = s_QuickBarPage_7_00a85450._8_4_;
  *(uint16_t *)(pActionMap + 0xff1) = s_QuickBarPage_7_00a85450._12_2_;
  *(char *)(pActionMap + 0xff3) = s_QuickBarPage_7_00a85450[0xe];
  *(uint32_t *)(pActionMap + 0x1019) = s_QuickBarPage_8_00a85440._0_4_;
  *(uint32_t *)(pActionMap + 0x101d) = s_QuickBarPage_8_00a85440._4_4_;
  *(uint32_t *)(pActionMap + 0x1021) = s_QuickBarPage_8_00a85440._8_4_;
  *(uint16_t *)(pActionMap + 0x1025) = s_QuickBarPage_8_00a85440._12_2_;
  *(char *)(pActionMap + 0x1027) = s_QuickBarPage_8_00a85440[0xe];
  *(uint32_t *)(pActionMap + 0x104d) = s_QuickBarPage_9_00a85430._0_4_;
  *(uint32_t *)(pActionMap + 0x1051) = s_QuickBarPage_9_00a85430._4_4_;
  *(uint32_t *)(pActionMap + 0x1055) = s_QuickBarPage_9_00a85430._8_4_;
  *(uint16_t *)(pActionMap + 0x1059) = s_QuickBarPage_9_00a85430._12_2_;
  *(char *)(pActionMap + 0x105b) = s_QuickBarPage_9_00a85430[0xe];
  *(uint32_t *)(pActionMap + 0x1081) = s_QuickBarPage_10_00a85420._0_4_;
  *(uint32_t *)(pActionMap + 0x1085) = s_QuickBarPage_10_00a85420._4_4_;
  *(uint32_t *)(pActionMap + 0x1089) = s_QuickBarPage_10_00a85420._8_4_;
  *(uint32_t *)(pActionMap + 0x108d) = s_QuickBarPage_10_00a85420._12_4_;
  *(uint32_t *)(pActionMap + 0x1289) = s_Next_Mission_00a85410._0_4_;
  *(uint32_t *)(pActionMap + 0x128d) = s_Next_Mission_00a85410._4_4_;
  *(uint32_t *)(pActionMap + 0x1291) = s_Next_Mission_00a85410._8_4_;
  *(char *)(pActionMap + 0x1295) = s_Next_Mission_00a85410[0xc];
  *(uint32_t *)(pActionMap + 0x12bd) = s_Prev_Mission_00a85400._0_4_;
  *(uint32_t *)(pActionMap + 0x12c1) = s_Prev_Mission_00a85400._4_4_;
  *(uint32_t *)(pActionMap + 0x12c5) = s_Prev_Mission_00a85400._8_4_;
  *(char *)(pActionMap + 0x12c9) = s_Prev_Mission_00a85400[0xc];

  // SECTION 3: DRIVE axes display names (Accelerate/Reverse/Steer/Soft/Brake)
  //   Links held flags used by Client_Input_DriveControlTick (DAT_00d1bc*)
  *(uint32_t *)(pActionMap + 0x27d) = s_Accelerate_00a78254._0_4_;
  *(uint32_t *)(pActionMap + 0x281) = s_Accelerate_00a78254._4_4_;
  *(uint16_t *)(pActionMap + 0x285) = s_Accelerate_00a78254._8_2_;
  *(char *)(pActionMap + 0x287) = s_Accelerate_00a78254[10];
  *(uint32_t *)(pActionMap + 0x3b5) = s_Brake_00a78244._0_4_;
  *(uint16_t *)(pActionMap + 0x3b9) = s_Brake_00a78244._4_2_;
  *(uint32_t *)(pActionMap + 0x2b1) = s_Reverse_00a7824c._0_4_;
  *(uint32_t *)(pActionMap + 0x2b5) = s_Reverse_00a7824c._4_4_;
  *(uint32_t *)(pActionMap + 0x2e5) = s_Steer_Left_00a853f4._0_4_;
  *(uint32_t *)(pActionMap + 0x2e9) = s_Steer_Left_00a853f4._4_4_;
  *(uint16_t *)(pActionMap + 0x2ed) = s_Steer_Left_00a853f4._8_2_;
  *(char *)(pActionMap + 0x2ef) = s_Steer_Left_00a853f4[10];
  *(uint32_t *)(pActionMap + 0x319) = s_Steer_Right_00a853e8._0_4_;
  *(uint32_t *)(pActionMap + 0x31d) = s_Steer_Right_00a853e8._4_4_;
  *(uint32_t *)(pActionMap + 0x321) = s_Steer_Right_00a853e8._8_4_;
  *(uint32_t *)(pActionMap + 0x34d) = s_Steer_Left_Soft_00a853d8._0_4_;
  *(uint32_t *)(pActionMap + 0x351) = s_Steer_Left_Soft_00a853d8._4_4_;
  *(uint32_t *)(pActionMap + 0x355) = s_Steer_Left_Soft_00a853d8._8_4_;
  *(uint32_t *)(pActionMap + 0x359) = s_Steer_Left_Soft_00a853d8._12_4_;
  *(uint32_t *)(pActionMap + 0x381) = s_Steer_Right_Soft_00a853c4._0_4_;
  *(uint32_t *)(pActionMap + 0x385) = s_Steer_Right_Soft_00a853c4._4_4_;
  *(uint32_t *)(pActionMap + 0x389) = s_Steer_Right_Soft_00a853c4._8_4_;
  *(uint32_t *)(pActionMap + 0x38d) = s_Steer_Right_Soft_00a853c4._12_4_;
  *(char *)(pActionMap + 0x391) = s_Steer_Right_Soft_00a853c4[0x10];

  // SECTION 4: Combat / target / weapons / bounce
  *(uint32_t *)(pActionMap + 0x485) = s_Bounce_Vehicle_00a853b4._0_4_;
  *(uint32_t *)(pActionMap + 0x489) = s_Bounce_Vehicle_00a853b4._4_4_;
  *(uint32_t *)(pActionMap + 0x48d) = s_Bounce_Vehicle_00a853b4._8_4_;
  *(uint16_t *)(pActionMap + 0x491) = s_Bounce_Vehicle_00a853b4._12_2_;
  *(char *)(pActionMap + 0x493) = s_Bounce_Vehicle_00a853b4[0xe];
  *(uint32_t *)(pActionMap + 0x1255) = s_Reply_00a853ac._0_4_;
  *(uint16_t *)(pActionMap + 0x1259) = s_Reply_00a853ac._4_2_;
  *(uint32_t *)(pActionMap + 0x3e9) = s_Fire_Weapons_00a8539c._0_4_;
  *(uint32_t *)(pActionMap + 0x3ed) = s_Fire_Weapons_00a8539c._4_4_;
  *(uint32_t *)(pActionMap + 0x3f1) = s_Fire_Weapons_00a8539c._8_4_;
  *(char *)(pActionMap + 0x3f5) = s_Fire_Weapons_00a8539c[0xc];
  pcVar2 = "Secondary Attack (Drop weapons)";
  puVar3 = (uint32_t *)(pActionMap + 0x41d);
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *(uint32_t *)pcVar2;
    pcVar2 = pcVar2 + 4;
    puVar3 = puVar3 + 1;
  }
  pcVar2 = "Context-Sensitive Action Modifier";
  puVar3 = (uint32_t *)(pActionMap + 0x451);
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *(uint32_t *)pcVar2;
    pcVar2 = pcVar2 + 4;
    puVar3 = puVar3 + 1;
  }
  *(uint16_t *)puVar3 = *(uint16_t *)pcVar2;
  *(uint32_t *)(pActionMap + 0x521) = s_Target_Next_Enemy_00a85344._0_4_;
  *(uint32_t *)(pActionMap + 0x525) = s_Target_Next_Enemy_00a85344._4_4_;
  *(uint32_t *)(pActionMap + 0x529) = s_Target_Next_Enemy_00a85344._8_4_;
  *(uint32_t *)(pActionMap + 0x52d) = s_Target_Next_Enemy_00a85344._12_4_;
  *(uint16_t *)(pActionMap + 0x531) = s_Target_Next_Enemy_00a85344._16_2_;
  *(uint32_t *)(pActionMap + 0x4ed) = s_Target_Previous_Enemy_00a8532c._0_4_;
  *(uint32_t *)(pActionMap + 0x4f1) = s_Target_Previous_Enemy_00a8532c._4_4_;
  *(uint32_t *)(pActionMap + 0x4f5) = s_Target_Previous_Enemy_00a8532c._8_4_;
  *(uint32_t *)(pActionMap + 0x4f9) = s_Target_Previous_Enemy_00a8532c._12_4_;
  *(uint32_t *)(pActionMap + 0x4fd) = s_Target_Previous_Enemy_00a8532c._16_4_;
  *(uint16_t *)(pActionMap + 0x501) = s_Target_Previous_Enemy_00a8532c._20_2_;
  *(uint32_t *)(pActionMap + 0x555) = s_Target_Closest_Enemy_00a85314._0_4_;
  *(uint32_t *)(pActionMap + 0x559) = s_Target_Closest_Enemy_00a85314._4_4_;
  *(uint32_t *)(pActionMap + 0x55d) = s_Target_Closest_Enemy_00a85314._8_4_;
  *(uint32_t *)(pActionMap + 0x561) = s_Target_Closest_Enemy_00a85314._12_4_;
  *(uint32_t *)(pActionMap + 0x565) = s_Target_Closest_Enemy_00a85314._16_4_;
  *(char *)(pActionMap + 0x569) = s_Target_Closest_Enemy_00a85314[0x14];
  *(uint32_t *)(pActionMap + 0x5bd) = s_Assist_Target_00a85304._0_4_;
  *(uint32_t *)(pActionMap + 0x5c1) = s_Assist_Target_00a85304._4_4_;
  *(uint32_t *)(pActionMap + 0x5c5) = s_Assist_Target_00a85304._8_4_;
  *(uint16_t *)(pActionMap + 0x5c9) = s_Assist_Target_00a85304._12_2_;
  pcVar2 = "Target Convoy Member 1";
  puVar3 = (uint32_t *)(pActionMap + 0x138d);
  for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *(uint32_t *)pcVar2;
    pcVar2 = pcVar2 + 4;
    puVar3 = puVar3 + 1;
  }
  *(uint16_t *)puVar3 = *(uint16_t *)pcVar2;
  *(char *)((int)puVar3 + 2) = pcVar2[2];
  pcVar2 = "Target Convoy Member 2";
  puVar3 = (uint32_t *)(pActionMap + 0x13c1);
  for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *(uint32_t *)pcVar2;
    pcVar2 = pcVar2 + 4;
    puVar3 = puVar3 + 1;
  }
  *(uint16_t *)puVar3 = *(uint16_t *)pcVar2;
  *(char *)((int)puVar3 + 2) = pcVar2[2];
  pcVar2 = "Target Convoy Member 3";
  puVar3 = (uint32_t *)(pActionMap + 0x13f5);
  for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *(uint32_t *)pcVar2;
    pcVar2 = pcVar2 + 4;
    puVar3 = puVar3 + 1;
  }
  *(uint16_t *)puVar3 = *(uint16_t *)pcVar2;
  *(char *)((int)puVar3 + 2) = pcVar2[2];
  pcVar2 = "Target Convoy Member 4";
  puVar3 = (uint32_t *)(pActionMap + 0x1429);
  for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *(uint32_t *)pcVar2;
    pcVar2 = pcVar2 + 4;
    puVar3 = puVar3 + 1;
  }
  *(uint16_t *)puVar3 = *(uint16_t *)pcVar2;
  *(char *)((int)puVar3 + 2) = pcVar2[2];
  *(uint32_t *)(pActionMap + 0x145d) = s_Use_Macro_1_00a85298._0_4_;
  *(uint32_t *)(pActionMap + 0x1461) = s_Use_Macro_1_00a85298._4_4_;
  *(uint32_t *)(pActionMap + 0x1465) = s_Use_Macro_1_00a85298._8_4_;
  *(uint32_t *)(pActionMap + 0x1491) = s_Use_Macro_2_00a8528c._0_4_;
  *(uint32_t *)(pActionMap + 0x1495) = s_Use_Macro_2_00a8528c._4_4_;
  *(uint32_t *)(pActionMap + 0x1499) = s_Use_Macro_2_00a8528c._8_4_;
  *(uint32_t *)(pActionMap + 0x14c5) = s_Use_Macro_3_00a85280._0_4_;
  *(uint32_t *)(pActionMap + 0x14c9) = s_Use_Macro_3_00a85280._4_4_;
  *(uint32_t *)(pActionMap + 0x14cd) = s_Use_Macro_3_00a85280._8_4_;
  *(uint32_t *)(pActionMap + 0x14f9) = s_Use_Macro_4_00a85274._0_4_;
  *(uint32_t *)(pActionMap + 0x14fd) = s_Use_Macro_4_00a85274._4_4_;
  *(uint32_t *)(pActionMap + 0x1501) = s_Use_Macro_4_00a85274._8_4_;
  *(uint32_t *)(pActionMap + 0x152d) = s_Use_Macro_5_00a85268._0_4_;
  *(uint32_t *)(pActionMap + 0x1531) = s_Use_Macro_5_00a85268._4_4_;
  *(uint32_t *)(pActionMap + 0x1535) = s_Use_Macro_5_00a85268._8_4_;
  *(uint32_t *)(pActionMap + 0x1561) = s_Use_Macro_6_00a8525c._0_4_;
  *(uint32_t *)(pActionMap + 0x1565) = s_Use_Macro_6_00a8525c._4_4_;
  *(uint32_t *)(pActionMap + 0x1569) = s_Use_Macro_6_00a8525c._8_4_;
  *(uint32_t *)(pActionMap + 0x1595) = s_Use_Macro_7_00a85250._0_4_;
  *(uint32_t *)(pActionMap + 0x1599) = s_Use_Macro_7_00a85250._4_4_;
  *(uint32_t *)(pActionMap + 0x159d) = s_Use_Macro_7_00a85250._8_4_;
  *(uint32_t *)(pActionMap + 0x15c9) = s_Use_Macro_8_00a85244._0_4_;
  *(uint32_t *)(pActionMap + 0x15cd) = s_Use_Macro_8_00a85244._4_4_;
  *(uint32_t *)(pActionMap + 0x15d1) = s_Use_Macro_8_00a85244._8_4_;
  *(uint32_t *)(pActionMap + 0x15fd) = s_Use_Macro_9_00a85238._0_4_;
  *(uint32_t *)(pActionMap + 0x1601) = s_Use_Macro_9_00a85238._4_4_;
  *(uint32_t *)(pActionMap + 0x1605) = s_Use_Macro_9_00a85238._8_4_;
  *(uint32_t *)(pActionMap + 0x1631) = s_Use_Macro_10_00a85228._0_4_;
  *(uint32_t *)(pActionMap + 0x1635) = s_Use_Macro_10_00a85228._4_4_;
  *(uint32_t *)(pActionMap + 0x1639) = s_Use_Macro_10_00a85228._8_4_;
  *(char *)(pActionMap + 0x163d) = s_Use_Macro_10_00a85228[0xc];
  *(uint32_t *)(pActionMap + 0x1665) = s_Use_Macro_11_00a85218._0_4_;
  *(uint32_t *)(pActionMap + 0x1669) = s_Use_Macro_11_00a85218._4_4_;
  *(uint32_t *)(pActionMap + 0x166d) = s_Use_Macro_11_00a85218._8_4_;
  *(char *)(pActionMap + 0x1671) = s_Use_Macro_11_00a85218[0xc];
  *(uint32_t *)(pActionMap + 0x1699) = s_Use_Macro_12_00a85208._0_4_;
  *(uint32_t *)(pActionMap + 0x169d) = s_Use_Macro_12_00a85208._4_4_;
  *(uint32_t *)(pActionMap + 0x16a1) = s_Use_Macro_12_00a85208._8_4_;
  *(char *)(pActionMap + 0x16a5) = s_Use_Macro_12_00a85208[0xc];
  *(uint32_t *)(pActionMap + 0x16cd) = s_Use_Macro_13_00a851f8._0_4_;
  *(uint32_t *)(pActionMap + 0x16d1) = s_Use_Macro_13_00a851f8._4_4_;
  *(uint32_t *)(pActionMap + 0x16d5) = s_Use_Macro_13_00a851f8._8_4_;
  *(char *)(pActionMap + 0x16d9) = s_Use_Macro_13_00a851f8[0xc];
  *(uint32_t *)(pActionMap + 0x1701) = s_Use_Macro_14_00a851e8._0_4_;
  *(uint32_t *)(pActionMap + 0x1705) = s_Use_Macro_14_00a851e8._4_4_;
  *(uint32_t *)(pActionMap + 0x1709) = s_Use_Macro_14_00a851e8._8_4_;
  *(char *)(pActionMap + 0x170d) = s_Use_Macro_14_00a851e8[0xc];
  *(uint32_t *)(pActionMap + 0x1735) = s_Use_Macro_15_00a851d8._0_4_;
  *(uint32_t *)(pActionMap + 0x1739) = s_Use_Macro_15_00a851d8._4_4_;
  *(uint32_t *)(pActionMap + 0x173d) = s_Use_Macro_15_00a851d8._8_4_;
  *(char *)(pActionMap + 0x1741) = s_Use_Macro_15_00a851d8[0xc];
  *(uint32_t *)(pActionMap + 0x1769) = s_Zoom_In_00a851d0._0_4_;
  *(uint32_t *)(pActionMap + 0x176d) = s_Zoom_In_00a851d0._4_4_;
  *(uint32_t *)(pActionMap + 0x179d) = s_Zoom_Out_00a851c4._0_4_;
  *(uint32_t *)(pActionMap + 0x17a1) = s_Zoom_Out_00a851c4._4_4_;
  *(char *)(pActionMap + 0x17a5) = s_Zoom_Out_00a851c4[8];
  *(uint32_t *)(pActionMap + 0x17d1) = s_Free_Look_00a4abfc._0_4_;
  *(uint32_t *)(pActionMap + 0x17d5) = s_Free_Look_00a4abfc._4_4_;
  *(uint16_t *)(pActionMap + 0x17d9) = s_Free_Look_00a4abfc._8_2_;
  *(uint32_t *)(pActionMap + 0x12f1) = s_Next_Quickbar_Active_00a851ac._0_4_;
  *(uint32_t *)(pActionMap + 0x12f5) = s_Next_Quickbar_Active_00a851ac._4_4_;
  *(uint32_t *)(pActionMap + 0x12f9) = s_Next_Quickbar_Active_00a851ac._8_4_;
  *(uint32_t *)(pActionMap + 0x12fd) = s_Next_Quickbar_Active_00a851ac._12_4_;
  *(uint32_t *)(pActionMap + 0x1301) = s_Next_Quickbar_Active_00a851ac._16_4_;
  *(char *)(pActionMap + 0x1305) = s_Next_Quickbar_Active_00a851ac[0x14];
  pcVar2 = "Previous Quickbar Active";
  pcVar4 = (char *)(pActionMap + 0x1325);
  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
    *(uint32_t *)pcVar4 = *(uint32_t *)pcVar2;
    pcVar2 = pcVar2 + 4;
    pcVar4 = pcVar4 + 4;
  }
  *pcVar4 = *pcVar2;
  *(uint32_t *)(pActionMap + 0x1359) = s_Use_Quickbar_Active_00a8517c._0_4_;
  *(uint32_t *)(pActionMap + 0x135d) = s_Use_Quickbar_Active_00a8517c._4_4_;
  *(uint32_t *)(pActionMap + 0x1361) = s_Use_Quickbar_Active_00a8517c._8_4_;
  *(uint32_t *)(pActionMap + 0x1365) = s_Use_Quickbar_Active_00a8517c._12_4_;
  *(uint32_t *)(pActionMap + 0x1369) = s_Use_Quickbar_Active_00a8517c._16_4_;

  // SECTION 5: Camera pan / mode
  *(uint32_t *)(pActionMap + 0x186d) = s_Pan_Up_00a85174._0_4_;
  *(uint16_t *)(pActionMap + 0x1871) = s_Pan_Up_00a85174._4_2_;
  *(char *)(pActionMap + 0x1873) = s_Pan_Up_00a85174[6];
  *(uint32_t *)(pActionMap + 0x18a1) = s_Pan_Down_00a85168._0_4_;
  *(uint32_t *)(pActionMap + 0x18a5) = s_Pan_Down_00a85168._4_4_;
  *(char *)(pActionMap + 0x18a9) = s_Pan_Down_00a85168[8];
  *(uint32_t *)(pActionMap + 0x18d5) = s_Pan_Reset_00a8515c._0_4_;
  *(uint32_t *)(pActionMap + 0x18d9) = s_Pan_Reset_00a8515c._4_4_;
  *(uint16_t *)(pActionMap + 0x18dd) = s_Pan_Reset_00a8515c._8_2_;
  *(uint32_t *)(pActionMap + 0xa69) = s_Toggle_Camera_Mode_00a85148._0_4_;
  *(uint32_t *)(pActionMap + 0xa6d) = s_Toggle_Camera_Mode_00a85148._4_4_;
  *(uint32_t *)(pActionMap + 0xa71) = s_Toggle_Camera_Mode_00a85148._8_4_;
  *(uint32_t *)(pActionMap + 0xa75) = s_Toggle_Camera_Mode_00a85148._12_4_;
  *(uint16_t *)(pActionMap + 0xa79) = s_Toggle_Camera_Mode_00a85148._16_2_;
  *(char *)(pActionMap + 0xa7b) = s_Toggle_Camera_Mode_00a85148[0x12];
  return;
}
