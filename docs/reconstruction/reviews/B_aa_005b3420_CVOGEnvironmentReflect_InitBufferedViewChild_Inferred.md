# Review B (skeptical / adversarial): `aa_005b3420` CVOGEnvironmentReflect_InitBufferedViewChild_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b3420` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY W37-M) |
| **Counterpart** | `reviews/A_aa_005b3420_CVOGEnvironmentReflect_InitBufferedViewChild_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | “Fog child” product class (W33-T residual phrasing) | **Overstated** — RTTI is **`gfxBufferedView`**, not a fog type; fog resolve is sibling `FUN_005b3520` |
| 2 | Same method as ParticleFluidPhase fluid-bump | **Falsified** — same **0x198 ctor**, different host slot (`+0x158` vs `+0x9c`), params (near 0.5/far 1e5 vs 0.2/500), no bump dds/fx strings here |
| 3 | thiscall with stack flag / RET 4 | **Falsified** — Enable has RET 4; **this unit** has plain RET, no flag formal |
| 4 | Drive_NDRiver scaffold name | **Rejected** — no evidence |
| 5 | Host is PalantirEnv method | **Falsified** — ECX is Reflect instance; sole caller Enable on env+0xC4 child |
| 6 | Full product demangle of all helpers | **Gap accepted** — structural seal only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX Reflect + void + plain RET | **High** | Stack imbalance |
| new 0x198 + gfxBufferedView RTTI | **High** | Wrong child type |
| Store @ +0x158 + parent @ child+4 | **High** | Lifetime / link bugs |
| Near 0.5 / far 1e5 / 256² pair | **High** | View frustum wrong |
| DAT_00afdf08 / vtbl+0x18 English | **Open** | Material bind residual |
| Runtime | **Open** | OOM / device fail |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  new(0x198) → FUN_00968a50 → +0x158; near/far/resource/vtbl+0x18; flags

bytes:
  SEH; MOV ESI,ECX; PUSH 0x198; CALL operator_new
  CALL FUN_00968a50; MOV [ESI+0x158],EAX; MOV [EAX+4],ESI
  PUSH 0x3f000000; CALL FUN_0075b3b0
  … PUSH 0x47c35000; CALL FUN_0075b390
  CALL [vtbl+0x18]; MOV byte [child+0x190],1
  ADD ESP,0x18; RET
```

RTTI chain: vtbl`00aa22a8` → COL`00aba3bc` → type_info`00b025e8` → `.?AVgfxBufferedView@@`.

---

## 4. Surviving contract for AutoCore

```
// Reflect Enable nested install:
//   ECX = CVOGEnvironmentReflect*
//   child = new gfxBufferedView(0x198) @ host+0x158
//   near=0.5, far=100000, vtbl+0x18(256,256)
// Do NOT name as fog type; fog slots are FUN_005b3520 residual.
// Do NOT merge with ParticleFluidPhase_InitFluidBumpChild (different slot/params).
// Do NOT invent stack flag / RET 4 on this VA (that is Enable, not this).
// Do NOT use NDRiver scaffold names.
```

---

## 5. Verdict

Adversarial pass **confirms** A on ABI/CF/RTTI/slot and rejects fog-class / fluid-bump identity / wrong-RET / env-method claims. Residual helper English → **accept-with-gaps**.
