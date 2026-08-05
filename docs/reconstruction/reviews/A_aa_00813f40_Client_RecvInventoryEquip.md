# Review A (reconstruction fidelity): `aa_00813f40` Client_RecvInventoryEquip

| Field | Value |
|---|---|
| **Stable ID** | `aa_00813f40` |
| **VA** | `0x00813f40` |
| **Canonical name** | `Client_RecvInventoryEquip` |
| **Review date** | `2026-07-23` |
| **Residual strengthen** | `2026-07-29` (pass 1 + dual-path re-seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00813f40_Client_RecvInventoryEquip.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

S2C **0x203C** InventoryEquip (size **0x40**). Resolve vehicle + item; if local player owns the vehicle, hand/cursor or cargo-pull then **`FUN_00502e90` vehicle equip dispatcher** + UI; else non-local hardpoint class switch (ornament / plant / weapon / **wheelset** / armor). Equip request is C2S Drop HARDPOINT=2 — this unit is apply-only.

---

## 2. Inspected artifacts (this residual)

| Artifact | Path / evidence |
|---|---|
| Live Ghidra decompile | `0x00813f40` body |
| Live callees | `FUN_004ff510`, `FUN_00502e90`, `FUN_004fe620`, `FUN_004fe800`, `FUN_004fe110`, `FUN_00502180` |
| Call site bytes | `read_memory 0x00815979` → `56 8b c5 e8 bf e5 ff ff` |
| Entry prologue | `read_memory 0x00813f40` → `51 53 55 8b 6c 24 10 … 8b f0` (ESI←EAX client) |
| Sole xref | `get_function_xrefs(0x00813f40)` → `From 0081597c in Client_PacketDispatch [UNCONDITIONAL_CALL]` |
| Raw / annotated / clean / function record | package under `docs/reconstruction/` |
| Wire | `Documentation/PACKET STRUCTURES.md` InventoryEquip; `InventoryEquipPacket.cs` |
| Prior dual | `aa_00813f40_reconstruction_review.md` / `aa_00813f40_skeptical_review.md` (superseded on class map / local equip / wheelset) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| **Opcode S2C `0x203C`, size `0x40`** | **High / Confirmed** | Sole xref PacketDispatch case `0x203c` @ `0x0081597c`; PACKET STRUCTURES Size=`0x40`; `GameOpcode.InventoryEquip` |
| **Framing: packet stack + client EAX** | **High / Confirmed** | Call site `PUSH ESI; MOV EAX,EBP; CALL`; body `MOV ESI,EAX` then uses `in_EAX` as client |
| Log string then vehicle resolve | **High** | `"Requesting InventoryEquip: char:%I64d Old:%I64d New:%I64d\n"`; `FUN_004bafe0(realm@+0x20, id@+0x18/+0x1c)` |
| Null vehicle → resolve item TFID, optional destroy | **High** | `Object_ResolveFromTFID` + `FUN_009440e0` |
| Local owner gate: vehicle `+0xb0` → vfunc `+0x1dc` vs `client+0xe98` | **High** | CF match |
| `putInHand@+0x38` local hand resolve vs cargo pull | **High** | Documented packet field; body branch |
| Local cargo pull `FUN_00571010` + unstamp `FUN_00571b80` | **High** CF | Roles inferred from inventory grid units |
| **Local equip via `FUN_00502e90` (thiscall vehicle, item)** | **High / Confirmed** | Full class switch + `menu_equip_*` sounds; **not** UI-only |
| Local UI: sheet refresh, cursor clear/set, place `FUN_00571620` | **High** | Body + PlaceItemFootprint sibling |
| Non-local resolve uses TFID global flag `+0x10` as resolve first arg | **High** | Docs “global flag” ≡ resolve first arg — same byte, dual use |
| Class **6** + subtype **10** → `FUN_004fe620` ornament `+0x26c` | **High** | Helper body stores `*(vehicle+0x26c)`; string `"Set ornament of unhappy type…"` |
| Class **10** → `Vehicle_EquipPowerPlant` | **High** | Named callee; local also RTTI `CVOGPowerPlant` |
| Class **0xc** subtype **9** → `FUN_004fe800` melee `+0x264` | **High** | Helper `+0x264`; `"Set weapon melee of unhappy type…"` |
| Class **0xc** else → `FUN_004fe110` → `Vehicle_AttachWeapon` (`+0x260`) | **High** | `"Tried to equip same weapon %d"`; array index at `+0x260` |
| **Class `0x10` → `FUN_004ff510` → `Vehicle_SetWheelset` (`+0x258`)** | **High / Confirmed** | Helper reads `vehicle+600` (`0x258`); strings wheelset; named `Vehicle_SetWheelset` |
| Class **0x1c** → `FUN_00502180` → `Vehicle_SetEquippedArmor` (`+0x254`) | **High / Confirmed** | Helper `+0x254`; `"Tried to equip same armor %d"`; named `Vehicle_SetEquippedArmor` |
| Previous-out destroy + `FUN_0092f120` (non-local) | **High** | Tail after switch |
| No C2S 0x203C builder (equip via Drop HARDPOINT=2) | **High** | Absence in this unit + inventory/networking docs |
| Product names for equip helpers | **Open / Probable** | Roles sealed; formal renames optional |

---

## 4. Dual-path class map (local ≡ non-local helpers)

Non-local switch is on `clonebase+0x38`. Local path uses the **same** equip helpers inside `FUN_00502e90` (thiscall `ECX=vehicle`, stack item). Local adds audio + RTTI + graphics bind; non-local adds scale/`0x3f800000` prep and previous-out destroy.

| Class (`clonebase+0x38`) | Subtype / gate | Helper | Vehicle slot | Seal strings / RTTI | Local-only extras |
|---:|---|---|---|---|---|
| 6 | subtype **10** (`+0x3c→+0x3f4`) | `FUN_004fe620` | **`+0x26c`** | `"Set ornament of unhappy type…"` | `menu_equip_item`; race subtype **0xb** → `Vehicle_SetEquippedRaceItem` (**local only**) |
| 10 | — | `Vehicle_EquipPowerPlant` | plant (via named helper) | RTTI `CVOGPowerPlant` (local) | `menu_equip_powerplant` |
| 0xc | subtype **9** | `FUN_004fe800` | **`+0x264`** | `"Set weapon melee…"`; RTTI `CVOGWeaponMelee` (local) | `menu_equip_weapon` |
| 0xc | else | `FUN_004fe110` → `Vehicle_AttachWeapon` | **`+0x260`** array | `"Tried to equip same weapon %d"` | Local selects slot via clonebase `+0x536` bits (2/0x10/4 → index 0/1/2) + mask bits |
| **0x10** | — | **`FUN_004ff510` → `Vehicle_SetWheelset`** | **`+0x258` (600)** | `"Tried to equip same wheelset %d"` / `"Set wheelset2 of unhappy type…"`; RTTI `CVOGWheelSet` (local) | `menu_equip_wheelset`; NetObject mask bit 1 |
| 0x1c | — | `FUN_00502180` → `Vehicle_SetEquippedArmor` | **`+0x254`** | `"Tried to equip same armor %d"`; RTTI `CVOGArmor` (local) | `menu_equip_armor`; mask `0x40000000` |
| other | — | default return | — | no equip | same |

**Prior residual “wheelset not in this switch” is FALSIFIED** — both paths equip class **0x10** via `FUN_004ff510` → `Vehicle_SetWheelset`.

**Prior residual “local path is UI-only” is FALSIFIED** — local calls `FUN_00502e90`, which is the full class equip dispatcher.

---

## 5. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Log + vehicle resolve / null destroy path | **Yes** |
| Local hand/cargo/`FUN_00502e90`/UI/flags | **Yes** |
| Non-local class switch + previous destroy | **Yes** |
| Case 0x10 wheelset helper | **Yes** (both; naming sealed) |
| No invented clamps | **Yes** |
| Clean `FUN_00502e90` prototype | **Weak** — clean decl is single-arg; plate documents thiscall vehicle+item correctly |

---

## 6. Packet field seal (body uses)

| Offset | Body use | Docs |
|---:|---|---|
| `+0x08/+0x0c` | New item TFID (log + resolve) | item COID |
| `+0x10` | Non-local `ResolveObjectTarget` first arg (via `CONCAT31`) | new-item global flag |
| `+0x18/+0x1c` | Vehicle id to `FUN_004bafe0` + log “char” | vehicle COID |
| `+0x20` | Vehicle realm/global to `FUN_004bafe0` | vehicle global flag |
| `+0x28/+0x2c` | Old item log; local empty-FF check with putInHand | old item COID |
| `+0x38` | putInHand branch | `bPutInHand` |
| `+0x39/+0x3a` | `FUN_00571620` place coords | src X/Y |
| `+0x3b` | `FUN_007fc270(invTypeFrom)` | source inv type |

---

## 7. Gaps

1. Optional product renames (`Vehicle_SetOrnament_Inferred`, local equip dispatcher, etc.).
2. Runtime putInHand true/false / live equip capture.
3. Ghost `VehicleNet_PostCorrectionEvent` synthesis (sibling path — not this body).
4. Bit-exact / differential open.
5. Clean signature of `FUN_00502e90` still under-typed (cosmetic to CF plate).

**Verdict:** Equip apply handler CF faithful; hardpoint class map + wheelset path **sealed static on both local and non-local paths**. **accept-with-gaps.**
