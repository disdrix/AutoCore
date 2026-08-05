# Review A (reconstruction fidelity): `aa_00955eb0` Client_DebugDumpEntityCombatStats

| Field | Value |
|---|---|
| **Stable ID** | `aa_00955eb0` |
| **VA** | `0x00955eb0` |
| **Canonical name** | `Client_DebugDumpEntityCombatStats` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00955eb0_Client_DebugDumpEntityCombatStats.md` |
| **System tag** | `skills-abilities` |
| **Verdict** | **accept** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Clean | `docs/reconstruction/reconstructed-exact/Client_DebugDumpEntityCombatStats.cpp` |
| Raw | `docs/reconstruction/raw/aa_00955eb0_*` (annotated if present) |
| Reviews dir | `docs/reconstruction/reviews/` |

**Purpose (from clean plate / body):** DEBUG dump: entity AI/skill state, armor, resists, owner skills, distance/pos. sprintf → chat/console helper FUN_00800af0. Not a combat authority path.

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| AI State / SkillsInState sprintf formats | High | Strings |
| Skill:(%d) Level(%d) lines | High | Strings |
| Distance/Pos dump | High | Strings |
| CVOGHBBase_GetRemainingSeconds used | High | Callees |
| Debug-only; no packet send | High | No SendSectorPacket |

---

## 3. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Gather entity → format multi-line dump → print helper | Yes |

---

## 4. Gaps

1. Registration slash command name (see RegisterDebugSlashCommands).
2. Full resist/armor field offsets not sealed in plate.

**Verdict:** **accept**
