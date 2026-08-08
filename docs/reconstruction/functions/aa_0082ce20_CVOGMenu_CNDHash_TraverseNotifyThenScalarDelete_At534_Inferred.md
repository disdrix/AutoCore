# Function record: CVOGMenu_CNDHash_TraverseNotifyThenScalarDelete_At534_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0082ce20` |
| **Canonical name** | `CVOGMenu_CNDHash_TraverseNotifyThenScalarDelete_At534_Inferred` |
| **Ghidra name** | `FUN_0082ce20` |
| **Address** | `0x0082ce20` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Body** | `0x0082ce20`–`0x0082cf28` exclusive (**264 B** / `0x108`); RET @ `0x0082cf27` |
| **System** | skills-abilities / CVOGMenu owned CNDHash teardown |
| **Agent** | WQ9L-H2 OWN-ONLY dual 2026-08-05 (scaffold WQ9L-H) |
| **Completion status** | Dual sealed (A/B **accept-with-gaps**) |
| **Terminal** | **false** |

## Purpose

Derived member teardown for **CVOGMenu**: if owned CNDHash\* @ **`this+0x534`** non-null, traversal-lock the hash, walk ordered bucket/entry chain (head@+0x14, next@+0x14, entry@+8), for each entry lock nested list@entry+8, notify **menu vtbl[+0xbc]** per value, destroy nested owned chain, unlock hash, **scalar-delete** hash, null slot. Does **not** free CVOGMenu or run `CNDUIDialog` base complete.

## Signature

```c
// ECX = CVOGMenu* this; void; bare RET after SUB ESP,8 frame
void __fastcall CVOGMenu_CNDHash_TraverseNotifyThenScalarDelete_At534_Inferred(void* self);
```

## Layout (fields touched)

| Offset | Field (inferred) |
|---|---|
| this+0x534 | owned CNDHash* (scalar-deleted; nulled) |
| hash+0x1d | TraversalLock byte |
| hash+0x14 | ordered node head |
| node+0x14 | ordered next |
| node+8 | entry* |
| entry+8 | nested locked list shell |
| entry+0xc / list+4 | CRITICAL_SECTION |
| entry+0x30 / list+0x28 | list TraversalLock flag |

## Call graph

| Role | Target |
|---|---|
| **Primary caller** | `CVOGMenu_CompleteDtor` @ `0x0082d540` site `0x0082d56b` |
| Other code caller | `FUN_0082f130` @ `0x0082f168` |
| vtbl exposure | 7 data xrefs |
| Lock nested list | `FUN_004294f0` |
| Iterate values | `FUN_004113b0` (ECX=&iter_state) |
| Destroy nested chain | `FUN_00410d60` |
| Soft log | `FUN_007a4480` |
| Base after parent | `CNDUIDialog_CompleteDtor` @ `0x00792c20` |

## Evidence summary

- Live decompile ≡ raw CF; body/entry/epilogue sealed via `read_memory` (WQ9L-H2).
- Complete parent dual documents this as menu-owned hash teardown callee (RTTI `.?AVCVOGMenu@@`).
- Nested list ECX restored from bytes (`LEA ESI,[entry+8]; MOV ECX,ESI`).
- Iterate ABI restored: ECX=&iter_state (decompiler elided).
- Soft lock errors only (no hard abort). `_Inferred` — product hash stamp / notify English open.

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/CVOGMenu_CNDHash_TraverseNotifyThenScalarDelete_At534_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_0082ce20.cpp`
- Raw: `docs/reconstruction/raw/aa_0082ce20_FUN_0082ce20.md`
- Annotated: `docs/reconstruction/raw/aa_0082ce20_FUN_0082ce20.annotated.md`
- Review A: `docs/reconstruction/reviews/A_aa_0082ce20_CVOGMenu_CNDHash_TraverseNotifyThenScalarDelete_At534_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_0082ce20_CVOGMenu_CNDHash_TraverseNotifyThenScalarDelete_At534_Inferred.md`
- Report: `docs/agents/task-dual-ab-0082ce20-wq9lh2-report.md`
