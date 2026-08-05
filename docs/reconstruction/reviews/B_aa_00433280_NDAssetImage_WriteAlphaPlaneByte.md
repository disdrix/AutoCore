# Review B (skeptical / adversarial): `aa_00433280` NDAssetImage_WriteAlphaPlaneByte

| Field | Value |
|---|---|
| **Stable ID** | `aa_00433280` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00433280_NDAssetImage_WriteAlphaPlaneByte.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Pure `__thiscall` (ECX=this) | Bytes load `this` from **EAX** (`[EAX+0x1b0]`); sites set EAX not ECX | **Falsified** — **EAX-this** leaf |
| 2 | Only stack formals / standard cdecl | `RET 4` + ESI/EDX uses; stack only alpha | **Falsified** — hybrid reg + stdcall-1 |
| 3 | Decompiler `param_1` is width formal | `param_1` storage empty/phantom; width loaded mid-body from `+0xc` | **Falsified** — width is field load |
| 4 | Writes RGB or RGBA interleaved | Index is 1-byte plane; TGA already wrote RGB elsewhere | **Falsified** — **alpha plane only** |
| 5 | Asserts / throws on OOB | All fails are JE/JL/JGE early outs to RET | **Falsified** — silent no-op |
| 6 | Name must be product TGA-only | Also called from PNG path `FUN_00435410` | **Falsify exclusive TGA** — general image alpha store |
| 7 | `+0x1b0` could be pitch/stride table | Sibling read returns single byte at same index formula | **Supports** byte plane base |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EAX/ESI/EDX + RET 4 ABI | **High** | Wrong hooks trash regs / stack |
| width@+0xc height@+0x10 plane@+0x1b0 | **High** | Corrupt image memory |
| row-major `row*width+col` | **High** | Visual alpha shear |
| Silent OOB | **High** | Overstated exception ports |
| “Alpha” product semantics | **High for use-sites** / Medium absolute | Could be any mono plane; call sites pass A channel |
| Structural name NDAssetImage_* | **Medium-High** | Family naming from siblings, not RTTI here |

---

## 3. Cross-check against raw + bytes

```
raw decompile:
  if plane@+0x1b0 && row>=0 && row<h@+0x10 && col>=0 && col<w@+0xc:
    plane[w*row + col] = alpha

bytes @ 00433280 (read_memory):
  8B88B0010000 85C9 7420 85F6 7C1C 3B7010 7D17
  85D2 7C13 8B400C 3BD0 7D0C 0FAFC6 03C1
  8A4C2404 880C10 C20400 CC...

≡ same CF. Call sites MOV EAX/ESI, set EDX col, PUSH alpha, CALL.
Sibling 004332b0: same gates, MOV AL,[eax+edx] read / XOR AL,AL miss.
```

---

## 4. Surviving contract for AutoCore

```csharp
// Client NDAssetImage alpha plane store (leaf). Silent OOB.
void WriteAlphaPlaneByte(NdAssetImage img, int row, int col, byte alpha)
{
    var plane = img.AlphaPlane; // +0x1b0
    if (plane == null) return;
    if (row < 0 || row >= img.Height /*+0x10*/) return;
    if (col < 0 || col >= img.Width  /*+0x0c*/) return;
    plane[row * img.Width + col] = alpha;
}
```

- Server ports of TGA/PNG loading need a mono alpha buffer if 32bpp fidelity matters for map/UI assets.
- Do not model this as a locked or allocating API.

---

## 5. Open questions

1. When is `+0x1b0` allocated / freed?  
2. Is pitch ever ≠ width (bytes prove width used as stride)?  
3. Full image struct product name beyond NDAssetImage structural family.  
4. Runtime confirmation on live process.  
5. Dual of sibling read `0x004332b0`.

**Verdict:** **accept**
