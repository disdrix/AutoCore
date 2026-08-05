# Function record: CNDHash_ReclaimToFreelist_009cb450

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bcae0` |
| **Canonical name** | `CNDHash_ReclaimToFreelist_009cb450` |
| **Ghidra name** | `FUN_004bcae0` |
| **Address** | `0x004bcae0`–`0x004bcb3e` inclusive (**95 B** / `0x5F`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | container / CNDHash tableC (`009cb450`) |
| **Completion status** | Dual A/B sealed W37-G 2026-08-04 — **accept** |
| **Dual** | `reviews/A_aa_004bcae0_CNDHash_ReclaimToFreelist_009cb450.md`, `B_*` |

## Purpose

Iterate buckets `0…mask` inclusive; for each live node: stamp `PTR_FUN_009cb358`, destroy owned value via vtbl(1) at `node+0x08`, push node onto freelist `hash+0x20`, then clear the bucket chain head. Sole reclaim callee of `CNDHash_FreeBuckets_009cb450`.

## Signature

```c
void __fastcall CNDHash_ReclaimToFreelist_009cb450(void *hash /*ECX*/);
// plain ret; void
```

## Node layout (this family)

| Off | Field |
|----:|---|
| `+0x00` | stamp then freelist next |
| `+0x08` | value* (owned) |
| `+0x0C` | bucket next |

## Related (not owned)

| VA | Role |
|---|---|
| `0x004bcc60` | FreeBuckets parent (W31-M) |
| `0x004e2bd0` | twin reclaim family `009cb45c` (W37-J) |
| `0x004bcca0` | FreeBuckets twin (W31-M) |
| `0x00413ea0` | older-family ReleaseNodesToFreelist pattern |
