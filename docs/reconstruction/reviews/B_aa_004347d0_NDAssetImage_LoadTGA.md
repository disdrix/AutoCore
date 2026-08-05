# Review B (skeptical / adversarial): `aa_004347d0` NDAssetImage_LoadTGA

| Field | Value |
|---|---|
| **Stable ID** | `aa_004347d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004347d0_NDAssetImage_LoadTGA.md` |
| **Verdict** | **accept-with-gaps** on CF / header / origin policy; residual row-decoder + stream type names |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Function is `thiscall` on the image | **Falsified** — free formals `[ebp+8]` image, `[ebp+0xc]` stream; prologue `read_memory` |
| 2 | All errors return 0 | **Falsified** — only null stream returns 0; header/type/create/cancel/corrupt **throw** |
| 3 | Supports arbitrary TGA (RLE-only, all bpp) | **Falsified** — types 1–3 and 9–11 only; bpp ∈ {8,15,16,24,32}; cmapLen ≤ 0x100 |
| 4 | Always FlipVertical for top-origin | **Falsified** — requires **bit5 AND bpp==32** (`local_1c == ' '`) |
| 5 | Never flips horizontal | **Falsified** — bit4 → `FUN_0098acc0` after row loop |
| 6 | Colormap only for image type 1/9 | **Overstated** — gate is **color-map type byte ≠ 0**, not image type |
| 7 | Palette entries are 32-bit | **Falsified** — read `cmapLen*3`; BGR triplets |
| 8 | Multiple independent callers | **Falsified** — sole `FUN_00432cb0` (two call sites) |
| 9 | Decompile drifted vs raw / force | **Falsified** — three-rep identical |
| 10 | Bottom-origin files are flipped | **Falsified** — bottom (bit5 clear) keeps file order; only top-origin 32bpp flips |
| 11 | Clean modernized / reordered CF | **Falsified** — clean is scaffold ≡ raw |
| 12 | Cancel only checked once at start | **Falsified** — pre-decode and every row iteration |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Null stream → 0 | **High** | Spurious throw / silent fail invert |
| Type allow-list + RLE flag | **High** | Wrong decode path / reject good assets |
| BPP allow-list | **High** | Bad create / throw on valid art |
| Origin bit5 + 32 → FlipVertical | **High** | Upside-down `map.tga` area ids / pixels |
| Origin bit4 → `FUN_0098acc0` | **High** call; **Probable** as H-flip | Mirrored pixels if misnamed |
| Image `+4` create success / `+0x148` cancel | **High** | Cancel ignored or false TGA Create |
| Stream vtbl +8 / +0x10 / +0x20 roles | **High** | Wrong I/O abstraction when porting |
| Row helper semantics (`34dd0`/`34b30`) | **Tentative** | RLE edge cases |
| `FUN_004323e0` / `00433180` product meaning | **Tentative** | Wrong internal pixel layout |
| Exception type / catch contract | **Tentative** | Wrong error surface for callers |

---

## 3. Cross-check against three-rep

```
Rep A — decompile_function(0x004347d0):
  null stream→0; header 0x12; types 1-3 / 9-11; bpp gates;
  create; cmap; greyscale; origin bits; row loop; flip; return 1

Rep B — force_decompile(0x004347d0):
  identical pseudocode (no CF drift)

Rep C — batch_decompile + read_memory prologue + xrefs:
  SEH + sub esp,0x368; formals ebp+8/+0xc; body 004347d0-00434b11;
  sole caller FUN_00432cb0 @ 00432d14, 00432ff6
  on-disk raw (2026-07-23) matches live body
```

**Attack on “scaffold is enough without three-rep”:** CF already stable in raw; three-rep still required to prove no plate/name drift and to seal ABI formals from prologue bytes. **Pass.**

**Attack on decompiler `_local_1c >> 8` origin extract:** packing is ugly but bit masks `0x10` / `0x20` match TGA image-descriptor origin bits at header byte 17; plate comment names bit5 explicitly. **Accept with known decomp artifact.**

---

## 4. Surviving contract for AutoCore

```
NDAssetImage_LoadTGA(image*, stream*) -> 1 | 0 | throw:
  if stream == null: return 0
  read 18-byte TGA header (fail → throw "Not a TGA")
  imageType in {1,2,3} → raw rows; {9,10,11} → RLE rows; else throw
  require width>0, height>0, bpp>0, colorMapLength<=256
  require bpp in {8,15,16,24,32}
  skip idLen bytes if any
  create image (FUN_004323e0; 32bpp extra FUN_00433180); fail → throw
  if image.cancel(+0x148): throw "Cancelled"
  if colorMapType: load colorMapLength * 3 BGR → palette slots
  if type 3 or 11: greyscale prep
  originH = descriptor.bit4; originTop = descriptor.bit5
  for y in 0..height-1:
    if cancel: throw
    if stream.eof/error: throw "corrupted TGA"
    decode one row (raw or RLE helper)
  if originH: FUN_0098acc0()            // probable FlipHorizontal
  if originTop && bpp==32: NDAssetImage_FlipVertical()
  return 1

// GetPixel y=0 is always image bottom after successful load of top-origin 32bpp.
// Bottom-origin TGAs keep file row order.
```

### Error surface

| Condition | Behavior |
|---|---|
| `stream == null` | `return 0` |
| Short / failed header read | throw `"Not a TGA"` |
| Bad type / dims / bpp / cmapLen | throw `"bad TGA header"` or `"Unknown TGA image type"` |
| Create failed (`image+4==0`) | throw `"TGA Create failed"` |
| Cancel flag | throw `"Cancelled"` |
| Mid-stream EOF/error | throw `"corrupted TGA"` |
| Success | `return 1` |

---

## 5. Residual uncertainty (honest)

| # | Item | Blocks seal? |
|---|---|---|
| R1 | Stream interface product type / full vtable | **No** (slots used are sealed) |
| R2 | `FUN_00434dd0` / `FUN_00434b30` pixel packing | **No** for loader CF; **Yes** if porting decoder |
| R3 | `FUN_0098acc0` English name | **No** (call site sealed) |
| R4 | Why V-flip only at 32bpp | **No** (binary gate sealed) |
| R5 | `NDAssetImage` full layout | **No** for this unit |
| R6 | Live `map.tga` differential | Open / deferred |

---

## 6. Falsification checklist

| Attempt | Result |
|---|---|
| Invert origin bit5 polarity | Conflicts with plate + FlipVertical call condition |
| Claim FlipVertical for all top-origin | Asm requires bpp==32 |
| Claim return codes for all failures | Throws dominate; only null stream is soft-fail |
| Claim multiple callers | Ghidra xrefs: only `FUN_00432cb0` |
| Claim clean reorders decode | clean ≡ raw scaffold |
| Claim colormap size uses entry-size field | Code always `*3` bytes per entry |

**Verdict:** **accept-with-gaps** — adversarial checks failed to break header validation, type/RLE split, cancel polarity, or origin post-process; decoder helper bodies and stream type names remain residual.
