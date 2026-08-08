# Function record: StdList_Resize_EsiList_EaxCount_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00402dd0` |
| **Canonical name** | `StdList_Resize_EsiList_EaxCount_Inferred` |
| **Ghidra name** | `FUN_00402dd0` |
| **Address** | `0x00402dd0` |
| **Body** | `0x00402dd0`–`0x00402e1f` inclusive (**80 B** / `0x50`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | shared `client::stdlist` resize (missions-progression nested consumers) |
| **Agent** | MEGA-127 OWN-ONLY dual 2026-08-05 |
| **Completion status** | Dual sealed (A/B **accept-with-gaps**) |
| **Terminal** | **false** |

## Purpose

Resize MSVC circular list shell with **ESI = list\*** / **EAX = new_size** / stack **fill** / **`RET 4`**:

- grow → `FUN_004034c0` insert-N of fill
- shrink → unlink `head->_Prev`, `operator_delete`, `size--`
- equal → return

Used by `Client_DebugListMissionsStatus` and four other sites, typically with **EAX=0** as clear-before-rebuild.

## Signature

```c
// Machine: ESI = list*; EAX = new_size; stack fill; RET 4; void
void StdList_Resize_EsiList_EaxCount_Inferred(void);
// Port form:
void StdList_Resize_EsiList_EaxCount_Inferred(ListShell* list, uint32_t new_size, uint32_t fill);
```

## Layout (list shell)

| Offset | Field |
|---|---|
| +4 | head / sentinel* |
| +8 | size (`_Mysize`) |

## Layout (node)

| Offset | Field |
|---|---|
| +0 | `_Next` |
| +4 | `_Prev` |

## Call graph

| Role | Target |
|---|---|
| Callers | `Client_DebugListMissionsStatus` `0x009572e0`; `FUN_008eca80`; `FUN_00801c50`; `FUN_0080b7f0`; `FUN_008a5c90` (5 xrefs) |
| Callees | `FUN_004034c0` (grow); `operator_delete` |
| Related | insert sibling `FUN_00402d10`; clear-only `StdList_Clear_ESI` `0x00415e90` |

## Evidence summary

- Live decompile ≡ raw CF; assembly seals size-- loop and RET 4 (decompiler false-noreturn).
- Call sites seal ESI list + EAX count + stack fill.
- Product element type open → `_Inferred`.

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/StdList_Resize_EsiList_EaxCount_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00402dd0.cpp`
- Raw: `docs/reconstruction/raw/aa_00402dd0_FUN_00402dd0.md`
- Annotated: `docs/reconstruction/raw/aa_00402dd0_FUN_00402dd0.annotated.md`
- Review A: `docs/reconstruction/reviews/A_aa_00402dd0_StdList_Resize_EsiList_EaxCount_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00402dd0_StdList_Resize_EsiList_EaxCount_Inferred.md`
- Report: `docs/agents/task-dual-ab-00402dd0-mega-127-report.md`
