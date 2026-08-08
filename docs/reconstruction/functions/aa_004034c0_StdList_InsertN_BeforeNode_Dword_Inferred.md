# Function record: StdList_InsertN_BeforeNode_Dword_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004034c0` |
| **Canonical name** | `StdList_InsertN_BeforeNode_Dword_Inferred` |
| **Ghidra name** | `FUN_004034c0` |
| **Address** | `0x004034c0`–`0x00403522` inclusive (**99 B** / `0x63`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | shared MSVC `std::list` (partition: missions-progression nested) |
| **Dual verdict** | **accept-with-gaps** (A+B MEGA-134) |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

- Ghidra: `FUN_004034c0`
- Retired: `Named_CalleeOf_Named_CalleeOf_Client_DebugListMissionsStatus_004034c0`

## Purpose

```text
for (count; count--; )
  list.insert_before(where, *val);  // dword node 0xC via FUN_004040f0
```

Used by `FUN_00402dd0` resize grow: insert `(target - size)` copies before sentinel head.

## Signature (sealed)

```c
void StdList_InsertN_BeforeNode_Dword_Inferred(
    const uint32_t *val /*ECX*/,
    StdListDword *list,
    ListNodeDword *where,
    uint32_t count);   // RET 0xC
```

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004034c0_FUN_004034c0.md` |
| Annotated | `docs/reconstruction/raw/aa_004034c0_FUN_004034c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdList_InsertN_BeforeNode_Dword_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_004034c0.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_004034c0_StdList_InsertN_BeforeNode_Dword_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_004034c0_StdList_InsertN_BeforeNode_Dword_Inferred.md` |
| FUN record | `docs/reconstruction/functions/aa_004034c0_FUN_004034c0.md` |

## Call graph

```text
Client_DebugListMissionsStatus (0x009572e0)  [among other parents]
  └─ FUN_00402dd0  list resize
       └─ FUN_004034c0  StdList_InsertN_BeforeNode_Dword_Inferred  [THIS]
            └─ FUN_004040f0  insert one before
                 ├─ FUN_00418700  BuyNode 0xC
                 └─ FUN_00404840  Incsize ("list<T> too long")
```

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / RET 0xC | **Confirmed** |
| List insert-N before node | **High** |
| Dword element | **High** |
| CRT demangle spelling | **Inferred** |
| Runtime Confirmed | **Open** |
