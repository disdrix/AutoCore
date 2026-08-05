# Function record: hkVehicleFrictionSolver_circleProjection

| Field | Value |
|---|---|
| **Stable ID** | `aa_006c3f90` |
| **Canonical name** | `hkVehicleFrictionSolver_circleProjection` |
| **Address** | `0x006c3f90` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | physics-havok-vehicle (deferred priority) |
| **Completion status** | **Partial refined** — raw/annotated/clean present; clean readability pass done; dual review + `unaff_ESI` recovery still open |
| **Bit-for-bit / runtime / diff** | Open (physics deferred / not run) |

## Purpose

Havok vehicle friction helper: when the scaled 2D force pair on a wheel/contact
state block exceeds the unit circle, project it back via a short scale-table
walk and write residual / output magnitude. Early-out zeros residual at `+0x98`
when already inside the circle.

## Signature (decompiler-derived)

```c
void __thiscall hkVehicleFrictionSolver_circleProjection(int param_1, int param_2)
```

- `param_1` — friction solver state block (see clean header field map).
- `param_2` — output; `float` write at `+0x08`.
- Hidden/unrecovered: `float *` scale table (`unaff_ESI` in decompile).

## Artifacts

- Raw: `docs/reconstruction/raw/aa_006c3f90_hkVehicleFrictionSolver_circleProjection.md`
- Annotated: `docs/reconstruction/raw/aa_006c3f90_hkVehicleFrictionSolver_circleProjection.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/hkVehicleFrictionSolver_circleProjection.cpp`

## Callers / callees

- Sibling in same worklist wave: `hkVehicleFrictionSolver_solve` @ `0x006c4450` (large).
- Full xref pass deferred with physics priority.

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Unit-circle project / early-out residual zero | High |
| Field offset roles (+0x80/+0x84 force pair, +0x98 residual) | Probable |
| `unaff_ESI` scale table identity | Tentative |
| Types (`int` vs struct*) | Tentative |
