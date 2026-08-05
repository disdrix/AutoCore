# Review A (reconstruction fidelity): `aa_00972e50` GfxNode_ComposeWorldMatrix_ClearDirty

| Field | Value |
|---|---|
| **Stable ID** | `aa_00972e50` |
| **VA** | `0x00972e50` |
| **Canonical name** | `GfxNode_ComposeWorldMatrix_ClearDirty` (structural; product/PDB open) |
| **Ghidra name** | `FUN_00972e50` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00972e50_GfxNode_ComposeWorldMatrix_ClearDirty.md` |
| **System** | graphics / scene graph (transform dirty bit) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Rebuild** a gfx/scene node’s composed transform via `FUN_0076f970`, then **clear dirty bit 0** on `this+0xBC`.

```
__fastcall / thiscall: ECX = node*
returns node* (EAX = ESI = this)
```

Body (bytes ≡ decompile intent):

1. Stack-allocate `vec4 local = (0, 0, 0, 1)` (`xorps` + `g_flOne`).
2. Push node component pointers:
   - `this + 0x90`
   - `this + 0x80`
   - `this + 0x9C`
   - `&local`
   - `this` (node)
3. `ECX = 0x00D1A6C0` (global composer / math service object).
4. `CALL FUN_0076f970` (`add esp, 0x14` → five stack dwords).
5. `AND dword [this+0xBC], 0xFFFFFFFE` — clear bit 0.
6. `return this`.

`FUN_0076f970` composes TRS-style matrices (identity base @ `DAT_00afdf70`, quat→matrix helpers, scale, translation) into the destination stream used by the node — **this VA is the dirty-rebuild entry**, not the full TRS math.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean / function record | `aa_00972e50_*` under raw/functions/reconstructed-exact |
| Fresh decompile | Ghidra @ `0x00972e50` |
| Bytes | `read_memory` full body through `AND [ESI+0xBC],0xFE` / `MOV EAX,ESI` |
| Callee | `FUN_0076f970` (matrix compose; large) |
| Callers | 49 xrefs — terrain chunker, gfx submit, many `FUN_0099*` / `FUN_007*` |
| Dirty gate caller | `FUN_00972fa0`: `if (*(byte*)(node+0xBC) & 1) FUN_00972e50();` then `FUN_0076f6e0` |

### Node offsets used

| Offset | Use in this VA |
|---|---|
| `+0x80` | Passed to composer (scale / axis block — callee-owned) |
| `+0x90` | Passed to composer |
| `+0x9C` | Passed to composer (quat path in `76f970`) |
| `+0xBC` | Flags; **bit 0 = dirty** cleared here |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `thiscall` ECX=node; returns this | **Confirmed** | `MOV ESI,ECX` … `MOV EAX,ESI` |
| Clears flag bit 0 at `+0xBC` | **Confirmed** | `AND …, 0xFFFFFFFE` |
| Composer global ECX `0x00D1A6C0` | **Confirmed** | `MOV ECX,0x00D1A6C0` before call |
| Five stack args to `76f970` | **Confirmed** | `ADD ESP,0x14` |
| Local `(0,0,0,1)` seed | **Confirmed** | xorps + `g_flOne` |
| Dirty bit semantics (bit0) | **High** | `00972fa0` tests bit 0 before call |
| Exact field English at +0x80/+0x90/+0x9C | **Tentative** | inferred TRS from callee structure |
| Product class name | **Open** | structural `GfxNode_*` |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| ECX node capture | Yes |
| Identity-ish local vec4 | Yes |
| Call `76f970` with component ptrs | Yes |
| Clear dirty bit 0 | Yes |
| Return this | Yes |

### Recovered CF

```c
// GfxNode* __fastcall GfxNode_ComposeWorldMatrix_ClearDirty(GfxNode* self)
float local[4] = {0, 0, 0, 1.f};
// thiscall on global @ 0x00D1A6C0:
FUN_0076f970(global, self, local, self+0x9C, self+0x80, self+0x90); // formals best-effort
self->flags &= ~1u;   // +0xBC
return self;
```

*(Exact `76f970` formal order is callee dual territory; stack push order sealed: `+0x90`, `+0x80`, `+0x9C`, `&local`, `self`.)*

---

## 5. Callers (sample of 49)

| Caller | Role |
|---|---|
| `CVOGTerrainChunker_SubmitForRendering` | Terrain submit |
| `FUN_00972fa0` / `FUN_00972ec0` / `FUN_00972f10` | Dirty-gated transform helpers |
| `FUN_0099d780` / `FUN_0099d9c0` / `FUN_0099dbf0` / `FUN_0099de60` / `FUN_0099e8a0` | Batch gfx |
| `FUN_00731d70` / `FUN_0075c340` / `FUN_0075c500` | Render path |
| `FUN_00424bd0` / `FUN_00439a80` / `FUN_004c0db0` | Engine/gfx |

---

## 6. Gaps

1. Product/PDB name for node type and API.
2. Full `FUN_0076f970` dual (compose order, dest matrix offset on node).
3. Precise English labels for +0x80 / +0x90 / +0x9C fields.
4. Runtime dirty-bit observation.

**Verdict:** entry CF + dirty clear + call shape sealed. **accept-with-gaps.**
