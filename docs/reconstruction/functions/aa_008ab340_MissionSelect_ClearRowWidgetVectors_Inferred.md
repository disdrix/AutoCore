# Function record: MissionSelect_ClearRowWidgetVectors_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ab340` |
| **Canonical name** | `MissionSelect_ClearRowWidgetVectors_Inferred` |
| **Ghidra name** | `FUN_008ab340` |
| **Address** | `0x008ab340` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `missions-progression` / Select-a-Mission list chrome |
| **Classification** | worker |
| **Completion status** | **Dual A/B sealed** (MEGA-105 2026-08-05) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (no Launcher) |

## Alias / rejected plates

| Name | Status |
|---|---|
| `FUN_008ab340` | Ghidra default — twin |
| `MissionSelect_ClearRowWidgetVectors_Inferred` | **Preferred** structural |
| `Named_CalleeOf_Mission_Select_a_Mission_008ab340` | Scaffold — **retired** |

## Purpose

Clear Select-a-Mission **list row widget** chrome held in two dynamic pointer vectors:

1. For each non-null widget in vector A (`host+0x72c`…`+0x730`) and vector B (`+0x73c`…`+0x740`):
   - widget **vtbl+0x3d8** bool query; if true **vtbl+0x440**
   - if `widget+0x2b0 ≠ 0`: host **vtbl+0xB0**(widget)
   - scalar deleting dtor **vtbl[0](1)**; zero slot
2. Set each vector's **end = begin** (used-range clear; capacity kept).

Call sites: always at end of `FUN_008ab550` (Select-a-Mission panel mode switch), and first step of host dtor `FUN_008ac340` before `operator_delete` of both buffers.

Does **not** rebuild rows, free capacity buffers, or paint the "Select a Mission:" title.

## Signature (sealed)

```c
// ESI = MissionSelectHost*; no stack args; plain RET
void MissionSelect_ClearRowWidgetVectors_Inferred(void);
```

| Item | Value |
|---|---|
| Body | `0x008ab340`–`0x008ab549` exclusive (**521 B** / `0x209`) |
| Full hex | see raw MEGA-105 re-verify |

## Layout (host)

| Offset | Type | Role |
|---|---|---|
| +0x72c | `T**` begin | list-row widget vector A |
| +0x730 | `T**` end | vector A used end |
| +0x734 | `T**` cap | capacity (dtor only) |
| +0x73c | `T**` begin | list-row widget vector B |
| +0x740 | `T**` end | vector B used end |
| +0x744 | `T**` cap | capacity (dtor only) |

## Callers / callees

| Direction | Target |
|---|---|
| Caller (2 sites) | `FUN_008ab550` @ `008ab6c4`, `008ab791` (`MOV ESI,ECX` at entry) |
| Caller (1 site) | `FUN_008ac340` @ `008ac36c` (`MOV ESI,ECX` then CALL) |
| Callee | `memmove` |
| Virtual | widget +0x3d8 / +0x440 / +0; host +0xB0 |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_008ab340_FUN_008ab340.md`
- Annotated: `docs/reconstruction/raw/aa_008ab340_FUN_008ab340.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/MissionSelect_ClearRowWidgetVectors_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_008ab340.cpp`
- Function FUN: `docs/reconstruction/functions/aa_008ab340_FUN_008ab340.md`
- Review A: `docs/reconstruction/reviews/A_aa_008ab340_MissionSelect_ClearRowWidgetVectors_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_008ab340_MissionSelect_ClearRowWidgetVectors_Inferred.md`
- Agent report: `docs/agents/task-dual-ab-008ab340-mega-105-report.md`

## Confidence

| Claim | Level |
|---|---|
| ESI ABI + 521 B body + plain RET | **High** |
| Offsets +0x72c/+0x730/+0x73c/+0x740 | **High** |
| Destroy protocol + end=begin clear | **High** |
| Product names for virtuals / banks A vs B | **Open** (`_Inferred`) |
| Runtime / bit-exact / differential | **Open** |

## Gaps

1. Product/PDB name.
2. Product English for vtbl +0x3d8 / +0x440 / host +0xB0.
3. Semantic split between vector A and vector B.
4. Runtime / bit-exact / differential.
