# Function record: Skill_ApplyMultiTargetHits_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0058c850` |
| **Canonical name** | `Skill_ApplyMultiTargetHits_Inferred` |
| **Address** | `0x0058c850`–`0x0058cc3f` (**1008** bytes) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `skills-abilities` / combat multi-target apply |
| **Completion status** | **Dual A/B sealed** (accept-with-gaps) — 2026-07-29 W20-Q |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

| Name | Notes |
|---|---|
| `FUN_0058c850` | Ghidra default |
| `Named_CalleeOf_Named_VOG_DEBUG_STOP_0058c850` | obsolete parent-seed scaffold |
| `Skill_ApplyMultiTargetHits_Inferred` | **canonical** (role; no product string) |

## Purpose

Resolve a **TFID target list** into a CS-guarded object list, then for each target: **accuracy** (skip first), **roll/compute damage**, **scale**, **apply single hit** (or combat floater on miss). Returns **summed damage**.

## Signature (sealed)

```c
// __cdecl  SEH frame; bare ret
int Skill_ApplyMultiTargetHits_Inferred(
    void *skillHost,           // param_1 — AccuracyHitCheck this / scale host
    uint32_t *tfidListHead,    // param_2 — stride 16; end (lo&hi)==0xffffffff
    void *damageSource,        // param_3 — fields +0x54..+0x68, +0x140/+0x144
    uint32_t unused_param4,    // param_4 — **unused in body**
    void *rollTable,           // param_5 — ushort*; index (i%600)*2
    int rollSeedIndex);        // param_6 — *6 once, +6 per target
// return: total damage int; 0 if null/empty list
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0058c850_FUN_0058c850.md`
- Annotated: `docs/reconstruction/raw/aa_0058c850_FUN_0058c850.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Skill_ApplyMultiTargetHits_Inferred.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_0058c850.cpp`
- Legacy Named: `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_VOG_DEBUG_STOP_0058c850.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_0058c850_Skill_ApplyMultiTargetHits_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0058c850_Skill_ApplyMultiTargetHits_Inferred.md`
- Scaffold record: `docs/reconstruction/functions/aa_0058c850_FUN_0058c850.md`

## Callers / callees

| Direction | Address | Name / role |
|---|---|---|
| Caller | `0x0054c720` / site `0x0054c79d` | Character skill apply (`VOG_DEBUG_STOP` path) |
| Caller | `0x0058d8e0` / site `0x0058d952` | Single-TFID wrapper from `obj+0x160` |
| Caller | `0x0061c090` / site `0x0061c104` | Multi-hit when `skill+0x624` bit0 |
| Callee | `0x004bae70` | `CVOGReaction_ResolveObjectTarget` |
| Callee | `0x004024d0` | list push |
| Callee | `0x0040b020` | list iterate |
| Callee | `0x004bcbf0` | list teardown |
| Callee | `0x00553240` | `Skill_AccuracyHitCheck_Inferred` |
| Callee | `0x004cf080` | damage scale |
| Callee | `0x004d7e30` | `Client_Combat_ApplySingleHitMaybeDefer_Inferred` |
| Callee | `0x00402620` | `Client_EnqueueCombatFloater_INFERRED` |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | **High** / **Confirmed** |
| Body size / bare ret | **Confirmed** (`read_memory` + Ghidra body) |
| First-target accuracy skip | **Confirmed** |
| param_4 unused | **Confirmed** |
| Return = damage sum | **Confirmed** |
| Product name | Inferred |
| Full damage field English | Tentative |
| Runtime | Open |
