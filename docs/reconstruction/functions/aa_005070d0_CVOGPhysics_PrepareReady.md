# Function record: CVOGPhysics_PrepareReady

| Field | Value |
|---|---|
| **Stable ID** | `aa_005070d0` |
| **Canonical name** | `CVOGPhysics_PrepareReady` (inferred) |
| **Ghidra symbol** | `FUN_005070d0` |
| **Address** | `0x005070d0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `physics` |
| **Completion status** | **accept-with-gaps** — dual A/B sealed 2026-07-29 |
| **Bit-for-bit / runtime / diff** | Open (static dual only) |

## Alias

- Scaffold: `Named_CalleeOf_CVOGReaction_TeleportTarget_005070d0` (under-named; ≥64 callers)
- Ghidra: `FUN_005070d0`

## Purpose

Ensure physics **host** (`*(phys+0x44)`) is activated in **world/sim** (`*(phys+8)`) and marked ready (`host+0x29=1` via `FUN_0055eb80`). Shared write-enable paired with probe `FUN_005070b0` before rigid-body vtbl stores.

## Signature (asm-derived)

```c
void __fastcall CVOGPhysics_PrepareReady(void *phys);  // thiscall ECX=phys; ret
```

## Control flow (sealed)

1. `world = *(phys+8)`; if null → return.
2. `FUN_0055e490(world, phys)` — world list bookkeeping (interface only).
3. `host = *(phys+0x44)` — **no null check**.
4. If `*(u8*)(host+0x29)==0` **and** `*(i32*)(host+0x24)!=-1` → `FUN_0055eb80(world, host)` (sets ready=1).

Body size **0x2A** bytes.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005070d0_FUN_005070d0.md`
- Annotated: `docs/reconstruction/raw/aa_005070d0_FUN_005070d0.annotated.md`
- Clean (Ghidra name): `docs/reconstruction/reconstructed-exact/FUN_005070d0.cpp`
- Clean (canonical): `docs/reconstruction/reconstructed-exact/CVOGPhysics_PrepareReady.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_005070d0_CVOGPhysics_PrepareReady.md`
- Dual B: `docs/reconstruction/reviews/B_aa_005070d0_CVOGPhysics_PrepareReady.md`
- Prior scaffold record: `docs/reconstruction/functions/aa_005070d0_FUN_005070d0.md`

## Callers / callees

| Direction | Targets |
|---|---|
| **Callees** | `FUN_0055e490` @ `0x0055e490`, `FUN_0055eb80` @ `0x0055eb80` |
| **Sibling** | `FUN_005070b0` @ `0x005070b0` (probe) |
| **Callers** | ≥64 sites — SetAngularVelocity, ApplyImpulseVector, airStab, AVD, postTick, network soft, TeleportTarget, AI heading, … |

## Confidence

| Claim | Level |
|---|---|
| Control flow + call ABI from asm | **High** |
| Ready flag at host+0x29 set by activate | **High** |
| Parameter type English names | **Tentative** |
| Deep callee algorithms | **Open** (not dual-owned) |
