# Review A (reconstruction fidelity): `aa_008635b0` Client_UI_InventoryItemClickDispatch

| Field | Value |
|---|---|
| **Stable ID** | `aa_008635b0` |
| **VA** | `0x008635b0` |
| **Canonical name** | `Client_UI_InventoryItemClickDispatch` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_008635b0_Client_UI_InventoryItemClickDispatch.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

UI click router for inventory/equip widgets (`__fastcall` this = `pWidget` in ECX):

1. Require `DAT_00d1b6d8`.
2. If item resolve null **or** store UI not ready → if `char+0xcd0==0` call **`Client_SendInventoryGrab_Hardpoint`**.
3. Else if cursor held + `FUN_00862860`: optional permanent-customize confirm (flags bit20 / `FUN_00513fc0`); then **`Client_SendInventoryDrop_Hardpoint`**.
4. Stash widget/item in `DAT_00d1e440` / `DAT_00d1e438` for confirm callback.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw / clean | `raw/aa_008635b0_…`, `reconstructed-exact/Client_UI_InventoryItemClickDispatch.cpp` |
| Callees | Grab_Hardpoint, Drop_Hardpoint |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Host gate | **High** | |
| Grab when no item / store not ready / no `+0xcd0` | **High** CF |
| Drop path when cursor + gate | **High** CF |
| Customize modal branch | **High** CF; string Probable |
| Global stash for confirm | **High** | |
| `__fastcall` pWidget | **Probable** | Plate |
| Clean fully refined | **Tentative** | Scaffold |

---

## 4. Control flow: clean ≡ raw

Routing predicates and named callees preserved.

---

## 5. Gaps / open

Full customize modal text path; store UI globals; runtime click matrix.

**Verdict:** **accept-with-gaps.**
