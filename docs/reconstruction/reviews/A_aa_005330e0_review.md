# Review A (reconstruction fidelity): `aa_005330e0` CVOGCharacter_LevelDown

| Field | Value |
|---|---|
| **Stable ID** | `aa_005330e0` |
| **VA** | `0x005330e0` |
| **Canonical name** | `CVOGCharacter_LevelDown` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005330e0_CVOGCharacter_LevelDown.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGCharacter_LevelDown.cpp` |
| Prior art | `docs/XP.md` de-level note |
| Caller | `CVOGReaction_AddExperience` negative-XP loop |

---

## 2. Signature & CF

| Stage | Raw | Clean | Match |
|---|---|---|---|
| `__fastcall this` | Present | Present | **Yes** |
| Lookup **current** level (pre-dec) | Present | Present | **Yes** |
| Dirty `\|0x80`; `nLevel--` | Present | Present | **Yes** |
| Attrib `+0x6ce` -= row+0x16; clamp ≥0 | Present | Present | **Yes** |
| Skill `+0x6cc` -= row+0x14; clamp ≥0 | Present | Present | **Yes** |
| Odd-level base-stat helper path | Present | Present (MSVC %2 idiom kept) | **Yes** |
| Vehicle_RecalcCombatPools | Present | Present | **Yes** |
| Vtable +0x5c; `+0x12c`←`+0x12e`; `+0x4f2=1` | Present | Present | **Yes** |
| Flag `+0x7e` → SearchAutoMissions | Present | Present | **Yes** |
| No research `+0x580` reverse | Absent | Absent (documented) | **Yes** |

---

## 3. State mutations

| Offset | Mutation |
|---|---|
| `+0x6c8` | Level -- |
| `+0x6cc` / `+0x6ce` | Skill / attrib pool -= row; clamp 0 |
| `+0x13c..+0x142` | Possible -1 via helpers when post-dec level odd |
| Dual-base `+0x180` | Dirty bit 0x80 |

---

## 4. Gaps

1. Odd-level path purpose (base-stat table vs UI) not fully typed.
2. `FUN_004c2ef0` CONCAT packing is decompiler surface — not proven against asm this pass.
3. Research asymmetry vs LevelUp is intentional gap, not a clean omission.

**Verdict:** Clean tracks raw de-level CF. **accept-with-gaps.**
