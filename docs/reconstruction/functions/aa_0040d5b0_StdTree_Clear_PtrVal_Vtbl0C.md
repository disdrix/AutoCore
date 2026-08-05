# Function record: StdTree_Clear_PtrVal_Vtbl0C

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040d5b0` |
| **Canonical name** | `StdTree_Clear_PtrVal_Vtbl0C` (**Inferred** structural) |
| **Ghidra name** | `FUN_0040d5b0` |
| **Address** | `0x0040d5b0` |
| **Body** | `0x0040d5b0`–`0x0040d62a` (**123 B** / `0x7B`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC `_Tree` clear (Val12 + pointer values) |
| **Completion status** | **Dual-reviewed** W30-P — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

Clear a Val12 red-black tree: for every node, thiscall `vtbl[+0x0c]` on the `T*` stored at `node+0x14`, then free all nodes and reset the empty sentinel (`head` self-links, `size=0`).

## Signature

```c
// ECX = tree host (head@+8, size@+0xc). Bare RET. void.
void __fastcall StdTree_Clear_PtrVal_Vtbl0C(TreeHost_Head8* self);
```

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `FUN_0040d820` @ `0x0040d84b`; DATA vtbl slot2 `PTR_FUN_009c7938+8` (`0x009c7940`) |
| Callees | `StdTree_Inc_Val12` (`0x005ae0b0`), `FUN_0040d630`, `operator_delete` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0040d5b0_FUN_0040d5b0.md`
- Annotated: `docs/reconstruction/raw/aa_0040d5b0_FUN_0040d5b0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_Clear_PtrVal_Vtbl0C.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_0040d5b0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0040d5b0_StdTree_Clear_PtrVal_Vtbl0C.md`
- Review B: `docs/reconstruction/reviews/B_aa_0040d5b0_StdTree_Clear_PtrVal_Vtbl0C.md`
- Scaffold record: `docs/reconstruction/functions/aa_0040d5b0_FUN_0040d5b0.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow (bytes) | **High** |
| ABI ECX + bare RET | **High** |
| Val12 isnil@+0x19 / Inc callee | **High** |
| Value = `T*` @ +0x14 + vtbl[+0xc] | **High** (call shape) / product method **Low** |
| Free left-walk + `FUN_0040d630(right)` | **High** (bytes) |
| Product map type / host class | **Low** |
