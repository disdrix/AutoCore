# Review A (reconstruction fidelity): `aa_0043b800` Gfx_DepthStencilFormat_ToBpp_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043b800` |
| **VA** | `0x0043b800`–`0x0043b831` exclusive (**49 B** / `0x31`) |
| **Canonical name** | `Gfx_DepthStencilFormat_ToBpp_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_0043b800` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W38-U) |
| **Counterpart** | `reviews/B_aa_0043b800_Gfx_DepthStencilFormat_ToBpp_Inferred.md` |
| **System** | graphics / D3D depth-stencil format → bpp |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (body + JT/IDX tables) + `analyze_function_complete` + 9 xrefs + `get_assembly_context` + twin `FUN_0040ead0` + callers `0075eff0` / `0096bb20` / `0075ebd0` / `00735410`. **No** `disassemble_bytes`. |
| **Verdict** | **accept** |

---

## 1. Purpose

Leaf **depth/stencil format → bits-per-pixel** mapper for D3D9 depth formats in enum band `0x47`–`0x50`. Callers size depth surfaces as `(bpp * width * height) >> 3` or test non-zero bpp for Clear/Z paths.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W38-U append) | `docs/reconstruction/raw/aa_0043b800_FUN_0043b800.md` |
| Annotated | `docs/reconstruction/raw/aa_0043b800_FUN_0043b800.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Gfx_DepthStencilFormat_ToBpp_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043b800.cpp` |
| Function record | `docs/reconstruction/functions/aa_0043b800_FUN_0043b800.md` |
| Named record | `docs/reconstruction/functions/aa_0043b800_Gfx_DepthStencilFormat_ToBpp_Inferred.md` |
| Live | decompile switch ≡ JT; full 49 B hex; IDX/JT tables |
| Twin | `FUN_0040ead0` color/texture bpp (different enum set) |
| Callers | Reset mem-acct, surface size, Clear, adapter score |

**Not performed:** Launcher, runtime, ledgers.

---

## 3. Signature (sealed)

```c
// EAX format in; EAX bpp out; plain RET
uint32_t Gfx_DepthStencilFormat_ToBpp_Inferred(uint32_t format /*EAX*/);
```

| Slot | Source | Conf |
|---|---|---|
| format | **EAX** (`ADD EAX,-0x47` first) | **High** |
| return bpp | **EAX** (`MOV EAX,imm` / `XOR EAX,EAX`) | **High** |
| cleanup | plain **`RET`** (`C3` ×5 exits) | **High** |
| stack/ECX | unused | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
if (format - 0x47) > 9: return 0
idx = IDX[format - 0x47]
jmp JT[idx]
  → return 32 / 15 / 24 / 16 / 0
```

| format | bpp | D3DFMT |
|---|---|---|
| 0x47 | 32 | D32 |
| 0x49 | 15 | D15S1 |
| 0x4B / 0x4D / 0x4F | 24 | D24S8 / D24X8 / D24X4S4 |
| 0x50 | 16 | D16 |
| else / holes | 0 | — |

---

## 5. Cross-check vs callers

Surface size (`FUN_0096bb20`):

```text
MOV EAX, [ESI+0x28]   ; format
CALL 0x0043b800
SHR EAX, 3
IMUL EAX, [ESI+0x20]  ; H
IMUL EAX, [ESI+0x1c]  ; W
```

GfxDevice_Reset mem-acct subtract/add at `DAT_00d1f614+0x3b0` uses identical formula (depth plane), while color plane uses twin `FUN_0040ead0` into `+0x3ac`.

Clear helper (`FUN_0075ebd0`): non-zero bpp sets flag bit 2; separate stencil-bit table on same format enum (0x49→1, 0x4B→8, 0x4F→4) confirms depth-stencil domain.

---

## 6. Name

`Gfx_DepthStencilFormat_ToBpp_Inferred` — structural + exact D3D9 depth enum hex match. Scaffold `Named_CalleeOf_Named_gfxDevice_*` rejected.

---

## 7. Gaps (non-blocking)

- Product/PDB demangle.
- Runtime / bit-exact.

**Verdict:** **accept**
