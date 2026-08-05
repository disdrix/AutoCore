# Function record: CNDHash_AllocBucketTable_009ce090

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051ba40` |
| **Canonical name** | `CNDHash_AllocBucketTable_009ce090` |
| **Ghidra name** | `FUN_0051ba40` |
| **Address** | `0x0051ba40`–`0x0051bad0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | container / CNDHash (medal family; sentinel stamp `009ce090`) |
| **Completion status** | **Dual A/B present** (2026-07-29 W25-F) — accept-with-gaps |
| **Name status** | Role + stamp inferred; fail-path string only |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

| Name | Status |
|---|---|
| `FUN_0051ba40` | Ghidra scaffold |
| `Named_VOG_DEBUG_STOP_0051ba40` | **Reject** as product id (assert string only) |
| `CNDHash_AllocBucketTable_Inferred` | Parallel name family at `0x00413d80` (other stamp) — **do not merge** |

## Purpose

Allocate a fresh bucket table for the medal-family CNDHash:

1. Gate `log2` at `this+0x1C` ∈ **[1,16]**
2. `N = *(this+0x08)` (power-of-two count pre-set by Recreate/ctor)
3. `table = new[](N*4)` → `this+0x10`
4. `slab = malloc(N*0xC)`; for each i: `table[i]=slab+i*0xC`, stamp **`009ce090`**, heads 0
5. `*(this+0x08) = N-1` (**count → mask**)

Bad log2 → `VOG_DEBUG_STOP` + throw `0x80004003`.

## Signature

```c
void __thiscall CNDHash_AllocBucketTable_009ce090(CNDHash *this); // plain ret or noreturn throw
```

## Callers / callees

| Direction | Symbol | VA / note |
|---|---|---|
| Caller | `CNDHash_Recreate` (`FUN_0051d230`) | `0x0051d27c` |
| Caller | ctor `FUN_0051db60` | `0x0051dbba` |
| Callee | `operator_new[]` | pointer table |
| Callee | `malloc` | sentinel slab (`IAT 0x009c6528`) |
| Callee | `FUN_007a4480` / `_CxxThrowException` | fail |

## Family

| Sibling | Role |
|---|---|
| `CNDHash_FreeBuckets` `0x0051d150` | free twin (`free(*buckets)` + `delete[]`) |
| `CNDHash_ReclaimAll_ValueOwning_009ce0a8` `0x0051bfb0` | reclaim before free |
| `CNDHash_Recreate` `0x0051d230` | string-named parent |
| `CNDHash_AllocBucketTable_Inferred` `0x00413d80` | same pattern other stamp |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0051ba40_FUN_0051ba40.md`
- Annotated: `docs/reconstruction/raw/aa_0051ba40_FUN_0051ba40.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/CNDHash_AllocBucketTable_009ce090.cpp`
- Clean scaffold: `docs/reconstruction/reconstructed-exact/FUN_0051ba40.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_0051ba40_CNDHash_AllocBucketTable_009ce090.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0051ba40_CNDHash_AllocBucketTable_009ce090.md`
- FUN_ record: `docs/reconstruction/functions/aa_0051ba40_FUN_0051ba40.md`

## Confidence

| Claim | Level |
|---|---|
| Dual alloc table + 0xC slab | **Confirmed** |
| Post-condition mask = N−1 | **Confirmed** |
| log2 gate 1..16 | **Confirmed** |
| Sentinel stamp `009ce090` | **Confirmed** |
| Callers Recreate + ctor | **Confirmed** (2 xrefs) |
| Role AllocBucketTable | **High** |
| Product/PDB symbol | **Open** |
| Runtime / bit-exact / diff | **Open** |
