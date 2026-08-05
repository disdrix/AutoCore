# Raw capture: VehicleEntity_SetLongitudinalInput (brief sibling)

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f5650` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004f5650` |
| **Body end (approx)** | `0x004f567a` (~0x2b bytes) |
| **Canonical name** | `VehicleEntity_SetLongitudinalInput` |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `decompile_function` (paired with `aa_004f5620`) |
| **Convention** | MSVC `__thiscall` |
| **Primary sibling** | `VehicleEntity_SetSteerInput` @ `0x004f5620` → store `+0x618` |
| **Related verified note** | `docs/reconstruction/physics/verified/fn_004f5620_setSteerInput.md` |

---

## Role

Identical write **gate** as `SetSteerInput`; only the store target differs:

| Function | Store |
|---|---|
| `SetSteerInput` `0x004f5620` | `this+0x618` steer f32 |
| `SetLongitudinalInput` `0x004f5650` | `this+0x614` longitudinal f32 |

Gate: `wobj = *(*(*(this+4)+4) + this + 0xb0)`; allow write if `wobj==0` OR `(*(u8*)(wobj+0xb4) & 0xC7)==0`. Mask decompiler decimal **199** ≡ **`0xC7`**. No clamps, no other side effects.

---

## Raw pseudocode (from verified / paired capture)

```c
/* WI-MOV-001: thiscall. Writes float to this+0x614 (longitudinal input). Called from
   Client_Input_DriveControlTick with -1 (Accelerate name held DAT_00d1bc26), +1 (Reverse name
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

---

## Notes

- Full annotated + function-record + exact C++ suite for this address is **not** part of this brief sibling raw file; primary package is `aa_004f5620`.
- Callers (sample): `0x009223b0`, `0x004fc650`, `0x005d73a0`, `0x00914c20`, `0x00925820`, `0x0092f090`, `0x009373e0`, `0x00938670`, `0x00946c00`.
- **Do not overwrite** this raw capture with cleaned reinterpretations.
