# Reconstruction review: `aa_00813f40` Client_RecvInventoryEquip

| Field | Value |
|---|---|
| **Stable ID** | `aa_00813f40` |
| **VA** | `0x00813f40` |
| **Canonical name** | `Client_RecvInventoryEquip` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review (faithfulness of clean C++ to low-level / raw) |
| **Author of reconstruction** | Not this reviewer |
| **Verdict** | **accept-with-gaps** |

---

## 1. What was inspected

| Artifact | Path | Role |
|---|---|---|
| Raw | `raw/aa_00813f40_Client_RecvInventoryEquip.md` | Authoritative decompile |
| Annotated | `…annotated.md` | Scaffold |
| Exact C++ | `reconstructed-exact/Client_RecvInventoryEquip.cpp` | Human-refined clean |
| Function record | `functions/aa_00813f40_….md` | Status |
| Callee | `Vehicle_EquipPowerPlant` | Class-10 path |
| Packet docs | `Documentation/PACKET STRUCTURES.md` InventoryEquip 0x40 | Field map |
| Networking | `docs/networking.md` | S2C 0x203C; equip via Drop HARDPOINT=2 |

**Primary claims under review:**

1. Log line then resolve vehicle via `FUN_004bafe0(realm@+0x20, id@+0x18/+0x1c)`
2. Null vehicle → resolve item TFID, optional destroy (`FUN_009440e0`), return
3. Local owner path: vehicle `+0xb0` → vfunc `+0x1dc` equals `client+0xe98`
4. Local: `putInHand@+0x38==1` → resolve to hand; else cargo pull `FUN_00571010` + `FUN_00571b80`
5. Local UI: sheet refresh, cursor clear/set (`FUN_007fc150`/`FUN_007fc270`), or `FUN_00571620` place at srcX/Y
6. Local flags `client+0x30b4/0x30b5`, equip UI vcall
7. Non-local: resolve by type hint `+0x10` + TFID; switch clonebase type `6/10/0xc/0x10/0x1c`
8. Class 10 → graphics scale + `Vehicle_EquipPowerPlant(vehicle, plant, &prev, false)`
9. If previous out non-null → destroy view; `FUN_0092f120`

**Not re-authored.** Live re-decompile not performed.

---

## 2. What evidence was used

| Evidence | Source | Use |
|---|---|---|
| Raw pseudocode | Raw | Full CF + switch |
| Clean C++ | reconstructed-exact | Fidelity + signature modeling |
| PACKET STRUCTURES | Docs | 0x203C offsets putInHand/src/invType |
| Equip flow narrative | PACKET STRUCTURES hardpoint section | Drop type 2 → S2C equip |

---

## 3. What was confirmed

### 3.1 Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Debug log fields | **Yes** |
| Vehicle resolve / null path | **Yes** (clean returns on null vehicle after optional destroy; raw may fall through only when item also null — same terminal return) |
| Owner local gate | **Yes** |
| putInHand vs cargo pull | **Yes** |
| UI refresh + cursor paths | **Yes** |
| Non-local class switch cases | **Yes** |
| Power plant case 10 + EquipPowerPlant | **Yes** |
| Previous destroy + FUN_0092f120 | **Yes** |

### 3.2 Packet offsets

| Offset | Docs | Raw use | Clean |
|---|---|---|---|
| +0x08 | new item COID | TFID | **Yes** |
| +0x10 | global flag / type hint | resolve hint non-local | **Yes** (hint) |
| +0x18/+0x20 | vehicle id + flag | FUN_004bafe0 | **Yes** |
| +0x28 | old item | log + cursor clear predicate | **Yes** |
| +0x38 | bPutInHand | local branch | **Yes** |
| +0x39/+0x3A/+0x3B | srcX/Y/type | place + cursor | **Yes** |

### 3.3 Signature modeling

Raw: `void Client_RecvInventoryEquip(void *param_1)` with `in_EAX` client.  
Clean: explicit `(pPacket, pClient /* in_EAX */)` — **documentation improvement**, not a CF change. Prior scaffold that zeroed client would have been **wrong**.

### 3.4 Hardpoint class map (partial)

| Class | Helper | Confidence |
|---|---|---|
| 6 + subtype 10 | FUN_004fe620 + RTTI cast | Probable simple/gfx |
| 10 | Vehicle_EquipPowerPlant | **High** (named + type check in callee) |
| 0xc | weapon path FUN_004fe800 / FUN_004fe110 | Probable |
| 0x10 | FUN_004ff510 | Tentative |
| 0x1c | FUN_00502180 (armor-adjacent) | Probable (armor slot type 0x1c elsewhere) |

---

## 4. Discrepancies or improvements needed

| Item | Severity | Notes |
|---|---|---|
| Many FUN_* hardpoint helpers | Medium | Class map incomplete for wheelset etc. |
| `CONCAT31` type-hint packing in raw non-local resolve | Low | Clean uses `pkt[0x10]` byte — equivalent for low byte; high bits from prior owner path residue in raw are decompiler noise |
| Graphics scale `0x3f800000` (1.0f) | Doc | Present; purpose “show mesh” interpretive |
| Annotated layer | Meta | Still thin vs clean header |
| Runtime equip from Drop HARDPOINT | Open | Not observed this session |

**No CF revision required** for refined clean vs raw.

---

## 5. What remains uncertain

1. Full class→hardpoint naming for 0xc / 0x10 / 0x1c helpers.
2. Wheelset equip path (not in this switch).
3. Exact `FUN_00502e90` role on local path.
4. Whether `+0x10` is solely “global flag” (docs) or also type hint (raw resolve arg) — may be overloaded byte.
5. Runtime / differential not run.

---

## 6. Verdict

### **accept-with-gaps**

**Accept because:** Human-refined clean matches raw control flow and packet field usage; power-plant edge chains to reviewed `Vehicle_EquipPowerPlant`; client EAX modeled explicitly.

**Gaps:** Incomplete hardpoint helper map, wheelset open, no runtime seal. Status remains partial / human-refined, not complete.
