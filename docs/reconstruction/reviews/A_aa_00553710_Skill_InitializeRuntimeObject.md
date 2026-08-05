# Review A (reconstruction fidelity): `aa_00553710` Skill_InitializeRuntimeObject

| Field | Value |
|---|---|
| **Stable ID** | `aa_00553710` |
| **VA** | `0x00553710` |
| **Canonical name** | `Skill_InitializeRuntimeObject` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00553710_Skill_InitializeRuntimeObject.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Initialize skill runtime object from template args: writes skill id **`+0x5fc`**, category **`+0x5e8`**, flags **`+0x614`**, clears casting state, then `Skill_ReevaluateForCurrentRank`. If flags byte **`+0x615` bit1** set → **`+0x61c=1`** (defer cast-again heartbeat start). Core factory path when a skill becomes live on character/NPC.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00553710_Skill_InitializeRuntimeObject.md` (or `aa_00553710_FUN_00553710.md`) |
| Annotated | `docs/reconstruction/raw/aa_00553710_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_InitializeRuntimeObject.cpp` |
| Function record | `docs/reconstruction/functions/aa_00553710_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Fills +0x5fc id / +0x5e8 category / +0x614 flags` | High | Plate |
| `Clears casting bookkeeping` | High | Body |
| `Calls ReevaluateForCurrentRank` | High | Callee |
| `+0x615 bit1 → +0x61c defer cast-again` | High | Plate |
| `FUN_00418820 helper role` | Medium | Unnamed |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Init fields → reevaluate rank | Yes |
| No network send | Yes |

---

## 5. Gaps / open

1. Full runtime field zero-init table.
2. Defer +0x61c consumer (StartCastAgainHeartbeat).

**Verdict:** **accept-with-gaps**
