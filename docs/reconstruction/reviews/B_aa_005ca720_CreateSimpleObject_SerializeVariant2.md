# Review B (skeptical / adversarial): `aa_005ca720` CreateSimpleObject_SerializeVariant2

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ca720` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005ca720_CreateSimpleObject_SerializeVariant2.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Different opcode | Falsified — still 0x2012 |
| 2 | Identical this offsets to Serialize | Falsified — -0x10c vs -0xbc |
| 3 | Delta ghost update pack | Falsified — create-shaped full blob |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Variant selection at call site | High | Wrong field source |
| Shared 0xD8 layout | High | Parse mismatch |
| this-base map | High | Garbage fields |

---

## 3. Cross-check against raw

```
SerializeVariant2(obj, buf):
  same 0x2012/0xD8 contract as Serialize with alternate this-base
Used by character create path. Clean ≡ raw CF.
```

---

## 4. Surviving contract for AutoCore

```
Character/object create path serializer; keep split from primary Serialize.
```

---

## 5. Open questions

1. Enumerate call sites for Variant2 vs Serialize.
2. Live-diff character create blob.

**Verdict:** **accept-with-gaps**
