# Function record: CVOGObjectiveRequirement_Patrol_EventAction_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060e800` |
| **Canonical name** | `CVOGObjectiveRequirement_Patrol_EventAction_Inferred` |
| **Prior / machine** | `FUN_0060e800` |
| **Address** | `0x0060e800` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Vtable** | `PTR_FUN_009e0404` slot **`+0x04`** (DATA `0x009e0408`) |
| **Completion status** | **Dual A/B MEGA-031 2026-08-05** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open |
| **Verdict** | **accept-with-gaps** |

---

## Purpose

Patrol requirement **event-driven Action** (same vtable slot family as Collect_Action `0x00611f20`):

| `eventType` | Arm | Effect | AL |
|:-----------:|-----|--------|:--:|
| **`0x0C`** | AutoFail flag | if `req+0x18` → `CVOGReaction_FailMission` (mission id `**(req+4)+0x14c`) | **0** |
| **`0x0B`** | Pad proximity | match current pad `GenericTargetCOID`; AutoComplete or AutoFail-by-distance | **0\|1** |
| other | — | fallthrough | **0** |

### Event 0x0B detail

1. `padCount = (int)slot_float` at `progress + 4 + (byte)(req+8)*4`
2. Require `padCount < Laps(+0x24) * targetCount(+0xd0)`
3. `idx = padCount % targetCount`
4. Match entity COID `+0x160/+0x164` to `req+0x30+idx*8` / `+0x34`
5. Entity `vtbl+0x144`; load pos `+0x80/+0x84/+0x88`
6. Character complex `vtbl+0x1a0` → player pos; `dist = sqrt(Δx²+Δy²+Δz²)`
7. **AutoComplete** (`+0x10`): if `dist < AutoCompleteDistance(+0x14) + 5.0` → slot += 1.0; return 1
8. **AutoFail** (`+0x18`): if `dist > AutoFailDistance(+0x1c) - 5.0` → FailMission; else if complex `vtbl+0x198` ≠ 0 → FailMission

Slop constant: `DAT_00aaa688 = 5.0f`. FailMission sites **do not** call drain `FUN_005307e0`.

---

## Signature (semantic)

```c
// thiscall: ECX = Patrol requirement*
// Stack: +8 character, +0xc progress, +0x10 eventType, +0x14..+0x1c unused,
//        +0x20 entity*; RET 0x1C; AL low-byte bool-like
uint8_t __thiscall CVOGObjectiveRequirement_Patrol_EventAction_Inferred(
    int*   req,
    int    character,
    int    progress,
    int    eventType,   // 0x0B pad-proximity / 0x0C fail-flag
    int    /*u14*/,
    int    /*u18*/,
    int    /*u1c*/,
    int*   entity);
```

---

## Layout consumers (req)

| Offset | Field | Source |
|------:|-------|--------|
| `+0x04` | parent / mission link | FailMission id via `+0x14c` |
| `+0x08` | slot index (byte) | slot float address |
| `+0x10` | **AutoComplete** (char) | GetFlags + this body |
| `+0x14` | **AutoCompleteDistance** (f32) | GetFlags + this body |
| `+0x18` | **AutoFail** (char) | GetFlags + this body |
| `+0x1c` | **AutoFailDistance** (f32) | GetFlags + this body |
| `+0x24` | **Laps** (int) | GetFlags / Eval product |
| `+0x30`… | **GenericTargetCOID** pairs (step 8) | GetFlags loop |
| `+0xd0` | target count | GetFlags / Eval |

Ctor `FUN_0060e090` installs vtable and stores type dword **`req+0x0c = 9`**.

---

## Related slots (do not confuse)

| Slot | Occupant | Role |
|------|----------|------|
| **`+0x04`** | **this** `0x0060e800` | **Event Action** (AutoComplete/Fail distance) |
| `+0x08` | `0x0060e0f0` Eval | complete when slot ≥ Laps×count |
| `+0x10` | `0x0060e120` dualed as `Patrol_Action` | **progress fraction only** |
| `+0x20` | `0x00637de0` | shared progress toast |
| `+0x28` | `0x0060e3d0` InitActive | optional Patrol HB enqueue when AutoFail |

---

## Artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_0060e800_FUN_0060e800.md` |
| Annotated | `raw/aa_0060e800_FUN_0060e800.annotated.md` |
| Clean named | `reconstructed-exact/CVOGObjectiveRequirement_Patrol_EventAction_Inferred.cpp` |
| Clean twin | `reconstructed-exact/FUN_0060e800.cpp` |
| Dual A | `reviews/A_aa_0060e800_CVOGObjectiveRequirement_Patrol_EventAction_Inferred.md` |
| Dual B | `reviews/B_aa_0060e800_CVOGObjectiveRequirement_Patrol_EventAction_Inferred.md` |
| Report | `docs/agents/task-dual-ab-0060e800-mega-031-report.md` |

## Confidence

| Claim | Level |
|---|---|
| Control flow + ABI | **High** |
| Class / vtable+0x04 / field dictionary | **High** |
| Method product English | **Probable** → `_Inferred` |
| Event 0x0B/0x0C product labels | **Tentative** |
| Runtime / bit-exact | **Open** |

## Open questions

- Product dictionary for events 0x0B / 0x0C.
- Virtual English for +0x144 / +0x1a0 / +0x198.
- 7-arg Action dispatcher residual.
- Runtime observation / differential equivalence.
