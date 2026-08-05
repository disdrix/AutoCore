# Review A (reconstruction fidelity): `aa_00466df0` StdVector_Resize_Elem28_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00466df0` |
| **VA** | `0x00466df0`–`0x00466e92` exclusive (**162 B**) |
| **Canonical name** | `StdVector_Resize_Elem28_Inferred` |
| **Ghidra name** | `FUN_00466df0` |
| **Review date** | `2026-07-29` (W36-P dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W36-P) |
| **Counterpart** | `reviews/B_aa_00466df0_StdVector_Resize_Elem28_Inferred.md` |
| **System** | MSVC `vector` resize, POD elem **0x1c** |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` (full 162 B) + xrefs/caller context. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + read_memory only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

`vector<T>::resize(new_size, value)` for trivially copyable T size **0x1c**: grow by InsertN CountEcx at end; shrink by erase `[new_end, end)`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W36-P append) | `docs/reconstruction/raw/aa_00466df0_FUN_00466df0.md` |
| Annotated | `docs/reconstruction/raw/aa_00466df0_FUN_00466df0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_Resize_Elem28_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00466df0.cpp` |
| Function records | `functions/aa_00466df0_FUN_00466df0.md`, `functions/aa_00466df0_StdVector_Resize_Elem28_Inferred.md` |
| Grow callee | `StdVector_InsertN_Elem28_CountEcx_Inferred` @ `0x00466ea0` (W34-Q sealed) |
| Twin unit | `StdVector_Resize_Pod28` @ `0x0045c4b0` (W35-M) |
| Live | full hex 162 B; epilogue `C2 1C 00` ×2; magic `0x92492493` |

---

## 3. Signature (sealed — bytes win)

```c
// EBX=vec*, ECX=new_size, stack Elem28 by value; RET 0x1C
void StdVector_Resize_Elem28_Inferred(
    VectorElem28* vec,
    uint32_t new_size,
    Elem28 value);
```

| Slot | Source | Conf |
|---|---|---|
| vec* | EBX (`8B 7B 04` begin load) | **High** |
| new_size | ECX (`3B C1` vs size) | **High** |
| value blob 0x1c | stack; `LEA ESI,[ESP+0xC]` + `RET 1C` | **High** |
| begin/end @ +4/+8 | triad | **High** |
| stride 0x1c | magic `0x92492493` + `*0x1c` lea | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| size via ÷0x1c magic | bytes | **High** |
| Grow → InsertN CountEcx (count=new−size, where=end) | call site + W34-Q ABI | **High** |
| Shrink → erase [new_end, end) | bytes + `FUN_0045cce0` call formals | **High** |
| Equal / empty no-op | CF | **High** |
| RET 0x1C both paths | `C2 1C 00` | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (162 B) — raw W36-P append.

Entry: `56 57 8B 7B 04`.  
Grow epilogue: `5F 5E C2 1C 00`.  
Shrink epilogue: `5D 5F 5E C2 1C 00`.  
Pad `CC`.

Caller (`0x0096443d` in `FUN_00963fb0`): `LEA EBX,[ESP+0x3c]`; `MOV ECX,ESI`; `SUB ESP,0x1c` value space before call.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | **worker** |
| Callers | `FUN_00963fb0` only (direct) |
| Callees | `FUN_00466ea0`, `FUN_0045cce0` |

---

## 7. Gaps / open

1. Product/MSVC demangle + exact T (anmAnimMaster residual only).  
2. Shrink helper `FUN_0045cce0` and parent `FUN_00963fb0` not dual-owned.  
3. Runtime / bit-exact / differential.

---

## 8. Verdict rationale

Resize ABI, size math, grow InsertN wiring, and shrink erase sealed by full-body bytes + sealed grow callee. Gaps are product English and unowned neighbors → **accept-with-gaps**.
