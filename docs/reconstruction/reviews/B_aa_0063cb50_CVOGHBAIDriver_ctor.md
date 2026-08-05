# Review B (skeptical / adversarial): `aa_0063cb50` CVOGHBAIDriver_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0063cb50` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0063cb50_CVOGHBAIDriver_ctor.md` |
| **Verdict** | **accept** (short ctor CF clear) |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Chains CreatureBase only | **Falsified — CharacterOrMine mid** |
| 2 | Size 0x100 | **Falsified — 0x110** |
| 3 | Uses OnHeartBeat as primary | **Falsified — DoLogic** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Driver vtbl | High | No DoLogic dispatch |
| Parent chain | High | Missing mid fields |
| Size 0x110 | High | Heap overrun |

---

## 3. Cross-check against raw

```
CharacterOrMine_ctor; *this=DriverVtbl; return.
Clean ≡ raw trampoline-ish ctor.
```

---

## 4. Surviving contract for AutoCore

```
Driver_ctor:
  AICode 5 DR vehicle AI; size 0x110 via CharacterOrMine parent
  tick via DoLogic + ReturnToNormalLocation + FireWeapons
  attach path COID for leash
```

---

## 5. Open questions

1. Dual A/B CharacterOrMine_ctor if still missing.

**Verdict:** **accept** (short ctor CF clear)
