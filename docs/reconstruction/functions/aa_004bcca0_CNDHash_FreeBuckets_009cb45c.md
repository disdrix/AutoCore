# Function record: CNDHash_FreeBuckets_009cb45c

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bcca0` |
| **Canonical name** | `CNDHash_FreeBuckets_009cb45c` |
| **Address** | `0x004bcca0`–`0x004bccd4` (**52 B / `0x34`**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | container / CNDHash (object family `009cb45c` primary) |
| **Completion status** | **Dual A/B present** (2026-07-29 W31-M) — accept-with-gaps |
| **Name status** | Role name stamp-qualified; no body string |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

| Name | Status |
|---|---|
| `FUN_004bcca0` | Ghidra scaffold |
| `Named_CalleeOf_Named_VOG_DEBUG_STOP_004bcca0` | **Reject** as product id (parent Recreate/dtor lock strings) |

## Purpose

Clear a CNDHash instance's occupied entries and bucket storage (primary family `009cb45c`):

1. `count (+0xC) = 0`
2. `FUN_004e2bd0(this)` — reclaim nodes to freelist; destroy owned values (node stamp path `009cb360`)
3. If `buckets (+0x10)` non-null: `free(*buckets)` (sentinel slab), `delete[] buckets`, null pointer

Does **not** free freelist `+0x20` or zero list head/tail.

**Shared body:** also called from dtor `FUN_004e66a0` (vtbl `009cc6c0`) and parallel Recreate `FUN_004e4990`.

## Signature

```c
void __thiscall CNDHash_FreeBuckets_009cb45c(CNDHash *this); // plain ret
```

## Callers / callees

| Direction | Symbol | VA / note |
|---|---|---|
| Caller | `CNDHash_Recreate_009cb45c` | `0x004bcd66` (W30-G) |
| Caller | Dtor `FUN_004bd140` | `0x004bd18e` (vtbl `009cb45c`) |
| Caller | Recreate-like `FUN_004e4990` | `0x004e49b6` |
| Caller | Dtor `FUN_004e66a0` | `0x004e66ee` (vtbl `009cc6c0`) |
| Callee | `FUN_004e2bd0` | owning reclaim |
| Callee | `free` | slab @ IAT `0x009c6524` |
| Callee | `operator_delete[]` | bucket table `0x0048981c` |

## Family

| Sibling | Role |
|---|---|
| `CNDHash_Recreate_009cb45c` `0x004bcd40` | Free → size → Alloc (W30-G) |
| `CNDHash_AllocBucketTable_009cb350` `0x004bc840` | alloc (W29-K) |
| `CNDHash_Ctor_009cb45c` `0x004bcf90` | ctor (W28-J) |
| `CNDHash_FreeBuckets_009cb450` `0x004bcc60` | tableC FreeBuckets twin (this dual) |
| `CNDHash_FreeBuckets` `0x0051d150` | medal parallel (W24-H) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004bcca0_FUN_004bcca0.md`
- Annotated: `docs/reconstruction/raw/aa_004bcca0_FUN_004bcca0.annotated.md`
- Clean scaffold: `docs/reconstruction/reconstructed-exact/FUN_004bcca0.cpp`
- Clean named: `docs/reconstruction/reconstructed-exact/CNDHash_FreeBuckets_009cb45c.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_004bcca0_CNDHash_FreeBuckets_009cb45c.md`
- Dual B: `docs/reconstruction/reviews/B_aa_004bcca0_CNDHash_FreeBuckets_009cb45c.md`
- FUN_ record: `docs/reconstruction/functions/aa_004bcca0_FUN_004bcca0.md`
- Dual report: `docs/agents/task-dual-ab-004bcca0-004bcc60-w31m-report.md`

## Confidence

| Claim | Level |
|---|---|
| CF zero / reclaim / free table | **Confirmed** |
| `__thiscall` plain ret | **Confirmed** |
| free(*buckets) = slab free (matches Alloc) | **High** |
| Four static callers | **Confirmed** |
| Role FreeBuckets + stamp qualifier | **High** |
| Product/PDB symbol | **Open** |
| Full reclaim value policy | **Open** (callee residual) |
| Runtime / bit-exact / diff | **Open** |
