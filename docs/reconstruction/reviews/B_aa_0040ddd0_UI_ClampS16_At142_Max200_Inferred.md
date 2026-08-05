# Review B (skeptical / adversarial): `aa_0040ddd0` UI_ClampS16_At142_Max200_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040ddd0` |
| **VA** | `0x0040ddd0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0040ddd0_UI_ClampS16_At142_Max200_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | NDUI child ctor for CharSheet | **Falsified** | No new/vtbl; 6-insn clamp only |
| 2 | Clamps to 199 inclusive max | **Falsified** | Predicate `199 < v` → set **200** (max 200) |
| 3 | Writes back to +0x142 | **Falsified** | Read-only return |
| 4 | Network / spend opcode | **Falsified** | Pure local getter |
| 5 | Always character object | **Open / not sealed** | Callers share attr UI; type residual |

---

## 2. Surviving contract

```
return min((int)(int16)this[+0x142], 200)   // if >199 → 200
```

**Verdict:** **accept-with-gaps** (CF sealed; product field name open)
