# Function record: IgnoreList_FindEntryByTfid_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00573a90` |
| **Canonical name** | `IgnoreList_FindEntryByTfid_Inferred` (**Inferred** structural + caller English) |
| **Ghidra symbol** | `FUN_00573a90` |
| **Address** | `0x00573a90`–`0x00573ae7` exclusive (**87 B** / `0x57`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Body** | linear vector scan + TFID pair @ entry+8/+0xc + dual `RET 0x8` |
| **System** | social / ignore list |
| **Agent** | R12-025 OWN-ONLY dual 2026-08-05 (dual start 2646) |
| **Completion status** | Dual sealed (A/B **accept-with-gaps**) |
| **Terminal** | **false** |

## Purpose

MSVC-style **pointer-vector linear find** for the ignore-list table hosted at offsets **+0x38 / +0x3c**. Each element is an entry pointer; the TFID pair lives at **entry+0x08 / entry+0x0c** and is compared with exact int equality. First match wins; empty begin or full miss returns **null**.

Role sealed by:

1. Remove-from-ignore residual `FUN_0080eeb0` — hit + name@+0x10 → *"has been removed from your ignore list"*.
2. Trade request residual `FUN_0080a170` — hit → auto-refuse sector path.
3. Convoy invite residual `FUN_0080fa50` — hit → auto-decline packet `0x8006`.
4. Dualed `Client_RecvBroadcast` — float-text bubble suppressed when speaker TFID is listed.
5. Dualed ignore-menu twin `UI_InteractionMenu_AddIgnoreToggle` uses name-key sibling on same vector (`FUN_00573af0`).

## Signature

```c
// __thiscall; RET 0x8; EAX = entry* | 0
void* IgnoreList_FindEntryByTfid_Inferred(void* listHost, int tfid_lo, int tfid_hi);
```

## Layout

| Offset | Field |
|---|---|
| host+0x38 | vector begin (`entry**`) |
| host+0x3c | vector end (`entry**`) |
| entry+0x08 | TFID lo (compare key) |
| entry+0x0c | TFID hi (compare key) |
| entry+0x10 | name C-string (caller-consumed; remove-ignore English) |

## Call graph

| Role | Target |
|---|---|
| **Caller** | `FUN_0080eeb0` remove-from-ignore @ `0x0080eee1` |
| **Caller** | `FUN_0080a170` trade residual @ `0x0080a2ac` |
| **Caller** | `FUN_0080fa50` convoy invite @ `0x0080fabb` |
| **Caller** | `Client_RecvBroadcast` @ `0x00810ceb` |
| **Caller** | `FUN_005740f0` insert-if-missing @ `0x00574101` |
| Callee | (none — leaf) |
| Sibling name-key (same vector) | `NameTable_FindEntryByNameI_Inferred` `0x00573af0` |
| Sibling friends name | `FriendsList_FindEntryByNameI_Inferred` `0x00573a30` (+0x8 / name@+0x1a) |
| Sibling friends TFID | `FUN_005739d0` (+0x8 / TFID@+8/+0xc) — do not merge |

## Evidence summary

- Live decompile ≡ raw CF; epilogue **`RET 0x8`** via `read_memory` (`C2 08 00`).
- Disasm seals thiscall ECX host, stack TFID lo/hi, entry keys +8/+0xc.
- Five xrefs; all ignore-list / social-filter related.
- Partition parent `0x00573a30` is dualed friends name find (same multi-list host family).

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/IgnoreList_FindEntryByTfid_Inferred.cpp`
- Scaffold twin: `docs/reconstruction/reconstructed-exact/FUN_00573a90.cpp`
- Raw: `docs/reconstruction/raw/aa_00573a90_FUN_00573a90.md`
- Annotated: `docs/reconstruction/raw/aa_00573a90_FUN_00573a90.annotated.md`
- Review A: `docs/reconstruction/reviews/A_aa_00573a90_IgnoreList_FindEntryByTfid_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00573a90_IgnoreList_FindEntryByTfid_Inferred.md`
- Ghidra FUN record: `docs/reconstruction/functions/aa_00573a90_FUN_00573a90.md`
- Report: `docs/agents/task-dual-ab-00573a90-r12-report.md`

## Gaps

1. Product/PDB demangle for ignore-list host and entry.
2. Full entry packing beyond TFID@+8/+0xc and name@+0x10.
3. Runtime / bit-exact / differential.
