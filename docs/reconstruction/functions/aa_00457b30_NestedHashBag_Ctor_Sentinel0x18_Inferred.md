# Function record: NestedHashBag_Ctor_Sentinel0x18_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00457b30` |
| **Canonical name** | `NestedHashBag_Ctor_Sentinel0x18_Inferred` |
| **Ghidra name** | `FUN_00457b30` |
| **Address** | `0x00457b30`–`0x00457b91` (**98 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | containers / NestedHashBag shell (sentinel 0x18) |
| **Wave** | W34-G OWN-ONLY dual 2026-07-29 |
| **Verdict** | **accept-with-gaps** |
| **Dual A/B** | `reviews/A_aa_00457b30_NestedHashBag_Ctor_Sentinel0x18_Inferred.md`, `reviews/B_aa_00457b30_NestedHashBag_Ctor_Sentinel0x18_Inferred.md` |

## Purpose

Placement NestedHash/HeadBag bag ctor using **0x18** circular sentinel (`FUN_00457c60` / W30-E), size 0, 9-bucket fill, flags 1/1. Host outer size **0x40** from sole caller; this unit writes core **0x28**.

## Related duals

| Unit | VA | Relation |
|---|---|---|
| `NestedHashBag_Ctor_Sentinel0x30_Inferred` | `0x004438c0` | same-wave twin, 0x30 sentinel |
| `StdList_AllocSentinel_0x18_Inferred` | `0x00457c60` | sentinel factory (W30-E) |
| `PtrVecShell_InitFill_Inferred` | `0x004646e0` | fill helper (W33-B) |
| Ass NestedHash / HeadBag | `0x00423cf0` / `0x00469db0` | 0x28 sentinel twins |
| `FUN_0073c810` | `0x0073c810` | sole caller (new 0x40) |

## Signature

```c
NestedHashBag_Sentinel0x18* NestedHashBag_Ctor_Sentinel0x18_Inferred(
    NestedHashBag_Sentinel0x18* self /*stack; RET 4*/);
```

## Artifacts

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00457b30_FUN_00457b30.md` |
| Annotated | `docs/reconstruction/raw/aa_00457b30_FUN_00457b30.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NestedHashBag_Ctor_Sentinel0x18_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00457b30.cpp` |
| Scaffold record | `docs/reconstruction/functions/aa_00457b30_FUN_00457b30.md` |

## Confidence

| Claim | Level |
|---|---|
| ABI / layout / CF | High |
| Sentinel 0x18 | High |
| Product English | Open |
