# Review B (skeptical / adversarial): `aa_00424ce0` ByteBuffer_ctor_BindExternal

| Field | Value |
|---|---|
| **Stable ID** | `aa_00424ce0` |
| **VA** | `0x00424ce0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00424ce0_ByteBuffer_ctor_BindExternal.md` |
| **Evidence** | Live decompile; vtbl cross-unit ByteBuffer seals; PostCorrectionEvent |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Sets owns=1 | **Falsified** | byte at +0x14 = 0 |
| 2 | mallocs data | **Falsified** | stores param_2 only |
| 3 | Different vtbl than skills HB wrap | **Falsified** | same `009d7b00` |
| 4 | Non-trivial CF | **Falsified** | leaf stores |
| 5 | Clean ≠ raw | **Falsified** | ≡ |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| External bind ctor | **High** | double-free if mis-owned |
| Layout offsets | **High** | corrupt buffer object |
| Product typename | **Medium** | naming |
| Runtime | **Open** | — |

---

## 3. Surviving contract

```
ByteBuffer_ctor_BindExternal(this, data, size):
  vtbl = 009d7b00
  refA=refB=0
  this.data = data; this.size = size; this.owns = 0
```

**Verdict:** **accept-with-gaps**
