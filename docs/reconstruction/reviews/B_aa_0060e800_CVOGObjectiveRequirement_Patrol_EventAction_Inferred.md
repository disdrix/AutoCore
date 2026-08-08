# Review B (skeptical / adversarial): `aa_0060e800` CVOGObjectiveRequirement_Patrol_EventAction_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060e800` |
| **Review type** | Path B — skeptical / adversarial |
| **Date** | `2026-08-05` (MEGA-031) |
| **Counterpart** | `reviews/A_aa_0060e800_CVOGObjectiveRequirement_Patrol_EventAction_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is the dualed `Patrol_Action` @ `0x0060e120` | That body is progress fraction only (`slot/(laps*count)`); vtable **+0x10**; **no** FailMission | **Falsified** |
| 2 | This is Patrol Eval @ `0x0060e0f0` | Eval is complete gate; vtable **+0x08**; no distance / FailMission | **Falsified** |
| 3 | This is shared toast Action `0x00637de0` | Toast is vtable **+0x20**; no pad match; no FailMission | **Falsified** |
| 4 | This is Collect/UseItem event Action | Vtable `009e0404` + ctor type **9** + GetFlags `type="patrol"` fields | **Falsified** |
| 5 | FailMission always drains | FailMission dual: sites `0060e82f` / `0060e9c3` are **drain-NO** | **Falsified** |
| 6 | AutoFail when **too close** | Image: fail when `dist > AutoFailDistance - 5` (too far); inside-band needs complex+0x198 | **Falsified** (inverted claim) |
| 7 | AutoComplete when **outside** radius | Image: `COMISS` complete+5 vs dist; complete when **closer** than threshold | **Falsified** |
| 8 | Decompiler `float* param_4` is a float pointer | Image loads dword event; compares to **0xB/0xC** immediates | **Falsified** |
| 9 | Static CALL graph has callers | `get_function_callers` empty; only DATA `009e0408` | **Sealed virtual-only** |
| 10 | Product method name sealed without `_Inferred` | No RTTI method string; role from slot+CF+GetFlags | **Attack holds → keep `_Inferred`** |
| 11 | event 0x0C is “complete” | 0x0C only FailMission under AutoFail flag; no slot++ | **Falsified** |
| 12 | Laps unused here | `IMUL` laps×count for upper bound before modulo | **Falsified** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Patrol class + vtable+0x04 identity | **High** | Mis-wire requirement dispatch |
| event 0x0B/0x0C numeric arms | **High** | Wrong client fail/progress |
| AutoComplete/AutoFail field offsets | **High** | Wrong mission XML mapping |
| 5.0f slop constant | **High** | Off-by-radius in port |
| FailMission no-drain | **High** | Double-remove active mission |
| 7-arg Action ABI | **High** | Stack corruption if ported wrong |
| Product event dictionary | **Tentative** | Misname in docs only |
| complex+0x198 meaning | **Tentative** | Wrong secondary fail gate |
| Runtime parity | **Open** | Silent client desync |

---

## 3. Surviving contract for AutoCore

```
// Client Patrol event Action (vtable+0x04) — not server authority alone
EventAction(req, character, progress, eventType, _, _, _, entity) -> AL 0|1
  if eventType == 0x0C:
    if req.AutoFail: FailMission(character, missionId(req)); return 0
    return 0
  if eventType != 0x0B or entity == null: return 0
  pad = (int)progress.slot[req.slot]
  if pad >= req.Laps * req.targetCount: return 0
  idx = pad % req.targetCount
  if entity.COID != req.targets[idx]: return 0
  refresh entity; dist = |entity.pos - player.pos|
  if req.AutoComplete and dist < req.AutoCompleteDistance + 5.0:
    progress.slot[req.slot] += 1.0; return 1
  if req.AutoFail:
    if dist > req.AutoFailDistance - 5.0: FailMission(...)
    else if characterComplex.vtbl+0x198(): FailMission(...)
  return 0
// No FUN_005307e0 drain after FailMission here
```

Port notes:

- Keep **distinct** from progress-fraction `Patrol_Action` `0x0060e120`.
- Mirror Collect_Action **7-arg / RET 0x1C** frame.
- Server must still own fail authority; this is client-side reaction path.

---

## 4. Gaps that block full accept

1. Seal product labels for events **0x0B** / **0x0C** (need dispatcher strings or PDB).
2. Name entity `+0x144` and character-complex `+0x1a0` / `+0x198`.
3. Runtime capture with Launcher approval.
4. Optional: rename dualed progress method `0x0060e120` away from bare `Patrol_Action` to reduce collision (out of OWN scope).

**Verdict:** **accept-with-gaps**. Adversarial merges (progress Action / Eval / toast / Collect / drain-yes / inverted distance) **falsified**. CF/ABI/fields sealed.
