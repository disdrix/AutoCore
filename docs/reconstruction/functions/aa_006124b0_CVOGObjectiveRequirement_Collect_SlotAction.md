# Function record: CVOGObjectiveRequirement_Collect_SlotAction

| Field | Value |
|---|---|
| **Stable ID** | `aa_006124b0` |
| **Canonical name** | `CVOGObjectiveRequirement_Collect_SlotAction` |
| **Prior name** | `FUN_006124b0` |
| **Address** | `0x006124b0` |
| **Body** | `0x006124b0`–`0x006126c1` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression (+ inventory collect bridge) |
| **Calling convention** | MSVC `__thiscall` — `this` = `CVOGObjectiveRequirement_Collect*` |
| **Completion status** | **Human-refined** — dual residual ABI/count/format sealed 2026-07-29 |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Format Collect objective progress for journal/UI as `"<itemName>: <have> / <NumToCollect>"`, where **have** is a **live cargo inventory recount** via `InventoryGrid_CountItemsByCbid`, capped at `NumToCollect`. Optionally appends `" Level: min-max"` when req `+0x58` is set.

This is the Collect counterpart of `CVOGObjectiveRequirement_UseItem_SlotAction` (`0x0060d060`), but UseItem reads **slot floats** from objective state while Collect reads **cargo**.

## Signature (asm-sealed)

```c
// Shared SlotAction family: four stack dwords (RET 0x10). Collect uses character only.
int __thiscall CVOGObjectiveRequirement_Collect_SlotAction(
    void* this,          // requirement (ECX → ESI)
    int character,       // stack0 — cargo host (char+0x250→+0x2b0)
    void* objState,      // stack1 — unread here (UseItem uses for slot floats)
    char* outBuf,        // stack2
    size_t outCap);      // stack3
// RET 0x10
```

Decompiler historically dropped character into `unaff_retaddr` (SEH stack analysis failure). Asm: `MOV EBP,[ESP+0x32c]` after `PUSH EBP` @ `0x00612522`.

## Offsets

| Offset | Field | Evidence |
|-------:|-------|----------|
| req `+0x10` | item CBID | `FUN_00404d70` + CountItemsByCbid; XML `CBID` |
| req `+0x14` | NumToCollect | display total / cap; XML `NumToCollect` |
| req `+0x58` | level-range text flag | SerializeXml RequireLevel* path |
| req `+0x5c` / `+0x60` | level min/max | sprintf Level append |
| char `+0x250` → `+0x2b0` | cargo `InventoryGrid` | same type-1 grid as DropResponse |

## Control flow

```
item = lookup(CBID)
if !item: return 0
if !character || !vehicle || !cargo: return 0
have = CountItemsByCbid(cargo, CBID, includeBroken=0)
display = min(have, NumToCollect)   // 2nd Count only when have < need
sprintf "%s: %d / %d"
optional Level append
strncat out; return strlen
```

## Residual seal (2026-07-29)

| Residual | Status | Evidence |
|---|---|---|
| Stack ABI `RET 0x10` / four formals | **Sealed High** | body epilogue `C2 10 00` |
| character = stack0 | **Sealed High** | `MOV EBP,[ESP+0x32c]` |
| stack1 unread family formal | **Sealed High** | no load; sibling UseItem |
| Double Count calls | **Sealed High** | CALL @ `0x0061255e`, `0x0061257b` |
| Count ECX + includeBroken=0 | **Sealed High** | asm + Count residual |
| Format VAs | **Sealed High** | `0x009df764` / `0x009e1734` / `0x00a41404` |
| Inventory UI vs 0x2071 authority | **Sealed** dual-path | UseItem contrast + missionHandler |
| Runtime / differential | Open | needs live capture |

Scratch: `reviews/a_006124b0.md`.

## Vtable / class evidence

| Evidence | Value |
|----------|-------|
| Collect vtable | `PTR_FUN_009e12c4` (set in ctor `0x00611690`) |
| This slot | `009e12dc` → `0x006124b0` (vtable +0x18) |
| Type code | ctor writes `param_1[3] = 2` (= Collect `RequirementType`) |
| RTTI string | `.?AVCVOGObjectiveRequirement_Collect@@` |
| XML | `"collect"`, `NumToCollect` via sibling `0x00611a00` |

## Artifacts

| Kind | Path |
|------|------|
| Raw | `raw/aa_006124b0_FUN_006124b0.md` (body frozen; append-only) |
| Annotated | `raw/aa_006124b0_FUN_006124b0.annotated.md` |
| Clean | `reconstructed-exact/CVOGObjectiveRequirement_Collect_SlotAction.cpp` |
| Dual A | `reviews/A_aa_006124b0_CVOGObjectiveRequirement_Collect_SlotAction.md` |
| Dual B | `reviews/B_aa_006124b0_CVOGObjectiveRequirement_Collect_SlotAction.md` |
| Residual | `reviews/a_006124b0.md` |
| Chain | `reviews/CHAIN_2026-07-29_inventory_collect.md` |

## Callers / callees

| Direction | Target | Role |
|-----------|--------|------|
| DATA xref | Collect vtable `009e12dc` | virtual SlotAction |
| callee | `InventoryGrid_CountItemsByCbid` `0x005711c0` | live count (×2 when under target) |
| callee | `FUN_00404d70` | CBID → item/clonebase |
| callee | `sprintf` / `strncat` | UI string |

## Confidence

| Claim | Level |
|---|---|
| Live inventory count for Collect UI | **High** |
| Same cargo grid as inventory type 1 | **High** |
| Shared four-stack SlotAction ABI | **High** |
| Name `Collect_SlotAction` (role match UseItem) | **High** (behavior); original symbol unknown |
| Character arg as stack0 | **High** (asm) |
| Runtime / bit-exact | Open |

## Related

- `aa_00611940` Collect_Eval — same count/NumToCollect ratio for completion fraction
- `aa_005711c0` CountItemsByCbid (+ residual `a_005711c0.md`)
- `aa_00611a00` Collect XML deserialize
- `aa_0060d060` UseItem_SlotAction (packet-float analog)
- Dual residual: `reviews/a_006124b0.md`
