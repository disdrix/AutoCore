# Dual A/B report — W34-N OWN-ONLY (`0x004c0a90`, `0x004c1cb0`)

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W34-N  
**Scope:** VAs `0x004c0a90`, `0x004c1cb0` only. Dual A/B + artifacts (trio + function + A/B).  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `batch_decompile` / `analyze_function_complete` / `get_function_by_address` / `read_memory` (+ callers/callees/xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave34_partition_map.md` → **W34-N**.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004c0a90` ParticleFluidPhase_InitFluidBumpChild_Inferred | **accept-with-gaps** — ECX phase* / RET / 0x198 child @+0x9c / near0.2 far500 / bump+blend FX strings / sole Init caller sealed; nested 0x198 class English residual |
| `aa_004c1cb0` ParticleFluidPhase_CreateFluidParticles_Inferred | **accept-with-gaps** — thiscall+capacity+RET4 / CreateFluidParticles product logs / field map +0xb4..+0xbc / factory 0x7FFF sealed; nested view/mesh/VB helpers residual |

---

## VA `0x004c0a90` — sealed facts

1. **Body:** `0x004c0a90`–`0x004c0c41` exclusive (**433 B** / `0x1B1`). Final **`C3`** (`RET`); pad `CC`. SEH `LAB_009a19e3`.
2. **ABI:** **ECX=`phase*`** (`mov esi,ecx`); **0** stack formals; **void**; plain **`RET`**. Decompiler `__fastcall` matches.
3. **Semantics:** Install fluid-bump render child on ParticleFluidPhase host:
   - `new(0x198)` + `FUN_00968a50` → `phase+0x9c`
   - `child+0x195 |= 0x40`; `child+4 = phase`
   - `GfxView_SetNear_Inferred(0.2f)` (`0x3e4ccccd`); far twin `FUN_0075b390(500.0f)` (`0x43fa0000`); `FUN_0075bf40(0x808080)`
   - dirties / device vtbl+0x18; `phase+0x94 = child+0x44`
   - load `Particle_Fluid_bump.dds` + `NDParticleFluidBlendNormal.fx`; shader param `NormalMapTexture`
4. **Classification:** worker.
5. **Callers (1):** `FUN_004c2080` (`ParticleFluidPhase_Init_Inferred`, W33-S) @ `0x004c208f`.
6. **Callees:** `operator_new`, `FUN_00968a50`, `FUN_0075b3b0` (`GfxView_SetNear_Inferred`), `FUN_0075b390`, `FUN_0075bf40`, `FUN_0075b450`, child vtbl+0x18, string/FX helpers (`FUN_00989e00` / `FUN_0096f3e0` / `FUN_009701d0` / `FUN_00970140` / `FUN_0096ef70` / `FUN_0096efd0`).
7. **Name:** `ParticleFluidPhase_InitFluidBumpChild_Inferred` (Ghidra `FUN_004c0a90`). Alias registry `Gfx_NDParticleFluidBlendNormal`. **Reject** scaffold `Named_CalleeOf_*_Drive_NDRiver_fx_004c0a90`.
8. **Decompile ≡ raw CF** (live 2026-07-29 ≡ 2026-07-23); ABI + floats sealed by `read_memory`.

### Gaps

- Product demangle for `FUN_00968a50` / 0x198 class (GfxView-compatible, not plain 0x150 GfxView).  
- Product English for `FUN_0075bf40` / `FUN_0075b450` / vtbl+0x18.  
- Flag `+0x195` bit `0x40` meaning.  
- Runtime / bit-exact / differential / OOM null-child.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004c0a90_ParticleFluidPhase_InitFluidBumpChild_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004c0a90_ParticleFluidPhase_InitFluidBumpChild_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ W34-N) | `docs/reconstruction/raw/aa_004c0a90_FUN_004c0a90.md` |
| Annotated | `docs/reconstruction/raw/aa_004c0a90_FUN_004c0a90.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ParticleFluidPhase_InitFluidBumpChild_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004c0a90.cpp` |
| Function | `docs/reconstruction/functions/aa_004c0a90_FUN_004c0a90.md` |
| Function named | `docs/reconstruction/functions/aa_004c0a90_ParticleFluidPhase_InitFluidBumpChild_Inferred.md` |

---

## VA `0x004c1cb0` — sealed facts

1. **Body:** `0x004c1cb0`–`0x004c207c` exclusive (**972 B** / `0x3CC`). Final **`C2 04 00`** (`RET 4`); pad `CC`. SEH `LAB_009a1b4a`.
2. **ABI:** **`__thiscall`**; ECX=`phase*`; stack formal **capacity**; **void**; **`RET 4`**.
3. **Semantics:** Product **CreateFluidParticles(capacity)**:
   - `phase+0xbc = capacity`; `phase+0xb8 = capacity*4`; reject verts==0 with `"Invalid arg to CreateFluidParticles %u"`
   - particle array `capacity*0x70` @ `+0xb4` via `operator_new[]` + `FUN_00404d80(..., 0x1c, verts, FUN_005edf20)`
   - view `new(0x14c)+FUN_00764030` @ `+0xac`; mesh `new(0xc4)+FUN_00748960` @ `+0xb0`
   - bind `NDParticleFluid.fx` + `Particles.dds`; `ParticleTexture`; optional `NormalMapTexture` from `+0x94`; optional `ReflectionSurface` via `FUN_005b3400`
   - VB (`capacity*4` verts) + IB (`capacity*6` indices); fill `FUN_004c05d0`; mesh flags `+0xa8=0`, `+0xac=5`; `FUN_007647c0`
4. **Classification:** worker.
5. **Callers (1):** `FUN_004c2080` @ `0x004c209b` — always **`push 0x7fff`** (32767).
6. **Callees:** alloc/ctors, FX bind path, VB/IB helpers, `FUN_007a4480` (error logs), `FUN_0096efd0` (see annotated).
7. **Name:** `ParticleFluidPhase_CreateFluidParticles_Inferred` (Ghidra `FUN_004c1cb0`). Product log stem **CreateFluidParticles**. Alias registry `Gfx_NDParticleFluid`. **Reject** scaffold `Named_CalleeOf_*_Drive_NDRiver_fx_004c1cb0`.
8. **Decompile ≡ raw CF**; ABI sealed by `read_memory` (capacity load + `RET 4`). Early `cmp 0xffff` is redundant; only zero capacity rejects.

### Gaps

- Product demangle for view/mesh/particle-element classes.  
- Capacity product tunability beyond Init hardcode.  
- Mesh flag enum for `+0xac=5` / busy bit.  
- Runtime / bit-exact / differential / partial OOM.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004c1cb0_ParticleFluidPhase_CreateFluidParticles_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004c1cb0_ParticleFluidPhase_CreateFluidParticles_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ W34-N) | `docs/reconstruction/raw/aa_004c1cb0_FUN_004c1cb0.md` |
| Annotated | `docs/reconstruction/raw/aa_004c1cb0_FUN_004c1cb0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ParticleFluidPhase_CreateFluidParticles_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004c1cb0.cpp` |
| Function | `docs/reconstruction/functions/aa_004c1cb0_FUN_004c1cb0.md` |
| Function named | `docs/reconstruction/functions/aa_004c1cb0_ParticleFluidPhase_CreateFluidParticles_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004c0a90` | Port as **phase helper** after EnsureAuxPtrs: install 0x198 fluid-bump child at `+0x9c`, near **0.2** / far **500**, bind Fluid_bump dds + FluidBlendNormal fx, cache texture at `+0x94`. ECX=phase (not env). Plain RET. |
| `004c1cb0` | Port as **CreateFluidParticles(capacity)** on same phase: store capacity/verts, reject 0, alloc particles+view+mesh, bind NDParticleFluid.fx, build VB/IB. Factory capacity **32767**. thiscall + RET 4. Prefer after bump child so `+0x94` is set. |
| Pair with | `ParticleFluidPhase_Init_Inferred` (`0x004c2080`, W33-S); phase ctor residual `FUN_004c0640` (W34-M); secondary child `FUN_004c1960` (W34-O); `GfxView_SetNear_Inferred` (`0x0075b3b0`, W31-O); InitPhases `0x0048fc90` (W31-P). |

### Lifecycle (sealed relative order)

```
PalantirEnv_InitPhases:
  phase = new(0xC8) ? FUN_004c0640(parent) : 0
  env+0xCC = phase
  ParticleFluidPhase_Init(phase, 1)
    → HostBase_EnsureAuxPtrs(phase, 1)
    → InitFluidBumpChild(phase)           // this dual 004c0a90
    → CreateFluidParticles(phase, 0x7fff) // this dual 004c1cb0
    → FUN_004c1960(phase)                 // W34-O residual
```

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + get_function_by_address + read_memory (+ callers/xrefs). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates: CreateFluidParticles from log strings; fluid-bump name from dds/fx; `_Inferred` for phase method structure.  
- Rejected scaffold Drive_NDRiver_fx names.  
- Pattern: `docs/agents/task-dual-ab-00442c80-004c2080-w33s-report.md`.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
