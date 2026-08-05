# Function record: CNDHash_ReclaimAll_NonOwning_009cefdc

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053b8c0` |
| **Canonical name** | `CNDHash_ReclaimAll_NonOwning_009cefdc` (Ghidra `FUN_0053b8c0`; **Inferred**) |
| **Address** | `0x0053b8c0` |
| **Body** | `0x0053b8c0`–`0x0053b8ff` (**`ret`**, 64 B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | container / CNDHash (node stamp `009cefdc`, FreeBuckets family `009cfa70`) |
| **Completion status** | **Dual sealed 2026-07-29 W19-L** — accept |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

**Non-owning full-bucket reclaim** for CNDHash family using node stamp `PTR_LAB_009cefdc`:

1. For `bucketIndex = 0 .. this->mask(+0x08)` **inclusive**:
2. Walk collision chain at `table[i]->head (+4)`.
3. For each node: stamp vtbl `009cefdc`; freelist-push via `this+0x20` (vtbl slot becomes freelist next). **No** value delete; **no** value zero.
4. Clear bucket head to 0.

Does **not** zero `count(+0x0c)` or free table `+0x10`.

Sole direct caller: `CNDHash_FreeBuckets_NonOwning_009cfa70` (`0x0053b880`).

## Signature (sealed)

```c
// void __fastcall / __thiscall — bare ret
void CNDHash_ReclaimAll_NonOwning_009cefdc(void *thisHash);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0053b8c0_FUN_0053b8c0.md`
- Annotated: `docs/reconstruction/raw/aa_0053b8c0_FUN_0053b8c0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CNDHash_ReclaimAll_NonOwning_009cefdc.cpp`
- Clean (FUN alias): `docs/reconstruction/reconstructed-exact/FUN_0053b8c0.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_0053b8c0_CNDHash_ReclaimAll_NonOwning_009cefdc.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0053b8c0_CNDHash_ReclaimAll_NonOwning_009cefdc.md`

## Callers / callees

| Direction | Symbol | VA | Role |
|---|---|---|---|
| Caller | `CNDHash_FreeBuckets_NonOwning_009cfa70` | `0x0053b880` site `0x0053b88a` | count=0 + reclaim + free table |
| Callee | *(none)* | — | leaf; freelist only |

## Confidence

| Claim | Level |
|---|---|
| Non-owning (no value free) | **Confirmed** |
| Stamp imm `009cefdc` | **Confirmed** |
| Inclusive mask `i <= +0x08` | **Confirmed** |
| Freelist `+0x20` | **Confirmed** |
| Sole static caller FreeBuckets `0053b880` | **Confirmed** |
| Product English name | **Open** |
| Runtime / bit-exact | **Open** |
