# Dual A/B report — W33-S OWN-ONLY (`0x00442c80`, `0x004c2080`)

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W33-S  
**Scope:** VAs `0x00442c80`, `0x004c2080` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `decompile_function` / `batch_decompile` / `analyze_function_complete` / `get_function_by_address` / `read_memory` (+ callers/callees/xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave33_partition_map.md` → **W33-S**.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00442c80` HostAux14_Ctor_Inferred | **accept** — leaf 58 B / stack self* / RET4 / vtbl+zeros / sole EnsureAuxPtrs caller sealed; product residual only |
| `aa_004c2080` ParticleFluidPhase_Init_Inferred | **accept-with-gaps** — thiscall+RET4 / Ensure→bump→CreateFluidParticles(0x7FFF)→child / sole InitPhases site sealed; nested free residual |

---

## VA `0x00442c80` — sealed facts

1. **Body:** `0x00442c80`–`0x00442cba` exclusive (**58 B** / `0x3A`). Final **`C2 04 00`** (`RET 4`); pad `CC`. SEH handler `0x009bcb48`.
2. **ABI:** Stack formal **`self*`** (after SEH loads from `[esp+0x10]`); **not** ECX thiscall entry; returns **self in EAX** (MSVC ctor); **`RET 4`**.
3. **Semantics:** Construct **0x14** host-aux object:
   - `+0` = `PTR_FUN_00a9f49c` (vtbl).
   - `+4` **untouched**.
   - `+8/+0xc/+0x10` = 0.
4. **Classification:** leaf — no callees.
5. **Callers (1):** `FUN_00756320` (`HostBase_EnsureAuxPtrs_Inferred`, W32-Q) @ `0x00756375` — `push raw; call; mov [host+8], eax` after `operator_new(0x14)`.
6. **Name:** `HostAux14_Ctor_Inferred` (Ghidra `FUN_00442c80`). **Reject** scaffold `Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_00442c80`.
7. **Decompile ≡ bytes** for field stores (live 2026-07-29 ≡ raw 2026-07-23). Full hex in raw W33-S section.

### Gaps

- Product/PDB class English for `PTR_FUN_00a9f49c`.  
- Vtable method roles.  
- Meaning of untouched `+4`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00442c80_HostAux14_Ctor_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00442c80_HostAux14_Ctor_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00442c80_FUN_00442c80.md` |
| Annotated | `docs/reconstruction/raw/aa_00442c80_FUN_00442c80.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/HostAux14_Ctor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00442c80.cpp` |
| Function | `docs/reconstruction/functions/aa_00442c80_FUN_00442c80.md` |
| Function named | `docs/reconstruction/functions/aa_00442c80_HostAux14_Ctor_Inferred.md` |

---

## VA `0x004c2080` — sealed facts

1. **Body:** `0x004c2080`–`0x004c20ad` exclusive (**45 B** / `0x2D`). Final **`C2 04 00`** (`RET 4`); pad `CC`.
2. **ABI:** **`__thiscall`**; ECX=`phase*` (`mov esi,ecx` — decompiler omits); stack formal **flags**; returns **0** (`XOR EAX,EAX`); **`RET 4`**.
3. **Semantics:** Fluid-particle **phase enable** on `FUN_004c0640` host (env+0xCC):
   - `HostBase_EnsureAuxPtrs(phase, flags)` (`FUN_00756320`).
   - `FUN_004c0a90(phase)` — fluid-bump child @ `+0x9c` (`Particle_Fluid_bump.dds`, `NDParticleFluidBlendNormal.fx`).
   - `FUN_004c1cb0(phase, 0x7fff)` — CreateFluidParticles capacity **32767** (`NDParticleFluid.fx`, `Particles.dds`).
   - `FUN_004c1960(phase)` — child @ `+0xc4` (0x40).
4. **Classification:** worker.
5. **Callers (1):** `FUN_0048fc90` (`PalantirEnv_InitPhases_Inferred`, W31-P) @ `0x0048fe62` — after `new(0xC8)+FUN_004c0640(parent)→env+0xCC`: `push 1; mov ecx,eax; call`.
6. **Callees:** `FUN_00756320`, `FUN_004c0a90`, `FUN_004c1cb0`, `FUN_004c1960`.
7. **Name:** `ParticleFluidPhase_Init_Inferred` (Ghidra `FUN_004c2080`). **Reject** scaffold `Named_CalleeOf_Drive_NDRiver_fx_004c2080` (NDRiver is InitPhases tail, not this body).
8. **Decompile ≡ CF order**; thiscall + constant sealed by `read_memory` (full 45 B hex in raw W33-S section).

### Gaps

- Product demangle for phase class (`FUN_004c0640` / `PTR_FUN_009cb62c`).  
- Nested free units product English / ownership.  
- Capacity 0x7FFF product tunability.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004c2080_ParticleFluidPhase_Init_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004c2080_ParticleFluidPhase_Init_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004c2080_FUN_004c2080.md` |
| Annotated | `docs/reconstruction/raw/aa_004c2080_FUN_004c2080.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ParticleFluidPhase_Init_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004c2080.cpp` |
| Function | `docs/reconstruction/functions/aa_004c2080_FUN_004c2080.md` |
| Function named | `docs/reconstruction/functions/aa_004c2080_ParticleFluidPhase_Init_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00442c80` | Port as **stack-self\* ctor** of 0x14 aux: vtbl `PTR_FUN_00a9f49c`, zero +8/+0xc/+0x10, leave +4, return self, **RET 4**. Only from `HostBase_EnsureAuxPtrs` after `new(0x14)`. Do **not** invent ECX thiscall entry. Do **not** use VOG_DEBUG_STOP scaffold name. |
| `004c2080` | Port as **phase method** on `FUN_004c0640` instance at env+0xCC: `Init(phase, flags=1)` → EnsureAuxPtrs → fluid-bump child → CreateFluidParticles(0x7FFF) → +0xc4 child; returns 0. Do **not** treat as PalantirEnv method. Do **not** name from NDRiver.fx. Nested creates stay free until owned. |
| Pair with | `HostBase_EnsureAuxPtrs_Inferred` (`0x00756320`, W32-Q); `PalantirEnv_InitPhases_Inferred` (`0x0048fc90`, W31-P); phase ctor `FUN_004c0640`; sibling enables `FUN_0055cc50` / `FUN_005b39a0` (W33-T). |

### Lifecycle (sealed relative order)

```
FUN_007560d0(host)                    // zeros host+4/+8
...
// Ensure path (many callers):
HostBase_EnsureAuxPtrs(host, flags)
  → if bit0: host+4 = FUN_00986070(...)
  → host+8 = HostAux14_Ctor(new(0x14))   // this dual's 00442c80

// InitPhases owned fluid phase:
phase = new(0xC8) ? FUN_004c0640(parent) : 0
env+0xCC = phase
ParticleFluidPhase_Init(phase, 1)        // this dual's 004c2080
  → EnsureAuxPtrs(phase, 1)              // may install HostAux14 at phase+8
  → fluid-bump / CreateFluidParticles(0x7fff) / +0xc4 child
```

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers/xrefs/body bounds). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; `_Inferred` structural names only (HostAux14 from size+Ensure consumer; ParticleFluidPhase from CreateFluidParticles / NDParticleFluid nested strings + InitPhases wiring).  
- Rejected scaffold parent-seed / VOG_DEBUG_STOP / Drive_NDRiver_fx names.  
- Pattern: `docs/agents/task-dual-ab-0048f2d0-00756320-w32q-report.md`, `docs/agents/task-dual-ab-00492dd0-0048fc90-w31p-report.md`.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
