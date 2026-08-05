# Raw capture: Client_PacketDispatch

| Field | Value |
|---|---|
| **Stable ID** | `aa_00815710` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00815710` |
| **Canonical name** | `Client_PacketDispatch` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Client_PacketDispatch — sector/global S2C switch
   
   Mission-critical cases (corrected):
     0x206C → Client_RecvGroupReactionCall
     0x206D → Client_RecvNpcMissionDialog
     0x2070 → Client_RecvCompleteDynamicObjective  (FORCE complete + UI refresh)
     0x2071 → Client_RecvObjectiveState           (progress slots only)
   
   Do not confuse 0x2070 with 0x2071 — historical docs swapped these handlers. */

undefined4 __fastcall
Client_PacketDispatch(void *param_1,Packet_CharacterLevel *param_2,void *param_3)

{
  uint uVar1;
  undefined1 uVar2;
  undefined1 *in_EAX;
  Packet_GiveCredits *unaff_ESI;
  GiveXpPacketBody *unaff_EDI;
  
  *in_EAX = 1;
  uVar1 = param_2->dwOpcode;
  if (uVar1 < 0x8064) {
    if (uVar1 != 0x8063) {
      switch(uVar1) {
      case 0x2002:
        FUN_00809ad0();
        return 1;
      case 0x2003:
      case 0x2008:
      case 0x2009:
      case 0x200a:
      case 0x200c:
      case 0x200d:
      case 0x200e:
      case 0x200f:
      case 0x2022:
      case 0x2029:
      case 0x203d:
      case 0x2040:
      case 0x2041:
      case 0x2042:
      case 0x2043:
      case 0x2067:
      case 0x206a:
      case 0x2083:
      case 0x208a:
        goto switchD_00815749_caseD_2003;
      case 0x2004:
        FUN_0080ba20();
        return 1;
      case 0x2005:
        FUN_008153b0(param_3,param_2);
        return 1;
      case 0x2006:
        FUN_004ce320(&param_2->dwCoidLo,param_1);
        return 1;
      case 0x2007:
        FUN_00808ee0(param_3);
        return 1;
      case 0x200b:
        FUN_00809690(param_3);
        return 1;
      case 0x2010:
        FUN_0080bc40(param_3,param_1);
        return 1;
      default:
        return 0;
      case 0x2012:
        FUN_00812360(param_3);
        return 1;
      case 0x2013:
        FUN_0080af70();
        return 1;
      case 0x2014:
        FUN_0080ba70(param_2);
        return 1;
      case 0x2015:
        Client_RecvCreateCharacter();
        return 1;
      case 0x2016:
        Client_RecvCreateCharacter();
        return 1;
      case 0x2017:
                    /* case 0x2017 CharacterLevel → absolute money/XP apply */
        Client_RecvCharacterLevel(param_3,param_2);
        return 1;
      case 0x2018:
        FUN_008144f0();
        return 1;
      case 0x2019:
        FUN_008144b0();
        return 1;
      case 0x201a:
        FUN_00814470();
        return 1;
      case 0x201b:
        FUN_008122e0();
        return 1;
      case 0x201c:
        FUN_00814400();
        return 1;
      case 0x201d:
        Client_CreateVehicleObjectApply(param_3,0);
        return 1;
      case 0x201e:
        Client_CreateVehicleObjectApply(param_3,1);
        return 1;
      case 0x2020:
        Client_RecvDestroyObject(param_2);
        return 1;
      case 0x2021:
        Client_RecvBroadcast(param_3);
        return 1;
      case 0x2023:
        FUN_00812a60(param_3,param_2);
        return 1;
      case 0x2025:
        FUN_0080ce90();
        return 1;
      case 0x2026:
        FUN_007fc360();
        return 1;
      case 0x2028:
        FUN_00810670(param_3);
        return 1;
      case 0x202c:
        FUN_00808ea0();
        return 1;
      case 0x202d:
        FUN_00808980();
        return 1;
      case 0x2031:
        Client_RecvSkillStatusEffect(param_3);
        return 1;
      case 0x2032:
        FUN_00809070();
        return 1;
      case 0x2033:
        FUN_00808a90();
        return 1;
      case 0x2035:
      case 0x2039:
        Client_RecvInventoryGrabResponse(unaff_EDI,unaff_ESI);
        return 1;
      case 0x2037:
      case 0x203b:
        Client_RecvInventoryDropResponse();
        return 1;
      case 0x203c:
        Client_RecvInventoryEquip(param_2);
        return 1;
      case 0x203e:
        Client_RecvInventoryUnequipNotify();
        return 1;
      case 0x203f:
        Client_RecvInventoryUnequipResponse();
        return 1;
      case 0x2044:
        Client_RecvInventoryUsePaint(param_3);
        return 1;
      case 0x2046:
        Client_RecvInventoryUseItemResponse(param_3);
        return 1;
      case 0x2047:
        Client_RecvInventoryAddItem(param_3);
        return 1;
      case 0x2049:
        FUN_00810170();
        return 1;
      case 0x204c:
        Client_RecvCraftFromAssemblyKitResponse(param_2);
        return 1;
      case 0x204d:
        FUN_0080df40(param_3,param_2);
        return 1;
      case 0x204f:
        FUN_00809d20();
        return 1;
      case 0x2050:
        FUN_00809c70();
        return 1;
      case 0x2052:
        FUN_0080db30(param_3);
        return 1;
      case 0x2054:
        FUN_00810360();
        return 1;
      case 0x2058:
        FUN_008136b0();
        return 1;
      case 0x205b:
                    /* case 0x205B UnlockRegion -> Client_RecvUnlockRegion */
        Client_RecvUnlockRegion(param_1);
        return 1;
      case 0x205e:
                    /* case 0x205E GiveCredits → additive money */
        Client_RecvGiveCredits(unaff_EDI,unaff_ESI);
        return 1;
      case 0x205f:
        Client_AwardKillExperience(unaff_EDI);
        return 1;
      case 0x2060:
        FUN_00812320();
        return 1;
      case 0x2068:
        FUN_00810fd0(param_3);
        return 1;
      case 0x2069:
        FUN_005569a0(param_2);
        *in_EAX = 1;
        return 1;
      case 0x206b:
        FUN_008093c0();
        return 1;
      case 0x206c:
        Client_RecvGroupReactionCall(param_3,param_2);
        return 1;
      case 0x206d:
        Client_RecvNpcMissionDialog(param_3);
        return 1;
      case 0x206f:
        FUN_0080c2f0();
        return 1;
      case 0x2070:
        Client_RecvCompleteDynamicObjective(param_2);
        return 1;
      case 0x2071:
        Client_RecvObjectiveState(param_2);
        return 1;
      case 0x2075:
        FUN_00812d90();
        return 1;
      case 0x2076:
        FUN_00808ad0();
        return 1;
      case 0x2077:
        FUN_00814d80(param_3,param_2);
        return 1;
      case 0x2079:
        uVar2 = FUN_00811750();
        *in_EAX = uVar2;
        return 1;
      case 0x207b:
        FUN_0080c240();
        return 1;
      case 0x207d:
        FUN_0080e4c0();
        return 1;
      case 0x207f:
        FUN_0080a410();
        return 1;
      case 0x2081:
        FUN_0080e360();
        return 1;
      case 0x2084:
        FUN_0080ce50();
        return 1;
      case 0x2086:
        FUN_0080c130();
        return 1;
      case 0x2088:
        FUN_0080a170();
        return 1;
      case 0x208c:
        FUN_008134d0();
        return 1;
      case 0x208e:
        FUN_008091e0();
        return 1;
      case 0x2090:
        FUN_0080a0e0();
        return 1;
      case 0x2091:
        FUN_0080a020();
        return 1;
      case 0x2093:
        FUN_00809f10();
        return 1;
      case 0x2098:
        FUN_00809e90();
        return 1;
      case 0x209a:
        FUN_0080e1e0(param_3);
        return 1;
      case 0x209b:
        FUN_00809e30();
        return 1;
      case 0x209d:
        FUN_0080c040();
        return 1;
      case 0x209f:
        FUN_00809dd0();
        return 1;
      case 0x20a1:
        FUN_0080e0c0();
        return 1;
      case 0x20a3:
        FUN_0080dcc0();
        return 1;
      case 0x20a6:
        FUN_0080d930();
        return 1;
      case 0x20a8:
        FUN_0080d570(param_2);
        return 1;
      case 0x20a9:
                    /* case 0x20A9 SpecialEvent -> Client_RecvSpecialEvent (ECX=packet, stack=game)
                        */
        Client_RecvSpecialEvent(param_3);
        return 1;
      case 0x20aa:
        FUN_0080b3a0(param_3);
        return 1;
      case 0x20ac:
        FUN_00811810(param_3);
        return 1;
      case 0x20ad:
        FUN_0080a680(param_3);
        return 1;
      case 0x20af:
        FUN_0080be70();
        return 1;
      case 0x20b2:
        FUN_0080b100();
        return 1;
      case 0x20b5:
        FUN_0080d480();
        return 1;
      case 0x20b7:
        FUN_00808830();
        return 1;
      case 0x20ba:
        FUN_00808a10(param_3);
        return 1;
      case 0x20bc:
        FUN_008089a0(param_3);
        return 1;
      case 0x20be:
        FUN_0080bec0(param_2);
        return 1;
      case 0x20c0:
        FUN_008090d0();
        return 1;
      case 0x20c2:
        FUN_0080cfc0(param_3);
        return 1;
      case 0x20c3:
        *(uint *)(DAT_00d1b644 + 0x30) = param_2->dwUnknownHeader;
        return 1;
      case 0x20c4:
        FUN_008085b0(param_3);
        return 1;
      case 0x20c5:
        FUN_0080cbf0(param_3);
        return 1;
      }
    }
    if (param_2->dwCoidLo != 0xffffffff) {
      FUN_00540c50(param_2->dwUnknownHeader);
      return 1;
    }
    FUN_005409c0(param_2->dwUnknownHeader);
    return 1;
  }
  if (uVar1 == 0x9001) {
    FUN_0080c5e0(param_3);
switchD_00815749_caseD_2003:
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
```
## Version note (2026-07-23)

- Fresh Ghidra MCP `batch_decompile` for `0x00815710` reconfirmed CF/case set against this raw body (whitespace/unicode only).
- Clean C++ human-refined with opcode switch comments (mission/inventory/skill/XP); dual reviews under `docs/reconstruction/reviews/aa_00815710_*`.
- Related units already present (not re-emitted): `aa_00810f00` Client_RecvCharacterLevel, `aa_0080cac0` Client_RecvGiveCredits, `aa_0080ff00` Client_RecvCompleteDynamicObjective.
- Batch JSON: `docs/reconstruction/coverage/tmp_batch_packetdispatch.json`.
