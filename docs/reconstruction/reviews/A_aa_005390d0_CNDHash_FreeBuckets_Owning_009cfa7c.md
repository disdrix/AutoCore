# Review A (reconstruction fidelity): `aa_005390d0` CNDHash_FreeBuckets_Owning_009cfa7c

| Field | Value |
|---|---|
| **Stable ID** | `aa_005390d0` |
| **VA** | `0x005390d0` |
| **Body** | `0x005390d0`–`0x00539103` (**`ret`**, 52 B + pad) |
| **Canonical name** | `CNDHash_FreeBuckets_Owning_009cfa7c` (Ghidra `FUN_005390d0`; **Inferred**) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_005390d0_CNDHash_FreeBuckets_Owning_009cfa7c.md` |
| **System** | container / CNDHash (object family `PTR_FUN_009cfa7c`, char hash `+0x530`) |
| **Live tools** | Ghidra `batch_decompile` + `read_memory` (no `disassemble_bytes`) |
| **Verdict** | **accept** |

---

## 1. Purpose

**Byte-identical FreeBuckets skeleton** to `0x00539090`, twin for object family **`009cfa7c`**:

1. `count(+0x0c) = 0`
2. Owning reclaim **`FUN_00538190`** (node freelist stamp **`009cefe4`**, `operator_delete` values)
3. If `table(+0x10)`: `free(*table)`, `operator_delete__(table)`, null `+0x10`

Shared by Recreate `0x00539dd0` and Dtor `0x0053b920`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Fresh decompile | `batch_decompile` @ `0x005390d0` ≡ raw |
| Machine | `read_memory` @ `0x005390d0` length 64 |
| Reclaim | `FUN_00538190` / stamp `009cefe4` |
| Callers | Recreate `0x00539df6`; Dtor `0x0053b96e` (`FUN_0053b920`) |
| Sibling duals | `A_aa_00539dd0_CNDHash_Recreate_009cfa7c.md` |
| Raw / clean / function | `raw/aa_005390d0_*`, `reconstructed-exact/FUN_005390d0.cpp`, `functions/aa_005390d0_*` |

---

## 3. Authoritative body

```c
void __fastcall CNDHash_FreeBuckets_Owning_009cfa7c(CNDHash *this)
{
  *(uint32_t *)((char *)this + 0x0c) = 0;
  FUN_00538190(this);  // owning reclaim, stamp 009cefe4
  if (*(void **)((char *)this + 0x10) != 0) {
    free(**(void ***)((char *)this + 0x10));
    operator_delete__(*(void **)((char *)this + 0x10));
    *(void **)((char *)this + 0x10) = 0;
  }
}
```

---

## 4. Machine seal (`read_memory` @ `0x005390d0`)

Hex:  
`56 8b f1 c7 46 0c 00 00 00 00 e8 b1 f0 ff ff 8b 46 10 85 c0 74 1c 8b 00 50 ff 15 24 65 9c 00 8b 4e 10 51 e8 24 07 f5 ff 83 c4 08 c7 46 10 00 00 00 00 5e c3`

| Claim | Evidence | Conf |
|---|---|---|
| Same opcode skeleton as `00539090` | hex differ only in near-call relocs | **High** |
| Reclaim target `0x00538190` | `e8 b1 f0 ff ff` | **High** |
| free IAT same `0x009c6524` | `ff 15 24 65 9c 00` | **High** |
| bare `ret`, ECX this | `5e c3` | **High** |
| Owning | callee deletes `node[2]` | **High** |

---

## 5. Family context

| Unit | VA |
|---|---|
| Reclaim | `0x00538190` |
| **FreeBuckets** | **`0x005390d0`** |
| Recreate | `0x00539dd0` |
| Dtor | `0x0053b920` |

---

## 6. Gaps / open

1. Product FreeBuckets name.
2. Runtime not run.

**Verdict:** **accept**
