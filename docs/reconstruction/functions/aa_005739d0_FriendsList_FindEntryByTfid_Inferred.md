# Function record: FriendsList_FindEntryByTfid_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005739d0` |
| **Canonical name** | `FriendsList_FindEntryByTfid_Inferred` (**Inferred** structural + caller English) |
| **Ghidra symbol** | `FUN_005739d0` |
| **Address** | `0x005739d0`–`0x00573a28` exclusive (**88 B** / `0x58`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Body** | linear vector scan + dual int CMP @ entry+8/+0xc + dual `RET 0x8` |
| **System** | social / friends list |
| **Agent** | R13-039 OWN-ONLY dual 2026-08-05 (dual start 2686) |
| **Completion status** | Dual sealed (A/B **accept-with-gaps**) |
| **Terminal** | **false** |

## Purpose

MSVC-style **pointer-vector linear find** for the friends-list table hosted at offsets **+0x8 / +0xc**. Each element is an entry pointer; the TFID pair lives at **entry+0x08 / entry+0x0c** and is compared with exact integer equality. First match wins; empty begin or full miss returns **null**.

Role sealed by:

1. Presence residual `FUN_0080f3b0` — hit path English **"Your friend"**; name display via **entry+0x1a**; enemy branch uses `FUN_00573b50` + **"Your enemy"**.
2. Insert-if-missing residuals `FUN_00574020` / `FUN_00574270` — miss → `FUN_005746e0`.
3. Same host vector family as dualed `FriendsList_FindEntryByNameI_Inferred` (`0x00573a30`, name@+0x1a).

## Signature

```c
// __thiscall; RET 0x8; EAX = entry* | 0
void* FriendsList_FindEntryByTfid_Inferred(void* listHost, int tfid_lo, int tfid_hi);
```

## Layout

| Offset | Field |
|---|---|
| host+0x08 | vector begin (`entry**`) |
| host+0x0c | vector end (`entry**`) |
| entry+0x08 | TFID lo (compare key) |
| entry+0x0c | TFID hi (compare key) |
| entry+0x1a | name C-string (caller-consumed; not compared here) |

## Call graph

| Role | Target |
|---|---|
| **Caller** | `FUN_0080f3b0` presence residual @ `0x0080f3f5` |
| **Caller** | `FUN_00574020` insert-if-missing @ `0x00574031` |
| **Caller** | `FUN_00574270` insert-if-missing twin @ `0x00574281` |
| Callee | **none** (leaf) |
| Sibling (do not merge) | `FriendsList_FindEntryByNameI_Inferred` `0x00573a30` (+0x8 / name@+0x1a) |
| Sibling (do not merge) | `IgnoreList_FindEntryByTfid_Inferred` `0x00573a90` (+0x38 / TFID) — partition parent |
| Sibling (do not merge) | `NameTable_FindEntryByNameI_Inferred` `0x00573af0` (+0x38 / name@+0x10) |

## Evidence summary

- Live decompile ≡ raw CF; epilogue **`RET 0x8`** via `read_memory` (`C2 08 00` dual).
- Disasm seals thiscall ECX host, stack TFID lo/hi, vector +0x8/+0xc, keys +8/+0xc.
- Three xrefs; all friends-list related (presence + insert helpers).
- Partition parent `0x00573a90` is dualed ignore TFID twin (score parent; different vector).

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/FriendsList_FindEntryByTfid_Inferred.cpp`
- Scaffold twin: `docs/reconstruction/reconstructed-exact/FUN_005739d0.cpp`
- Raw: `docs/reconstruction/raw/aa_005739d0_FUN_005739d0.md`
- Annotated: `docs/reconstruction/raw/aa_005739d0_FUN_005739d0.annotated.md`
- Review A: `docs/reconstruction/reviews/A_aa_005739d0_FriendsList_FindEntryByTfid_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_005739d0_FriendsList_FindEntryByTfid_Inferred.md`
- Ghidra FUN record: `docs/reconstruction/functions/aa_005739d0_FUN_005739d0.md`
- Report: `docs/agents/task-dual-ab-005739d0-r13-report.md`

## Gaps

1. Product/PDB demangle for friends-list host and entry.
2. Full entry packing beyond TFID and name@+0x1a.
3. Runtime / bit-exact / differential.
