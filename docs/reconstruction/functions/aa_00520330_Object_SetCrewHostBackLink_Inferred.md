# Function record: Object_SetCrewHostBackLink_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00520330` |
| **Canonical name** | `Object_SetCrewHostBackLink_Inferred` |
| **Ghidra name** | `FUN_00520330` |
| **Address** | `0x00520330`–`0x0052033d` exclusive |
| **Body size** | **13 B**; `ret 4` (`C2 04 00`); pad `CC` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities / vehicle crew |
| **Completion status** | **Dual sealed** (WQ9E-D 2026-08-04) — **accept** |
| **Bit-for-bit / runtime / diff** | Open (no Launcher; Terminal false) |

## Alias

- Human: `Object_SetCrewHostBackLink_Inferred`
- Prior: `FUN_00520330` / `Named_CalleeOf_Named_VOG_DEBUG_STOP_00520330`

## Purpose

Leaf **crew-host back-link setter**: `*(object+0xCB0) = crewHostOrNull`. Insert paths write the host; Clear/wipe/leave write null. Field is read by convoy UI and skill gather mode 0xb consumers.

## Signature

```c
// __thiscall; RET 4; void
void Object_SetCrewHostBackLink_Inferred(Object* self, void* crewHostOrNull);
```

## Layout

| Offset | Role |
|---|---|
| `this+0xCB0` | crew host back-pointer (object* or null) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00520330_FUN_00520330.md`
- Annotated: `docs/reconstruction/raw/aa_00520330_FUN_00520330.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/Object_SetCrewHostBackLink_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00520330.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00520330_Object_SetCrewHostBackLink_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00520330_Object_SetCrewHostBackLink_Inferred.md`
- Scaffold record: `docs/reconstruction/functions/aa_00520330_FUN_00520330.md`

## Callers / callees

| Direction | Targets |
|---|---|
| Callers (7) | `FUN_00574a30`, `VehicleCrew_ClearMemberObject_Inferred` (`00574a90`), `FUN_005750e0`, `FUN_00575200`, `FUN_005752c0`, `VehicleCrew_InsertMember_Inferred` (`005755b0`), `FUN_0094dab0` |
| Callees | none |

## Related

| VA | Name | Relation |
|---|---|---|
| `0x005755b0` | `VehicleCrew_InsertMember_Inferred` | sets member→host |
| `0x00574a90` | `VehicleCrew_ClearMemberObject_Inferred` | clears back-link |
| `0x005749d0` | `VehicleCrew_ContainsMember_Inferred` | twin reader on host table |
| `0x0082fb30` | `UI_InteractionMenu_AddConvoyInviteOrKick_Inferred` | reads `*(local+0xCB0)` |

## Confidence

| Claim | Level |
|---|---|
| Store `+0xCB0` / `ret 4` / leaf | **Confirmed** |
| Insert/Clear call-site polarity | **Confirmed** |
| Product C++ name | **Inferred** |
