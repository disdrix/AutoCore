# Review B (skeptical / adversarial): `aa_0063c940` CVOGHBAIBase_Default_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0063c940` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0063c940_CVOGHBAIBase_Default_ctor.md` |
| **Verdict** | **accept** (short ctor CF clear) |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Same as CreatureBase_ctor | **Falsified — chains WalkingTurreted not CreatureBase** |
| 2 | Size 0x100 | **Falsified — 0xD0 family** |
| 3 | No vtbl swap after parent | **Falsified — installs PTR_FUN_009e3d40** |
| 4 | Finished named layout for [0x1f] | **Overstated** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Fallback size 0xD0 | High | Heap overrun if mis-sized |
| Default vtbl install | High | Wrong virtuals |
| WalkingTurreted parent chain | High | Missing mid zeros |
| FUN_0063a700 role | Tentative | Uninitialized side state |

---

## 3. Cross-check against raw

```
WalkingCreatureTurreted_ctor; *this=DefaultVtbl; [4]=0; FUN_0063a700(0); [0x1f]=1.0f.
Clean ≡ raw short ctor.
```

---

## 4. Surviving contract for AutoCore

```
Default_ctor:
  AICode default / unknown → 0xD0 WalkingTurreted-family HBAI
  do not map unknown codes to Creature/Driver
  pair with CreateByAICode default case
```

---

## 5. Open questions

1. Name FUN_0063a700.
2. Confirm default vtbl tick entry vs Turreted.

**Verdict:** **accept** (short ctor CF clear)
