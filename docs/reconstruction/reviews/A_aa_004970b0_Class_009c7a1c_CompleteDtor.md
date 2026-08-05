# Review A (reconstruction fidelity): `aa_004970b0` Class_009c7a1c_CompleteDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_004970b0` |
| **VA** | `0x004970b0`–`0x004971e0` exclusive (**304 B** / `0x130`) |
| **Canonical name** | `Class_009c7a1c_CompleteDtor` |
| **Ghidra name** | `FUN_004970b0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W28-M) |
| **Counterpart** | `reviews/B_aa_004970b0_Class_009c7a1c_CompleteDtor.md` |
| **System** | class / complete-object destructor |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (full body). **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC **complete-object destructor** for vtbl family `PTR_FUN_009c7a1c`:

1. Install vtbl.
2. Cookie-vector destroy at `this+0x28` (elem size `0x28`, dtor `FUN_005b8000`, `operator_delete[]`).
3. Zero array ptr + fields `+4`/`+8`.
4. Free six begin/end/cap buffer triples.
5. `StdList_Destroy_FreeHead` on **`this+0x0C`** (byte LEA; decompiler incomplete).

Scalar deleting wrapper `FUN_004975e0` is **vtbl[0]** and is **not** this VA.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W28-M) | `docs/reconstruction/raw/aa_004970b0_FUN_004970b0.md` |
| Annotated | `docs/reconstruction/raw/aa_004970b0_FUN_004970b0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/Class_009c7a1c_CompleteDtor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004970b0.cpp` |
| Function records | `functions/aa_004970b0_FUN_004970b0.md`, `functions/aa_004970b0_Class_009c7a1c_CompleteDtor.md` |
| List peer | `StdList_Destroy_FreeHead` `aa_00497360` (W27-K accept) |
| Live | decompile; full 304 B hex; vtbl[0]=`0x004975e0`; sole caller scalar-deleting pattern |

---

## 3. Signature (sealed)

```c
// __thiscall; ECX=this; bare RET; void
void __thiscall Class_009c7a1c_CompleteDtor(void *self);
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX (`8B F1`) | **High** |
| return | void (EAX unused) | **High** |
| cleanup | bare `C3` after SEH restore | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes, with LEA seal)

```
SEH install (LAB_009a0d7e); state=6
*this = PTR_FUN_009c7a1c
if arr@+0x28:
  eh_vector_dtor_iter(arr, 0x28, count@arr-4, FUN_005b8000)
  operator_delete[](arr-4)
arr=0; +4=0; +8=0
for each of {0xBC,0xAC,0x9C,0x40,0x30,0x1C}:
  if begin: operator_delete(begin); begin=end=cap=0
lea ecx, [this+0x0C]; call StdList_Destroy_FreeHead
SEH restore; RET
```

| Stage | Match | Conf |
|---|---|---|
| Vtbl + vector cookie free | **Yes** | **High** |
| Six buffer frees | **Yes** | **High** |
| List @ +0x0C (not this) | **Yes** (bytes LEA) | **High** |
| operator_delete fall-through | **Yes** | **High** |
| Sole caller scalar-deleting | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

| Region | Note |
|---|---|
| Entry | `6A FF 68 7E 0D 9A 00` … `8B F1` … `C7 06 1C 7A 9C 00` |
| Vector | `6A 28` size; push `FUN_005b8000`; `eh_vector` + `delete[]` |
| List | `8D 4E 0C E8 91 01 00 00` → `call 0x00497360` |
| Epilogue | `83 C4 10 C3` |
| Size | **304 B** exclusive end `0x004971e0` |

**No `disassemble_bytes` used.**

---

## 6. Gaps

- Product / MSVC demangled class name.
- Semantic labels for the six buffers and `+4`/`+8` pair.
- Element type beyond stride/`FUN_005b8000`.
- Runtime / bit-exact / differential — open.

---

## 7. Verdict

CF, ABI, vtbl, vector free, six buffers, and list LEA sealed → **accept-with-gaps** (product English residual).
