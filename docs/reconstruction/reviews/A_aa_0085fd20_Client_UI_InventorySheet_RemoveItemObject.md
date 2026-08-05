# Review A (reconstruction fidelity): `aa_0085fd20` Client_UI_InventorySheet_RemoveItemObject

| Field | Value |
|---|---|
| **Stable ID** | `aa_0085fd20` |
| **VA** | `0x0085fd20` |
| **Canonical name** | `Client_UI_InventorySheet_RemoveItemObject` |
| **Aliases** | `FUN_0085fd20`, thin wrapper → `Client_UI_InventorySheet_RemoveByCoid` (`0x0085fcc0`) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B — AddItem/Equip sheet residual) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0085fd20_Client_UI_InventorySheet_RemoveItemObject.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** (first dual pair) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Thin **item* → COID pair** adapter for inventory **sheet** remove:

```
// EAX = item*
push *(item + 0x164)   // COID hi
push *(item + 0x160)   // COID lo
call FUN_0085fcc0      // RemoveByCoid (ESI = sheet*, set by caller)
```

Does **not** set sheet `ESI` — callers must establish sheet before call (sealed in parent dual `aa_0085fcc0` §7).

---

## 2. Calling convention — SEALED (bytes)

```text
; 0x0085fd20
mov ecx, [eax+0x164]
mov edx, [eax+0x160]
push ecx
push edx
call FUN_0085fcc0   ; rel32 → 0x0085fcc0
ret
```

| Slot | Role |
|------|------|
| **EAX** | item object* |
| **ESI** | sheet* (implicit, caller-owned; not touched here) |
| stack | none beyond pushes into callee |

`read_memory`: `8B 88 64 01 00 00 8B 90 60 01 00 00 51 52 E8 8D FF FF FF C3`.

---

## 3. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_0085fd20_*`, `reconstructed-exact/FUN_0085fd20.cpp` |
| Callee dual | `A_aa_0085fcc0_Client_UI_InventorySheet_RemoveByCoid` §7.1 |
| Sibling remove | `A_aa_008c2940_UI_InventorySheet_RemoveItemByCoid` (pushes COIDs itself) |
| Xrefs | `0x00810949`, `0x007fee73`, `0x007fef14`, `0x0093d7f1`, `0x00945111`, `0x00945194` |
| Parent chains | GrabApplyToCursor `0x0093d6e0`, sell/loot UI, destroy paths |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Load item `+0x164` then `+0x160` | **Yes** |
| Push hi, lo | **Yes** |
| Tail call RemoveByCoid | **Yes** |
| No other logic | **Yes** |

---

## 5. Offsets

| Offset | Role | Confidence |
|--------|------|------------|
| item `+0x160` | COID lo | **Confirmed** (family-wide) |
| item `+0x164` | COID hi | **Confirmed** |

---

## 6. Gaps

1. Sheet ESI identity per caller (documented at callee dual; not re-proven here).
2. Runtime / bit-exact open.

**Verdict:** Trivial adapter sealed. **accept-with-gaps.**
