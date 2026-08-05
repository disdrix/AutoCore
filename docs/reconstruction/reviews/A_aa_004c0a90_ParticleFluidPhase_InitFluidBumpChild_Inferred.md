# Review A (reconstruction fidelity): `aa_004c0a90` ParticleFluidPhase_InitFluidBumpChild_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c0a90` |
| **VA** | `0x004c0a90`–`0x004c0c41` exclusive (**433 B** / `0x1B1`) |
| **Canonical name** | `ParticleFluidPhase_InitFluidBumpChild_Inferred` |
| **Ghidra name** | `FUN_004c0a90` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W34-N) |
| **Counterpart** | `reviews/B_aa_004c0a90_ParticleFluidPhase_InitFluidBumpChild_Inferred.md` |
| **System** | client / particle fluid phase |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `get_function_by_address` + `read_memory`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Install fluid-bump / blend-normal render child on the ParticleFluidPhase host:

1. `new(0x198)` + `FUN_00968a50` → `phase+0x9c`
2. Flag `child+0x195 |= 0x40`; parent link `child+4 = phase`
3. `GfxView_SetNear(0.2f)` + far `500.0f` + color `0x808080` + dirties
4. Device vtbl+0x18; cache `phase+0x94 = child+0x44`
5. Load `Particle_Fluid_bump.dds` + `NDParticleFluidBlendNormal.fx`; set `NormalMapTexture`

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W34-N) | `docs/reconstruction/raw/aa_004c0a90_FUN_004c0a90.md` |
| Annotated | `docs/reconstruction/raw/aa_004c0a90_FUN_004c0a90.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/ParticleFluidPhase_InitFluidBumpChild_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004c0a90.cpp` |
| Function records | `functions/aa_004c0a90_FUN_004c0a90.md`, `functions/aa_004c0a90_ParticleFluidPhase_InitFluidBumpChild_Inferred.md` |
| Related | Parent W33-S `ParticleFluidPhase_Init`; SetNear W31-O; InitPhases W31-P |
| Live | body bounds; prologue `mov esi,ecx`; epilogue `RET`; imm floats; sole xref `004c208f` |

---

## 3. Signature (sealed)

```c
// ECX=phase*; 0 stack formals; void; plain RET
void __fastcall ParticleFluidPhase_InitFluidBumpChild_Inferred(void *phase);
```

| Formal | Source | Conf |
|---|---|---|
| phase | ECX (`mov esi,ecx`) | **High** |
| stack formals | none (`C3` not `C2 04 00`) | **High** |
| return | void | **High** |

---

## 4. Control flow (clean ≡ raw ≡ live)

```
child = new(0x198) ? FUN_00968a50 : 0
phase+0x9c = child
child+0x195 |= 0x40; child+4 = phase
SetNear(0.2f); SetFar(500.0f); color 0x808080; dirties
vtbl+0x18(device pair); phase+0x94 = child+0x44
load bump dds + blend-normal fx; NormalMapTexture
```

| Stage | Match | Conf |
|---|---|---|
| Body size / RET | **Yes** | **High** |
| ECX this | **Yes** | **High** |
| Float imms 0.2 / 500 | **Yes** (`0x3e4ccccd` / `0x43fa0000`) | **High** |
| Strings | **Yes** | **High** |
| Sole caller Init | **Yes** | **High** |

---

## 5. Gaps

- Product demangle for `FUN_00968a50` / 0x198 class.
- Product English for `FUN_0075bf40`, `FUN_0075b450`, vtbl+0x18.
- Flag `+0x195` bit 0x40 product meaning.
- Runtime / bit-exact / differential / OOM path.

---

## 6. Verdict

Reconstruction fidelity sealed for ABI, body bounds, child install site, near/far constants, material strings, and sole Init wiring. Nested free class/method English → **accept-with-gaps**.
