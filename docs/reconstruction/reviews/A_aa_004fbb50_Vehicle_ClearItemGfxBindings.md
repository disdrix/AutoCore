# Review A (reconstruction fidelity): `aa_004fbb50` Vehicle_ClearItemGfxBindings

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fbb50` |
| **VA** | `0x004fbb50` |
| **Canonical name** | `Vehicle_ClearItemGfxBindings` |
| **Aliases** | `FUN_004fbb50`, equip-path unbind helper before slot replace |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B — Equip callee residual) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004fbb50_Vehicle_ClearItemGfxBindings.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** (first dual pair) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

On vehicle equip/replace paths, when vehicle has character host at COM `+0xb0` and **item** non-null:

1. `CNDDoubleList_InvokePredicateAndRemove` (`FUN_004e2600`) on **`item+0x160`** list (`param_2+0x58`) with predicate `LAB_004f5400`.
2. If character resolve `vtbl+0x1dc` non-null **and** `char+0x250` (vehicle) non-null: resolve again and **re-run** the same list remove.
3. Item vcall **`+0x40(1)`** — enable/flag set (same family PlaceItem uses).

Used by weapon / melee / ornament / wheelset / armor equip helpers when clearing prior graphics base (`bSkipUnbind==0` paths).

---

## 2. Calling convention

| Slot | Role |
|------|------|
| **ECX** | vehicle (this) — COM base with `+4/+4/+0xb0` character host |
| stack0 | item* being unbound / prepared |
| return | void |

Xrefs (subset): `004fe661` ornament, `004fe865` melee, `004fe226` weapon attach, `004ff5c6` wheelset, `005024a1`/`005020c1` armor, multiple `004ff3**` equip-from-create paths.

---

## 3. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_004fbb50_*`, `reconstructed-exact/FUN_004fbb50.cpp` |
| Live decompile | ≡ raw |
| Parent equip duals | `004fe620`, `004fe800`, `004fe110`, `004ff510`, `00502180` |
| List helper | `A_aa_004e2600_CNDDoubleList_InvokePredicateAndRemove_Inferred` (if present) / `FUN_004e2600` |
| Equip notify | `aa_00813f40` → class helpers → this unit |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Gate host `+0xb0` and item non-null | **Yes** |
| First `FUN_004e2600(&LAB_004f5400, item+0x58*4, 0)` | **Yes** — `param_2+0x58` |
| Nested char resolve `+0x1dc` and `+0x250` | **Yes** |
| Second list remove under vehicle present | **Yes** |
| Final `item.vtbl+0x40(1)` | **Yes** |
| Early no-op if gates fail | **Yes** |

---

## 5. Offsets

| Offset | Role | Confidence |
|--------|------|------------|
| vehicle COM `+0xb0` | character host* | **High** (equip family) |
| char `vtbl+0x1dc` | resolve character / player object | **High** as call |
| char `+0x250` | vehicle* | **High** (UnequipNotify dual) |
| item `+0x160` (`[0x58]`) | double-list head for gfx/bind entries | **High** as list arg |
| item vtbl `+0x40` | set flag / activate | **High** as call |

---

## 6. Gaps

1. Predicate `LAB_004f5400` product meaning (which nodes removed).
2. Why second remove only when `char+0x250 != 0` (likely “only if still in vehicle world”).
3. Runtime / bit-exact open.

**Verdict:** Equip unbind leaf sealed at CF level. **accept-with-gaps.**
