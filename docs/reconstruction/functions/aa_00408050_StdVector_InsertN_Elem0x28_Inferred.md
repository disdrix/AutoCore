# Function record: StdVector_InsertN_Elem0x28_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00408050` |
| **Canonical name** | `StdVector_InsertN_Elem0x28_Inferred` |
| **Ghidra name** | `FUN_00408050` |
| **Address** | `0x00408050`–`0x004082ed` exclusive (**669 B** / `0x29D`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | util / container (`std::vector` InsertN, POD **elem 0x28**) |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual A/B** | `A_aa_00408050_StdVector_InsertN_Elem0x28_Inferred.md`, `B_aa_00408050_StdVector_InsertN_Elem0x28_Inferred.md` |
| **Last reviewed** | `2026-08-04` (WQ9H-A OWN-ONLY) |

## Alias

- `FUN_00408050`

## Purpose

Generic MSVC **vector::insert(n)** instantiation for **0x28-byte POD**. Not skill/tree domain logic. Sole listed caller is InsertOne wrapper `00406de0` (count=1), but ABI accepts arbitrary `count`.

## Signature (sealed)

```c
void __fastcall StdVector_InsertN_Elem0x28_Inferred(
    /*ECX*/ VecPod28 *self,
    /*EDX*/ const Pod28 *value,
    /*stack*/ Pod28 *where,
    /*stack*/ unsigned count); // ret 8
```

## Layout

| Offset | Field |
|---|---|
| `+4` | begin |
| `+8` | end |
| `+0xC` | capEnd |
| elem | 0x28 (10 dwords) |

## Related

| Role | VA |
|---|---|
| InsertOne+rebind | `0x00406de0` |
| UfillN | `0x00406e50` |
| ConstructN 0x28 | `0x00409d40` |
| Twin InsertN 0xC | `0x004082f0` |
| Twin InsertN dword | `0x004073a0` |

## Artifacts

- See FUN twin record + agent report `docs/agents/task-dual-ab-004085e0-00408050-wq9ha-report.md`
