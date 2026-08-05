# Review A (reconstruction fidelity): `aa_0074ce60` phyBoundingBox_Unserialize

| Field | Value |
|---|---|
| **Stable ID** | `aa_0074ce60` |
| **VA** | `0x0074ce60`–`0x0074d0b4` exclusive (**596 B** / `0x254`) |
| **Canonical name** | `phyBoundingBox_Unserialize` |
| **Ghidra name** | `FUN_0074ce60` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W38-H) |
| **Counterpart** | `reviews/B_aa_0074ce60_phyBoundingBox_Unserialize.md` |
| **System** | palantir physics / sto-chunk |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (body + pad) + `analyze_function_complete` + callers/xrefs + call-site context + reader/f32/bool callee decompiles. **No** `disassemble_bytes`. |
| **Verdict** | **accept** |

---

## 1. Purpose

Unserialize a **phyBoundingBox** from a **stoChunkReader**:

1. SEH + `stoChunkReader_EnterChunkScope` (reader in **EBX**, object in **ECX** → **ESI**).
2. Require tag **`'BBOX'`** (`0x42424F58`); else log (`phyBoundingBox.cpp:0x7e`) and return −1.
3. **Version 1:** three `readF32Array(3)` into **`+0x14` / `+0x20` / `+0x00`** (stream order B→C→A; ADV 2026-08-04); read f32 `@+0x0C`; compute extent `@+0x10`; set bool `@+0x2C` from `(+0x0C)<=0`.
4. **Version 2:** read bool `@+0x2C` first; then same three arrays + f32 + extent (bool not re-derived).
5. Else log invalid version (`:0x9c`) and return −1.
6. Leave scope; return **0** if reader `+0x402c >= 0` else **−1**.

Binary (`reader+0x4044==0`) vs text selects f32/bool helpers.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W38-H append) | `docs/reconstruction/raw/aa_0074ce60_FUN_0074ce60.md` |
| Annotated | `docs/reconstruction/raw/aa_0074ce60_FUN_0074ce60.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/phyBoundingBox_Unserialize.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0074ce60.cpp` |
| Function record | `docs/reconstruction/functions/aa_0074ce60_FUN_0074ce60.md` |
| Named record | `docs/reconstruction/functions/aa_0074ce60_phyBoundingBox_Unserialize.md` |
| Live | decompile CF ≡ strings/tag/version; body end `ADD ESP,0x24; RET`; pad `CC` |
| Callees | EnterChunkScope, readF32Array, binary/text f32+bool, leave, vog_LogMessage |
| Call sites | gfxGeometryPiece `LEA ECX,[EBP+0x24]`; physics `MOV EBX,reader` + `LEA ECX,bbox` |

**Not performed:** Launcher, runtime, ledgers.

---

## 3. Signature (sealed)

```c
// ECX = phyBoundingBox*; EBX = stoChunkReader*; returns 0 / -1
int phyBoundingBox_Unserialize(void* bbox /*ECX*/);
```

| Slot | Source | Conf |
|---|---|---|
| bbox | **ECX** (`MOV ESI,ECX`) | **High** |
| reader | **EBX** (EnterChunkScope / callers set EBX) | **High** |
| tag | `CMP [scope],0x42424F58` | **High** |
| return | −1 error; `(status>=0)?0:-1` success path | **High** |
| extent | SSE/x87 `abs(sqrt(dx²+dz²))` → `[ESI+0x10]` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
EnterChunkScope
if tag != 'BBOX': log; leave; return -1
if version == 1: arrays; f32; extent; bool = (f32<=0)
else if version == 2: bool; arrays; f32; extent
else: log; leave; return -1
leave; return status_ok ? 0 : -1
```

Decompiler elides some `readF32Array` destinations — **LEA ECX** sites seal stream order **`+0x14` / `+0x20` / `+0x00`** (not A→B→C field order).

---

## 5. Gaps

- Product English for float3 roles (min / max / center labels).  
- Full SEH cleanup path bit-exact.  
- Runtime / differential.

**Verdict:** **accept**
