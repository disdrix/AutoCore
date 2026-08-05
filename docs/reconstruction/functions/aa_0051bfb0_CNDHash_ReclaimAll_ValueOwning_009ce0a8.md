# Function record: CNDHash_ReclaimAll_ValueOwning_009ce0a8

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051bfb0` |
| **Canonical name** | `CNDHash_ReclaimAll_ValueOwning_009ce0a8` |
| **Ghidra name** | `FUN_0051bfb0` |
| **Address** | `0x0051bfb0`–`0x0051c021` (**0x72** bytes) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | container / CNDHash (medal family; node stamp `009ce0a8`) |
| **Completion status** | **Dual A/B present** (2026-07-29 W25-F) — accept-with-gaps |
| **Name status** | Role + stamp inferred; no body string |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

| Name | Status |
|---|---|
| `FUN_0051bfb0` | Ghidra scaffold |
| `Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_0051bfb0` | **Reject** as product id |

## Purpose

Owning full-bucket reclaim for CNDHash instances whose nodes stamp `PTR_FUN_009ce0a8`:

1. For `bucketIndex = 0 .. this->mask(+0x08)` **inclusive**
2. Walk collision chain at `table[i]->head (+4)`
3. Per node: stamp `009ce0a8`; if `node+0x08` non-null → **`FUN_00604e30(value)`** (nested field teardown) then **`operator_delete(value)`**; clear value; push freelist `this+0x20`
4. Clear bucket head to 0

Does **not** zero `count(+0x0C)`, free table `+0x10`, free freelist storage, or call virtual node dtor.

## Signature

```c
void __thiscall CNDHash_ReclaimAll_ValueOwning_009ce0a8(CNDHash *this); // plain ret
```

## Callers / callees

| Direction | Symbol | VA / note |
|---|---|---|
| Caller | `CNDHash_FreeBuckets` (`FUN_0051d150`) | `0x0051d15a` (sole xref) |
| Callee | `FUN_00604e30` | nested value clear (residual) |
| Callee | `operator_delete` | value free (returns) |

## Family

| Sibling | Role |
|---|---|
| `CNDHash_FreeBuckets` `0x0051d150` | count=0 → this → free slab/table |
| `CNDHash_AllocBucketTable_009ce090` `0x0051ba40` | alloc twin |
| `CNDHash_ReclaimAll_ValueOwning_009cefec` `0x00538200` | plain delete (no nested helper) |
| `CNDHash_Insert_009ce0a8` | insert on same node stamp |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0051bfb0_FUN_0051bfb0.md`
- Annotated: `docs/reconstruction/raw/aa_0051bfb0_FUN_0051bfb0.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/CNDHash_ReclaimAll_ValueOwning_009ce0a8.cpp`
- Clean scaffold: `docs/reconstruction/reconstructed-exact/FUN_0051bfb0.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_0051bfb0_CNDHash_ReclaimAll_ValueOwning_009ce0a8.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0051bfb0_CNDHash_ReclaimAll_ValueOwning_009ce0a8.md`
- FUN_ record: `docs/reconstruction/functions/aa_0051bfb0_FUN_0051bfb0.md`

## Confidence

| Claim | Level |
|---|---|
| CF walk / stamp / freelist / clear heads | **Confirmed** |
| Inclusive `0..mask` loop | **Confirmed** |
| Nested `FUN_00604e30` before delete | **Confirmed** (bytes `MOV ECX,EBX; CALL`) |
| `operator_delete` returns | **Confirmed** |
| Sole caller FreeBuckets | **Confirmed** (1 xref) |
| Role ReclaimAll value-owning | **High** |
| Product/PDB symbol | **Open** |
| Exact value type fields | **Open** (residual) |
| Runtime / bit-exact / diff | **Open** |
