# Review B (skeptical / adversarial): `aa_005fe6a0` CVOGHBWeaponFire_ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fe6a0` |
| **VA** | `0x005fe6a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005fe6a0_CVOGHBWeaponFire_ctor_Inferred.md` |
| **Evidence** | Live decompile; weapon fire parent dual; AttachOwner xref list |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Plain CVOGHBBase only (no subclass vtbl) | **Falsified** | overwrites vtbl to 009dd43c after base ctor |
| 2 | Type code left 0 | **Falsified** | `[7]=9` |
| 3 | Does not attach owner | **Falsified** | AttachOwnerObject call |
| 4 | Accepts period 1000 as second formal | **Falsified in this body** | only weapon/owner pointer formal; parent decompile residual |
| 5 | Clean ≠ raw | **Falsified** | ≡ |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| HB subclass ctor shape | **High** | broken fire HB |
| type=9 | **High** | wrong HB dispatch |
| Owner MI resolve | **Medium–High** | null attach |
| English class name | **Low–Medium** | naming |
| Runtime | **Open** | — |

---

## 3. Surviving contract

```
CVOGHBWeaponFire_ctor(this, weaponChain):
  CVOGHBBase_ctor(this)
  vtbl = 009dd43c
  flags[3]=flags[4]=1; [2]=TimerHelper(0)
  AttachOwner(this, MI_owner(weaponChain) or null)
  this[7] = 9
  maybe FUN_00514ff0(0); FUN_0056b400(1); weapon.vtbl+0x2c(1)
  return this
```

**Verdict:** **accept-with-gaps**
