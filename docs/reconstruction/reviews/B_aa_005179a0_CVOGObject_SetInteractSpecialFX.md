# Review B (skeptical / adversarial): `aa_005179a0` CVOGObject_SetInteractSpecialFX

| Field | Value |
|---|---|
| **Stable ID** | `aa_005179a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005179a0_CVOGObject_SetInteractSpecialFX.md` |
| **Verdict** | **accept** (small focused unit) |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Leaks old FX without teardown | **Falsified — always teardown if non-null** |
| 2 | Skips attach when non-null new | **Falsified — attaches then stores** |
| 3 | Hardcodes non-null | **Falsified — null clears** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| +0x130 slot | High | Wrong FX field |
| Teardown before replace | High | Leak / double FX |
| Attach args (1,0) | Tentative | Wrong attach mode |

---

## 3. Cross-check against raw

```
old=+0x130; if old: FUN_00517250(old);
if new: vtbl+0xF8(new,1,0);
+0x130=new.
Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
SetInteractSpecialFX(obj, pFx):
  teardown previous +0x130; attach new if non-null; store
  used for mission/NPC interact chrome (interact_* scripts)
  null clears icon FX
```

---

## 5. Open questions

1. Catalog interact_* script names vs EvalInteractState.

**Verdict:** **accept** (small focused unit)
