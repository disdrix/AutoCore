# Function record: StdMap_EraseRange_Isnil131_DestroyStr0C_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00407b70` |
| **Canonical name** | `StdMap_EraseRange_Isnil131_DestroyStr0C_Inferred` |
| **Ghidra name** | `FUN_00407b70` |
| **Address** | `0x00407b70`–`0x00407bea` exclusive (**122 B** / `0x7A`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC std::_Tree range erase (isnil@+0x131, DestroyStr0C) |
| **Completion status** | **Dual sealed** 2026-08-05 WQ9K-B OWN |
| **Bit-for-bit / runtime / diff** | Open (Terminal false; no Launcher) |

## Purpose

Full-clear / partial **range erase** parent for the **isnil@+0x131** free-subtree string family. Sole external caller of dualed free-subtree `0x00409920` on full `[begin,end)`.

## Signature

```c
// ESI = map*; stack out/first/last; RET 0x0c
Node** StdMap_EraseRange_Isnil131_DestroyStr0C_Inferred(
    /*ESI*/ Map* map, Node** outIt, Node* first, Node* last);
```

## Naming evidence

| Evidence | Present? |
|---|---|
| Full-clear free-subtree of dualed isnil131 DestroyStr0C | **Yes** |
| Partial successor + erase with string@+0x0c | **Yes** (via residual callees) |
| Product/PDB English | **No** → `_Inferred` |

## Artifacts

- FUN record: `docs/reconstruction/functions/aa_00407b70_FUN_00407b70.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdMap_EraseRange_Isnil131_DestroyStr0C_Inferred.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00407b70_StdMap_EraseRange_Isnil131_DestroyStr0C_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00407b70_StdMap_EraseRange_Isnil131_DestroyStr0C_Inferred.md`
- Report: `docs/agents/task-dual-ab-00407b70-00407f90-wq9kb-report.md`
