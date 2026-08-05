# Function record: CVOGEnvironmentReflect_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b35a0` |
| **Canonical name** | `CVOGEnvironmentReflect_ctor` |
| **Ghidra name** | `FUN_005b35a0` |
| **Address** | `0x005b35a0` |
| **Body range** | `0x005b35a0`–`0x005b366f` exclusive (**207 B** / `0xCF`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / VOGEnvironmentSector / fog+reflect phase |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; RTTI + CF + ABI + factory sealed; base/matrix product names open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_005b35a0_CVOGEnvironmentReflect_ctor.md`, `reviews/B_aa_005b35a0_CVOGEnvironmentReflect_ctor.md` (2026-07-29 W32-T) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_005b35a0`
- `Named_CalleeOf_Drive_NDRiver_fx_005b35a0` (**reject**)
- Class RTTI: `CVOGEnvironmentReflect` (**Confirmed**)

## Purpose

Construct the owned **environment reflect / fog** phase host (size **0x170**):

1. `FUN_007560d0` base
2. Install vtbl `PTR_FUN_009d95a0`
3. Init matrix sub at `+0x90` via `FUN_00972cc0`
4. Wire parent + nested `parent+0xE4E8` / `parent+0xE894`
5. Stamp matrix floats **(1, -1, 1)** via `FUN_0044b440`; optional `FUN_00972e50`
6. Set enable flags `+0x78` / `+0x80` = 1

Factory stores result at env`+0xC4` and calls `FUN_005b39a0(1)`. Virtual apply is `FUN_005b36f0` (vtbl[1], W29-I).

## Signature

```c
CVOGEnvironmentReflect* __thiscall CVOGEnvironmentReflect_ctor(
    CVOGEnvironmentReflect* this,
    void* parent);   // env parent @ factory env+0xB8
// ret 4; returns this
```

## Algorithm

```
SEH LAB_009a67ed
FUN_007560d0(this)
*this = CVOGEnvironmentReflect_vtbl
FUN_00972cc0(this+0x90)
this+0x15C = parent
this+0x158 = 0
this+0x160 = *(parent+0xE4E8)
this+0x150 = this+0x154 = 0
this+0x164 = *(parent+0xE894)
FUN_0044b440(this+0x90, 1.0f, -1.0f, 1.0f)
if (this+0x14C bit0): FUN_00972e50(this+0x90)
*(u8*)(this+0x78) = 1
*(u8*)(this+0x80) = 1
return this
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005b35a0_FUN_005b35a0.md`
- Annotated: `docs/reconstruction/raw/aa_005b35a0_FUN_005b35a0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGEnvironmentReflect_ctor.cpp`
- Alias clean: `docs/reconstruction/reconstructed-exact/FUN_005b35a0.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_005b35a0_FUN_005b35a0.md`
- Review A/B: as above
- Apply peer: `functions/aa_005b36f0_Env_ApplyFogShaderAndReflect_Inferred.md`
- Report: `docs/agents/task-dual-ab-00576ed0-005b35a0-w32t-report.md`

## Callers / callees

| Direction | VA | Name / role |
|---|---|---|
| Callee | `0x007560d0` | base ctor (shared phase-like) |
| Callee | `0x00972cc0` | matrix/transform default @ `+0x90` |
| Callee | `0x0044b440` | float stamp (1,-1,1) on matrix |
| Callee | `0x00972e50` | optional matrix post (flag `+0x14C`) |
| Caller | `0x0048fc90` @ `0x0048fdc7` | `PalantirEnv_InitPhases_Inferred` (sole) |
| Related | `0x005b3670` / `0x005b3a30` | body / scalar dtor |
| Related | `0x005b36f0` | vtbl[1] fog+reflect apply |
| Related | `0x005b39a0` | post-ctor enable(1) |

## Confidence

| Claim | Level |
|---|---|
| Control flow + bytes + `ret 4` | **Confirmed** |
| Vtbl / RTTI = `CVOGEnvironmentReflect` | **Confirmed** |
| Alloc 0x170 + sole factory + parent wires | **Confirmed** |
| Matrix sub @ `+0x90`; flags `+0x78`/`+0x80` | **Confirmed** |
| Float triple (1,-1,1) | **Confirmed** (read_memory) |
| Product English for base / matrix helpers | **Open** |
| Runtime / differential | Open |
