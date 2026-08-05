# Review B (skeptical / adversarial): `aa_004c0a90` ParticleFluidPhase_InitFluidBumpChild_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c0a90` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W34-N) |
| **Counterpart** | `reviews/A_aa_004c0a90_ParticleFluidPhase_InitFluidBumpChild_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | ECX is PalantirEnv / client root | **Falsified** — sole caller `004c2080` reloads ECX from phase ESI after EnsureAuxPtrs |
| 2 | Stack flag / RET 4 like Init | **Falsified** — epilogue `C3` plain RET; no stack formal load |
| 3 | Child is plain GfxView 0x150 | **Falsified** — `push 0x198` + `FUN_00968a50` (not `FUN_0075ceb0` / 0x150) |
| 4 | Near default 0.5f like view ctor | **Falsified** — imm `0x3e4ccccd` = **0.2f** (peer distort path also ~0.2f) |
| 5 | NDRiver / Drive_NDRiver_fx name | **Reject** — strings are Fluid_bump / FluidBlendNormal; NDRiver is InitPhases tail |
| 6 | Multiple static callers | **Falsified** — single xref from `FUN_004c2080` |
| 7 | ExceptionList = device+0x84 | **Decompiler residual** — bytes restore SEH via standard epilogue; device pair is vtbl+0x18 arg only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX phase* / void RET | **High** | Wrong ABI / stack smash |
| `+0x9c` child ownership | **High** | Leak / double-bind |
| Near/far float bits | **High** | Wrong projection |
| 0x198 class product English | **Low** | Naming only |
| Texture cache `+0x94` role | **Medium** | Break CreateFluidParticles normal map |
| Runtime OOM | **Open** | Null-child crash residual |

---

## 3. Cross-check against raw + body + peers

```
// ParticleFluidPhase_Init:
//   EnsureAuxPtrs(phase, flags)
//   FUN_004c0a90(phase)          // THIS
//   FUN_004c1cb0(phase, 0x7fff)  // uses phase+0x94 from this unit
//   FUN_004c1960(phase)
// Peer distort child FUN_0055ca90: also SetNear(~0.2f) on new particle host
// W31-O: FUN_0075b3b0 callers include this VA @ 0x004c0b17
```

Live decompile ≡ raw CF; prologue/epilogue + float imms sealed by `read_memory`.

---

## 4. Surviving contract for AutoCore

```
// Port as phase method (ECX = fluid phase @ env+0xCC):
void ParticleFluidPhase_InitFluidBumpChild(void* phase) {
  auto* child = new_0x198_then_FUN_00968a50(); // residual class
  phase->child_9c = child;
  child->flag_195 |= 0x40;
  child->parent_4 = phase;
  GfxView_SetNear(child, 0.2f);
  SetFar(child, 500.0f);
  // color / dirties / device bind / load bump dds + blend-normal fx
  phase->tex_94 = child->field_44;
}
// Call only from ParticleFluidPhase_Init before CreateFluidParticles.
// Do NOT name from NDRiver.fx. Do NOT invent ECX=env.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI polarity, child size/site, float constants, material strings, sole caller, and reject of NDRiver scaffold. Nested class product English + OOM → **accept-with-gaps**.
