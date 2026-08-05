# Function record: FUN_005ae2b0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ae2b0` |
| **Canonical name** | `FUN_005ae2b0` |
| **Structural name** | `StdTree_AllocNode_0x1c_Inferred` |
| **Address** | `0x005ae2b0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | util / container (MSVC `_Tree` / map) |
| **Completion status** | **Dual sealed** (A+B W16-G, 2026-07-29) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Human / structural: `StdTree_AllocNode_0x1c_Inferred`
- Prior scaffold alias: `Named_CalleeOf_Named_effDeviceEffect_005ae2b0` (one of many callers; name too narrow)

## Purpose

Allocate and partially init a **0x1C-byte** tree node: zero left/parent/right, set color=1 at `+0x18`, isnil=0 at `+0x19`. Callers that need a map **head/sentinel** flip isnil to 1 and self-link the three pointers; size field lives on the map host, not here.

## Signature (caller-sealed)

```c
// Ghidra: void FUN_005ae2b0(void)  — incorrect return type
void *FUN_005ae2b0(void);  // EAX = node* (0x1C)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005ae2b0_FUN_005ae2b0.md`
- Annotated: `docs/reconstruction/raw/aa_005ae2b0_FUN_005ae2b0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_005ae2b0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_005ae2b0_StdTree_AllocNode_0x1c_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_005ae2b0_StdTree_AllocNode_0x1c_Inferred.md`

## Callers / callees

| Direction | Symbol | Notes |
|---|---|---|
| Callee | `operator_new` | size `0x1C` |
| Caller | `InventoryGrid_ctor_Inferred` | head @ `this+0x60` |
| Caller | `Skill_GetCategoryCooldownMap` | lazy map @ owner+0x6c |
| Caller | `FUN_004e7420` | map object ctor pattern |
| Caller | `FUN_005adb20`, `FUN_00572ab0`, `FUN_005e12b0`, `FUN_0046e310`, `FUN_00536920`, `FUN_00750260`, `FUN_0075d470`, `FUN_00970cf0`, `FUN_0098ef00` | additional xrefs |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler ≡ raw ≡ live | **High** |
| Size 0x1C; color@+0x18; isnil@+0x19 | **Confirmed** (bytes) |
| EAX return used by callers | **Confirmed** |
| Tree head factory role (with caller post-init) | **High** |
| Value payload exact type | **Open** (12-byte middle; caller-specific) |
| Product name | **Open** (`_Inferred`) |
