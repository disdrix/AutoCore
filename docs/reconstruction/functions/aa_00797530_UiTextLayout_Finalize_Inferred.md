# Function record: UiTextLayout_Finalize_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00797530` |
| **Canonical name** | `UiTextLayout_Finalize_Inferred` |
| **Ghidra name** | `FUN_00797530` |
| **Address** | `0x00797530` |
| **Body** | `0x00797530`–`0x00797987` (**1112 B** / `0x458`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | UI — owned text-layout finalize / flush |
| **Completion status** | **Dual-reviewed** MEGA-122 — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

MSVC-style finalize of a text-layout block used by UI windows (notably CNDUIWindow owned block at `+0x28C`, via dualed complete dtor `UiTextLayout_CompleteDtor_Inferred`). Trims trailing spaces, applies alignment mode `@+0xCC`, materializes display runs (0x60 source → 0x80 display or single-run path), sets ready `@+0xB4`, clears embedded `wstring`. No product RTTI — name **inferred** from CF + ownership. Reject scaffold parent-seed name tying it to `Client_RecvBroadcast`.

## Signature

```c
// layout* in EBX. Stack char flag. SEH LAB_009add2c. RET 4 (C2 04 00). void.
void __stdcall UiTextLayout_Finalize_Inferred(char flag);
```

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `FUN_00797990`, `FUN_007979c0`, `FUN_00797a10`, `FUN_00797a60`, `UiTextLayout_CompleteDtor_Inferred` (`FUN_00797d70`), `FUN_00797e20` (flags 1/0/0), `FUN_007b3880`, `FUN_007b55c0` |
| Callees | `wstring` ops; `FUN_004275b0`; `FUN_00427a40`; `FUN_00426ff0`; `FUN_00427050`; `FUN_00427210` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00797530_FUN_00797530.md`
- Annotated: `docs/reconstruction/raw/aa_00797530_FUN_00797530.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/UiTextLayout_Finalize_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00797530.cpp`
- Retired scaffold: `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Client_RecvBroadcast_00797530.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00797530_UiTextLayout_Finalize_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00797530_UiTextLayout_Finalize_Inferred.md`
- Scaffold record: `docs/reconstruction/functions/aa_00797530_FUN_00797530.md`
- Peer complete dtor: `aa_00797d70_UiTextLayout_CompleteDtor_Inferred.md` (WQ9L-F)

## Confidence

| Claim | Level |
|---|---|
| Finalize role (not free host) | **High** |
| ABI EBX-this + stack flag + RET 4 | **High** |
| Object offsets sealed | **High** |
| Mode-3 flag gate | **High** |
| Product class demangle | **Open** |
| Runtime | **Open** |
