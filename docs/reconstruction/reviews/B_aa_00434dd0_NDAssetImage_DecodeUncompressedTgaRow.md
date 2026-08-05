# Review B (skeptical / adversarial): `aa_00434dd0` NDAssetImage_DecodeUncompressedTgaRow

| Field | Value |
|---|---|
| **Stable ID** | `aa_00434dd0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W22-O) |
| **Counterpart** | `reviews/A_aa_00434dd0_NDAssetImage_DecodeUncompressedTgaRow.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is the RLE decoder | **Falsified** — no RLE packet headers; RLE is `FUN_00434b30` which **calls** this |
| 2 | Decompiler signature (2 reg + 3 stack / void) is complete | **Falsified** — **`ret 0x14`** and 32bpp use of `[ebp+14]/`[ebp+18]` |
| 3 | 16-bit path is RGB565 | **Falsified** — G mask `0xf8` after `>>2` is **5-bit mid** (RGB555-style), not 6-bit 565 |
| 4 | Decompiler R expand `(char)pix*8` is bit-exact | **Falsified** — bytes **`and ecx,0x1f`** then ×8 |
| 5 | Function allocates image buffers | **Falsified** — only stream reads + optional alpha store |
| 6 | 32bpp writes 4 bytes into dest | **Falsified** — dest advances by **3**; A goes to `FUN_00433280` |
| 7 | Clean invents D3D/texture upload | **Falsified** — stops at stream vtbl + sealed callee |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| bpp cases + bulk vs loop | **High** | Wrong TGA decode |
| Stack ABI / ret 0x14 | **High** | Call convention port break |
| RGB555 expand | **High** | Color shift on 15/16bpp assets |
| Alpha store callee identity | **High** | Missing A plane for 32bpp |
| Stream product type name | Medium | Naming only |
| Alpha plane vs packed A | Medium | Layout residual in callee |

---

## 3. Cross-check against raw + bytes

```
SEH → switch(header+0x10 bpp):
  8:  Read(dest, count, 1)
  15/16: loop Read(2); expand RGB555 → dest+=3
  24: Read(dest, count*3, 1)
  32: loop Read(4); dest RGB+=3; FUN_00433280(A, image, x0+i, y)
  default: fall through
→ SEH restore; ret 0x14
```

Clean must **not** invent RLE, colormap, flip, or CreateTexture.

Do **not** trust decompiler formals for stack arity or unmasked 16-bit R.

---

## 4. Surviving contract for AutoCore

```csharp
// Client asset path only; server may omit TGA decode
void DecodeUncompressedTgaRow(Stream s, byte[] destRgb, Image img,
    byte bpp, int count, int y, int x0)
{
    switch (bpp) {
    case 8:  s.Read(destRgb, count); break;
    case 15:
    case 16:
        for (int i = 0; i < count; i++) {
            ushort p = s.ReadU16();
            destRgb[i*3+0] = (byte)((p & 0x1f) << 3);
            destRgb[i*3+1] = (byte)((p >> 2) & 0xf8);
            destRgb[i*3+2] = (byte)((p >> 7) & 0xf8);
        }
        break;
    case 24: s.Read(destRgb, count * 3); break;
    case 32:
        for (int i = 0; i < count; i++) {
            var px = s.ReadBytes(4);
            destRgb[i*3+0]=px[0]; destRgb[i*3+1]=px[1]; destRgb[i*3+2]=px[2];
            StoreAlpha(img, x0 + i, y, px[3]); // FUN_00433280
        }
        break;
    }
}
```

---

## 5. Open questions

1. Exact product name of stream / whether Read returns bool vs size.
2. Whether AutoCore server needs TGA load (client terrain `map.tga` path is primary consumer).

**Verdict:** **accept**
