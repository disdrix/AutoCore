# Review B (skeptical / adversarial): `Client_RecvInventoryEquip` @ `0x00813f40`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00813f40` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Residual strengthen** | `2026-07-29` (pass 1 + dual-path re-seal) |
| **Counterpart** | `reviews/A_aa_00813f40_Client_RecvInventoryEquip.md` |
| **Verdict** | **accept-with-gaps** on CF + dual class map; residual runtime/diff only |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Client builds C2S 0x203C equip request | **Falsified** — S2C apply only; equip requested via Drop HARDPOINT=2 |
| 2 | Always places on hardpoint | **Falsified** — local path may put in hand/cursor or re-place grid after equip attempt |
| 3 | Local path is UI-only / never hardpoint-equips | **Falsified** — `FUN_00502e90` is full class equip dispatcher (plant/weapon/wheelset/armor + sounds); re-decompiled 2026-07-29 |
| 4 | Switch is complete equipment matrix including wheelset | **Holds for this unit** — case **0x10** → `FUN_004ff510` → `Vehicle_SetWheelset` (`vehicle+600`); prior “wheelset not in switch” was wrong |
| 5 | All object classes equip successfully | **Falsified** — default switch returns; non-local class 6 needs subtype 10; local class 6 accepts subtype 10 **or** 0xb only |
| 6 | Local and non-local class maps diverge on core slots | **Mostly falsified** — same helpers for 6/10/0xc/0x10/0x1c; **local-only** race item (6/0xb) and finer weapon slot bitfield |
| 7 | `+0x10` is only “global flag” with no resolve role | **Overstated conflict** — docs flag **is** the resolve first arg; dual-use of same TFID byte |
| 8 | Opcode/size proved by body alone | **Body-external** — sealed via sole PacketDispatch xref + docs (not body compare) |
| 9 | Framing is standard cdecl two-arg | **Custom** — stack packet + **EAX client**; call site `56 8b c5 e8…`; entry `8b f0` (ESI←EAX) |
| 10 | Class 0x10 “maybe armor / unknown” | **Falsified** — wheelset strings + `Vehicle_SetWheelset` + RTTI `CVOGWheelSet` on local path |
| 11 | `FUN_00502180` may not be armor | **Falsified** — body `"Tried to equip same armor %d"` + `Vehicle_SetEquippedArmor` @ `+0x254` |

---

## 2. Adversarial re-check of dual path (2026-07-29)

| Attack | Method | Result |
|---|---|---|
| Wheelset only on ghost path, not 0x203C | Decompile case `0x10` + `FUN_004ff510` | **Fails** — both non-local switch and local `FUN_00502e90` call wheelset equip |
| Local skips plant | Decompile `FUN_00502e90` case 10 | **Fails** — `Vehicle_EquipPowerPlant` + `menu_equip_powerplant` |
| Slot offsets guessed | Helper bodies | **Sealed**: ornament `+0x26c`, melee `+0x264`, weapon array `+0x260`, wheelset `+0x258` (600), armor `+0x254` |
| Multiple call sites / dual ABI | `get_function_xrefs` | **Sole** caller `Client_PacketDispatch` @ `0x0081597c` |
| Opcode not 0x203C | Cross docs + enum + sole case | **Holds** body-external seal |
| Product rename required for port | Roles sealed by strings/named callees | Renames optional; emit/apply by class ints is enough |

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Opcode 0x203C / size 0x40 | High / Confirmed | Wrong server emit |
| Local vs non-local branch | High | Wrong UI / wrong hardpoint apply |
| putInHand / srcX/Y/invType packet fields | High | Cursor/grid mis-sync |
| Local `FUN_00502e90` equip | High / Confirmed | Miss local hardpoint apply in port |
| Class 10 plant equip | High | Vehicle power wrong |
| Class 0xc melee vs attach split | High | Wrong weapon helper |
| **Class 0x10 wheelset** | **High / Confirmed** | Null `+0x258` / drive AV if emit wrong type |
| Class 0x1c armor | High / Confirmed | Armor slot wrong |
| Class 6 ornament | High | Ornament/`+0x26c` wrong |
| Local race item 6/0xb | High (local only) | Missing race equip on local apply |
| Local weapon slot bitfield | High (local only) | Wrong weapon index on local apply |
| Product helper names | Probable | Docs only |
| Runtime seal | Open | Edge cases |

---

## 4. Surviving contract for AutoCore

```
S2C InventoryEquip 0x203C (0x40):
  item TFID (+ global flag @+0x10), vehicle id+realm, old item,
  putInHand@+0x38, srcX/Y, invTypeFrom
Client:
  resolve vehicle; if local owner:
    hand resolve or cargo pull+unstamp → FUN_00502e90(vehicle,item) class equip
    → UI cursor/place/refresh
  else:
    resolve(item, globalFlag) → hardpoint equip by clonebase class
    destroy previous attachment view; refresh
C2S equip request is Drop type HARDPOINT=2, not 0x203C.
Class map (both paths):
  6/sub10 ornament +0x26c; 10 plant; 0xc melee +0x264 or weapon +0x260;
  0x10 wheelset +0x258; 0x1c armor +0x254
Class 0x10 MUST run wheelset equip (SetWheelset / +0x258).
Local-only: 6/sub0xb race item; weapon slot via clonebase+0x536 bits.
```

---

## 5. Open questions (residual only)

1. Optional formal renames for sealed helpers (leave FUN_* until registry pass).
2. Runtime putInHand true/false capture.
3. Ghost PostCorrection equip synthesis interaction (sibling — not body of this unit).
4. Bit-exact / differential.

**Not open:** wheelset case; local equip dispatcher; armor helper identity; sole opcode/ABI framing.

**Verdict:** Safe for server emit of 0x203C apply including **wheelset class 0x10**. Do not invent a client 0x203C request builder. Do not claim local path skips hardpoint equip. Prior skeptical review (`aa_00813f40_skeptical_review.md`) is **superseded** on claims 2–3 class matrix / local plant / wheelset.
