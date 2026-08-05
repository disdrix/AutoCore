# Function record: GameUtils_createRagDoll

| Field | Value |
|---|---|
| **Stable ID** | `aa_005f44c0` |
| **Canonical name** | `GameUtils_createRagDoll` |
| **Ghidra name** | `FUN_005f44c0` |
| **Address** | `0x005f44c0`–`0x005f4ed9` (**2586 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | GameUtils / ragdoll |
| **Completion status** | **Dual-sealed 2026-07-29 W26-F** — plate name + CF stages + A/B; nested helpers residual |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias history

| Name | Status |
|---|---|
| `GameUtils_createRagDoll` | **Canonical** (plate `GameUtils::createRagDoll`) |
| `Named_GameUtils_createRagDoll` | prior scaffold alias |
| `Named_CalleeOf_Named_SkyBoxParticles_005f44c0` | **superseded** (mis-tag from caller bulk) |

## Purpose

Build a ragdoll binding for an object from a ragdoll buffer + gfx Body skeleton: validate params, parse buffer bone count, match bone names (space→`_`), build pose/parent maps and subsystem objects, store results on the owner context. Returns **1** on full match success, **0** on any failure path.

## Signature (sealed)

```c
// cdecl; EAX = 0|1
uint32_t GameUtils_createRagDoll(int param_1, int param_2, int param_3);
```

| Formal | Role | Conf |
|---|---|---|
| param_1 | buffer / parse input to `FUN_005f4380` | **High** (use sites) |
| param_2 | paired parse input / size-like | **High** |
| param_3 | owner context (Body @+0x914, outs @+0x50..+0x5c) | **High** |
| return | 0 fail / 1 success | **High** |

## Control flow (summary)

Validate → init → parse count → limit checks (`<0x21`, `<0x41`) → grow vectors → per-bone name match/maps/poses → success build outs / fail log bones-not-found → return.

## Callers / callees

| Dir | Symbol | Notes |
|---|---|---|
| Caller | `FUN_005911b0` | sets `@+0x90d` bit2 from result |
| Callee | many | see raw W26-F list; includes `FUN_00560e90`, `FUN_007a4480`, string ops |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005f44c0_FUN_005f44c0.md` (+ W26-F append)
- Annotated: `docs/reconstruction/raw/aa_005f44c0_FUN_005f44c0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/GameUtils_createRagDoll.cpp`
- Clean twins: `FUN_005f44c0.cpp`, `Named_GameUtils_createRagDoll.cpp`
- Reviews: `A_aa_005f44c0_GameUtils_createRagDoll.md`, `B_aa_005f44c0_GameUtils_createRagDoll.md`

## Confidence

| Claim | Level |
|---|---|
| Plate product name | **High** (embedded strings) |
| CF stages / return 0\|1 | **High** |
| cdecl SEH frame / body bounds | **High** |
| Param_3 owner offsets | **High** (decompile + use) |
| Nested helper semantics | **Medium** (residual duals) |
| Runtime | **Open** |
