# Function record: StdTree_OperatorIndex_Val12_U32Key_EdiEdx_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043d570` |
| **Canonical name** | `StdTree_OperatorIndex_Val12_U32Key_EdiEdx_Inferred` |
| **Ghidra name** | `FUN_0043d570` |
| **Address** | `0x0043d570` |
| **Body range** | `0x0043d570`–`0x0043d5e0` exclusive (**112** B / `0x70`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | std red-black map operator[] / get-or-insert (Val12, u32 key, EDI map / EDX key*) |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual A/B** | `reviews/A_aa_0043d570_StdTree_OperatorIndex_Val12_U32Key_EdiEdx_Inferred.md`, `reviews/B_aa_0043d570_StdTree_OperatorIndex_Val12_U32Key_EdiEdx_Inferred.md` |
| **Last reviewed** | `2026-08-04` (W38-A) |

## Purpose

Val12 **operator[]** get-or-insert: unsigned u32 key lower_bound + equality gate; hit returns mapped@+0x10; miss inserts `{key,0,0}`.

## Signature

```c
int32_t* StdTree_OperatorIndex_Val12_U32Key_EdiEdx_Inferred(
    MapShell_Val12* map /*EDI*/,
    const uint32_t* key /*EDX*/);
// plain RET; returns &node->val1
```

## Artifacts

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043d570_FUN_0043d570.md` |
| Annotated | `docs/reconstruction/raw/aa_0043d570_FUN_0043d570.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_OperatorIndex_Val12_U32Key_EdiEdx_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0043d570.cpp` |
| FUN record | `docs/reconstruction/functions/aa_0043d570_FUN_0043d570.md` |
| Review A/B | as above |

## See also

Primary record: `docs/reconstruction/functions/aa_0043d570_FUN_0043d570.md`
