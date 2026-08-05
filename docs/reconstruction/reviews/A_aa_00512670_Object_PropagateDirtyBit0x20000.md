# Review A (reconstruction fidelity): `aa_00512670` Object_PropagateDirtyBit0x20000

| Field | Value |
|---|---|
| **Stable ID** | `aa_00512670` |
| **VA** | `0x00512670` |
| **Canonical name** | `Object_PropagateDirtyBit0x20000` (**INFERRED**) |
| **Aliases** | `FUN_00512670`, equip-path dirty preamble |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B — Equip nested residual) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_00512670_Object_PropagateDirtyBit0x20000.md` |
| **System** | `inventory-transfer` / object net-dirty |
| **Dual status** | **Present** (first dual pair) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Tiny dirty propagator** used as the first step of many equip / inventory mutators:

1. `*(object + 0x17c) |= 0x20000`
2. Walk parent chain at `object + 0xac` (singly-linked); for each non-null parent, `*(parent + 0x17c) |= 0x20000`

No other side effects. Same bit appears on Item_SetBroken / inventory place / equip hardpoint helpers as “object needs resync / serialize dirty.”

Equip-path callers (subset): `Vehicle_SetEquippedMeleeWeapon` (`004fe800`), `Vehicle_SetEquippedOrnament` (`004fe620`), powerplant / race / armor equip family, `InventoryGrid_PlaceItemFootprint` / remove siblings.

---

## 2. Calling convention

| Slot | Role | Evidence |
|------|------|----------|
| **ECX** | object (cloned object / vehicle COM base) | `__fastcall`; parents use object-style `+0x17c` / `+0xac` |
| return | void | |

Body is 8–10 instructions; no callees.

---

## 3. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_00512670_*`, `reconstructed-exact/FUN_00512670.cpp` |
| Live decompile | Ghidra 2026-07-29 ≡ raw |
| Parent equip duals | `A_aa_004fe800`, `A_aa_004fe620`, `A_aa_004fe1b0`, race/armor |
| Layout | `OBJECT_LAYOUTS.md` notes `FUN_00512670` dirty from inventory |
| Sibling | `Item_SetBroken` dual also dirties via this unit |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| OR `0x20000` at `+0x17c` | **Yes** |
| Parent walk `+0xac` until null | **Yes** |
| Each parent ORs same bit | **Yes** |
| No early exit other than null parent | **Yes** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Role = dirty bit set + parent propagate | **High** | body sealed |
| Bit immediate `0x20000` | **High** / Confirmed | live decompile |
| Parent link is `+0xac` | **High** | walk uses that offset |
| Product English for bit 17 | **Tentative** | flag sealed; name open |
| Always vehicle vs any object | **High** as “object” | many non-vehicle callers |

---

## 6. Gaps

1. Product name for mask bit `0x20000` (net dirty? visual? inventory stamp?).
2. Full parent-chain ownership (container vs graphics host) beyond offset seal.
3. Runtime / bit-exact open.

**Verdict:** Equip preamble dirty helper sealed. **accept-with-gaps.**
