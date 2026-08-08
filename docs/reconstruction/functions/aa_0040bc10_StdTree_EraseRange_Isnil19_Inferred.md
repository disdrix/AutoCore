# Function record: StdTree_EraseRange_Isnil19_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040bc10` |
| **Canonical name** | `StdTree_EraseRange_Isnil19_Inferred` |
| **Ghidra name** | `FUN_0040bc10` |
| **Address** | `0x0040bc10`–`0x0040bcc2` exclusive (**178 B** / `0xB2`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC std::_Tree range erase (isnil@+0x19 / Val12 family) |
| **Partition** | R13-020 inventory-transfer (parent `0x0092b2a0`) |
| **Completion status** | **Dual sealed** 2026-08-05 R13-020 OWN |
| **Bit-for-bit / runtime / diff** | Open (Terminal false; no Launcher) |

## Purpose

Full-clear / partial **range erase** parent for the **isnil@+0x19** free-subtree + erase family used under inventory-transfer residual parent `FUN_0092b2a0` and local tidy wrappers. Sole dualed unit of this EDI-map clone; free `0040c100` and erase `0040b440` remain residual.

## Signature

```c
// EDI = map*; stack out/first/last; RET 0x0C
Node** StdTree_EraseRange_Isnil19_Inferred(
    /*EDI*/ MapShell* map, Node** outIt, Node* first, Node* last);
```

## Naming evidence

| Evidence | Present? |
|---|---|
| Full-clear free-subtree of isnil19 residual `0040c100` | **Yes** |
| Partial inline successor isnil@+0x19 + erase `0040b440` | **Yes** |
| Distinct from ECX Val12 peer `0040d700` | **Yes** |
| Product/PDB English | **No** → `_Inferred` |

## Artifacts

- FUN record: `docs/reconstruction/functions/aa_0040bc10_FUN_0040bc10.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_EraseRange_Isnil19_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_0040bc10.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_0040bc10_StdTree_EraseRange_Isnil19_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0040bc10_StdTree_EraseRange_Isnil19_Inferred.md`
- Report: `docs/agents/task-dual-ab-0040bc10-r13-report.md`

## Confidence

| Claim | Level |
|---|---|
| Role / CF / ABI | **High** |
| isnil19 family | **High** |
| Product demangle | **Low** |
| Runtime | **Open** |
