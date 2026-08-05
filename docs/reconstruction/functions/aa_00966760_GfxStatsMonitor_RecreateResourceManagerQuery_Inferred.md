# Function record: GfxStatsMonitor_RecreateResourceManagerQuery_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00966760` |
| **Canonical name** | `GfxStatsMonitor_RecreateResourceManagerQuery_Inferred` (**Inferred** structural + product log) |
| **Ghidra name** | `FUN_00966760` |
| **Address** | `0x00966760` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | graphics / gfxDevice Device Reset (Stats Monitor) |
| **Completion status** | **Dual sealed (A+B)** — W38-Z 2026-08-04 |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Scaffold seed: `Named_CalleeOf_Named_gfxDevice_00966760` (**reject** as product).
- Ghidra: `FUN_00966760`.
- Parent product fail string: `"Failed to Reset() device on Stats Monitor"`.

## Purpose

After `IDirect3DDevice9::Reset` (and after prior Release of the old query at `host+0x3d4`), recreate a **resource-manager query** for the Stats Monitor host:

1. `dev = *DAT_00d1f044` (`IDirect3DDevice9*`).
2. `CreateQuery(dev, D3DQUERYTYPE_RESOURCEMANAGER /*5*/, &host->query@+0x3d4)`.
3. Clear flag byte `host+0x3d8 = 0`.
4. On HRESULT failure, force `host->query = null`.
5. **Always return 0** (do not propagate CreateQuery HRESULT).

## Signature (machine-sealed)

```c
// Register: EDI = StatsMonitor host*  (parent loads device+0x79c)
// Stack: none
// Return: always 0
// Cleanup: plain RET (c3)
uint32_t GfxStatsMonitor_RecreateResourceManagerQuery_Inferred(/* EDI host */);
// body 0x00966760–0x0096678e inclusive (47 B / 0x2F)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00966760_FUN_00966760.md`
- Annotated: `docs/reconstruction/raw/aa_00966760_FUN_00966760.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/GfxStatsMonitor_RecreateResourceManagerQuery_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00966760.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00966760_GfxStatsMonitor_RecreateResourceManagerQuery_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00966760_GfxStatsMonitor_RecreateResourceManagerQuery_Inferred.md`
- Report: `docs/agents/task-dual-ab-00966760-00968680-w38z-report.md`

## Callers / callees

| Direction | VA | Name / role |
|---|---|---|
| Caller (1) | `FUN_0075eff0` @ `0x0075f313` | Device Reset success path; `MOV EDI,[device+0x79c]` then call |
| Callee | `IDirect3DDevice9::CreateQuery` | vtbl **`+0x1d8`** (method 118) |
| Global read | `DAT_00d1f044` | gfx wrapper; `*wrapper` = device9 |
| Sibling (not OWN) | `0x00966790` | Release + null query `@+0x3d4` |

## Host layout (partial, sealed)

| Offset | Role |
|---|---|
| `+0x3d4` | `IDirect3DQuery9*` (CreateQuery out / Release target) |
| `+0x3d8` | `uint8_t` flag cleared after recreate |

## Confidence

| Claim | Level |
|---|---|
| Control flow ≡ live bytes | **Confirmed** |
| CreateQuery + type 5 + out `+0x3d4` | **Confirmed** |
| Always `EAX=0` / plain RET | **Confirmed** |
| EDI host / parent `device+0x79c` | **Confirmed** |
| Subsystem = Stats Monitor (log English) | **Confirmed** (string) |
| Product C++ class / PDB name | **Open** |
| Flag `+0x3d8` product English | **Open** |
