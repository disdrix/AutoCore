# Function record: StdList_Clear_ESI

| Field | Value |
|---|---|
| **Stable ID** | `aa_00415e90` |
| **Canonical name** | `StdList_Clear_ESI` |
| **Ghidra name** | `FUN_00415e90` |
| **Address** | `0x00415e90` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Body** | `0x00415e90`–`0x00415ec6` exclusive (**54 B** / `0x36`) |
| **System** | shared `client::stdlist` |
| **Agent** | WQ9L-H OWN-ONLY dual 2026-08-05 |
| **Completion status** | Dual sealed (A/B accept-with-gaps) |
| **Terminal** | **false** |

## Purpose

Clear MSVC circular list shell with **ESI = list\*** ABI: re-ring sentinel, zero size, free all element nodes via `operator_delete`. Sentinel retained for parent destroy paths (e.g. `CNDUIDialog_CompleteDtor` frees head at `this+0x4e0` after clear of `this+0x4dc`).

## Signature

```c
// Machine: ESI = list* (+4 head, +8 size); bare RET; void
void StdList_Clear_ESI(void);
// Port form:
void StdList_Clear_ESI(StdListShell* list);
```

## Layout (list shell)

| Offset | Field |
|---|---|
| +4 | head / sentinel* |
| +8 | size (`_Mysize`) |

## Call graph

| Role | Target |
|---|---|
| **Primary parent (this dual)** | `CNDUIDialog_CompleteDtor` @ `0x00792c20` site `0x00792cde` |
| Other callers | `FUN_00402280`, auth/UI/client sites (~78 xrefs) |
| Callee | `operator_delete` |
| ECX twin | `StdList_Clear_Inferred` @ `0x00404060` |

## Evidence summary

- Live decompile ≡ raw CF; free loop sealed via `read_memory` (decompiler false-noreturn truncates).
- Dialog site `LEA ESI,[EDI+0x4dc]` seals ESI ABI + list offset.
- Do not merge with ECX twin VA or Destroy_FreeHead.

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/StdList_Clear_ESI.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00415e90.cpp`
- Raw: `docs/reconstruction/raw/aa_00415e90_FUN_00415e90.md`
- Annotated: `docs/reconstruction/raw/aa_00415e90_FUN_00415e90.annotated.md`
- Review A: `docs/reconstruction/reviews/A_aa_00415e90_StdList_Clear_ESI.md`
- Review B: `docs/reconstruction/reviews/B_aa_00415e90_StdList_Clear_ESI.md`
- Report: `docs/agents/task-dual-ab-0082ce20-00415e90-wq9lh-report.md`
