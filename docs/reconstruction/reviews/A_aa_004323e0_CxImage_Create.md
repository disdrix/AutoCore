# Review A (reconstruction fidelity): `aa_004323e0` CxImage_Create

| Field | Value |
|---|---|
| **Stable ID** | `aa_004323e0` |
| **VA** | `0x004323e0`–`0x0043255f` |
| **Canonical name** | `CxImage_Create` |
| **Prior scaffold** | `FUN_004323e0` / auto `CxImage_Create.cpp` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction fidelity — OWN-ONLY W22-Q |
| **Counterpart** | `reviews/B_aa_004323e0_CxImage_Create.md` |
| **System** | graphics / CxImage |
| **Verdict** | **accept-with-gaps** — ABI, bpp quantize, MAX_MEMORY, stride, alloc, header install sealed; nested destroy/palette helpers open |

**Tools:** Ghidra `decompile_function` + `read_memory` (body). No `disassemble_bytes`. Own VA only. No ledgers. No Launcher.

---

## 1. Purpose

Create a CxImage raster buffer:

1. Gate via `FUN_004321b0`.
2. Reject zero width/height; copy plate error into `this+0x44`.
3. Quantize `bpp` → effective bit depth `{1,4,8,24}`.
4. Reject oversized images (`(w*h*bits)>>8 > 256000000`).
5. Fill BITMAPINFOHEADER-ish fields; set palette count.
6. `malloc(imageBytes + 0x28 + palette*4)`; zero palette; optional `FUN_004331d0`.
7. Copy 10 dwords header into block; set bits pointer `this+0x34`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004323e0_FUN_004323e0.md` (+ W22-Q live seal append) |
| Annotated | `docs/reconstruction/raw/aa_004323e0_FUN_004323e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CxImage_Create.cpp` |
| Function record | `docs/reconstruction/functions/aa_004323e0_CxImage_Create.md` |
| Live decompile | Ghidra `decompile_function` `0x004323e0` — **≡** raw |
| Live bytes | `read_memory` `0x004323e0` + `0x004324e0` (multiple `C2 0C 00`) |
| Callers | TGA / BMP / PNG / WBMP loaders (Ghidra callers list) |
| Naming | `NAMING_REGISTRY.md` → `CxImage_Create` |

---

## 3. Sealed residuals

### 3.1 ABI — **SEALED**

| Fact | Evidence |
|---|---|
| `this` | **EBX** (`mov esi,ebx` prologue; stores via `ebx+off`) |
| height | **EAX** on entry (`mov edi,eax`) |
| stack | width, bpp, type — **3 args** |
| Epilogue | **`RET 12`** (`C2 0C 00`) × all exits |
| Return | block pointer or **NULL** |

```c
int32_t* CxImage_Create(
    /* EBX */ CxImage* self,
    /* EAX */ int32_t height,
    /* stack */ int32_t width,
    /* stack */ uint32_t bpp,
    /* stack */ uint32_t type);
```

### 3.2 bpp → bits — **SEALED**

| bpp | bits |
|---|---|
| `< 2` | 1 |
| `< 5` | 4 |
| `≤ 8` | 8 |
| `> 8` | 24 (`8 + 0x10`) |

### 3.3 MAX_MEMORY — **SEALED**

```
if (((uint)(width * height * bits) >> 8) > 256000000) {
  // lastError = "CXIMAGE_MAX_MEMORY exceeded" (7 dwords)
  return NULL;
}
```

Byte proof: `3D 00 40 42 0F` → `cmp eax, 0x0F424000` (256000000); `jbe` continue.

### 3.4 Stride / sizes — **SEALED**

```
stride = ((width * bits + 31) >> 5) * 4   // this+0x30
imageBytes = stride * height              // this+0x1c
alloc = imageBytes + 0x28 + paletteCount*4
```

### 3.5 Palette count — **SEALED**

| bits | `this+0x28` |
|---|---|
| 1 | 2 |
| 4 | 0x10 |
| 8 | 0x100 |
| 24 | 0 |

### 3.6 Header install — **SEALED**

- Fields: biSize=0x28, width, height, planes=1, bitCount, compression=0, sizeImage, type@+0x40.
- Copy 10 dwords `this+8 → block`.
- `this+0x34 = block + *block + paletteCount*4`.

### 3.7 Three-rep — **SEALED**

live decompile ≡ raw body ≡ annotated CF ≡ clean plate control flow.

---

## 4. Gaps (owned)

| Gap | Severity | Notes |
|---|---|---|
| `FUN_004321b0` body | Medium | Precheck / prior destroy — not owned |
| `FUN_00433490` exact palette base | Low | Called then zero-fill; pointer identity open |
| `FUN_004331d0` / `+0x1b0` | Low | Optional path |
| lastError buffer exact size | Low | Copy counts sealed (7/9+u16/15+u8) |
| Runtime differential | Open | Not run |

---

## 5. Confidence summary

| Area | Confidence |
|---|---|
| Name `CxImage_Create` | **High** |
| ABI + ret 12 | **High** |
| Quantize / MAX_MEMORY / stride / alloc | **High** |
| Offsets +0x04..+0x44 | **High** |
| Nested helpers | **Tentative** |
| Runtime | **Open** |

**Verdict: accept-with-gaps**
