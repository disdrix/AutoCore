# Review B (skeptical / adversarial): `Client_InitActionDisplayNames` @ `0x007f7570`

| Field | Value |
|---|---|
| **Stable ID** | `aa_007f7570` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_007f7570_Client_InitActionDisplayNames.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Sets default DIK for Accelerate | Falsified — names only |
| 2 | Localizes via resource DLL | Overstated — copies literals |
| 3 | Drive offsets same as DIK tables | Falsified — separate name fields |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Name-only side effect | High | Blank options UI |
| Drive display offsets | High | Mislabel binds |
| Full slot coverage | Medium | Missing labels |

---

## 3. Cross-check against raw

```
Copy string literals into ActionMap name fields; return.
No DIK. Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
InitActionDisplayNames(actionMap):
  fill human-readable labels only
  DIK defaults = InitDefaultKeybinds
  drive labels at +0x27d..+0x3b5
```

---

## 5. Open questions

1. Export full name-offset table for options UI.

**Verdict:** **accept**
