# Raw capture: VehicleEntity_SetDriveAxes

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fbec0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004fbec0` |
| **Canonical name** | `VehicleEntity_SetDriveAxes` |
| **System** | input-drive-control |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WI-MOV-002: thiscall SetDriveAxes(throttle@+0x614, steer@+0x618, handbrake@+0x61c) then
   PushDriveAxesToController. */

void __thiscall
VehicleEntity_SetDriveAxes(int param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4)

{
  *(undefined4 *)(param_1 + 0x614) = param_2;
  *(undefined4 *)(param_1 + 0x618) = param_3;
  *(undefined1 *)(param_1 + 0x61c) = param_4;
  VehicleEntity_PushDriveAxesToController();
  return;
}
```

---

## Re-verify 2026-07-29 (dual strengthen; append-only)

Tool: Ghidra MCP `decompile_function` @ `0x004fbec0` + `read_memory` len 48.

Live decompile body ≡ frozen section above (three stores + `VehicleEntity_PushDriveAxesToController`).

Machine hex (body + pad):
`f30f104424048a44240cf30f118114060000f30f10442408f30f11811806000088811c060000e825fdffffc20c00cccc`

- Call rel @ `0x004fbee6` → `0x004fbc10`
- `ret 0xc`; span end `0x004fbeed`
- Sole xref: `0x0059858a` airStabilization recovery args thr=0, steer=0, hb=1
