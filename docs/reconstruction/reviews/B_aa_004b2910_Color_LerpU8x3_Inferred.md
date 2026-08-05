# Review B (skeptical / adversarial): `Color_LerpU8x3_Inferred` / `FUN_004b2910` @ `0x004b2910`

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b2910` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W28-E) |
| **Counterpart** | `reviews/A_aa_004b2910_Color_LerpU8x3_Inferred.md` |
| **Verdict** | **accept-with-gaps** on CF/ABI/role; **needs-more-evidence** on product color-slot English |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is float RGB lerp | **Falsified** — U8 channels with ROUND, not float stores |
| 2 | 4-channel / includes alpha | **Falsified** — only indices 2,1,0 |
| 3 | `thiscall` / ECX this | **Falsified** — all four args on stack; plain `ret` |
| 4 | `ret 0x10` stdcall | **Falsified** — plain `C3`; callers `add esp,10` |
| 5 | Linear without ROUND | **Falsified** — ROUND after mulss thrice |
| 6 | Multi-caller shared util | **Weak / mostly false** — sole code caller is ApplyStageParams |
| 7 | Product field names sealed | **Open** |
| 8 | Runtime / bit-exact | **Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| cdecl void plain ret | **Confirmed** | stack imbalance |
| 3-channel ROUND lerp | **Confirmed** | wrong color intermediate |
| Channel order 2→1→0 | **Confirmed** | BGR swap |
| No alpha write | **Confirmed** | clobber neighbor byte |
| Sole ApplyStageParams consumer | **High** | missed xref |
| Product C++ name / slot labels | **Open** | docs only |
| Runtime | **Open** | |

---

## 3. Cross-check against raw + bytes

```
// cdecl
out[2] = from[2] + ROUND((to[2]-from[2]) * t)
out[1] = from[1] + ROUND((to[1]-from[1]) * t)
out[0] = from[0] + ROUND((to[0]-from[0]) * t)
// ret
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Full-body `read_memory` ends `5F 88 16 5E C3`.

---

## 4. Surviving contract for AutoCore

```
// cdecl, plain ret, void, leaf
void Color_LerpU8x3(float t, uint8_t* out, const uint8_t* from, const uint8_t* to):
  for i in (2, 1, 0):
    out[i] = from[i] + round((int)to[i] - (int)from[i]) * t
// Called only from ObjectMotion_ApplyStageParams (dirty RNG + continuous progress)
```

Do **not** expand to 4 channels. Do **not** skip ROUND. Do **not** treat as float lerp. Preserve channel order 2→1→0.

---

## 5. Falsification notes

### 5.1 “Float color lerp”

Body uses `movzx` byte loads, integer subtract, float mul, ROUND, byte store — classic U8 lerp, not float RGB.

### 5.2 “Includes alpha”

No fourth channel block; continuous path lerps alpha-like single bytes **inline** in ApplyStageParams, not via this helper.

### 5.3 “stdcall ret 16”

Call sites explicitly `add esp, 0x10` after `call` — cdecl.

---

## 6. Open questions

1. Retail name / product class of the 3-byte color blobs.
2. Whether any data xref (vtable) exists beyond the 3 code xrefs — none found in analyze.
3. Bit-exact / runtime — open.

**Verdict:** **accept-with-gaps** on sealed leaf U8×3 ROUND lerp and cdecl ABI. Reject float/4-channel/thiscall overclaims.
