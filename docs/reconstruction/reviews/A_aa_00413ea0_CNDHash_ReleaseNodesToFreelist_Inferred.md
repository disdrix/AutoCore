# Review A (reconstruction fidelity): `aa_00413ea0` CNDHash_ReleaseNodesToFreelist_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00413ea0` |
| **VA** | `0x00413ea0` |
| **Canonical name** | `CNDHash_ReleaseNodesToFreelist_Inferred` |
| **Ghidra** | `FUN_00413ea0` |
| **Review date** | `2026-07-29` (OWN-ONLY dual — rebuild nested) |
| **Counterpart** | `reviews/B_aa_00413ea0_CNDHash_ReleaseNodesToFreelist_Inferred.md` |
| **System** | container / CNDHash u64 node family |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

For each bucket index `i = 0 .. *(hash+8)` **inclusive** (mask+1 buckets when `+8` is mask):

- Walk chain starting at `table[i]->head` (`*(bucket+4)`).
- Per node:
  - Restore node vtbl `PTR_FUN_00a64758` (same as Insert).
  - If value `node+0xc` non-null: call `(*value_vtbl)(1)` — **deleting destroy** of owned payload.
  - Clear value ptr; push node onto freelist at `hash+0x20` (intrusive free via `*node = old_freelist`).
- Zero bucket head `*(bucket+4) = 0`.

**Caller:** DestroyBucketTable only (within sealed Recreate chain).

---

## 2. ABI / layout

| Slot | Role |
|------|------|
| **EBX** | hash* (`unaff_EBX`) |

| Offset | Role |
|-------:|------|
| hash+8 | upper bound for bucket loop (`<=`) → count = mask+1 |
| hash+0x10 | bucket pointer array |
| hash+0x20 | freelist head |
| node+0xc (`[3]`) | value* |
| node+0x10 (`[4]`) | next in bucket chain |
| bucket+4 | chain head |

---

## 3. Confidence

| Claim | Conf |
|---|---|
| Releases all live nodes to freelist | **High** |
| Deletes value with vtbl(1) | **High** |
| Node vtbl `00a64758` matches Insert | **High** |
| Loop bound uses mask-or-count consistently with Alloc post-state | **High** |
| EBX ABI (decompiler unaff) | **High** (custom) |

**Verdict:** **accept-with-gaps**
