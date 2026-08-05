# Function record: FUN_0044fee0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0044fee0` |
| **Canonical name** | `FUN_0044fee0` |
| **Named (Inferred)** | `NestedHash0x10_StaticOnceGet_d1fcc0_Inferred` |
| **Address** | `0x0044fee0` |
| **Body** | `0x0044fee0`–`0x0044ff39` (**90 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | NestedHash static once-get |
| **Completion status** | **Dual A/B complete** (2026-07-29 W35-E) — **accept** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |
| **Ghidra name** | `FUN_0044fee0` |

## Alias

- **Accept:** `NestedHash0x10_StaticOnceGet_d1fcc0_Inferred`
- **Reject:** `Named_CalleeOf_Named_CalleeOf_Named_anmTrackEvents_0044fee0`

## Purpose

One-shot initialize static NestedHash (sentinel node **0x10**) at `DAT_00d1fcc0`, register `atexit(LAB_009c34b0)`, return `&DAT_00d1fcc0`.

## Signature

```c
void *NestedHash0x10_StaticOnceGet_d1fcc0_Inferred(void);
// alias: void *FUN_0044fee0(void);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0044fee0_FUN_0044fee0.md`
- Annotated: `docs/reconstruction/raw/aa_0044fee0_FUN_0044fee0.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/NestedHash0x10_StaticOnceGet_d1fcc0_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0044fee0.cpp`
- Named record: `docs/reconstruction/functions/aa_0044fee0_NestedHash0x10_StaticOnceGet_d1fcc0_Inferred.md`
- Dual A: `docs/reconstruction/reviews/A_aa_0044fee0_NestedHash0x10_StaticOnceGet_d1fcc0_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0044fee0_NestedHash0x10_StaticOnceGet_d1fcc0_Inferred.md`

## Callers / callees

| Direction | Symbol | Role |
|---|---|---|
| Caller | `FUN_0044fe10` @ `0x0044fe1f`, `0x0044fe33` | bag lookup via `*(get()+8)` sentinel |
| Callee | `FUN_00457ac0` | NestedHash_Ctor_Sentinel0x10_Inferred |
| Callee | `_atexit` | teardown |
| Data | `DAT_00d1fcc0` / `DAT_00d1fce8` / `LAB_009c34b0` | static + flag + dtor |

## Confidence

| Claim | Level |
|---|---|
| Control flow / once-flag / return | **High** / Confirmed |
| Ctor = NestedHash0x10 (W34-E) | **High** |
| Product English for this static | Open |
| Dual review | Present |
