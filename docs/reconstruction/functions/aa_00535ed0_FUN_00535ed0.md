# Function record: CVOGCharacter_ResolveUseObjectPending_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00535ed0` |
| **Canonical name** | `CVOGCharacter_ResolveUseObjectPending_Inferred` |
| **Ghidra name** | `FUN_00535ed0` |
| **Address** | `0x00535ed0`–`0x0053607e` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `missions-progression` / use-object pending |
| **Calling convention** | MSVC `__thiscall` (ECX=character; 1 stack `char commit`; `ret 4`) |
| **Completion status** | **Sealed** — dual A/B W25-A 2026-07-29; CF/kind10/UI0x14/TFID High; product English **Probable** |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

- `FUN_00535ed0`
- `Named_CalleeOf_Named_CalleeOf_CVOGReaction_RecordFirstTimeEvent_00535ed0` (legacy scaffold — **rejected** as product role)

## Purpose

Resolve and clear the character's **pending use-object** interaction state. On commit with a resolvable TFID, fire `EvaluatePendingObjectives` context kind **10**. On non-commit with secondary flag, either cancel via secondary-object vtbl `+0x2cc` or send logic-UI packet kind **0x14**. Always nulls TFID/flags on the finish path.

## Signature

```c
bool __thiscall CVOGCharacter_ResolveUseObjectPending_Inferred(
    void* this /* CVOGCharacter* */,
    char commit);
```

## Behavioral summary (sealed)

1. Gate: vbase via this-adjust `+0xa8` and `char+0xc7c` must be set.
2. **Invalid TFID** (`(+0xc88 & +0xc8c)==~0` and `+0xc90==0`): if `+0xc9c` set, vtbl`+0x2cc`(commit?1:0) when commit or `+0xc7d`; clear `+0xc9c` / optional `FUN_0060b410` on `+0xca0`.
3. **Valid TFID** + `!commit`: require `+0xc7d`; `Client_SendLogicUiPacket` with kind dword **0x14**.
4. **Valid TFID** + `commit`: `Object_ResolveFromTFID(+0xc88)` → `EvaluatePendingObjectives(kind=10, (float)clonebase+0x34, 0, 0)`.
5. Finish: clear `+0xc7c/+0xc7d`, copy null TFID from `DAT_009cee98`, zero `+0xc9c/+0xca0/+0xc80`.

## Callers / callees

| Direction | Address / name | Role |
|---|---|---|
| Caller | `FUN_005360f0` | countdown tick → commit when `+0xc80` ≤ 0 |
| Caller | `FUN_0060b410` / `FUN_0060b440` | HB/aux fire path commit/clear |
| Caller | `FUN_00515520` | broader character update path |
| Callee | `Object_ResolveFromTFID` | TFID → object* |
| Callee | `CVOGCharacter_EvaluatePendingObjectives` | kind **10** |
| Callee | `Client_SendLogicUiPacket` | UI kind **0x14** |
| Callee | `FUN_0060b410` | clear aux at `+0xca0` |

## Confidence by dimension

| Dimension | Level | Rationale |
|---|---|---|
| Function boundary | **High** | Ghidra body `…607e` + pad before `005360f0` |
| thiscall / ret 4 | **High** | `C2 04 00` epilogue bytes |
| Kind **10** EvaluatePending | **High** | decompile call |
| UI packet **0x14** | **High** | `local_11c = 0x14` |
| Null TFID seed | **High** | `read_memory` `0x009cee98` |
| Flag/slot map `+0xc7c…+0xca0` | **High** | body + countdown caller |
| Product English name | **Probable** | structural `_Inferred` |
| Overall static CF | **High** | dual W25-A |

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_00535ed0_FUN_00535ed0.md` |
| Annotated | `raw/aa_00535ed0_FUN_00535ed0.annotated.md` |
| Clean | `reconstructed-exact/CVOGCharacter_ResolveUseObjectPending_Inferred.cpp` |
| Clean twin | `reconstructed-exact/FUN_00535ed0.cpp` |
| Dual A | `reviews/A_aa_00535ed0_CVOGCharacter_ResolveUseObjectPending_Inferred.md` |
| Dual B | `reviews/B_aa_00535ed0_CVOGCharacter_ResolveUseObjectPending_Inferred.md` |
| Sibling kind 9 | `A/B_aa_00535c60_CVOGCharacter_TryEvalInteractObjectivesNearObject_Inferred.md` |

## Open questions

- Product name for UI packet kind `0x14` and objective context kind `10`.
- Exact secondary-object type behind `+0xc9c` vtbl `+0x2cc`.
- Full `FUN_0060b410` contract (not owned this wave).
