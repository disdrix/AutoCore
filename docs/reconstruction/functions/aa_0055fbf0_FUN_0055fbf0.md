# Function record: FUN_0055fbf0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0055fbf0` |
| **Canonical name** | `WorldObj_UnbindLinks_Inferred` |
| **Ghidra name** | `FUN_0055fbf0` |
| **Address** | `0x0055fbf0`–`0x0055fd72` (**386 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | world-object / manager unbind |
| **Completion status** | **Sealed** W26-D dual A/B 2026-07-29 |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

- `FUN_0055fbf0`
- Prior auto: `Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_SetObjectActiveSta_0055fbf0` (xref-path noise)
- Role synonym used in prior duals: unbind / remove links

## Purpose

Manager **unbind / remove spatial-query links** for a world object. Always preprocesses `*(manager+0x234)` via `FUN_0062d960` and finishes with `FUN_0055f4c0`. Optional simple or complex clear of query hits based on `*(obj+0x40)`.

## Signature (sealed)

```c
// thiscall; ret 4; void
void WorldObj_UnbindLinks_Inferred(void *manager /*ECX*/, void *obj /*stack*/);
```

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0055fbf0_FUN_0055fbf0.md` |
| Annotated | `docs/reconstruction/raw/aa_0055fbf0_FUN_0055fbf0.annotated.md` |
| Clean (named) | `docs/reconstruction/reconstructed-exact/WorldObj_UnbindLinks_Inferred.cpp` |
| Clean (FUN_*) | `docs/reconstruction/reconstructed-exact/FUN_0055fbf0.cpp` |
| Named record | `docs/reconstruction/functions/aa_0055fbf0_WorldObj_UnbindLinks_Inferred.md` |
| Review A | `docs/reconstruction/reviews/A_aa_0055fbf0_WorldObj_UnbindLinks_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0055fbf0_WorldObj_UnbindLinks_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_0055fbf0.md` |

## Callers / callees

| Direction | Symbol | Notes |
|---|---|---|
| Callee | `FUN_0062d960` | entry preprocess on `manager+0x234` |
| Callee | vcall `*(mgr+0xc4)+0xc` | query into stack out |
| Callee | `FUN_006297e0` | clear/simple and per-hit |
| Callee | `FUN_006caaa0` | complex path |
| Callee | `FUN_0055f4c0` | always; stack alloc cleanup |
| Callee | `*DAT_00b05060+0x14` | optional free tag `0x12` |
| Caller | `FUN_00560e90` | RebindActivate (unbind→bind) |
| Caller | `FUN_00561450` | RemoveOrDefer unbind chain |
| Caller | `FUN_005614f0`, `FUN_00561370` | sibling manager paths |

## Confidence

| Claim | Level |
|---|---|
| CF stages + dual exit `FUN_0055f4c0` | **High** |
| thiscall manager/obj + ret 4 | **High** |
| Unbind role vs bind `0055fa40` | **High** (caller duals) |
| Nested callee product contracts | **Open** (not OWN) |
| Product English plate | **Inferred** |
| Runtime / bit-exact | **Open** |
