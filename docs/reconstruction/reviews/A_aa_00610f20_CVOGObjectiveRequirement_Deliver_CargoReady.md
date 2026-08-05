# Review A: `aa_00610f20` Deliver CargoReady

| Field | Value |
|---|---|
| **Review date** | `2026-07-29` (dual residual strengthen same day) |
| **Verdict** | **accept-with-gaps** |
| **Stable ID** | `aa_00610f20` |
| **Address** | `0x00610f20` |
| **Canonical name** | `CVOGObjectiveRequirement_Deliver_CargoReady_Inferred` |

## Inspected

- Ghidra `decompile_function` + `read_memory` body `0x00610f20`..`0x00610f61` (live ≡ frozen raw)
- Ghidra `get_xrefs_to` / `get_function_callers` (DATA-only vtable; no static callers)
- Deliver ctor `0x00610bc0` (`read_memory`): type **3**, `+0x23=1` default
- Deliver XML unserialize (`CBIDItem` → `+0x10`; **−1 forces `+0x23=0`**)
- GetFlags dump path (no standalone `+0x23` XML tag)
- Sibling OnInventoryEvent `0x00611290` (same qty OR)
- Count helper dual `a_005711c0.md` (includeBroken=0)
- Clean `CVOGObjectiveRequirement_Deliver_CargoReady.cpp` (notes vehicle-null modernization)
- Residual scratch: `reviews/a_00610f20.md`

## Confirmed

| Claim | Confidence | Evidence |
|---|---|---|
| Pure predicate — no side effects | **High** | returns AL 0/1 only; no progress/toast/mutates |
| Match key: `*(req+0x18) == matchKey` | **High** | first gate; stack0 |
| Cargo grid required: `*( *(char+0x250) + 0x2b0 ) != 0` | **High** | TEST ECX / JE fail; **no** host-null check on `+0x250` |
| Count via `InventoryGrid_CountItemsByCbid` CBID=`+0x10`, includeBroken=`0` | **High** | `PUSH 0; PUSH [ESI+0x10]; CALL 0x005711c0` with ECX=grid |
| Qty: `count >= need(+0x14)` | **High** | `CMP EAX,[ESI+0x14]; JGE ready` |
| **`+0x23` polarity:** **0 = bypass quantity**; non-zero (default **1**) = enforce need | **High** | `CMP byte,0 / JE ready` after short-count; ctor `=1` |
| **`+0x23` authorship:** derived — `CBIDItem == -1` stores **0**; else leave **1** | **High** | unserialize image; not dumped as own tag |
| ABI: `__thiscall` + **RET 8** (matchKey, character) | **High** | both exits `C2 08 00` |
| Virtual slot Deliver vtbl **`+0x38`** | **High** | DATA xref `0x009e0f5c` |
| Deliver family (type 3); method name stays `_Inferred` | **High** (class) / **Probable** (CargoReady label) | ctor + RTTI + pure readiness role |

## Residual sealed this pass

| Prior gap | Disposition |
|-----------|-------------|
| Flag `+0x23` polarity open / thin duals | **Sealed High** as **require-count / enforce-qty** |
| Source of `+0x23` | **Sealed High** — not free XML; set from **CBIDItem == −1** |
| Stack formals / RET | **Sealed High** — two stack args, `RET 8` |
| Identity vs Collect | **Sealed High** — Deliver type 3 / distinct vtable (sibling dual UF-014) |

## Gaps (remaining)

- Original PDB / C++ method symbol (keep `_Inferred`)
- Static virtual dispatch callers of vtbl+0x38 (none in image xrefs)
- Full matchKey domain (NPC CBID vs event id) beyond int equality
- AutoCore server `RequireItemToComplete = (ItemCBID == -1)` appears **inverted** vs client `+0x23` (parity residual; unused in server progress paths today)
- Runtime / bit-exact / image diff (policy)

**Verdict:** **accept-with-gaps** — dual residual **`+0x23` polarity + authorship** sealed; pure CargoReady CF High; remaining gaps name/dispatch/runtime only.
