# Review B (skeptical / adversarial): `aa_004c2080` ParticleFluidPhase_Init_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c2080` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W33-S) |
| **Counterpart** | `reviews/A_aa_004c2080_ParticleFluidPhase_Init_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | ECX is PalantirEnv | **Falsified** — InitPhases call site: `mov ecx,eax` where EAX is `FUN_004c0640` result; store also goes to `env+0xCC` |
| 2 | Decompiler signature complete | **Falsified** — decompiler drops this; bytes `mov esi,ecx` + all calls reload ECX from ESI |
| 3 | Returns void / undefined | **Falsified** — `xor eax,eax` + `RET 4` |
| 4 | NDRiver / Drive_NDRiver_fx is this unit | **Reject** — NDRiver.fx loaded in InitPhases **after** this call; scaffold parent-seed name |
| 5 | Always creates env-level objects | **Falsified** — this is phase-object method; EnsureAuxPtrs targets phase host+4/+8 |
| 6 | Capacity free / zero | **Falsified** — hard `push 0x7fff` before `FUN_004c1cb0`; nested string `CreateFluidParticles` |
| 7 | Multiple static callers | **Falsified** — single xref from `FUN_0048fc90` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Thiscall on phase @ env+0xCC | **High** | Wrong `this` / crash |
| Flags forwarded to EnsureAuxPtrs | **High** | Miss bit0 +4 alloc |
| Call order fixed | **High** | Child dependency break |
| Nested product English | **Low** | Naming only |
| 0x7FFF product meaning | **Medium** | Wrong buffer sizing if tuned |
| Runtime under OOM in nested | **Open** | Partial init residual |

---

## 3. Cross-check against raw + body + peers

```
// PalantirEnv_InitPhases:
//   phase = new(0xC8) ? FUN_004c0640(parent) : 0
//   env+0xCC = phase
//   ParticleFluidPhase_Init(phase, 1)   // this VA
//   ... then FUN_004982d0 / NDRiver.fx / clear +0x178
// Peer enables: FUN_005b39a0(1), FUN_0055cc50(1) — same Ensure-then-work pattern
// FUN_004c1cb0 body: stores capacity @ +0xbc; string "CreateFluidParticles"
// FUN_004c0a90: "Particle_Fluid_bump.dds", "NDParticleFluidBlendNormal.fx"
```

Live decompile ≡ raw CF order; 45 B hex seals thiscall, four call relocs, `RET 4`, return 0.

---

## 4. Surviving contract for AutoCore

```
// Port as phase method (ECX = FUN_004c0640 instance at env+0xCC):
uint32_t ParticleFluidPhase_Init(void* phase, uint32_t flags) {
  HostBase_EnsureAuxPtrs(phase, flags); // factory flags=1
  FUN_004c0a90(phase);                  // fluid-bump child
  FUN_004c1cb0(phase, 0x7fff);          // CreateFluidParticles(32767)
  FUN_004c1960(phase);                  // child @ +0xc4
  return 0;
}
// Call only after phase ctor stored at env+0xCC.
// Do NOT treat as env method; do NOT name from NDRiver.fx tail.
// Nested creates remain free residual until owned.
```

---

## 5. Verdict

Adversarial pass confirms A on thiscall polarity, flags, call order, sole caller, and reject of NDRiver scaffold name. Nested free helpers + product demangle → **accept-with-gaps**.
