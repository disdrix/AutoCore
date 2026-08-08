# Function record: gfxUIWindow_CompleteDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00759de0` |
| **Canonical name** | `gfxUIWindow_CompleteDtor` |
| **Ghidra name** | `FUN_00759de0` |
| **Address** | `0x00759de0` |
| **Body** | `0x00759de0`–`0x0075a143` (**868 B** / `0x364`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | UI / graphics — gfxUIWindow complete destructor |
| **Completion status** | **Dual-reviewed** WQ9L-F — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

MSVC complete-object destructor for the class whose primary vtbl is `PTR_FUN_00a9f304`. RTTI seals product name **gfxUIWindow** (`.?AVgfxUIWindow@@`). Installs that vtbl; clears multiple tree shells and vectors; releases refcounted iface at `+0x34`; asserts if the children vector at `+0x94` is non-empty; mid-dtor installs nested vtbl `PTR_FUN_00a9db18` at `+0x30`; returns without freeing `this`. Bound as the body behind scalar-deleting `vtbl[0]` (`0x004401b0`). Super-base of `CNDUIWindow_CompleteDtor` (`0x007b5be0`).

## Signature

```c
// ECX = this. SEH LAB_009b3156. Bare RET after ADD ESP,0x20. void.
void __fastcall gfxUIWindow_CompleteDtor(void* self);
```

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `CNDUIWindow_CompleteDtor`, scalar `0x004401b0`, `FUN_00753db0`, `FUN_00968560`, EH unwinds |
| Callees | tree erase helpers, `FUN_00988710`, `FUN_00756be0`, assert/crash, `operator_delete` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00759de0_FUN_00759de0.md`
- Annotated: `docs/reconstruction/raw/aa_00759de0_FUN_00759de0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/gfxUIWindow_CompleteDtor.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00759de0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00759de0_gfxUIWindow_CompleteDtor.md`
- Review B: `docs/reconstruction/reviews/B_aa_00759de0_gfxUIWindow_CompleteDtor.md`
- Scaffold record: `docs/reconstruction/functions/aa_00759de0_FUN_00759de0.md`
- Derived pair: `aa_007b5be0_CNDUIWindow_CompleteDtor.md` (WQ9K-F)

## Confidence

| Claim | Level |
|---|---|
| Complete-dtor role (no free this) | **High** |
| ABI ECX + SEH + bare RET | **High** |
| Product RTTI name gfxUIWindow | **High** |
| Children-assert + free-null order | **High** |
| Tree-shell element product English | **Low** |
| Runtime | **Open** |
