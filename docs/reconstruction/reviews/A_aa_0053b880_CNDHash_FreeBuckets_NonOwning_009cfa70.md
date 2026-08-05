# Review A (reconstruction fidelity): `aa_0053b880` CNDHash_FreeBuckets_NonOwning_009cfa70

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053b880` |
| **VA** | `0x0053b880` |
| **Body** | `0x0053b880`–`0x0053b8b3` (**`ret`**, 52 B + pad) |
| **Canonical name** | `CNDHash_FreeBuckets_NonOwning_009cfa70` (Ghidra `FUN_0053b880`; **Inferred**) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_0053b880_CNDHash_FreeBuckets_NonOwning_009cfa70.md` |
| **System** | container / CNDHash (object family `PTR_FUN_009cfa70`, char install `+0x6f0`) |
| **Live tools** | Ghidra `batch_decompile` + `read_memory` (no `disassemble_bytes`) |
| **Verdict** | **accept** — FreeBuckets CF High; **non-owning** reclaim High |

---

## 1. Purpose

**FreeBuckets** for object family **`009cfa70`** with the **same outer skeleton** as owning twins (`00539090`/`d0`/`110`) but **non-owning reclaim**:

1. `count(+0x0c) = 0`
2. Reclaim **`FUN_0053b8c0`**: walk buckets; stamp node **`009cefdc`**; freelist-push; **no** `operator_delete` on values
3. If `table(+0x10)`: `free(*table)`, `operator_delete__(table)`, null `+0x10`

Primary static caller: Dtor `0x0053b810` (also internal xref `0x0053b85e` within that body). Payload ownership is **external** for this family.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Fresh decompile | `batch_decompile` @ `0x0053b880` ≡ raw |
| Machine | `read_memory` @ `0x0053b880` length 64 |
| Reclaim | `FUN_0053b8c0` — freelist only, stamp `009cefdc` |
| Caller | Dtor `FUN_0053b810` / dual `A_aa_0053b810_CNDHash_Dtor_009cfa70.md` |
| Contrast | Owning FreeBuckets `00539090`/`d0`/`110` |
| Raw / clean / function | `raw/aa_0053b880_*`, `reconstructed-exact/FUN_0053b880.cpp`, `functions/aa_0053b880_*` |

---

## 3. Authoritative body

```c
void __fastcall CNDHash_FreeBuckets_NonOwning_009cfa70(CNDHash *this)
{
  *(uint32_t *)((char *)this + 0x0c) = 0;
  FUN_0053b8c0(this);  // non-owning reclaim, stamp 009cefdc
  if (*(void **)((char *)this + 0x10) != 0) {
    free(**(void ***)((char *)this + 0x10));
    operator_delete__(*(void **)((char *)this + 0x10));
    *(void **)((char *)this + 0x10) = 0;
  }
}
```

---

## 4. Machine seal (`read_memory` @ `0x0053b880`)

Hex:  
`56 8b f1 c7 46 0c 00 00 00 00 e8 31 00 00 00 8b 46 10 85 c0 74 1c 8b 00 50 ff 15 24 65 9c 00 8b 4e 10 51 e8 74 df f4 ff 83 c4 08 c7 46 10 00 00 00 00 5e c3`

| Claim | Evidence | Conf |
|---|---|---|
| Outer CF ≡ owning FreeBuckets | same opcodes; call relocs differ | **High** |
| Reclaim `0x0053b8c0` | `e8 31 00 00 00` → next function | **High** |
| Non-owning reclaim | callee has **no** `operator_delete` on `node[2]` | **High** |
| free(*table) + delete table + null | same free/delete/null sequence | **High** |
| bare `ret` | `5e c3` | **High** |

---

## 5. Family context

| Unit | VA | Role |
|---|---|---|
| Reclaim | `0x0053b8c0` | non-owning freelist reclaim |
| **FreeBuckets** | **`0x0053b880`** | count=0 + reclaim + free table |
| Dtor | `0x0053b810` | FreeBuckets + freelist-slab dtor |
| Scalar dtor | `0x0053b7f0` | dtor + optional `operator_delete` |

---

## 6. Gaps / open

1. Product FreeBuckets name.
2. Who owns values before this teardown (caller contract residual).
3. Runtime not run.

**Verdict:** **accept**
