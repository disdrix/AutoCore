# Annotated: Client_SendInventoryEquipC2S (`aa_00931440`)

| Field | Value |
|---|---|
| Stable ID | `aa_00931440` |
| VA | `0x00931440`–`0x009314ec` |
| System | `inventory-transfer` |
| Date | `2026-07-29` (W19-T) |

## Machine-level notes

- **ABI (bytes > decompiler labels):** `EAX` = item, `ECX` = client, stack mode (`RET 4`). Decompiler `__thiscall(param_1,param_2)` + `in_EAX` matches this once ECX=client and EAX=item are recognized.
- **Role:** emit **C2S equip / type-0xe customize** packet after parent pre-gates succeed. Does **not** perform equip validation (that is `Client_ConfirmEquipOrCustomizeItem` / hardpoint drop path).
- **Net iface:** `client+0xc78` object; vtbl slot **`+0x18`** send: `(token=-1, buf, size, flag=0)`.
- **Always returns 0** — success is signalled by the **caller** (e.g. ConfirmEquip returns 1 after call).

## Annotated CF

```c
// Client_SendInventoryEquipC2S(client /*ECX*/, item /*EAX*/, mode /*stack*/)
uint32_t Client_SendInventoryEquipC2S(Client *client, Item *item, uint8_t mode)
{
  CloneMeta *meta = *(CloneMeta **)(item + 0xa8);
  int type = *(int *)(meta + 0x38);

  if (type == 0xe) {
    // Short customize / vehicle-switch style packet (AutoCore opcode name VehicleSwitch = 0x2053)
    // Layout size 0x10:
    //   +0x00 u32 opcode 0x2053
    //   +0x08 u32 item COID lo  (item+0x160)
    //   +0x0c u32 item COID hi  (item+0x164)
    Packet2053 pkt;
    pkt.opcode = 0x2053;
    pkt.coidLo = *(u32 *)(item + 0x160);
    pkt.coidHi = *(u32 *)(item + 0x164);
    if (*(void **)(client + 0xc78) != NULL) {
      SendViaNet(client+0xc78, /*token*/ -1, &pkt, /*size*/ 0x10, /*flag*/ 0);
      return 0;
    }
    // null net: no send, fall to return 0
  }
  else {
    // Full inventory equip request (opcode 0x203c, size 0x40)
    //   +0x00 u32 opcode 0x203c
    //   +0x08..+0x17 TFID-ish 16B from item+0x160..+0x16c
    //   +0x38 byte 0
    //   +0x3b mode (param)
    Packet203c pkt;
    pkt.opcode = 0x203c;
    memcpy(&pkt.tfid, item + 0x160, 16);
    pkt.byte_38 = 0;
    pkt.mode    = mode;
    if (*(void **)(client + 0xc78) != NULL) {
      SendViaNet(client+0xc78, -1, &pkt, 0x40, 0);
    }
  }
  return 0;
}
```

**Note on stack locals:** decompiler `local_50`/`local_40` names reflect frame offsets; type-0xe buffer starts at `local_50` (opcode at `[esp]` after frame setup), type-other buffer at `local_40` (opcode `0x203c`). Size args **0x10** vs **0x40** sealed in both decompile and bytes (`push 0x10` / `push 0x40` before vtbl call).

## Type `0xe` product context (caller-owned)

Parent `Client_ConfirmEquipOrCustomizeItem` gates type `0xe` with town check and toast  
`"This item can only be changed in town."` before calling this unit.  
Hardpoint drop path `Client_SendInventoryDrop_Hardpoint` also calls this unit for type `0xe` with **mode=1**.

## Open questions

1. Full C2S wire layout for `0x203c` body fields beyond TFID + mode (remaining 0x40-size padding zeros).
2. Product English for type `0xe` (paint / customize / vehicle-switch).
3. Product name of net object at `client+0xc78` and vtbl `+0x18`.
4. Whether S2C `InventoryEquip` 0x203C shares framing with this C2S request (same opcode id, different direction).
