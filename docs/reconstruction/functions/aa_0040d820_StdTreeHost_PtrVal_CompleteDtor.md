# Function record: StdTreeHost_PtrVal_CompleteDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040d820` |
| **Canonical name** | `StdTreeHost_PtrVal_CompleteDtor` (**Inferred** structural) |
| **Ghidra name** | `FUN_0040d820` |
| **Address** | `0x0040d820` |
| **Body** | `0x0040d820`–`0x0040d86f` (**80 B** / `0x50`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC host complete dtor — Val12 pointer-value tree (`PTR_FUN_009c7938`) |
| **Completion status** | **Dual-reviewed** W31-A — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

Complete destructor for the host that owns a Val12 pointer-value tree: install `PTR_FUN_009c7938`, clear the tree (value destroy + free nodes + empty reset), then teardown the tree subobject / head via `FUN_0040d7c0(this+4)`. Does **not** free `this`.

## Signature

```c
// ECX = this; SEH; ADD ESP,0x10; RET; void; complete dtor (no operator_delete this)
void __fastcall StdTreeHost_PtrVal_CompleteDtor(TreeHost_Head8* self);
```

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `FUN_0040d590` @ `0x0040d593` (scalar-deleting); `FUN_0040d890` @ `0x0040d8b7`; Unwind `@009be2d3` |
| Callees | `StdTree_Clear_PtrVal_Vtbl0C` / `FUN_0040d5b0`, `FUN_0040d7c0` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0040d820_FUN_0040d820.md`
- Annotated: `docs/reconstruction/raw/aa_0040d820_FUN_0040d820.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTreeHost_PtrVal_CompleteDtor.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_0040d820.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0040d820_StdTreeHost_PtrVal_CompleteDtor.md`
- Review B: `docs/reconstruction/reviews/B_aa_0040d820_StdTreeHost_PtrVal_CompleteDtor.md`
- Scaffold record: `docs/reconstruction/functions/aa_0040d820_FUN_0040d820.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow / stage order | **High** |
| ABI ECX + SEH + ADD ESP,0x10; RET | **High** |
| Vtbl install `PTR_FUN_009c7938` | **High** |
| Clear callee + `FUN_0040d7c0(this+4)` | **High** (bytes) |
| Complete vs scalar | **High** (scalar is `FUN_0040d590`) |
| Product class / T English | **Low** |
| Nested `FUN_0040d7c0` full body | **Med** (decompile only; not owned) |
