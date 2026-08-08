# Review B (skeptical / adversarial): `aa_00404e00` CVOGPhysics_WriteNotFullyReadyOut_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00404e00` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (MEGA-049 OWN dual) |
| **Counterpart** | `reviews/A_aa_00404e00_CVOGPhysics_WriteNotFullyReadyOut_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Skill status-effect packet decoder (partition seed) | RecvSkillStatusEffect plate | **Falsified** — leaf phys field probe; only nested via `005d0d60` caller |
| 2 | Same as ready-probe `FUN_005070b0` | Family merge | **Falsified** — `5070b0` uses `+0x44`/`+0x29`; this uses `+0x40`/`+0x08` |
| 3 | *out polarity is fully-ready=1 | Polarity flip | **Falsified** — fully ready writes **0**; not-ready writes **1** |
| 4 | cdecl / no stack cleanup | Wrong ABI | **Falsified** — `RET 4` (`C2 04 00`) ×2 |
| 5 | ECX = entity host / skill table | Wrong this | **Falsified** — both sites `MOV ECX,[entity+8]` |
| 6 | Has callees / not leaf | Scaffold noise | **Falsified** — analyze_function_complete callees=[] |
| 7 | Returns void; EAX meaningless | Decompiler void | **Falsified as caller contract** — callers `CMP [EAX],0`; EAX=out |
| 8 | Named_CalleeOf_* is role-accurate | Auto plate | **Falsified** — plate is depth-seed only; role is phys readiness |
| 9 | SetRotation body / vtbl dispatch | Family conflation | **Falsified** — no vtbl, no callees; pure out-byte write |
| 10 | Product name sealed without `_Inferred` | Symbol inflation | **Not sealed** — keep `_Inferred` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| CF + body hex + RET 4 | **High** | Wrong port size / ABI |
| Fully-ready polarity | **High** | Soft path always/never taken |
| ECX=phys via entity+8 | **High** | Wrong object type |
| Field offsets +0x40/+0x08 | **High** | Gate on wrong members |
| CVOGPhysics type English | **High** (behavioral) / **Probable** (class) | Doc only |
| "Fully ready" product English | **Probable** | Naming only |
| Runtime | Open | Live mismatch |

---

## 3. Cross-check against raw

```text
// raw aa_00404e00 ≡ live decompile ≡ assembly 2026-08-05
if (*(char*)(this+0x40) != 0 && *(int*)(this+0x08) != 0)
    *out = 0;
else
    *out = 1;
// RET 4; EAX = out
```

SetRotation dualed gate (consumer inverted):
```text
// CVOGPhysics_SetRotation — skip body when fully ready
if (*(char*)(phys+0x40) == 0 || *(int*)(phys+0x08) == 0)
    body_vtbl[+0x44](rot);   // only when NOT fully ready
```

Parity: this unit's `*out==1` ≡ SetRotation's dispatch-allowed condition.

---

## 4. Surviving contract for AutoCore

```
CVOGPhysics_WriteNotFullyReadyOut(phys, out):
  if phys.byte_40 != 0 AND phys.field_08 != 0:
      *out = 0          // fully ready
  else:
      *out = 1          // not fully ready / soft allowed
  return out            // thiscall RET 4

// Callers:
//   Skill_ApplyBoundStatusMotionTable: soft aim/heading when *out
//   CVOGHBAICreatureBase_DoLogic: AI state branch when *out
// Do NOT merge with FUN_005070b0 ready probe.
// Do NOT invent skill-packet fields here.
```

---

## 5. Gaps surviving adversarial pass

1. Product English for fully-ready fields (behavioral sealed; symbol open).
2. Runtime CE force of gate under live AI / skill status.
3. Parent matrix / naming registry lockstep (OWN-ONLY forbidden).

**Verdict:** **accept-with-gaps** — CF/ABI/polarity/callers sealed; product English + runtime open. Skill-misname and polarity-flip claims falsified.
