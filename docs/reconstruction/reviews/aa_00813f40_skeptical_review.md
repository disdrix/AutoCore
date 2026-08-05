# Skeptical / adversarial review: `Client_RecvInventoryEquip` @ `0x00813f40`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00813f40` |
| **Review type** | Skeptical / adversarial |
| **Date** | 2026-07-23 |
| **Scope** | S2C InventoryEquip handler + equip-chain claims |
| **Verdict** | **needs-more-evidence** |

---

## 1. What was inspected

| Path | Role |
|------|------|
| Raw / annotated / clean / function record | Package |
| `Vehicle_EquipPowerPlant` unit | Callee |
| PACKET STRUCTURES InventoryEquip | Wire layout |
| networking.md opcode table | Direction S2C |
| Unequip notify sibling | Symmetric clear path |

**Not performed:** live re-decompile, packet capture, disassembly.

---

## 2. Evidence used (authoritative body)

1. Resolves vehicle; null → maybe destroy item by TFID.
2. Owner equality against `in_EAX+0xe98` gates local UI/grid path.
3. `*(packet+0x38)==1` selects hand/cursor behavior.
4. Non-local switch on `*(item_clonebase+0x38)` with cases 6,10,0xc,0x10,0x1c.
5. Case 10 calls `Vehicle_EquipPowerPlant`.
6. Ends non-local path with optional destroy of previous + `FUN_0092f120`.

---

## 3. Attack results

### Claim 1 — Opcode 0x203C S2C InventoryEquip size 0x40

| Sub-claim | Attack result |
|-----------|----------------|
| Plate + PACKET STRUCTURES + dispatcher name | **Strong external.** |
| Body itself encodes opcode/size | **No** — handler receives already-sliced body. Size/opcode are dispatch-layer claims. |
| No C2S 0x203C builder | **Plate claim**; not proven by absence search in this unit alone (but networking docs agree equip is Drop HARDPOINT). |

### Claim 2 — Local path is “put in hand or place grid”

| Sub-claim | Attack result |
|-----------|----------------|
| putInHand byte gates resolve vs cargo pull | **Not broken.** |
| `FUN_007fc270(invTypeFrom)` is cursor UI | **Probable** (name from plate / equip flow docs). |
| `FUN_00571620` is PlaceItemFootprint | **Probable** (shared with drop/unequip units). |
| Local path does **not** call Vehicle_EquipPowerPlant | **Holds** — plant equip is non-local branch only in this decompile. **Important:** local player hardpoint visual may depend on other packets (Create / ghost masks) not this switch. |

### Claim 3 — Non-local hardpoint switch is complete equipment matrix

| Sub-claim | Attack result |
|-----------|----------------|
| Cases present for 6/10/0xc/0x10/0x1c | **Not broken.** |
| Default returns without equip | **Holds.** |
| Covers wheelset | **FALSIFIED as complete matrix** — wheelset not in switch; open question in system map. |
| Class 10 is power plant | **Strong** (callee + type check 10). |
| Class 0x1c is armor | **Probable** via `Vehicle_SetEquippedArmor` type 0x1c — but this handler calls `FUN_00502180`, not necessarily `SetEquippedArmor` by name. |

### Claim 4 — `+0x10` is object-type hint

| Sub-claim | Attack result |
|-----------|----------------|
| Passed as first arg to `CVOGReaction_ResolveObjectTarget` | **Not broken.** |
| Docs call it “new item global flag” | **Tension.** May be dual-use or docs incomplete; do not over-unify without more evidence. |

### Claim 5 — Signature / EAX client

| Sub-claim | Attack result |
|-----------|----------------|
| `in_EAX` used as client (`+0xe98`, UI ptrs) | **Not broken.** |
| Clean formalizes second arg | **OK** if documented; claiming MSVC standard cdecl two-arg is **unproven** — custom dispatch. |
| Zeroing client (old scaffold bug) | **Would break** local path — correctly fixed. |

### Claim 6 — Clean ≡ retail

| Sub-claim | Attack result |
|-----------|----------------|
| CF match | **Yes** for refined clean. |
| Decompiler ≡ retail | **Not sealed.** |
| Graphics scale blocks required for equip correctness | **Unknown** — may be visual only; stripping them is a port risk. |

### Claim 7 — Overconfident naming

| Name | Warranted? |
|------|------------|
| `Client_RecvInventoryEquip` | Working (plate + docs) |
| putInHand / srcX / invTypeFrom | Probable (docs + uses) |
| Full hardpoint map | **No** — partial |
| Completion “done” | **No** |

---

## 4. Alternate interpretations

### Minimal hard reading

```
log(vehicle, old, new);
veh = resolve_vehicle(pkt);
if (!veh) { maybe_destroy(item); return; }
if (owner(veh) == local_char) {
  item = putInHand ? resolve(item) : take_from_cargo(item);
  ui_and_cursor_or_place(item, pkt);
  return;
}
item = resolve(hint, item);
switch (type(item)) { ... hardpoint helpers ... }
destroy(previous_if_any); refresh();
```

### Risky over-read

- Local equip applies hardpoint swap in this function (it does not call EquipPowerPlant on local path).
- Switch is the full equip matrix including wheels.
- `+0x10` is only “global flag” with no resolve role.

---

## 5. What would seal or kill claims

| Evidence | Effect |
|----------|--------|
| Live 0x203C capture with putInHand true/false | Seal local branches |
| Name recovery for FUN_004fe800/110/510/02180 | Seal class map |
| Wheelset equip decompile | Close open system question |
| Confirm ghost mask interaction when local | Explain missing local hardpoint call |

---

## 6. Verdict

### **needs-more-evidence**

Faithful reconstruction of the decompile: **yes**. Server-port completeness for equip: **no** — local vs non-local split, incomplete class map, wheelset open, runtime open.

Do not mark verified complete.
