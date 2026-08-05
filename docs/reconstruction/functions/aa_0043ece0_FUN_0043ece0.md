# Function record: FUN_0043ece0 / Pod8_CopyIfNonNull

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043ece0` |
| **Canonical name** | `Pod8_CopyIfNonNull` (**Inferred**) |
| **Ghidra name** | `FUN_0043ece0` |
| **Address** | `0x0043ece0` |
| **Body range** | `0x0043ece0`–`0x0043ecee` (**15 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | POD store / GuardedVector stride-2 helpers |
| **Completion status** | **partial** — dual A/B **accept**; CF + bytes sealed; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_0043ece0_Pod8_CopyIfNonNull.md`, `reviews/B_aa_0043ece0_Pod8_CopyIfNonNull.md` (2026-07-29 W32-M) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_0043ece0`
- `PodU32x2_CopyIfNonNull`
- `Named_CalleeOf_Named_CalleeOf_Named_assPreloader_0043ece0` (legacy scaffold)

## Purpose

Null-safe copy of an 8-byte POD (`uint32_t` × 2) from `src` to `dest`. Used as the store helper for `GuardedVector_PushBack_Stride2_U32x2` when the slot base may be null.

## Signature

```c
// EAX=dest (nullable); ECX=const PodU32x2* src; bare RET
void Pod8_CopyIfNonNull(PodU32x2* dest /*EAX*/, const PodU32x2* src /*ECX*/);
```

## Algorithm

1. If `dest == nullptr`, return without writing.
2. `dest[0] = src[0]`; `dest[1] = src[1]` (two dwords).
3. Return.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0043ece0_FUN_0043ece0.md`
- Annotated: `docs/reconstruction/raw/aa_0043ece0_FUN_0043ece0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Pod8_CopyIfNonNull.cpp`
- Alias clean: `docs/reconstruction/reconstructed-exact/FUN_0043ece0.cpp`
- Named record: `docs/reconstruction/functions/aa_0043ece0_Pod8_CopyIfNonNull.md`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-0043ece0-0043ea50-w32m-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | none (leaf) |
| **Callers (1)** | `FUN_0043e970` / `GuardedVector_PushBack_Stride2_U32x2` @ `0x0043e9cf` |

## Confidence

| Claim | Level |
|---|---|
| Control flow + bytes | **High** |
| EAX dest + ECX src + bare RET | **High** |
| Null-safe two-dword store | **High** |
| Product English name | **Inferred** |
| Runtime / differential | Open |

## Related

- `aa_0043ecf0` — null-safe u32+u8 contiguous store (W32-N)
- `aa_0043e970` — sole push_back parent (W31-J)
- `aa_0043ea50` — split-source u32+u8 store, no null gate (this dual pair)
