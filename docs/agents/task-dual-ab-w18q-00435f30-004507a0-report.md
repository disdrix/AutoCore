# Dual A/B report — W18-Q OWN-ONLY (`0x00435f30`, `0x004507a0`)

**Date:** 2026-07-29  
**Agent:** W18-Q  
**Scope:** OWN VAs only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory`. No `disassemble_bytes`.  
**Program:** `autoassault.exe` base `0x400000`.

---

## Verdicts

| Unit | VA | Canonical | Verdict |
|------|-----|-----------|---------|
| `aa_00435f30` | `0x00435f30` | `stoChunkStream_ReadBytes_Inferred` | **accept-with-gaps** — bulk byte read + refill/direct-IO sealed |
| `aa_004507a0` | `0x004507a0` | `StdVector_Dword_InsertN_Inferred` | **accept-with-gaps** — dword insert-N + growth sealed |

---

## `0x00435f30` — stoChunkStream_ReadBytes_Inferred

### Sealed facts

1. **`__thiscall`**, stack `dest*`, `byteCount`, **`RET 8`**.  
2. Returns **`0`** success or **`0xFFFFFFFF`** on refill failure.  
3. Stream shell: cursor `+4`, base `+8`, avail `+0xC`, maxChunk `+0x10`, window `+0x18`.  
4. Three paths: in-buffer copy; refill via `FUN_00435df0` when `n ≤ maxChunk`; direct **vtbl+4 / vtbl+0x14** when oversized.  
5. Decompiler `unaff_EBX` on direct path is residual — bytes pass **advanced dest**.  
6. **8 xrefs**; bulk consumer includes sealed `stoChunkReader_readF32Array` with `this = reader+0x14`.

### Gaps

- Product stream/vtbl English names.  
- Full `FUN_00435df0` semantics (not owned).  
- Runtime / bit-exact.

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00435f30_stoChunkStream_ReadBytes_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00435f30_stoChunkStream_ReadBytes_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_00435f30_FUN_00435f30.md` |
| Clean | `docs/reconstruction/reconstructed-exact/stoChunkStream_ReadBytes_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00435f30.cpp` |
| Raw | `docs/reconstruction/raw/aa_00435f30_FUN_00435f30.md` |
| Annotated | `docs/reconstruction/raw/aa_00435f30_FUN_00435f30.annotated.md` |

---

## `0x004507a0` — StdVector_Dword_InsertN_Inferred

### Sealed facts

1. **`__thiscall`**, stack `insertPos`, `count`, `fillSrc*`, **`RET 0xC`**.  
2. Vector shell: begin `+4`, end `+8`, capEnd `+0xC`; **dword** elems (`>>2`, `new(cap*4)`).  
3. Fill is **one dword** from `*fillSrc`.  
4. Max size **`0x3FFFFFFF`**; overflow → `FUN_004540b0`.  
5. Growth **`cap + (cap>>1)`** then clamp to `size+count`; realloc rebinds all three pointers.  
6. In-capacity hybrid and pure backward-move arms via `FUN_004e2e80` / `FUN_004e2f70` / `FUN_004e24d0` / `FUN_005739b0`.  
7. **22 xrefs**; grow callee of `StdVector_DwordResize` (`0x004367f0`).

### Gaps

- Product STL mangled name.  
- Relation to sibling insert-N `FUN_004073a0`.  
- Runtime / bit-exact.

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_004507a0_StdVector_Dword_InsertN_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_004507a0_StdVector_Dword_InsertN_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_004507a0_FUN_004507a0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_Dword_InsertN_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_004507a0.cpp` |
| Raw | `docs/reconstruction/raw/aa_004507a0_FUN_004507a0.md` |
| Annotated | `docs/reconstruction/raw/aa_004507a0_FUN_004507a0.annotated.md` |

---

## AutoCore impact

- **stoChunk bulk reads:** ports must honor the stream subobject at `reader+0x14` (not the full reader), maxChunk direct-IO split, and `-1` refill failure — do not assume always-buffered copies.  
- **Dword vector grow:** resize and push_back slow paths share this insert-N; keep stride 4 and `0x3FFFFFFF` cap; do not merge with 0x38 floater or map-node families.

---

## Compliance

| Rule | Status |
|------|--------|
| OWN VAs only (`00435f30`, `004507a0`) | Yes |
| Dual A + B per VA | Yes |
| raw + annotated + reconstructed-exact + function record | Yes |
| `decompile_function` + `read_memory` only | Yes |
| No `disassemble_bytes` | Yes |
| No Launcher | Yes |
| No parent ledger edits | Yes |
