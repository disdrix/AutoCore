# Review A (reconstruction fidelity): `aa_008e5ce0` Client_UI_CraftHost_BindObjectByTfid_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008e5ce0` |
| **VA** | `0x008e5ce0`–`0x008e5df3` |
| **Canonical name** | `Client_UI_CraftHost_BindObjectByTfid_Inferred` |
| **Prior names** | `FUN_008e5ce0`, `Named_CalleeOf_Named_CalleeOf_Client_RefreshOpenMissionUiWindow_008e5ce0` |
| **Review date** | `2026-08-04` (WQ8R-H dual seal) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_008e5ce0_Client_UI_CraftHost_BindObjectByTfid_Inferred.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** (A + B) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Resolve a 64-bit object id to a live object pointer and bind it into a craft/RE host panel (`FUN_008e5990`). Invalid sentinel TFID clears the bind.

Resolution order:

1. If vehicle cargo grid present → `InventoryGrid_FindItemByCoid`.
2. Else/also under locker + UI flag → same find.
3. If null or **Broken** (`+0x17c` bit 19) → scan equip TFID table `char+0x5a0` (count `FUN_00522000`) → `CVOGReaction_ResolveObjectTarget(1, lo, hi)`.
4. Non-null → `FUN_008e5990(host, obj)`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_008e5ce0_FUN_008e5ce0.md` (+ 2026-08-04 re-verify) |
| Annotated | `docs/reconstruction/raw/aa_008e5ce0_FUN_008e5ce0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_UI_CraftHost_BindObjectByTfid_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_008e5ce0.cpp` |
| Live | Ghidra `batch_decompile` + `force_decompile` + `read_memory` (entry + bind tail) + caller context |
| Not performed | `disassemble_bytes`, Launcher, bit-exact, runtime |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| stdcall `RET 0x0C` (host, lo, hi) | **High** | prologue + ret bytes |
| Invalid `(lo&hi)==−1` → bind null | **High** | early path |
| Host is thiscall ECX for `FUN_008e5990` | **High** | invalid + success tails reload ECX from stack |
| FindItemByCoid + broken skip | **High** | same bit as tooltip unit |
| Equip table @ +0x5a0 | **High** | parent `FUN_008e5e00` same layout |
| “Craft host” product class name | **Inferred** | from `FUN_008e5990` recipe/slot side effects |
| `FUN_00522000` semantics | **Tentative** | unowned; used as loop bound |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Invalid clear | Yes |
| Null character return | Yes |
| Cargo/locker find | Yes (compound short-circuit preserved in notes) |
| Broken → equip scan | Yes |
| Bind non-null | Yes |

---

## 5. Gaps

1. Product RTTI name of host panel.
2. Full `FUN_00522000` / equip-array capacity vs UI flag interaction.
3. Whether broken items ever bind via equip path after Resolve (Resolve may return broken — then bind still fires if non-null).
4. Runtime selection UX.
5. Bit-for-bit / differential.

**Verdict:** **accept-with-gaps**
