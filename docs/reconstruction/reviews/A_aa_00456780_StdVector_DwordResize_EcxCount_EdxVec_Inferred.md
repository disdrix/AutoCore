# Review A (reconstruction fidelity): `aa_00456780` StdVector_DwordResize_EcxCount_EdxVec_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00456780` |
| **VA** | `0x00456780`–`0x004567f5` exclusive (**117 B** / `0x75`) |
| **Canonical name** | `StdVector_DwordResize_EcxCount_EdxVec_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_00456780` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W38-H) |
| **Counterpart** | `reviews/B_aa_00456780_StdVector_DwordResize_EcxCount_EdxVec_Inferred.md` |
| **System** | STL dword vector resize (ECX-count / EDX-vec ABI) |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (117 B full) + `analyze_function_complete` + callers/xrefs + call-site context + grow/shrink callee decompile. **No** `disassemble_bytes`. |
| **Verdict** | **accept** |

---

## 1. Purpose

MSVC-style **`vector<uint32_t>::resize(n, value)`**:

1. `size = begin? (end−begin)>>2 : 0` with begin `@+4`, end `@+8`.
2. **Grow** when `size < n`: `FUN_00456960` InsertN with count `n−size` and `&fill`.
3. **Shrink** when `begin && n < size`: `FUN_00456660(vec, begin+n*4, end)`.
4. Equal / empty: no-op.

**ABI:** **EDX=`vec*`**, **ECX=`newCount`**, stack **fill**, **`RET 4`**.

Not `FUN_0044a380` (ECX=vec / EAX=n) and not `FUN_004367f0` (stack n / `RET 8`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W38-H append) | `docs/reconstruction/raw/aa_00456780_FUN_00456780.md` |
| Annotated | `docs/reconstruction/raw/aa_00456780_FUN_00456780.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_DwordResize_EcxCount_EdxVec_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00456780.cpp` |
| Function record | `docs/reconstruction/functions/aa_00456780_FUN_00456780.md` |
| Named record | `docs/reconstruction/functions/aa_00456780_StdVector_DwordResize_EcxCount_EdxVec_Inferred.md` |
| Live | decompile CF skeleton; full 117 B hex; 3× `C2 04 00` |
| Grow callee | `FUN_00456960` decompile — capacity `@+0xC`, InsertN + fill |
| Shrink callee | `FUN_00456660` decompile — memmove-publish end |
| Call sites | Pool `0x009860ba/ce`; clear `0x004665d6`; physics `0x00765b74` |

**Not performed:** Launcher, runtime, ledgers.

---

## 3. Signature (sealed)

```c
// EDX=vec*; ECX=newCount; stack fill; RET 4
void StdVector_DwordResize_EcxCount_EdxVec_Inferred(
    void* vec /*EDX*/,
    uint32_t newCount /*ECX*/,
    uint32_t fill /*stack*/);
```

| Slot | Source | Conf |
|---|---|---|
| vec | **EDX** (`MOV EAX,[EDX+4]`) | **High** |
| newCount | **ECX** (`CMP ESI,ECX`) | **High** |
| fill | stack; grow `LEA EAX,[ESP+0xC]` | **High** |
| cleanup | **RET 4** (`C2 04 00` ×3) | **High** |
| stride | `SAR 2` / `LEA [reg+reg*4]` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
size = begin ? (end-begin)>>2 : 0
if size < n: InsertN(end, n-size, &fill); RET 4
if begin && n < size: erase [begin+n, end); RET 4
RET 4
```

Decompiler grow shows `FUN_00456960(end)` only — **bytes supply count + fill**. Equal path and null-begin early-outs sealed.

---

## 5. Gaps

- Product/PDB STL mangled English.  
- Unowned grow/shrink callee duals.  
- Runtime / bit-exact.

**Verdict:** **accept**
