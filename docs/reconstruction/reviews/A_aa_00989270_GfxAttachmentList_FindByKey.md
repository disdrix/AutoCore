# Review A (reconstruction fidelity): `aa_00989270` GfxAttachmentList_FindByKey

| Field | Value |
|---|---|
| **Stable ID** | `aa_00989270` |
| **VA** | `0x00989270` |
| **Canonical name** | `GfxAttachmentList_FindByKey` (**INFERRED**) |
| **Aliases** | `FUN_00989270`, circular list find-by-int |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B — Equip nested residual) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00989270_GfxAttachmentList_FindByKey.md` |
| **System** | graphics / `inventory-transfer` (ornament equip) |
| **Dual status** | **Present** (first dual pair) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Circular singly-linked list lookup** on a list head at `this+0xc`:

```
node = *head
while node != head:
  if *(node[2] + 8) == key: return node + 2   // payload ptr
  node = *node
return null
```

**Equip path:** `Vehicle_SetEquippedOrnament` (`004fe620`) when vehicle graphics host `+0x48` has attachment table with `count > 0`:

- Call `FUN_00989270(100)` (key **100**)
- If hit and ornament slot `+0x26c` non-null: copy floats from `*entry + 0x20 / +0x24` into vehicle `+0x3bc / +0x3c0` (ornament attach offsets / scales residual)

Also used by exhaust FX path `Drive_s_VEHICLE_EXHAUST_d` and other attachment lookups — key is domain-specific int id.

---

## 2. Calling convention

| Slot | Role |
|------|------|
| **ECX** | list owner (this) with head at `+0xc` |
| stack0 | int key |
| **EAX** | payload (`node+2`) or null |

---

## 3. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_00989270_*`, `reconstructed-exact/FUN_00989270.cpp` |
| Live decompile | Ghidra 2026-07-29 ≡ raw |
| Parent dual | `A_aa_004fe620_Vehicle_SetEquippedOrnament` |
| Ornament call | key **100**; writes vehicle `+0x3bc/+0x3c0` |
| Sibling exhaust callers | `FUN_004ff850` family |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Start at `*(*(this+0xc))` | **Yes** (head node) |
| Stop when node == head | **Yes** |
| Key at `*(node[2]+8)` | **Yes** |
| Return `node+2` or 0 | **Yes** |
| No mutation | **Yes** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Pure find; no insert/delete | **High** | body sealed |
| Circular list via head sentinel | **High** | classic pattern |
| Ornament equip uses key 100 | **High** | parent decompile |
| Product key dictionary (100=?) | **Tentative** | value sealed |
| List owner type name | **Open** | offset `+0xc` only |

---

## 6. Gaps

1. Product meaning of key **100** (attachment class?).
2. Full node layout beyond key at payload `+8`.
3. Runtime open.

**Verdict:** Find-by-key helper sealed; ornament equip consumer sealed. **accept-with-gaps.**
