# Annotated low-level: VehicleEntity_SetLongitudinalInput

| Field | Value |
|---|---|
| Stable ID | `aa_004f5650` |
| VA | `0x004f5650` |
| Body | `0x004f5650` – `0x004f567a` (exclusive end; **0x2a** bytes) |
| System | `input-drive-control` |
| Date | 2026-07-23 capture; **2026-07-29** dual residual re-seal |

## Machine-level notes

- Source: raw capture for `aa_004f5650`; live Ghidra MCP re-decompile + `read_memory` 2026-07-29 **≡ raw**.
- Sibling `VehicleEntity_SetSteerInput` @ `0x004f5620` is a **byte twin** except store displacement (`+0x618` vs `+0x614`).
- Gate mask immediate is **`0xC7`** (`F6 80 B4 00 00 00 C7`); decompiler decimal **199**.
- Float arg via `movss xmm0,[esp+4]`; store `movss [ecx+0x614],xmm0`; epilogue `ret 4` (`__thiscall`).
- Intermediate link loads unchecked; only final wobj null is allow-write.
- No callees, clamps, or controller push in body.

## Pseudocode (annotated copy of raw / live)

```c
/* WI-MOV-001: thiscall. Writes float to this+0x614 (longitudinal input). Called from
   Client_Input_DriveControlTick with -1 (Accelerate name held DAT_00d1bc26), +1 (Reverse action
   DAT_00d1bc5a), or 0. Gate: skip if vehicle subsystem at this+linked+0xb0 has flags & 0xC7. */

void __thiscall VehicleEntity_SetLongitudinalInput(int param_1, undefined4 param_2)
{
  int iVar1;

  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1);
  if ((iVar1 == 0) || ((*(byte *)(iVar1 + 0xb4) & 199) == 0)) {
    *(undefined4 *)(param_1 + 0x614) = param_2;
  }
  return;
}
```

## Residual seals (2026-07-29)

| Item | Result |
|---|---|
| Live decompile ≡ raw | **Yes** |
| Body size | **0x2a** bytes (end exclusive `0x004f567a`) |
| Sibling delta | Store disp only (`0x614` / `0x618`) |
| Callers | 9 functions / 16 call sites (see function record) |
| Consumer | Push → `ctrl+0x20`; not applyAction thr ramp |
| Bypass writers | SetDriveAxes, setDrivingInputs, MoveToTarget proportional thr |

## Open questions

- `wobj` class name; per-bit `0xC7` producers.
- Runtime / differential / bit-exact (policy-open).
- English names for non-input callers.
