# Review B (skeptical / adversarial): `aa_004c1960` ParticleFluidPhase_CreateLiquidChild_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c1960` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W34-O) |
| **Counterpart** | `reviews/A_aa_004c1960_ParticleFluidPhase_CreateLiquidChild_Inferred.md` |
| **Scratch** | `tmp/a_004c1960.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is InitPhases / NDRiver.fx body | **Falsified** — only creates `+0xc4` child; Init is `004c2080`; NDRiver scaffold rejected |
| 2 | Method of PalantirEnv (env*) | **Falsified** — ECX is phase; callers pass phase from env+0xCC path |
| 3 | Child size 0xC8 / 0x18 | **Falsified** — `push 0x40` + `FUN_004c1800` |
| 4 | Store at +0x9c / +0xb0 | **Falsified** — `mov [esi+0xc4], eax` only |
| 5 | `RET 4` / stack flags | **Falsified** — bare `C3`; no stack formals |
| 6 | Product name from retail string in this body | **Overstated** — liquid strings live in nested `FUN_004c0fe0` (free); name is structural `_Inferred` |
| 7 | Safe on OOM | **Residual** — null store then thiscall/activate is undefined; not exercised by Init success path |
| 8 | Creates fluid particles (0x7FFF) | **Falsified** — that is `FUN_004c1cb0` in Init; this unit is liquid child only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX phase + bare RET | **High** | Wrong port ABI |
| `+0xc4` install / 0x40 | **High** | Wrong field / leak |
| Call order | **High** | Missing filter init |
| Activate gate `+0x10` | **High** | Double-activate / skipped |
| Nested product English | **Low** | Misnamed child class |
| OOM path | **Open** | rare crash residual |
| Runtime | **Open** | edge timing |

---

## 3. Cross-check against raw + bytes

```
bytes: mov esi,ecx; push 40; call operator_new; ... call FUN_004c1800;
       mov [esi+0xc4],eax; call FUN_004c0fe0; cmp byte [esi+10],1; ...
       mov byte [esi+10],1; add esp,10; ret
raw ≡ live CF; decompiler labels void __fastcall with param_1=phase
xrefs: 004c20a2 (Init), 004c1c5c (blend rebind after delete)
```

Sibling Init dual (W33-S) already named this residual “child @ +0xc4 (0x40)” — this dual seals that free unit without re-opening Init.

---

## 4. Surviving contract for AutoCore

```
ParticleFluidPhase_CreateLiquidChild(phase):
  child = new(0x40) ? FUN_004c1800(child, phase) : 0
  phase[+0xc4] = child
  FUN_004c0fe0(child)                 // nested free
  if child[+0x10] != 1:
    FUN_0075bf40(0); FUN_007567b0(child[+0x38], 0); child[+0x10]=1
  // ECX=phase; bare RET
```

Do **not** name from NDRiver.fx. Do **not** treat as CreateFluidParticles. Nested `FUN_004c0fe0` / `FUN_004c1800` stay free until owned.

---

## 5. Open questions

- Product class for 0x40 liquid child and `DAT_00b03794`.
- Whether activate helpers are effect-enable vs visibility.
- Runtime null-child / re-entry from blend rebind.

**Verdict:** **accept-with-gaps**
