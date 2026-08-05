# Annotated low-level: Drive_CollisionListener_Contact

| Field | Value |
|---|---|
| Stable ID | `aa_005da0a0` |
| VA | `0x005da0a0`–`0x005dab25` |
| Ghidra name | `FUN_005da0a0` |
| Canonical name | `Drive_CollisionListener_Contact` |
| System | drive / collision / vehicle damage |
| Date | 2026-07-29 (W22-I seal) |

## Machine-level notes

- Source: live Ghidra `decompile_function` + `read_memory` (no `disassemble_bytes`).
- Embedded profiler string **`"CollisionListener::contact"`** — product class/method evidence (**High**).
- Sibling: `Drive_CollisionListener_DoVehicleCollision` @ `0x005d9290` (string `"CollisionListener::DoVehicleCollision"`).
- Sole caller: `FUN_005dab30` (thin contact-event adapter; sets `event+0x20=1` when AL==0).
- Body **2693 B**; SEH frame `LAB_009a720f`; `RET 0x10`.
- **thiscall**: prologue `mov [esp+0x24], ecx`. Decompiler drops this formal; residual `local_18c` is the saved this (rate field `this+0x10`).
- Returns **uint8_t** in AL: 0 = reject/disable (caller marks event); non-zero keeps contact (`local_19e` default 1, or forced 1 on early ok paths).

## Signature (sealed)

```c
// __thiscall RET 0x10
uint8_t Drive_CollisionListener_Contact(
    void* this,          // ECX CollisionListener*; +0x10 last-contact time
    uint32_t ctx,        // stack0 from contact event +0x14
    float* impact,       // stack1 contact event +0x1c
    int* bodyA,          // stack2 phys shape/body chain
    int* bodyB);         // stack3
```

| Formal | Source | Conf |
|---|---|---|
| this | ECX saved; used as rate host (`+0x10`) | **High** |
| ctx | Stack[0x4]; forwarded to `FUN_005d9ea0` / `FUN_005d9290` / `FUN_005d9af0` | **High** |
| impact | Stack[0x8] float*; magnitude gate vs 1.0 | **High** |
| bodyA/B | Stack[0xC]/[0x10]; parent-walk + pair-list resolve | **High** |
| return AL | 0 reject; else `local_19e` or 1 | **High** |

## Key offsets / vtbls

| Offset / slot | Role | Conf |
|---|---|---|
| body`[3]` | parent link (walk to root) | **High** |
| body`[8]` | host / world-object holder | **High** |
| host`+0x30`/`+0x34` | pair list base / count (entries stride 8, type dword) | **High** |
| obj`[0x5f]` bit5 (`+0x17c`) | eligible for game-object resolve | **High** |
| vtbl`+0x1c8` | resolve game object from phys entry | **High** |
| vtbl`+0x1d4` | linked vehicle/character (TFID host) | **High** |
| vtbl`+0x1d8` | secondary object / TFID source | **High** |
| vtbl`+0x210`(0) | affinity / mode gate | **High** |
| vtbl`+0x298`(other) | mutual relation / hostile check | **High** |
| vtbl`+0x28` / `+0x2c` | mass-like scalars for sort / energy | **High** |
| clonebase `+0x38` | type id (seen: 3, 0xe, 0x12) | **High** |
| object `+0x164`/`+0x168` | TFID dword pair for UI packet | **High** |
| object `+0x26` (via adj) | damage-apply enable flag | **High** |
| object `+0x180` bit10 / `+0x200` bit4 | skip flags | **High** |
| UI opcode **0x29** | Logic-UI collision toast/event | **High** |

## Constants

| Symbol | Value | Role |
|---|---|---|
| `_DAT_00af4364` | 1.0f | `ABS(*impact)` UI gate |
| `_DAT_00af4368` | 0.5f | time throttle for contact flag |
| `_DAT_00aaa994` | 3.6f | linear speed scale |
| `_DAT_009db4e4` | ~2.5e-7f | energy multiplier |
| `DAT_00aaacd0` | 350.0f | energy clamp |
| `DAT_00af43b4` | 500 | GetTickCount debounce window |

## Control-flow stages (annotated)

1. **Enter**: SEH; `FUN_0076cf00("CollisionListener::contact")`; `local_19e=1`; time sample.
2. **Resolve hosts**: parent-walk A/B → `local_17c` / `local_16c` hosts.
3. **Game objects**: scan type==1 list entries; vtbl+0x1c8 → `piVar12` (A) / `piVar6` (B).
4. **Material type 1 special**: exclusive one-side type==1; resolve linked actor; type 0x12/0xe gates; tick map debounce (`FUN_005dab60`, `FUN_004055c0`); may set `local_19e=0`.
5. **Type 0xe hooks**: per-side `FUN_004faf80` after vtbl+0x1d4.
6. **Throttle flag** `iStack_194`: clear low byte if within 0.5s of `this+0x10`, else set 1 and refresh time.
7. **Per-body prep**: `FUN_005d9ea0` ×2 → out flags `cStack_18d` / `cStack_19d`.
8. **Missing GO**: return 1.
9. **Relation fail**: affinity+mutual → `LAB_005dab08` return 0.
10. **Energy**: sort by vtbl+0x28; speed from vel @ body+2 → `+0x3c+0x40` or `DAT_00bc5660`; `E = min(350, (|v|*3.6)^2 * mass * 2.5e-7)`; optional mutual damage apply.
11. **Type 0x12 hard gates** both sides (return 0).
12. **FX + UI**: if either has linked actor and neither prep-flag: `FUN_005d9af0`; if `ABS(*impact)>1`: packet opcode 0x29 via `Client_SendLogicUiPacket`.
13. **Pair filters**: mutual check; type 3+3 → return 1; either 0xe → skip vehicle collision; type 0x12 TFID≠null → skip path.
14. **Vehicle collision**: bidirectional `FUN_005d9290` (`Drive_CollisionListener_DoVehicleCollision`).
15. **Exit**: return `local_19e` or 0; always `FUN_0076cef0` profiler leave.

## Decompiler residuals

| Residual | Resolution |
|---|---|
| Missing this formal | Bytes: ECX saved; treat as first formal |
| `local_18c` unassigned | = saved this (rate host) |
| `undefined4` widths | Use `uint32_t` in clean |
| Complex material-type boolean nest | CF preserved; product English for types 0xe/0x12/3 open |

## Open questions

- Product English for clonebase types **0xe**, **0x12**, **3**.
- Exact meaning of contact event fields `+0x14` / `+0x1c` / `+0x20`.
- `FUN_005d9ea0` / `FUN_005d9af0` full contracts (owned by other agents).
- Runtime / bit-exact not run.
