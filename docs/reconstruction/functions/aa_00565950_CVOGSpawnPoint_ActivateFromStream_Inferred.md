# Function record: CVOGSpawnPoint_ActivateFromStream_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00565950` |
| **Canonical name** | `CVOGSpawnPoint_ActivateFromStream_Inferred` |
| **Ghidra name** | `FUN_00565950` |
| **Address** | `0x00565950`–`0x00566485` (**2870 B / `0xB36`**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client spawn-point stream unpack + activation |
| **Completion status** | **Sealed (W30-H)** — dual A/B accept-with-gaps (schema atlas residual) |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Alias

- Scaffold: `FUN_00565950`
- Prior plate: `Named_BAD_SPAWN_POINT_ACTIVATION_RANGE` (string-only; too narrow)

## Purpose

Unpack versioned spawn-point activation data from a stream into a CVOGSpawnPoint MI subobject, apply world offset, clamp bad activation range to **75.0f**, optionally create linked spawn entities, and insert race/slot map entries.

## Signature (byte-sealed)

```c
// thiscall; ret 0x10 (16 B stack)
// returns 0 if stream==null, else 1
uint32_t CVOGSpawnPoint_ActivateFromStream_Inferred(
    void *spawn_subobject,  // ECX — MI; negative field offsets
    void *stream,           // null → 0
    int version,
    float *world_offset4);
// + fourth stack dword cleaned by ret 0x10 (role unsealed)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00565950_FUN_00565950.md`
- Annotated: `docs/reconstruction/raw/aa_00565950_FUN_00565950.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGSpawnPoint_ActivateFromStream_Inferred.cpp`
- Clean twin (full CF body): `docs/reconstruction/reconstructed-exact/FUN_00565950.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00565950_CVOGSpawnPoint_ActivateFromStream_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00565950_CVOGSpawnPoint_ActivateFromStream_Inferred.md`
- Report: `docs/agents/task-dual-ab-00565950-00518370-w30h-report.md`

## Callers / callees

**CODE entry:** MI this-adjustor thunk `0x00567CBE` → sole direct xref to body (vtable-facing).

**Callees (selected):** stream vtbl+`0x14` reads; `sprintf` / `OutputDebugStringA`; `FUN_005630f0`; `FUN_00512460`; `FUN_00567860` (W29-M)×2; `FUN_0040b330`; `Object_GetRootRaceId`; `operator_new` / spawn helpers `FUN_0057b0e0`, `FUN_005dbfa0`; `FUN_004bc180`; `FUN_00512160`; `FUN_00418e60`.

## Confidence

| Claim | Level |
|---|---|
| Body bounds + `ret 0x10` + return 0/1 | **Confirmed** |
| Product strings + 75.0f default | **Confirmed** |
| Stream unpack + version gates | **Confirmed** (CF) |
| CVOGSpawnPoint family name | **Inferred** (strings + neighbor names + layout) |
| Full field product atlas | **Tentative** / open |
| Fourth stack formal role | Open |
| Runtime golden | Open |
