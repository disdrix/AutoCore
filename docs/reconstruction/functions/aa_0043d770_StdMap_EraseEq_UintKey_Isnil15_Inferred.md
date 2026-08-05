# Function record (named): StdMap_EraseEq_UintKey_Isnil15_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043d770` |
| **Semantic name** | `StdMap_EraseEq_UintKey_Isnil15_Inferred` |
| **Ghidra name** | `FUN_0043d770` |
| **Address** | `0x0043d770`–`0x0043d7c7` exclusive (**87 B** / `0x57`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | STL / MSVC `_Tree` uint-key map (isnil@+0x15) |
| **Naming basis** | equal_range + count + erase_range; unsigned key@+0x0C; isnil@+0x15; returns erase count — MSVC `map::erase(key)` shape |
| **Status** | Dual sealed W38-O (**accept**) |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

See `aa_0043d770_FUN_0043d770.md`.

## Signature

```c
// EAX=map*; ECX=const uint32_t* key; plain RET; returns count
int StdMap_EraseEq_UintKey_Isnil15_Inferred(void /*EAX*/, void /*ECX*/);
```

## Artifacts

- Raw / annotated / clean / twin / scaffold record / A+B reviews — see dual report W38-O.
