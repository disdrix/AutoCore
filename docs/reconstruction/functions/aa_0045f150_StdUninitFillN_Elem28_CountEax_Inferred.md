# Function record: StdUninitFillN_Elem28_CountEax_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0045f150` |
| **Canonical name** | `StdUninitFillN_Elem28_CountEax_Inferred` |
| **Ghidra name** | `FUN_0045f150` |
| **Address** | `0x0045f150`–`0x0045f198` (**73 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | stl-helpers / POD uninit fill-n (elem 0x1c) |
| **Wave** | W35-L OWN-ONLY dual 2026-07-29 |
| **Verdict** | **accept** |
| **Dual A/B** | `reviews/A_aa_0045f150_StdUninitFillN_Elem28_CountEax_Inferred.md`, `reviews/B_aa_0045f150_StdUninitFillN_Elem28_CountEax_Inferred.md` |

## Purpose

Null-safe uninit fill-n for 28-byte POD on register ABI (EAX count / ECX template* / EDX dest*). Closes the fill residual under `StdVector_InsertN_Pod28` (W34-P).

## Related duals

| Unit | VA | Relation |
|---|---|---|
| `StdVector_InsertN_Pod28` | `0x0045cd30` | sole parent (W34-P) |
| `StdCopyBackward_Elem28_Inferred` | `0x0046a240` | mid-shift peer (this dual) |
| `FUN_0046a260` | `0x0046a260` | sibling fill-n, different ABI |
| `Mem_FillDwordN_FromSrc_EaxEcxEdx` | `0x00436ef0` | dword-stride null-safe fill cousin |

## Signature

```c
// EAX=count, ECX=template*, EDX=dest*; bare RET; leaf
void StdUninitFillN_Elem28_CountEax_Inferred(
    uint32_t count, const Elem28* tmpl, Elem28* dest);
```

## Artifacts

See `aa_0045f150_FUN_0045f150.md` for full paths and confidence table.
