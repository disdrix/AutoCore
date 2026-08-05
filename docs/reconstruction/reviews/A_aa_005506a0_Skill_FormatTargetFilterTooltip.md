# Review A (reconstruction fidelity): `aa_005506a0` Skill_FormatTargetFilterTooltip

| Field | Value |
|---|---|
| **Stable ID** | `aa_005506a0` |
| **VA** | `0x005506a0` |
| **Canonical name** | `Skill_FormatTargetFilterTooltip` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005506a0_Skill_FormatTargetFilterTooltip.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Large pure-format helper (~26KB): given skill def (`param_1`) and output buffer, sprintf many target-filter tooltip lines from skill flags (e.g. `skill+0x614` bits). Client tooltip UX only — does not validate cast. Evidence via heavy sprintf/FUN_007a6de0 fanout.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005506a0_Skill_FormatTargetFilterTooltip.md` (or `aa_005506a0_FUN_005506a0.md`) |
| Annotated | `docs/reconstruction/raw/aa_005506a0_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_FormatTargetFilterTooltip.cpp` |
| Function record | `docs/reconstruction/functions/aa_005506a0_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Skill def +0x614 flag bits drive text` | High | Body |
| `Many sprintf tooltip fragments` | High | Callees |
| `Output buffer param_2` | High | Signature |
| `No cast mutation` | High | Pure format |
| `Client UI` | High | Tooltip |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Flag tests → append strings | Yes |
| No invented cast gates executed | Yes |

---

## 5. Gaps / open

1. Full flag→string table.
2. Buffer size limits.

**Verdict:** **accept-with-gaps**
