# Review B (skeptical / adversarial): `aa_004c1cb0` ParticleFluidPhase_CreateFluidParticles_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c1cb0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W34-N) |
| **Counterpart** | `reviews/A_aa_004c1cb0_ParticleFluidPhase_CreateFluidParticles_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Capacity free / default 0 | **Falsified** — Init hard `push 0x7fff` before call; body stores arg |
| 2 | Rejects capacity ≥ 0x4000 | **Falsified** — early path only rejects `capacity*4 == 0`; redundant `cmp 0xffff` does not reject large verts (0x7FFF works) |
| 3 | ECX is env / PalantirEnv | **Falsified** — same phase object as Init; fields `+0xac..+0xbc` on 0xC8 host |
| 4 | Void without stack cleanup | **Falsified** — `C2 04 00` RET 4 |
| 5 | NDRiver naming | **Reject** — body strings `NDParticleFluid.fx` / `CreateFluidParticles`; NDRiver is InitPhases tail |
| 6 | Multiple static callers | **Falsified** — single xref from `FUN_004c2080` |
| 7 | Independent of fluid-bump child | **Partial** — runs without `+0x94` (skips NormalMapTexture); Init always calls bump child first |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall + capacity + RET 4 | **High** | Wrong ABI |
| Field map +0xb4/+0xb8/+0xbc | **High** | Buffer mismanage |
| Product CreateFluidParticles name | **High** | Cosmetic only if wrong |
| Nested view/mesh types | **Low** | Wrong port structure |
| 0x7FFF product meaning | **Medium** | Buffer size if tuned |
| VB/IB path residual helpers | **Medium** | Wrong GPU bring-up |

---

## 3. Cross-check against raw + body + peers

```
// Init call site 0x004c2090..:
//   push 0x7fff; mov ecx,esi; call FUN_004c1cb0
// Early bytes:
//   mov eax,[esp+0x10]  ; capacity
//   lea edi,[eax*4]     ; verts
//   mov esi,ecx
//   mov [esi+0xbc],eax ; mov [esi+0xb8],edi
//   ja good if edi>0 ; else log CreateFluidParticles
// Strings seal product role; peer 004c0a90 seals +0x94 dependency
```

Live decompile ≡ raw CF; prologue/epilogue sealed by `read_memory`.

---

## 4. Surviving contract for AutoCore

```
// Port as phase method:
void ParticleFluidPhase_CreateFluidParticles(void* phase, int capacity) {
  phase->capacity_bc = capacity;
  phase->verts_b8 = capacity * 4;
  if (phase->verts_b8 == 0) { log("Invalid arg to CreateFluidParticles %u", 0); return; }
  phase->particles_b4 = new_array_construct(capacity); // residual element type
  phase->view_ac = new_0x14c_view();                   // residual
  phase->mesh_b0 = new_0xc4_mesh();                    // residual
  bind NDParticleFluid.fx + Particles.dds;
  set ParticleTexture(capacity);
  if (phase->tex_94) set NormalMapTexture(phase->tex_94);
  // optional ReflectionSurface; VB/IB build residual helpers
}
// Factory: CreateFluidParticles(phase, 0x7fff) from ParticleFluidPhase_Init only.
// Prefer after InitFluidBumpChild so +0x94 is populated.
// Do NOT name from NDRiver.fx.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI, capacity gates, product naming, field map, sole caller with 0x7FFF, and reject of NDRiver scaffold. Nested free alloc/FX helpers → **accept-with-gaps**.
