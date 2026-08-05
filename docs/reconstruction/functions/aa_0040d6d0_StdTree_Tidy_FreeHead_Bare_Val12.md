# Function record: StdTree_Tidy_FreeHead_Bare_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040d6d0` |
| **Canonical name** | `StdTree_Tidy_FreeHead_Bare_Val12` (**Inferred** structural) |
| **Ghidra name** | `FUN_0040d6d0` |
| **Address** | `0x0040d6d0` |
| **Body** | `0x0040d6d0`–`0x0040d6fe` exclusive (**46 B** / `0x2E`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC `_Tree` tidy / free header (Val12) |
| **Completion status** | **Dual-reviewed** W33-A — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

MSVC-style `_Tree` tidy on a Val12 facade (`head@+4`, `size@+8`) **without** an SEH frame: erase the full range `[begin,end)=[*head,head)` via `StdTree_EraseRange_Val12` (`0x0040d700`), free the header sentinel with `operator_delete`, then null head and size. Used as the SEH unwind target `@009bda70`. Peer with SEH: `StdTree_Tidy_FreeHead_Val12` @ `0x0040d7c0` (W32-B).

## Signature

```c
// ECX = tree*; bare RET (C3); void
void __fastcall StdTree_Tidy_FreeHead_Bare_Val12(StdTree_Val12* tree);
```

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | Unwind `@009bda70` → JMP this |
| Callees | `StdTree_EraseRange_Val12` / `FUN_0040d700`, `operator_delete` |

## Artifacts

- Raw (+ W33-A append): `docs/reconstruction/raw/aa_0040d6d0_FUN_0040d6d0.md`
- Annotated: `docs/reconstruction/raw/aa_0040d6d0_FUN_0040d6d0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_Tidy_FreeHead_Bare_Val12.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_0040d6d0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0040d6d0_StdTree_Tidy_FreeHead_Bare_Val12.md`
- Review B: `docs/reconstruction/reviews/B_aa_0040d6d0_StdTree_Tidy_FreeHead_Bare_Val12.md`
- Scaffold record: `docs/reconstruction/functions/aa_0040d6d0_FUN_0040d6d0.md`
- Scratch: `docs/reconstruction/tmp/a_0040d6d0.md`

## Confidence

| Claim | Level |
|---|---|
| Full-range erase + free head + null | **High** (bytes) |
| ABI ECX / bare RET / no SEH | **High** |
| Peer of SEH tidy `0040d7c0` | **High** (same offsets/order) |
| Nested erase product English | **Med** (owned W32-C) |
| Product map T demangle | **Low** |
