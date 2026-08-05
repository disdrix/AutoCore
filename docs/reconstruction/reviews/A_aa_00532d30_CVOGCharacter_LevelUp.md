# Review A (reconstruction fidelity): `aa_00532d30` CVOGCharacter_LevelUp

| Field | Value |
|---|---|
| **Stable ID** | `aa_00532d30` |
| **VA** | `0x00532d30` |
| **Canonical name** | `CVOGCharacter_LevelUp` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00532d30_CVOGCharacter_LevelUp.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Grant **one** character level from the experience-level table row for `nLevel+1`:

- Dirty object flags `\|0x80`
- Increment `nLevel` at `+0x6c8`
- Add skill/attribute shorts from packed row `+0x14` into `+0x6cc` / `+0x6ce`
- Add research short from row `+0x18` into `+0x580`
- Refresh skill HB / attribute helpers; optional vehicle combat-pool recalc
- If local-player flag (`…+0x7e`): `CVOGCharacter_SearchAutoMissions`
- If `bNotifyUi`: send LogicUI packet type **`0x2D`**

Called from XP award paths when level thresholds are crossed (`docs/XP.md`).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00532d30_CVOGCharacter_LevelUp.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGCharacter_LevelUp.cpp` |
| Function record | `docs/reconstruction/functions/aa_00532d30_CVOGCharacter_LevelUp.md` |
| Prior art | `docs/XP.md` LevelUp section |
| Callee | `CVOGCharacter_SearchAutoMissions`; LogicUI send |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__thiscall(this, bNotifyUi)` void | **High** | Raw plate + body |
| Ensure level table loaded if not ready | **High** | Double ensure pattern preserved |
| LowerBound map by `nLevel+1` key | **High** | `StdMap_LowerBoundByIntKey_INFERRED` |
| No-op if key past map end | **High** | Outer `if (pvVar1 != end)` |
| Dirty `object+0x180 \|= 0x80` | **High** | Via this+4 indirection |
| `+0x6c8`++ level | **High** | Explicit store |
| Skill/attrib from packed `row+0x14` low/high 16 | **High** | `>> 0x10` for attrib |
| Research add `+0x580` from `row+0x18` low short | **High** | After skill vec loop |
| Two-pass skill HB walk (iVar8 0..1) with RTTI filters | **High** | Complex but mirrored |
| Attribute helpers `FUN_004c2ef0`..`FUN_004c2f10` | **Probable** | Unnamed but call order fixed |
| Vehicle `+0x250` combat-pool delta + vtbl | **Probable** | HP-delta naming INFERRED |
| Local flag `…+0x7e` → SearchAutoMissions | **High** | Same polarity family as XP gating |
| LogicUI `0x2d` when `bNotifyUi` | **High** | Stack prep + `Client_SendLogicUiPacket` |
| Row layout XP@+0x10 sealed for this body | **Tentative** | Loaded into locals; not all fields consumed |
| `nHpDelta_INFERRED` name for vehicle delta | **Tentative** | Reuses local; plate inference |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| ExceptionList prologue / SEH labels | **Yes** (scaffold) |
| Table ensure + map lower_bound | **Yes** |
| Dirty + level++ + skill/attrib grants | **Yes** |
| Dual skill-list HB refresh loop | **Yes** |
| Research + attribute FUN chain | **Yes** |
| Vehicle pool / vtbl / flag@0x4f2 | **Yes** |
| SearchAutoMissions gate | **Yes** |
| Optional LogicUI 0x2D | **Yes** |
| operator_delete skill vec | **Yes** |

---

## 5. Gaps

1. Many `FUN_*` attribute/UI helpers unresolved.
2. ExperienceLevel map entry layout only partially sealed (`+0x10/+0x14/+0x18`).
3. Skill-vec collection side of RTTI loop is sparse in decompile (empty-path common).
4. Runtime multi-level chain (repeated LevelUp) not exercised here.
5. Function record still “Partial scaffold” / system tag `unknown` — should be missions-progression/XP.

**Verdict:** Level-up kernel CF faithful to raw. **accept-with-gaps.**
