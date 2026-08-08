# Function record: Map_EraseRange_C

| Field | Value |
|---|---|
| **Stable ID** | `aa_00407d70` |
| **Canonical name** | `Map_EraseRange_C` |
| **Ghidra name** | `FUN_00407d70` |
| **Address** | `0x00407d70`–`0x00407e24` exclusive (**180 B** / `0xB4`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC std::_Tree range erase (isnil@+0x29) |
| **Completion status** | **Dual sealed** 2026-08-04 WQ9H-F OWN |
| **Bit-for-bit / runtime / diff** | Open (Terminal false; no Launcher) |

## Purpose

MSVC-style **map/set erase([first, last))**. Full-range fast path is the free-subtree full-clear caller of dualed `StdTree_FreeSubtree_Isnil29_Inferred` (`0x00406c00`); partial path uses dualed `Map_EraseNode_B` (`0x00409220`). Structural third isnil29 twin of dualed `Map_EraseRange` / `Map_EraseRange_B`.

## Signature

```c
// __thiscall; RET 0x0c
Node** __thiscall Map_EraseRange_C(
    Map* map, Node** outIt, Node* first, Node* last);
```

## Sealed facts

| Fact | Evidence |
|---|---|
| Body 180 B; `ret 0x0c` | `read_memory` + assembly context |
| Full clear: first==*head && last==head | decomp ≡ bytes |
| Free via `00406c00(head->parent)` + head/size reset | rel call + stores |
| Partial successor isnil@+0x29 + `Map_EraseNode_B` | immediates + call |
| Callers: map tidy/dtor full-range | 3 callers |

## Callers / callees

| Direction | Targets |
|---|---|
| Callers (3) | `FUN_00405350`, `FUN_00406010`, `FUN_004d98f0` |
| Callees | `StdTree_FreeSubtree_Isnil29_Inferred` (`0x00406c00`), `Map_EraseNode_B` (`0x00409220`) |

## Related

| Unit | Relation |
|---|---|
| `Map_EraseRange` `0x0051c7c0` | isnil29 twin A |
| `Map_EraseRange_B` `0x0051d880` | isnil29 twin B |
| `Map_EraseNode_B` `0x00409220` | partial erase |
| `StdTree_FreeSubtree_Isnil29_Inferred` `0x00406c00` | full-clear free |

## Artifacts

- Raw (+ re-verify): `docs/reconstruction/raw/aa_00407d70_FUN_00407d70.md`
- Annotated: `docs/reconstruction/raw/aa_00407d70_FUN_00407d70.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Map_EraseRange_C.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00407d70.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00407d70_Map_EraseRange_C.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00407d70_Map_EraseRange_C.md`
- Report: `docs/agents/task-dual-ab-00407d70-00406560-wq9hf-report.md`

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / isnil29 | **High** |
| Structural name | **High** |
| Product demangle | Open |
| Runtime | Open |