# Review B (skeptical / adversarial): `aa_0055cc50` CVOGEnvironmentDistort_Enable_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0055cc50` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W33-T) |
| **Counterpart** | `reviews/A_aa_0055cc50_CVOGEnvironmentDistort_Enable_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` + `read_memory` + xrefs. **No** `disassemble_bytes`.

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Is NDRiver / Drive_NDRiver_fx method | **Falsified** — no FX string in this unit; sole caller is InitPhases after Distort ctor; host RTTI **EnvironmentDistort** |
| 2 | Is process-singleton PhaseDistort enable (`00576*`) | **Falsified** — different class (EnvironmentDistort vs PhaseDistort); owned alloc every InitPhases; size **0xA0** not **0x18** |
| 3 | Is Reflect enable (`005b39a0`) | **Falsified** — one work callee (`0055ca90`) vs two (`005b3520`/`005b3420`); different host RTTI |
| 4 | cdecl / no this / multi-arg | **Falsified** — `mov esi,ecx`; `ret 4`; single stack flag |
| 5 | Multiple callers / free helper | **Falsified** — one CODE xref @ `0048fe20` |
| 6 | Returns success code / this | **Falsified** — `XOR EAX,EAX` always 0 |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Class host = CVOGEnvironmentDistort | **Confirmed** | Wrong phase hierarchy |
| Enable not ctor | **Confirmed** | Double-construct / skip ctor |
| Distinct from Reflect / Water / PhaseDistort | **High** | Merge enable paths |
| Nested `0055ca90` full semantics | **Medium** residual | Incomplete port of child bring-up |

---

## 3. Cross-check

```
raw 2026-07-23: EnsureAux(flag); 0055ca90(); return 0
live 2026-07-29: identical CF
bytes: mov eax,[esp+4]; push esi; push eax; mov esi,ecx; call 00756320;
       mov ecx,esi; call 0055ca90; xor eax,eax; pop esi; ret 4
factory 0048fc90: new(0xA0); FUN_0055c8c0(parent); env+C8=result; FUN_0055cc50(1)
RTTI ctor vtbl 009d26ac: COL 00aae6cc → 00af2d0c ".?AVCVOGEnvironmentDistort@@"
peer Reflect enable 005b39a0: Ensure + 005b3520 + 005b3420
peer third phase enable 004c2080: Ensure + three workers
```

---

## 4. Surviving contract for AutoCore

```
CVOGEnvironmentDistort_Enable_Inferred(this, flag):
  HostBase_EnsureAuxPtrs(this, flag)
  ParticleDistortChild_BringUp(this)   // FUN_0055ca90 residual
  return 0
```

Port as **post-ctor enable** on the **owned** env child at `env+0xC8` (size **0xA0**). Always called with **1** from InitPhases. Do **not** confuse with process-singleton `CVOGPhaseDistort` (0x18) or Reflect enable. Reject NDRiver naming.

---

## 5. Open questions

- Product name for nested particle child worker `0055ca90`.
- Whether enable is re-entrant (second InitPhases call on live host).

**Verdict:** **accept-with-gaps**
