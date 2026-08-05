# Review A (reconstruction fidelity): `aa_00531e90` CVOGCharacter_ApplyCharacterLevelPacket

| Field | Value |
|---|---|
| **Stable ID** | `aa_00531e90` |
| **VA** | `0x00531e90` |
| **Canonical name** | `CVOGCharacter_ApplyCharacterLevelPacket` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00531e90_CVOGCharacter_ApplyCharacterLevelPacket.md` |
| **System** | `unknown` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Absolute apply of Packet_CharacterLevel onto CVOGCharacter: on level change vehicle hook + level-up UI; gated HP to vehicle; absolute Level/Currency/XP; mana always; skill/attr/research points; skill-rank loop; trailing FUN_00531330.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00531e90_CVOGCharacter_ApplyCharacterLevelPacket.md` |
| Annotated | `docs/reconstruction/raw/aa_00531e90_CVOGCharacter_ApplyCharacterLevelPacket.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGCharacter_ApplyCharacterLevelPacket.cpp` |
| Function record | `docs/reconstruction/functions/aa_00531e90_CVOGCharacter_ApplyCharacterLevelPacket.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Level change → vehicle vcall+0x244 + LogicUi level-up` | **High** | Body |
| `HP apply gated game+0xA8, +0xF5, vehicle+0x250; vtbl +0x248 max / +0x240 cur` | **High** | Body |
| `Level@char+0x6c8 from packet bLevel` | **High** | Body |
| `Currency absolute @+0x720; XP @+0x730` | **High** | Body |
| `Mana current/max always @+0x12c/+0x12e` | **High** | Body |
| `Skill/Attr/Research points stores` | **High** | Body |
| `Skill rank loop by count` | **High** | Body |
| `IMPORTANT: absolute set zeros unspecified if partial` | **Probable** | Plate warning |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Level-change UI | **Yes** |
| HP gate + absolute fields | **Yes** |
| Mana + points + ranks | **Yes** |

---

## 5. Gaps / open

1. Packet field struct names partially inferred (nSkillRankCount).
2. Skill rank packet addressing uses odd pPacket[1] math — residual.
3. Runtime character-level capture open.

**Verdict:** **accept-with-gaps**
