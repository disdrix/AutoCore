# Review A (reconstruction fidelity): `aa_00413e20` CNDHash_DestroyBucketTable_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00413e20` |
| **VA** | `0x00413e20` |
| **Canonical name** | `CNDHash_DestroyBucketTable_Inferred` |
| **Ghidra** | `FUN_00413e20` |
| **Review date** | `2026-07-29` (OWN-ONLY dual — rebuild nested) |
| **Counterpart** | `reviews/B_aa_00413e20_CNDHash_DestroyBucketTable_Inferred.md` |
| **System** | container / CNDHash (u64 inventory family) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Tear down the **bucket pointer table** of a CNDHash (EAX=hash):

1. `*(hash+0xc) = 0` — live entry count → 0.
2. `FUN_00413ea0` — walk every bucket chain; destroy value objects; push nodes to freelist `hash+0x20`.
3. If `*(hash+0x10) != 0`:
   - `free(**(hash+0x10))` — free the **contiguous 0xc-stride sentinel slab** (first bucket ptr = slab base).
   - `operator_delete[](*(hash+0x10))` — free the **pointer array**.
   - `*(hash+0x10) = 0`.

**Callers:** `CNDHash_Recreate` (`004138d0`), `FUN_00413850` (sibling dtor path).

---

## 2. ABI / CF

| Slot | Role |
|------|------|
| **EAX** | hash* (`in_EAX`) |
| return | void |

```text
count = 0
ReleaseNodesToFreelist(hash)   // EBX/this plumbing on child
if table = hash+0x10:
  free(*table)                 // slab
  delete[] table
  hash+0x10 = 0
```

Does **not** clear freelist head `+0x20`, ordered list (caller Recreate zeros head/tail), or lock byte.

---

## 3. Confidence

| Claim | Conf |
|---|---|
| Role = destroy bucket table after node release | **High** |
| Dual free of slab + ptr array | **High** |
| Count zeroed first | **High** |
| Product name | **Inferred** |
| Safe if `+0x10` null mid-call to 00413ea0 | **Open** (caller invariant) |

**Verdict:** **accept-with-gaps**
