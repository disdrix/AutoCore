# Function record: StdMap_EraseRange_Isnil2d_DestroyStr0C_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00407f90` |
| **Canonical name** | `StdMap_EraseRange_Isnil2d_DestroyStr0C_Inferred` |
| **Ghidra name** | `FUN_00407f90` |
| **Address** | `0x00407f90`–`0x00408042` exclusive (**178 B** / `0xB2`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC std::_Tree range erase (isnil@+0x2d, DestroyStr0C / StringKey) |
| **Completion status** | **Dual sealed** 2026-08-05 WQ9K-B OWN |
| **Bit-for-bit / runtime / diff** | Open (Terminal false; no Launcher) |

## Purpose

Full-clear / partial **range erase** parent for the **isnil@+0x2d** free-subtree string family. Sole external full-clear caller of dualed free-subtree `0x00409970`; partial caller of dualed StringKey erase `0x004094c0`.

## Signature

```c
// EDI = map*; stack out/first/last; RET 0x0c
Node** StdMap_EraseRange_Isnil2d_DestroyStr0C_Inferred(
    /*EDI*/ Map* map, Node** outIt, Node* first, Node* last);
```

## Naming evidence

| Evidence | Present? |
|---|---|
| Full-clear free-subtree of dualed isnil2d DestroyStr0C | **Yes** |
| isnil@+0x2d immediates in body | **Yes** |
| Partial dualed StringKey erase+rebalance | **Yes** |
| Product/PDB English | **No** → `_Inferred` |

## Artifacts

- FUN record: `docs/reconstruction/functions/aa_00407f90_FUN_00407f90.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdMap_EraseRange_Isnil2d_DestroyStr0C_Inferred.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00407f90_StdMap_EraseRange_Isnil2d_DestroyStr0C_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00407f90_StdMap_EraseRange_Isnil2d_DestroyStr0C_Inferred.md`
- Report: `docs/agents/task-dual-ab-00407b70-00407f90-wq9kb-report.md`
