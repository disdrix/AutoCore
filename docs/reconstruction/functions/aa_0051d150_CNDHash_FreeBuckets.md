# Function record: CNDHash_FreeBuckets

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051d150` |
| **Canonical name** | `CNDHash_FreeBuckets` |
| **Address** | `0x0051d150`–`0x0051d183` (**0x33** bytes) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | container / missions-progression (medal CNDHash) |
| **Completion status** | **Dual A/B present** (2026-07-29 W24-H) — accept-with-gaps |
| **Name status** | Role name from FreeBuckets family pattern; no body string |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

| Name | Status |
|---|---|
| `FUN_0051d150` | Ghidra scaffold |
| `Named_CalleeOf_Named_VOG_DEBUG_STOP_0051d150` | **Reject** as product id (dtor/recreate lock strings are parent) |

## Purpose

Clear a CNDHash instance's occupied entries and bucket storage:

1. `count (+0xC) = 0`
2. `FUN_0051bfb0(this)` — reclaim nodes to freelist; destroy owned values
3. If `buckets (+0x10)` non-null: `free(*buckets)` (sentinel slab), `delete[] buckets`, null pointer

Does **not** free freelist `+0x20` or zero list head/tail.

## Signature

```c
void __thiscall CNDHash_FreeBuckets(CNDHash *this); // plain ret
```

## Callers / callees

| Direction | Symbol | VA / note |
|---|---|---|
| Caller | `CNDHash_Recreate` | `0x0051d256` |
| Caller | `FUN_0051dfe0` (dtor, vtbl `009ce1a0`) | `0x0051e02e` |
| Callee | `FUN_0051bfb0` | reclaim / freelist |
| Callee | `free` | slab |
| Callee | `operator_delete[]` | bucket table |

## Family

| Sibling | Role |
|---|---|
| `CNDHash_Recreate` `0x0051d230` | clear + realloc (string-named) |
| `CNDHash_Insert_009ce0a8` | insert on same table family |
| `FUN_0051ba40` | alloc buckets/sentinels |
| `CNDHash_FreeBuckets_Owning_009cfa*` | parallel FreeBuckets on other stamps |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0051d150_FUN_0051d150.md`
- Annotated: `docs/reconstruction/raw/aa_0051d150_FUN_0051d150.annotated.md`
- Clean scaffold: `docs/reconstruction/reconstructed-exact/FUN_0051d150.cpp`
- Clean named: `docs/reconstruction/reconstructed-exact/CNDHash_FreeBuckets.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_0051d150_CNDHash_FreeBuckets.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0051d150_CNDHash_FreeBuckets.md`
- FUN_ record: `docs/reconstruction/functions/aa_0051d150_FUN_0051d150.md`

## Confidence

| Claim | Level |
|---|---|
| CF zero / reclaim / free table | **Confirmed** |
| `__thiscall` plain ret | **Confirmed** |
| free(*buckets) = slab free (matches Alloc) | **High** |
| Role name FreeBuckets | **High** |
| Product/PDB symbol | **Open** |
| Full reclaim value policy | **Open** (callee residual) |
