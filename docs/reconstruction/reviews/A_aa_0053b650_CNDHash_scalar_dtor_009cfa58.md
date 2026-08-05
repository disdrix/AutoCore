# Review A (reconstruction fidelity): `aa_0053b650` CNDHash_scalar_dtor_009cfa58

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053b650` |
| **VA** | `0x0053b650` |
| **Body** | `0x0053b650`–`0x0053b66d` (**`ret 4`**, 30 B + pad) |
| **Canonical name** | `CNDHash_scalar_dtor_009cfa58` (Ghidra `FUN_0053b650`; **Inferred**) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_0053b650_CNDHash_scalar_dtor_009cfa58.md` |
| **System** | container / CNDHash object family `PTR_FUN_009cfa58` |
| **Live tools** | Ghidra `batch_decompile` + `read_memory` (no `disassemble_bytes`) |
| **Verdict** | **accept** |

---

## 1. Purpose

**Scalar deleting destructor** — **vtbl[0]** of **`PTR_FUN_009cfa58`**:

1. Body dtor **`FUN_0053b670`** (`CNDHash_Dtor_009cfa58`).
2. If `flags & 1` → `operator_delete(this)`.
3. Return `this`; **`ret 4`**.

Byte twin of `0053b540` with different near-call targets.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Fresh decompile | `batch_decompile` @ `0x0053b650` ≡ raw |
| Machine | `read_memory` @ `0x0053b650` length 32 |
| Vtbl dword0 | `read_memory` @ `0x009cfa58` → `0x0053b650` |
| Body dtor dual | `A_aa_0053b670_CNDHash_Dtor_009cfa58.md` |
| Xrefs | DATA from `0x009cfa58` |
| Raw / clean / function | `raw/aa_0053b650_*`, `reconstructed-exact/FUN_0053b650.cpp`, `functions/aa_0053b650_*` |

---

## 3. Authoritative body

```c
void * __thiscall CNDHash_scalar_dtor_009cfa58(void *this, byte flags)
{
  FUN_0053b670();
  if ((flags & 1) != 0) operator_delete(this);
  return this;
}
```

---

## 4. Machine seal (`read_memory` @ `0x0053b650`)

Hex:  
`56 8b f1 e8 18 00 00 00 f6 44 24 08 01 74 09 56 e8 bd e1 f4 ff 83 c4 04 8b c6 5e c2 04 00`

| Claim | Evidence | Conf |
|---|---|---|
| Call body `0x0053b670` | `e8 18 00 00 00` → next function | **High** |
| `flags&1` + `ret 4` | same pattern as `0053b540` | **High** |
| Vtbl[0] = this | `009cfa58` dword0 | **High** |

---

## 5. Gaps / open

1. Product mangled name.
2. Runtime not run.

**Verdict:** **accept**
