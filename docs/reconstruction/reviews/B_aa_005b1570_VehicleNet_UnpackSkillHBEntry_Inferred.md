# Review B (skeptical / adversarial): `aa_005b1570` VehicleNet_UnpackSkillHBEntry_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b1570` |
| **VA** | `0x005b1570` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005b1570_VehicleNet_UnpackSkillHBEntry_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Pure bulk `readBits(size*8, out)` | **Falsified** | structured 14/8/8 + flags + optional 64b + tail |
| 2 | No opcode stamp | **Falsified** | writes **0x2014** at `*out` |
| 3 | Same as hardpoint blob fill | **Falsified** | skills path only; sole caller UnpackOwnerSkillsHB |
| 4 | Fail path aborts process | **Falsified** | sticky `stream+0x1c=1` + defaults |
| 5 | Pack widths differ | **Falsified** | matches pack twin 14/8/8 + 10 + tails |

---

## 2. Surviving contract

```
UnpackSkillHBEntry(base, stream, out, size):
  out.fields = read structured head; *out = 0x2014
  optional extended block || defaults from base+0x40
  if size>0x38: readBits((size-0x38)*8, out+0x38)
```

**Verdict:** **accept-with-gaps**
