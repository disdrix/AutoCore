# Review A (reconstruction fidelity): `aa_004c1cb0` ParticleFluidPhase_CreateFluidParticles_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c1cb0` |
| **VA** | `0x004c1cb0`–`0x004c207c` exclusive (**972 B** / `0x3CC`) |
| **Canonical name** | `ParticleFluidPhase_CreateFluidParticles_Inferred` |
| **Ghidra name** | `FUN_004c1cb0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W34-N) |
| **Counterpart** | `reviews/B_aa_004c1cb0_ParticleFluidPhase_CreateFluidParticles_Inferred.md` |
| **System** | client / particle fluid phase |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `get_function_by_address` + `read_memory`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Product **CreateFluidParticles(capacity)** on the fluid phase host:

1. Store `+0xbc=capacity`, `+0xb8=capacity*4`; reject zero verts with product log.
2. Alloc particle array `capacity*0x70` + element construct path.
3. Alloc view `0x14c` @ `+0xac` and mesh `0xc4` @ `+0xb0`.
4. Bind `NDParticleFluid.fx` / `Particles.dds`; set `ParticleTexture`; optional `NormalMapTexture` from `+0x94`; optional `ReflectionSurface`.
5. Build VB/IB (`capacity*4` verts, `capacity*6` indices); fill indices; finalize mesh flags.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W34-N) | `docs/reconstruction/raw/aa_004c1cb0_FUN_004c1cb0.md` |
| Annotated | `docs/reconstruction/raw/aa_004c1cb0_FUN_004c1cb0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/ParticleFluidPhase_CreateFluidParticles_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004c1cb0.cpp` |
| Function records | `functions/aa_004c1cb0_FUN_004c1cb0.md`, `functions/aa_004c1cb0_ParticleFluidPhase_CreateFluidParticles_Inferred.md` |
| Related | Parent W33-S; peer fluid-bump `004c0a90`; InitPhases factory `push 0x7fff` |
| Live | body bounds; `mov esi,ecx`; capacity from stack; `RET 4`; sole xref `004c209b` |

---

## 3. Signature (sealed)

```c
// __thiscall; ECX=phase*; stack capacity; void; RET 4
void __thiscall ParticleFluidPhase_CreateFluidParticles_Inferred(void *phase, int capacity);
```

| Formal | Source | Conf |
|---|---|---|
| phase | ECX (`mov esi,ecx`) | **High** |
| capacity | stack after SEH (`[esp+0x10]` at entry) | **High** |
| cleanup | `RET 4` | **High** |
| product name | log `"CreateFluidParticles"` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ live)

```
verts = capacity * 4
phase+0xbc = capacity; phase+0xb8 = verts
if verts==0: log Invalid arg; return
particles = new[](capacity*0x70); construct; phase+0xb4 = particles
view = new(0x14c)+FUN_00764030 → +0xac
mesh = new(0xc4)+FUN_00748960 → +0xb0
bind FX/textures; optional nmap/reflect
VB/IB alloc+fill; mesh finalize
```

| Stage | Match | Conf |
|---|---|---|
| Body size / RET 4 | **Yes** | **High** |
| thiscall + capacity | **Yes** | **High** |
| Zero-capacity reject | **Yes** | **High** |
| Factory 0x7FFF | **Yes** (caller bytes) | **High** |
| Product strings | **Yes** | **High** |
| Nested ctor product English | residual | **Low** |

---

## 5. Gaps

- Product demangle for view/mesh/particle element classes.
- Whether capacity is tunable beyond Init hardcode.
- Mesh flag `+0xac=5` / busy bit product enum.
- Runtime / bit-exact / differential / partial OOM.

---

## 6. Verdict

Reconstruction fidelity sealed for ABI, capacity field map, product CreateFluidParticles naming, material strings, VB/IB scaling, and sole Init wiring with 0x7FFF. Nested free units → **accept-with-gaps**.
