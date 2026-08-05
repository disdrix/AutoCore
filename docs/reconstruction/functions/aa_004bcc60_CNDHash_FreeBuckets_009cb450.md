# Function record: CNDHash_FreeBuckets_009cb450

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bcc60` |
| **Canonical name** | `CNDHash_FreeBuckets_009cb450` |
| **Address** | `0x004bcc60`–`0x004bcc94` (**52 B / `0x34`**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | container / CNDHash (object family `009cb450` / tableC) |
| **Completion status** | **Dual A/B present** (2026-07-29 W31-M) — accept-with-gaps |
| **Name status** | Role name stamp-qualified; no body string |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

| Name | Status |
|---|---|
| `FUN_004bcc60` | Ghidra scaffold |
| `Named_CalleeOf_Named_VOG_DEBUG_STOP_004bcc60` | **Reject** as product id |

## Purpose

Clear a CNDHash instance's occupied entries and bucket storage (family `009cb450` / tableC):

1. `count (+0xC) = 0`
2. `FUN_004bcae0(this)` — reclaim nodes to freelist; destroy owned values (node stamp path `009cb358`)
3. If `buckets (+0x10)` non-null: `free(*buckets)` (sentinel slab), `delete[] buckets`, null pointer

Does **not** free freelist `+0x20` or zero list head/tail.

**Twin:** opcode-identical skeleton to `CNDHash_FreeBuckets_009cb45c` (`0x004bcca0`); only reclaim + `operator_delete[]` relocs differ.

## Signature

```c
void __thiscall CNDHash_FreeBuckets_009cb450(CNDHash *this); // plain ret
```

## Callers / callees

| Direction | Symbol | VA / note |
|---|---|---|
| Caller | `CNDHash_Recreate_009cb450` | `0x004bcd06` (W30-G) |
| Caller | Dtor `FUN_004bd0b0` | `0x004bd0fe` (vtbl `009cb450`) |
| Callee | `FUN_004bcae0` | owning reclaim |
| Callee | `free` | slab @ IAT `0x009c6524` |
| Callee | `operator_delete[]` | bucket table `0x0048981c` |

## Family

| Sibling | Role |
|---|---|
| `CNDHash_Recreate_009cb450` `0x004bcce0` | Free → size → Alloc (W30-G) |
| `CNDHash_AllocBucketTable_009cb348` `0x004bc7a0` | alloc (W29-K) |
| `CNDHash_Ctor_009cb450` `0x004bce90` | ctor (W28-J) |
| `CNDHash_FreeBuckets_009cb45c` `0x004bcca0` | twin FreeBuckets (this dual) |
| Host always log2=5 | via Recreate consumer `FUN_004bbeb0` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004bcc60_FUN_004bcc60.md`
- Annotated: `docs/reconstruction/raw/aa_004bcc60_FUN_004bcc60.annotated.md`
- Clean scaffold: `docs/reconstruction/reconstructed-exact/FUN_004bcc60.cpp`
- Clean named: `docs/reconstruction/reconstructed-exact/CNDHash_FreeBuckets_009cb450.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_004bcc60_CNDHash_FreeBuckets_009cb450.md`
- Dual B: `docs/reconstruction/reviews/B_aa_004bcc60_CNDHash_FreeBuckets_009cb450.md`
- FUN_ record: `docs/reconstruction/functions/aa_004bcc60_FUN_004bcc60.md`
- Dual report: `docs/agents/task-dual-ab-004bcca0-004bcc60-w31m-report.md`

## Confidence

| Claim | Level |
|---|---|
| CF zero / reclaim / free table | **Confirmed** |
| Twin reloc-only vs `004bcca0` | **Confirmed** |
| `__thiscall` plain ret | **Confirmed** |
| Two static callers | **Confirmed** |
| Role FreeBuckets + stamp qualifier | **High** |
| Product/PDB symbol | **Open** |
| Full reclaim value policy | **Open** (callee residual) |
| Runtime / bit-exact / diff | **Open** |
