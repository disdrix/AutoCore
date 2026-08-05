# Annotated low-level: NDAssetImage_FlipHorizontal

| Field | Value |
|---|---|
| Stable ID | `aa_0098acc0` |
| VA | `0x0098acc0`–`0x0098ae77` |
| Canonical name | `NDAssetImage_FlipHorizontal` |
| Prior scaffold | `FUN_0098acc0` |
| System | client assets / `NDAssetImage` |
| Date | 2026-07-29 (W20-L) |

## Machine-level notes

- Source: live `decompile_function` + `read_memory` (no `disassemble_bytes`).
- **this in EDI** — all field loads `[EDI+disp]`; fail path `XOR AL,AL; ADD ESP,10; RET`.
- Object size for temp clone: **`0x1b8`** via `operator_new`.
- Vtable install on temp: `PTR_FUN_00a9bcac` (`C7 06 AC BC A9 00`).
- bpp short at `this+0x16`: **8** and **0x18 (24)** have dedicated reverse-copy loops; else per-pixel helpers.
- Last-pixel row offset: `((bpp==24)*2+1)*(width-1)` → 1×(w−1) for 8bpp, 3×(w−1) for 24bpp.
- Source pixels: `*(this+0x34)`; dest: `temp[0xd]` (= `temp+0x34`); row pitch step: `*(this+0x30)`.
- Post: `FUN_00433390` (ESI=temp; secondary buffer path at `+0x1b0`) then `FUN_00432580(original)` (EBX=temp → move state into EDI) then scalar-deleting dtor on temp (`vtbl[0](1)`).
- Sole caller: `NDAssetImage_LoadTGA` when TGA descriptor bit4 set.

## Object fields (this / NDAssetImage)

| Offset | Role | Confidence |
|---|---|---|
| `+0x04` | Create/valid gate (null → return 0) | **High** |
| `+0x0c` | Width in pixels (used with bpp for last-pixel offset) | **High** |
| `+0x10` | Height in rows | **High** |
| `+0x16` | bpp (`short`; 8 / 0x18 / other) | **High** |
| `+0x30` | Row pitch (bytes) for +0x34 store | **High** |
| `+0x34` | Pixel buffer pointer (raw store reverse-copied) | **High** |
| `+0x1b0` | Working buffer touched by `FUN_00433390` / transfer | **High** (sibling FlipVertical primary) |

## Pseudocode (annotated)

```c
// this in EDI; return AL success
uint8_t NDAssetImage_FlipHorizontal(/* NDAssetImage* this in EDI */)
{
  if (*(int*)(this+4) == 0) return 0;

  NDAssetImage* tmp = operator_new(0x1b8);
  if (!tmp) return 0;
  tmp->vtbl = &PTR_FUN_00a9bcac;
  FUN_004320d0(/* tmp init via regs */);
  FUN_00432260(this, 0, 0, 1);   // clone dims / setup into tmp

  short bpp = *(short*)(this + 0x16);
  int lastPxOff = ((bpp == 0x18) ? 3 : 1) * (*(int*)(this + 0xc) - 1);
  // decompiler form: ((bpp==0x18)*2 + 1) * (width - 1)
  uint8_t* dst = (uint8_t*)tmp[0xd];          // tmp+0x34
  uint8_t* src = *(uint8_t**)(this + 0x34) + lastPxOff;
  int pitch = *(int*)(this + 0x30);
  int height = *(int*)(this + 0x10);

  if (bpp == 8) {
    // per row: copy right→left bytes into left→right
    for (int y = 0; y < height; y++) {
      for (int i = 0; i <= lastPxOff; i++)
        dst[i] = src[-i];  // src walks backward from last pixel
      src += pitch; dst += pitch;
    }
  } else if (bpp == 0x18) {
    // per row: reverse RGB triplets (3-byte groups)
    for (int y = 0; y < height; y++) {
      // uVar7 = (lastPxOff + 3) / 3  pixel count
      // copy B,G,R groups from right edge leftward
      src += pitch; dst += pitch;
    }
  } else {
    // other bpp (incl. 16/32 paths): per-pixel helpers
    for (int y = 0; y < height; y++)
      for (int x = 0; x <= lastPxOff; x++) {
        FUN_00433530();
        FUN_004337d0(y);
      }
  }

  FUN_00433390();            // ESI=tmp — horizontal reverse of +0x1b0 store
  FUN_00432580(this);        // EBX=tmp — move tmp fields into original; zero tmp
  (*tmp->vtbl)(tmp, 1);      // scalar deleting destructor
  return 1;
}
```

## Open residual

- Product English names for `FUN_004320d0` / `FUN_00432260` / `FUN_00433390` / `FUN_00432580` / pixel helpers (not OWN).
- Exact relationship between `+0x34` reverse-copy and `+0x1b0` post-flip (dual buffers).
- Runtime golden with bit4 TGA fixtures.
