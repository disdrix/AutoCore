# Function record: AssPreloader_ProcessKeyRingStep_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ed310` |
| **Canonical name** | `AssPreloader_ProcessKeyRingStep_Inferred` (**Inferred** structural) |
| **Ghidra name** | `FUN_004ed310` |
| **Address** | `0x004ed310`–`0x004ed46b` |
| **Body** | **348 B** / `0x15C` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | AssPreloader / client-fx preload key ring |
| **Completion status** | **Dual-reviewed** W35-A — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

Process one cooperative step of a GuardedVector **preload key ring**: erase keys already tracked by AssPreloader, enqueue the first unready key (and deps), and yield until resources/tree readiness allows advancing. Gate and nested ECX come from global `DAT_00d1f050` / `+0x6c`.

## Signature

```c
// cdecl; plain RET; AL = 1 exhausted / 0 yield
uint8_t AssPreloader_ProcessKeyRingStep_Inferred(
    GuardedVectorHeader* ring,   // stack+4
    char* progress_flag,         // stack+8
    uint32_t* cursor);           // stack+c
```

| Formal | Source | Conf |
|---|---|---|
| ring | Stack[+4] GuardedVector* | **High** |
| progress_flag | Stack[+8] char* | **High** |
| cursor | Stack[+0xc] uint* | **High** |
| cleanup | plain `RET` (cdecl) | **High** |
| return | **AL** 0/1 | **High** |

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | FxCache_ApplyWithNfxEnsure (`00542790`); `00542e20`; `005575c0`; `005c6ad0` |
| Callees | IsKeyTrackedRecursive (`00971900`); pending remove (`00971030`); EraseRange_Thiscall (`0043df90`); cache present (`0075d610`); tree ready (`00971a20`); EnqueueKeyAndDeps (`009717a0`) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004ed310_FUN_004ed310.md`
- Annotated: `docs/reconstruction/raw/aa_004ed310_FUN_004ed310.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/AssPreloader_ProcessKeyRingStep_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_004ed310.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_004ed310_AssPreloader_ProcessKeyRingStep_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_004ed310_AssPreloader_ProcessKeyRingStep_Inferred.md`
