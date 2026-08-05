# Review A (reconstruction fidelity): `aa_0098acc0` NDAssetImage_FlipHorizontal

| Field | Value |
|---|---|
| **Stable ID** | `aa_0098acc0` |
| **VA** | `0x0098acc0`–`0x0098ae77` |
| **Canonical name** | `NDAssetImage_FlipHorizontal` |
| **Prior scaffold** | `FUN_0098acc0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (pixel-buffer horizontal flip) |
| **Counterpart** | `reviews/B_aa_0098acc0_NDAssetImage_FlipHorizontal.md` |
| **System** | client assets / `NDAssetImage` (TGA normalize) |
| **Verdict** | **accept-with-gaps** — CF/ABI/bpp branches sealed; dual-buffer + helper product names residual |

**Tools:** Ghidra `decompile_function` + `read_memory` + `get_function_by_address` + callers/callees. **No** `disassemble_bytes`. **No** Launcher. Own VA only.

---

## 1. Purpose

**Horizontal flip** of an `NDAssetImage` so TGA **right-origin** (image-descriptor **bit4** = `0x10`) loads normalize to left→right pixel order.

```
NDAssetImage_FlipHorizontal(this in EDI) -> AL
  if this+4 == 0 or operator_new(0x1b8) fails: return 0
  build temp image; reverse-copy rows bpp-aware into temp+0x34
  FUN_00433390(); FUN_00432580(this); destroy temp; return 1
```

Sibling: `NDAssetImage_FlipVertical` `0x004332e0` (LoadTGA: bit5 **and** bpp==32).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | `decompile_function` `0x0098acc0` ≡ 2026-07-23 raw |
| Live bytes | `read_memory` 256 B entry + 256 B @ `0x0098adc0` (tail `MOV AL,1` / `RET`) |
| Meta | body `0098acc0`–`0098ae77` |
| Caller | `NDAssetImage_LoadTGA` `0x004347d0` (bit4 → this) |
| Sibling plate | `NDAssetImage_FlipVertical` dual (vertical only; EBX this) |
| Clean | `reconstructed-exact/NDAssetImage_FlipHorizontal.cpp` |
| Raw / annotated | `raw/aa_0098acc0_NDAssetImage_FlipHorizontal{,.annotated}.md` |
| Function record | `functions/aa_0098acc0_NDAssetImage_FlipHorizontal.md` |

---

## 3. Sealed residuals

### 3.1 ABI — **SEALED / Confirmed**

| Fact | Evidence |
|---|---|
| `this` | All gates/fields via **EDI** (`CMP [EDI+4]`, `[EDI+0x16]`, …) |
| Args | No stack formals; frame `SUB ESP,0x10` locals only |
| Epilogue | `ADD ESP,0x10` / plain **`C3` RET** — **not** `RET n` |
| Return | Fail: `XOR AL,AL`; success: `MOV AL,1` |
| Body | `0x0098acc0`–`0x0098ae77` |

```c
uint8_t NDAssetImage_FlipHorizontal(/* NDAssetImage* this in EDI */);
```

### 3.2 Control flow — **SEALED**

Live decompile **≡** 2026-07-23 raw (no CF delta).

```
gate this+4
tmp = operator_new(0x1b8); fail → 0
tmp.vtbl = PTR_FUN_00a9bcac
FUN_004320d0(); FUN_00432260(this,0,0,1)
bpp = *(short*)(this+0x16)
lastPxOff = ((bpp==0x18)*2 + 1) * (width - 1)
src = *(this+0x34) + lastPxOff; dst = tmp+0x34
if bpp==8:   row loop reverse bytes
elif bpp==24: row loop reverse RGB triplets (count (last+3)/3)
else:        nested y,x → FUN_00433530 / FUN_004337d0(y)
FUN_00433390()          // ESI=tmp
FUN_00432580(this)      // EBX=tmp → move into original
tmp->vtbl[0](1)         // scalar delete
return 1
```

### 3.3 bpp math — **Confirmed**

| bpp | lastPxOff factor | Loop |
|---:|---|---|
| 8 | `1 * (width-1)` | byte reverse |
| 0x18 (24) | `3 * (width-1)` | 3-byte triplet reverse |
| other | same formula with factor 1 if not 24 | per-pixel helpers |

### 3.4 Caller gate — **High**

`NDAssetImage_LoadTGA`: `local_17 = (descriptor & 0x10) != 0` → call this; independent of FlipVertical path.

---

## 4. Gaps

1. Product names for `FUN_004320d0` / `FUN_00432260` / `FUN_00433390` / `FUN_00432580` / pixel helpers (not OWN).
2. Full dual-buffer model (`+0x34` vs `+0x1b0`) product documentation.
3. Runtime TGA bit4 golden.
4. PDB / RTTI product symbol string for this method (none in image strings).

---

## 5. Verdict

**accept-with-gaps** — ABI, CF, bpp branches, caller role sealed High; helper duals and dual-buffer product model residual.
