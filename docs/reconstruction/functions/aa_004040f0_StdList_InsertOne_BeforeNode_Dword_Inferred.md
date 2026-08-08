# Function record: StdList_InsertOne_BeforeNode_Dword_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004040f0` |
| **Canonical name** | `StdList_InsertOne_BeforeNode_Dword_Inferred` |
| **Ghidra name** | `FUN_004040f0` |
| **Address** | `0x004040f0`–`0x00404122` inclusive (**51 B** / `0x33`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | shared MSVC `std::list` (partition: missions-progression nested) |
| **Dual verdict** | **accept-with-gaps** (A+B R10-005) |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

- Ghidra: `FUN_004040f0`
- Retired: `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_DebugListMi_004040f0`

## Purpose

```text
node = BuyNode(where, where->prev, val*)   // 0xC: Next/Prev/dword
_Incsize(list, 1)                          // may throw "list<T> too long"
where->prev = node
node->prev->next = node
```

Used by InsertN (`004034c0`) and insert-range (`00404560`). When `where == head` (sentinel), equivalent to push_back twin `00402d10`.

## Signature (sealed)

```c
void __thiscall StdList_InsertOne_BeforeNode_Dword_Inferred(
    StdListHeaderDword *list /*ECX*/,
    StdListNodeDword *where,
    const uint32_t *val);   // RET 0x8
```

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004040f0_FUN_004040f0.md` |
| Annotated | `docs/reconstruction/raw/aa_004040f0_FUN_004040f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdList_InsertOne_BeforeNode_Dword_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_004040f0.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_004040f0_StdList_InsertOne_BeforeNode_Dword_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_004040f0_StdList_InsertOne_BeforeNode_Dword_Inferred.md` |
| FUN record | `docs/reconstruction/functions/aa_004040f0_FUN_004040f0.md` |

## Call graph

```text
Client_DebugListMissionsStatus (0x009572e0)  [among other parents]
  └─ FUN_00402dd0  list resize
       └─ FUN_004034c0  StdList_InsertN_BeforeNode_Dword_Inferred
            └─ FUN_004040f0  StdList_InsertOne_BeforeNode_Dword_Inferred  [THIS]
                 ├─ FUN_00418700  StdList_BuyNode_Dword_Seh
                 └─ FUN_00404840  Incsize ("list<T> too long")

Peer: FUN_00404560  insert-range → same insert-one
Twin: FUN_00402d10  StdList_PushBack_Dword_Inferred  (where = head fixed)
```

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / RET 0x8 | **Confirmed** |
| List insert-one before node | **High** |
| Dword element | **High** |
| CRT demangle spelling | **Inferred** |
| Runtime Confirmed | **Open** |
