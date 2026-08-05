# Function record: CVOGCharacter_TryEvalInteractObjectivesNearObject_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00535c60` |
| **Canonical name** | `CVOGCharacter_TryEvalInteractObjectivesNearObject_Inferred` |
| **Ghidra name** | `FUN_00535c60` |
| **Address** | `0x00535c60`–`0x00535ec1` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `missions-progression` |
| **Calling convention** | MSVC `__thiscall` (ECX=character; 1 stack object*; `ret 4`) |
| **Completion status** | **Sealed** — dual A/B W24-K 2026-07-29; range/inventory/type0xC/kind9 High; **static callers open** |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

- `FUN_00535c60`
- `Named_VOG_DEBUG_STOP_00535c60` (legacy scaffold — **misleading**; string is hash lock assert)

## Purpose

If target is inventory-held **or** within **20.0f** adjusted range, walk active hash `@char+0x548` for type-`0xC` evaluators matching the target; on first hit fire `EvaluatePendingObjectives` with context kind **9**.

## Signature

```c
bool __thiscall CVOGCharacter_TryEvalInteractObjectivesNearObject_Inferred(
    void* this /* CVOGCharacter* */,
    void* target_object);
```

## Behavioral summary (sealed)

1. `FindItemByCoid(grid from char+0x250→+0x2b0, object+0x160/164)` — hit skips range.
2. Else distance (player vs object pos − radius) vs `DAT_00aaa6e8` (**20.0f**); too far → false.
3. Lock-traverse `char+0x548`; per def evaluators `[+0x158,+0x15c)`.
4. Type `vtbl+0x50 == 0xC` and match `vtbl+0x40(char, object)`.
5. `EvaluatePendingObjectives(char, 9, (float)clonebase_cbid, 0, 0)` → true.

## Callers / callees

| Direction | Address / name | Role |
|---|---|---|
| Caller | *(none static)* | entry residual — gap |
| Callee | `FUN_00571010` | `InventoryGrid_FindItemByCoid` |
| Callee | `FUN_0053e510` | nested distance |
| Callee | `CVOGCharacter_EvaluatePendingObjectives` | kind **9** |
| Callee | `FUN_007a4480` | HashError / VOG_DEBUG_STOP asserts |

## Confidence by dimension

| Dimension | Level | Rationale |
|---|---|---|
| Function boundary | **High** | body + pad before `0x00535ed0` |
| thiscall / ret 4 | **High** | image epilogue |
| Inventory skip gate | **High** | prologue + sealed FindByCoid |
| 20.0f threshold | **High** | comiss + float bytes |
| Hash `+0x548` walk | **High** | strings + structure |
| Type 0xC + kind 9 | **High** | decompile + `push 9` |
| Static callers | **Open** | no CODE/DATA xrefs |
| Product name | **Probable** | inferred role |
| Overall static CF | **High** | dual W24-K |

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_00535c60_FUN_00535c60.md` |
| Annotated | `raw/aa_00535c60_FUN_00535c60.annotated.md` |
| Clean | `reconstructed-exact/CVOGCharacter_TryEvalInteractObjectivesNearObject_Inferred.cpp` |
| Dual A | `reviews/A_aa_00535c60_CVOGCharacter_TryEvalInteractObjectivesNearObject_Inferred.md` |
| Dual B | `reviews/B_aa_00535c60_CVOGCharacter_TryEvalInteractObjectivesNearObject_Inferred.md` |
| Kind owner | `A/B_aa_00534920_CVOGCharacter_EvaluatePendingObjectives.md` |

## Open questions

- Who calls this VA (vtable / reaction table / missed data ref).
- Product enum name for objective type `0xC` and context kind `9`.
- Whether `g_nInferredThreatDefault` plate English matches interact-range product name (value sealed 20.0f).
