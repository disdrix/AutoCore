# Function record: FUN_0075ceb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0075ceb0` |
| **Canonical name** | `GfxView_Ctor_Inferred` (see named record) |
| **Address** | `0x0075ceb0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | graphics / client camera (GfxView) |
| **Completion status** | **Dual A/B present** — 2026-07-29 W31-O |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Verdict** | **accept-with-gaps** |

## Alias

| Name | Notes |
|---|---|
| `FUN_0075ceb0` | Ghidra default |
| `Named_gfxView_0075ceb0` | Auto string seed |
| `GfxView_Ctor_Inferred` | **Canonical** named record |

## Purpose

GfxView constructor (`gfxView.cpp`): vtbl, fields, VB + background effect, defaults near 0.5 / far 10000 / FOV π/3.

## Signature (decompiler-derived / sealed)

```c
void * __fastcall FUN_0075ceb0(void *this /*ECX*/); // returns this
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0075ceb0_FUN_0075ceb0.md`
- Annotated: `docs/reconstruction/raw/aa_0075ceb0_FUN_0075ceb0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_0075ceb0.cpp`
- Named clean: `docs/reconstruction/reconstructed-exact/GfxView_Ctor_Inferred.cpp`
- Named record: `docs/reconstruction/functions/aa_0075ceb0_GfxView_Ctor_Inferred.md`

## Callers / callees

Callers: `FUN_004cda90` @ `0x004cdac8`, `FUN_00968a50` @ `0x00968a71`.  
Callees: see named record.

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | **High** |
| Product path / constants | **High** |
| Nested helper product English | **Open** |
