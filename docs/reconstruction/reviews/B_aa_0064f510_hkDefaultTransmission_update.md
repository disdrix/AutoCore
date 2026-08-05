# Review B (skeptical / adversarial): `aa_0064f510` hkDefaultTransmission_update

| Field | Value |
|---|---|
| **Stable ID** | `aa_0064f510` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0064f510_hkDefaultTransmission_update.md` |
| **Verdict** | accept-with-gaps |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | postTick reads transm+0x1c for drive | Falsified — WI-MOV-004 |
| 2 | Writes hardpoint wheel+0x20 | Falsified — preUpdate owns that |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Orphan +0x1c vs AA torque path | High | Wrong port coupling |

---

## 3. Cross-check against raw

```
trans.update: rpm@+0x18; factor@+0x1c; axle fracs; reverse bit.
Not drive source for postTick.
Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
Transmission bookkeeping only under AA architecture (no hk engine).
```

---

## 5. Open questions

1. Confirm gear tables from BuildTransmissionDescriptor.

**Verdict:** accept-with-gaps
