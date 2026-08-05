# Review B (skeptical / adversarial): `aa_0055ca90` CVOGEnvironmentDistort_BringUpParticleDistort_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0055ca90` |
| **VA** | `0x0055ca90` |
| **Canonical name** | `CVOGEnvironmentDistort_BringUpParticleDistort_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_0055ca90_CVOGEnvironmentDistort_BringUpParticleDistort_Inferred.md` |
| **System** | client / VOGEnvironmentSector |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Full Enable / host ctor | Enable still calls `HostBase_EnsureAuxPtrs` before this; ctor separate | **Falsified** as full enable/ctor |
| 2 | Process-singleton CVOGPhaseDistort | Different VA/size family (`0x00576ed0`, 0x18) | **Falsified** interchange |
| 3 | Same as Reflect child `005b3420` | Peer lacks Particle_Distort.dds / NDParticle…fx / NormalMapTexture; different host slot (+0x158 vs +0x90) | **Falsified** identity |
| 4 | `Gfx_NDParticleDistortBlendNormal` complete product name | Body also loads dds + host wiring + 0.2/500 params | **Agree incomplete** as sole name |
| 5 | Returns success code | Plain `RET`; void; no EAX contract | **Agree** void |
| 6 | Multiple callers | Sole xref `0055cc5f` | **Agree** |
| 7 | Host RTTI proved on this body alone | RTTI sealed on enable/ctor path, not this VA's local data | **Agree High not Confirmed** for this unit alone — inherits W33-T |
| 8 | Null-safe on failed `operator_new` | Bytes still write `child+0x195 \|= 0x40` with null child → **crash path** | **Agree residual risk** (decompiler preserves; no null check after store) |
| 9 | PDB BringUp name proven | Structural + strings only | **Agree Open** product method name |

---

## 2. Live ≡ raw

```
Live decompile ≡ raw 2026-07-23.
read_memory: 6A FF 68 75 49 9A 00 … 83 C4 20 C3  (0x1B2 B).
Caller: FUN_0055cc50 @ 0055cc5f only.
Strings: Particle_Distort.dds; NDParticleDistortBlendNormal.fx; NormalMapTexture.
Floats: 0x3e4ccccd (0.2f), 0x43fa0000 (500.f); color 0xff808000.
```

Null-path note (adversarial): after `operator_new` fail → EAX=0 path stores 0 at +0x90 then immediately `OR byte [EAX+0x195],0x40` — **no null guard**. Port must either match crash-on-OOM or document intentional retail behavior.

---

## 3. Surviving contract

```
// void __thiscall CVOGEnvironmentDistort_BringUpParticleDistort_Inferred(host*)
// new(0x198)+particle_ctor → host+0x90; backlink; |0x40;
// set 0.2f / 500.f / color; vcall +0x18(snapshot);
// bind Particle_Distort.dds + NDParticleDistortBlendNormal.fx + NormalMapTexture;
// host+0x8C ← child+0x44.
// Solely called from Enable after HostBase_EnsureAuxPtrs.
```

---

## 4. CF challenge of Review A

- Alloc/ctor/params/FX/strings/mirror field: **agree Confirmed/High**
- thiscall void SEH: **agree Confirmed**
- Sole Enable caller: **agree Confirmed**
- Name BringUpParticleDistort_Inferred: **agree acceptable** structural
- Reject bare Gfx_ plate: **agree**
- Child class English Open: **agree**

---

## 5. Residual risks

1. Child class product English (`FUN_00968a50` / vtbl `00aa22a8`).
2. OOM null-child crash path (match retail).
3. Binder object identity / unowned material helpers (W37-H/L/I neighbors).
4. host+0x8C field product meaning.
5. Runtime / bit-exact / differential not run.

**Verdict:** **accept-with-gaps.** Agree with A on ABI, CF, strings, constants, sole caller, and structural name.
