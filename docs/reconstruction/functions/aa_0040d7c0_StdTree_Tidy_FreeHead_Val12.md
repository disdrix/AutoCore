# Function record: StdTree_Tidy_FreeHead_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040d7c0` |
| **Canonical name** | `StdTree_Tidy_FreeHead_Val12` (**Inferred** structural) |
| **Ghidra name** | `FUN_0040d7c0` |
| **Address** | `0x0040d7c0` |
| **Body** | `0x0040d7c0`–`0x0040d81c` exclusive (**92 B** / `0x5C`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC `_Tree` tidy / free head (Val12) |
| **Completion status** | **Dual-reviewed** W32-B — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

Tidy a Val12 tree subobject: full-range erase via `FUN_0040d700` (empty/full path free-subtree of root + reset sentinel), `operator_delete` the header node, null `head` and `size`. Called from host complete dtor as `FUN_0040d7c0(this+4)` after tree clear.

## Signature

```c
// ECX = tree* (host+4); bare RET; void
void __fastcall StdTree_Tidy_FreeHead_Val12(StdTree_Val12* tree);
```

| Formal | Source | Conf |
|---|---|---|
| tree | ECX (`8B F1`) | **High** |
| head @ +4 | `8B 46 04` / post-null `89 46 04` | **High** |
| size @ +8 | post-null `89 46 08` | **High** |
| cleanup | `C3` | **High** |

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `StdTreeHost_PtrVal_CompleteDtor` / `FUN_0040d820` @ `0x0040d85b`; Unwind `@009be2b6` |
| Callees | `FUN_0040d700`, `operator_delete` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0040d7c0_FUN_0040d7c0.md` (W32-B append)
- Annotated: `docs/reconstruction/raw/aa_0040d7c0_FUN_0040d7c0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_Tidy_FreeHead_Val12.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_0040d7c0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0040d7c0_StdTree_Tidy_FreeHead_Val12.md`
- Review B: `docs/reconstruction/reviews/B_aa_0040d7c0_StdTree_Tidy_FreeHead_Val12.md`
- Scaffold record: `docs/reconstruction/functions/aa_0040d7c0_FUN_0040d7c0.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow (erase full + delete head + null) | **High** (bytes) |
| ABI ECX + bare RET | **High** |
| head@+4 / size@+8 on tree subobject | **High** |
| Decompiler body complete | **Falsified** (false noreturn) |
| Product map / host demangle | **Low** |
| Nested `FUN_0040d700` full plate | **Med** (not owned) |
