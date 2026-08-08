# Function record: StdTree_ConstructEmpty_Isnil31_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00405f20` |
| **Canonical name** | `StdTree_ConstructEmpty_Isnil31_Inferred` (**Inferred** structural) |
| **Ghidra symbol** | `FUN_00405f20` |
| **Address** | `0x00405f20` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Body** | `0x00405f20`–`0x00405f7a` exclusive (**90 B** / `0x5A`) |
| **System** | MSVC `std::_Tree` empty construct |
| **Agent** | WQ9K-C OWN-ONLY dual 2026-08-04 |
| **Completion status** | Dual sealed (A/B accept-with-gaps) |
| **Terminal** | **false** |

## Purpose

Construct an **empty** tree/map shell for the **isnil@+0x31 / node 0x38** family: call dualed buyhead, install as `_Myhead`, set head isnil=1, self-link L/P/R, zero `_Mysize`. Sole live caller is Client constructor subobject init at `client+0xF14` (`param_1+0x3c5`).

## Signature

```c
TreeShellIsnil31* __stdcall StdTree_ConstructEmpty_Isnil31_Inferred(TreeShellIsnil31* shell);
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
| +0x30 | color | black (from buyhead) |
| +0x31 | isnil | **1** (this unit) |

## Call graph

| Role | Target |
|---|---|
| **Caller (1)** | `FUN_009495c0` (Client ctor) @ `0x00949d37` |
| Head buy | `StdTree_BuyHeadNode_Isnil31_Size0x38_Inferred` (`0x00409180`) |
| Contrast | isnil29 head wrappers; do not merge node size families |

## Evidence summary

- Live decompile ≡ raw CF; epilogue `ADD ESP,0xC; RET 0x4` via `read_memory`.
- isnil@+0x31 force-1 + self-link + size0 sealed in disasm.
- Reject Client-constructor chain-of-caller scaffold as product English.
- Family sealed by dualed buyhead WQ9J-F.

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/StdTree_ConstructEmpty_Isnil31_Inferred.cpp`
- Scaffold twin: `docs/reconstruction/reconstructed-exact/FUN_00405f20.cpp`
- Raw: `docs/reconstruction/raw/aa_00405f20_FUN_00405f20.md`
- Annotated: `docs/reconstruction/raw/aa_00405f20_FUN_00405f20.annotated.md`
- Review A: `docs/reconstruction/reviews/A_aa_00405f20_StdTree_ConstructEmpty_Isnil31_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00405f20_StdTree_ConstructEmpty_Isnil31_Inferred.md`
- Report: `docs/agents/task-dual-ab-00404180-00405f20-wq9kc-report.md`
