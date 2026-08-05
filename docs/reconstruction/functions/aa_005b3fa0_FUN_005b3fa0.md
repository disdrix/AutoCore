# Function record: FUN_005b3fa0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b3fa0` |
| **Canonical name** | `FUN_005b3fa0` (scaffold) |
| **Preferred name** | `Obj_PopulateListAt10_ScaledGridFill_Inferred` |
| **Ghidra name** | `FUN_005b3fa0` |
| **Address** | `0x005b3fa0` |
| **Body range** | `0x005b3fa0`–`0x005b4255` exclusive (**693** B / `0x2B5`); pad `CC` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | host object / list populate worker |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF + bytes + ABI + callers sealed; product class open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_005b3fa0_Obj_PopulateListAt10_ScaledGridFill_Inferred.md`, `reviews/B_aa_005b3fa0_Obj_PopulateListAt10_ScaledGridFill_Inferred.md` (2026-08-04 W37-L) |
| **Last reviewed** | `2026-08-04` |

## Alias

- `Obj_PopulateListAt10_ScaledGridFill_Inferred`
- Role: populate embedded list at `+0x10` with scaled grid nodes after empty ctor

## Purpose

Given a non-null context object, store dimension floats on the 0x30 host, lock a path-derived gfxBody asset, and fill the list at `this+0x10` with `ROUND(dim*scale)` nested grid nodes. Return 1/0.

## Signature

```c
uint32_t __thiscall FUN_005b3fa0(
    void *self,
    float dim_a, float dim_b, float dim_c,
    float scale, void *ctx);
// ECX = this; ret 0x14; EAX/AL status
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005b3fa0_FUN_005b3fa0.md`
- Annotated: `docs/reconstruction/raw/aa_005b3fa0_FUN_005b3fa0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Obj_PopulateListAt10_ScaledGridFill_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_005b3fa0.cpp`
- Named record: `docs/reconstruction/functions/aa_005b3fa0_Obj_PopulateListAt10_ScaledGridFill_Inferred.md`
- Report: `docs/agents/task-dual-ab-005b3fa0-0075bf40-w37l-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_004f1e20`, `FUN_00764030`, `FUN_004eb1c0`, `FUN_00764830`, `FUN_00763f60`, `FUN_005b4470`, `FUN_005b43d0`, `FUN_004eb010` |
| **Callers** | `FUN_004cd8f0` @ `0x004cd97a`; `FUN_005b4260` @ `0x005b42cc` |

## Confidence

| Claim | Level |
|---|---|
| ABI thiscall + ret 0x14 + status 1/0 | **High** |
| Float store order + null ctx gate | **High** |
| List insert at +0x10 / node 0x30 | **High** |
| 0.5f half-step constant | **High** |
| Product class English | **Open** |
| Runtime / differential | Open |
