# Function record: Host_ScreenToTerrainHitNotify_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005995a0` |
| **Canonical name** | `Host_ScreenToTerrainHitNotify_Inferred` |
| **Ghidra name** | `FUN_005995a0` |
| **Address** | `0x005995a0` |
| **Body range** | sealed **209** B to pad (exclusive end `0x00599671`); Ghidra meta `005995a0`–`00599670` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | world-terrain / screen pick → heightfield hit notify |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF + host offsets sealed; product class/vtbl English open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_005995a0_Host_ScreenToTerrainHitNotify_Inferred.md`, `reviews/B_aa_005995a0_Host_ScreenToTerrainHitNotify_Inferred.md` |
| **Last reviewed** | `2026-07-29` (W20-P) |

## Alias

- `FUN_005995a0` (Ghidra / scaffold)
- Residual: product host class / notify vfunc English

## Purpose

Host **thiscall** virtual method:

1. Null map `@+0x40` → return 0.
2. Screen ints `@+0x38/+0x3c` → unproject via `*(map+0xe890)` gfxView.
3. Pack float4 origin/dir (w=0) → `MarchDirToTerrain(map, …, maxSteps=400)`.
4. On hit: `(*(this+0x24))->vtbl[+0x5c](hitBuf)`; return 1; else 0.

DATA-only xref (vtbl slot `@0x009d55bc`).

## Signature

```c
// ECX = host*; bare ret; return 0/1
uint32_t __thiscall Host_ScreenToTerrainHitNotify_Inferred(void *host);
```

## Host layout

| Off | Role |
|----:|------|
| `+0x24` | notify target* (vtbl+0x5c hit callback) |
| `+0x38` | screen X (int) |
| `+0x3c` | screen Y (int) |
| `+0x40` | `CVOGMap*` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005995a0_FUN_005995a0.md` (+ W20-P append)
- Annotated: `docs/reconstruction/raw/aa_005995a0_FUN_005995a0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Host_ScreenToTerrainHitNotify_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_005995a0.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-005995a0-004e15a0-w20p-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_0075c340` (UnprojectScreenToWorldRay); `FUN_004cff70` (MarchDirToTerrain) |
| **Callers** | none direct; **DATA** vtbl `@0x009d55bc` |

## Confidence

| Claim | Level |
|---|---|
| CF unproject → pack → march 400 → notify | **High** |
| Host offsets +0x24/+0x38/+0x3c/+0x40 | **High** |
| map+0xe890 gfxView; march this=map | **High** |
| maxSteps 400; vtbl+0x5c | **High** |
| bare ret bool | **High** |
| Product host/notify names | Open (`_Inferred`) |
| Hit buffer beyond float4 | Residual |
| Runtime / bit-exact | Open |

## Related

- `aa_0075c340` GfxView_UnprojectScreenToWorldRay_Inferred
- `aa_004cff70` CVOGMap_MarchDirToTerrain_Inferred
- Consumers of MarchDir also: DriveControlTick, InteractClickPick (distinct units)
