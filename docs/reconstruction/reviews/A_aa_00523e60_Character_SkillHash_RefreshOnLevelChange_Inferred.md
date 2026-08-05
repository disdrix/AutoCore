# Review A (reconstruction fidelity): `aa_00523e60` Character_SkillHash_RefreshOnLevelChange_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00523e60` |
| **VA** | `0x00523e60` |
| **Canonical name** | `Character_SkillHash_RefreshOnLevelChange_Inferred` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00523e60_Character_SkillHash_RefreshOnLevelChange_Inferred.md` |
| **System** | `missions-progression` / skills (LevelUp residual) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

On level change (caller `CVOGCharacter_LevelUp`), traverse the character skill hash under a traversal lock (`hash+0x1d`), and for each skill entry where `skill+0xdc` (s16) **> 0** and `skill+0x615` bit0 set, call `FUN_00514e70(skill+0x5fc)` (clear/refresh cast-related state — sibling of skill cast-clear family).

Traversal:

- Hash host at `char_via_rtti + 0x74` (offset chain through `*(this+4)+4`).
- Set lock byte `+0x1d = 1` (error log + `VOG_DEBUG_STOP` if already locked).
- `FUN_00411900` start iterator; while entries: `FUN_005536c0(char)` then conditional clear; advance via node `+0x14` chain / payload `+8`.
- Clear lock byte on exit.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Ghidra decompile | `0x00523e60` |
| Raw | `docs/reconstruction/raw/aa_00523e60_FUN_00523e60.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00523e60.cpp` |
| Parent | `CVOGCharacter_LevelUp` `0x00532d30` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Traversal lock at hash `+0x1d` | **High** | Strings `HashError:TraversalLock` / `TraverseToNext` |
| Gate: `*(s16*)(skill+0xdc)>0` and `(byte)(skill+0x615)&1` | **High** | Body |
| Clears via `FUN_00514e70(*(skill+0x5fc))` | **High** | Call shape |
| Called from LevelUp after XP threshold cross | **Probable** | Parent callees list |
| Exact product name of clear helper | **Tentative** | Sibling cast-clear family |

---

## 4. Gaps

1. Seal `FUN_00514e70` / `FUN_005536c0` duals if missing.
2. Full skill entry field names for `+0xdc` / `+0x615` / `+0x5fc`.

**Verdict:** **accept-with-gaps**
