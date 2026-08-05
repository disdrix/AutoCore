# Review A (reconstruction fidelity): `aa_0053b560` CNDHash_Dtor_009cfa4c

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053b560` |
| **VA** | `0x0053b560` |
| **Canonical name** | `CNDHash_Dtor` (object vtbl `PTR_FUN_009cfa4c`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Path A — fidelity |
| **Counterpart** | `reviews/B_aa_0053b560_CNDHash_Dtor_009cfa4c.md` |
| **System** | container / CNDHash family |
| **Live tools** | `batch_decompile`; `read_memory`; FreeBuckets chain; callers |
| **Dual status** | **Present — sealed 2026-07-29** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**CNDHash destructor** for object family `009cfa4c` (same family as sealed ctor `0053b0b0`):

1. SEH frame; set object vtbl `PTR_FUN_009cfa4c` (dtor re-stamp).
2. If lock `+0x1d` → `"HashError:Destructor, already locked for traversal"` + `VOG_DEBUG_STOP`; continue.
3. **`FUN_0053b5d0`** FreeBuckets: `count=0`; reclaim all chains via `FUN_0053b610` (node stamp `009cf024`, push freelist `+0x20`, no value delete in this twin); free sentinel slab (`free(*table[0])` pattern) + `operator_delete__` pointer table; null `+0x10`.
4. **`FUN_0059c8a0`** — freelist slab vector teardown (`_aligned_free` each slab, delete vector). Ghidra shows bare call; product intent is freelist pool cleanup after nodes reclaimed (subobject / adjusted-ECX residual noted in gaps).
5. Restore ExceptionList; return.

Scalar deleting dtor: `FUN_0053b540` → this + optional `operator_delete`.

### Callers

| Site | Role |
|---|---|
| `FUN_0053b540` | scalar deleting dtor |
| `FUN_0060c000` | region / table teardown path |

---

## 2. Evidence table

| Claim | Evidence | Confidence |
|---|---|---|
| Dtor vtbl stamp `009cfa4c` | body `mov [esi], 009cfa4c` | **High** |
| Lock log non-fatal | branch only logs | **High** |
| FreeBuckets `0053b5d0` → reclaim `0053b610` | decompile | **High** |
| Reclaim does **not** `operator_delete` values | `0053b610` only freelist push | **High** |
| Loop `u <= mask` | `while (uVar4 <= *(param+8))` | **High** |
| Pair with ctor `0053b0b0` | same object vtbl | **High** |
| Exact ECX for `0059c8a0` | freelist vector role clear; adjust residual | **Probable** |

---

## 3. Recovered CF

```c
// void __fastcall CNDHash_Dtor_009cfa4c(CNDHash *this)
this->vtbl = PTR_FUN_009cfa4c;
if (this->lock) log Destructor-locked;
FreeBuckets_0053b5d0(this);   // non-owning reclaim → freelist; free table
FreelistSlabVector_dtor_0059c8a0(/* freelist pool */);
```

**Verdict:** **accept-with-gaps.**
