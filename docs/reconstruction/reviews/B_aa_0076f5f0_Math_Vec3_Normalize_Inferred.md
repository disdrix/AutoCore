# Review B (skeptical / adversarial): `aa_0076f5f0` Math_Vec3_Normalize_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076f5f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0076f5f0_Math_Vec3_Normalize_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Always writes unit vector | Near-zero band returns without stores | **Falsified** always-write |
| 2 | Zero → (1,0,0) safe default | No default axis; dest stale | **Falsified** |
| 3 | In-place only single pointer | Two formals; out then src on stack | **Falsified** |
| 4 | eps is 1e-5 or FLT_EPSILON | `read_memory` ±1e-6 (`0x358637bd` / `0xb58637bd`) | **Falsified** wrong eps |
| 5 | Same as mat4 transform | Pure length scale; no matrix | **Falsified** |

---

## 2. Live ≡ raw

Live ≡ raw: `len=sqrt(dot)`, band `(len < 1e-6) && (-1e-6 < len)` → return out; else `out = src * (1/len)`. Constants match mat4 dual’s shared eps globals.

---

## 3. Surviving contract

```
// out = Normalize(src):
// len = |src|
// if -1e-6 < len < 1e-6: return out  // unchanged
// out = src * (1/len); return out
```

**Gaps kept:** product name; caller reliance on stale out; runtime.

**Verdict:** **accept-with-gaps**.
