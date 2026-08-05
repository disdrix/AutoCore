# Review A (reconstruction fidelity): `aa_004ce340` CVOGCharacter_WeaponAllowsKillXpBonus

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ce340` |
| **VA** | `0x004ce340` |
| **Canonical name** | `CVOGCharacter_WeaponAllowsKillXpBonus` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004ce340_CVOGCharacter_WeaponAllowsKillXpBonus.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept** |

---

## 1. Purpose

Tiny boolean gate (no weapon lookup): fail if +0x100 flag non-zero or mode @+0xac == 2 (and LEA +0xa0 null-ish). Used by kill-path XP spree table **and** mission hash policy selection. Retail name is historical.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004ce340_CVOGCharacter_WeaponAllowsKillXpBonus.md` |
| Annotated | `docs/reconstruction/raw/aa_004ce340_CVOGCharacter_WeaponAllowsKillXpBonus.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGCharacter_WeaponAllowsKillXpBonus.cpp` |
| Function record | `docs/reconstruction/functions/aa_004ce340_CVOGCharacter_WeaponAllowsKillXpBonus.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `No weapon/item dereference in body` | **High** | 11-insn field pair only |
| `+0x100 must be 0` | **High** | else false |
| `+0xac must not be 2` | **High** | else false |
| `Returns 1/0 in AL` | **High** | thiscall |
| `Name oversells weapon semantics` | **High** | Clean plate documents dual use |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Field checks only | **Yes** |
| No invented weapon scan | **Yes** |

---

## 5. Gaps / open

1. Object type of `this` (character vs combat ctx) across call sites.
2. Meaning of mode==2 and +0x100 flag.
3. Full mission dual-hash policy map.

**Verdict:** **accept**
