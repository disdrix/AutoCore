# Review A (reconstruction fidelity): `aa_00639210` CVOGHBAIBase_FindTargetToAttack

| Field | Value |
|---|---|
| **Stable ID** | `aa_00639210` |
| **VA** | `0x00639210` |
| **Canonical name** | `CVOGHBAIBase_FindTargetToAttack` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00639210_CVOGHBAIBase_FindTargetToAttack.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBAIBase_FindTargetToAttack.cpp` |
| Related | `CVOGHBAIBase_GetTargetFromAggro`, `Object_GetRootRaceId` |
| System notes | `docs/NPC.md` § FindTargetToAttack |

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Scoped string `CVOGHBAIBase::FindTargetToAttack` | **High** | Present |
| Owner at `this[6]`; null bail | **High** | Early gate |
| Owner validate vtbl+0x214 / +0x19c | **High** | Calls + debug-stop |
| Dead race `-100` / `owner+0x278==2` → no target | **High** | Direct compares |
| Respawn `owner+0x278==3` → no target | **High** | Branch to epilogue |
| Spatial query `FUN_004ea350` | **High** CF; **Medium** query-type codes 0xd/0x11 |
| Hostile `FUN_005134e0` + team bit10 of `+0x180` | **High** | Filters preserved |
| Aggro gate owner vtbl+0x298 | **High** | Call preserved |
| Alive candidate vtbl+0x198 | **High** | Call preserved |
| Level-delta shrinks r² (cap 11) | **High** math; **Medium** constant names |
| Commit via `FUN_005172d0` | **High** | Call preserved |
| “Closest” selection | **Medium** | Loop accepts first in-radius after filters, not full min-distance sort |

---

## 3. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Exception frame + scoped string | **Yes** |
| Owner null / validate | **Yes** |
| Random seed `this[2]` | **Yes** |
| Dead/respawn early outs | **Yes** |
| Spatial fill + iterate | **Yes** |
| Level radius adjust + r² test | **Yes** |
| `FUN_005172d0` + cleanup | **Yes** |

---

## 4. Gaps

1. `FUN_004ea350` / `FUN_005172d0` / `FUN_00639710` still anonymous.
2. Query mode 0xd vs 0x11 selection (random vs force) only partially explained.
3. Plate “closest” wording overstates if loop is first-hit; clean preserves first-in-radius semantics.
4. Global hit buffer `DAT_00d0307c/80` lifetime not typed.

**Verdict:** Target scan CF faithful; helper names and selection wording are the main gaps. **accept-with-gaps.**
