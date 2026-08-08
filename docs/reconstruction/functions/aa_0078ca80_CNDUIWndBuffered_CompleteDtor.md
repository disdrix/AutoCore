# Function record: CNDUIWndBuffered_CompleteDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0078ca80` |
| **Canonical name** | `CNDUIWndBuffered_CompleteDtor` |
| **Ghidra name** | `FUN_0078ca80` |
| **Address** | `0x0078ca80` |
| **Body** | `0x0078ca80`–`0x0078caef` (**112 B** / `0x70`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | UI / CNDUIWndBuffered complete destructor |
| **Completion status** | **Dual-reviewed** WQ9K-F — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

MSVC-style **complete destructor** for the class whose primary vtbl is `PTR_FUN_00a99f74`. RTTI seals product name **CNDUIWndBuffered** (`.?AVCNDUIWndBuffered@@`). Installs that vtbl, runs shared teardown helpers, scalar-deletes nested HostBase at `+0x2A8` (always nulls field), then `FUN_007b5be0` (`CNDUIWindow_CompleteDtor`). Does **not** free `this`. Bound as the body behind scalar-deleting `vtbl[0]` (`0x004293f0`).

## Signature

```c
// ECX = this. SEH LAB_009b3fee. Bare RET after ADD ESP,0x10. void.
void __fastcall CNDUIWndBuffered_CompleteDtor(void* self);
```

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `CWndVehicle_CompleteDtor` (`0x00834520`), scalar `0x004293f0`, `FUN_00856380`, EH |
| Callees | `FUN_007a8580`, `FUN_0078c3d0`, nested scalar dtor, `CNDUIWindow_CompleteDtor` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0078ca80_FUN_0078ca80.md`
- Annotated: `docs/reconstruction/raw/aa_0078ca80_FUN_0078ca80.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CNDUIWndBuffered_CompleteDtor.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_0078ca80.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0078ca80_CNDUIWndBuffered_CompleteDtor.md`
- Review B: `docs/reconstruction/reviews/B_aa_0078ca80_CNDUIWndBuffered_CompleteDtor.md`
- Scaffold record: `docs/reconstruction/functions/aa_0078ca80_FUN_0078ca80.md`
- Ctor twin: `docs/reconstruction/functions/aa_0078caf0_*` (W34-T)
- Base pair: `aa_007b5be0_CNDUIWindow_CompleteDtor.md` (OWN WQ9K-F)

## Confidence

| Claim | Level |
|---|---|
| Complete-dtor role (no free this) | **High** |
| ABI ECX + SEH + bare RET | **High** |
| Product RTTI name CNDUIWndBuffered | **High** |
| Nested `+0x2A8` / base chain order | **High** |
| Helper product English | **Low** |
| Runtime | **Open** |
