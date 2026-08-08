# Function record: IgnoreList_EraseEntriesByTfid_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00573ce0` |
| **Canonical name** | `IgnoreList_EraseEntriesByTfid_Inferred` (**Inferred** structural + sole-caller English) |
| **Ghidra symbol** | `FUN_00573ce0` |
| **Address** | `0x00573ce0`–`0x00573d4c` exclusive (**108 B** / `0x6c`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Body** | linear vector erase-all-by-TFID + delete + memmove compact + end−4 + dual-pad `CC` |
| **System** | social / ignore list |
| **Agent** | R13-040 OWN-ONLY dual 2026-08-05 (dual start **2686**) |
| **Parent dual** | `IgnoreList_FindEntryByTfid_Inferred` `0x00573a90` (R12-025) |
| **Completion status** | Dual sealed (A/B **accept-with-gaps**) |
| **Terminal** | **false** |

## Purpose

MSVC-style **pointer-vector linear erase** for the ignore-list table hosted at offsets **+0x38 / +0x3c**. Each element is an entry pointer; the TFID pair at **entry+0x08 / entry+0x0c** is compared with exact int equality. On match the heap entry is `operator_delete`d, the slot is zeroed, the tail is `memmove`d down, and **end** shrinks by one pointer. Cursor is **not** advanced after erase (re-scan slid-in element) so **all** matching TFID entries are removed in one call. Always returns **0**.

Role sealed by sole caller:

1. Remove-from-ignore residual `FUN_0080eeb0` — after dualed find `FUN_00573a90` + English *"has been removed from your ignore list"*, mutates the table via this unit, then refreshes `CDlgTabsSocial`.

## Signature

```c
// __thiscall; RET 0x10; EAX = 0 always
// unused1/unused2 are stack-cleaned but unread by the body
int IgnoreList_EraseEntriesByTfid_Inferred(
    void* listHost,
    int unused1, int unused2,
    int tfid_lo, int tfid_hi);
```

## Layout

| Offset | Field |
|---|---|
| host+0x38 | vector begin (`entry**`) |
| host+0x3c | vector end (`entry**`) |
| entry+0x08 | TFID lo (erase key) |
| entry+0x0c | TFID hi (erase key) |
| entry heap | freed on match via `operator_delete` |

## Call graph

| Role | Target |
|---|---|
| **Caller** | `FUN_0080eeb0` remove-from-ignore @ `0x0080ef7c` (only xref) |
| Callee | `operator_delete` @ `0x00489822` (cdecl) |
| Callee | `memmove` via IAT `DAT_009c652c` |
| Parent find (same vector) | `IgnoreList_FindEntryByTfid_Inferred` `0x00573a90` |
| Sibling erase plate | `FUN_00573d50` (+0x28/+0x2c) — do not merge |
| Sibling friends TFID find | `FUN_005739d0` (+0x8) — do not merge |

## Evidence summary

- Live decompile ≡ raw CF; epilogue **`RET 0x10`** via `read_memory` (`C2 10 00`).
- Disasm seals thiscall ECX host, four stack dwords, TFID keys on args 3–4, multi-erase without cursor advance.
- Ghidra false-noreturn on `operator_delete` falsified (`ADD ESP,4` continues).
- One UNCONDITIONAL_CALL from remove-ignore residual.
- Partition system tag `skills-abilities` is residual nest only; live role is **UI/social ignore list**.

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/IgnoreList_EraseEntriesByTfid_Inferred.cpp`
- Scaffold twin: `docs/reconstruction/reconstructed-exact/FUN_00573ce0.cpp`
- Raw: `docs/reconstruction/raw/aa_00573ce0_FUN_00573ce0.md`
- Annotated: `docs/reconstruction/raw/aa_00573ce0_FUN_00573ce0.annotated.md`
- Review A: `docs/reconstruction/reviews/A_aa_00573ce0_IgnoreList_EraseEntriesByTfid_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00573ce0_IgnoreList_EraseEntriesByTfid_Inferred.md`
- Ghidra FUN record: `docs/reconstruction/functions/aa_00573ce0_FUN_00573ce0.md`
- Report: `docs/agents/task-dual-ab-00573ce0-r13-report.md`

## Gaps

1. Product/PDB demangle for ignore-list host and entry.
2. Semantic reason for unused stack arg1/arg2 (caller still passes them).
3. Full entry packing beyond TFID@+8/+0xc (name@+0x10 known from find sibling).
4. Runtime / bit-exact / differential.
