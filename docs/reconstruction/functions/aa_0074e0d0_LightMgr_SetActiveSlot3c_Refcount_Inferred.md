# Function record: LightMgr_SetActiveSlot3c_Refcount_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0074e0d0` |
| **Canonical name** | `LightMgr_SetActiveSlot3c_Refcount_Inferred` |
| **Ghidra name** | `FUN_0074e0d0` |
| **Address** | `0x0074e0d0`–`0x0074e107` exclusive (**55 B** / `0x37`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | Palantir light manager / active refcounted slot |
| **Completion status** | **Dual-sealed W37-AE** — accept |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Classification** | worker |

## Alias

- Ghidra: `FUN_0074e0d0`
- Reject scaffold: `Named_CalleeOf_Named_VOG_DEBUG_STOP_0074e0d0` (parent-seed only; VOG string is in a large caller, not this unit)

## Purpose

Swap `host[+0x3c]` to a new refcounted object pointer (or null): AddRef new (vtbl[+4] on 0→1), Release old (vtbl[+8] on →0), store.

## Signature (sealed)

```c
// __thiscall; RET 4; void
void LightMgr_SetActiveSlot3c_Refcount_Inferred(void* host /*ECX*/, void* new_obj /*stack*/);
```

## Product / domain evidence

- Tear path `PalantirEnv_TearDefaultLights_Inferred` (`FUN_0048eb10`) calls with **null** to clear dir-light attach (`push 0`; `ECX = env+4`).
- Rebuild `PalantirEnv_RebuildDefaultLights_Inferred` (`FUN_0048f370`) attaches Direction light host after `FUN_0074e310`.
- Host UI path `FUN_00792600` attaches `"Directional"` light `+0x8c` through same mgr pattern.
- Product English for the manager class itself remains structural (`_Inferred`); slot role sealed by light rebuild/tear peers (W34-T).

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0074e0d0_FUN_0074e0d0.md` (+ W37-AE append)
- Annotated: `docs/reconstruction/raw/aa_0074e0d0_FUN_0074e0d0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/LightMgr_SetActiveSlot3c_Refcount_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_0074e0d0.cpp`
- A: `docs/reconstruction/reviews/A_aa_0074e0d0_LightMgr_SetActiveSlot3c_Refcount_Inferred.md`
- B: `docs/reconstruction/reviews/B_aa_0074e0d0_LightMgr_SetActiveSlot3c_Refcount_Inferred.md`

## Callers / callees

| Dir | Target |
|-----|--------|
| Caller | `FUN_0048f370` @ `0x0048f3f9` (RebuildDefaultLights) |
| Caller | `FUN_0048eb10` @ `0x0048eb54` (TearDefaultLights; arg 0) |
| Caller | `FUN_00792600` @ `0x00792784` (Directional attach) |
| Callee | virtual only: `new_obj->vtbl[+4]`, `old->vtbl[+8]` |

## Confidence

| Claim | Level |
|---|---|
| Body 55 B / RET 4 / thiscall | **High** |
| Slot `+0x3c` store | **High** |
| Refcount at `obj+4`; vtbl +4 / +8 | **High** |
| Light-mgr domain from callers | **High** |
| Product C++ class English | **Low** (structural name) |
