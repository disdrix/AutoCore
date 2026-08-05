# Function record: FUN_005d9ea0 / Drive_CollisionListener_PrepBodyContact

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d9ea0` |
| **Canonical name** | `Drive_CollisionListener_PrepBodyContact` |
| **Ghidra name** | `FUN_005d9ea0` |
| **Address** | `0x005d9ea0`–`0x005da093` (500 B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | drive / collision / client FX+SFX |
| **Completion status** | **partial** — dual A/B sealed 2026-07-29 W25-K; runtime/diff/bit-exact open |
| **Bit-for-bit / runtime / diff** | Open |
| **Name confidence** | **Inferred** (Contact sibling family; no string on this VA) |

## Purpose

Per-body contact prep from `CollisionListener::contact`: parent-walk body → host pair-list (types 1/3/4) → optional `PlayCollisionSound` + type-3 GO `PlayCollisionEffect(allowCreate=0)` when enable and `|impact|>1`; updates `this+0xc` body cache and optional out flag.

## Signature

```c
// __thiscall RET 0x14
void Drive_CollisionListener_PrepBodyContact(
    void* this, void* ctx, int* body, float* impact,
    uint8_t enable, uint8_t* outPlayed);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005d9ea0_FUN_005d9ea0.md`
- Annotated: `docs/reconstruction/raw/aa_005d9ea0_FUN_005d9ea0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Drive_CollisionListener_PrepBodyContact.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_005d9ea0.cpp`
- Reviews: `A_aa_005d9ea0_*`, `B_aa_005d9ea0_*`

## Callers / callees

| Direction | Target | Notes |
|---|---|---|
| Caller (1) | `FUN_005da0a0` Contact | sites `0x005da4d8`, `0x005da4f3` (A/B) |
| Callee | `FUN_005d90a0` PlayCollisionSound | if enable + \|impact\|>1 |
| Callee | `FUN_0040afb0` ×2 | material keys 3/4 |
| Callee | `FUN_005d9af0` PlayCollisionEffect | allowCreate **0** |

## Confidence

| Claim | Level |
|---|---|
| Body 500 B / RET 0x14 / 5 stack formals | **High** (bytes) |
| Contact dual call A/B | **High** |
| Impact gate 1.0f | **High** |
| Pair types 1/3/4 CF | **High** |
| allowCreate=0 from prep | **High** |
| ctx / material English | **Medium** residual |
| Product method name | **Open** (Inferred) |
