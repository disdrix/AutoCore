# Review A (reconstruction fidelity): `aa_00531330` Character_LevelUpFxAndUiNotify_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00531330` |
| **VA** | `0x00531330` |
| **Canonical name** | `Character_LevelUpFxAndUiNotify_Inferred` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00531330_Character_LevelUpFxAndUiNotify_Inferred.md` |
| **System** | `missions-progression` / LevelUp residual of kill XP award |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Post-level-up client presentation/notify (callee of `CVOGCharacter_LevelUp`):

When `flag == 1` (true level-up path):

1. Lazy-init character FX master at `char+0xcb8` (`operator_new(8)` → `FUN_004a1620` ctor, `FUN_004a6390` load master XML).
2. `FUN_004a16d0` load event variant; if non-null: `FUN_004b7550` set float params, resolve host object (self or vehicle at `+0x250`), vcall `+0xf8`, `FUN_004b7e50(0,0,0)` play, `Client_SendLogicUiPacket`.

Unconditional follow-ups (any flag): if non-zero shorts at `char+0x6cc`, `+0x6ce`, or `+0x580`, each triggers another `Client_SendLogicUiPacket` (skill-point / attr UI refresh — field names Probable).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Ghidra decompile | `0x00531330` |
| Raw | `docs/reconstruction/raw/aa_00531330_FUN_00531330.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_CVOGCharacter_LevelUp_00531330.cpp` |
| Parent | `CVOGCharacter_LevelUp` / `CVOGReaction_AddExperience` chain |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `flag==1` gates FX master + play | **High** | Outer if |
| Lazy FX host at `+0xcb8` | **High** | Alloc + store |
| Uses FxMaster catalog helpers (`004a1620`/`004a6390`/`004a16d0`) | **High** | Known dual names in tree |
| Multiple LogicUi packets for residual shorts | **High** | Three independent ifs |
| Does **not** mutate XP totals | **High** | Notify/FX only |
| Exact LogicUi opcode payloads | **Tentative** | Inside `SendLogicUiPacket` |

---

## 4. Gaps

1. Which FX event key `004a16d0` loads for level-up.
2. Semantic names for `+0x6cc` / `+0x6ce` / `+0x580` shorts (skill points / unspent attrs).

**Verdict:** **accept-with-gaps**
