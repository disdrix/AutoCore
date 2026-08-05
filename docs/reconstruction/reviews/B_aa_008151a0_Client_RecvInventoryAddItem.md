# Review B (skeptical / adversarial): `aa_008151a0` Client_RecvInventoryAddItem

| Field | Value |
|---|---|
| **Stable ID** | `aa_008151a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Residual pass** | `2026-07-29` — see `reviews/a_008151a0.md` |
| **Counterpart** | `reviews/A_aa_008151a0_Client_RecvInventoryAddItem.md` |
| **Verdict** | **accept-with-gaps** on CF + sealed residual facts; runtime/diff still open |

---

## 1. Claims under attack

| # | Claim | Attack | Residual outcome |
|---|---|---|---|
| 1 | Body proves S2C opcode `0x2047` | **Falsified as body claim** — no opcode immediate | **Sealed via PacketDispatch** `case 0x2047` → this VA (**High**, external) |
| 2 | Plate: “skip place when `@+0x12` non-zero” | **Falsified vs body** — non-zero **and** in-grid → `FUN_00571830` | **Confirmed falsified**; correct polarity sealed |
| 3 | Signature is portable `__cdecl(client)` only | **Weak** without packet arg | **Sealed retail shape:** stack client + **EBX packet** (prologue) |
| 4 | Always places into cargo on success | **Falsified** — success `@+0x18` only gates loot/place; re-find may fail internally | Survives |
| 5 | Loot line always fires | **Falsified** — requires `DAT_00d1b8dc` and success | Survives |
| 6 | Clean is finished exact | **Overstated** — scaffold fidelity yes; bit-exact open | Survives |
| 7 | Server XY `@+0x10/+0x11` drive client place | **Falsified for this unit** — body never loads them | **Sealed absence** |
| 8 | `FUN_00571830` is generic “place into cargo” | **Overstated** — helper only merges qty on found COID | **Sealed as stack-qty merge** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Success byte `@+0x18` early-out | **High** | Apply failed adds as loot |
| Place vs re-find polarity of `@+0x12` | **High** (body + C2S serialize) | Server merge flag inverted → wrong path |
| Loot sprintf paths | **High** | UI string desync only |
| Opcode binding (dispatch) | **High** | Wrong table → dead handler |
| Register framing (EBX packet, stack client) | **High** | Silent wrong memory |
| XY ignored by Recv | **High** | Server-only slot authority misimplemented |
| Helper product names (PDB) | Tentative | Rename churn only |
| Runtime capture matrix | Open | Live edge cases |

---

## 3. Cross-check against raw

Authoritative shape (re-decompile 2026-07-29 ≡ frozen raw):

```
FUN_007a69d0();
item = Resolve(1, pkt+8, pkt+0xc); if !item return;
if !(char)pkt[+0x18] return;
optional "Received Loot" / Broken / xN  via channel 0x17;
optional loot UI client+0xf38;
if !flag@+0x12 || !char || !vehicle || !FindInGrid(COID):
  FUN_00945540(client);   // re-find / full loot place
else:
  FUN_00571830(qty@+0x14, lo, hi);  // qty merge on existing
widget refresh; FUN_0092ce90();
```

Clean preserves this. Plate header’s historical “skip place when non-zero” is the reverse of the compound `if` — **trust body, not that plate sentence**.

Cross-link to C2S `Inventory_SerializeAddItemPacket`: sender `+0x12` is `bAddToExistingItem` (1 on stack-merge path, 0 on free-slot). Recv non-zero ≈ merge/place existing; zero ≈ re-find. Survives attack.

Helper attack:

| Helper | Prior gloss | Adversarial read of body | Survives as |
|--------|-------------|--------------------------|-------------|
| `FUN_00571010` | “find” | Walk cargo; match `+0x160/+0x164` | Find-by-COID **High** |
| `FUN_00571830` | “place” | Get qty vtbl+0x25c; set cur+delta +0x260 | **Merge only** |
| `FUN_00945540` | “re-find” | Free slot + footprint **or** stack scan → may call 71830; lootpickup SFX | Full place/loot **High** |

---

## 4. Surviving contract for AutoCore

```
On S2C opcode 0x2047 (PacketDispatch → this handler):
  packet in EBX; client formal on stack
  resolve item COID @+0x08/+0x0c; bail if null
  if success@+0x18 == 0: return
  optional loot chat (qty@+0x14, broken bit, name vfunc, channel 0x17)
  optional loot UI inject (client+0xf38)
  if addToExisting@+0x12 && char/vehicle ready && item already in grid:
    merge qty via FUN_00571830 (does not use XY)
  else:
    re-find / full place FUN_00945540 (client finds free slot; ignores wire XY)
  refresh inventory widgets + mission-related UI
Do not treat plate "skip place" wording as authoritative.
Do not require client to honor server X/Y for this opcode body.
```

---

## 5. Open questions

1. ~~Exact PacketDispatch opcode for this VA~~ → **Sealed `0x2047`**.
2. ~~Full S2C field consumption~~ → body map sealed; XY unread.
3. ~~Semantics of `FUN_00945540` vs `FUN_00571830`~~ → roles sealed (full place vs qty merge).
4. Product label of channel `0x17` beyond constant.
5. Runtime add / loot / stack-merge capture still open.
6. EDI / thiscall handoffs into callees (decompiler residual).

**Verdict:** Safe as CF map for add-notify; residual pass sealed opcode, framing, polarity, helpers. Runtime/diff still open — **accept-with-gaps**.
