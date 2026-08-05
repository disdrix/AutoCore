# Review B (skeptical / adversarial): `aa_007e07b0` Named_tCloneBase

| Field | Value |
|---|---|
| **Stable ID** | `aa_007e07b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_007e07b0_Named_tCloneBase.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Runtime GetCloneBaseFromID only | Falsified — table load |
| 2 | Single column | Falsified — large multi-read |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Column map | High | Wrong templates |
| Ready flag | Medium | Reload loops |

---

## 3. Cross-check against raw

```
tCloneBase: DBReader full clonebase table into runtime maps.
```

---

## 4. Surviving contract for AutoCore

```
Authoritative template load. AutoCore must load before loot/combat.
```

---

## 5. Open questions

1. Sample CBID row parity.

**Verdict:** **accept-with-gaps**
