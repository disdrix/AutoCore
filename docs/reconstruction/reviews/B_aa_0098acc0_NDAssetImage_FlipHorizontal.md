# Review B (skeptical / adversarial): `aa_0098acc0` NDAssetImage_FlipHorizontal

| Field | Value |
|---|---|
| **Stable ID** | `aa_0098acc0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0098acc0_NDAssetImage_FlipHorizontal.md` |
| **Verdict** | **accept-with-gaps** on CF/ABI/role; dual-buffer residual |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Vertical flip / same as FlipVertical | Rows stay in order; columns reversed from right edge; sibling FlipVertical walks **last row** by pitch | **Falsified vertical** — horizontal only |
| 2 | In-place single buffer swap | Always `operator_new(0x1b8)` + later scalar delete; transfer via `FUN_00432580` | **Out-of-place temp object** |
| 3 | `this` in ECX / stack | Fields via **EDI**; no stack `this` | **this in EDI** |
| 4 | Full EAX success code | Fail/success set **AL** only | **bool in AL** |
| 5 | Only 8bpp | Dedicated 24bpp triplet path + else helpers | **Multi-bpp** |
| 6 | lastPxOff = width always | `((bpp==24)*2+1)*(width-1)` — last **byte** offset of last pixel | **Sealed formula** |
| 7 | Caller for every TGA | LoadTGA only when **bit4**; bit5 uses FlipVertical (32bpp gate) | **Context sealed** |
| 8 | `+0x0c` is pitch | Used as **pixel width** in lastPxOff; pitch is **`+0x30`** | **width vs pitch distinct** |
| 9 | `FUN_00433390` is vertical | Context decompile (read-only): reverse within rows of `+0x1b0` | **Also horizontal** (secondary store) |
| 10 | No destroy of temp | Epilogue `CALL [vtbl]` with arg 1 after transfer | **Scalar deleting dtor** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Horizontal reverse role | **High** | Mirrored textures / map.tga |
| this in EDI; AL return | **High** | Wrong ABI port |
| bpp 8 / 24 / else | **High** | Wrong channel packing |
| width `+0xc`, pitch `+0x30`, buf `+0x34` | **High** | OOB / tear |
| TGA bit4 sole caller | **High** | Wrong origin fixups |
| `+0x34` vs `+0x1b0` product story | **Medium** | Miss which buffer GetPixel uses |
| Helper English names | **Low** (out of OWN) | Doc only |
| Runtime golden | **Open** | Edge bpp (15/16/32) |

---

## 3. Cross-check against raw / bytes

```
raw 2026-07-23 ≡ live decompile 2026-07-29 ≡ clean NDAssetImage_FlipHorizontal.cpp

entry:
  83 EC 10           SUB ESP,10
  83 7F 04 00        CMP [EDI+4],0
  75 06 / 32 C0 / 83 C4 10 / C3
  68 B8 01 00 00     PUSH 0x1B8
  … operator_new …
  C7 06 AC BC A9 00  MOV [ESI], 00a9bcac

tail:
  CALL FUN_00433390
  PUSH EDI; MOV EBX,ESI; CALL FUN_00432580
  MOV EAX,[EBX]; PUSH 1; MOV ECX,EBX; CALL [EAX]
  MOV AL,1; ADD ESP,10; RET
```

Reject ports that:

- Treat as vertical flip or 180° rotate alone.
- Assume ECX thiscall without EDI.
- Drop 24bpp triplet path or other-bpp helpers.
- Leak the 0x1b8 temp (must destroy after transfer).
- Use `+0x0c` as byte pitch (that is `+0x30` here).

---

## 4. Surviving contract for AutoCore

```csharp
// Behavior-exact horizontal flip of NDAssetImage (TGA right-origin normalize)
// retail: this in EDI; managed port = NDAssetImage instance
bool NDAssetImage_FlipHorizontal(NDAssetImage self)
{
    if (self.CreateState == 0) return false; // +0x04

    var tmp = new NDAssetImage(); // retail operator_new(0x1b8) + vtbl + init
    if (tmp == null) return false;
    CloneSetup(tmp, self); // FUN_00432260(self,0,0,1)

    short bpp = self.Bpp;           // +0x16
    int width = self.WidthPx;       // +0x0c
    int height = self.Height;       // +0x10
    int pitch = self.RawPitch;      // +0x30
    int last = ((bpp == 24) ? 3 : 1) * (width - 1);
    byte* src = self.RawPixels + last; // +0x34
    byte* dst = tmp.RawPixels;

    if (bpp == 8) {
        for (int y = 0; y < height; y++) {
            for (int i = 0; i <= last; i++) dst[i] = *(src - i);
            src += pitch; dst += pitch;
        }
    } else if (bpp == 24) {
        // reverse RGB triplets per row (count (last+3)/3)
        // ... exact loop as decompile ...
    } else {
        // FUN_00433530 / FUN_004337d0 per pixel
    }

    PostHorizontalWorkingBuffer(tmp); // FUN_00433390
    MoveImageState(self, tmp);        // FUN_00432580 — install into self; zero tmp
    Destroy(tmp);                     // vtbl scalar delete(1)
    return true;
}
```

**Port traps:**

- Do not reuse FlipVertical’s `+0x1b0`/`+0x0c`-as-pitch layout alone — this unit’s primary reverse uses **`+0x34` / `+0x30` / width `+0x0c`**.
- Do not skip temp destroy.
- LoadTGA already gates bit4; server ports that load TGA must mirror both origin bits.

---

## 5. Verdict

**accept-with-gaps** — adversarial checks leave CF/ABI/horizontal role sealed; dual-buffer product residual and unowned helpers only.
