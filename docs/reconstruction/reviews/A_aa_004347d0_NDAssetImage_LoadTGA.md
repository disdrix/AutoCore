# Review A (reconstruction fidelity): `aa_004347d0` NDAssetImage_LoadTGA

| Field | Value |
|---|---|
| **Stable ID** | `aa_004347d0` |
| **VA** | `0x004347d0` |
| **Canonical name** | `NDAssetImage_LoadTGA` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (faithfulness of clean / annotated to Ghidra decompile) |
| **Counterpart** | `reviews/B_aa_004347d0_NDAssetImage_LoadTGA.md` |
| **System** | `gfx-asset` / `NDAssetImage` |
| **Verdict** | **accept-with-gaps** — TGA header / type / bpp / origin CF sealed; row-decoder and stream-vtable English residual |

---

## 1. Purpose

Load a TGA from an abstract stream into an `NDAssetImage` instance. Validates the 18-byte header, optionally skips ID field and loads a 24-bit colormap, allocates/configures the image buffer, then decodes **one row per outer loop iteration** via uncompressed (`FUN_00434dd0`) or RLE (`FUN_00434b30`) helpers. After all rows: if image-descriptor **bit4** (right→left) call `FUN_0098acc0`; if **bit5** (top origin) **and** bpp==32 call `NDAssetImage_FlipVertical` so `GetPixel` y=0 is always image bottom. Plate: used by `CVOGTerrain_LoadMapImage` for `map.tga` area ids (via intermediate `FUN_00432cb0`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live Ghidra | `decompile_function` `0x004347d0`; `force_decompile` (identical); `batch_decompile` (identical) |
| Prologue bytes | `read_memory` @ `0x004347d0` len 64 — SEH frame, `sub esp,0x368`, formals `[ebp+8]` / `[ebp+0xc]` |
| Function body | Entry `0x004347d0` … end `0x00434b11` |
| Xrefs to | `get_xrefs_to` / callers: sole `FUN_00432cb0` @ `0x00432d14`, `0x00432ff6` |
| Callees | `get_function_callees` (listed below) |
| Raw | `docs/reconstruction/raw/aa_004347d0_NDAssetImage_LoadTGA.md` |
| Annotated | `docs/reconstruction/raw/aa_004347d0_NDAssetImage_LoadTGA.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NDAssetImage_LoadTGA.cpp` |
| Function record | `docs/reconstruction/functions/aa_004347d0_NDAssetImage_LoadTGA.md` |
| Sibling (context only) | `NDAssetImage_FlipVertical` `0x004332e0` (own dual out of scope) |

**Three-rep this pass** — decompile ≡ force ≡ batch ≡ on-disk raw body (no CF drift).

---

## 3. Signature (ABI from prologue + decompile)

```c
// Free function (not thiscall): arg0 = NDAssetImage*, arg1 = stream object*
// Prologue (read_memory @ 0x004347d0):
//   push ebp; mov ebp,esp; SEH setup; sub esp,0x368
//   mov edi,[ebp+8]   ; param_1 image
//   mov esi,[ebp+0xc] ; param_2 stream
//   cmp esi,0 → return 0
undefined4 NDAssetImage_LoadTGA(int image /*param_1*/, int *stream /*param_2*/);
// Success return 1; null stream return 0; most failures throw C++ exception (DAT_00acc49c).
```

| Formal | Role | Confidence |
|---|---|---|
| `param_1` | `NDAssetImage*` — create result checked at `+0x4`; cancel flag at `+0x148` | **High** |
| `param_2` | Stream / reader with vtable (`+8` read, `+0x10` skip, `+0x20` eof/error) | **High** (layout); English name **Tentative** |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Null `stream` → return `0` (no throw) | **High** | First gate |
| Read 18 (`0x12`) bytes header via `stream.vtbl+8(buf, 0x12, 1)` | **High** | Fail → throw `"Not a TGA"` |
| Image types 1/2/3 → uncompressed (`local_15=0`); 9/10/11 → RLE (`local_15=1`); else throw | **High** | Standard TGA type codes |
| Width `local_20`, height `local_1e`, bpp `local_1c`; reject 0 dims / 0 bpp / colormap length `>0x100` | **High** | `"bad TGA header"` |
| Allowed bpp: 8, 15, 16, 24, 32 only | **High** | Second header check |
| ID field skip: if `idLen!=0`, `stream.vtbl+0x10(idLen,1)` | **High** | |
| `FUN_004323e0(width, bpp, 3)` then if bpp==32 `FUN_00433180()`; `image+4==0` → `"TGA Create failed"` | **High** CF; helper semantics **Tentative** |
| Cancel `image+0x148 != 0` → throw `"Cancelled"` (pre-decode and mid-loop) | **High** | |
| Colormap if type≠0: read `cmapLen*3` into stack buf; loop `FUN_00433440(R,G,B,0)` with BGR→RGB swap | **High** | 24-bit entries assumed |
| Greyscale types 3/11 → `FUN_00433a00()` | **High** call site |
| Image descriptor: bit4 → `local_17` (H flip later); bit5 → `local_16` (V flip gate) | **High** intent; decomp uses `_local_1c>>8` for descriptor byte (header off 17) | **High** with known decomp packing artifact |
| Per-row: eof/error `vtbl+0x20` non-zero → `"corrupted TGA"`; `FUN_00433d70()`; uncompressed `FUN_00434dd0` vs RLE `FUN_00434b30` | **High** CF |
| Post-loop: bit4 → `FUN_0098acc0()`; bit5 **and** bpp==32 → `NDAssetImage_FlipVertical()`; return 1 | **High** | FlipVertical **not** applied for 24bpp top-origin |
| Sole direct caller `FUN_00432cb0` (two sites) | **High** | xrefs |
| Clean ≡ raw control flow | **High** | Scaffold rewrite; no modernization of CF |
| Bit-for-bit / runtime / differential | **Open** | Deferred |

---

## 5. Control flow: clean ≡ raw / decompile

| Stage | Match |
|---|---|
| Null stream → 0 | **Yes** |
| Header read + type switch + bpp/dim validation | **Yes** |
| ID skip + Create + cancel gate | **Yes** |
| Optional colormap load | **Yes** |
| Greyscale prep | **Yes** |
| Origin bits + row loop (uncomp / RLE) | **Yes** |
| Post-process H/V flip + return 1 | **Yes** |
| Cancel mid-loop throw | **Yes** |
| No invented formats (PNG/DDS) | **Yes** |

---

## 6. TGA header map (this function's stack locals)

| TGA offset | Field | Local | Use |
|---|---|---|---|
| 0 | ID length | `local_2c` | Skip via vtbl+0x10 |
| 1 | Color-map type | `local_2b` | Gate palette load |
| 2 | Image type | `local_2a` | RLE flag + greyscale |
| 5–6 | Color-map length | `local_27` | Palette entry count (cap ≤0x100) |
| 12–13 | Width | `local_20` | Create + row decode |
| 14–15 | Height | `local_1e` | Outer row loop bound |
| 16 | Pixel depth | `local_1c` | bpp allow-list; 32 → extra create + FlipVertical gate |
| 17 | Image descriptor | high byte of `_local_1c` packing | bit4 H-origin, bit5 V-origin |

Standard TGA; colormap first-entry / entry-size / X-Y origin fields are read into the 18-byte block but not branched on in this unit.

---

## 7. Stream vtable (observed slots)

| Off | Args (decomp) | Role |
|---|---|---|
| `+8` | `(buf, size, count=1)` → nonzero ok | Read |
| `+0x10` | `(n, 1)` | Skip/seek forward `n` bytes (ID field) |
| `+0x20` | `()` → char | Nonzero treated as EOF/error (`"corrupted TGA"`) |

---

## 8. Callees (own-VA boundary)

| VA | Name in decomp | Role (inferred) |
|---|---|---|
| `0x004323e0` | `FUN_004323e0` | Image create/alloc (width, bpp, 3) |
| `0x00433180` | `FUN_00433180` | 32bpp post-create setup |
| `0x00433440` | `FUN_00433440` | Palette entry write (R,G,B,A=0) |
| `0x00433a00` | `FUN_00433a00` | Greyscale type prep |
| `0x00433d30` | `FUN_00433d30` | Pre-row-loop setup |
| `0x00433d70` | `FUN_00433d70` | Per-row packet / state |
| `0x00434dd0` | `FUN_00434dd0` | Uncompressed row decode |
| `0x00434b30` | `FUN_00434b30` | RLE row decode (returns next RLE state byte) |
| `0x004332e0` | `NDAssetImage_FlipVertical` | Normalize top-origin 32bpp |
| `0x0098acc0` | `FUN_0098acc0` | Probable horizontal flip (bit4) |
| `0x006a3d60` | `_CxxThrowException` | Error paths |

Callee bodies **not** dual-reviewed this pass (own VA only).

---

## 9. Gaps / open (acceptable for accept-with-gaps)

1. Product English names for stream interface and `FUN_004323e0` / row decoders.
2. Whether `FUN_0098acc0` is exactly `FlipHorizontal` (High by origin bit; not string-sealed here).
3. Why FlipVertical is gated to **32bpp only** (binary fact; product rationale residual).
4. Full `NDAssetImage` layout beyond `+4` buffer and `+0x148` cancel.
5. Exception type `DAT_00acc49c` / catcher policy outside this unit.
6. Runtime load of a retail `map.tga` vs buffer (deferred).

**Verdict:** **accept-with-gaps** — loader contract, header validation, type/RLE split, origin post-process, and exception vs return-0 polarity sealed from three-rep decompile.

---

## Checklist (reviewer)

| Check | Result |
|---|---|
| Clean CF matches raw / live decompile | **Pass** |
| Three-rep agreement | **Pass** (decomp ≡ force ≡ batch ≡ raw) |
| Header / type / bpp allow-list | **Pass** |
| Origin bit5 + 32bpp → FlipVertical only | **Pass** |
| Sole caller named | **Pass** (`FUN_00432cb0` ×2) |
| Row decoder internals | **Open** (documented residual) |
| Verdict | **accept-with-gaps** |
