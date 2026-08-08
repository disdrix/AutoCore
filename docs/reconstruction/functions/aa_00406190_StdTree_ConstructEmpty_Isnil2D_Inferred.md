# Function record: StdTree_ConstructEmpty_Isnil2D_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00406190` |
| **Canonical name** | `StdTree_ConstructEmpty_Isnil2D_Inferred` (**Inferred** structural) |
| **Ghidra symbol** | `FUN_00406190` |
| **Address** | `0x00406190` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Body** | `0x00406190`–`0x004061e9` inclusive (**90 B** / `0x5A`) |
| **System** | MSVC `std::_Tree` empty construct |
| **Agent** | WQ9K-D OWN-ONLY dual 2026-08-05 |
| **Completion status** | Dual sealed (A/B accept-with-gaps) |
| **Terminal** | **false** |

## Purpose

Construct an **empty** tree/map shell for the **isnil@+0x2d / node 0x30** family: call dualed buyhead, install as `_Myhead`, set head isnil=1, self-link L/P/R, zero `_Mysize`. Sole live caller is host ctor `FUN_00404e40` subobject at `this+0x0C`.

## Signature

```c
TreeShellIsnil2D* __stdcall StdTree_ConstructEmpty_Isnil2D_Inferred(TreeShellIsnil2D* shell);
// RET 0x4; EAX = shell*
```

## Shell layout (this unit writes)

| Offset | Field | Init |
|---|---|---|
| +0x00 | (allocator/comp) | untouched |
| +0x04 | `_Myhead` | buyhead result |
| +0x08 | `_Mysize` | **0** |

Head (via buyhead + this unit):

| Offset | Field | Init |
|---|---|---|
| +0x00/+0x04/+0x08 | L/P/R | **self** |
| +0x2c | color | black (from buyhead) |
| +0x2d | isnil | **1** (this unit) |

## Call graph

| Role | Target |
|---|---|
| **Caller (1)** | `FUN_00404e40` @ `0x00404e76` |
| Head buy | `StdTree_BuyHeadNode_Isnil2D_Inferred` (`0x00409780`) |
| Contrast | isnil31 empty `0x00405f20`; isnil29 BuyHead `0x00408a30` — do not merge |

## Evidence summary

- Live decompile ≡ raw CF; epilogue `ADD ESP,0xC; RET 0x4` via `read_memory` / disasm.
- isnil@+0x2d force-1 + self-link + size0 sealed in disasm.
- Family sealed by dualed buyhead WQ9J-G.
- Product map English open → `_Inferred`.

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/StdTree_ConstructEmpty_Isnil2D_Inferred.cpp`
- Scaffold twin: `docs/reconstruction/reconstructed-exact/FUN_00406190.cpp`
- Raw: `docs/reconstruction/raw/aa_00406190_FUN_00406190.md`
- Annotated: `docs/reconstruction/raw/aa_00406190_FUN_00406190.annotated.md`
- Review A: `docs/reconstruction/reviews/A_aa_00406190_StdTree_ConstructEmpty_Isnil2D_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00406190_StdTree_ConstructEmpty_Isnil2D_Inferred.md`
- Report: `docs/agents/task-dual-ab-00406190-00405bd0-wq9kd-report.md`
