# Review B (skeptical / adversarial): `aa_0052b310` CVOGCharacter_IsAreaExplored

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052b310` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0052b310_CVOGCharacter_IsAreaExplored.md` |
| **Verdict** | **accept-with-gaps** (small pure function; high CF confidence) |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Missing continent counts as explored | **Falsified — null → false** |
| 2 | areaId is 0-based index | **Falsified — 1..32 with (id-1) shift** |
| 3 | Awards explore XP | **Falsified — pure bit test; XP.md notes no XP here** |
| 4 | Finished exact types | **Weak — entry type INFERRED** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| 1..32 range | High | False negatives on valid areas |
| Bit polarity at +0x08 | High | Wrong fog state |
| Hash @+0x534 | High | Wrong continent table |

---

## 3. Cross-check against raw

```
if areaId not in 1..32: false;
entry = hash(char+0x534, continentId);
if !entry: false;
return (entry+0x08) & (1<<(areaId-1)).
Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
IsAreaExplored(char, continentId, areaId):
  false if areaId∉[1,32] or no unlock entry
  else test ExploredBits bit (areaId-1)
Do not award XP on read. Pair with SetAreaExploredBit writer.
```

---

## 5. Open questions

1. Full USContinentUnlocked layout.
2. Terrain SampleExploredAreaId id mapping cross-check.

**Verdict:** **accept-with-gaps** (small pure function; high CF confidence)
