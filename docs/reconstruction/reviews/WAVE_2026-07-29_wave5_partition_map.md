# Multi-agent partition map — wave 5 (2026-07-29)

| Field | Value |
|-------|-------|
| Terminal bar | every live Ghidra VA → full / reviewed / trivial-batch / deferred-low |
| Live Ghidra | 25666 |
| Dual pairs start | ~600 |
| Rule | One write owner per VA |

## High-priority duals (named / system)

| VA | Focus |
|----|-------|
| `0x005532e0` | Skill_ValidateTarget_HBSkillListener |
| `0x00512bb0` | SiblingCastClearPredicate |
| `0x00606d70` | Outpost_CastSkillsForFaction |
| `0x006070e0` | Outpost_CastSkillsForBeaconShare |
| `0x00504c70` | throttle / setDrivingInputs |
| `0x00404aa0` | TFID_EqualsObjectId |
| `0x0040b150` | TFID_NotEquals |
| `0x005b0920` | CNDHash_LookupByKey |
| `0x0053c560` | CNDHash_Insert |
| `0x00512830` | EnsureQuestCreditsLookupLoaded |
| `0x00512870` | EnsureQuestBaseCreditsLoaded |
| `0x00512440` | Object_GetRootRaceId |
| `0x005cced0` | AI_CheckSlotTimerReady |
| `0x005d2360` | Map_InsertOrFind_IntKey |
| `0x00825bf0` | UI_QuickBar_CreateSlotButton |
| `0x00611690` | Collect ctor |
| `0x00610bc0` | Deliver ctor |
| `0x00611a00` | Collect helper |
| `0x0059e1c0` | RPC GuaranteedOrdered Method1 |
| `0x005a2a50` | RPC Execute |

## Skills residual duals

| VA | Focus |
|----|-------|
| `0x0051a980` | EnsureLoadedInTree |
| `0x0051d3b0` | QueueDeferred (if thin) |
| `0x00518cf0` | LookupActiveCastBinding residual |
| `0x005083b0` | AttachOwnerObject |
| `0x005081c0` | CVOGHBBase_Start |
| `0x005078f0` | CVOGHBList_Enqueue |
| `0x005082c0` | CVOGHBBase_TryFire |
| `0x00508280` | GetRemainingSeconds |

## Inventory residual duals

| VA | Focus |
|----|-------|
| `0x00513de0` | Broken flag setter |
| `0x0040abf0` | Stack capacity |
| `0x00571830` | Stack qty merge |
| `0x00571b80` | sibling of occupancy |
| `0x00860e20` | Grab residual deepen if needed |

## Missions residual duals

| VA | Focus |
|----|-------|
| `0x00538ea0` | Map insert rebalance |
| `0x00537770` | Map predecessor |
| `0x005380d0` | Node construct 0x50 |
| `0x0052d8b0` | Clear staging tree |
| `0x008aa3f0` | Auto-select reward slot |

## Meta

| Role | Focus |
|------|-------|
| CRT/import trivial-batch | Body-prove ceil/floor/free/strncmp etc. → extend imports ledger |
| thunk_* trivial-batch | Body-prove thin thunks → new thunk ledger |
| Ledger/RESUME restamp | After duals land |
