# Function record: FriendsList_FindEntryByNameI_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00573a30` |
| **Canonical name** | `FriendsList_FindEntryByNameI_Inferred` (**Inferred** structural + caller English) |
| **Ghidra symbol** | `FUN_00573a30` |
| **Address** | `0x00573a30`–`0x00573a8b` exclusive (**91 B** / `0x5B`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Body** | linear vector scan + `_stricmp` @ entry+0x1a + dual `RET 0x4` |
| **System** | social / friends list |
| **Agent** | R11-005 OWN-ONLY dual 2026-08-05 |
| **Completion status** | Dual sealed (A/B **accept-with-gaps**) |
| **Terminal** | **false** |

## Purpose

MSVC-style **pointer-vector linear find** for the friends-list table hosted at offsets **+0x8 / +0xc**. Each element is an entry pointer; the display/login name lives at **entry+0x1a** and is compared with CRT **`_stricmp`** (case-insensitive). First match wins; empty begin or full miss returns **null**.

Role sealed by:

1. Dualed `UI_InteractionMenu_AddFriendsToggle` membership gate on `DAT_00d1da2c`.
2. `/friend` residual `FUN_0094d900` — hit string *"That person is already on your friends list."*
3. Interaction-menu button `0x1117a` Remove-from-Friends path in `FUN_00830010`.

## Signature

```c
// __thiscall; RET 0x4; EAX = entry* | 0
void* FriendsList_FindEntryByNameI_Inferred(void* listHost, char* name);
```

## Layout

| Offset | Field |
|---|---|
| host+0x08 | vector begin (`entry**`) |
| host+0x0c | vector end (`entry**`) |
| entry+0x08 | TFID lo (caller-consumed; Remove path) |
| entry+0x0c | TFID hi (caller-consumed) |
| entry+0x1a | name C-string (compare key) |

## Call graph

| Role | Target |
|---|---|
| **Caller** | `FUN_0082f9a0` `UI_InteractionMenu_AddFriendsToggle` @ `0x0082f9de` |
| **Caller** | `FUN_0094d900` `/friend` residual @ `0x0094d9d5` |
| **Caller** | `FUN_00830010` case `0x1117a` @ `0x008304fe` |
| Callee | `_stricmp` via IAT `0x009c6678` |
| Sibling (do not merge) | `NameTable_FindEntryByNameI_Inferred` `0x00573af0` (+0x38 / name@+0x10) |
| Neighbor | `FUN_00573a90` TFID scan on +0x38 vector |

## Evidence summary

- Live decompile ≡ raw CF; epilogue **`RET 0x4`** via `read_memory` (`C2 04 00`).
- Disasm seals thiscall ECX host, stack name, IAT `_stricmp`, name key +0x1a.
- Three xrefs; all friends-list related.
- Partition parent `0x0082f9a0` is dualed friends toggle (score parent + live caller).

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/FriendsList_FindEntryByNameI_Inferred.cpp`
- Scaffold twin: `docs/reconstruction/reconstructed-exact/FUN_00573a30.cpp`
- Raw: `docs/reconstruction/raw/aa_00573a30_FUN_00573a30.md`
- Annotated: `docs/reconstruction/raw/aa_00573a30_FUN_00573a30.annotated.md`
- Review A: `docs/reconstruction/reviews/A_aa_00573a30_FriendsList_FindEntryByNameI_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00573a30_FriendsList_FindEntryByNameI_Inferred.md`
- Ghidra FUN record: `docs/reconstruction/functions/aa_00573a30_FUN_00573a30.md`
- Report: `docs/agents/task-dual-ab-00573a30-r11-report.md`

## Gaps

1. Product/PDB demangle for friends-list host and entry.
2. Full entry packing before +0x1a.
3. Runtime / bit-exact / differential.
