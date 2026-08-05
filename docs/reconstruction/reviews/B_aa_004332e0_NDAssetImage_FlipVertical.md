# Review B (skeptical / adversarial): `aa_004332e0` NDAssetImage_FlipVertical

| Field | Value |
|---|---|
| **Stable ID** | `aa_004332e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004332e0_NDAssetImage_FlipVertical.md` |
| **Verdict** | **accept-with-gaps** on CF/layout; pitch-vs-width residual |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Horizontal flip / mirror X | Source starts at **last row**, steps **−pitch**; columns never reversed | **Falsified** — vertical only |
| 2 | In-place swap of row pairs without alloc | Body always `malloc` full buffer then `free` old | **Falsified** — out-of-place replace |
| 3 | `+0x0c` is pixel width always | Used only as **byte** count for size/copy/step; no bpp multiply in this unit | **Overstated if “width”** — treat as **row pitch (bytes)** |
| 4 | `__cdecl` / stack `this` | No stack args; fields via **EBX** | **Falsified** — **this in EBX** |
| 5 | Full `EAX` success code | Fail/success set **`AL` only** (`XOR AL` / `MOV AL,1`) | **Clarify** — bool in AL (upper EAX junk possible) |
| 6 | Flips for all TGA origins/bpp | Caller gate is **LoadTGA**: top-origin bit + **32bpp** only | **Context** — unit itself is bpp-agnostic pitch×height |
| 7 | Leaves `+0x0c`/`+0x10` unchanged | Only mutates `+0x1b0` pointer | **Confirmed** — dimensions not rewritten |
| 8 | Null-safe if height invalid | Null **buffer** checked; height≤0 skips copy but still free+install if malloc ok | **Edge** — no explicit height>0 require for replace path |
| 9 | Decompiler missed REP bulk | Bytes show `F3 A5` / `F3 A4` matching dword/byte loops | **No conflict** |
| 10 | Modern “std::swap rows” without free | Retail always free old after copy | **Port trap** — must free old buffer |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Vertical row reverse of buffer | **High** | Upside-down maps / textures |
| pitch `+0xc`, height `+0x10`, buf `+0x1b0` | **High** | Wrong stride → tear/OOB |
| Return 0/1 in AL | **High** | Caller branch if they test full EAX |
| this in EBX | **High** | Wrong ABI → corrupt object |
| malloc size = pitch×height | **High** | Truncate/overread |
| “pitch == width×4 always” | **Medium** | Wrong if non-32bpp path ever calls |
| Semantic “y=0 is bottom after flip” | **High** w.r.t. LoadTGA plate | GetPixel origin bugs |
| Full class layout | **Low** (out of scope) | Unrelated fields |

---

## 3. Cross-check against raw / bytes

```
raw decompile:
  if (this->buf==0) return 0;
  tmp = malloc(pitch * height);
  if (!tmp) return 0;
  src = buf + (height-1)*pitch;
  for rows: copy pitch (>>2 dwords + &3 bytes); src-=pitch; dst+=pitch;
  free(buf); buf=tmp; return 1;

bytes:
  CMP [EBX+0x1b0],0 → AL=0 RET
  IMUL [EBX+0xC]*[EBX+0x10] → CALL malloc
  LEA (height-1)*pitch + buf → REP MOVSD/MOVSB loop
  CALL free; MOV [EBX+0x1b0],tmp; MOV AL,1; RET
```

Clean ≡ raw CF outline. Scaffold return-type comment noise only.

---

## 4. Surviving contract for AutoCore

```csharp
// Behavior-exact vertical flip of NDAssetImage pixel store
// this: EBX on x86 retail; managed port = NDAssetImage instance
bool NDAssetImage_FlipVertical(NDAssetImage self)
{
    byte* buf = self.PixelBuffer;      // +0x1b0
    if (buf == null) return false;

    int pitch  = self.RowPitchBytes;   // +0x0c  (byte stride, not pixel width)
    int height = self.Height;          // +0x10
    int bytes  = pitch * height;

    byte* tmp = malloc(bytes);
    if (tmp == null) return false;

    byte* src = buf + (height - 1) * pitch;
    byte* dst = tmp;
    for (int row = 0; row < height; row++) {
        memcpy(dst, src, pitch);       // retail: REP MOVSD + MOVSB
        src -= pitch;
        dst += pitch;
    }

    free(buf);
    self.PixelBuffer = tmp;            // only +0x1b0 rewritten
    return true;                       // AL=1
}
```

**Port traps to reject:**

- Interpreting as horizontal flip / rotate 180 (180 would reverse rows **and** columns).
- Using `width` in pixels without multiplying bpp for allocation/copy.
- `realloc` / in-place pairwise row swap that keeps the same pointer (retail installs a **new** pointer).
- Stack/`__thiscall` ECX `this` without evidence (retail field access is **EBX**).
- Skipping `free` of the previous buffer.
- Inventing bpp conversion or channel swizzle inside this unit (none in body).

---

## 5. Residual gaps (do not block CF seal)

1. Confirm pitch packing for every bpp NDAssetImage can hold (own unit does not read bpp).
2. Whether `FUN_0098ae80` path always leaves 32bpp-compatible pitch (sibling residual).
3. Clean plate rename pass (`unaff_EBX` → `this`, drop bogus “width” return note).
4. Live runtime / bit-exact image verification deferred.

---

## Verdict

**accept-with-gaps** — adversarial review cannot break the **vertical pitch-stride row reverse + buffer replace** kernel. Main falsification targets are “horizontal flip”, “pixel width at +0xc”, and “stack thiscall”. Main residual is product naming of pitch vs width×bpp outside this VA.
