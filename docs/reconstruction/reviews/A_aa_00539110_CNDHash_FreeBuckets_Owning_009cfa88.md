# Review A (reconstruction fidelity): `aa_00539110` CNDHash_FreeBuckets_Owning_009cfa88

| Field | Value |
|---|---|
| **Stable ID** | `aa_00539110` |
| **VA** | `0x00539110` |
| **Body** | `0x00539110`–`0x00539143` (**`ret`**, 52 B + pad) |
| **Canonical name** | `CNDHash_FreeBuckets_Owning_009cfa88` (Ghidra `FUN_00539110`; **Inferred**) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00539110_CNDHash_FreeBuckets_Owning_009cfa88.md` |
| **System** | container / CNDHash (object family `PTR_FUN_009cfa88`, pending objectives char `+0x55c`) |
| **Live tools** | Ghidra `batch_decompile` + `read_memory` (no `disassemble_bytes`) |
| **Verdict** | **accept** |

---

## 1. Purpose

Third **owning FreeBuckets** twin (same 52-byte skeleton):

1. `count(+0x0c) = 0`
2. Owning reclaim **`FUN_00538200`** (node freelist stamp **`009cefec`**, value-owning)
3. Free sentinel slab + bucket table at `+0x10` if non-null

Callers: Recreate `0x00539e30`, Dtor `0x0053b9b0`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Fresh decompile | `batch_decompile` @ `0x00539110` ≡ raw |
| Machine | `read_memory` @ `0x00539110` length 64 |
| Reclaim | `FUN_00538200` / stamp `009cefec` (value-owning node dual family) |
| Callers | Recreate `0x00539e56`; Dtor `0x0053b9fe` (`FUN_0053b9b0`) |
| Sibling duals | `A_aa_00539e30_CNDHash_Recreate_009cfa88.md`; node scalar `A_aa_00537550_*` |
| Raw / clean / function | `raw/aa_00539110_*`, `reconstructed-exact/FUN_00539110.cpp`, `functions/aa_00539110_*` |

---

## 3. Authoritative body

```c
void __fastcall CNDHash_FreeBuckets_Owning_009cfa88(CNDHash *this)
{
  *(uint32_t *)((char *)this + 0x0c) = 0;
  FUN_00538200(this);  // owning reclaim, stamp 009cefec
  if (*(void **)((char *)this + 0x10) != 0) {
    free(**(void ***)((char *)this + 0x10));
    operator_delete__(*(void **)((char *)this + 0x10));
    *(void **)((char *)this + 0x10) = 0;
  }
}
```

---

## 4. Machine seal (`read_memory` @ `0x00539110`)

Hex:  
`56 8b f1 c7 46 0c 00 00 00 00 e8 e1 f0 ff ff 8b 46 10 85 c0 74 1c 8b 00 50 ff 15 24 65 9c 00 8b 4e 10 51 e8 e4 06 f5 ff 83 c4 08 c7 46 10 00 00 00 00 5e c3`

| Claim | Evidence | Conf |
|---|---|---|
| Skeleton ≡ `00539090` / `005390d0` | hex compare | **High** |
| Reclaim `0x00538200` | `e8 e1 f0 ff ff` | **High** |
| bare `ret` | `5e c3` | **High** |
| Owning values via `009cefec` reclaim | callee body | **High** |

---

## 5. Family context

| Unit | VA |
|---|---|
| Reclaim | `0x00538200` |
| **FreeBuckets** | **`0x00539110`** |
| Recreate | `0x00539e30` |
| Dtor | `0x0053b9b0` |
| Pending hash install | char `+0x55c` |

---

## 6. Gaps / open

1. Product FreeBuckets name.
2. Runtime not run.

**Verdict:** **accept**
