# Review A (reconstruction fidelity): `aa_0053b920` CNDHash_Dtor_009cfa7c

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053b920` |
| **VA** | `0x0053b920` |
| **Body** | `0x0053b920`–`0x0053b98a` (**`ret`**, 107 B / `0x6B`) |
| **Canonical name** | `CNDHash_Dtor_009cfa7c` (Ghidra `FUN_0053b920`; **Inferred**) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_0053b920_CNDHash_Dtor_009cfa7c.md` |
| **System** | container / CNDHash (object family `PTR_FUN_009cfa7c`, owning FreeBuckets) |
| **Live tools** | Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` + `get_function_by_address` (no `disassemble_bytes`) |
| **Dual status** | **Present — sealed 2026-07-29 W24-M** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**CNDHash destructor** for object family **`009cfa7c`** (same FreeBuckets as Recreate `0x00539dd0`):

1. SEH frame; set object vtbl `PTR_FUN_009cfa7c` (dtor re-stamp).
2. If lock `+0x1d` → `"HashError:Destructor, already locked for traversal"` + `VOG_DEBUG_STOP`; continue.
3. **`FUN_005390d0`** FreeBuckets owning: `count=0`; reclaim all chains via **`FUN_00538190`** (node stamp `009cefe4`, **`operator_delete` values**, freelist push `+0x20`); free sentinel slab + pointer table; null `+0x10`.
4. **`FUN_0059c8a0`** freelist slab vector teardown with **ECX = this+0x20** (`_aligned_free` each slab, delete vector).
5. Restore ExceptionList; bare `ret`.

Scalar deleting dtor: `FUN_0053b900` → this + optional `operator_delete`.

### Callers

| Site | Role |
|---|---|
| `FUN_0053b900` | scalar deleting dtor (vtbl[0] of `009cfa7c`) |

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Fresh decompile | `decompile_function` @ `0x0053b920` ≡ raw surface |
| Machine | `read_memory` @ `0x0053b920` length 128 |
| FreeBuckets | dual `A_aa_005390d0_CNDHash_FreeBuckets_Owning_009cfa7c.md` |
| Reclaim | `CNDHash_ReclaimAll_ValueOwning_009cefe4` @ `0x00538190` |
| Freelist | this dual `aa_0059c8a0` |
| Vtbl | `read_memory` @ `0x009cfa7c` → slot0 `0x0053b900` |
| Raw / clean / function | `raw/aa_0053b920_*`, `CNDHash_Dtor_009cfa7c.cpp`, `functions/aa_0053b920_*` |

---

## 3. Authoritative body (machine-corrected)

```c
// void __thiscall CNDHash_Dtor_009cfa7c(CNDHash *this)
this->vtbl = PTR_FUN_009cfa7c;
if (this->lock) log Destructor-locked; // non-fatal
CNDHash_FreeBuckets_Owning_009cfa7c(this);     // 005390d0
FreelistSlabVector_dtor(this + 0x20);            // 0059c8a0; lea ecx,[esi+0x20]
```

---

## 4. Machine seal (`read_memory` @ `0x0053b920`)

Hex (body through `c3`):  
`6aff68db3e9a0064a100000000506489250000000051568bf189742404c7067cfa9c00807e1d00c744241000000000741b6870c2a2006a00e8238b2600684458a1006a00e8178b260083c4108bcee85dd7ffff8d4e20e8250f06008b4c24085e64890d0000000083c410c3`

| Claim | Evidence | Conf |
|---|---|---|
| Vtbl imm `0x009cfa7c` | `c7 06 7c fa 9c 00` | **High** |
| FreeBuckets target `0x005390d0` | `e8 5d d7 ff ff` @ `0x0053b96e` | **High** |
| Freelist ECX = `this+0x20` | `8d 4e 20` + call `0059c8a0` | **High** |
| Bare `ret` | `c3` @ `0x0053b98a` | **High** |
| Owning family | FreeBuckets → reclaim `00538190` deletes values | **High** |
| Lock non-fatal | log then fall through | **High** |

---

## 5. Family context

| Unit | VA |
|---|---|
| Scalar dtor | `0x0053b900` |
| **Dtor body** | **`0x0053b920`** |
| FreeBuckets owning | `0x005390d0` |
| Reclaim owning | `0x00538190` |
| Freelist slabs | `0x0059c8a0` |
| Recreate (shares FreeBuckets) | `0x00539dd0` |

Non-owning twin: `CNDHash_Dtor_009cfa70` @ `0x0053b810`.

---

## 6. Gaps / open

1. Product FreeBuckets / class English name for family `009cfa7c`.
2. Runtime not run.
3. Install site(s) of object vtbl `009cfa7c` (ctor) not re-walked this seal (known via FreeBuckets dual).

**Verdict:** **accept-with-gaps.**
