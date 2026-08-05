# Review A (reconstruction fidelity): `aa_00539090` CNDHash_FreeBuckets_Owning_009cfa64

| Field | Value |
|---|---|
| **Stable ID** | `aa_00539090` |
| **VA** | `0x00539090` |
| **Body** | `0x00539090`–`0x005390c3` (**`ret`**, 52 B + `int3` pad) |
| **Canonical name** | `CNDHash_FreeBuckets_Owning_009cfa64` (Ghidra `FUN_00539090`; product English **Inferred**) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00539090_CNDHash_FreeBuckets_Owning_009cfa64.md` |
| **System** | container / CNDHash (object family `PTR_FUN_009cfa64`, char hash `+0x534`) |
| **Live tools** | Ghidra `batch_decompile` + `read_memory` (no `disassemble_bytes`) |
| **Verdict** | **accept** — FreeBuckets CF sealed High; ownership via reclaim twin High |

---

## 1. Purpose

**CNDHash FreeBuckets / full table teardown** shared by Recreate (`0x00539d70`) and Dtor (`0x0053b780`) for object family **`009cfa64`**:

1. Zero element **count** at `this+0x0c`.
2. Call **owning reclaim** `FUN_00538120` — walk all buckets `0..mask(+0x08)`, for each node: stamp `009cefd4`, `operator_delete` value at `node+8` if set, push node to freelist `+0x20`, clear chain heads.
3. If bucket table pointer `this+0x10` non-null: `free(*table)` (sentinel slab via first entry), `operator_delete__(table)`, set `+0x10 = 0`.

Does **not** free freelist slab vector (`0059c8a0` is dtor-only), does **not** touch lock/bits, does **not** zero freelist head.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Fresh decompile | `batch_decompile` @ `0x00539090` ≡ raw 2026-07-23 |
| Machine | `read_memory` @ `0x00539090` length 64 |
| Reclaim twin | `FUN_00538120` (owning; node stamp `009cefd4`) |
| Callers | Recreate `0x00539d96`; Dtor `0x0053b7ce` (`FUN_0053b780`) |
| Sibling duals | `A_aa_00539d70_CNDHash_Recreate_009cfa64.md`; `A_aa_0053b780_CNDHash_Dtor_009cfa64.md` |
| Raw / clean / function | `raw/aa_00539090_*`, `reconstructed-exact/FUN_00539090.cpp`, `functions/aa_00539090_*` |

---

## 3. Authoritative body

```c
void __fastcall CNDHash_FreeBuckets_Owning_009cfa64(CNDHash *this)
{
  *(uint32_t *)((char *)this + 0x0c) = 0;       // count
  FUN_00538120(this);                           // owning reclaim → freelist
  if (*(void **)((char *)this + 0x10) != 0) {
    free(**(void ***)((char *)this + 0x10));    // free(*table) sentinel slab
    operator_delete__(*(void **)((char *)this + 0x10));
    *(void **)((char *)this + 0x10) = 0;
  }
}
```

---

## 4. Machine seal (`read_memory` @ `0x00539090`)

Hex:  
`56 8b f1 c7 46 0c 00 00 00 00 e8 81 f0 ff ff 8b 46 10 85 c0 74 1c 8b 00 50 ff 15 24 65 9c 00 8b 4e 10 51 e8 64 07 f5 ff 83 c4 08 c7 46 10 00 00 00 00 5e c3`

| Claim | Evidence | Conf |
|---|---|---|
| `this` ECX → ESI | `56 8b f1` | **High** |
| `count(+0x0c) = 0` | `c7 46 0c 00 00 00 00` | **High** |
| Call reclaim `0x00538120` | `e8 81 f0 ff ff` from `0x0053909f` | **High** |
| Gate on `table(+0x10)` | `8b 46 10; 85 c0; 74 1c` | **High** |
| `free(*table)` via IAT | `8b 00; 50; ff 15 24 65 9c 00` | **High** |
| `operator_delete__(table)` + `add esp,8` | push table; call; `83 c4 08` | **High** |
| Null `+0x10`; bare **`ret`** | `c7 46 10 …; 5e c3` | **High** |
| Owning reclaim | callee deletes `node[2]` | **High** (callee body) |

---

## 5. Family context

| Unit | VA | Role |
|---|---|---|
| Reclaim | `0x00538120` | owning freelist reclaim, stamp `009cefd4` |
| **FreeBuckets** | **`0x00539090`** | count=0 + reclaim + free table |
| Recreate | `0x00539d70` | FreeBuckets then AllocBuckets |
| Dtor | `0x0053b780` | FreeBuckets then freelist-slab dtor |
| Scalar dtor | `0x0053b760` | dtor body + optional `operator_delete` |

---

## 6. Gaps / open

1. Product/PDB English for FreeBuckets method name.
2. Exact slab layout of `*table` (sentinel-at-0 free pattern — High for free order, layout residual).
3. Runtime / bit-exact / differential — open.

**Verdict:** **accept**
