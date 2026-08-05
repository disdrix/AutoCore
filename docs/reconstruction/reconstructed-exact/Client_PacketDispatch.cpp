// READABILITY (auto CF):
//  - Body size: ~375 non-empty decompiler lines.
//  - Control keywords: return×107, if×6, switch×2, goto×1.
//  - Notable callees: Client_CreateVehicleObjectApply×2, Client_RecvCompleteDynamicObjective×2, Client_RecvCreateCharacter×2, Client_RecvObjectiveState×2, Client_RecvSpecialEvent×2, Client_AwardKillExperience, Client_PacketDispatch, Client_RecvBroadcast.
//  - Return sites: 107.

// =============================================================================
// Client_PacketDispatch
// -----------------------------------------------------------------------------
// Purpose:  Sector/global S2C game-packet switch. Reads packet opcode and
//           dispatches to the matching client recv handler (or intentional
//           no-op). Returns 1 if handled, 0 if unknown.
//
// Address:  0x00815710  (autoassault.exe, image base 0x400000)
// Stable:   aa_00815710
// System:   missions-progression (multi-system hub; also inventory / skills S2C)
//
// Convention (decompiler):
//   __fastcall with imperfect register recovery for some cases
//   pCtx      - opaque context (dispatch arg; passed through to some handlers)
//   pPacket   - packet header; dwOpcode at +0; typed Packet_CharacterLevel* in
//               decomp is a header-layout stand-in, NOT correct for every case
//   pPayload  - secondary buffer / body pointer (case-dependent)
//   *in_EAX   - success/continue flag; set 1 on entry; some cases overwrite
//   unaff_ESI / unaff_EDI - used on GiveCredits / GiveXP / grab paths (register
//               framing from caller; treat as best-effort recovery)
//
// Control flow summary:
//   1) *in_EAX = 1; opcode = pPacket->dwOpcode
//   2) if opcode < 0x8064:
//        if opcode != 0x8063: large switch (0x2002… mission/inventory/skill cases)
//        else 0x8063 path: coid check → FUN_00540c50 / FUN_005409c0
//   3) high range: 0x9001 / 0x9004 / 0x901c; else return 0
//   4) unknown switch default → return 0; handled → return 1
//   5) multi-case fallthroughs share intentional no-op (case 0x2003 label)
//
// Named callees (addresses from sealed siblings / headers):
//   Client_RecvCharacterLevel          0x00810f00  (0x2017)
//   Client_RecvInventoryGrabResponse   0x00811be0  (0x2035/0x2039)
//   Client_RecvInventoryDropResponse   0x00813730  (0x2037/0x203B)
//   Client_RecvInventoryEquip          0x00813f40  (0x203C)
//   Client_AwardKillExperience         0x0080ae70  (0x205F)
//   Client_RecvCompleteDynamicObjective 0x0080ff00 (0x2070)
//   Client_RecvObjectiveState          0x00809460  (0x2071)
//   Client_RecvSkillStatusEffect       0x00811170  (0x2031)
//
// NOT in this switch (important negatives):
//   0x2030 RequestCastSkill - C2S only (Client_RequestCastSkill builders)
//   0x2034/0x2036/0x2038/0x203A grab/drop requests - C2S; only *Response here
//   0x206E MissionDialogResponse - C2S dialog OK
//   0x20B3 AutoPatrol (and similar C2S-only) - absent
//
// Exactness: Behavior-preserving rewrite of decompiler CF. Not modernization.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual reviews:
//   reviews/A_aa_00815710_Client_PacketDispatch.md
//   reviews/B_aa_00815710_Client_PacketDispatch.md
//   (also: aa_00815710_reconstruction_review.md / aa_00815710_skeptical_review.md)
// =============================================================================

/*
 * Readability pass:
 * - undefinedN widths → fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw (2026-07-23).
 * - Case comments: AutoCore GameOpcode names + reconstructed handler where known.
 *   Comments only; no invented call targets or pruned branches.
 *
 * Priority opcode map (mission / inventory / skills):
 *   0x2017 CharacterLevel          → Client_RecvCharacterLevel (absolute money/XP)
 *   0x2031 SkillStatusEffect       → Client_RecvSkillStatusEffect
 *   0x2035/0x2039 GrabResponse     → Client_RecvInventoryGrabResponse
 *   0x2037/0x203B DropResponse     → Client_RecvInventoryDropResponse
 *   0x203C InventoryEquip          → Client_RecvInventoryEquip
 *   0x203D InventoryEquipResponse  → intentional no-op fallthrough
 *   0x203E/0x203F Unequip notify/response
 *   0x2040-0x2043 SendAll variants → intentional no-op fallthrough
 *   0x205E GiveCredits             → Client_RecvGiveCredits
 *   0x205F GiveXP                  → Client_AwardKillExperience
 *   0x206C GroupReactionCall       → Client_RecvGroupReactionCall
 *   0x206D MissionDialog (NPC)     → Client_RecvNpcMissionDialog
 *   0x2070 CompleteDynamicObjective→ Client_RecvCompleteDynamicObjective (force)
 *   0x2071 ObjectiveState          → Client_RecvObjectiveState (progress only)
 *
 * Do not confuse 0x2070 with 0x2071 - historical docs swapped these handlers.
 */

uint32_t /* width from decompiler */ __fastcall
Client_PacketDispatch(void *pCtx,Packet_CharacterLevel *pPacket,void *pPayload)

{
  uint uVar1;
  uint8_t uVar2;
  uint8_t *in_EAX;
  Packet_GiveCredits *unaff_ESI;
  GiveXpPacketBody *unaff_EDI;
  
  *in_EAX = 1;
  uVar1 = pPacket->dwOpcode;
  if (uVar1 < 0x8064) {
    if (uVar1 != 0x8063) {
      switch(uVar1) {
      case 0x2002:
                    /* TransferFromGlobalStage3 */
        FUN_00809ad0();
        return 1;
      case 0x2003:
                    /* TransferToWorld - intentional no-op ack */
      case 0x2008:
                    /* CreatureMoved - no-op fallthrough */
      case 0x2009:
                    /* ObjectMoved */
      case 0x200a:
                    /* VehicleMoved */
      case 0x200c:
                    /* MultipleVehicleMoved */
      case 0x200d:
                    /* MultipleCreatureMoved */
      case 0x200e:
                    /* MultipleObjectMoved */
      case 0x200f:
                    /* MultipleGridMoved */
      case 0x2022:
                    /* Firing */
      case 0x2029:
                    /* StoreUpdate */
      case 0x203d:
                    /* InventoryEquipResponse - S2C no-op (equip applied via 0x203C) */
      case 0x2040:
                    /* InventoryCargoSendAll - client no-op */
      case 0x2041:
                    /* InventoryLockerSendAll - client no-op */
      case 0x2042:
                    /* InventoryTradeSendAll - client no-op */
      case 0x2043:
                    /* InventoryDraggingSendAll - client no-op */
      case 0x2067:
                    /* ModifyTrickTrim */
      case 0x206a:
                    /* ActivateSpawnedObject */
      case 0x2083:
                    /* RefineryRefineResponse */
      case 0x208a:
                    /* TradeAddItemResponse */
        goto switchD_00815749_caseD_2003;
      case 0x2004:
                    /* NotifyOfGlobalReconnect */
        FUN_0080ba20();
        return 1;
      case 0x2005:
                    /* MapInfo */
        FUN_008153b0(pPayload,pPacket);
        return 1;
      case 0x2006:
                    /* ArenaInfo */
        FUN_004ce320(&pPacket->dwCoidLo,pCtx);
        return 1;
      case 0x2007:
                    /* ObjectFullInfo */
        FUN_00808ee0(pPayload);
        return 1;
      case 0x200b:
                    /* MultipleFullInfo */
        FUN_00809690(pPayload);
        return 1;
      case 0x2010:
                    /* MultipleStatUpdate */
        FUN_0080bc40(pPayload,pCtx);
        return 1;
      default:
        return 0;
      case 0x2012:
                    /* CreateSimpleObject */
        FUN_00812360(pPayload);
        return 1;
      case 0x2013:
                    /* CreateCreature */
        FUN_0080af70();
        return 1;
      case 0x2014:
                    /* CreateSkillHeartbeat */
        FUN_0080ba70(pPacket);
        return 1;
      case 0x2015:
                    /* CreateCharacter */
        Client_RecvCreateCharacter();
        return 1;
      case 0x2016:
                    /* CreateCharacterExtended */
        Client_RecvCreateCharacter();
        return 1;
      case 0x2017:
                    /* CharacterLevel (S2C) - absolute money/XP/level snapshot
                       → Client_RecvCharacterLevel @ 0x00810f00 */
        Client_RecvCharacterLevel(pPayload,pPacket);
        return 1;
      case 0x2018:
                    /* CreatePowerPlant */
        FUN_008144f0();
        return 1;
      case 0x2019:
                    /* CreateGadget */
        FUN_008144b0();
        return 1;
      case 0x201a:
                    /* CreateTinkeringKit */
        FUN_00814470();
        return 1;
      case 0x201b:
                    /* CreateWheelSet */
        FUN_008122e0();
        return 1;
      case 0x201c:
                    /* CreateWeapon */
        FUN_00814400();
        return 1;
      case 0x201d:
                    /* CreateVehicle */
        Client_CreateVehicleObjectApply(pPayload,0);
        return 1;
      case 0x201e:
                    /* CreateVehicleExtended */
        Client_CreateVehicleObjectApply(pPayload,1);
        return 1;
      case 0x2020:
                    /* DestroyObject */
        Client_RecvDestroyObject(pPacket);
        return 1;
      case 0x2021:
                    /* Broadcast */
        Client_RecvBroadcast(pPayload);
        return 1;
      case 0x2023:
                    /* Damage */
        FUN_00812a60(pPayload,pPacket);
        return 1;
      case 0x2025:
                    /* StoreOpenResponse */
        FUN_0080ce90();
        return 1;
      case 0x2026:
                    /* StoreList */
        FUN_007fc360();
        return 1;
      case 0x2028:
                    /* StoreTransactionResponse */
        FUN_00810670(pPayload);
        return 1;
      case 0x202c:
                    /* HazardModeSwitch */
        FUN_00808ea0();
        return 1;
      case 0x202d:
                    /* HazardModeSwitchResponse */
        FUN_00808980();
        return 1;
      case 0x2031:
                    /* SkillStatusEffect (S2C) - cast/status feedback
                       Note: 0x2030 RequestCastSkill is C2S only (not in this switch) */
        Client_RecvSkillStatusEffect(pPayload);
        return 1;
      case 0x2032:
                    /* CancelSkill */
        FUN_00809070();
        return 1;
      case 0x2033:
                    /* SetGMFlag */
        FUN_00808a90();
        return 1;
      case 0x2035:
                    /* InventoryGrabResponse (S2C) */
      case 0x2039:
                    /* InventoryGrabMMResponse (S2C mass-move sibling)
                       Shared handler Client_RecvInventoryGrabResponse @ 0x00811be0 */
        Client_RecvInventoryGrabResponse(unaff_EDI,unaff_ESI);
        return 1;
      case 0x2037:
                    /* InventoryDropResponse (S2C) */
      case 0x203b:
                    /* InventoryDropMMResponse (S2C mass-move sibling)
                       Shared handler Client_RecvInventoryDropResponse @ 0x00813730 */
        Client_RecvInventoryDropResponse();
        return 1;
      case 0x203c:
                    /* InventoryEquip (S2C) - apply equip; may SetWheelset etc.
                       → Client_RecvInventoryEquip (FUN_00813f40 path) */
        Client_RecvInventoryEquip(pPacket);
        return 1;
      case 0x203e:
                    /* InventoryUnequip (S2C notify path) */
        Client_RecvInventoryUnequipNotify();
        return 1;
      case 0x203f:
                    /* InventoryUnequipResponse */
        Client_RecvInventoryUnequipResponse();
        return 1;
      case 0x2044:
                    /* InventoryUsePaint */
        Client_RecvInventoryUsePaint(pPayload);
        return 1;
      case 0x2046:
                    /* InventoryUseItemResponse */
        Client_RecvInventoryUseItemResponse(pPayload);
        return 1;
      case 0x2047:
                    /* InventoryAddItem (S2C) */
        Client_RecvInventoryAddItem(pPayload);
        return 1;
      case 0x2049:
                    /* InventoryDestroyItem */
        FUN_00810170();
        return 1;
      case 0x204c:
                    /* CraftFromAssemblyKitResponse */
        Client_RecvCraftFromAssemblyKitResponse(pPacket);
        return 1;
      case 0x204d:
                    /* CraftSwitchKitState */
        FUN_0080df40(pPayload,pPacket);
        return 1;
      case 0x204f:
                    /* CraftAddPrefix */
        FUN_00809d20();
        return 1;
      case 0x2050:
                    /* CraftRemovePrefix */
        FUN_00809c70();
        return 1;
      case 0x2052:
                    /* CraftFromMemoryResponse */
        FUN_0080db30(pPayload);
        return 1;
      case 0x2054:
                    /* VehicleSwitchResponse */
        FUN_00810360();
        return 1;
      case 0x2058:
                    /* ItemDropResponse */
        FUN_008136b0();
        return 1;
      case 0x205b:
                    /* UnlockRegion → Client_RecvUnlockRegion */
        Client_RecvUnlockRegion(pCtx);
        return 1;
      case 0x205e:
                    /* GiveCredits (S2C) - additive money delta
                       → Client_RecvGiveCredits @ 0x0080cac0 */
        Client_RecvGiveCredits(unaff_EDI,unaff_ESI);
        return 1;
      case 0x205f:
                    /* GiveXP (S2C) - kill/mission XP grant + floater
                       → Client_AwardKillExperience @ 0x0080ae70 */
        Client_AwardKillExperience(unaff_EDI);
        return 1;
      case 0x2060:
                    /* CreateArmor */
        FUN_00812320();
        return 1;
      case 0x2068:
                    /* ModifyTrickTrimResponse */
        FUN_00810fd0(pPayload);
        return 1;
      case 0x2069:
                    /* WeatherUpdate */
        FUN_005569a0(pPacket);
        *in_EAX = 1;
        return 1;
      case 0x206b:
                    /* LogicStateChange */
        FUN_008093c0();
        return 1;
      case 0x206c:
                    /* GroupReactionCall (S2C) - bit-packed reaction batch
                       (GiveMission / CompleteObjective reactions, etc.) */
        Client_RecvGroupReactionCall(pPayload,pPacket);
        return 1;
      case 0x206d:
                    /* MissionDialog / NpcMissionDialog (S2C)
                       → Client_RecvNpcMissionDialog @ 0x00815070 */
        Client_RecvNpcMissionDialog(pPayload);
        return 1;
      case 0x206f:
                    /* ChoiceDialogResponse (often C2S naming; handled if S2C arrives) */
        FUN_0080c2f0();
        return 1;
      case 0x2070:
                    /* CompleteDynamicObjective (S2C FORCE complete + UI refresh)
                       → Client_RecvCompleteDynamicObjective @ 0x0080ff00
                       NOT ObjectiveState - do not swap with 0x2071 */
        Client_RecvCompleteDynamicObjective(pPacket);
        return 1;
      case 0x2071:
                    /* ObjectiveState (S2C) - progress slots only
                       → Client_RecvObjectiveState */
        Client_RecvObjectiveState(pPacket);
        return 1;
      case 0x2075:
                    /* SetSpectator */
        FUN_00812d90();
        return 1;
      case 0x2076:
                    /* UpdateTimer */
        FUN_00808ad0();
        return 1;
      case 0x2077:
                    /* BattleSummary */
        FUN_00814d80(pPayload,pPacket);
        return 1;
      case 0x2079:
                    /* TakeArena */
        uVar2 = FUN_00811750();
        *in_EAX = uVar2;
        return 1;
      case 0x207b:
                    /* RefineryOpenResponse */
        FUN_0080c240();
        return 1;
      case 0x207d:
                    /* RefineryCloseResponse */
        FUN_0080e4c0();
        return 1;
      case 0x207f:
                    /* RefineryAddItemResponse */
        FUN_0080a410();
        return 1;
      case 0x2081:
                    /* RefineryRemoveItemResponse */
        FUN_0080e360();
        return 1;
      case 0x2084:
                    /* AddAchievementResponse */
        FUN_0080ce50();
        return 1;
      case 0x2086:
                    /* TradeTargetResponseResponse */
        FUN_0080c130();
        return 1;
      case 0x2088:
                    /* TradeRequestResponse */
        FUN_0080a170();
        return 1;
      case 0x208c:
                    /* TradeRemoveItemResponse */
        FUN_008134d0();
        return 1;
      case 0x208e:
                    /* TradeCancelResponse */
        FUN_008091e0();
        return 1;
      case 0x2090:
                    /* TradeApproveResponse */
        FUN_0080a0e0();
        return 1;
      case 0x2091:
                    /* TradeCompleteResponse */
        FUN_0080a020();
        return 1;
      case 0x2093:
                    /* TradeAddCreditsResponse */
        FUN_00809f10();
        return 1;
      case 0x2098:
                    /* DisciplineAddMaxResponse */
        FUN_00809e90();
        return 1;
      case 0x209a:
                    /* DisciplineAddCurrentResponse */
        FUN_0080e1e0(pPayload);
        return 1;
      case 0x209b:
                    /* DisciplinePointsAddResponse */
        FUN_00809e30();
        return 1;
      case 0x209d:
                    /* DisciplineTrainResponse */
        FUN_0080c040();
        return 1;
      case 0x209f:
                    /* DisciplineUnlearnResponse */
        FUN_00809dd0();
        return 1;
      case 0x20a1:
                    /* RNDAddCurrentResponse */
        FUN_0080e0c0();
        return 1;
      case 0x20a3:
                    /* MemorizeSuccessResponse */
        FUN_0080dcc0();
        return 1;
      case 0x20a6:
                    /* AddGadgetResponse */
        FUN_0080d930();
        return 1;
      case 0x20a8:
                    /* OpenAvailableGadgetResponse */
        FUN_0080d570(pPacket);
        return 1;
      case 0x20a9:
                    /* SpecialEvent → Client_RecvSpecialEvent (ECX=packet, stack=game) */
        Client_RecvSpecialEvent(pPayload);
        return 1;
      case 0x20aa:
                    /* StatUpdate */
        FUN_0080b3a0(pPayload);
        return 1;
      case 0x20ac:
                    /* JoinTournamentResponse */
        FUN_00811810(pPayload);
        return 1;
      case 0x20ad:
                    /* ConvoyJoinMatchRequest (S2C name as GameOpcode; body still FUN_*) */
        FUN_0080a680(pPayload);
        return 1;
      case 0x20af:
                    /* ProgressBar */
        FUN_0080be70();
        return 1;
      case 0x20b2:
                    /* FailMission (S2C) → Client_RecvFailMission (0x0080b100)
                       Call site 0x00815d97: MOV EAX,ESI; MOV ECX,EBP; CALL
                       (packet in EAX, client in ECX). UF-012 sealed 2026-07-29.
                       Note: 0x20B3 AutoPatrol is C2S-only (absent from this switch) */
        FUN_0080b100();
        return 1;
      case 0x20b5:
                    /* RequestItemDetailsResponse */
        FUN_0080d480();
        return 1;
      case 0x20b7:
                    /* InitCreateObject */
        FUN_00808830();
        return 1;
      case 0x20ba:
                    /* ChangeCombatModeResponse */
        FUN_00808a10(pPayload);
        return 1;
      case 0x20bc:
                    /* ChangeBattleModeResponse */
        FUN_008089a0(pPayload);
        return 1;
      case 0x20be:
                    /* RequestRespecResponse */
        FUN_0080bec0(pPacket);
        return 1;
      case 0x20c0:
                    /* RequestTaxiStopResponse */
        FUN_008090d0();
        return 1;
      case 0x20c2:
                    /* PowerDumpResponse */
        FUN_0080cfc0(pPayload);
        return 1;
      case 0x20c3:
                    /* OutpostTokenChance - store header field into global+0x30 */
        *(uint *)(DAT_00d1b644 + 0x30) = pPacket->dwUnknownHeader;
        return 1;
      case 0x20c4:
                    /* SectorMail */
        FUN_008085b0(pPayload);
        return 1;
      case 0x20c5:
                    /* ArenaRewardsDialog */
        FUN_0080cbf0(pPayload);
        return 1;
      }
    }
                    /* 0x8063 QuickBarUpdate-ish boundary path */
    if (pPacket->dwCoidLo != 0xffffffff) {
      FUN_00540c50(pPacket->dwUnknownHeader);
      return 1;
    }
    FUN_005409c0(pPacket->dwUnknownHeader);
    return 1;
  }
  if (uVar1 == 0x9001) {
    FUN_0080c5e0(pPayload);
switchD_00815749_caseD_2003:
                    /* Shared intentional no-op: return handled=1 without body work */
    return 1;
  }
  if (uVar1 != 0x9004) {
    if (uVar1 != 0x901c) {
      return 0;
    }
    FUN_00811830();
    return 1;
  }
  FUN_00809260();
  return 1;
}
