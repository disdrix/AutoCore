# Function record: StdTree_ConstructEmpty_Isnil19_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040b3b0` |
| **Canonical name** | `StdTree_ConstructEmpty_Isnil19_Inferred` (**Inferred** structural) |
| **Ghidra symbol** | `FUN_0040b3b0` |
| **Address** | `0x0040b3b0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Body** | `0x0040b3b0`–`0x0040b40a` exclusive (**90 B** / `0x5A`) |
| **System** | MSVC `std::_Tree` empty construct (partition: inventory-transfer) |
| **Agent** | R13-017 OWN-ONLY dual 2026-08-05 |
| **Parent dual** | `0x0092b2a0` MissionTracker_FillTrackedTargetSlots_Inferred (R12-008) |
| **Dual start** | 2686 |
| **Completion status** | Dual sealed (A/B accept-with-gaps) |
| **Terminal** | **false** |

## Purpose

Construct an **empty** tree/map shell for the **isnil@+0x19 / node 0x1c** family: call residual buyhead `FUN_0040bfc0`, install as `_Myhead`, set head isnil=1, self-link L/P/R, zero `_Mysize`. Sole live caller is MissionTracker secondary fill at a **stack-local** shell (`LEA … [ESP+0x38]`).

## Signature

```c
TreeShellIsnil19* __stdcall StdTree_ConstructEmpty_Isnil19_Inferred(TreeShellIsnil19* shell);
// RET 0x4; EAX = shell*
```

## Shell layout (this unit writes)

| Offset | Field | Init |
|---|---|---|
| +0x00 | (allocator/comp) | untouched |
| +0x04 | `_Myhead` | buyhead result |
| +0x08 | `_Mysize` | **0** |

Head (via buyhead residual + this unit):

| Offset | Field | Init |
|---|---|---|
| +0x00/+0x04/+0x08 | L/P/R | **self** |
| +0x18 | color | black (from residual buyhead) |
| +0x19 | isnil | **1** (this unit) |
| size | node | **0x1c** |

## Call graph

| Role | Target |
|---|---|
| **Caller (1)** | `MissionTracker_FillTrackedTargetSlots_Inferred` (`0x0092b2a0`) @ `0x0092b319` |
| Head buy | residual `FUN_0040bfc0` (`operator_new(0x1c)`) — **not dualled R13-017** |
| Contrast | ConstructEmpty isnil31 `00405f20`; isnil2d `00406190`; BuyHead isnil29/31/2d peers |

## Evidence summary

- Live decompile ≡ raw CF; epilogue `ADD ESP,0xC; RET 0x4` via `read_memory`.
- isnil@+0x19 force-1 + self-link + size0 sealed in disasm.
- Reject MissionTracker product English as unit name; reject thiscall; reject isnil29/31 merge.
- Family sealed by residual buyhead size 0x1c + isnil offset.

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/StdTree_ConstructEmpty_Isnil19_Inferred.cpp`
- Scaffold twin: `docs/reconstruction/reconstructed-exact/FUN_0040b3b0.cpp`
- Raw: `docs/reconstruction/raw/aa_0040b3b0_FUN_0040b3b0.md`
- Annotated: `docs/reconstruction/raw/aa_0040b3b0_FUN_0040b3b0.annotated.md`
- Review A: `docs/reconstruction/reviews/A_aa_0040b3b0_StdTree_ConstructEmpty_Isnil19_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_0040b3b0_StdTree_ConstructEmpty_Isnil19_Inferred.md`
- Report: `docs/agents/task-dual-ab-0040b3b0-r13-report.md`
