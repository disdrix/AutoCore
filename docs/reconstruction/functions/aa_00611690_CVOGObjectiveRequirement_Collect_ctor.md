# Function record: CVOGObjectiveRequirement_Collect_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00611690` |
| **Canonical name** | `CVOGObjectiveRequirement_Collect_ctor` |
| **Prior name** | `FUN_00611690` |
| **Address** | `0x00611690` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Calling convention** | MSVC `__thiscall` + one stack dword; **`RET 4`** |
| **Completion status** | **Human-refined** — dual A/B seal type=2 2026-07-29 |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Construct a **`CVOGObjectiveRequirement_Collect`** instance:

- Base requirement link (`FUN_00637da0(parent)`).
- Install Collect vtable `0x009e12c4`.
- Set **RequirementType = 2** at `this+0x0c`.
- Initialize Collect fields (CBID −1, NumToCollect 0, OptionalDropPercent 0.0f, sentinel pads).

## Signature

```c
void* __thiscall CVOGObjectiveRequirement_Collect_ctor(
    void* this,     // ECX
    void* parent);  // stack0 → stored at this+0x04
// returns this; RET 4
```

## Key facts (sealed)

| Fact | Value | Confidence |
|------|-------|------------|
| RequirementType | **2** @ `+0x0c` | **High / Confirmed** |
| Vtable | `PTR_FUN_009e12c4` / `0x009e12c4` | **High** |
| RTTI | `.?AVCVOGObjectiveRequirement_Collect@@` | **High** |
| Factory string | UTF-16 `"collect"` @ `0x009d0b34` | **High** |
| Alloc size | **0x68** (factory `PUSH 0x68`) | **High** |
| Sole caller | `FUN_00547050` @ `0x00547337` | **High** |
| CBID default | `+0x10 = 0xFFFFFFFF` | **High** |
| NumToCollect default | `+0x14 = 0` | **High** |
| OptionalDropPercent | `+0x48 = 0.0f` (`movss`) | **High** |

## Offsets (ctor-owned)

| Offset | Init | Field |
|-------:|------|-------|
| `+0x00` | Collect vtable | `CVOGObjectiveRequirement_Collect` vfptr |
| `+0x04` | parent | from base ctor |
| `+0x0c` | **2** | RequirementType Collect |
| `+0x10` | −1 | `collectReqItemCbid` (pre-XML) |
| `+0x14` | 0 | `collectReqNumToCollect` |
| `+0x48` | 0.0f | OptionalDropPercent |

## Callers / callees

| Direction | Target | Note |
|-----------|--------|------|
| Caller | `FUN_00547050` (`0x00547337`) | Objective requirement factory; wide `"collect"` |
| Callee | `FUN_00637da0` | Shared requirement base ctor |

## Vtable consumers (not this unit)

| Slot | VA | Name |
|-----:|-----|------|
| `+0x04` | `0x00611f20` | `CVOGObjectiveRequirement_Collect_Action` |
| `+0x10` | `0x00611940` | `CVOGObjectiveRequirement_Collect_Eval` |
| `+0x18` | `0x006124b0` | `CVOGObjectiveRequirement_Collect_SlotAction` |
| `+0x48` | `0x00611a00` | `CVOGObjectiveRequirement_Collect_DeserializeXml` |

## Artifacts

- Review A: `docs/reconstruction/reviews/A_aa_00611690_CVOGObjectiveRequirement_Collect_ctor.md`
- Review B: `docs/reconstruction/reviews/B_aa_00611690_CVOGObjectiveRequirement_Collect_ctor.md`
- Raw: `docs/reconstruction/raw/aa_00611690_FUN_00611690.md`
- Annotated: `docs/reconstruction/raw/aa_00611690_FUN_00611690.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGObjectiveRequirement_Collect_ctor.cpp`
- Legacy scaffold: `functions/aa_00611690_FUN_00611690.md`, `reconstructed-exact/FUN_00611690.cpp`
- Chain: `reviews/CHAIN_2026-07-29_inventory_collect.md`
- Report: `docs/agents/task-dual-ab-00611690-collect-requirement-ctor-report.md`

## Related

- Deliver ctor type **3**: `0x00610bc0` (do not conflate).
- Inventory bridge: Eval/SlotAction + `InventoryGrid_CountItemsByCbid`.
