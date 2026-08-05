# Function record: FUN_005da0a0 / Drive_CollisionListener_Contact

| Field | Value |
|---|---|
| **Stable ID** | `aa_005da0a0` |
| **Canonical name** | `Drive_CollisionListener_Contact` |
| **Ghidra name** | `FUN_005da0a0` |
| **Address** | `0x005da0a0`–`0x005dab25` (2693 B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | drive / collision / vehicle damage |
| **Completion status** | **dual-sealed** W22-I 2026-07-29 — raw/annotated/clean + A/B |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- `Drive_CollisionListener_Contact` (preferred; string + sibling naming)
- `Named_CollisionListener_Contact` (legacy scaffold)

## Purpose

Havok/phys **contact** callback core for `CollisionListener`: resolve game objects from both contact bodies, apply material/type gates, compute impact energy, optional damage + Logic-UI opcode 0x29, then bidirectional vehicle-collision handling via `Drive_CollisionListener_DoVehicleCollision`.

## Signature (sealed)

```c
// __thiscall RET 0x10; returns uint8_t in AL
uint8_t Drive_CollisionListener_Contact(
    void* this,       // ECX; +0x10 last contact time
    uint32_t ctx,     // contact event +0x14
    float* impact,    // contact event +0x1c
    int* bodyA,
    int* bodyB);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005da0a0_FUN_005da0a0.md`
- Annotated: `docs/reconstruction/raw/aa_005da0a0_FUN_005da0a0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Drive_CollisionListener_Contact.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_005da0a0.cpp`
- Reviews: `A_aa_005da0a0_Drive_CollisionListener_Contact.md`, `B_aa_005da0a0_Drive_CollisionListener_Contact.md`

## Callers / callees

| Role | Symbol | VA / note |
|---|---|---|
| Caller (sole) | `FUN_005dab30` | `0x005dab30` (site `0x005dab45`) |
| Profiler enter/leave | `FUN_0076cf00` / `FUN_0076cef0` | string contact |
| Time | `FUN_0079a110` | float time |
| Debounce map | `FUN_005dab60`, `FUN_004055c0`, `GetTickCount` | 500 ms |
| Per-body prep | `FUN_005d9ea0` | ×2 |
| Type 0xe hook | `FUN_004faf80` | |
| Damage channel | `FUN_00515170` + vtbl+0x54 | |
| Gates | `FUN_0040d080`, `FUN_0040b1b0`, `FUN_0040afb0` | |
| TFID | `FUN_004ba740`, `TFID_NotEquals` | vs `DAT_009db428` |
| FX | `FUN_005d9af0` | |
| UI | `Client_SendLogicUiPacket` | opcode 0x29 |
| Vehicle coll | `FUN_005d9290` / `Drive_CollisionListener_DoVehicleCollision` | bidirectional |

## Confidence

| Claim | Level |
|---|---|
| Name from `"CollisionListener::contact"` | **High** |
| CF stages + return 0/local_19e/1 | **High** |
| thiscall ECX + RET 0x10 | **High** |
| Energy formula constants | **High** (floats sealed) |
| Clonebase type English (0xe/0x12/3) | **Tentative** |
| Full contact-event layout | **Probable** (caller offsets only) |
