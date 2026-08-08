# Function record: FUN_004cb2c0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cb2c0` |
| **Canonical name** | `FUN_004cb2c0` (scaffold); dual-named **`StdTree_Min_Isnil21_Inferred`** |
| **Address** | `0x004cb2c0` |
| **Body** | `0x004cb2c0`–`0x004cb2da` inclusive (**27 B** / `0x1b`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC `std::_Tree` min / leftmost (isnil @ +0x21) |
| **Completion status** | **Dual-reviewed** R13-002 — **accept** |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Partition** | `WAVE_2026-08-05_r13_residual_partition_map.md` → **R13-002** |

## Purpose

Return leftmost non-nil node in subtree (MSVC `_Tree_min`). isnil flag at `+0x21`. Stack-arg ABI (`[esp+4]`); EAX return. Callers: seven isnil21 map erase plates recomputing head leftmost (including parent `FUN_00405650`).

## Signature (sealed)

```c
// stack arg node*; returns node* in EAX; bare RET
void *FUN_004cb2c0(void *node /*[esp+4]*/);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004cb2c0_FUN_004cb2c0.md`
- Annotated: `docs/reconstruction/raw/aa_004cb2c0_FUN_004cb2c0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_Min_Isnil21_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_004cb2c0.cpp`
- Named record: `docs/reconstruction/functions/aa_004cb2c0_StdTree_Min_Isnil21_Inferred.md`
- Review A/B: `docs/reconstruction/reviews/A_aa_004cb2c0_StdTree_Min_Isnil21_Inferred.md`, `B_aa_004cb2c0_StdTree_Min_Isnil21_Inferred.md`

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `FUN_00405650` @ `0x0040571a`; `FUN_004e3e70` @ `0x004e3f5f`; `FUN_00511c00` @ `0x00511cec`; `FUN_0059d300` @ `0x0059d3ec`; `FUN_005a2ea0` @ `0x005a2f8f`; `FUN_005a4590` @ `0x005a467c`; `FUN_005ae6d0` @ `0x005ae7bf` (7 UNCONDITIONAL_CALL) |
| Callees | none (leaf) |

## Confidence

| Claim | Level |
|---|---|
| Control flow from bytes | **High** |
| Stack-arg / EAX-out ABI | **High** |
| isnil +0x21 | **High** |
| Product map English | **Open** (role sealed) |
| Runtime | **Open** |
