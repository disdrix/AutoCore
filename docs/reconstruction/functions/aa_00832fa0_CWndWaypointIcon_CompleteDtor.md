# Function record: CWndWaypointIcon_CompleteDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00832fa0` |
| **Canonical name** | `CWndWaypointIcon_CompleteDtor` |
| **Ghidra name** | `FUN_00832fa0` |
| **Address** | `0x00832fa0` |
| **Body** | `0x00832fa0`–`0x0083300f` (**112 B** / `0x70`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | UI / CWndWaypointIcon complete destructor |
| **Completion status** | **Dual-reviewed** WQ9J-B — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

MSVC-style **complete destructor** for the class whose primary vtbl is `PTR_FUN_00a7000c`. RTTI seals product name **CWndWaypointIcon** (`.?AVCWndWaypointIcon@@`). Installs that vtbl, releases/frees owned pointer at `+0x488`, nulls it, then `FUN_007b5be0` (base UI window). Does **not** free `this`. Bound as the body behind scalar-deleting `vtbl[0]` (`0x00416350`).

## Signature

```c
// ECX = this. SEH LAB_009b33be. Bare RET after ADD ESP,0x10. void.
void __fastcall CWndWaypointIcon_CompleteDtor(void* self);
```

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `Class_00a7000c_ScalarDeletingDtor_Inferred` (`0x00416350`; product rename residual) |
| Callees | `FUN_0096efd0`, `operator_delete`, `FUN_007b5be0` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00832fa0_FUN_00832fa0.md`
- Annotated: `docs/reconstruction/raw/aa_00832fa0_FUN_00832fa0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CWndWaypointIcon_CompleteDtor.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00832fa0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00832fa0_CWndWaypointIcon_CompleteDtor.md`
- Review B: `docs/reconstruction/reviews/B_aa_00832fa0_CWndWaypointIcon_CompleteDtor.md`
- Scaffold record: `docs/reconstruction/functions/aa_00832fa0_FUN_00832fa0.md`
- Scalar peer: `docs/reconstruction/functions/aa_00416350_Class_00a7000c_ScalarDeletingDtor_Inferred.md` (WQ9I-H)

## Confidence

| Claim | Level |
|---|---|
| Complete-dtor role (no free this) | **High** |
| ABI ECX + SEH + bare RET | **High** |
| Product RTTI name CWndWaypointIcon | **High** |
| Owned `+0x488` free-then-null + base chain | **High** |
| Owned block / `FUN_0096efd0` product English | **Low** |
| Runtime | **Open** |
