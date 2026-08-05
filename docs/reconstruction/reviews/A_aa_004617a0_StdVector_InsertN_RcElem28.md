# Review A (reconstruction fidelity): `aa_004617a0` StdVector_InsertN_RcElem28

| Field | Value |
|---|---|
| **Stable ID** | `aa_004617a0` |
| **VA** | `0x004617a0`–`0x00461abb` exclusive (**795 B**) |
| **Canonical name** | `StdVector_InsertN_RcElem28` |
| **Ghidra name** | `FUN_004617a0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W34-P) |
| **Counterpart** | `reviews/B_aa_004617a0_StdVector_InsertN_RcElem28.md` |
| **System** | MSVC `vector` refcounted-elem insert-n stride **0x1c** |
| **Evidence pass** | Live Ghidra `batch_decompile` / `decompile_function` + `analyze_function_complete` (no disasm) + `read_memory` (full body) + callers. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Insert `count` copies of a **non-trivial** 0x1c element (shared resource `@+0x10`) at `where`, with AddRef/Release-correct grow and in-place paths.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W34-P append) | `docs/reconstruction/raw/aa_004617a0_FUN_004617a0.md` |
| Annotated | `docs/reconstruction/raw/aa_004617a0_FUN_004617a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_InsertN_RcElem28.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_004617a0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004617a0_StdVector_InsertN_RcElem28.md` |
| Callers | `FUN_004611e0`, `FUN_004612d0` |
| Helpers | `FUN_00461ac0` copy-ctor; `FUN_004620b0` uninit-copy; `FUN_00461c90` fill-n |

---

## 3. Signature (sealed)

```c
// ECX=value*, stack (vec*, where, count); RET 0xC; void
void StdVector_InsertN_RcElem28(
    const RcElem28* value,
    StdVectorRc28* vec,
    RcElem28* where,
    uint32_t count);
```

| Formal | Source | Conf |
|---|---|---|
| value* | ECX → ESI (`8B F1`) + `FUN_00461ac0` | **High** |
| vec / where / count | stack; `RET 0xC` | **High** |
| resource @+0x10 | copy helpers AddRef/Release | **High** |
| stride 0x1c / max / 1.5× | same family as Pod28 | **High** |

---

## 4. Control flow

| Stage | Match | Conf |
|---|---|---|
| Local copy-ctor + EH state 0 | decompile + bytes | **High** |
| count==0 → Release local | decompile | **High** |
| overflow throw | decompile | **High** |
| Grow: new + uninit-copy + fill + destroy old | decompile | **High** |
| In-place hole / mid | decompile | **High** |
| Local Release + RET 0xC | `C2 0C 00` + vtbl+8 | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (795 B) — raw W34-P append.

Entry: `55 8B EC 6A FF 68 D8 E5 9B 00`.  
Epilogue: `5B 8B E5 5D C2 0C 00`.  
Pad `CC`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | `FUN_004611e0` (resize grow); `FUN_004612d0` (insert-one) |
| Callees | copy-ctor; throw; size; new/delete; uninit-copy; fill-n; destroy; assign fwd/back |

---

## 7. Gaps

1. Product class English (gfxDevice scaffold residual only).  
2. Nested helpers not dual-owned.  
3. Exact AddRef semantics when refcount transitions 0→1 (vtbl+4) residual.  
4. Runtime / bit-exact / differential.

---

## 8. Verdict rationale

Hybrid ABI, refcount lifetime, grow/in-place trichotomy sealed. Gaps product + nested → **accept-with-gaps**.
