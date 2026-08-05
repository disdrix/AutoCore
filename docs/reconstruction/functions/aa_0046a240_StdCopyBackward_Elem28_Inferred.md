# Function record: StdCopyBackward_Elem28_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0046a240` |
| **Canonical name** | `StdCopyBackward_Elem28_Inferred` |
| **Ghidra name** | `FUN_0046a240` |
| **Address** | `0x0046a240`–`0x0046a25d` (**30 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | stl-helpers / POD copy_backward (elem 0x1c) |
| **Wave** | W35-L OWN-ONLY dual 2026-07-29 |
| **Verdict** | **accept** |
| **Dual A/B** | `reviews/A_aa_0046a240_StdCopyBackward_Elem28_Inferred.md`, `reviews/B_aa_0046a240_StdCopyBackward_Elem28_Inferred.md` |

## Purpose

Leaf MSVC-style `copy_backward` for 28-byte POD. Closes the reverse-move residual under elem-28 insert-n duals (W34-P/Q).

## Related duals

| Unit | VA | Relation |
|---|---|---|
| `StdVector_InsertN_Pod28` | `0x0045cd30` | parent mid-arm (W34-P) |
| `StdVector_InsertN_Elem28_CountEcx_Inferred` | `0x00466ea0` | parent mid-arm (W34-Q) |
| `StdVector_InsertN_Elem28_ValueEdx_Inferred` | `0x00469f50` | parent mid-arm (W34-Q) |
| `StdUninitFillN_Elem28_CountEax_Inferred` | `0x0045f150` | fill-n peer (this dual) |
| `BasicString_CopyBackward_Thunk_0x1c` | `0x00431480` | string-aware sibling family (W33-I) |

## Signature

```c
// EAX=dest_end*, EDX=src_end*, EBX=src_begin*; bare RET; leaf
void StdCopyBackward_Elem28_Inferred(
    Elem28* dest_end, Elem28* src_end, const Elem28* src_begin);
```

## Artifacts

See `aa_0046a240_FUN_0046a240.md` for full paths and confidence table.
