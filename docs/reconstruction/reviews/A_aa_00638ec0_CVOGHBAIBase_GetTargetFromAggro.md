# Review A (reconstruction fidelity): `aa_00638ec0` CVOGHBAIBase_GetTargetFromAggro

| Field | Value |
|---|---|
| **Stable ID** | `aa_00638ec0` |
| **VA** | `0x00638ec0` |
| **Canonical name** | `CVOGHBAIBase_GetTargetFromAggro` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00638ec0_CVOGHBAIBase_GetTargetFromAggro.md` |
| **System** | `npc-ai` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Pick in-range target from owner's **aggro/hate list** (not world scan). Owner this+0x18; validate vtbl+0x214; build temp list; resolve entries via `CVOGReaction_ResolveObjectTarget`; faction vtbl+0x1dc/+0x1d8; skip vehicle-flag +0x250; hostile FUN_005134e0; range vs attack radius owner profile +0x4c8. Complements `FindTargetToAttack`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00638ec0_CVOGHBAIBase_GetTargetFromAggro.md` |
| Annotated | `docs/reconstruction/raw/aa_00638ec0_CVOGHBAIBase_GetTargetFromAggro.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBAIBase_GetTargetFromAggro.cpp` |
| Function record | `docs/reconstruction/functions/aa_00638ec0_CVOGHBAIBase_GetTargetFromAggro.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Owner this+0x18 + validate +0x214` | **High** | Entry |
| `Temp list FUN_0058d9c0 + load FUN_004c9380` | **High** | List build |
| `Attack radius profile +0x4c8` | **High** | Range gate |
| `ResolveObjectTarget per entry` | **High** | Shared reaction helper |
| `Faction vtbl+0x1dc / +0x1d8` | **High** | Filter |
| `Skip if vehicle +0x250 set on path` | **High** | Plate |
| `Hostile FUN_005134e0` | **High** | Call |
| `In-range keep else remove FUN_0051cb40` | **High** | List prune |
| `Complements spatial FindTargetToAttack` | **High** | Docs / dual unit |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Owner validate + list build | **Yes** |
| Per-entry resolve/faction/hostile/range | **Yes** |
| Cleanup return | **Yes** |

---

## 5. Gaps / open

1. Aggro list source layout on owner.
2. Exact faction polarity (0 means ally skip?).
3. Why +0x250 vehicle skip on some entries.
4. Runtime aggro pick vs FindTarget.

**Verdict:** **accept-with-gaps**
