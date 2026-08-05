# Review B (skeptical / adversarial): `aa_005c72f0` CLoadNode__initPreload

| Field | Value |
|---|---|
| **Stable ID** | `aa_005c72f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005c72f0_CLoadNode__initPreload.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | No physics preload touch | Falsified — FUN_004eb3b0 |
| 2 | Wait key +0x14c | Falsified — +0x174 |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Preload side effects | High | Missing RB assets |
| +0x58 store | Medium | Later stage null |

---

## 3. Cross-check against raw

```
_initPreload: wait +0x174; eb3b0; maybe f2540; +0x58=vtbl+0xc; 0|3.
```

---

## 4. Surviving contract for AutoCore

```
Asset preload stage; ties to Phy_CollectAllPhysicsPreloads family.
```

---

## 5. Open questions

1. Confirm clonebase +0x174 asset id type.

**Verdict:** **accept-with-gaps**
