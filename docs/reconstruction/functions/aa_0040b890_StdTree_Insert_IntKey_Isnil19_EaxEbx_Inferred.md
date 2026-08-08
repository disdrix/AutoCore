# Function record: StdTree_Insert_IntKey_Isnil19_EaxEbx_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040b890` |
| **Canonical name** | `StdTree_Insert_IntKey_Isnil19_EaxEbx_Inferred` (**Inferred** structural) |
| **Ghidra symbol** | `FUN_0040b890` |
| **Address** | `0x0040b890` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Body** | `0x0040b890`–`0x0040b8eb` inclusive (**92 B** / `0x5C`); pad `CC` @ `0x0040b8ec` |
| **System** | MSVC tree always-insert (inventory-transfer residual partition host) |
| **Parent dual** | `0x0092b2a0` MissionTracker_FillTrackedTargetSlots_Inferred (R12-008) |
| **Agent** | R13-019 OWN-ONLY dual 2026-08-05 |
| **Dual start** | 2686 |
| **Completion status** | Dual sealed (A/B **accept-with-gaps**) |
| **Terminal** | **false** |

## Purpose

MSVC-style **always-insert** for trees with **color @ +0x18** / **isnil @ +0x19** (node size **0x1C**). Signed **int32** key at value dword0 / node **+0x0C**. Walks root with goLeft flag, then insert+RB via residual `FUN_0040bcd0`. Out pair **always** `{new it, inserted=1}` — **not** insert-or-find.

Host context (not product name of this helper): `MissionTracker_FillTrackedTargetSlots_Inferred` uses it against a **stack temp map** while ranking secondary multi-targets.

## Signature

```c
// EAX = map; EBX = value*; stack = out; RET 4; returns out
InsertPair_Isnil19 *StdTree_Insert_IntKey_Isnil19_EaxEbx_Inferred(
    MapShell_Isnil19 *map,             // EAX
    InsertPair_Isnil19 *out,           // { Node* it; bool inserted; }
    const Val_IntKey_Isnil19 *value);  // key @ +0 (EBX)
```

## Layout / constants

| Item | Value |
|---|---|
| Key | signed int32 @ node+0x0C |
| isnil / color | +0x19 / +0x18 |
| Node size | `0x1C` (`operator_new` in `FUN_0040c060`) |
| Compare | signed (`SETL`) |
| ABI | EAX map, EBX value*, stack out, RET 4 |
| Inserted flag | **always 1** |

## Call graph

| Role | Target |
|---|---|
| **Caller (1)** | `MissionTracker_FillTrackedTargetSlots_Inferred` `0x0092b2a0` @ `0x0092b4fc` |
| Insert+RB | `FUN_0040bcd0` (unOWN; buy `0040c060`, Lrot `0040b910`, Rrot `00446b10`) |
| Family peers (parent callees) | construct `0040b3b0`; erase `0040b440`; erase-range `0040bc10` (R13-017/018/020) |

## Evidence summary

- Live decompile ≡ raw CF; RET 4 + SETL + isnil@+0x19 sealed via `disassemble_function` + `read_memory`.
- Call-site EAX/EBX sealed via `get_assembly_context` + bytes @ `0x0092b4c0`.
- Always-insert sealed: no equal path; `MOV BYTE PTR [EBP+4],1` unconditional.
- Partition system inventory-transfer ≠ inventory product role for this leaf.

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/StdTree_Insert_IntKey_Isnil19_EaxEbx_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0040b890.cpp`
- Raw: `docs/reconstruction/raw/aa_0040b890_FUN_0040b890.md`
- Annotated: `docs/reconstruction/raw/aa_0040b890_FUN_0040b890.annotated.md`
- Review A: `docs/reconstruction/reviews/A_aa_0040b890_StdTree_Insert_IntKey_Isnil19_EaxEbx_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_0040b890_StdTree_Insert_IntKey_Isnil19_EaxEbx_Inferred.md`
- FUN record: `docs/reconstruction/functions/aa_0040b890_FUN_0040b890.md`
- Report: `docs/agents/task-dual-ab-0040b890-r13-report.md`

## Gaps

1. Product English for host temp-map T in MissionTracker ranking.
2. Dual seal of insert `0040bcd0` / buynode `0040c060` / ctor `0040c210`.
3. Runtime / bit-exact / differential.
