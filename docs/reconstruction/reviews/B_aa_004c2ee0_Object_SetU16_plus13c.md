# Review B (skeptical / adversarial): `aa_004c2ee0` Object_SetU16_plus13c

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c2ee0` |
| **VA** | `0x004c2ee0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004c2ee0_Object_SetU16_plus13c.md` |
| **Evidence** | Live decompile + body bytes; callers |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Sets mask bits / dirties net | **Falsified** | Single store; `ret 4` |
| 2 | Clamps or validates value | **Falsified** | raw store |
| 3 | Writes different offset than `0x13c` | **Falsified** | imm `0x13c` in encoding |
| 4 | thiscall with 0 stack args | **Falsified** | `ret 4` one stack word |
| 5 | Clean diverges from raw | **Falsified** | ≡ live |

---

## 2. Surviving contract

```
Object_SetU16_plus13c(self, value16):
  *(u16*)(self + 0x13c) = value16
```

**Verdict:** **accept-with-gaps**
