# Function record: CWndVehicle_CompleteDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00834520` |
| **Canonical name** | `CWndVehicle_CompleteDtor` |
| **Ghidra name** | `FUN_00834520` |
| **Address** | `0x00834520` |
| **Body** | `0x00834520`–`0x008345b1` (**146 B** / `0x92`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | UI / CWndVehicle complete destructor |
| **Completion status** | **Dual-reviewed** WQ9J-B — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

MSVC-style **complete destructor** for the class whose primary vtbl is `PTR_FUN_00a6fbcc`. RTTI seals product name **CWndVehicle** (`.?AVCWndVehicle@@`). Installs that vtbl, notifies nested object at `+0x2A8`, runs `FUN_00833d50` (EDI=this) for derived vehicle-UI teardown, then `FUN_0078ca80` (CNDUIWndBuffered base). Does **not** free `this`. Bound as the body behind scalar-deleting `vtbl[0]` (`0x004160d0`).

## Signature

```c
// ECX = this. SEH LAB_009b4563. Bare RET after ADD ESP,0x18. void.
void __fastcall CWndVehicle_CompleteDtor(void* self);
```

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `CWndVehicle_ScalarDeletingDtor` (`0x004160d0`) |
| Callees | `FUN_0076c4d0`, `FUN_00833d50`, `FUN_0078ca80` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00834520_FUN_00834520.md`
- Annotated: `docs/reconstruction/raw/aa_00834520_FUN_00834520.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CWndVehicle_CompleteDtor.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00834520.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00834520_CWndVehicle_CompleteDtor.md`
- Review B: `docs/reconstruction/reviews/B_aa_00834520_CWndVehicle_CompleteDtor.md`
- Scaffold record: `docs/reconstruction/functions/aa_00834520_FUN_00834520.md`
- Scalar peer: `docs/reconstruction/functions/aa_004160d0_CWndVehicle_ScalarDeletingDtor.md` (WQ9I-F)

## Confidence

| Claim | Level |
|---|---|
| Complete-dtor role (no free this) | **High** |
| ABI ECX + SEH + bare RET | **High** |
| Product RTTI name CWndVehicle | **High** |
| Nested `+0x2A8` / base chain order | **High** |
| Nested / binder / `FUN_00833d50` product English | **Low** |
| Runtime | **Open** |
