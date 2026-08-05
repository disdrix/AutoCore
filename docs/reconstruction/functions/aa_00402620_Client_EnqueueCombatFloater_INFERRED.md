# Function record: Client_EnqueueCombatFloater_INFERRED

| Field | Value |
|---|---|
| **Stable ID** | `aa_00402620` |
| **Canonical name** | `Client_EnqueueCombatFloater_INFERRED` |
| **Address** | `0x00402620` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Completion status** | **Human-refined scaffold** — clean rewritten; dual review still open; floater element type incomplete |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Append a combat-floater UI entry to a vector-like queue on the client. Used by kill-award / session XP paths (plate: floater type XP = 3). Element size is **0x38**; storage triad is `begin/end/capacity` at `this+0x04/+0x08/+0x0C`.

## Signature (decompiler-derived + refined)

```c
void Client_EnqueueCombatFloater_INFERRED(void* queue /*this*/, uint32_t value);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00402620_Client_EnqueueCombatFloater_INFERRED.md`
- Annotated: `docs/reconstruction/raw/aa_00402620_Client_EnqueueCombatFloater_INFERRED.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Client_EnqueueCombatFloater_INFERRED.cpp`

## Callers / callees

| Direction | Symbol / VA | Notes |
|---|---|---|
| Callee | `FUN_00404600` | In-place construct count=1 at end |
| Callee | `FUN_00402e20` | Grow/push when full or begin null |
| Callers | (kill-award / XP path; plate) | Confirm via xrefs in follow-up |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Queue triad + element size 0x38 | High |
| XP / kill-award use | Probable (plate comment; callers not fully mapped) |
| Floater payload type / layout | Tentative (`value` still opaque) |
