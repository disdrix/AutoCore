# Review A (reconstruction fidelity): `aa_00589bc0` Skill_HB_ApplyHeatDelta_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00589bc0` |
| **VA** | `0x00589bc0`–`0x00589c69` inclusive (**170 B** / `0xAA`) |
| **Canonical name** | `Skill_HB_ApplyHeatDelta_Inferred` |
| **Ghidra name** | `FUN_00589bc0` |
| **Prior scaffold** | `FUN_00589bc0` (2026-07-23 generic plate; decompiler-wrong 2-arg body) |
| **Rejected misname** | bare `FUN_*` permanent; HP/shield sibling merge; thiscall-on-self; adjustor-as-delta |
| **Review date** | `2026-08-05` (MEGA-005 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00589bc0_Skill_HB_ApplyHeatDelta_Inferred.md` |
| **System** | skills-abilities / Skill HB combat pools |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `force_decompile` + `analyze_function_complete` + `disassemble_function` + `read_memory` + `get_function_callers` + `get_xrefs_to` + `get_function_by_address` + parent/peer/callee samples. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Skill hardpoint / heartbeat helper that **applies a signed heat delta** to a vehicle combat pool resolved from the target object:

1. RTTI-cast `target` → `CVOGVehicle`; else `CVOGCreature` then load vehicle* at `+0x250`.
2. Convert float `amount` → integer heat delta with optional **percent-of-max-heat** when `amount ∈ [-1, 1]`.
3. If net/ghost object at MI-adjusted `+0xA8` is present and gate byte `+0x7E` is set, call `Vehicle_AddHeat`.
4. Return actual `nCurrentHeat` change (`+0x150`), or 0 on fail / gate skip.

```text
Skill_HB_ApplyHeatDelta_Inferred(sourceUnused, target, amount) -> int dHeat
  vehicle = dyn_cast<CVOGVehicle>(target)
         || *(dyn_cast<CVOGCreature>(target) + 0x250)
  if !vehicle: return 0
  delta = (|amount|<=1) ? trunc(maxHeat(+0x244)*amount) : trunc(amount)
  cur = heat(+0x150)
  if net(+0xA8) && net[+0x7E]: Vehicle_AddHeat(vehicle, delta)
  return heat(+0x150) - cur
```

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | same CF as 2026-07-23 scaffold (**wrong arity/math**) |
| Full body | `disassemble_function` + `read_memory` 170 B |
| Constants | `DAT_00aaa668`=-1.0f; `g_flOne`@`00a0f2a0`=1.0f |
| Callee | `Vehicle_AddHeat` `0x004f7210` (thiscall; clamp / HeatMask) |
| Parent | `FUN_0061b6f0` skill HB @ `0x0061b7d2` (float@`+0x114` × period@`+0x6c4`) |
| Peer | `FUN_00618270` @ `0x0061858a` |
| Xrefs | 5 `UNCONDITIONAL_CALL` |
| Family | HP `00589c70`, shield `00589d90`, short/floater `0058cc40` |

---

## 3. Signature (sealed)

```c
// __cdecl; bare RET; caller cleans 0xC
int Skill_HB_ApplyHeatDelta_Inferred(
    void *sourceUnused,  // [ESP+4]  pushed; unread
    void *targetObj,     // [ESP+8]  RTTI
    float amount);       // [ESP+C]  +heat / −cool
```

| Formal | Source | Conf |
|---|---|---|
| sourceUnused | stack `[ESP+4]` | **Confirmed** (present, unread) |
| targetObj | stack `[ESP+8]` → EDI | **Confirmed** |
| amount | stack float `[ESP+0xC]` / MOVSS | **Confirmed** |
| return | EAX = heat'−heat or 0 | **Confirmed** |
| cleanup | bare `RET` (`C3`); callers `ADD ESP,0xC` | **Confirmed** |
| convention | **cdecl** (not thiscall) | **Confirmed** |

---

## 4. Control flow (sealed)

| Stage | Match | Conf |
|---|---|---|
| Prolog PUSH ESI/EDI | bytes | **Confirmed** |
| dyn_cast Vehicle RTTI | PUSH typeids + CALL | **Confirmed** |
| else dyn_cast Creature → `+0x250` | second cast path | **Confirmed** |
| early ret0 on null vehicle | XOR EAX / JZ | **Confirmed** |
| percent window COMISS [-1,1] | DAT_00aaa668 / g_flOne | **Confirmed** |
| max heat `+0x244` × amount | CVTSI2SS/MULSS/CVTTSS2SI | **Confirmed** |
| absolute trunc amount | CVTTSS2SI ECX,XMM0 | **Confirmed** |
| netobj MI+0xA8 gate +0x7E | TEST/CMP/JZ | **Confirmed** |
| Vehicle_AddHeat this=ESI, push delta | CALL 004f7210 | **Confirmed** |
| return heat'−cur @+0x150 | SUB EAX,EDI | **Confirmed** |
| Live decompile ≠ assembly math | re-verify delta table | **Confirmed** |

---

## 5. Gaps

- Product / PDB symbol English for this VA.
- Netobj `+0x7E` product flag name.
- Why unused source arg is still pushed (ABI symmetry only).
- Orphan/switch site plates `0061beaf` / `0061e8de` / `0061ea44`.
- Runtime / bit-exact / differential.

---

## 6. Verdict

**accept-with-gaps** — CF/ABI/cdecl-3arg/ADD ESP 0xC/RTTI resolve/percent band/fields +0x150+0x244/gate+AddHeat/callers sealed via assembly; product English + orphan plates + runtime open. Decompiler must not be used as sole port source for this VA.
