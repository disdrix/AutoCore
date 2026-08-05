# Review B (skeptical / adversarial): `aa_009463b0` Phy_Start_ReinitPhysics

| Field | Value |
|---|---|
| **Stable ID** | `aa_009463b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_009463b0_Phy_Start_ReinitPhysics.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Steps one PhysX actor | Falsified — world reinit |
| 2 | No resource eviction | Falsified — explicit log + vtbl |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| List clear completeness | High | Leak / stale phys |
| Map transition order | High | Crash on sector change |

---

## 3. Cross-check against raw

```
Start_ReinitPhysics: clear flag; tear lists; evict resources; optional WS trim.
```

---

## 4. Surviving contract for AutoCore

```
Map-change physics reset entry for client world.
```

---

## 5. Open questions

1. Find who calls after sector transfer packet.

**Verdict:** **accept-with-gaps**
