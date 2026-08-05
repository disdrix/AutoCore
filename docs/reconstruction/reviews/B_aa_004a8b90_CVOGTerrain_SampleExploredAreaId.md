# Review B (skeptical / adversarial): `aa_004a8b90` CVOGTerrain_SampleExploredAreaId

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a8b90` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_004a8b90_CVOGTerrain_SampleExploredAreaId.md` |
| **Verdict** | **accept** (short CF clear) |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Uses low 3 bits for area | **Falsified — >>3 high 5** |
| 2 | No OOB guard | **Falsified — return 0** |
| 3 | Grants XP | **Falsified — sample only** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| >>3 area id | High | Wrong explore bit |
| Column-major buffer | High | Swapped axes |
| OOB 0 | High | Spurious unlock |

---

## 3. Cross-check against raw

```
half=grid*0.5; cell=(p-half)/grid; if in bounds return tile>>3 else 0.
Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
SampleExploredAreaId(terrain, x, z):
  fog/explore area 1..32 from map G channel high bits
  AutoCore ContinentAreaMask.SampleAreaId
  pair SetAreaExploredBit / LocalDiscoveryTick
  not tile layer (that is &7)
```

---

## 5. Open questions

1. Cross-check explore bit duals.
2. Map asset authoring docs for G channel.

**Verdict:** **accept** (short CF clear)
