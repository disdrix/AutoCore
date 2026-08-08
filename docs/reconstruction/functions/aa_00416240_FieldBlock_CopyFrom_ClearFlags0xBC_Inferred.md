# Function record: FieldBlock_CopyFrom_ClearFlags0xBC_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00416240` |
| **Canonical name** | `FieldBlock_CopyFrom_ClearFlags0xBC_Inferred` (**Inferred** structural) |
| **Ghidra name** | `FUN_00416240` |
| **Address** | `0x00416240` |
| **Body** | `0x00416240`–`0x0041625d` exclusive (**29 B** / `0x1D`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | field-block / selective POD assign helper |
| **Completion status** | **Dual-reviewed** WQ9I-H — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

Thiscall wrapper that clears dest flag dword at **`+0xBC`** (the same dword `FUN_00416160` treats as index `0x2f` / copy-control flags), then performs selective field-block assignment from `src` via `FUN_00416160`, and returns `dest`. Used as a temp-side copy in object nested-block swap (`FUN_00833160` on `+0x510` subobjects) and by `FUN_00634c50`.

## Signature

```c
// ECX = dest; stack src; RET 4; returns dest*
void* __thiscall FieldBlock_CopyFrom_ClearFlags0xBC_Inferred(void* dest, const void* src);
```

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `FUN_00634c50` @ `0x00634ce5`; `FUN_00833160` @ `0x00833249` |
| Callees | `FUN_00416160` (WQ9I-G OWN — selective assign) |

## Full body hex

```
8b442404568bf150c786bc00000000000000e809ffffff8bc65ec20400
```

## Artifacts

- Raw (+ WQ9I-H append): `docs/reconstruction/raw/aa_00416240_FUN_00416240.md`
- Annotated: `docs/reconstruction/raw/aa_00416240_FUN_00416240.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FieldBlock_CopyFrom_ClearFlags0xBC_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00416240.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00416240_FieldBlock_CopyFrom_ClearFlags0xBC_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00416240_FieldBlock_CopyFrom_ClearFlags0xBC_Inferred.md`
- Scaffold record: `docs/reconstruction/functions/aa_00416240_FUN_00416240.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow (bytes) | **High** |
| ABI ECX + RET 4 + return dest | **High** |
| Clear +0xBC then copy | **High** |
| Pre-clear product motive | **Low** (overwritten by callee) |
| Product field-block English | **Open** |
| Callee flag-bit map | **Open** (WQ9I-G) |
