# Review B (skeptical / adversarial): `aa_007971b0` Dword4_Copy

| Field | Value |
|---|---|
| **Stable ID** | `aa_007971b0` |
| **VA** | `0x007971b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_007971b0_Dword4_Copy.md` |
| **Evidence** | Live decompile; multi-domain callers |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Copies 3 floats only | **Falsified** | four stores |
| 2 | Zeroes destination first | **Falsified** | pure assign |
| 3 | Domain-specific TFID logic | **Falsified** | no compares |
| 4 | Clean ≠ raw | **Falsified** | ≡ |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| 16-byte dword copy | **High** | pose/id corruption if wrong count |
| Type English | **n/a** | generic helper |

---

## 3. Surviving contract

```
Dword4_Copy(dst, src):
  dst[0..3] = src[0..3]
```

**Verdict:** **accept**
