# Function record: AssPreloader_TryPreloadChildAssetsForAbsentKeys_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00971280` |
| **Canonical name** | `AssPreloader_TryPreloadChildAssetsForAbsentKeys_Inferred` |
| **Ghidra name** | `FUN_00971280` |
| **Address** | `0x00971280`–`0x00971472` (**498 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | assPreloader / asset preload pipeline |
| **Completion status** | Dual A/B sealed W32-J 2026-07-29 — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

For each parent key in a caller-supplied flat pointer range, if the key is **not** yet in the AssPreloader membership tree, try to preload a child asset via resource-listed children (`vtbl+0x0C`). Success enqueues a stride-2 pair and marks the tree; failure logs product PRELOAD text and records the key on the fail ring.

## Signature

```c
// stack (host*, key_vec*); RET 8; void
void AssPreloader_TryPreloadChildAssetsForAbsentKeys_Inferred(
    void* host /*stack*/,
    void* key_vec /*stack; +4 begin*, +8 end**/);
```

## Host offsets (sealed)

| Off | Role |
|-----|------|
| `+0x4C` | stride-2 result ring (`GuardedVector_PushBack_Stride2_U32x2` / `FUN_0043e970`) |
| `+0x60` / `+0x78` | CS + enable flag for `+0x4C` |
| `+0x7C` | fail key ring (`GuardedVector_PushBack_Thiscall` / `FUN_0043d670`) |
| `+0x90` / `+0xA8` | CS + enable flag for `+0x7C` |
| `+0xDC` / `+0xE0` | membership tree base / end header |
| `+0x110` | resource object; child source at `*(+0x110)+0x28` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00971280_FUN_00971280.md`
- Annotated: `docs/reconstruction/raw/aa_00971280_FUN_00971280.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/AssPreloader_TryPreloadChildAssetsForAbsentKeys_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00971280.cpp`
- FUN record: `docs/reconstruction/functions/aa_00971280_FUN_00971280.md`
- Review A/B: `docs/reconstruction/reviews/A_aa_00971280_AssPreloader_TryPreloadChildAssetsForAbsentKeys_Inferred.md`, `B_…`
- Agent report: `docs/agents/task-dual-ab-00971280-009717a0-w32j-report.md`

## Confidence

| Claim | Level |
|---|---|
| CF + ABI (RET 8, two stack args) + host offsets | **High** |
| Absent-tree gate via `+0xE0` end header | **High** |
| AssPreloader product family (`assPreloader.cpp` string) | **High** (family) / **Inferred** (exact method English) |
| Nested drain / child vtbl / cache product types | **Open** |
| Runtime / bit-exact | **Open** |
