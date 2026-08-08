# Function record: Gfx_BindMatDiffuseAmbientEmissive_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005194f0` |
| **Canonical name** | `Gfx_BindMatDiffuseAmbientEmissive_Inferred` |
| **Address** | `0x005194f0` |
| **Body** | `0x005194f0`–`0x00519657` (359 bytes → `ret`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | graphics / material FX |
| **Calling convention** | cdecl — `(shaderHost*, colorVec*)` void; callers `ADD ESP,8` |
| **Completion status** | **Dual A/B complete** — accept-with-gaps (2026-08-04 WQ9R-F) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- `FUN_005194f0` (Ghidra)
- **Rejected:** `Named_VOG_DEBUG_STOP_005194f0` (scaffold)

## Purpose

Bind packed **MatDiffuse / MatAmbient / MatEmissive** float4 triples from a color bank onto per-shader effect objects (`entry+0x20`), assert `shaderN*3 == colorN`, then **clear** the color vector (`FUN_0051def0` resize 0).

## Signature

```c
void Gfx_BindMatDiffuseAmbientEmissive_Inferred(void* shaderHost, void* colorVec);
```

## Behavioral summary (asm-sealed)

1. `shaderN = count_dword(host+0xc0, host+0xc4)`; `colorN = count_float4(colorVec+4, colorVec+8)`.
2. If `shaderN*3 != colorN`: `FUN_007a4480(0, "VOG_DEBUG_STOP")`.
3. Loop `i=0..shaderN-1` while color slots remain for `2+3*i`:
   - `this = *(host.begin + 4*i) + 0x20`
   - bind `"MatDiffuse"` / `"MatAmbient"` / `"MatEmissive"` at `color.begin + 0x30*i + {0,0x10,0x20}` via `FUN_009700f0`.
4. `FUN_0051def0(colorVec, 0)` with stack fill `(0,0,0,1.0)`.

## Strings / globals

| VA | Role |
|---|---|
| `0x00a2f8cc` | `"MatDiffuse"` |
| `0x00a2f8c0` | `"MatAmbient"` |
| `0x00a2f8b4` | `"MatEmissive"` |
| `0x00a15844` | `"VOG_DEBUG_STOP"` |
| `0x00a0f2a0` | `g_flOne` = 1.0f |

## Callers / callees

**Callers:** `FUN_0051b310` (`0051b345`), `FUN_004c5510` (`004c5553`).  
**Callees:** `FUN_007a4480`, `FUN_009700f0`, `FUN_0051def0`.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005194f0_FUN_005194f0.md`
- Annotated: `docs/reconstruction/raw/aa_005194f0_FUN_005194f0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Gfx_BindMatDiffuseAmbientEmissive_Inferred.cpp`
- Review A/B: `docs/reconstruction/reviews/A_aa_005194f0_…` / `B_aa_005194f0_…`
- Dual report: `docs/agents/task-dual-ab-005194f0-005197b0-wq9rf-report.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow + ABI | **High** |
| Mat* string names + triple stride | **High** |
| Product host type English | Tentative / Inferred |
