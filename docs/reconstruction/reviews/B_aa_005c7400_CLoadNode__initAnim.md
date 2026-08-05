# Review B (skeptical / adversarial): `aa_005c7400` CLoadNode__initAnim

| Field | Value |
|---|---|
| **Stable ID** | `aa_005c7400` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005c7400_CLoadNode__initAnim.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Wait key +0x14c physics | Falsified — +0x138 |
| 2 | No object call | Falsified — vtbl+0x20 |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Anim stage key | High | Wrong wait |
| vtbl+0x20 | Medium | Anim missing |

---

## 3. Cross-check against raw

```
_initAnim: wait +0x138; +0x61=0; obj.vtbl+0x20(); return 0|3.
```

---

## 4. Surviving contract for AutoCore

```
Animation bind stage in CLoad pipeline.
```

---

## 5. Open questions

1. Confirm +0x138 asset type (anim pack id).

**Verdict:** **accept-with-gaps**
