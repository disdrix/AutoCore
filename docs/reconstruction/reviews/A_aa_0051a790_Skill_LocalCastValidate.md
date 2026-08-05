# Review A (reconstruction fidelity): `aa_0051a790` Skill_LocalCastValidate

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051a790` |
| **VA** | `0x0051a790` |
| **Canonical name** | `Skill_LocalCastValidate` |
| **Review date** | `2026-07-23` (dual residual `2026-07-29`; **gate-ladder strengthen** same day) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0051a790_Skill_LocalCastValidate.md` |
| **Residual scratch** | `reviews/a_0051a790.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Local pre-cast validation on caster (`__thiscall`). Returns `eSkillResponses` (`0` = allow). Fail UX bridged by callers via `Skill_FormatFailureMessage`. **Not server authority.**

**Ordered early-exit ladder (G0→G9):** suppress(5) → vehicle plant(3) → optional busy(5/6) → null-skill allow(0) → free-binding deep path: power(4) → casting/CD(7) → prevent(10) → hide/range(12/11/LocalRangeTargetCheck) → else 0. Occupied active-cast binding skips deep path → 0.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0051a790_Skill_LocalCastValidate.md` |
| Annotated | `docs/reconstruction/raw/aa_0051a790_Skill_LocalCastValidate.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_LocalCastValidate.cpp` |
| Function record | `docs/reconstruction/functions/aa_0051a790_Skill_LocalCastValidate.md` |
| Fresh re-decompile | Ghidra `0x0051a790` (2026-07-29 residual + gate-ladder pass) |
| UX table | `Skill_FormatFailureMessage` `0x0054fa20` |
| TFID | `TFID_NotEquals` `0x0040b150`; invalid @ `0x009cdf88` (`read_memory`) |
| Helpers | `FUN_005169c0`, `FUN_00518c20` (leave-FUN), `LookupActiveCastBinding`, `LocalRangeTargetCheck` |
| Callers | 9 sites — RequestCast, QuickBar, Stance, NPC_TryCastSkillFromSet, FUN_00521650/606180/829190/91f6b0/941d50 |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Gate order G0→G9 early-exit | **High** | raw ≡ re-decompile ≡ clean CF |
| `Return 0 = allow cast` | **High** | callers continue on 0 |
| `this+0xb4 bit2 → 5` | **High** | body + FormatFailure case 5 |
| Vehicle plant missing / `+0x6b4<1` → **3** | **High CF**; UX “wrecked” | string High; gate≠name Probable |
| Busy `FUN_005169c0+0x10` → **6** | **High** | leave-FUN; toast “actively using” |
| Power short → **4** only when `plant+0x6b4 < 1` | **High** | **if `+0x6b4 >= 1`, power short does not reject** |
| Casting / category CD → **7** | **High** | `+0x628` / ST0 residual |
| **10** prevent / **11** must-hidden / **12** can't-while-hidden | **High** UX + CF | FormatFailure 10/0xb/0xc |
| Occupied bind → skip deep → 0 | **High CF** | TFID NotEquals ≠ 0 path |
| TFID compare width 8+1 B (not 16) | **High** | NotEquals body |
| Working ABI `(this, skipBusy, pSkill, rangeExtra)` | **High** | body + callers; plate false |
| Ghidra plate param names | **Falsified** | do not port plate |
| 13/14 returned as literals here | **Falsified** | LocalRangeTargetCheck / handler |
| Not server authority | **High** | local precheck only |
| Clean ≡ raw CF (incl. power `< 1`) | **Yes** | residual typo fix held |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| G0 suppress / G1 vehicle / G2 busy / G3–G9 skill | **Yes** |
| No invented server grant | **Yes** |
| Power conjunct `+0x6b4 < 1` (not `>=`) | **Yes** |
| Hide ladder formFlag / 0x4000 / 0x40 | **Yes** |
| Leave-FUN callees not renamed | **Yes** |

---

## 5. Gaps / open

1. Assembly-level formal seal (stack widths) — open by policy.
2. Product field name for `plant+0x6b4`; skill flag enum bits (`0x4000`, `0x40`, `0x02`).
3. `FUN_005169c0` / `FUN_00518c20` product symbols (leave FUN_*).
4. Product rationale for occupied binding → allow 0.
5. Runtime deny-code capture matrix; bit-exact / image diff.

**Verdict:** **accept-with-gaps** — gate ladder + UX codes 3/5/10/11/12 + TFID + power dual-use of `+0x6b4` + helper roles sealed; assembly/runtime remain.
