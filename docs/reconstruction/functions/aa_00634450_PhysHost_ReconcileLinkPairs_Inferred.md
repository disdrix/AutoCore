# Function record: PhysHost_ReconcileLinkPairs_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00634450` |
| **Canonical name** | `PhysHost_ReconcileLinkPairs_Inferred` |
| **Ghidra name** | `FUN_00634450` |
| **Address** | `0x00634450`–`0x0063453f` (**240 B** / `0xF0`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | phys / host link-pair reconcile |
| **Completion status** | **Dual sealed** (W29-R 2026-07-29) — A/B accept |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Ghidra: `FUN_00634450`
- Prior scaffold alias: `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_Cre_00634450` (superseded)

## Purpose

Reconcile a phys host's link-pair set against the manager after bounds/pose writes. Dual stride-8 worklists, manager query vtbl+0x14, CanonAndSort + SortedDiffWalk, compact host+0x3c, dual release. Callers are AABB/pose copy paths (`FUN_00580c00` / `FUN_00580dd0` / `FUN_005eb*`).

## Signature (machine)

```c
// thiscall; ECX = host; stack = query_param; ret 4; void
void PhysHost_ReconcileLinkPairs_Inferred(int host, unsigned query_param);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00634450_FUN_00634450.md` (+ W29-R append)
- Annotated: `docs/reconstruction/raw/aa_00634450_FUN_00634450.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/PhysHost_ReconcileLinkPairs_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00634450.cpp`
- Function: `docs/reconstruction/functions/aa_00634450_FUN_00634450.md`
- Review A: `docs/reconstruction/reviews/A_aa_00634450_PhysHost_ReconcileLinkPairs_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00634450_PhysHost_ReconcileLinkPairs_Inferred.md`

## Callers / callees

| Direction | Targets |
|---|---|
| Callers (8) | `FUN_00580c00`, `FUN_00580dd0`, `FUN_005eb0e0`, `FUN_005eb130`, `FUN_005eb2b0`, `FUN_005eb320`, `FUN_005eb8e0`, `FUN_005eb9e0` |
| Callees | `FUN_0062d960`×2, vtbl+0x14, `LinkPair_CanonAndSort`×2, `LinkPair_SortedDiffWalk`, `FUN_005fff20`, `LocalWorklist_Release`×2 |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler ≡ live | **High** |
| ABI thiscall / `ret 4` | **High** |
| Dual worklist + SortedDiffWalk role | **High** |
| Machine SortedDiffWalk ECX | **High** |
| Product host type English | **Tentative** |
| Runtime / bit-exact | **Open** |
