# Review A (reconstruction fidelity): `aa_00532d30` CVOGCharacter_LevelUp

| Field | Value |
|---|---|
| **Stable ID** | `aa_00532d30` |
| **VA** | `0x00532d30` |
| **Canonical name** | `CVOGCharacter_LevelUp` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00532d30_CVOGCharacter_LevelUp.md` (annotated sibling) |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGCharacter_LevelUp.cpp` |
| Prior art | `docs/XP.md` § Level-up |
| Caller | `CVOGReaction_AddExperience` level-up loop |

---

## 2. Signature & CF

| Stage | Raw | Clean | Match |
|---|---|---|---|
| `__thiscall (this, bNotifyUi)` | Present | Present | **Yes** |
| Table ensure + lower_bound(level+1) | Present | Present | **Yes** |
| Dirty `+0x180\|=0x80`; `nLevel++` | Present | Present | **Yes** |
| Skill/attrib from packed row+0x14 | Present | Present | **Yes** |
| Research short to `+0x580` from row+0x18 | Present | Present | **Yes** |
| Two-pass skill-HB walk (char / vehicle) | Present | Present | **Yes** |
| Attribute helpers + vehicle pool recalc | Present | Present | **Yes** |
| Flag `+0x7e` → SearchAutoMissions | Present | Present | **Yes** |
| `bNotifyUi` → LogicUI type `0x2D` | Present | Present | **Yes** |

---

## 3. State mutations

| Offset | Mutation |
|---|---|
| `+0x6c8` | Level ++ |
| `+0x6cc` / `+0x6ce` | Skill / attrib pool += row grants |
| `+0x580` | Research pool += row grant |
| Dual-base `+0x180` | Dirty bit 0x80 |
| `+0x4f2` | Set to 1 |

---

## 4. Gaps

1. Skill-HB helpers (`FUN_004294f0`, `FUN_004022a0`, `FUN_0053a820`) still unresolved.
2. Attribute helpers `FUN_004c2ef0..f10` arg semantics partial (no-arg form in LevelUp).
3. SEH / `operator_delete` on skill vector path not runtime-verified.
4. `nLookupLevel` local reused for HP delta — name is documentation of decompiler reuse, not two live vars.

**Verdict:** Clean tracks raw level-grant CF. **accept-with-gaps.**
