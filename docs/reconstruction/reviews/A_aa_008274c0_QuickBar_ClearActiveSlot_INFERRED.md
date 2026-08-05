# Review A (reconstruction fidelity): `aa_008274c0` QuickBar_ClearActiveSlot_INFERRED

| Field | Value |
|---|---|
| **Stable ID** | `aa_008274c0` |
| **VA** | `0x008274c0` |
| **Canonical name** | `QuickBar_ClearActiveSlot_INFERRED` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_008274c0_QuickBar_ClearActiveSlot_INFERRED.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Clears currently selected QuickBar UI slot locally: `CVOGCharacter_SetQuickBarItem(slot, -1)` and `SetQuickBarSkill(slot, -1)`; zeros `QuickBarSlotPayload_INFERRED` near **this+0x548** (kind=0, value=-1). Slot index from row/col **[0x140]/[0x141]** as `row*10+col` (ESI dword indices 0x140/0x141). Callers often follow with `Client_SendQuickBarUpdateFromUi` (IsItem=1, Value=-1) for server persist. Name `_INFERRED` — full UI refresh side effects partial.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_008274c0_QuickBar_ClearActiveSlot_INFERRED.md` (or `aa_008274c0_FUN_008274c0.md`) |
| Annotated | `docs/reconstruction/raw/aa_008274c0_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/QuickBar_ClearActiveSlot_INFERRED.cpp` |
| Function record | `docs/reconstruction/functions/aa_008274c0_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Clears item and skill for slot` | High | Callees SetQuickBar* |
| `Payload zero kind=0 value=-1` | High | Plate |
| `Slot = col + row*10` | High | Body math |
| `Local clear; server via separate send` | High | Plate |
| `Full UI refresh map` | Medium | INFERRED residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Zero payload → clear char arrays → optional UI refresh | Yes |
| No invent cast | Yes |

---

## 5. Gaps / open

1. Seal all ESI field indices to absolute offsets.
2. Document server packet shape for clear.

**Verdict:** **accept-with-gaps**
