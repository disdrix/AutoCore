# Review A (reconstruction fidelity): `aa_00461b80` RcElem28_AssignFillRange

| Field | Value |
|---|---|
| **Stable ID** | `aa_00461b80` |
| **VA** | `0x00461b80`–`0x00461bfd` exclusive (**125 B**) |
| **Canonical name** | `RcElem28_AssignFillRange` |
| **Ghidra name** | `FUN_00461b80` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W35-P) |
| **Counterpart** | `reviews/B_aa_00461b80_RcElem28_AssignFillRange.md` |
| **System** | RcElem28 range fill-by-assign stride **0x1c** |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` (no disasm) + `read_memory` (full body) + callers/xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Fill live slots `[dest_first, dest_last)` by assigning one source element with AddRef/Release on shared resource `@+0x10`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W35-P append) | `docs/reconstruction/raw/aa_00461b80_FUN_00461b80.md` |
| Annotated | `docs/reconstruction/raw/aa_00461b80_FUN_00461b80.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/RcElem28_AssignFillRange.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00461b80.cpp` |
| Function record | `docs/reconstruction/functions/aa_00461b80_RcElem28_AssignFillRange.md` |
| Parent | `StdVector_InsertN_RcElem28` @ hole `0x00461a2a` + mid `0x00461a89` |

---

## 3. Signature (sealed)

```c
// EAX=dest_first*, EDI=value*, stack dest_last*; plain RET; void
void RcElem28_AssignFillRange(
    RcElem28* dest_first,
    const RcElem28* value,
    RcElem28* dest_last);
```

| Formal | Source | Conf |
|---|---|---|
| dest_first* | **EAX** → ESI (`8B F0`) | **High** |
| value* | **EDI** live-in (fixed) | **High** |
| dest_last* | stack → EBP | **High** |
| RET | plain `C3` | **High** |

---

## 4. Control flow

| Stage | Match | Conf |
|---|---|---|
| Empty range early-out | decompile + bytes | **High** |
| 4× dword + 3× byte + dword lanes | decompile + bytes | **High** |
| AddRef then Release then store @+0x10 | decompile + bytes | **High** |
| Stride `+0x1c` | `83 C6 1C` | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (125 B) — raw W35-P append.

Entry: `55 8B 6C 24 08 56 8B F0`.  
Epilogue: `5B 5E 5D C3`.  
Pad `CC`×3 then `00461c00`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | leaf |
| Callers | `FUN_004617a0` ×2 |
| Callees | vtbl+4 / vtbl+8 only |

---

## 7. Gaps

1. Product/PDB class English (gfx residual only).  
2. Exact AddRef gate (refcount becomes 1 → vtbl+4) vs classic COM residual.  
3. Runtime / bit-exact / differential.

---

## 8. Verdict rationale

Register ABI, fill-assign CF, RC lanes, body size sealed. Gaps product + runtime → **accept-with-gaps**.
