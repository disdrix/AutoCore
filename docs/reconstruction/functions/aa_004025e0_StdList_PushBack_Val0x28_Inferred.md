# Function record: StdList_PushBack_Val0x28_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004025e0` |
| **Canonical name** | `StdList_PushBack_Val0x28_Inferred` (**Inferred** — product T English open) |
| **Ghidra name** | `FUN_004025e0` |
| **Prior scaffold** | `Named_CalleeOf_CVOGReaction_TransferMap_004025e0` (**retired**) |
| **Address** | `0x004025e0`–`0x00402611` inclusive last byte (**50 B** / `0x32`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | shared MSVC `std::list` (seed: missions-progression / reaction transfer) |
| **Agent** | MEGA-059 OWN-ONLY dual 2026-08-05 |
| **Completion status** | Dual sealed (A/B **accept-with-gaps**) |
| **Terminal** | **false** |

## Purpose

Classic MSVC **`std::list::push_back`** for element type size **0x28**:

```text
head = list->_Myhead                    // +4
node = Buynode(head, head->_Prev, val)  // FUN_00403560 → new 0x30 + FUN_00404390
_Incsize(1)                             // FUN_00403600; max 0x6666666 = 0xFFFFFFFF/0x28
head->_Prev = node
node->_Prev->_Next = node
```

Insert-before-sentinel ⇒ end insert. Sole known host: `CVOGReaction` list embed at **`+0xe778`**.

## Signature

```c
// __thiscall: ECX = list*; stack const T* (T size 0x28); RET 4; void
void __thiscall StdList_PushBack_Val0x28_Inferred(
    StdListShell_Val0x28 *list,
    const void *value);
```

## Layout

| Offset | Field |
|---|---|
| list+0x04 | `_Myhead` sentinel* |
| list+0x08 | `_Mysize` (via Incsize) |
| node+0x00 | `_Next` |
| node+0x04 | `_Prev` |
| node+0x08..+0x2F | value (**0x28** / 10 dwords) |
| node size | **0x30** |

## Call graph

| Role | Target |
|---|---|
| **Callers (1)** | `CVOGReaction_TransferMap` `0x004d37f0` site `0x004d3893` |
| Callees | `FUN_00403560` buynode; `FUN_00403600` Incsize max 0x6666666 |
| Nested (via buynode) | `operator_new(0x30)`; `FUN_00404390` node ctor |
| Twin pattern | `StdList_PushPayloadNode` (dword T) — same link CF |
| Related Incsize peers | `StdList_Incsize` max 0x3fffffff; `StdList_Incsize_Max1fffffff` |

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/StdList_PushBack_Val0x28_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_004025e0.cpp`
- Raw: `docs/reconstruction/raw/aa_004025e0_FUN_004025e0.md`
- Annotated: `docs/reconstruction/raw/aa_004025e0_FUN_004025e0.annotated.md`
- Review A: `docs/reconstruction/reviews/A_aa_004025e0_StdList_PushBack_Val0x28_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_004025e0_StdList_PushBack_Val0x28_Inferred.md`
- Scaffold FUN record: `docs/reconstruction/functions/aa_004025e0_FUN_004025e0.md`
- Report: `docs/agents/task-dual-ab-004025e0-mega-059-report.md`

## Confidence

| Claim | Level |
|---|---|
| push_back CF | **Confirmed** |
| T=0x28 / node=0x30 / max 0x6666666 | **Confirmed** |
| thiscall + RET 4; ECX=list | **Confirmed** |
| Sole caller + list @ +0xe778 | **Confirmed** |
| Product T / member English | **Open** (`_Inferred`) |
| Runtime / bit-exact | **Open** |
