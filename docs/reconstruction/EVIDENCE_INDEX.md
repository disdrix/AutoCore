# Evidence Index

| Evidence ID | Kind | Location | Relates to | Summary | Confidence |
|-------------|------|----------|------------|---------|------------|
| EV-GH-5620-20260723 | Ghidra decompile | MCP `decompile_function` @ `0x004f5620` | aa_004f5620 | Fresh pseudocode: 0xC7 gate + store +0x618 | Confirmed capture |
| EV-GH-5650-20260723 | Ghidra decompile | MCP @ `0x004f5650` | aa_004f5650 | Identical gate → +0x614 | Confirmed capture |
| EV-GH-3620-20260723 | Ghidra decompile | MCP @ `0x004f3620` | SetHandbrake | Ungated store +0x61c | Confirmed capture |
| EV-GH-3620-20260729 | Ghidra re-decompile + xrefs | MCP `0x004f3620` / callers / `0x004fc650` | aa_004f3620 dual residual | Live body ≡ raw; caller inventory; MoveToTarget **direct** +0x61c (not caller) | Confirmed |
| EV-PRIOR-PUSH-HB | prior RE note | `physics/verified/fn_004fbc10_pushDriveAxes.md` | +0x61c consumer | Push copies HB → ctrl+0x24; +0x109 hard-stop override | High |
| EV-PRIOR-CWT-HB | prior RE note | `physics/verified/fn_00598040_calcWheelTorque.md` | +0x61c consumer | Rear drive torque ×0.5 when entity+0x61c≠0 | High |
| EV-GH-223b0-20260723 | Ghidra decompile | MCP @ `0x009223b0` | DriveControlTick | Full tick pseudocode (large) | Confirmed capture; interpretation partial |
| EV-GH-CALLERS-5620 | xrefs | MCP `get_function_callers` | aa_004f5620 | DriveControlTick, 0x4fc650, 0x5d73a0, 0x636ba0, 0x92f090, 0x9373e0 | Confirmed |
| EV-GH-CALLEES-223b0 | callees | MCP `get_function_callees` | DriveControlTick | Setters, PushDriveAxes, skills, terrain cast, … | Confirmed |
| EV-PRIOR-5620 | prior RE note | `physics/verified/fn_004f5620_setSteerInput.md` | aa_004f5620 | Gate analysis, callers, porting notes | High (static) |
| EV-PRIOR-STEER-FEED | prior RE note | `physics/verified/fn_steering_input_feed.md` | downstream of +0x618 | entity→VA→driverInput→steering update | High for chain |
| EV-PRIOR-INV | prior RE | `docs/inventory-cargo-wire-re.md` | SYS-INVENTORY | Grab/drop addresses, wire policy | High for wire facts |
| EV-PRIOR-MOTION | prior RE | `docs/MOTION_CLIENT_RE.md` | network pose | Soft/hard pose apply | High for documented facts |

## Capture policy

Raw captures under `raw/` are append-only originals. Later versions add sections or new files; do not overwrite first capture body.
