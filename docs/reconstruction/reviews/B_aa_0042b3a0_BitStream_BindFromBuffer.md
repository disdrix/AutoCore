# Review B (skeptical / adversarial): `aa_0042b3a0` BitStream_BindFromBuffer

| Field | Value |
|---|---|
| **Stable ID** | `aa_0042b3a0` |
| **VA** | `0x0042b3a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0042b3a0_BitStream_BindFromBuffer.md` |
| **Evidence** | Live decompile + body bytes; Damage/TNL callers |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Allocates / owns buffer | **Falsified** | owns@+0x14 = 0; no malloc |
| 2 | Same vtbl as ByteBuffer `009d7b00` | **Falsified** | `009d7b94` |
| 3 | Bit capacity = size (bytes) | **Falsified** | `size * 8` at +0x2c/+0x30 |
| 4 | Leaves bitPos uncleared | **Falsified** | +0x18 = 0 |
| 5 | Clean diverges from raw | **Falsified** | ≡ live |

---

## 2. Surviving contract

```
BindFromBuffer(this, buf, sizeBytes):
  this.vtbl = BitStream_vtbl_009d7b94
  this.data = buf; this.byteCap = sizeBytes; this.owns = 0
  this.bitPos = 0; this.bitMax = this.bitCap = sizeBytes*8
  clear error/flags/string-seed
```

**Verdict:** **accept-with-gaps**
