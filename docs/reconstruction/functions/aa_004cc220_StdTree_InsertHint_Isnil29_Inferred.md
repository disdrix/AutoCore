# Function record: StdTree_InsertHint_Isnil29_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cc220` |
| **Canonical name** | `StdTree_InsertHint_Isnil29_Inferred` |
| **Ghidra name** | `FUN_004cc220` |
| **Address** | `0x004cc220`–`0x004cc3c4` (**421 B** / `0x1A5`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `skills-abilities` (STL map insert-hint residual) |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual A/B** | `A_aa_004cc220_StdTree_InsertHint_Isnil29_Inferred.md`, `B_aa_004cc220_StdTree_InsertHint_Isnil29_Inferred.md` |
| **Last reviewed** | `2026-08-04` (WQ9F-E OWN-ONLY) |

## Alias

- `FUN_004cc220`
- `Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_004cc220` (scaffold; reject)

## Purpose

MSVC map unique insert-with-hint for isnil@+0x29 nodes with 2-dword ordered key. Local attachment via always-insert rebalance; fallback insert-or-find.

## Signature (sealed)

```c
Node** __thiscall StdTree_InsertHint_Isnil29_Inferred(
    Map* map, Node** outIt, Node* hint, const void* value);
// RET 0x0c
```

## Algorithm

1. If size==0: InsertAndRebalance(out, addLeft=1, head, value).
2. If hint==leftmost and value < hint: Insert left of hint.
3. If hint==head and rightmost < value: Insert right of rightmost.
4. If value < hint: Prevnode; if pred < value < hint: open-side Insert.
5. If hint < value: Nextnode; if hint < value < succ: open-side Insert.
6. Else InsertOrFind; `*outIt = node`.

## Related

- `aa_004cbb60` `StdTree_InsertAndRebalance_Isnil29_Inferred` (always-insert callee)
- `aa_0053a8e0` `StdTree_InsertHint_Val12` (peer CF, isnil@+0x19)
- `FUN_004cbee0` insert-or-find fallback (WQ9F-D residual)
- `FUN_004cc400` sole external caller

## Artifacts

- Raw / annotated / clean / dual A/B — see FUN twin record + agent report
