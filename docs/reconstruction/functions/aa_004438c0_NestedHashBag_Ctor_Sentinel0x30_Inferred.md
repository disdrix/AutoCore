# Function record: NestedHashBag_Ctor_Sentinel0x30_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004438c0` |
| **Canonical name** | `NestedHashBag_Ctor_Sentinel0x30_Inferred` |
| **Ghidra name** | `FUN_004438c0` |
| **Address** | `0x004438c0`–`0x00443921` (**98 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | containers / NestedHashBag shell (sentinel 0x30) |
| **Wave** | W34-G OWN-ONLY dual 2026-07-29 |
| **Verdict** | **accept-with-gaps** |
| **Dual A/B** | `reviews/A_aa_004438c0_NestedHashBag_Ctor_Sentinel0x30_Inferred.md`, `reviews/B_aa_004438c0_NestedHashBag_Ctor_Sentinel0x30_Inferred.md` |

## Purpose

Placement constructor for NestedHash/HeadBag bag using **0x30** circular sentinel (`FUN_005b43b0`), size 0, 9-bucket pointer fill (`FUN_004646e0`), flags 1/1. Same layout shape as Ass NestedHash/HeadBag; different sentinel node size.

## Related duals

| Unit | VA | Relation |
|---|---|---|
| `AssResolverA_NestedHash_Ctor_Inferred` | `0x00423cf0` | same bag shape, 0x28 sentinel |
| `AssResolverCore_HeadBag_Ctor_Inferred` | `0x00469db0` | same bag shape, 0x28 sentinel |
| `NestedHashBag_Ctor_Sentinel0x18_Inferred` | `0x00457b30` | same wave twin, 0x18 sentinel |
| `PtrVecShell_InitFill_Inferred` | `0x004646e0` | shared fill helper (W33-B) |
| `FUN_005b43b0` | `0x005b43b0` | 0x30 sentinel factory (unowned) |
| `FUN_00754ee0` | `0x00754ee0` | sole caller (host +0x44) |

## Signature

```c
NestedHashBag_Sentinel0x30* NestedHashBag_Ctor_Sentinel0x30_Inferred(
    NestedHashBag_Sentinel0x30* self /*stack; RET 4*/);
```

## Artifacts

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004438c0_FUN_004438c0.md` |
| Annotated | `docs/reconstruction/raw/aa_004438c0_FUN_004438c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NestedHashBag_Ctor_Sentinel0x30_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004438c0.cpp` |
| Scaffold record | `docs/reconstruction/functions/aa_004438c0_FUN_004438c0.md` |

## Confidence

| Claim | Level |
|---|---|
| ABI stack this* / RET 4 / return this | High |
| Layout +8/+0c/+10..+24 | High |
| Sentinel node 0x30 | High |
| Product English of host / flags | Open / Med |
