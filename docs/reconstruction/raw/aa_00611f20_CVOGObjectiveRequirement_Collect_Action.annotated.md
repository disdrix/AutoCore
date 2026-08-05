# Annotated: CVOGObjectiveRequirement_Collect_Action (`aa_00611f20`)

| Field | Value |
|---|---|
| **VA** | `0x00611f20` |
| **System** | missions-progression |

## Signature (corrected)

```c
// this = Collect requirement instance
// character = param_2
// eventType = param_4 (0=death/loot, 1=inventory change) — decompiler int*
// returns low-byte bool-like in many paths (1 = handled/progress)
uint __thiscall CVOGObjectiveRequirement_Collect_Action(
    CollectReq* this,
    Character* character,
    ...,
    int eventType,
    float itemCbidOrQty,  // param_5 overloaded by event
    float qtyDelta,       // param_6 inventory path
    ...,
    Object* killerOrActor);
```

## Field map (req)

| Offset | Role | Evidence |
|-------:|------|----------|
| `[4]` / +0x10 | Item CBID | CountItemsByCbid / GiveItemByCbid |
| `[5]` / +0x14 | NumToCollect | compare count |
| `[7]` / +0x1c | OptionalTarget count | loop bound |
| `+8..` | OptionalTargetCBID[10] | kill match |
| `+0x19` | TargetIsPlayer | race path |
| `+0x1a` | TargetIsTemplateVehicle | template match |
| `[0x12]` / +0x48 | OptionalDropPercent | float roll |
| `[0x13]` / +0x4c | GiveToAllConvoyMembers | convoy loop |
| `[0x16]` | RequireLevel flag | level min/max |
| `[0x17]/[0x18]` | Level min/max | vtbl +0x27c |

## Side-effect order (kill path)

1. Level gate (optional)
2. Require cargo grid on character vehicle
3. Count current holdings; if already at need, skip spawn
4. Match optional kill targets (CBID or template)
5. Random roll vs OptionalDropPercent
6. Optionally GiveItemByCbid + FUN_004d2820 place; convoy variant iterates party

## Inventory path (eventType==1)

1. Cargo required
2. `newCount = CountItemsByCbid(CBID)`
3. `delta = newCount - param_6` (decompiler)
4. If `param_5` (item) matches CBID and under need → return 1

## Confidence

| Claim | Level |
|---|---|
| Dual event types kill vs inventory | **High** |
| Uses CountItemsByCbid cargo bridge | **High** |
| Drop percent roll path | **High** |
| Exact param_5/6 ABI labels | **Probable** |

## Open

- Full caller matrix of eventType values beyond 0/1
- Server authority vs client prediction on GiveItem
