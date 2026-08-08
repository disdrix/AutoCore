# Function record: CVOGCharacter_TryType1aSimpleExchange_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00531570` |
| **Canonical name** | `CVOGCharacter_TryType1aSimpleExchange_Inferred` |
| **Address** | `0x00531570` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `inventory-transfer` |
| **Completion status** | **Dual present** — A/B accept-with-gaps (WQ8R-B 2026-08-04) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias / history

| Name | Notes |
|------|-------|
| `FUN_00531570` | Ghidra auto |
| `CVOGCharacter_TryType1aSimpleExchange_Inferred` | Dual WQ8R-B; type `0x1a` single-ingredient exchange |

## Purpose

Consume `qty` of ingredient CBID `blob+0x4c0` from cargo+locker, require free cargo footprint (InvSize `+0x406/+0x407`), grant `(u8)blob+0x4c9 * qty` of product CBID `object+0x34`. Type gate `object+0x38 == 0x1a`.

## Signature

```c
uint32_t __thiscall CVOGCharacter_TryType1aSimpleExchange_Inferred(
    CVOGCharacter* self,
    void* type1aObject,
    int requestQty);   // ret 8
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00531570_FUN_00531570.md`
- Annotated: `docs/reconstruction/raw/aa_00531570_FUN_00531570.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGCharacter_TryType1aSimpleExchange_Inferred.cpp`
- Scaffold clean (legacy): `docs/reconstruction/reconstructed-exact/FUN_00531570.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00531570_CVOGCharacter_TryType1aSimpleExchange_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00531570_CVOGCharacter_TryType1aSimpleExchange_Inferred.md`
- Report: `docs/agents/task-dual-ab-00531570-005316c0-wq8rb-report.md`

## Callers / callees

| Direction | Symbol | VA | Notes |
|-----------|--------|-----|-------|
| Callers | *(none direct)* | — | zero code xrefs; likely vtable |
| Callee | `InventoryGrid_CountItemsByCbid` | `0x005711c0` | cargo then locker |
| Callee | `InventoryGrid_FindFreeSlot` | `0x005713a0` | cargo, page `-1` |
| Callee | `CVOGReaction_RemoveInventoryItem` | `0x005721c0` | cargo then locker |
| Callee | `FUN_005310a0` | `0x005310a0` | give cbid×qty |

## Confidence

| Claim | Level |
|---|---|
| Control flow + dual-grid ECX | **High** |
| Parameter semantic names | **High** (role); product type name **Tentative** |
| Types | **Probable** |
