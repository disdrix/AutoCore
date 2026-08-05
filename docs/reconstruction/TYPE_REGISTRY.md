# Type Registry

| Type / concept | Kind | Size / width | Related offsets | Evidence | Confidence | Conflicts |
|----------------|------|--------------|-----------------|----------|------------|-----------|
| `VehicleEntity` (partial) | class/struct | unknown full size | drive axes region ~0x614–0x61c | Setters + DriveControlTick | Partial | Full layout not recovered this pass |
| `steerInput` | f32 field | 4 | `+0x618` | SetSteerInput store | High | — |
| `longitudinalInput` | f32 field | 4 | `+0x614` | SetLongitudinalInput store | High | — |
| `handbrakeFlag` | u8 field | 1 | `+0x61c` | SetHandbrake store | High | Whether other bits coexist nearby unknown |
| `suppressDriveAxisApply` | char flag | 1 | vehicle `+0x101` | DriveControlTick branches skip setters when set | Probable | Exact name uncertain |
| `driveAxisLockObject` | pointer object | 4 (ptr) | resolved via entity link chain +0xb0 | Gate load in setters | Tentative type id | May be wheel-control / subsystem |
| `driveAxisLockFlags` | u8 bitfield | 1 | lockobj `+0xb4` | `& 0xC7` compare | Probable as lock mask | Bit meanings individually unknown |
| Action-map held flags | global chars | 1 each | `DAT_00d1bc26` accel, `d1bc5a` reverse, `d1bc8e` steerL, `d1bcc2` steerR, soft L/R, brake `d1bd5e` | DriveControlTick | High existence; Probable action names from plate comments | Exact ActionMap table not fully typed |

See also: `types/VehicleEntity_drive_axes.md`, `OBJECT_LAYOUTS.md`.
