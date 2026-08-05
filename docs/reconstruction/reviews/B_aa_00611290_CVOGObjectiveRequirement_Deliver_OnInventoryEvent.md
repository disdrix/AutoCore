# Review B (skeptical): `aa_00611290` Deliver OnInventoryEvent

| Field | Value |
|---|---|
| **Review date** | `2026-07-29` (dual residual refresh same day) |
| **Verdict** | **accept-with-gaps** |
| **Stable ID** | `aa_00611290` |
| **Address** | `0x00611290` |

## Challenges

| Challenge | Outcome |
|---|---|
| Could this still be Collect (type-4 mislabel)? | **Rejected High.** Collect type-2 Eval is `0x00611940` / vtable `009e12c4`. This body sits at Deliver vtable `009e0f24+0x04`; ctor `0x00610bc0` writes type **`3`**. “Collect type-4” confuses **req type** with **inventory event type**. **UF-014 sealed.** |
| Is `param_4==4` a requirement type? | **No High.** Req type is `req+0x0c` / ctor slot (3 for Deliver). `param_4` is the inventory **event** discriminator; body ignores all other event values. |
| Flag `+0x23` means “skip when set”? | **Falsified High.** Raw is `(need ≤ count) \|\| (*(char*)(req+0x23) == 0)`. **Zero bypasses** qty; non-zero enforces. Ctor default **`+0x23 = 1`** → enforce on normal Deliver instances. Same OR as CargoReady `0x00610f20`. |
| Does `+0x23==0` skip the whole event? | **No High.** Bypass is **qty only**. Still requires event type 4, cargo grid non-null, and `(int)param_5 == req+0x18`. |
| Does Count include Broken stacks? | **No High.** Call passes includeBroken **0**; Count residual seals bit19=Broken omitted. |
| Progress absolute vs fraction? | **Absolute 1.0 High** on success — writes `(int)g_flOne` to slot, not count/need ratio (contrast Collect_Eval). |
| Name proven Deliver_OnInventoryEvent? | **Probable** family/role from type 3 + inventory-event vslot + cargo turn-in pattern. Original symbol **unknown** — keep `_Inferred`. Do not invent. |
| Toast path required for success? | **No High.** Progress write + `return 1` happen whether or not `+0x22` toast runs. |
| Static CODE callers? | **None expected High** — only DATA xref from vtable `009e0f28` (slot +0x04). Virtual dispatch. |

## Residual disposition

| Prior gap (B draft) | Disposition |
|---------------------|-------------|
| Flag `+0x23` skip-count meaning open | **Sealed High** — require-count / enforce-qty; **`==0` bypass** |
| eventType 4 identity | **Still open** as enum label; CF gate sealed |
| Deliver vs Collect identity | **Sealed High** Deliver |
| Runtime / bit-exact | Still open |

## Cross-check vs CargoReady (`0x00610f20`)

| Aspect | OnInventoryEvent | CargoReady |
|--------|------------------|------------|
| Qty / `+0x23` | `(need≤count) \|\| (+0x23==0)` | **identical** |
| Id match | event `(int)param_5` vs `req+0x18` | `param_2` vs `req+0x18` |
| Event type gate | `param_4==4` | none (predicate helper) |
| Progress write | slot ← 1.0 | returns 1 only |
| Vtable | `+0x04` | `+0x38` |

Polarity agreement **High** — independent sibling confirms `+0x23==0` is qty bypass, not “flag set skips.”

## UF-014 note (this dual only)

Do **not** re-own or rewrite `aa_005711c0` dual files. If any CountItems caller table still says “Collect type-4 @ 0x00611290”, correct label is:

**Deliver OnInventoryEvent** — **req type 3** / **event type 4**.

**Verdict:** **accept-with-gaps** — skeptical challenges on Collect mislabel and `+0x23` polarity **closed**; enum name + original symbol + runtime remain.
