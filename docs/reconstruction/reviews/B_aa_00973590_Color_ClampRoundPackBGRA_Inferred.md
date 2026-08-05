# Review B (skeptical / adversarial): `Color_ClampRoundPackBGRA_Inferred` / `FUN_00973590` @ `0x00973590`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00973590` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W29-I) |
| **Counterpart** | `reviews/A_aa_00973590_Color_ClampRoundPackBGRA_Inferred.md` |
| **Verdict** | **accept** on CF/ABI/channel map; reject decompiler-only stack-void and mid-channel alias labels |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Signature is pure cdecl `void(float,float,float,float)` with no dest | **Falsified** — **EAX dest**; stores through `in_EAX` |
| 2 | plain `ret` / caller-clean only | **Falsified** — **`ret 0x10`** |
| 3 | RGBA memory order (`dest[0]=f0` …) | **Falsified** — **BGRA**: f0→[2], f1→[1], f2→[0], f3→[3] |
| 4 | Truncate toward zero | **Falsified** — FPU **ROUND** (`fistp`) |
| 5 | This is the ×255 scale wrapper | **Falsified** — scale is `00973820`; this only clamps/packs |
| 6 | Decompiler out-of-range pointers (`&param_1` for channel 2 high) are literal | **Overstated** — stack-slot aliasing; value still 0 or 0xFF |
| 7 | D3DX math emulator primary identity | **Narrow** — legacy scaffold name; body is color pack |
| 8 | Runtime / bit-exact | **Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ret 0x10 + EAX dest + 4 floats | **Confirmed** | stack imbalance / wrong dest |
| BGRA channel indices | **Confirmed** | R/B swap in ports |
| ROUND + 0..255 clamp | **Confirmed** | banding / wrap |
| Product English | **Open** | docs only |
| Runtime | **Open** | |

---

## 3. Cross-check against raw + bytes

```
// EAX = dest; stack f0..f3; ret 0x10
dest[2] = clamp_u8(ROUND(f0));
dest[1] = clamp_u8(ROUND(f1));
dest[0] = clamp_u8(ROUND(f2));
dest[3] = clamp_u8(ROUND(f3));
```

Live decompile 2026-07-29 ≡ 2026-07-23 raw for channel **stores**. Epilogue bytes: `83 C4 0C C2 10 00`. Mid-channel decomp `puVar2 = &param_1` when high is a **labeling artifact** (lea of 0xFF stack slot).

---

## 4. Surviving contract for AutoCore

```
// EAX dest, 4 stack floats, ret 0x10, void, leaf
void Color_ClampRoundPackBGRA(uint8_t* dest, float r, float g, float b, float a):
  dest[0]=clamp_u8(ROUND(b))
  dest[1]=clamp_u8(ROUND(g))
  dest[2]=clamp_u8(ROUND(r))
  dest[3]=clamp_u8(ROUND(a))
```

Do **not** drop EAX dest. Do **not** use plain `ret`. Do **not** store RGBA as `[0]=r`. Do **not** merge scale-255 into this unit. Do **not** trust mid-channel decomp pointer labels over clamp semantics.

---

## 5. Falsification notes

### 5.1 “Decompiler signature is complete”

Surface omits EAX dest and `ret 0x10`. Callers of `00973820` / `00973690` set dest in ECX then `mov eax,ecx` before calling this.

### 5.2 “RGBA pack”

Sibling W28-F packed ARGB lerp extracts R/G/B/A then calls this; destination memory is BGRA (D3DCOLOR-style). Channel map sealed independently here.

### 5.3 “Is the scale function”

`Color_PackFloat4_Scale255_Inferred` multiplies by 255 then calls **this**. Clamp lives here only.

---

## 6. Open questions

1. Retail name for color-pack cluster (`00973590` / `00973690` / `00973820`).
2. Bit-exact / runtime — open.

**Verdict:** **accept** on sealed clamp-pack leaf. Reject stack-only/RGBA-memory/plain-ret overclaims.
