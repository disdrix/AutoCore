# Review A (reconstruction fidelity): `aa_0045cd30` StdVector_InsertN_Pod28

| Field | Value |
|---|---|
| **Stable ID** | `aa_0045cd30` |
| **VA** | `0x0045cd30`–`0x0045d01c` exclusive (**748 B**) |
| **Canonical name** | `StdVector_InsertN_Pod28` |
| **Ghidra name** | `FUN_0045cd30` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W34-P) |
| **Counterpart** | `reviews/B_aa_0045cd30_StdVector_InsertN_Pod28.md` |
| **System** | MSVC `vector` POD insert-n stride **0x1c** |
| **Evidence pass** | Live Ghidra `batch_decompile` / `decompile_function` + `analyze_function_complete` (no disasm) + `read_memory` (full body) + callers. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Insert `count` copies of a trivially copyable **0x1c** element at iterator `where`, with 1.5× reallocation or in-place shift.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W34-P append) | `docs/reconstruction/raw/aa_0045cd30_FUN_0045cd30.md` |
| Annotated | `docs/reconstruction/raw/aa_0045cd30_FUN_0045cd30.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_InsertN_Pod28.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0045cd30.cpp` |
| Function record | `docs/reconstruction/functions/aa_0045cd30_StdVector_InsertN_Pod28.md` |
| Caller | `FUN_0045c4b0` @ `0x0045c506` |
| Live | full hex 748 B; epilogue `C2 08 00`; SSE prologue sealed |

---

## 3. Signature (sealed)

```c
// ECX=count, EDX=vec*, stack where + value*; RET 8; void
void StdVector_InsertN_Pod28(
    uint32_t count,
    StdVectorPod28* vec,
    Pod28* where,
    const Pod28* value);
```

| Formal | Source | Conf |
|---|---|---|
| count | ECX (`8B F1`) | **High** |
| vec | EDX (`8B DA`) | **High** |
| where / value* | stack; `RET 8` | **High** |
| begin/end/cap @ +4/+8/+0xC | triad math | **High** |
| stride 0x1c | magic `0x92492493` + `*0x1c` | **High** |
| max `0x9249249` | `BA 49 92 24 09` | **High** |

---

## 4. Control flow

| Stage | Match | Conf |
|---|---|---|
| SSE local value (7×movss) | bytes only | **High** |
| count==0 early out | decompile + bytes | **High** |
| overflow → `FUN_004540b0` | decompile | **High** |
| Grow 1.5× + new + relocate + fill + delete | decompile + helpers | **High** |
| In-place hole/mid arms | decompile | **High** |
| RET 8 | `C2 08 00` | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (748 B) — raw W34-P append.

Entry: `55 8B EC 6A FF 68 F0 DD 9B 00`.  
Epilogue: `5B 8B E5 5D C2 08 00`.  
Pad `CC`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | `FUN_0045c4b0` only (direct) |
| Callees | throw; size; new/delete; trivial range copy/fill/assign |

---

## 7. Gaps

1. Product/MSVC demangle + exact T (anm-track key residual only).  
2. Nested helpers `FUN_0045f360` / `FUN_0045f150` / `FUN_0045efe0` / `FUN_0046a240` / caller `FUN_0045c4b0` not dual-owned.  
3. Runtime / bit-exact / differential.

---

## 8. Verdict rationale

ABI, stride, max, growth, and trichotomy sealed by bytes+decompile. Gaps are product English and nested duals only → **accept-with-gaps**.
