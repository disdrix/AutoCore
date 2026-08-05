# Review B (skeptical / adversarial): `aa_00521480` Character_SetDword_plusCf4_Dirty_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00521480` |
| **VA** | `0x00521480` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00521480_Character_SetDword_plusCf4_Dirty_Inferred.md` |
| **Evidence** | Live decompile + body bytes |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Skips when value unchanged | **Falsified** | always OR + store |
| 2 | ORs mission bit `0x10` only | **Falsified** | OR imm is `1` |
| 3 | Writes `+0xcf8` (twin) | **Falsified** | imm `0xcf4` |
| 4 | No local dirty flag | **Falsified** | `or [ecx+0x634], 1` |
| 5 | Dual vehicle dirty | **Falsified** | character net only |
| 6 | Clean ≡ raw | **Supported** | match |
| 7 | Field is known product ID | **Open** | residual |

---

## 2. Surviving contract

```
Character_SetDword_plusCf4(self, v):
  *(u32*)(self+0x634) |= 1
  *(u32*)(self+0xcf4) = v
  if charNet: NetObject_SetMaskBits(charNet, 0x20000000, 0)
```

**Verdict:** **accept-with-gaps**
