# Function record: StdTree_InsertHint_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00406560` |
| **Canonical name** | `StdTree_InsertHint_Isnil21_Inferred` |
| **Ghidra name** | `FUN_00406560` |
| **Address** | `0x00406560`–`0x00406705` exclusive (**421 B** / `0x1A5`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC std::_Tree unique insert-with-hint (isnil@+0x21; 2-dword pair key) |
| **Completion status** | **Dual sealed** 2026-08-04 WQ9H-F OWN |
| **Bit-for-bit / runtime / diff** | Open (Terminal false; no Launcher) |

## Purpose

Structural name from sealed CF: **insert-with-hint** for **isnil@+0x21** maps with **pair-key less** via dualed `StdPairKey_Less_HiSignedLoUnsigned_Inferred`. Peer of dualed `StdTree_InsertHint_Isnil29_Inferred` (`0x004cc220`). Product demangle open → `_Inferred`.

## Signature

```c
// __thiscall; RET 0x0c
Node** __thiscall StdTree_InsertHint_Isnil21_Inferred(
    Map* map, Node** outIt, Node* hint, const void* value);
```

## Sealed facts

| Fact | Evidence |
|---|---|
| Body 421 B; frame `SUB ESP,8`; `ADD ESP,8; RET 0x0c` | bytes |
| Empty / begin / end / neighbor / fallback | decomp ≡ assembly context |
| isnil@+0x21 open-side | immediates `0x21` |
| Key less `FUN_00401480` (+ leftmost inline) | 5 call sites + inline path |
| Insert where after pred/succ | bytes override decomp alias |
| Sole caller `FUN_004055c0` → node+0x18 | callers/xrefs |

## Callers / callees

| Direction | Targets |
|---|---|
| Callers (1) | `FUN_004055c0` |
| Callees | always-insert `FUN_00407200`; less `FUN_00401480`; pred `FUN_005adff0`; succ `FUN_004e12c0`; insert-or-find `FUN_00407060` |

## Related

| Unit | Relation |
|---|---|
| `StdTree_InsertHint_Isnil29_Inferred` `0x004cc220` | CF peer (isnil29) |
| `StdPairKey_Less_HiSignedLoUnsigned_Inferred` `0x00401480` | shared less leaf |
| `FUN_00407200` / `FUN_00407060` | insert residual undualed |

## Artifacts

- Raw (+ re-verify): `docs/reconstruction/raw/aa_00406560_FUN_00406560.md`
- Annotated: `docs/reconstruction/raw/aa_00406560_FUN_00406560.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_InsertHint_Isnil21_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00406560.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00406560_StdTree_InsertHint_Isnil21_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00406560_StdTree_InsertHint_Isnil21_Inferred.md`
- Report: `docs/agents/task-dual-ab-00407d70-00406560-wq9hf-report.md`

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / isnil21 / pair-key | **High** |
| Structural name `_Inferred` | **High** (role) |
| Product demangle | Open |
| Runtime | Open |