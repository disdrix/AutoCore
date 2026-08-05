# Function record: UI_VehicleInvHardpoint_RecomputeMode_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00862b70` |
| **Canonical name** | `UI_VehicleInvHardpoint_RecomputeMode_Inferred` |
| **Address** | `0x00862b70` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `inventory-transfer` |
| **Completion status** | **Dual-sealed** (A/B 2026-07-29) |
| **Bit-for-bit / runtime / diff** | Open (deferred) |
| **Ghidra name** | `FUN_00862b70` |

## Purpose

Vehicle inventory hardpoint widget mode recompute. `EAX=widget*`, `EDI=vehicle* or null`. Writes mode 0/1/2 at `widget+0x520`; on change calls `vtbl+0x3b4` then `vtbl+0x34c`.

## Signature

```c
void UI_VehicleInvHardpoint_RecomputeMode_Inferred(void);
// EAX = slot widget*, EDI = selected vehicle* (nullable)
```

## Callers / callees

- Caller: `FUN_008800e0` (10 slot sites)
- Callees: `FUN_00862860`, `FUN_004fabc0`, indirect `+0x3b4/+0x34c`

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00862b70_FUN_00862b70.md`
- Annotated: `docs/reconstruction/raw/aa_00862b70_FUN_00862b70.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_00862b70.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00862b70_UI_VehicleInvHardpoint_RecomputeMode_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00862b70_UI_VehicleInvHardpoint_RecomputeMode_Inferred.md`

## Confidence

| Claim | Level |
|---|---|
| Mode 0/1/2 + redraw-on-change | High |
| Mode English labels | Probable |
