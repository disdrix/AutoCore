# Function record: CVOGHBAICreatureBase_DoMovement (`aa_005cd3b0`)

| Field | Value |
|---|---|
| **Stable ID** | `aa_005cd3b0` |
| **Canonical name** | `FUN_005cd3b0` (Ghidra) |
| **Product name** | **`CVOGHBAICreatureBase::DoMovement`** (string sealed @ `0x009da8a8`) |
| **Address** | `0x005cd3b0` – `0x005ce989` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | combat / AI creature movement (HB) |
| **Completion status** | **Dual A/B sealed** (2026-07-29 W16-I) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Scaffold (misleading): `Named_VOG_DEBUG_STOP_005cd3b0` — trap string only
- Clean product file: `CVOGHBAICreatureBase_DoMovement.cpp`

## Purpose

Virtual **creature AI movement tick**: integrate host pose/velocity with terrain, climb, impulse damping, optional teleport, and local-position override. SEH + named scope enter. On NaN cascade hits debug stop string path.

## Signature (image + decompiler)

```c
// __thiscall  ECX = CVOGHBAICreatureBase* (or derived)
// stack: float dt
void CVOGHBAICreatureBase_DoMovement(void *this, float dt);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005cd3b0_FUN_005cd3b0.md`
- Annotated: `docs/reconstruction/raw/aa_005cd3b0_FUN_005cd3b0.annotated.md`
- Clean (product): `docs/reconstruction/reconstructed-exact/CVOGHBAICreatureBase_DoMovement.cpp`
- Clean (FUN alias): `docs/reconstruction/reconstructed-exact/FUN_005cd3b0.cpp`
- Deprecated named: `docs/reconstruction/reconstructed-exact/Named_VOG_DEBUG_STOP_005cd3b0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_005cd3b0_CVOGHBAICreatureBase_DoMovement.md`
- Review B: `docs/reconstruction/reviews/B_aa_005cd3b0_CVOGHBAICreatureBase_DoMovement.md`

## Callers / callees

**Callers:** no direct `CALL` xrefs; **5 DATA/vtable** slots: `009da9b4`, `009daf3c`, `009db0bc`, `009db11c`, `009db17c`.

**Callees (Ghidra list):** `CVOGMap_CastTerrainHeight`, `CVOGPhysics_ApplyImpulseVector`, `CVOGReaction_TeleportTarget`, `FUN_00404a20`, `FUN_00404c90`, `FUN_00404d10`, `FUN_00404dc0`, `FUN_0040b1b0`, `FUN_0040cf70`, `FUN_0040d040`, `FUN_0040d2a0`, `FUN_004ba740`, `FUN_004c3ac0`, `FUN_004c55e0`, `FUN_004cb3e0`, `FUN_004cdd90`, `FUN_0053e0b0`, `FUN_005d1ce0`, `FUN_0076cef0`, `FUN_0076cf00`, `FUN_007a4480`, `TFID_EqualsObjectId`, `_isnan`.

## Confidence

| Claim | Level |
|---|---|
| Product name DoMovement | **High** (scope string) |
| Thiscall + dt + host @ `this+0x64` | **High** |
| Early-out gates + NaN trap path | **High** CF |
| Full float-stack temporary naming | **Tentative** |
| Every host flag English | **Open** |
