# Review A (reconstruction fidelity): `aa_0053b780` CNDHash_Dtor_009cfa64

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053b780` |
| **VA** | `0x0053b780` |
| **Canonical name** | `CNDHash_Dtor` (object vtbl `PTR_FUN_009cfa64`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Path A — fidelity |
| **Counterpart** | `reviews/B_aa_0053b780_CNDHash_Dtor_009cfa64.md` |
| **System** | container / CNDHash family |
| **Live tools** | `batch_decompile`; FreeBuckets `00539090` (shared with Recreate); callers |
| **Dual status** | **Present — sealed 2026-07-29** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**CNDHash destructor** for object family **`PTR_FUN_009cfa64`** (character hash install `+0x534`; recreate `00539d70`).

CF twin of `0053b560`, stamp delta:

| Step | This VA |
|---|---|
| Object vtbl | `009cfa64` |
| FreeBuckets | **`FUN_00539090`** (shared with Recreate path) |
| Reclaim | `FUN_00538120` — **owning** (`operator_delete` on `node+8` when set) |
| Freelist slabs | `FUN_0059c8a0` |
| Scalar dtor | `FUN_0053b760` |

Important: this family’s FreeBuckets reclaim **is value-owning**, unlike `0053b560`/`0053b670` non-owning reclaim twins. Matches recreate teardown for the same object family.

---

## 2. Evidence table

| Claim | Evidence | Confidence |
|---|---|---|
| Dtor stamps `009cfa64` | decompile | **High** |
| FreeBuckets `00539090` | call site | **High** |
| Owning reclaim | `00538120` deletes `node[2]` | **High** |
| Shared teardown with Recreate | recreate also calls `00539090` | **High** |
| Lock log non-fatal | same pattern | **High** |

---

## 3. Recovered CF

```c
// void __fastcall CNDHash_Dtor_009cfa64(this)
this->vtbl = PTR_FUN_009cfa64;
if (this->lock) log Destructor-locked;
FreeBuckets_00539090(this);  // owning reclaim 00538120 + free table
FreelistSlabVector_dtor_0059c8a0(...);
```

**Verdict:** **accept-with-gaps.**
