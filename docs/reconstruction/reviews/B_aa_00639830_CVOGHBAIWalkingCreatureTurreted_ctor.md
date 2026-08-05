# Review B (skeptical / adversarial): `aa_00639830` CVOGHBAIWalkingCreatureTurreted_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00639830` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00639830_CVOGHBAIWalkingCreatureTurreted_ctor.md` |
| **Verdict** | **accept** (short ctor CF clear) |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Size 0x100 like Creature | **Falsified — 0xD0** |
| 2 | Gets factory profile trio | **Falsified — case 6 skips** |
| 3 | Chains CreatureBase | **Falsified — Base only** |
| 4 | Unrelated to Default_ctor | **Falsified — Default chains this** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Size 0xD0 | High | Heap overrun |
| Turreted vtbl | High | Wrong virtuals |
| Skip profile init | High | Assume initialized ranges |
| FUN_0063a700 | Tentative | Side init miss |

---

## 3. Cross-check against raw

```
Base_ctor; *this=TurretedVtbl; [0x30]=0; [4]=0; FUN_0063a700(0); [0x1f]=1.0f.
Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
WalkingCreatureTurreted_ctor:
  AICode 6; size 0xD0; also Default parent
  factory does NOT run post-ctor profile float trio
  rare/absent in some retail tables — still implement for completeness
```

---

## 5. Open questions

1. Confirm AICode 6 presence in live AI tables.
2. Name FUN_0063a700.

**Verdict:** **accept** (short ctor CF clear)
