# Review A (reconstruction fidelity): `aa_00433280` NDAssetImage_WriteAlphaPlaneByte

| Field | Value |
|---|---|
| **Stable ID** | `aa_00433280` |
| **VA** | `0x00433280` |
| **Body** | `0x00433280`–`0x004332ac` |
| **Canonical name** | `NDAssetImage_WriteAlphaPlaneByte` |
| **Prior scaffold** | `FUN_00433280` |
| **Review date** | `2026-07-29` (W23-A dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00433280_NDAssetImage_WriteAlphaPlaneByte.md` |
| **System** | `gfx-asset` / `NDAssetImage` / alpha plane |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` (+ function meta, assembly context on xrefs). No `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Leaf **alpha-plane store**: given image object, row, column, and a byte value, write `alpha_plane[row * width + col] = value` if the plane is allocated and coordinates are in range; otherwise return without writing.

Consumed by TGA 32bpp uncompressed row decode and PNG decode when an alpha plane is present.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00433280_FUN_00433280.md` (+ residual) |
| Annotated | `docs/reconstruction/raw/aa_00433280_FUN_00433280.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NDAssetImage_WriteAlphaPlaneByte.cpp` |
| Alias clean | `docs/reconstruction/reconstructed-exact/FUN_00433280.cpp` |
| Function record | `docs/reconstruction/functions/aa_00433280_NDAssetImage_WriteAlphaPlaneByte.md` |
| Live decompile | Ghidra `decompile_function` `0x00433280` |
| Live bytes | `read_memory` length 80 |
| Meta | `get_function_by_address` body `00433280`–`004332ac` |
| Xrefs / callers | `analyze_function_complete` → `FUN_00434dd0`, `FUN_00435410` |
| Call-site regs | `get_assembly_context` @ `0x00434efb`, `0x00435a10` |
| Sibling read | decompile + bytes `0x004332b0` |

**Not performed:** Launcher, runtime, parent ledgers.

---

## 3. Sealed residuals

### 3.1 ABI — **SEALED**

| Fact | Evidence |
|---|---|
| `this` in **EAX** | Entry `MOV ECX,[EAX+0x1b0]`; call sites `MOV EAX,image` |
| Row in **ESI** | `TEST ESI,ESI` / `CMP ESI,[EAX+0x10]`; callers load ESI=row before CALL |
| Col in **EDX** | `TEST EDX,EDX` / `CMP EDX,width`; PNG `ADD EDX,1` after call |
| Alpha on stack | `MOV CL,[ESP+4]` |
| Epilogue | **`RET 4`** (`C2 04 00`) |
| Return | void (no intentional EAX result) |

Decompiler `__fastcall` + `in_EAX`/`unaff_ESI` is a **presentation residual** — machine formals sealed above.

### 3.2 Algorithm — **SEALED**

```
plane = *(image + 0x1b0)
if !plane: return
if row < 0 or row >= *(image+0x10): return
if col < 0 or col >= *(image+0x0c): return
*(plane + row * width + col) = alpha
```

- Index uses **`IMUL`** width×row then add plane and col (row-major).
- Miss paths are **silent no-ops** (no assert, no log).

### 3.3 Layout — **SEALED** (fields touched)

| Off | Role |
|---|---|
| `+0x0c` | width (int32) |
| `+0x10` | height (int32) |
| `+0x1b0` | alpha plane `uint8_t*` |

Sibling **read** `0x004332b0` uses the same three fields (returns byte / 0).

### 3.4 Name — **structural accept**

`NDAssetImage_WriteAlphaPlaneByte` — family sealed by `NDAssetImage_LoadTGA` / TGA row duals; plane role proven by alpha write call sites. No product string/RTTI on this VA.

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Null plane early-out | Yes |
| Row signed range vs height | Yes |
| Col signed range vs width | Yes |
| `plane[row*width+col]=alpha` | Yes |
| `RET 4` | Yes |
| No invented callees | Yes |

---

## 5. Gaps / open

1. Allocator / lifetime of `+0x1b0` plane buffer.  
2. Full `NDAssetImage` size and other channel fields.  
3. Product English method name.  
4. Runtime / differential verification.  
5. Sibling read dual (`0x004332b0`) not owned this wave.

**Verdict:** **accept**
