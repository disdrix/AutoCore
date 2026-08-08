# Function record: StdTree_EraseRange_Isnil11_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00441960` |
| **Canonical name** | `StdTree_EraseRange_Isnil11_Inferred` |
| **Ghidra symbol** | `FUN_00441960` |
| **Address** | `0x00441960`–`0x00441a11` inclusive (**178 B** / `0xB2`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities — STL tree range erase (isnil@+0x11) |
| **Dual** | MEGA-136 OWN-ONLY 2026-08-05 — **accept-with-gaps** |
| **Terminal** | **false** (no runtime Confirmed) |

## Naming gate

| Evidence | Present? |
|---|---|
| Full-clear + partial range erase CF | **Yes** |
| isnil@+0x11 successor immediates | **Yes** |
| Free callee dualed isnil11 | **Yes** (`0x00440d20`) |
| Shell@+0xA4 consumer (gfxUIWindow) | **Yes** (context; not product method) |
| Product / PDB demangle of map T | **No** → `_Inferred` |

**Decision:** promote **`StdTree_EraseRange_Isnil11_Inferred`**. Partition alias `StdTree_EraseAll_ShellA4`. Retire `Named_CalleeOf_Named_gfxUIWindow_00441960`.

## Signature

```c
// EDI = MapShell*; three stack args; RET 0xC; EAX = outIt*
Node **StdTree_EraseRange_Isnil11_Inferred(
    MapShell *map /*EDI*/,
    Node **outIt,
    Node *first,
    Node *last);
```

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00441960_FUN_00441960.md` |
| Annotated | `docs/reconstruction/raw/aa_00441960_FUN_00441960.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_EraseRange_Isnil11_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00441960.cpp` |
| FUN record | `docs/reconstruction/functions/aa_00441960_FUN_00441960.md` |
| Review A | `docs/reconstruction/reviews/A_aa_00441960_StdTree_EraseRange_Isnil11_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00441960_StdTree_EraseRange_Isnil11_Inferred.md` |
| Report | `docs/agents/task-dual-ab-00441960-mega-136-report.md` |

## Gaps

1. Product demangle of map key/value type.
2. Dual of single-erase `FUN_004477a0`.
3. Runtime / bit-exact / differential.
