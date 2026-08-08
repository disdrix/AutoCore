# Function record: Character_CountType1aCraftableBatches

| Field | Value |
|---|---|
| **Stable ID** | `aa_00522060` |
| **Canonical name** | `Character_CountType1aCraftableBatches` |
| **Ghidra name** | `FUN_00522060` |
| **Prior scaffold** | `FUN_00522060` / `Named_CalleeOf_Inv_Client_ValidateCraftAffordability_00522060` (**retired**) |
| **Address** | `0x00522060`–`0x00522203` inclusive (**420 B** / `0x1A4`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `inventory-transfer` |
| **Agent** | MEGA-002 OWN-ONLY dual 2026-08-05 |
| **Completion status** | Dual sealed (A/B **accept-with-gaps**) |
| **Terminal** | **false** |

## Alias / history

| Name | Notes |
|------|-------|
| `FUN_00522060` | Ghidra auto |
| `Named_CalleeOf_Inv_Client_ValidateCraftAffordability_00522060` | Scaffold parent-seed — **retired** |
| `Character_CountType1aCraftableBatches` | Dual MEGA-002; type-0x1a craft batch counter |

## Purpose

Character method: count affordable **type-0x1a** craft batches from **cargo + locker** grids. Writes total to `*outBatches`; returns whether total is positive. Mode-aware primary bank (`blob+0x4d0/+0x4d4`) and secondary CBID list (`blob+0x498…`); simple flag uses `blob+0x4c0` only.

```text
*out = 0
require this+0x250, *(+0x250)+0x2b0, this+0xcbc, obj+0x38==0x1a, obj+0x3c
if simpleFlag: *out = count both grids of +0x4c0; return *out != 0
if mode != 1 and cost@+0x4d4 > 0: *out += floor(have(+0x4d0) / cost)
if mode != 2: *out += min(secondary slot counts)   // ADD not min-with-primary
return *out > 0
```

## Signature

```c
// __thiscall: ECX = character; RET 0x10; AL bool
bool __thiscall Character_CountType1aCraftableBatches(
    void *self,
    void *type1aObject,
    int *outBatches,
    char mode,         // 0 both, 1 skip primary, 2 skip secondary
    char simpleFlag);  // !=0 → simple +0x4c0 path
```

## Layout (touched)

| Offset | Object | Field |
|---|---|---|
| +0x250 | character | cargo holder* |
| +0x2b0 | holder | cargo InventoryGrid* |
| +0xcbc | character | locker InventoryGrid* |
| +0x38 | item/object | type (must be `0x1a`) |
| +0x3c | item/object | recipe blob* |
| +0x4c0 | blob | simple-path CBID |
| +0x4d0 | blob | primary material CBID |
| +0x4d4 | blob | primary cost per batch (char) |
| +0x498..+0x4a8 | blob | up to 5 secondary CBIDs (`-1` empty) |

## Call graph

| Role | Target |
|---|---|
| **Callers** | `CVOGCharacter_TryType1aCraft_Inferred` `0x005316c0` @ `0x00531750`; `FUN_0089bc30` @ `0x0089bdb5`; `FUN_0089bf50` @ `0x0089c1a6`; `FUN_0089c330` @ `0x0089c383`; xref `0x0089cc96` |
| Callee | `InventoryGrid_CountItemsByCbid` `0x005711c0` (dual cargo+locker; includeBroken=0) |
| Callee | `ItemDef_CountConfiguredModSlots_Inferred` `0x00599dd0` (secondary slot count 0..5) |
| Parent craft | dualed `CVOGCharacter_TryType1aCraft_Inferred` |

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/Character_CountType1aCraftableBatches.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00522060.cpp`
- Retired scaffold: `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Inv_Client_ValidateCraftAffordability_00522060.cpp`
- Raw (+ re-verify): `docs/reconstruction/raw/aa_00522060_FUN_00522060.md`
- Annotated: `docs/reconstruction/raw/aa_00522060_FUN_00522060.annotated.md`
- Review A: `docs/reconstruction/reviews/A_aa_00522060_Character_CountType1aCraftableBatches.md`
- Review B: `docs/reconstruction/reviews/B_aa_00522060_Character_CountType1aCraftableBatches.md`
- Report: `docs/agents/task-dual-ab-00522060-mega-002-report.md`

## Confidence

| Claim | Level |
|---|---|
| CF / type-0x1a gate / mode matrix | **Confirmed** |
| thiscall + RET 0x10 + dual-grid counts | **Confirmed** |
| Primary ADD secondary (not min) | **Confirmed** |
| Product field English | **Inferred** / open |
| Runtime / bit-exact / differential | **Open** |
