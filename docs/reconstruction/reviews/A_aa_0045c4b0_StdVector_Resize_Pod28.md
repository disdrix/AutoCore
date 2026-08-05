# Review A (reconstruction fidelity): `aa_0045c4b0` StdVector_Resize_Pod28

| Field | Value |
|---|---|
| **Stable ID** | `aa_0045c4b0` |
| **VA** | `0x0045c4b0`–`0x0045c552` exclusive (**162 B**) |
| **Canonical name** | `StdVector_Resize_Pod28` |
| **Ghidra name** | `FUN_0045c4b0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W35-M) |
| **Counterpart** | `reviews/B_aa_0045c4b0_StdVector_Resize_Pod28.md` |
| **System** | MSVC `vector` resize, POD elem **0x1c** |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` (full body) + callee decompile of `FUN_0045cce0` (context). **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

`vector<T>::resize(new_size, value)` for trivially copyable T size **0x1c**: grow by InsertN at end; shrink by erase `[new_end, end)`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W35-M append) | `docs/reconstruction/raw/aa_0045c4b0_FUN_0045c4b0.md` |
| Annotated | `docs/reconstruction/raw/aa_0045c4b0_FUN_0045c4b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_Resize_Pod28.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0045c4b0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0045c4b0_StdVector_Resize_Pod28.md` |
| Grow callee | `StdVector_InsertN_Pod28` @ `0x0045cd30` (W34-P sealed) |
| Live | full hex 162 B; epilogue `C2 1C 00` ×2; magic `0x92492493` |

---

## 3. Signature (sealed)

```c
// EBX=vec*, ECX=new_size, stack Pod28 by value; RET 0x1C
void StdVector_Resize_Pod28(
    StdVectorPod28* vec,
    uint32_t new_size,
    Pod28 value);
```

| Formal | Source | Conf |
|---|---|---|
| vec* | EBX (`8B 7B 04` begin load) | **High** |
| new_size | ECX (`3B C1` vs size) | **High** |
| value blob 0x1c | stack; `LEA ESI,[ESP+0xC]` + `RET 1C` | **High** |
| begin/end @ +4/+8 | triad | **High** |
| stride 0x1c | magic `0x92492493` + `*0x1c` lea | **High** |

---

## 4. Control flow

| Stage | Match | Conf |
|---|---|---|
| size via ÷0x1c magic | bytes | **High** |
| Grow → InsertN (count=new−size, where=end) | bytes call site + W34-P ABI | **High** |
| Shrink → erase [new_end, end) | bytes + `FUN_0045cce0` decompile | **High** |
| Equal / empty no-op | CF | **High** |
| RET 0x1C both paths | `C2 1C 00` | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (162 B) — raw W35-M append.

Entry: `56 57 8B 7B 04`.  
Grow epilogue: `5F 5E C2 1C 00`.  
Shrink epilogue: `5D 5F 5E C2 1C 00`.  
Pad `CC`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | **worker** |
| Callers | `FUN_00459750` only (direct) |
| Callees | `FUN_0045cd30`, `FUN_0045cce0` |

---

## 7. Gaps

1. Product/MSVC demangle + exact T (anm-track residual only).  
2. Shrink helper `FUN_0045cce0` and parent `FUN_00459750` not dual-owned.  
3. Runtime / bit-exact / differential.

---

## 8. Verdict rationale

Resize ABI, size math, grow InsertN wiring, and shrink erase sealed by full-body bytes + callee context. Gaps are product English and unowned neighbors → **accept-with-gaps**.
