# Function record: CVOGCreature_FindTerrainHeight

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c6100` |
| **Canonical name** | `CVOGCreature_FindTerrainHeight` |
| **Address** | `0x004c6100` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | world / creature movement |
| **Completion status** | **Human-refined scaffold** — clean rewritten from raw; dual review open; castRay out-param packing still SEH/stack-coupled |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Ground-snap a creature to terrain height under a world XZ sample. Adds foot offset at `this+0x120`. Used by AI/movement; static IsNPC path may skip and rely on server-elevated Y.

## Signature (decompiler-derived + refined)

```c
long double __thiscall CVOGCreature_FindTerrainHeight(
    int* thisCreature, uint32_t* pWorldPos /* X,Y,Z */, float flBias);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004c6100_CVOGCreature_FindTerrainHeight.md`
- Annotated: `docs/reconstruction/raw/aa_004c6100_CVOGCreature_FindTerrainHeight.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGCreature_FindTerrainHeight.cpp`

## Callers / callees

| Direction | Symbol / VA | Notes |
|---|---|---|
| Callee | `FUN_004cd220` | Heightfield sample (x,z) |
| Callee | `CVOGMap_CastTerrainHeight` `0x004cfe60` | Map cast when no physics body |
| Callee | `FUN_00580ed0` castRay | Physics vertical ray |
| Callee | profile enter/leave `FUN_0076cf00` / `FUN_0076cef0` | Scoped timing |
| Callers | AI / movement (xrefs follow-up) | |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Foot offset at +0x120 | High (plate + return) |
| bLocal via sector+0xe8a0 vfunc+0x1d8 | Probable |
| castRay filter `5` / `5\|0xd` when local | High (raw) |
| Full ray / hit-out struct layout | Tentative (stack-coupled to aa_00580ed0) |
