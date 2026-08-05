# Function record: CVOGHBAICreatureBase_PathlessIdleRoam_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005cd220` |
| **Canonical name** | `CVOGHBAICreatureBase_PathlessIdleRoam_Inferred` |
| **Ghidra name** | `FUN_005cd220` |
| **Address** | `0x005cd220`–`0x005cd3ad` exclusive (**397** B / `0x18D`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client creature HBAI / pathless idle roam |
| **Completion status** | **Sealed** — dual A/B W30-S 2026-07-29; **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |
| **Dual verdict** | **accept-with-gaps** |

## Naming evidence

| Source | Value |
|---|---|
| Caller | `CVOGHBAICreatureBase_OnHeartBeat` @ `0x005d0310` (×2 sites) |
| Docs | `docs/NPC.md` — pathless idle roam random offset within radius |
| Math | local XZ offset → quat transform → AI vtbl+0x4c set dest |
| Not | seek-player / MapPath / `ReturnToNormalLocation` |
| Product mangled on this VA | **No** |

**Decision:** promote **`CVOGHBAICreatureBase_PathlessIdleRoam_Inferred`**.

## Signature

```c
// __thiscall; ECX = CVOGHBAICreatureBase*; ret (c3); uint ignored by caller
uint32_t CVOGHBAICreatureBase_PathlessIdleRoam_Inferred(void *ai_self);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005cd220_FUN_005cd220.md`
- Annotated: `docs/reconstruction/raw/aa_005cd220_FUN_005cd220.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGHBAICreatureBase_PathlessIdleRoam_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_005cd220.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_005cd220_CVOGHBAICreatureBase_PathlessIdleRoam_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_005cd220_CVOGHBAICreatureBase_PathlessIdleRoam_Inferred.md`
- Scaffold record: `docs/reconstruction/functions/aa_005cd220_FUN_005cd220.md`

## Callers / callees

| Dir | VA | Name |
|---|---|---|
| Caller | `0x005d0310` | `CVOGHBAICreatureBase_OnHeartBeat` |
| Callee | `0x007a4330` | `CVOGReaction_RandomUnitScalar` |
| Callee | `0x0053e0b0` | quat cache at object+0x28 |
| Callee | `0x004e8bf0` | `Math_QuatTransformPoint_Inferred` |
| Callee | vtbl | object `+0x1a4`, AI `+0x4c` |

## Constants (`read_memory`)

| VA | Value | Role |
|---|---|---|
| `0x00a1330c` | **3.0f** | if radius < 3 then radius += 3 |
| `0x00a10e74` | **2.0f** | scale (misnamed `g_flLevelUpUiBase_Inferred`) |
| `0x00aaa638` | **~1.525902e-5** | ~1/65536 ushort normalize |
| `0x00b041cc` | `g_dwClientTickMs` | cooldown clock |

## Confidence

| Claim | Level |
|---|---|
| Pathless idle roam / random local dest | **High** (caller + CF + NPC.md) |
| 1/3 gate + cooldown + radius formula | **Confirmed** (decomp + floats) |
| Quat transform via `0x004e8bf0` | **High** |
| Product English | **Inferred** |
| Exact multi-inherit ECX for vtbl+0x1a4 | **Medium** (decomp shape) |
| Runtime | **Open** |
