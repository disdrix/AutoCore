# Review B (skeptical / adversarial): `aa_004c2f10` Object_SetU16_plus142

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c2f10` |
| **VA** | `0x004c2f10` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004c2f10_Object_SetU16_plus142.md` |
| **Evidence** | Live decompile + body bytes; callers |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Sets mask bits / dirties net | **Falsified** | Single store; `ret 4` |
| 2 | Clamps or validates value | **Falsified** | raw store |
| 3 | Writes different offset than `0x142` | **Falsified** | imm `0x142` (`42 01 00 00`) in encoding |
| 4 | thiscall with 0 stack args | **Falsified** | `ret 4` one stack word |
| 5 | Clean diverges from raw | **Falsified** | ≡ live |
| 6 | Product attr name is known | **Open** | not established by body |

---

## 2. Surviving contract

```
Object_SetU16_plus142(self, value16):
  *(u16*)(self + 0x142) = value16
```

**Verdict:** **accept-with-gaps**
