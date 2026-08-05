# Function record: Client_CreateObjectFromCbidPacket_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008120d0` |
| **Canonical name** | `Client_CreateObjectFromCbidPacket_Inferred` |
| **Ghidra name** | `FUN_008120d0` |
| **Address** | `0x008120d0`–`0x008122de` (526 B exclusive) |
| **Module** | `autoassault.exe` base `0x400000` |
| **System** | client net / object create |
| **Dual** | W26-L 2026-07-29 **accept-with-gaps** |
| **Name confidence** | **Inferred** — plate string + create role vs ProcessSectorUpdate twin |

## Contract

```
// RET 8; returns object* or null
GameObject* Client_CreateObjectFromCbidPacket_Inferred(GameClient* game, Packet* pkt)
{
  obj = CVOGReaction_GiveItemByCbid(pkt->cbid_at_4);
  if (!obj) { log fail; return null; }
  obj->vtbl+8(cbid, *(game+0xe04), 0);
  obj->vtbl+0x1cc();
  fuse flag bit0 into obj[+0x184] from mask/flags;
  obj->vtbl+0xc4(pkt, mode=2, host, !pkt[0xa1], flag_u3, flag_u3);
  if (pkt[0xa1]) FUN_009972a0 + FUN_008024d0(... ids ...);
  // residual: optional FUN_0092a3b0 under flags
  if (pkt[0xc0]) FUN_007fb2b0(ids);
  return obj;
}
```

## Why this name

- Fail string embeds **`allocatenewobjectfromcbid`**.
- Exclusive create branch from resolve-or-create handlers (`0x201C` dual etc.).
- Sibling `FUN_00811e00` logs **ProcessSectorUpdate** — this is the allocate/create counterpart.
- `_Inferred` — no exact PDB method string beyond fail plate.

## Gaps

- Product packet / opcode English.
- Full vtbl `+0xc4` product semantics.
- `FUN_0092a3b0` reachability residual.
- Nested helper duals (`008024d0`, `007fb2b0`, factory) not OWN.
- Runtime wire create differential.

## Artifacts

See `aa_008120d0_FUN_008120d0.md`.
