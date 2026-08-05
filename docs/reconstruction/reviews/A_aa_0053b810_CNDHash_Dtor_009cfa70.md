# Review A (reconstruction fidelity): `aa_0053b810` CNDHash_Dtor_009cfa70

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053b810` |
| **VA** | `0x0053b810` |
| **Canonical name** | `CNDHash_Dtor` (object vtbl `PTR_FUN_009cfa70`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Path A — fidelity |
| **Counterpart** | `reviews/B_aa_0053b810_CNDHash_Dtor_009cfa70.md` |
| **System** | container / CNDHash family |
| **Live tools** | `batch_decompile`; FreeBuckets `0053b880` / reclaim `0053b8c0`; callers |
| **Dual status** | **Present — sealed 2026-07-29** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**CNDHash destructor** for object family **`PTR_FUN_009cfa70`** (character ctor install `param_1[0x1bc]` → **`this+0x6f0`**, bits=4, Alloc `00537ab0`).

| Step | This VA |
|---|---|
| Object vtbl | `009cfa70` |
| FreeBuckets | `FUN_0053b880` |
| Reclaim | `FUN_0053b8c0` (node stamp `009cefdc`, freelist push, **no** value delete) |
| Freelist slabs | `FUN_0059c8a0` |
| Scalar dtor | `FUN_0053b7f0` |

CF: SEH → vtbl stamp → Destructor lock log → FreeBuckets (count=0, reclaim all buckets, free table) → freelist slab teardown.

Reclaim `0053b8c0`: `for (u=0; u<=mask; u++)` walk chain at `table[u]->head` (`+4`); stamp node `009cefdc` then overwrite with freelist link; clear chain head.

---

## 2. Evidence table

| Claim | Evidence | Confidence |
|---|---|---|
| Dtor CF family | decompile | **High** |
| Non-owning reclaim | no `operator_delete` on values | **High** |
| FreeBuckets `0053b880` | call | **High** |
| Char `+0x6f0` install uses object vtbl | ctor dual | **High** |
| Scalar wrapper `0053b7f0` | callers | **High** |

---

## 3. Recovered CF

```c
// void __fastcall CNDHash_Dtor_009cfa70(this)
this->vtbl = PTR_FUN_009cfa70;
if (this->lock) log Destructor-locked;
FreeBuckets_0053b880(this);  // reclaim 0053b8c0 non-owning + free table
FreelistSlabVector_dtor_0059c8a0(...);
```

**Verdict:** **accept-with-gaps.**
