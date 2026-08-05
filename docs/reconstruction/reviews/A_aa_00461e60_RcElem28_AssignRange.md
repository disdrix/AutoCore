# Review A (reconstruction fidelity): `aa_00461e60` RcElem28_AssignRange

| Field | Value |
|---|---|
| **Stable ID** | `aa_00461e60` |
| **VA** | `0x00461e60`–`0x00461eea` exclusive (**138 B**) |
| **Canonical name** | `RcElem28_AssignRange` |
| **Ghidra name** | `FUN_00461e60` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W37-Y) |
| **Counterpart** | `reviews/B_aa_00461e60_RcElem28_AssignRange.md` |
| **System** | RcElem28 forward assign-range stride **0x1c** |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` (no disasm) + `read_memory` (full body) + callers/xrefs + `get_assembly_context` @ `0x0046173e`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Assign live slots from `[src_first, src_last)` onto `[dest, …)` with AddRef/Release on shared resource `@+0x10`. Erase-range tail mover.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W37-Y append) | `docs/reconstruction/raw/aa_00461e60_FUN_00461e60.md` |
| Annotated | `docs/reconstruction/raw/aa_00461e60_FUN_00461e60.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/RcElem28_AssignRange.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00461e60.cpp` |
| Function record | `docs/reconstruction/functions/aa_00461e60_RcElem28_AssignRange.md` |
| Parent | `StdVector_EraseRange_RcElem28` @ call `0x0046173e` |

---

## 3. Signature (sealed)

```c
// EAX=dest*, stack src_first*, src_last*; plain RET; returns final dest*
RcElem28* RcElem28_AssignRange(
    RcElem28* dest,
    RcElem28* src_first,
    RcElem28* src_last);
```

| Formal | Source | Conf |
|---|---|---|
| dest* | **EAX** → ESI | **High** |
| src_first* | stack0 → EBP | **High** |
| src_last* | stack1 | **High** |
| return | final dest* in EAX | **High** |
| RET | plain `C3` (parent `ADD ESP,0xC`) | **High** |

---

## 4. Control flow

| Stage | Match | Conf |
|---|---|---|
| Empty range early-out | decompile + bytes | **High** |
| 4× dword + RC@+0x10 + 3× byte + dword | decompile + bytes | **High** |
| AddRef then Release then store | decompile + bytes | **High** |
| Stride `+0x1c` | `83 C5/C6/C7 1C` | **High** |
| Return advanced dest | `8B C6` before epilogue | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (138 B) — raw W37-Y append.

Entry: `55 8B 6C 24 08 3B 6C 24 0C 56 8B F0`.  
Epilogue: `5F 5B 8B C6 5E 5D C3`.  
Pad `CC`×6 then `00461ef0` (`RcElem28_AssignBackward`).

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | leaf |
| Callers | `FUN_00461720` ×1 @ `0x0046173e` |
| Callees | vtbl+4 / vtbl+8 only |

---

## 7. Gaps

1. Product/PDB class English (gfx residual only).  
2. AddRef-when-becomes-1 gate residual (shared family).  
3. Parent third stack push unread by leaf (document-only).  
4. Runtime / bit-exact / differential.

---

## 8. Verdict rationale

Register/stack ABI, forward assign CF, RC lanes, body size, sole erase parent sealed. Gaps product + runtime → **accept-with-gaps**.
