# Review A (reconstruction fidelity): `aa_004c2080` ParticleFluidPhase_Init_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c2080` |
| **VA** | `0x004c2080`–`0x004c20ad` exclusive (**45 B** / `0x2D`) |
| **Canonical name** | `ParticleFluidPhase_Init_Inferred` |
| **Ghidra name** | `FUN_004c2080` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W33-S) |
| **Counterpart** | `reviews/B_aa_004c2080_ParticleFluidPhase_Init_Inferred.md` |
| **System** | client / particle fluid phase |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` + callee batch_decompile + InitPhases call site. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Phase-enable method on the fluid-particle host (`FUN_004c0640`, env+0xCC):

1. `HostBase_EnsureAuxPtrs(phase, flags)`.
2. `FUN_004c0a90(phase)` — fluid-bump / blend FX child @ `+0x9c`.
3. `FUN_004c1cb0(phase, 0x7fff)` — CreateFluidParticles capacity **32767**.
4. `FUN_004c1960(phase)` — secondary child @ `+0xc4`.
5. Return **0**.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W33-S) | `docs/reconstruction/raw/aa_004c2080_FUN_004c2080.md` |
| Annotated | `docs/reconstruction/raw/aa_004c2080_FUN_004c2080.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/ParticleFluidPhase_Init_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004c2080.cpp` |
| Function records | `functions/aa_004c2080_FUN_004c2080.md`, `functions/aa_004c2080_ParticleFluidPhase_Init_Inferred.md` |
| Related | InitPhases W31-P; EnsureAuxPtrs W32-Q; ctor `FUN_004c0640` |
| Live | body hex; call site `0x0048fe50` `push 1; mov ecx,eax; call`; callees sealed |

---

## 3. Signature (sealed)

```c
// __thiscall; ECX=phase*; stack flags; RET 4; returns 0
uint32_t __thiscall ParticleFluidPhase_Init_Inferred(void *phase, uint32_t flags);
```

| Formal | Source | Conf |
|---|---|---|
| phase | ECX (`mov esi,ecx`) | **High** |
| flags | stack `[esp+4]` | **High** |
| return | `xor eax,eax` → 0 | **High** |
| cleanup | `RET 4` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ live)

```
esi = ecx (phase)
FUN_00756320(phase, flags)
FUN_004c0a90(phase)
FUN_004c1cb0(phase, 0x7fff)
FUN_004c1960(phase)
return 0
```

| Stage | Match | Conf |
|---|---|---|
| Body size 0x2D / RET 4 | **Yes** | **High** |
| ECX thiscall (decompiler gap) | **Yes** (bytes + call site) | **High** |
| Call order 4 callees | **Yes** | **High** |
| Constant 0x7FFF | **Yes** | **High** |
| Sole caller InitPhases | **Yes** | **High** |

---

## 5. Gaps

- Product demangle for phase class (`FUN_004c0640` / `PTR_FUN_009cb62c`).
- Nested free units: `FUN_004c0a90`, `FUN_004c1cb0`, `FUN_004c1960` product English / full ownership.
- Whether capacity 0x7FFF is data-driven elsewhere.
- Runtime / bit-exact / differential.

---

## 6. Verdict

Reconstruction fidelity sealed for ABI, thiscall polarity, call order, constant capacity, and sole InitPhases wiring. Nested create helpers remain free → **accept-with-gaps**.
