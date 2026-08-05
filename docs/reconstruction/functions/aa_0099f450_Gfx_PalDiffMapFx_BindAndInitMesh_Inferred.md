# Function record: Gfx_PalDiffMapFx_BindAndInitMesh_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0099f450` |
| **Canonical name** | `Gfx_PalDiffMapFx_BindAndInitMesh_Inferred` |
| **Ghidra name** | `FUN_0099f450` |
| **Address** | `0x0099f450`–`0x0099f5c3` (**372 B** / `0x174`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | gfx / PalDiffMap.fx host init |
| **Completion status** | **Dual A/B sealed** (W36-I) — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |

## Naming basis

- Embedded `"PalDiffMap.fx"` + Mat* parameter strings (structural).
- Role: bind effect → material params → mesh init (`0099f270`).
- **Inferred** — no PDB. Reject scaffold-only `Gfx_PalDiffMap_0099f450` without BindAndInitMesh.

## Signature

```c
uint32_t __stdcall Gfx_PalDiffMapFx_BindAndInitMesh_Inferred(
    void* host, uint32_t scale_bits /*float*/);
// optional EAX third formal (unused at sole sealed caller)
```

## Artifacts

See `aa_0099f450_FUN_0099f450.md`.

## Dual verdict

| Review | Verdict |
|--------|---------|
| A | **accept-with-gaps** |
| B | **accept-with-gaps** |
