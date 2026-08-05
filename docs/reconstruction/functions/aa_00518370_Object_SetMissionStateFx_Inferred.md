# Function record: Object_SetMissionStateFx_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00518370` |
| **Canonical name** | `Object_SetMissionStateFx_Inferred` |
| **Ghidra name** | `FUN_00518370` |
| **Address** | `0x00518370`–`0x00518580` (**529 B / `0x211`**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client-fx / mission-state SpecialFX |
| **Completion status** | **Sealed (W30-H)** — dual A/B accept |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Alias

- Scaffold: `FUN_00518370`
- Prior: `Named_CalleeOf_CVOGReaction_SpawnObject_00518370` (caller chain only; too narrow)

## Purpose

Store mission/progress FX **state** at object `+0x154`, tear down secondary SpecialFX list, arm `+0x184` bit2, then apply event-variant FX (states 0/1/2 → events 9/10/11) or audio-only (state >2, including spawn path state 3).

## Signature (byte-sealed)

```c
// thiscall; ret 4
void Object_SetMissionStateFx_Inferred(void *self, int newState);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00518370_FUN_00518370.md`
- Annotated: `docs/reconstruction/raw/aa_00518370_FUN_00518370.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Object_SetMissionStateFx_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00518370.cpp`
- Prior named scaffold: `docs/reconstruction/reconstructed-exact/Named_CalleeOf_CVOGReaction_SpawnObject_00518370.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00518370_Object_SetMissionStateFx_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00518370_Object_SetMissionStateFx_Inferred.md`
- Report: `docs/agents/task-dual-ab-00565950-00518370-w30h-report.md`

## Callers / callees

**CODE callers (5 xrefs):** `CVOGReaction_SpawnObject`, `FUN_005825d0`, `FUN_00582670`, `FUN_005c8270`, `FUN_005c8580`.

**Callees:** `FUN_00516930` (W29-N), `FUN_004eb3b0`, `FUN_004a16d0` (FxMaster_LoadEventVariant), `Client_GetMissionCompleteAudioTable`, `FUN_00723b20`, `CVOGReaction_FailMissionNotify`/`Vector_PushDword`, `FUN_004b7e50`, vtbl `+0x1CC` / `+0xF8`.

## Confidence

| Claim | Level |
|---|---|
| Body bounds + `ret 4` | **Confirmed** (`get_function_by_address` + `read_memory`) |
| State @ `+0x154`, flag bit2 @ `+0x184` | **Confirmed** |
| Events 9/10/11 for states 0/1/2 | **Confirmed** |
| Teardown secondary before re-arm | **Confirmed** (W29-N nested) |
| Product English for state enum | **Inferred** |
| Runtime golden | Open |
