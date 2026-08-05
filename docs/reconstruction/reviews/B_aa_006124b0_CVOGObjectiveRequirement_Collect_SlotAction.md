# Review B (skeptical): `aa_006124b0` Collect_SlotAction

| Field | Value |
|---|---|
| **Stable ID** | `aa_006124b0` |
| **VA** | `0x006124b0` |
| **Canonical name** | `CVOGObjectiveRequirement_Collect_SlotAction` |
| **Review date** | `2026-07-29` (dual residual refresh same day) |
| **Reviewer role** | Skeptical counter-review |
| **Counterpart** | `reviews/A_aa_006124b0_CVOGObjectiveRequirement_Collect_SlotAction.md` |
| **Verdict** | **accept-with-gaps** |

## Challenges

| Challenge | Outcome |
|---|---|
| Is this Collect or Deliver? | **Collect.** Vtable entry `009e12dc` under `PTR_FUN_009e12c4` (Collect ctor type code **2**). Deliver is type **3** / vtable `009e0f24` (separate). **Sealed.** |
| Could UI use packet floats like UseItem? | **No for this unit.** Body calls CountItemsByCbid; no load of stack1/objState slot floats. Contrasts UseItem_SlotAction. **High** |
| Is display cap inventing progress? | **No.** `display = min(count, NumToCollect)` feeds sprintf only; does not write mission state. **High** |
| Does GrabResponse call this directly? | **Not shown.** DATA-only vtable xref; invokers are virtual UI/journal paths. Inventory mutates cargo; next SlotAction/Eval sees new count. **High** (static) |
| Original name proven? | **No.** `_Inferred` via class RTTI + role; registry notes original unknown. |
| Character is only `unaff_retaddr` garbage? | **Rejected.** Asm loads **stack0** into EBP after `PUSH EBP`; decompiler SEH residue mislabeled it. **Sealed High** |
| Decompiler 3-arg signature vs RET? | **Asm wins** — **`RET 0x10`** four stack formals; stack1 unread family formal (UseItem uses it). **High** |
| Double Count call invents re-entrancy? | **Real** image calls @ `0x0061255e` / `0x0061257b`; second only when count &lt; need. **High** |
| Broken items inflate UI count? | **No** — both Count sites pass includeBroken=0; bit19=Broken sealed on Count residual. **High** |
| Locker / non-cargo inventory? | SlotAction hardcodes `char+0x250→+0x2b0` cargo only. **High** |

## Residual disposition

| Prior gap | Disposition |
|-----------|-------------|
| Character `unaff_retaddr` | **Sealed High** = stack0 |
| Stack ABI / RET size | **Sealed High** `RET 0x10` |
| Double Count | **Sealed High** (real) |
| Format string VAs | **Sealed High** |
| Progress authority vs 0x2071 / UseItem | **Sealed** dual-path model |
| Runtime | Still open |

## Evidence accepted

- Live cargo recount for Collect UI text — **High**
- Cross-link to inventory type-1 grid — **High**
- Server still owns 0x2071 absolute progress — **High** (not contradicted)
- Shared SlotAction four-stack ABI with UseItem — **High**

## Residual risk

Wrong character pointer still zeros the string path (null gates). Does not affect CountItemsByCbid math itself. Name-blob English field open; does not affect count/format control flow.

**Verdict:** **accept-with-gaps**

---

## Cross-check 2026-07-29

Challenge "is character unaff garbage?" — **Rejected**: stack0 load. Challenge "UseItem-style floats?" — **Rejected**: cargo only. Challenge "double Count artifact?" — **Rejected**: two CALL sites.
