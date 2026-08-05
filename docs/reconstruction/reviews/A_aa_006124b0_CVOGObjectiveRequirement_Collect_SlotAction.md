# Review A: `aa_006124b0` Collect_SlotAction

| Field | Value |
|---|---|
| **Stable ID** | `aa_006124b0` |
| **VA** | `0x006124b0` |
| **Canonical name** | `CVOGObjectiveRequirement_Collect_SlotAction` |
| **Review date** | `2026-07-29` (dual residual refresh same day) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_006124b0_CVOGObjectiveRequirement_Collect_SlotAction.md` |
| **Verdict** | **accept-with-gaps** (runtime / bit-exact open) |

## Inspected

- Ghidra decompile `0x006124b0` (residual re-check)
- Image body bytes `0x006124b0`–`0x006126c1` (`read_memory`)
- Vtable DATA xref `0x009e12dc` under Collect `PTR_FUN_009e12c4` (+0x18)
- Count helper `0x005711c0` + residual `a_005711c0.md` (Broken / includeBroken)
- Sibling SlotAction ABI: UseItem `0x0060d060` (`RET 0x10`, four stack formals)
- Sibling Collect_Eval residual `a_00611940.md` (same cargo path)
- Format strings `0x009df764` / `0x009e1734` / `0x00a41404`
- Clean `CVOGObjectiveRequirement_Collect_SlotAction.cpp`
- Residual scratch `reviews/a_006124b0.md`

## Confirmed

| Claim | Confidence | Evidence |
|---|---|---|
| Format `"%s: %d / %d"` @ `0x009df764` | **High** | `read_memory` + PUSH imm |
| Count via `0x005711c0` with req+0x10, includeBroken=0 | **High** | `PUSH 0; PUSH [ESI+0x10]; CALL` ×1–2 |
| Count `this` = cargo grid (ECX) | **High** | asm sets ECX=`[vehicle+0x2b0]` before CALL |
| Cap display at NumToCollect (+0x14) | **High** | first count compare; 2nd CALL only if count &lt; need |
| Cargo path char+0x250→+0x2b0 | **High** | EBP null gates |
| Optional Level append +0x58/+0x5c/+0x60 | **High** | body; `"Level"` @ `0x00a41404`; `" %s: %d-%d"` @ `0x009e1734` |
| `RET 0x10` four stack dwords | **High** | epilogue `C2 10 00` |
| stack0 = character (not unaff) | **High** | `MOV EBP,[ESP+0x32c]` |
| stack1 unread (family objState formal) | **High** | no load; UseItem uses stack1 |
| stack2/3 = outBuf / outCap | **High** | strncat args |
| Class is Collect type=2 | **High** | vtable of ctor; RTTI; XML collect family |
| Name SlotAction | **High** role / **Probable** original | same family role as UseItem_SlotAction |
| UI-only (no mission state write) | **High** | no store to req/objState |

## Control flow: clean ≡ raw/asm

| Stage | Match |
|---|---|
| CBID lookup early-out | **Yes** |
| Cargo gate (character stack0) | **Yes** (asm seals character; clean notes residual) |
| min(count, NumToCollect) display | **Yes** |
| sprintf + optional Level + strncat | **Yes** |
| `RET 0x10` | **Yes** (clean signature updated) |

## Gaps (remaining)

- Item name blob exact product type at `item+0x3c+0x92`
- `FUN_00404d70` / `FUN_007a6de0` / lock pair product names
- Runtime journal refresh timing after Grab/Add
- Bit-exact / image diff (policy)
- Original PDB name
- Virtual callers (no static CODE xrefs)

**Verdict:** **accept-with-gaps** — dual residual **ABI**, **character=stack0**, **double-count**, **format VAs**, **Count ECX**, and **UseItem contrast** sealed; only verification/runtime remain.
