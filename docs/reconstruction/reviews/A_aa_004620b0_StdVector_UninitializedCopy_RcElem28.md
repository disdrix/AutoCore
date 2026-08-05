# Review A (reconstruction fidelity): `aa_004620b0` StdVector_UninitializedCopy_RcElem28

| Field | Value |
|---|---|
| **Stable ID** | `aa_004620b0` |
| **VA** | `0x004620b0`–`0x00462194` exclusive (**228 B**) |
| **Canonical name** | `StdVector_UninitializedCopy_RcElem28` |
| **Ghidra name** | `FUN_004620b0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W35-N) |
| **Counterpart** | `reviews/B_aa_004620b0_StdVector_UninitializedCopy_RcElem28.md` |
| **System** | MSVC `uninitialized_copy` for refcounted elem **0x1c** |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (full body) + `get_function_by_address` + xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Uninitialized-copy `[src_begin, src_end)` into `dest`, constructing each **RcElem28** with AddRef on shared `@+0x10`; return advanced dest. Used by parent insert-n grow/in-place relocate.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W35-N append) | `docs/reconstruction/raw/aa_004620b0_FUN_004620b0.md` |
| Annotated | `docs/reconstruction/raw/aa_004620b0_FUN_004620b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_UninitializedCopy_RcElem28.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_004620b0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004620b0_StdVector_UninitializedCopy_RcElem28.md` |
| Callers | four sites in `FUN_004617a0` |
| Element leaf | `FUN_00461ac0` / `RcElem28_CopyCtor_EsiEdi` (same field map) |

---

## 3. Signature (sealed)

```c
// ECX=src_begin, stack (src_end, dest); EAX=dest_end; plain RET
RcElem28* StdVector_UninitializedCopy_RcElem28(
    RcElem28* src_begin,
    RcElem28* src_end,
    RcElem28* dest);
```

| Formal | Source | Conf |
|---|---|---|
| src_begin | ECX → EDI (`8B F9`) | **High** |
| src_end | `[ebp+8]` | **High** |
| dest | `[ebp+0xC]` → ESI | **High** |
| return dest_end | EAX (`8B C6`) | **High** |
| RET plain | `C3` (not `C2 08 00`) | **High** — **bytes win** over Ghidra `__thiscall` |
| stride 0x1c | `83 C6 1C` / `83 C7 1C` / `+7` dwords | **High** |

---

## 4. Control flow

| Stage | Match | Conf |
|---|---|---|
| SEH frame `LAB_009be5a1` | entry bytes | **High** |
| Loop until src==end | decompile ≡ bytes | **High** |
| Per-elem construct + AddRef | same as copy-ctor leaf | **High** |
| Dest null → skip write, still advance | decompile | **High** |
| Happy epilogue restore SEH + RET | bytes | **High** |
| EH Release unwind | bytes residual; decompiler omits | **Medium** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (228 B) — raw W35-N append.

Entry: `55 8B EC 6A FF 68 A1 E5 9B 00 …`  
Epilogue: `5B 8B E5 5D C3`  
Pad `CC` from `0x00462194`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | 4× `StdVector_InsertN_RcElem28` only |
| Callees | vtbl+4; EH vtbl+8 |

---

## 7. Gaps

1. Product T English.  
2. Full EH unwind bit-exact (present in bytes; not re-owned as separate VA).  
3. Dest-null advance semantics product intent residual.  
4. Runtime / bit-exact.

---

## 8. Verdict rationale

Range uninit-copy CF, stride, AddRef, hybrid ABI sealed. Product + EH polish open → **accept-with-gaps**.
