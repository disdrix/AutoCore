# Function record: CVOGCharacter_TryType1aCraft_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005316c0` |
| **Canonical name** | `CVOGCharacter_TryType1aCraft_Inferred` |
| **Address** | `0x005316c0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `inventory-transfer` |
| **Completion status** | **Dual present** — A/B accept-with-gaps (WQ8R-B 2026-08-04) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias / history

| Name | Notes |
|------|-------|
| `FUN_005316c0` | Ghidra auto |
| `CVOGCharacter_TryType1aCraft_Inferred` | Dual WQ8R-B; multi-ingredient craft + mode |

## Purpose

Mode-aware craft: count batches (`FUN_00522060`), cargo free-slot probe, consume primary (`+0x4d0/+0x4d4`) and/or secondary list (`+0x498…`), grant product `*(blob+4)`. Soft-success if nothing craftable.

## Signature

```c
uint32_t __thiscall CVOGCharacter_TryType1aCraft_Inferred(
    CVOGCharacter* self,
    void* type1aObject,
    int craftQty,
    int mode);   // ret 12; mode 1 skips primary, 2 skips secondary
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005316c0_FUN_005316c0.md`
- Annotated: `docs/reconstruction/raw/aa_005316c0_FUN_005316c0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGCharacter_TryType1aCraft_Inferred.cpp`
- Scaffold clean (legacy): `docs/reconstruction/reconstructed-exact/FUN_005316c0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_005316c0_CVOGCharacter_TryType1aCraft_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_005316c0_CVOGCharacter_TryType1aCraft_Inferred.md`
- Report: `docs/agents/task-dual-ab-00531570-005316c0-wq8rb-report.md`

## Callers / callees

| Direction | Symbol | VA | Notes |
|-----------|--------|-----|-------|
| Callers | *(none direct)* | — | zero code xrefs |
| Callee | `FUN_004f1e20` | `0x004f1e20` | ensure blob loaded |
| Callee | `FUN_00522060` | `0x00522060` | craftable batch count |
| Callee | `InventoryGrid_FindFreeSlot` | `0x005713a0` | cargo, page `-1` |
| Callee | `InventoryGrid_CountItemsByCbid` | `0x005711c0` | primary dual-grid |
| Callee | `CVOGReaction_RemoveInventoryItem` | `0x005721c0` | primary + secondary |
| Callee | `FUN_00599dd0` | `0x00599dd0` | secondary slot count |
| Callee | `FUN_005310a0` | `0x005310a0` | give product |

## Confidence

| Claim | Level |
|---|---|
| Control flow + mode matrix | **High** |
| Soft no-op return 1 | **High** (CF) |
| Product English / callers | **Tentative / Open** |
