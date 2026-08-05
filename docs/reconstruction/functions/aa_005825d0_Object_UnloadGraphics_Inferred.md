# Function record: Object_UnloadGraphics_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005825d0` |
| **Canonical name** | `Object_UnloadGraphics_Inferred` |
| **Ghidra name** | `FUN_005825d0` |
| **Address** | `0x005825d0`–`0x00582664` (**148 B / `0x94`**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | object / graphics unload / mission-state FX |
| **Completion status** | **Sealed (W31-T)** — dual A/B accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

- Scaffold: `FUN_005825d0`
- Caller plate: UnloadGraphics (via `FUN_005d4fd0` format string)

## Purpose

Unload object graphics and related side effects for an MI subobject: remove from manager tracking, clear local flag, invoke object graphics-destroy virtual, set mission FX state 3, optional host notify, then residual virtuals on object and self.

## Signature (byte-sealed)

```c
// thiscall; bare ret
void Object_UnloadGraphics_Inferred(void *mi_this);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005825d0_FUN_005825d0.md`
- Annotated: `docs/reconstruction/raw/aa_005825d0_FUN_005825d0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Object_UnloadGraphics_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_005825d0.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_005825d0_Object_UnloadGraphics_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_005825d0_Object_UnloadGraphics_Inferred.md`
- Report: `docs/agents/task-dual-ab-0094e530-005825d0-w31t-report.md`

## Callers / callees

**CODE callers (1):** `FUN_005d4fd0` @ `0x005d5016`.

**DATA:** 14 vtable slots (see raw W31-T append).

**Callees:** `FUN_004bfd10`, `Object_SetMissionStateFx_Inferred` (`0x00518370`), object/self virtuals.

## Confidence

| Claim | Level |
|---|---|
| Body bounds + bare RET | **Confirmed** |
| UnloadGraphics role | **Confirmed** (caller string) |
| SetMissionStateFx(3) | **Confirmed** |
| Product class English | **Inferred** |
| Runtime golden | Open |
