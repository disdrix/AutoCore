# Review A (reconstruction fidelity): `aa_0044a380` StdVector_DwordResize_EaxCount_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0044a380` |
| **VA** | `0x0044a380`–`0x0044a3e9` exclusive (**105 B** / `0x69`) |
| **Canonical name** | `StdVector_DwordResize_EaxCount_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_0044a380` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W37-Z) |
| **Counterpart** | `reviews/B_aa_0044a380_StdVector_DwordResize_EaxCount_Inferred.md` |
| **System** | STL dword vector resize (EAX-count ABI) |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (105 B full) + `analyze_function_complete` + callers/xrefs + call-site context + grow/shrink callee decompile. **No** `disassemble_bytes`. |
| **Verdict** | **accept** |

---

## 1. Purpose

MSVC-style **`vector<uint32_t>::resize(n, value)`**:

1. `size = begin? (end−begin)>>2 : 0` with begin `@+4`, end `@+8`.
2. **Grow** when `size < n`: `FUN_00463e30(this, end, n−size, &fill)` InsertN.
3. **Shrink** when `begin && n < size`: `FUN_00469f10(begin+n*4, end)` with **EBX=this**.
4. Equal / empty: no-op.

**ABI:** **ECX=vec\***, **EAX=newCount**, stack **fill**, **`RET 4`**.

Not the stack-count twin `FUN_004367f0` (`RET 8`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W37-Z append) | `docs/reconstruction/raw/aa_0044a380_FUN_0044a380.md` |
| Annotated | `docs/reconstruction/raw/aa_0044a380_FUN_0044a380.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_DwordResize_EaxCount_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0044a380.cpp` |
| Function record | `docs/reconstruction/functions/aa_0044a380_FUN_0044a380.md` |
| Named record | `docs/reconstruction/functions/aa_0044a380_StdVector_DwordResize_EaxCount_Inferred.md` |
| Live | decompile CF ≡ scaffold; full 105 B hex; 2× `C2 04 00` |
| Grow callee | `FUN_00463e30` decompile — capacity `@+0xC`, InsertN |
| Shrink callee | `FUN_00469f10` decompile — EBX=vec, memmove-publish end |
| Twin context | `A_aa_004367f0_StdVector_DwordResize` (stack/`RET 8`) |
| NestedHash use | W36-B insert rehash @ `0x0046bfe3` |

**Not performed:** Launcher, runtime, ledgers.

---

## 3. Signature (sealed)

```c
// ECX=vec*; EAX=newCount; stack fill; RET 4
void StdVector_DwordResize_EaxCount_Inferred(
    void* vec /*ECX*/,
    uint32_t newCount /*EAX*/,
    uint32_t fill /*stack*/);
```

| Slot | Source | Conf |
|---|---|---|
| vec | **ECX** (`MOV EAX,[ECX+4]`) | **High** |
| newCount | **EAX** (`MOV ESI,EAX` prologue) | **High** |
| fill | stack; grow `&stack` into InsertN | **High** |
| cleanup | **RET 4** (`C2 04 00` ×2) | **High** |
| stride | `SAR 2` / `LEA [reg+reg*4]` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
size = begin ? (end-begin)>>2 : 0
if size < n: InsertN(end, n-size, &fill); RET 4
if begin && n < size: erase [begin+n, end); RET 4
RET 4
```

| Stage | Match | Conf |
|---|---|---|
| Size from begin/end >>2 | **Yes** | **High** |
| Grow InsertN | **Yes** | **High** |
| Shrink erase | **Yes** | **High** |
| RET 4 both exits | **Yes** | **High** |
| Body 105 B | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Prologue / epilogue anchors:

```text
0x0044a380: 56 8B F0          ; PUSH ESI; MOV ESI,EAX  (n)
            8B 41 04          ; MOV EAX,[ECX+4]       (begin)
            …
            E8 … 5F 5E C2 04 00  ; grow → RET 4
            …
            E8 … 5B 5F 5E C2 04 00  ; shrink → RET 4
```

Full 105 B hex in raw W37-Z append.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | 12 functions + 1 raw (NestedHash insert, hash-map rehash family) |
| Callees | `FUN_00463e30`, `FUN_00469f10` |

---

## 7. Gaps

1. Product STL mangled English.  
2. Unowned grow/shrink callees not dual-owned this wave.  
3. Runtime / bit-exact / differential — open.

---

## 8. Verdict

ABI (ECX/EAX/fill/RET4), dword resize CF, and NestedHash rehash call form sealed. Residual product/callee detail does not block. → **accept**.
