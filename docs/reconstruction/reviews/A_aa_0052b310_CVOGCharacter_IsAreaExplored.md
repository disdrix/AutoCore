# Review A (reconstruction fidelity): `aa_0052b310` CVOGCharacter_IsAreaExplored

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052b310` |
| **VA** | `0x0052b310` |
| **Canonical name** | `CVOGCharacter_IsAreaExplored` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0052b310_CVOGCharacter_IsAreaExplored.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Boolean test: explored-area bit (areaId−1) set for continentId in character's USContinentUnlocked hash @ **+0x534**; entry ExploredBits @ **+0x08**. areaId outside 1..32 → false.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0052b310_CVOGCharacter_IsAreaExplored.md` |
| Annotated | `docs/reconstruction/raw/aa_0052b310_CVOGCharacter_IsAreaExplored.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGCharacter_IsAreaExplored.cpp` |
| Function record | `docs/reconstruction/functions/aa_0052b310_CVOGCharacter_IsAreaExplored.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `areaId range 1..32 inclusive` | **High** | ≤0 or ≥33 ('!') → false |
| `Hash lookup continentId @ char+0x534` | **High** | CNDHash_LookupByKey |
| `Missing entry → false` | **High** | Null check |
| `Bit = 1<<(areaId-1); test entry+0x08` | **High** | ExploredBits |
| `No side effects / no XP` | **High** | Pure reader |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Range gate | **Yes** |
| Hash + bit test | **Yes** |
| No invented modernizations | **Yes** |

---

## 5. Gaps / open

1. Continent unlock entry full struct beyond +0x08.
2. Call graph beyond SetAreaExploredBit sibling.
3. Runtime fog-of-war capture open.

**Verdict:** **accept-with-gaps**
