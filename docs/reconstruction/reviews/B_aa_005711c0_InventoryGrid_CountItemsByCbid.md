# Review B (skeptical): `aa_005711c0` InventoryGrid_CountItemsByCbid

| Field | Value |
|---|---|
| **Review date** | `2026-07-29` (residual refresh same day; UF-014 caller label fix) |
| **Verdict** | **accept-with-gaps** |

## Challenges

| Challenge | Outcome |
|---|---|
| Is `this` definitely InventoryGrid? | **High** from callers using cargo `+0x2b0` and CS at +0x30 matching unlock path |
| Does collect always use param_3=0? | Collect_Eval / SlotAction / Deliver OnInventoryEvent / Deliver CargoReady / Collect_Action inventory arm pass `0` — **High**. Counterexample: `FUN_00502590` passes `1` (include broken) — so the flag is real, not dead |
| Is bit 19 “quest/mission” rather than Broken? | **Falsified.** Independent strings `"Broken: "` (loot log + UI) and texture `i_g_2d_overlay_broken.dds` bind bit 19 to broken state. Stack-merge + equip code-9 are consistent with “broken items are special / non-mergeable” |
| Name invents "CountItemsByCbid"? | Reconstructed; original unknown — documented |
| Could count wrong inventory (locker)? | Collect_Eval hardcodes vehicle cargo; locker not used in Eval |
| Are `FUN_004294f0` / `FUN_004022a0` inventively named? | Roles sealed by `"List Error! TraversalLock..."` + list-node walk; full PDB names still unknown — accept role names only |
| Grid+0x2c list embed? | **Probable** from CS/flag delta only; not required for CountItems CF seal |
| Is `0x00611290` Collect type-4? | **Falsified (UF-014).** Prior dual A mislabel. Chain + Deliver duals: **Deliver** req type **3**, OnInventoryEvent when event type **4** (`param_4==4`). Collect_Eval remains `0x00611940` (Collect type 2). Name stays `CVOGObjectiveRequirement_Deliver_OnInventoryEvent_Inferred` — do not invent Collect alias |

## Residual disposition

| Prior gap | Disposition |
|-----------|-------------|
| Flag bit19 semantics | **Sealed High** → Broken / `ItemFlag_Broken` |
| Enumerator helper names | **Sealed High** as TraversalLock / IterateNext roles |
| Caller `0x00611290` “Collect type-4” label | **Sealed High** → Deliver OnInventoryEvent (req type 3 / event type 4); CX-004 closed |
| Runtime | Still open |

**Verdict:** **accept-with-gaps**
