# Function record: CVOGObjective_ProbeEligibilityCode_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0059db80` |
| **Canonical name (proposed)** | `CVOGObjective_ProbeEligibilityCode_Inferred` |
| **Prior / Ghidra** | `FUN_0059db80`; retired `Named_CalleeOf_Named_VOG_DEBUG_STOP_0059db80` |
| **Address** | `0x0059db80`–`0x0059dc40` (**193 B** / `0xC1`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `missions-progression` |
| **Calling convention** | MSVC `__thiscall` (objective ECX + character\* stack); **`RET 4`**; int EAX |
| **Completion status** | **Human-refined + dual A/B sealed (MEGA-091 2026-08-05)** — CF/ABI/hash/eval slots High; product code English open |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual status** | A/B **accept-with-gaps** 2026-08-05 |
| **Partition** | MEGA-091; parent context `0x0059dc50` (Objective-node eligibility gate for tracker) |

## Purpose

Objective-side nested probe used by the tracker eligibility gate and mission-tracker UI:

1. Load default code `objective+0x120`; if `-1`, use `*(objective+0x14c)+0xfc`.
2. Inline-lookup pending node in `character+0x55c` by key `objective+0x10` (CNDHash mask/bucket/chain).
3. No pending → return default.
4. Walk evaluators `[objective+0x158, +0x15c)`:
   - `vtbl+0x8(character, pendingValue)` — if **false**, take `vtbl+0x58()` when not `-1` and not `0`.
   - First such override wins; else default.

**Not** MatchTarget (`+0x40` OR-walk). **Not** readiness AND-walk (`CVOGCharacter_IsObjectiveReady`).

## Signature (refined / sealed)

```c
// Result in EAX. Callee cleans 4.
int __thiscall CVOGObjective_ProbeEligibilityCode_Inferred(
    void* objective,   /* ECX */
    void* character);  /* stack */
```

## Behavioral summary

| Path | Result |
|---|---|
| Pending miss / empty eval range / no override | `defaultCode` (`+0x120` or `def+0xfc`) |
| Eval `+0x8` false and `+0x58` ∉ {0, −1} | that `+0x58` code |
| Parent `FUN_0059dc50` sees `−1` | ineligible (return 0) |
| UI rebuild sees code | match widget `+0x110` category |

## Offset map

| Location | Role | Conf |
|---|---|---|
| `obj+0x10` | Objective id (hash key) | **High** |
| `obj+0x120` | Default code | **High** |
| `obj+0x14c` → `def+0xfc` | Fallback default | **High** |
| `char+0x55c` | Pending objectives CNDHash* | **High** |
| hash `+0x8`/`+0x10` | mask / buckets | **High** |
| node `+0x10`/`+0xc`/`+0x8` | key / next / value | **High** |
| `obj+0x158`/`+0x15c` | Evaluator** half-open | **High** |
| eval `+0x8` | Progress boolean | **High** |
| eval `+0x58` | Code override | **High CF** / English **Tentative** |

## Callers / callees

| Direction | Target | Notes |
|---|---|---|
| Caller | `FUN_0059dc50` @ `0x0059dc75` | eligibility gate (`EAX==-1` fail) |
| Caller | `FUN_008a5240` @ `0x008a546d` | tracker UI rebuild |
| Caller | `FUN_008a2670` @ `0x008a2703` | UI category match |
| Caller | `FUN_008a2df0` @ `0x008a3029` | UI category match |
| Callee | none direct | indirect `+0x8` / `+0x58` |

## Confidence by dimension

| Dimension | Level | Rationale |
|---|---|---|
| Function boundary | **High** | Ghidra body + CC pad to `0059dc50` |
| Control flow | **High** | live ≡ raw; 3 RET4 exits |
| ABI RET 4 thiscall | **High** | `c2 04 00` ×3; ECX=this; stack char* |
| Pending hash binding | **High** | shared mission units + inline mask walk |
| Eval slot `+0x8` / override `+0x58` | **High** | disasm `CALL [EDX+8]` / `CALL [EDX+0x58]` |
| Role = eligibility/category probe | **High** | parent −1 gate + UI `+0x110` |
| Product English for codes | **Tentative** | `_Inferred` |
| Runtime / bit-diff | **Open** | |
| Overall | **High (static dual)** | accept-with-gaps |

## Open questions

1. Product name / enum for `+0x120` / `def+0xfc` / `+0x58` codes.
2. Full requirement-type implementer matrix for `+0x8`/`+0x58`.
3. Whether `DAT_00d1b6d8` global character is always the probe subject in UI paths.

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0059db80_FUN_0059db80.md` |
| Annotated | `docs/reconstruction/raw/aa_0059db80_FUN_0059db80.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGObjective_ProbeEligibilityCode_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0059db80.cpp` |
| FUN record | `docs/reconstruction/functions/aa_0059db80_FUN_0059db80.md` |
| Dual A | `docs/reconstruction/reviews/A_aa_0059db80_CVOGObjective_ProbeEligibilityCode_Inferred.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_0059db80_CVOGObjective_ProbeEligibilityCode_Inferred.md` |
| Report | `docs/agents/task-dual-ab-0059db80-mega-091-report.md` |
| Parent (not OWN) | `FUN_0059dc50` / MEGA-025 eligibility gate |
| Sibling sealed | `aa_0059d9c0` MatchTargetEvaluators; `aa_0052a020` IsObjectiveReady |
