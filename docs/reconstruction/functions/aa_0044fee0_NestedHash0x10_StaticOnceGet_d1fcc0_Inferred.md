# Function record: NestedHash0x10_StaticOnceGet_d1fcc0_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0044fee0` |
| **Canonical name** | `NestedHash0x10_StaticOnceGet_d1fcc0_Inferred` |
| **Address** | `0x0044fee0` |
| **Body** | `0x0044fee0`–`0x0044ff39` (**90 B** / `0x5A`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | NestedHash static once-get |
| **Completion status** | **Dual A/B complete** (2026-07-29 W35-E) — **accept** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |
| **Ghidra name** | `FUN_0044fee0` |

## Purpose

One-shot factory for the static NestedHash bag at `DAT_00d1fcc0` (sentinel nodes **0x10**, shell span **0x28**). Registers process teardown via `atexit(LAB_009c34b0)`. Twin of `FUN_00438c40` / `FUN_00438ca0` once-gets for sibling statics.

## Signature

```c
void *NestedHash0x10_StaticOnceGet_d1fcc0_Inferred(void);
```

| Slot | Source | Conf |
|---|---|---|
| return | `MOV EAX, &DAT_00d1fcc0` | **High** |
| formals | none | **High** |
| cleanup | `ADD ESP,0xC; RET` | **High** |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0044fee0_FUN_0044fee0.md`
- Annotated: `docs/reconstruction/raw/aa_0044fee0_FUN_0044fee0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/NestedHash0x10_StaticOnceGet_d1fcc0_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0044fee0.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_0044fee0_FUN_0044fee0.md`
- Dual A: `docs/reconstruction/reviews/A_aa_0044fee0_NestedHash0x10_StaticOnceGet_d1fcc0_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0044fee0_NestedHash0x10_StaticOnceGet_d1fcc0_Inferred.md`

## Callers / callees

| Direction | Symbol | Role |
|---|---|---|
| Caller (sole fn) | `FUN_0044fe10` ×2 | NestedHash sentinel compare / vcall |
| Callee | `NestedHash_Ctor_Sentinel0x10_Inferred` (`0x00457ac0`) | placement ctor |
| Callee | `_atexit` | process teardown |
| Data | `LAB_009c34b0` | atexit destructor thunk |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler ≡ bytes | **High** |
| Static NestedHash0x10 role | **High** (W34-E ctor + layout) |
| Product plate English | Open |
| Dual review | Present |
