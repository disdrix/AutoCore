# Review B (skeptical / adversarial): `aa_005b39a0` CVOGEnvironmentReflect_Enable_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b39a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W33-T) |
| **Counterpart** | `reviews/A_aa_005b39a0_CVOGEnvironmentReflect_Enable_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` + `read_memory` + xrefs. **No** `disassemble_bytes`.

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Is NDRiver / Drive_NDRiver_fx method | **Falsified** — no FX string; sole caller InitPhases after Reflect ctor; host RTTI **EnvironmentReflect** |
| 2 | Is complete ctor (`005b35a0`) | **Falsified** — ctor installs vtbl/matrix; this is thin ensure+two workers; factory calls **after** ctor |
| 3 | Is apply path (`005b36f0` vtbl[1]) | **Falsified** — different body; apply is fog+reflect shader residual W29-I |
| 4 | Is Distort enable (`0055cc50`) | **Falsified** — two workers vs one; different host class/size |
| 5 | cdecl / no this | **Falsified** — `mov esi,ecx` / re-`mov ecx,esi` twice; `ret 4` |
| 6 | Multiple callers | **Falsified** — one CODE xref @ `0048fdde` |
| 7 | Nonzero status return | **Falsified** — `XOR EAX,EAX` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Class host = CVOGEnvironmentReflect | **Confirmed** | Wrong phase hierarchy |
| Enable order after ctor | **Confirmed** | Missing child @ `+0x158` |
| Distinct from Distort / third phase | **High** | Swap enable callees |
| Nested resolve/alloc full product names | **Medium** residual | Incomplete fog child port |

---

## 3. Cross-check

```
raw 2026-07-23: EnsureAux(flag); 005b3520(); 005b3420(); return 0
live 2026-07-29: identical CF
bytes: mov eax,[esp+4]; push esi; push eax; mov esi,ecx; call 00756320;
       mov ecx,esi; call 005b3520; mov ecx,esi; call 005b3420;
       xor eax,eax; pop esi; ret 4
factory 0048fc90: new(0x170); FUN_005b35a0(parent@+B8); env+C4=result; FUN_005b39a0(1)
RTTI (W32-T): COL 00aafff8 → 00af3eb0 ".?AVCVOGEnvironmentReflect@@"
005b3520: if +0x154==0 pull nested from parent env graph
005b3420: new(0x198)+FUN_00968a50 → +0x158; fog scalars
peer Distort enable 0055cc50: Ensure + 0055ca90 only
```

---

## 4. Surviving contract for AutoCore

```
CVOGEnvironmentReflect_Enable_Inferred(this, flag):
  HostBase_EnsureAuxPtrs(this, flag)
  ResolveNestedFogSlots(this)     // FUN_005b3520 residual
  AllocBindFogChild(this)         // FUN_005b3420 residual → +0x158
  return 0
```

Port as **post-ctor enable** on the **owned** env child at `env+0xC4` (size **0x170**). Always called with **1** from InitPhases immediately after `CVOGEnvironmentReflect_ctor`. Apply path remains separate vfunc residual (W29-I). Reject NDRiver naming.

---

## 5. Open questions

- Product names for `005b3520` / `005b3420` / child class at `+0x158`.
- Re-entrancy if InitPhases re-run with live `+0xC4`.

**Verdict:** **accept-with-gaps**
