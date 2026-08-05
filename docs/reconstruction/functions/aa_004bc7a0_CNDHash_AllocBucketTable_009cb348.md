# Function record: CNDHash_AllocBucketTable_009cb348

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bc7a0` |
| **Canonical name** | `CNDHash_AllocBucketTable_009cb348` |
| **Ghidra name** | `FUN_004bc7a0` |
| **Address** | `0x004bc7a0`–`0x004bc830` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | container / CNDHash (COList tableC; sentinel stamp `009cb348`) |
| **Completion status** | **Dual A/B present** (2026-07-29 W29-K) — accept-with-gaps |
| **Name status** | Role + stamp inferred; fail-path string only |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

| Name | Status |
|---|---|
| `FUN_004bc7a0` | Ghidra scaffold |
| `Named_VOG_DEBUG_STOP_004bc7a0` | **Reject** as product id (assert string only) |
| `CNDHash_AllocBucketTable_009cb350` | Twin at `0x004bc840` — **do not merge** |
| `CNDHash_AllocBucketTable_009ce090` | Parallel medal family at `0x0051ba40` — **do not merge** |

## Purpose

Allocate a fresh bucket table for the COList tableC CNDHash family:

1. Gate `log2` at `this+0x1C` ∈ **[1,16]**
2. `N = *(this+0x08)` (power-of-two count pre-set by Recreate/ctor)
3. `table = new[](N*4)` → `this+0x10`
4. `slab = malloc(N*0xC)`; for each i: `table[i]=slab+i*0xC`, stamp **`009cb348`**, heads 0
5. `*(this+0x08) = N-1` (**count → mask**)

Bad log2 → `VOG_DEBUG_STOP` + throw `0x80004003`.

## Signature

```c
void __thiscall CNDHash_AllocBucketTable_009cb348(CNDHash *this); // plain ret or noreturn throw
```

## Callers / callees

| Direction | Symbol | VA / note |
|---|---|---|
| Caller | `CNDHash_Ctor_009cb450` (`FUN_004bce90`) | `0x004bceea` |
| Caller | Recreate `FUN_004bcce0` | `0x004bcd2c` |
| Callee | `operator_new[]` | pointer table |
| Callee | `malloc` | sentinel slab (`IAT 0x009c6528`) |
| Callee | `FUN_007a4480` / `_CxxThrowException` | fail |

## Family

| Sibling | Role |
|---|---|
| `CNDHash_AllocBucketTable_009cb350` `0x004bc840` | twin Alloc (hashA/B; stamp `009cb350`) |
| `CNDHash_Ctor_009cb450` `0x004bce90` | ctor that hands off here (W28-J) |
| `FUN_004bcce0` | Recreate that sets N then calls here |
| `CNDHash_AllocBucketTable_009ce090` `0x0051ba40` | same pattern other stamp |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004bc7a0_FUN_004bc7a0.md`
- Annotated: `docs/reconstruction/raw/aa_004bc7a0_FUN_004bc7a0.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/CNDHash_AllocBucketTable_009cb348.cpp`
- Clean scaffold: `docs/reconstruction/reconstructed-exact/FUN_004bc7a0.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_004bc7a0_CNDHash_AllocBucketTable_009cb348.md`
- Dual B: `docs/reconstruction/reviews/B_aa_004bc7a0_CNDHash_AllocBucketTable_009cb348.md`
- FUN_ record: `docs/reconstruction/functions/aa_004bc7a0_FUN_004bc7a0.md`

## Confidence

| Claim | Level |
|---|---|
| Dual alloc table + 0xC slab | **Confirmed** |
| Post-condition mask = N−1 | **Confirmed** |
| log2 gate 1..16 | **Confirmed** |
| Sentinel stamp `009cb348` | **Confirmed** |
| Callers ctor + Recreate | **Confirmed** (2 xrefs) |
| Role AllocBucketTable | **High** |
| Product/PDB English | **Open** |
| Runtime / bit-exact / diff | **Open** |
