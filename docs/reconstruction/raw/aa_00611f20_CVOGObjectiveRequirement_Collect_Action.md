# Raw capture: CVOGObjectiveRequirement_Collect_Action

| Field | Value |
|---|---|
| **Stable ID** | `aa_00611f20` |
| **VA** | `0x00611f20` |
| **Canonical name** | `CVOGObjectiveRequirement_Collect_Action` |
| **Prior** | `FUN_00611f20` |
| **System** | missions-progression |
| **Capture** | 2026-07-29 Ghidra `batch_decompile` |
| **Integrity** | Append-only; do not erase raw body |

## Raw pseudocode (authoritative)

```c
uint __thiscall
FUN_00611f20(int *param_1,int param_2,undefined4 param_3,int *param_4,float param_5,float param_6,
            undefined4 param_7,int *param_8)

{
  /* Collect event handler:
     param_4 == 0 / null: death-loot path (OptionalDropPercent, GiveItemByCbid)
     param_4 == 1: inventory-change path (CountItemsByCbid delta vs NumToCollect)
     param_1[4] = item CBID, param_1[5] = NumToCollect, param_1[7] = optional target count
     cargo via param_2 (character) +0x250 → grid for CountItemsByCbid @ 0x005711c0
  */
  // ... full body in prior scaffold aa_00611f20_FUN_00611f20.md; re-decompile 2026-07-29 matches ...
}
```

## Versioned note 2026-07-29

Full decompile re-fetched; behavioral map:

| Branch | Condition | Effect |
|--------|-----------|--------|
| Level gate | `param_1[0x16]` level-req flag | Skip if char level outside `[0x17,0x18]` |
| TargetIsPlayer | `+0x19` | Race/class bitmask path on killer |
| Kill loot | `param_4==0` and cargo present and count < need | Match optional targets; roll drop %; GiveItemByCbid + place |
| Inventory event | `param_4==1` and cargo | `count = CountItemsByCbid(CBID)`; if item CBID match and count-delta < need → return 1 (progress signal) |

Legacy raw body: `aa_00611f20_FUN_00611f20.md` (full text preserved).
