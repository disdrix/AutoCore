# Review A (reconstruction fidelity): `aa_0053b760` CNDHash_scalar_dtor_009cfa64

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053b760` |
| **VA** | `0x0053b760` |
| **Body** | `0x0053b760`–`0x0053b77d` (**`ret 4`**, 30 B + pad) |
| **Canonical name** | `CNDHash_scalar_dtor_009cfa64` (Ghidra `FUN_0053b760`; **Inferred**) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_0053b760_CNDHash_scalar_dtor_009cfa64.md` |
| **System** | container / CNDHash object family `PTR_FUN_009cfa64` (char hash `+0x534`) |
| **Live tools** | Ghidra `batch_decompile` + `read_memory` (no `disassemble_bytes`) |
| **Verdict** | **accept** |

---

## 1. Purpose

**Scalar deleting destructor** — **vtbl[0]** of **`PTR_FUN_009cfa64`**:

1. Body dtor **`FUN_0053b780`** → FreeBuckets **owning** `00539090` + freelist slabs.
2. If `flags & 1` → `operator_delete(this)`.
3. Return `this`; **`ret 4`**.

Important: body chain is **value-owning** FreeBuckets (unlike `009cfa4c`/`009cfa58` non-owning reclaim families).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Fresh decompile | `batch_decompile` @ `0x0053b760` ≡ raw |
| Machine | `read_memory` @ `0x0053b760` length 32 |
| Vtbl dword0 | `read_memory` @ `0x009cfa64` → `0x0053b760` |
| Body dtor dual | `A_aa_0053b780_CNDHash_Dtor_009cfa64.md` |
| FreeBuckets dual | `A_aa_00539090_CNDHash_FreeBuckets_Owning_009cfa64.md` |
| Xrefs | DATA from `0x009cfa64` |
| Raw / clean / function | `raw/aa_0053b760_*`, `reconstructed-exact/FUN_0053b760.cpp`, `functions/aa_0053b760_*` |

---

## 3. Authoritative body

```c
void * __thiscall CNDHash_scalar_dtor_009cfa64(void *this, byte flags)
{
  FUN_0053b780();  // owning FreeBuckets 00539090 + freelist slabs
  if ((flags & 1) != 0) operator_delete(this);
  return this;
}
```

---

## 4. Machine seal (`read_memory` @ `0x0053b760`)

Hex:  
`56 8b f1 e8 18 00 00 00 f6 44 24 08 01 74 09 56 e8 ad e0 f4 ff 83 c4 04 8b c6 5e c2 04 00`

| Claim | Evidence | Conf |
|---|---|---|
| Call body `0x0053b780` | `e8 18 00 00 00` | **High** |
| `flags&1` + `ret 4` | standard scalar pattern | **High** |
| Vtbl[0] = this | `009cfa64` dword0 | **High** |
| Owning teardown via body | dtor → FreeBuckets `00539090` | **High** |

---

## 5. Gaps / open

1. Product mangled name.
2. Runtime not run.

**Verdict:** **accept**
