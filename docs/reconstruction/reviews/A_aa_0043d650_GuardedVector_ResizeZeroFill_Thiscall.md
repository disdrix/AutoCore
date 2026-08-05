# Review A (reconstruction fidelity): `aa_0043d650` GuardedVector_ResizeZeroFill_Thiscall

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043d650` |
| **VA** | `0x0043d650`–`0x0043d66b` (**28 B**) |
| **Canonical name** | `GuardedVector_ResizeZeroFill_Thiscall` (**Inferred**) |
| **Ghidra name** | `FUN_0043d650` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W34-M) |
| **Counterpart** | `reviews/B_aa_0043d650_GuardedVector_ResizeZeroFill_Thiscall.md` |
| **System** | STL / guarded ring-deque container |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (full 28 B) + `analyze_function_complete` + callers; sole callee W33-L Resize_Thiscall |
| **Verdict** | **accept** |

---

## 1. Purpose

Zero-fill thiscall resize wrapper:

1. Allocate stack fill dword = `0`.
2. Call `GuardedVector_Resize_Thiscall(ECX, new_size, fill=0)`.
3. Return (`RET 4` cleans `new_size`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0043d650_FUN_0043d650.md` (+ W34-M append) |
| Annotated | `docs/reconstruction/raw/aa_0043d650_FUN_0043d650.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_ResizeZeroFill_Thiscall.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043d650.cpp` |
| Function record | `docs/reconstruction/functions/aa_0043d650_FUN_0043d650.md` |
| Named record | `docs/reconstruction/functions/aa_0043d650_GuardedVector_ResizeZeroFill_Thiscall.md` |
| Live | decompile ≡ raw CF; full 28 B hex; epilogue `C2 04 00`; rel32 → `0043d940` |
| Context | W33-L Resize_Thiscall sole caller residual |

---

## 3. Signature (sealed)

```c
// ECX=container; stack new_size; RET 0x4
void GuardedVector_ResizeZeroFill_Thiscall(GuardedVectorHeader* container /*ECX*/,
                                           uint32_t new_size);
```

| Slot | Source | Conf |
|---|---|---|
| container | **ECX** preserved into callee | **High** |
| new_size | Stack[+4] (`MOV EAX,[ESP+0xC]` after two pushes) | **High** |
| fill | Local dword `0` only (not a formal) | **High** |
| cleanup | `RET 0x4` | **High** |

Decompiler omits ECX this — **bytes win**.

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
fill = 0
GuardedVector_Resize_Thiscall(ECX, new_size, fill)
RET 4
```

| Stage | Match | Conf |
|---|---|---|
| Linear wrapper CF | **Yes** | **High** |
| Call → `0043d940` | **Yes** (rel32) | **High** |
| fill=0 seed | **Yes** (`C7 00 00 00 00 00`) | **High** |
| RET 4 | **Yes** | **High** |

---

## 5. Verdict

Full body sealed; ABI + zero-fill contract confirmed against W33-L callee → **accept**.
