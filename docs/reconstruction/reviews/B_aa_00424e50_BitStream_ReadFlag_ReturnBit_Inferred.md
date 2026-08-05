# Review B (skeptical / adversarial): `aa_00424e50` BitStream_ReadFlag_ReturnBit_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00424e50` |
| **VA** | `0x00424e50` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00424e50_BitStream_ReadFlag_ReturnBit_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Same as `BitStream_readFlag` `0x0042ad50` | **Falsified** | different VA + return ABI (bit vs success/out-param) |
| 2 | Reads 8-bit integer | **Falsified** | one bit; shifts mask |
| 3 | On OOB returns previous EAX garbage as true | **Falsified** | clears low byte → 0 |
| 4 | VehicleNet-only helper | **Falsified** | challenge-response also calls |
| 5 | Advances cursor by 8 | **Falsified** | `+1` bit |

---

## 2. Surviving contract

```
readFlagRet(stream):
  if bitPos > max: err=1; return 0
  b = bit(buffer, bitPos); bitPos++; return b
```

**Verdict:** **accept-with-gaps**
