# Review B (skeptical / adversarial): `aa_004323e0` CxImage_Create

| Field | Value |
|---|---|
| **Stable ID** | `aa_004323e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004323e0_CxImage_Create.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory`. No `disassemble_bytes`. Own VA `0x004323e0` only.

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | `__thiscall` with `this` in **ECX** | Prologue uses **EBX** as base for all `this` stores; no ECX setup | **Falsified** as thiscall — **EBX this** |
| 2 | Height is a stack arg | Height from **EAX** (`mov edi,eax`); stack has width/bpp/type only; **ret 12** | **Falsified** — **EAX height** |
| 3 | Plain `ret` / cdecl | Epilogue `C2 0C 00` on every exit | **Falsified** — **`RET 12`** |
| 4 | bpp used raw as bit depth | Quantize ladder `<2→1`, `<5→4`, else 8/24 | **Falsified** as raw bpp |
| 5 | Memory limit is `width*height*bits` bytes | Gate is `(w*h*bits)>>8 > 256000000` | **Falsified** as raw byte count |
| 6 | Always 24-bit / truecolor | Palette path for 1/4/8; 24 has paletteCount 0 | **Falsified** |
| 7 | Returns bool / void | Returns `int*` block or null | **Falsified** as bool |
| 8 | Three-rep diverges from live | live ≡ raw strings/CF; clean matches | **Falsified** |
| 9 | `FUN_004321b0` is optional | Zero return → immediate null, no error string | **Survives** as hard gate |
| 10 | Product name invented | Strings contain `CxImage::Create` | **Falsified** as invented — **High** name |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EBX this, EAX height, 3 stack, ret 12 | **High** | Wrong call ABI → crash |
| bpp quantize + palette map | **High** | Wrong buffer size |
| MAX_MEMORY shift compare | **High** | Over/under reject |
| stride DWORD align formula | **High** | Row pitch bugs |
| bits ptr = block+biSize+pal*4 | **High** | Wrong pixel base |
| Nested helper semantics | **Out of scope** | Destroy/palette edge cases |
| Runtime / bit-exact | **Open** | Shipping load |

---

## 3. Cross-check against raw + bytes

```
raw / live decompile:
  FUN_004321b0 gate
  width (param_1) & height (EAX) nonzero
  bpp → bits {1,4,8,24}
  MAX_MEMORY (w*h*bits)>>8 > 256000000
  palette this+0x28; stride this+0x30; malloc; zero pal; copy 10 dwords; bits this+0x34

bytes (entry):
  55 8B6C240C 56 57 8BF3 8BF8 E8…   ; ebp=bpp, esi=ebx, edi=eax=height
  … 3D0040420F 7617 … C20C00          ; MAX_MEMORY path ret 12
  … C20C00                             ; success / other fails ret 12
```

**No conflict** on owned CF. Helper bodies not re-proven.

---

## 4. Surviving contract for AutoCore

```csharp
// CxImage_Create @ 0x004323e0
// retail: EBX=this, EAX=height, stack (width,bpp,type), RET 12

IntPtr Create(CxImage self, int height, int width, uint bpp, uint type)
{
    if (!PrecheckDestroy(self)) return IntPtr.Zero; // FUN_004321b0
    if (width == 0 || height == 0) { self.LastError = "…greater than zero"; return IntPtr.Zero; }

    int bits = bpp < 2 ? 1 : bpp < 5 ? 4 : (bpp > 8 ? 24 : 8);
    if (((long)width * height * bits >> 8) > 256_000_000) {
        self.LastError = "CXIMAGE_MAX_MEMORY exceeded";
        return IntPtr.Zero;
    }

    int pal = bits == 1 ? 2 : bits == 4 ? 16 : bits == 8 ? 256 : 0;
    int stride = ((width * bits + 31) >> 5) * 4;
    int imageBytes = stride * height;
    // fill header fields @ +0x08.. ; type @ +0x40
    var block = Marshal.AllocHGlobal(imageBytes + 0x28 + pal * 4); // retail: malloc
    if (block == IntPtr.Zero) { self.LastError = "…can't allocate memory"; return IntPtr.Zero; }
    // zero palette; copy 10 dwords; bits = block + biSize + pal*4
    return block;
}
```

---

## 5. Gaps that survive attack

1. **`FUN_004321b0`** — full destroy/create gate semantics.
2. **`FUN_00433490` / `FUN_004331d0`** — palette base + secondary buffer.
3. **Exact lastError buffer capacity** — copy lengths sealed; field width not fully sized.
4. **Runtime** — no live alloc differential.

None overturn sealed ABI / math / CF.

---

## 6. Verdict

**accept-with-gaps** — core create contract High; nested helpers Tentative/Open.
