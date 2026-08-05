# Chain seal: Inventory ↔ Mission collect progress (2026-07-29)

| Field | Value |
|---|---|
| Systems | inventory-transfer + missions-progression |
| Status | **Sealed (static)** — runtime open |
| Residual closed | "inventory collect progress cross-links" from missions next-work |

## End-to-end (client)

```
Collect requirement def
  ctor 0x00611690  type code = 2, vtable PTR_FUN_009e12c4
  XML  0x00611a00  CBID→+0x10, NumToCollect→+0x14, OptionalDropPercent→+0x48, …
  RTTI ".?AVCVOGObjectiveRequirement_Collect@@"

Inventory mutates cargo grid (grab/drop/add place)
  DropResponse type 1 → character+0x250 → vehicle+0x2b0  (InventoryGrid)

Live Collect progress (no exclusive reliance on 0x2071 slot float):
  count = InventoryGrid_CountItemsByCbid(cargo, CBID, 0)   @ 0x005711c0
  fraction = min(1, count / NumToCollect)                  @ 0x00611940 Collect_Eval
  UI text  = "<name>: have / need"                         @ 0x006124b0 Collect_SlotAction
             have = min(count, NumToCollect)

Optional Collect Action 0x00611f20 (vtable +0x04):
  event type 1: inventory-ish notify — match CBID + count-param6 < NumToCollect
  event type 0 path: kill-to-loot OptionalDropPercent + GiveItemByCbid (not inventory recount)
```

## Why this is the cross-link

| Inventory side | Mission side |
|----------------|--------------|
| Cargo grid place/grab/drop mutates cells | Collect_Eval / SlotAction re-count by CBID |
| `InventoryGrid_CountItemsByCbid` walks objects | NumToCollect gates fraction + UI |
| DropResponse type 1 → `char+0x250+0x2b0` | Collect units use **same** cargo pointer |

Server still authorizes absolute `0x2071` progress and turn-in (`MissionCollectProgress` on AutoCore). Client Collect_Eval/SlotAction are **inventory-derived** (matches `docs/missionHandler.md` §5.5: client Collect_Eval uses inventory; pickup sync can lag).

## Contrast: UseItem

| | Collect | UseItem |
|--|---------|---------|
| Eval | Live cargo count / NumToCollect | Slot float ≥ RepeatCount |
| SlotAction | Live cargo count in `"%s: %d / %d"` | Slot float in `"%s: %i / %i"` |
| Inventory bridge | **Direct** | Indirect (uses item, not cargo count) |

## Related but NOT Collect: Deliver type 3

| Unit | VA | Note |
|------|-----|------|
| Deliver ctor | `0x00610bc0` | type code **3**, vtable `PTR_FUN_009e0f24` |
| `FUN_00611290` | `0x00611290` | Deliver vtable +0x04; **param_4==4** inventory event; also calls CountItemsByCbid |
| `FUN_00610f20` | `0x00610f20` | Deliver cargo readiness check |

Earlier draft mislabeled `0x00611290` as Collect type-4 — **corrected**: that is **Deliver**.

## Units sealed this chain

| Stable ID | Name | VA | Duals |
|-----------|------|-----|-------|
| aa_005711c0 | `InventoryGrid_CountItemsByCbid` | `0x005711c0` | A/B + residual `a_005711c0.md` (Broken bit19 sealed) |
| aa_00611940 | `CVOGObjectiveRequirement_Collect_Eval` | `0x00611940` | A/B |
| aa_006124b0 | `CVOGObjectiveRequirement_Collect_SlotAction` | `0x006124b0` | A/B |

Supporting (documented, not all dual-refined this pass):

| Stable ID | Name | VA |
|-----------|------|-----|
| aa_00611690 | Collect_ctor (type 2) | `0x00611690` |
| aa_00611a00 | Collect_DeserializeXml / SerializeXml family | `0x00611a00` |
| aa_00611f20 | Collect_Action (drop + inventory event) | `0x00611f20` |

## Confidence

| Claim | Level |
|---|---|
| Count walks grid objects by CBID | **High** |
| Collect_Eval uses cargo + count/NumToCollect | **High** |
| Collect_SlotAction live count UI | **High** |
| Same cargo grid as inventory type 1 | **High** |
| Class name Collect from RTTI/XML/type=2 | **High** |
| Count param_3=0 excludes **Broken** bit19 (`item+0x17c`) | **High** — dual residual `a_005711c0.md` |
| Pickup auto-fires Eval without UI tick | **Open** |
| Live GrabResponse → journal string timing | **Open** |

## Not claimed

- Full loot drop `OptionalDropPercent` client path sealed end-to-end
- QuestItemPickup `0x205D`
- Server `MissionCollectProgress` (see `docs/missionHandler.md`; out of client RE scope)
- Deliver dual reviews (related inventory consumer; separate work)

## Ghidra evidence (2026-07-29)

- Program: `autoassault.exe` image base `0x400000`
- Decompile: `0x005711c0`, `0x00611940`, `0x006124b0`, `0x00611690`, `0x00611a00`, `0x00611f20`, `0x00610bc0`
- Strings: `Requirement type="collect"`, `NumToCollect`, collect lacking-child error, RTTI Collect
- Vtable xrefs: Collect Eval/SlotAction DATA-only (virtual)

## Collect_Action + Deliver (2026-07-29 follow-up)

| Stable | VA | Role |
|--------|-----|------|
| aa_00611f20 | 0x00611f20 | Collect_Action kill-loot / inventory event |
| aa_00611290 | 0x00611290 | Deliver_OnInventoryEvent_Inferred (type 4) |
| aa_00610f20 | 0x00610f20 | Deliver_CargoReady_Inferred |

Duals: A/B under reviews for each. Cargo count bridge via aa_005711c0.
