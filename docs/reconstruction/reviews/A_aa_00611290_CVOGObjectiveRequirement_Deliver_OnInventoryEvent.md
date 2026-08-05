# Review A: `aa_00611290` Deliver OnInventoryEvent

| Field | Value |
|---|---|
| **Review date** | `2026-07-29` (dual residual refresh same day) |
| **Verdict** | **accept-with-gaps** |
| **Stable ID** | `aa_00611290` |
| **Address** | `0x00611290` |
| **Canonical name** | `CVOGObjectiveRequirement_Deliver_OnInventoryEvent_Inferred` |

## Inspected

- Ghidra decompile `0x00611290` (residual re-check; body ≡ frozen raw)
- Sibling Deliver ctor `0x00610bc0` (type code **3**, default `+0x23=1`)
- Sibling Deliver CargoReady `0x00610f20` (same qty / `+0x23` predicate)
- Vtable `PTR_FUN_009e0f24` (`read_memory`): slot **+0x04** = `0x00611290`; CargoReady at **+0x38**
- Count helper `0x005711c0` (includeBroken=0); dual residual `a_005711c0.md`
- `g_flOne` @ `0x00a0f2a0` = IEEE `1.0f` (`00 00 80 3f`)
- Clean `CVOGObjectiveRequirement_Deliver_OnInventoryEvent.cpp`
- Chain note: `CHAIN_2026-07-29_inventory_collect.md` (Deliver ≠ Collect)

## Confirmed

| Claim | Confidence | Evidence |
|---|---|---|
| **Not Collect** — this is Deliver OnInventoryEvent | **High** | Deliver ctor type **3** + vtable `009e0f24+0x04`; Collect Eval is `0x00611940` (type 2). **UF-014** / prior “Collect type-4” mislabel rejected |
| Only runs when `param_4 == 4` (inventory **event type** 4) | **High** | outer `if (param_4 == 4)` only entry |
| Cargo grid non-null gate: `char+0x250` → vehicle `+0x2b0` | **High** | null short-circuit before Count |
| Count via `InventoryGrid_CountItemsByCbid` CBID=`req+0x10`, includeBroken=`0` | **High** | call site; ECX = cargo grid (decomp flattens `this`) |
| Event id match: `(int)param_5 == *(req+0x18)` | **High** | AND arm before progress write |
| **Qty gate:** `*(req+0x14) <= count` **OR** `*(char*)(req+0x23) == 0` | **High** | raw CF; same predicate as CargoReady |
| **`+0x23` polarity:** **0 = bypass quantity**; non-zero (default **1**) = enforce `need ≤ count` | **High** | `== '\0'` OR-bypass; ctor `0x00610bc0` stores `+0x23 = 1` |
| Progress write: `progressSlots[*(u8*)(req+8)+1] = (int)g_flOne` (float 1.0 bits) | **High** | store + `g_flOne` constant |
| Optional toast when `*(char*)(req+0x22) != 0` → `CVOGReaction_BuildTextParams` | **High** | char COID + object TFID pack + `-1` fillers |
| Return `1` on armed progress; else `0` | **High** | dual exit |
| Class family Deliver (type 3); name stays `_Inferred` | **Probable** (role) / **High** (not Collect) | ctor type + vtable family; original PDB unknown |

## Residual sealed this pass

| Prior gap | Disposition |
|-----------|-------------|
| Flag `+0x23` “skip-count” meaning open | **Sealed High** as **require-count / enforce-qty**: default **1** (enforce); **`==0` bypasses** qty only (id match + event type + cargo still required). **Not** “skip when set”. |
| Could still be Collect? | **Sealed High Rejected** — Deliver type 3 / distinct vtable (UF-014) |
| Polarity match CargoReady | **Sealed High** — identical OR form at `0x00610f20` |

## Gaps (remaining)

- Original PDB / C++ symbol (keep `_Inferred`)
- Inventory **event type 4** enum name / full event-type map
- XML / asset field name for `+0x23` (behavioral role sealed; source name open)
- Exact semantic of `param_5` / `req+0x18` pair beyond int equality (event item vs deliver-target id)
- Identity of toast `param_8` object beyond TFID loads
- Runtime / bit-exact / image diff (policy)

## UF-014 (caller-label note only — CountItems dual not rewritten here)

Prior residual text on **CountItems** dual A once labeled caller `0x00611290` as “Collect type-4”. Correct label for **this** unit:

- **Deliver** requirement class (**req type 3**, ctor `0x00610bc0`)
- Method role: **OnInventoryEvent** when **event type 4** (`param_4==4`)
- **Not** Collect; Collect inventory Eval remains `0x00611940`

CountItems dual ownership stays with `aa_005711c0` (do not rewrite that dual here). Cross-ref only.

**Verdict:** **accept-with-gaps** — dual residual **`+0x23 ==0` qty bypass** sealed; Deliver identity sealed; remaining gaps are enum/name/runtime only.
