# Review A (reconstruction fidelity): `aa_0040da70` ClonedObject_GetDefBlob

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040da70` |
| **VA** | `0x0040da70` |
| **Canonical name** | `ClonedObject_GetDefBlob` (**INFERRED**) |
| **Aliases** | `FUN_0040da70`, clonebase def accessor |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B — MenuEquip nested residual) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0040da70_ClonedObject_GetDefBlob.md` |
| **System** | `inventory-transfer` / object layout |
| **Dual status** | **Present** (first dual pair) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**One-liner accessor** from a cloned object COM base to its **item/clonebase definition blob**:

```
cb = *( COM_adjust(this) + 0xac )   // via *( *(this+4)+4 ) + 0xac + this
if cb == 0: return 0
return *(cb + 0x3c)
```

Returns the def pointer used for subtype short `+0x3f4`, weapon flags `+0x536`, etc.

**MenuEquip path (`0x00502e90`):** for class **0xc** weapons:

1. `FUN_0040da70()` → def
2. Melee gate: `(char)*(short*)(def+0x3f4) == 9` → melee equip
3. Else bit tests on `*(def+0x536)` bits **2 / 0x10 / 4** → ranged slots 0/1/2

Also called from unequip dispatcher `00504f60`, tooltips `UI_BuildItemTooltipStats`, drop hardpoint path, other item-def readers.

Equivalent data is often inlined as `item[0x2a]…` / COM `+0xac` elsewhere; this helper packages the COM chase + `+0x3c`.

---

## 2. Calling convention

| Slot | Role |
|------|------|
| **ECX** | cloned object (this) |
| **EAX** | def blob* or null |

No stack args. No callees.

---

## 3. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_0040da70_*`, `reconstructed-exact/FUN_0040da70.cpp` |
| Live decompile | Ghidra 2026-07-29 ≡ raw |
| Parent dual | `A_aa_00502e90_Vehicle_MenuEquipByItemClass` |
| Sibling duals | unequip `00504f60`, weapon slot flags |
| Layout | COM `+0xac` clonebase; def at clonebase `+0x3c` |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| COM MI adjust via `+4/+4` | **Yes** |
| Load `+0xac` clonebase | **Yes** |
| Null → 0 | **Yes** |
| Return `*(clonebase+0x3c)` | **Yes** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Pure getter | **High** | no side effects |
| Def used for subtype/flags | **High** | MenuEquip consumers |
| Offsets `+0xac` / `+0x3c` | **High** | body + equip dual map |
| Product English “def blob” | **Tentative** | role sealed |

---

## 6. Gaps

1. Formal type name of returned blob (item template vs weapon def).
2. When `+0xac` is null (incomplete objects).
3. Runtime open.

**Verdict:** Def accessor sealed; MenuEquip weapon branch depends on it. **accept-with-gaps.**
