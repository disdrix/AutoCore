# Review B (skeptical / adversarial): `aa_0040da70` ClonedObject_GetDefBlob

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040da70` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0040da70_ClonedObject_GetDefBlob.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Returns clonebase type at `+0x38` | **Falsified** — returns `*(+0xac)+0x3c` def ptr |
| 2 | Mutates object | **Falsified** — load only |
| 3 | MenuEquip-only | **Falsified** — tooltip/unequip/drop callers |
| 4 | Same as `item+0x2a` MI without COM | **Related** — alternate path to similar data; this uses COM `+0xac` |
| 5 | Null-safe beyond clonebase check | **Partial** — null clonebase → 0; no validate of this |

---

## 2. Surviving contract

```
fastcall(obj) -> def*|0
  cb = COM(obj).field_0xac
  return cb ? *(cb+0x3c) : 0
```

MenuEquip dual weapon subtype/slot tests **via this return** survive.

---

## 3. Open

Def type name; null-object crash residual if `this` bad.

**Verdict:** Getter sealed. **accept-with-gaps.**
