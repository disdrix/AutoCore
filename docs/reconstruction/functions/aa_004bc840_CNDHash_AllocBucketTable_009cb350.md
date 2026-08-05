# Function record: CNDHash_AllocBucketTable_009cb350

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bc840` |
| **Canonical name** | `CNDHash_AllocBucketTable_009cb350` |
| **Ghidra name** | `FUN_004bc840` |
| **Address** | `0x004bc840`–`0x004bc8d0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | container / CNDHash (COList hashA/hashB; sentinel stamp `009cb350`) |
| **Completion status** | **Dual A/B present** (2026-07-29 W29-K) — accept-with-gaps |
| **Name status** | Role + stamp inferred; fail-path string only |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

| Name | Status |
|---|---|
| `FUN_004bc840` | Ghidra scaffold |
| `Named_VOG_DEBUG_STOP_004bc840` | **Reject** as product id (assert string only) |
| `CNDHash_AllocBucketTable_009cb348` | Twin at `0x004bc7a0` — **do not merge** |
| `CNDHash_AllocBucketTable_009ce090` | Parallel medal family at `0x0051ba40` — **do not merge** |

## Purpose

Allocate a fresh bucket table for the COList hashA/hashB CNDHash family:

1. Gate `log2` at `this+0x1C` ∈ **[1,16]**
2. `N = *(this+0x08)` (power-of-two count pre-set by Recreate/ctor)
3. `table = new[](N*4)` → `this+0x10`
4. `slab = malloc(N*0xC)`; for each i: `table[i]=slab+i*0xC`, stamp **`009cb350`**, heads 0
5. `*(this+0x08) = N-1` (**count → mask**)

Bad log2 → `VOG_DEBUG_STOP` + throw `0x80004003`.

## Signature

```c
void __thiscall CNDHash_AllocBucketTable_009cb350(CNDHash *this); // plain ret or noreturn throw
```

## Callers / callees

| Direction | Symbol | VA / note |
|---|---|---|
| Caller | `CNDHash_Ctor_009cb45c` (`FUN_004bcf90`) | `0x004bcfea` |
| Caller | Recreate `FUN_004bcd40` | `0x004bcd8c` |
| Callee | `operator_new[]` | pointer table |
| Callee | `malloc` | sentinel slab (`IAT 0x009c6528`) |
| Callee | `FUN_007a4480` / `_CxxThrowException` | fail |

## Family

| Sibling | Role |
|---|---|
| `CNDHash_AllocBucketTable_009cb348` `0x004bc7a0` | twin Alloc (tableC; stamp `009cb348`) |
| `CNDHash_Ctor_009cb45c` `0x004bcf90` | ctor that hands off here (W28-J) |
| `FUN_004bcd40` | Recreate that sets N then calls here |
| `CNDHash_AllocBucketTable_009ce090` `0x0051ba40` | same pattern other stamp |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004bc840_FUN_004bc840.md`
- Annotated: `docs/reconstruction/raw/aa_004bc840_FUN_004bc840.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/CNDHash_AllocBucketTable_009cb350.cpp`
- Clean scaffold: `docs/reconstruction/reconstructed-exact/FUN_004bc840.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_004bc840_CNDHash_AllocBucketTable_009cb350.md`
- Dual B: `docs/reconstruction/reviews/B_aa_004bc840_CNDHash_AllocBucketTable_009cb350.md`
- FUN_ record: `docs/reconstruction/functions/aa_004bc840_FUN_004bc840.md`

## Confidence

| Claim | Level |
|---|---|
| Dual alloc table + 0xC slab | **Confirmed** |
| Post-condition mask = N−1 | **Confirmed** |
| log2 gate 1..16 | **Confirmed** |
| Sentinel stamp `009cb350` | **Confirmed** |
| Callers ctor + Recreate | **Confirmed** (2 xrefs) |
| Role AllocBucketTable | **High** |
| Product/PDB English | **Open** |
| Runtime / bit-exact / diff | **Open** |
