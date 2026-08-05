# Function record: Mem_FillDwordN_FromSrc_EaxEcxEdx

| Field | Value |
|---|---|
| **Stable ID** | `aa_00436ef0` |
| **Canonical name** | `Mem_FillDwordN_FromSrc_EaxEcxEdx` |
| **Ghidra name** | `FUN_00436ef0` |
| **Address** | `0x00436ef0`–`0x00436f06` (**23 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | stl-helpers / POD fill |
| **Wave** | W34-D OWN-ONLY dual 2026-07-29 |
| **Verdict** | **accept** |
| **Dual A/B** | `reviews/A_aa_00436ef0_Mem_FillDwordN_FromSrc_EaxEcxEdx.md`, `reviews/B_aa_00436ef0_Mem_FillDwordN_FromSrc_EaxEcxEdx.md` |

## Purpose

Null-safe dword fill-from-pointer helper on register ABI (EAX dest / ECX count / EDX src*). Closes the fill residual under `PtrVecShell_InitFill_Inferred`.

## Related duals

| Unit | VA | Relation |
|---|---|---|
| `PtrVecShell_InitFill_Inferred` | `0x004646e0` | primary sealed caller (W33-B) |
| `Mem_FillDwordN_ReturnEnd` | `0x004651d0` | related fill helper (different ABI) |
| `NestedHashBag_Ctor_Inferred` | `0x0044a0d0` | grandparent path via 004646e0 (this dual) |

## Signature

```c
// EAX=dest, ECX=count, EDX=src*; bare RET; leaf
void Mem_FillDwordN_FromSrc_EaxEcxEdx(uint32_t* dest, int count, uint32_t const* src);
```

## Artifacts

See `aa_00436ef0_FUN_00436ef0.md` for full paths and confidence table.
