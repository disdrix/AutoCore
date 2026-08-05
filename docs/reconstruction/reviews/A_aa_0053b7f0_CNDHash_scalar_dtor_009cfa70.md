# Review A (reconstruction fidelity): `aa_0053b7f0` CNDHash_scalar_dtor_009cfa70

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053b7f0` |
| **VA** | `0x0053b7f0` |
| **Body** | `0x0053b7f0`–`0x0053b80d` (**`ret 4`**, 30 B + pad) |
| **Canonical name** | `CNDHash_scalar_dtor_009cfa70` (Ghidra `FUN_0053b7f0`; **Inferred**) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_0053b7f0_CNDHash_scalar_dtor_009cfa70.md` |
| **System** | container / CNDHash object family `PTR_FUN_009cfa70` (char `+0x6f0`) |
| **Live tools** | Ghidra `batch_decompile` + `read_memory` (no `disassemble_bytes`) |
| **Verdict** | **accept** |

---

## 1. Purpose

**Scalar deleting destructor** — **vtbl[0]** of **`PTR_FUN_009cfa70`**:

1. Body dtor **`FUN_0053b810`** → FreeBuckets **non-owning** `0053b880` + freelist slabs.
2. If `flags & 1` → `operator_delete(this)`.
3. Return `this`; **`ret 4`**.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Fresh decompile | `batch_decompile` @ `0x0053b7f0` ≡ raw |
| Machine | `read_memory` @ `0x0053b7f0` length 32 |
| Vtbl dword0 | `read_memory` @ `0x009cfa70` → `0x0053b7f0` |
| Body dtor dual | `A_aa_0053b810_CNDHash_Dtor_009cfa70.md` |
| FreeBuckets dual | `A_aa_0053b880_CNDHash_FreeBuckets_NonOwning_009cfa70.md` |
| Xrefs | DATA from `0x009cfa70` |
| Raw / clean / function | `raw/aa_0053b7f0_*`, `reconstructed-exact/FUN_0053b7f0.cpp`, `functions/aa_0053b7f0_*` |

---

## 3. Authoritative body

```c
void * __thiscall CNDHash_scalar_dtor_009cfa70(void *this, byte flags)
{
  FUN_0053b810();  // non-owning FreeBuckets 0053b880 + freelist slabs
  if ((flags & 1) != 0) operator_delete(this);
  return this;
}
```

---

## 4. Machine seal (`read_memory` @ `0x0053b7f0`)

Hex:  
`56 8b f1 e8 18 00 00 00 f6 44 24 08 01 74 09 56 e8 1d e0 f4 ff 83 c4 04 8b c6 5e c2 04 00`

| Claim | Evidence | Conf |
|---|---|---|
| Call body `0x0053b810` | `e8 18 00 00 00` | **High** |
| `flags&1` + `ret 4` | scalar pattern | **High** |
| Vtbl[0] = this | `009cfa70` dword0 | **High** |
| Non-owning body teardown | FreeBuckets → reclaim `0053b8c0` | **High** |

---

## 5. Gaps / open

1. Product mangled name.
2. External value ownership residual for this family.
3. Runtime not run.

**Verdict:** **accept**
