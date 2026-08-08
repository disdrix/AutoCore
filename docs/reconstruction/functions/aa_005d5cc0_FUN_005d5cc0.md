# Function record: FUN_005d5cc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d5cc0` |
| **Canonical name** | `FUN_005d5cc0` |
| **Address** | `0x005d5cc0` |
| **Body range** | `0x005d5cc0`–`0x005d62fb` (**1596 B** / `0x63C`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities / waypoint path AI |
| **Completion status** | **Dual-reviewed MEGA-057** — raw re-verify + annotated + clean + A/B **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run); Terminal **false** |
| **Dual A/B** | `reviews/A_aa_005d5cc0_CVOGWaypoint_DoFollowObjectShortcutsUpdate.md`, `reviews/B_aa_005d5cc0_CVOGWaypoint_DoFollowObjectShortcutsUpdate.md` |
| **Last reviewed** | `2026-08-05` (MEGA-057) |

## Alias

- Product: `CVOGWaypoint_DoFollowObjectShortcutsUpdate` (plate `"CVOGWaypoint::DoFollowObjectShortcutsUpdate"` @ `0x009dace4`)
- Retired scaffold: `Named_CalleeOf_CVOGWaypoint_UpdateState_005d5cc0`

## Purpose

Ghidra symbol twin for the product-named waypoint state-2 handler. See named function record for full semantics.

## Signature (decompiler + bytes)

```c
// Ghidra: void __fastcall FUN_005d5cc0(int param_1)
// Bytes: thiscall ECX=this; void; RET 0
void __thiscall FUN_005d5cc0(void *this_wp);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005d5cc0_FUN_005d5cc0.md`
- Annotated: `docs/reconstruction/raw/aa_005d5cc0_FUN_005d5cc0.annotated.md`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_005d5cc0.cpp`
- Clean named: `docs/reconstruction/reconstructed-exact/CVOGWaypoint_DoFollowObjectShortcutsUpdate.cpp`
- Named record: `docs/reconstruction/functions/aa_005d5cc0_CVOGWaypoint_DoFollowObjectShortcutsUpdate.md`

## Callers / callees

- **Callers:** `CVOGWaypoint_UpdateState` @ `0x005d6300` (call `0x005d6353`, state case 2) only.
- **Callees:** `FUN_0076cf00`, `Object_ResolveFromTFID`, `__RTDynamicCast`, `Object_SurfaceDistance3D_Inferred`, `FUN_005d5960`, `Object_GetWorldPositionPtr`, `FUN_004d5910`, `operator_delete`, `FUN_0076cef0`, virtuals `+0x10` / `+0x2c`.

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler ≡ live | **High** |
| ABI thiscall void RET 0 | **High** |
| Product plate name | **High** |
| Residual callee English | **Open** |
