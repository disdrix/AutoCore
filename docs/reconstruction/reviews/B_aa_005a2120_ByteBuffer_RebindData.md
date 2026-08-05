# Review B (skeptical / adversarial): `aa_005a2120` ByteBuffer_RebindData

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a2120` |
| **VA** | `0x005a2120` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005a2120_ByteBuffer_RebindData.md` |
| **Evidence** | Live decompile; PostCorrectionEvent; ByteBuffer layout |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Always frees old data | **Falsified** | only when owns≠0 |
| 2 | Uses operator_delete | **Falsified** | `free` |
| 3 | Constructs vtbl | **Falsified** | rebind only |
| 4 | Leaves owns uncleared before free | **Falsified** | clears owns first |
| 5 | Clean ≠ raw | **Falsified** | ≡ |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| owns-gated free + rebind | **High** | leak / double-free |
| Layout +0xC/+0x10/+0x14 | **High** | wrong field |
| Runtime | **Open** | — |

---

## 3. Surviving contract

```
RebindData(this, data, size, owns):
  if this.owns: this.owns=0; free(this.data)
  this.data=data; this.size=size; this.owns=owns
```

**Verdict:** **accept-with-gaps**
