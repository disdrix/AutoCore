# Function record: Host_EnsureRegionCellOwned_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00494700` |
| **Canonical name** | `Host_EnsureRegionCellOwned_Inferred` (**Inferred** structural) |
| **Ghidra name** | `FUN_00494700` |
| **Address** | `0x00494700` |
| **Body** | `0x00494700`–`0x0049484f` exclusive (**335 B** / `0x14F`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | host grid region ensure (ListTrackedObj per cell) |
| **Completion status** | **Dual-reviewed** W31-C — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

For each cell in host region `[+0x64,+0x6c)×[+0x68,+0x70)` of the **0x28-stride** grid @ `host+0x28` (dimX @ `+4`): if `cell+0x24` null, allocate **0x5E0** `ListTrackedObj`, construct (`FUN_004becb0`), bind context @ `+0x5D4`, place (`FUN_004bd890`), populate (`FUN_004bf690`), store owned pointer; optional global-list pressure eviction via `ListTrackedObj_CompleteDtor` + `operator_delete`. If already owned, MRU-relink (`FUN_004bd6f0`). Busy flag `host+0x53` 0→1 around the loop.

## Signature

```c
// ECX = host. Stack: context. SEH LAB_009a0bd0. RET 4.
void __thiscall Host_EnsureRegionCellOwned_Inferred(void* host, void* ctx);
```

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `FUN_004951d0` (static culling); `FUN_00495130` |
| Callees | `operator_new`, `FUN_004becb0`, `FUN_004bd890`, `FUN_004bf690`, `FUN_004bd660`, `ListTrackedObj_CompleteDtor` (`0x004be2a0`), `operator_delete`, `FUN_004bd6f0` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00494700_FUN_00494700.md`
- Annotated: `docs/reconstruction/raw/aa_00494700_FUN_00494700.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Host_EnsureRegionCellOwned_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00494700.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00494700_Host_EnsureRegionCellOwned_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00494700_Host_EnsureRegionCellOwned_Inferred.md`
- Scaffold record: `docs/reconstruction/functions/aa_00494700_FUN_00494700.md`

## Confidence

| Claim | Level |
|---|---|
| Region loop + 0x28 cell formula | **High** |
| thiscall + RET 4 + busy flag | **High** |
| Create path 0x5E0 + ListTrackedObj ctor | **High** |
| Eviction → CompleteDtor + delete | **High** |
| Product host/context English | **Low** |
| Pressure policy product meaning | **Med** |
