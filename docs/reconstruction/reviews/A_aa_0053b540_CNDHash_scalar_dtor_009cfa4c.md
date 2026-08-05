# Review A (reconstruction fidelity): `aa_0053b540` CNDHash_scalar_dtor_009cfa4c

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053b540` |
| **VA** | `0x0053b540` |
| **Body** | `0x0053b540`–`0x0053b55d` (**`ret 4`**, 30 B + pad) |
| **Canonical name** | `CNDHash_scalar_dtor_009cfa4c` (Ghidra `FUN_0053b540`; MSVC scalar-deleting dtor **Inferred**) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_0053b540_CNDHash_scalar_dtor_009cfa4c.md` |
| **System** | container / CNDHash object family `PTR_FUN_009cfa4c` |
| **Live tools** | Ghidra `batch_decompile` + `read_memory` (no `disassemble_bytes`) |
| **Verdict** | **accept** — classic MSVC scalar-deleting dtor sealed High |

---

## 1. Purpose

**Scalar deleting destructor** — **vtbl[0]** of object vtbl **`PTR_FUN_009cfa4c`**:

1. Call body dtor **`FUN_0053b560`** (`CNDHash_Dtor_009cfa4c`: vtbl re-stamp, lock log, FreeBuckets non-owning path, freelist-slab teardown).
2. If **`flags & 1`**: `operator_delete(this)`.
3. Return `this`.

`__thiscall` + one stack flag byte; epilogue **`ret 4`**.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Fresh decompile | `batch_decompile` @ `0x0053b540` ≡ raw |
| Machine | `read_memory` @ `0x0053b540` length 32 |
| Vtbl dword0 | `read_memory` @ `0x009cfa4c` → `0x0053b540` |
| Body dtor dual | `A_aa_0053b560_CNDHash_Dtor_009cfa4c.md` |
| Xrefs | DATA only from `0x009cfa4c` |
| Raw / clean / function | `raw/aa_0053b540_*`, `reconstructed-exact/FUN_0053b540.cpp`, `functions/aa_0053b540_*` |

---

## 3. Authoritative body

```c
void * __thiscall CNDHash_scalar_dtor_009cfa4c(void *this, byte flags)
{
  FUN_0053b560();           // body dtor; this in ECX
  if ((flags & 1) != 0) {
    operator_delete(this);
  }
  return this;
}
// ret 4
```

---

## 4. Machine seal (`read_memory` @ `0x0053b540`)

Hex:  
`56 8b f1 e8 18 00 00 00 f6 44 24 08 01 74 09 56 e8 cd e2 f4 ff 83 c4 04 8b c6 5e c2 04 00`

| Claim | Evidence | Conf |
|---|---|---|
| ECX → ESI | `56 8b f1` | **High** |
| Call body dtor `0x0053b560` | `e8 18 00 00 00` (from `0x0053b548` → `0x0053b560`) | **High** |
| `test flags&1` | `f6 44 24 08 01` | **High** |
| Conditional `operator_delete` | push esi; call; `add esp,4` | **High** |
| Return this; **`ret 4`** | `8b c6 5e c2 04 00` | **High** |
| Vtbl slot 0 | `009cfa4c` dword0 = this VA | **High** |

---

## 5. Lifecycle context

| Step | VA | Role |
|---|---|---|
| Ctor | `0x0053b0b0` | object family `009cfa4c` |
| Body dtor | `0x0053b560` | FreeBuckets non-owning + freelist slabs |
| **Scalar dtor** | **`0x0053b540`** | body + optional heap free |
| RemoveAll twin | `0x0053b130` | vtbl sibling |

---

## 6. Gaps / open

1. Product mangled `scalar deleting destructor` name / RTTI.
2. Full call-site inventory of `delete hash` vs `~CNDHash()` only (`flags&1` polarity).
3. Runtime not run.

**Verdict:** **accept**
