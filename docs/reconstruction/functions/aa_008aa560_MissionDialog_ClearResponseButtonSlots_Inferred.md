# Function record: MissionDialog_ClearResponseButtonSlots_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008aa560` |
| **Canonical name** | `MissionDialog_ClearResponseButtonSlots_Inferred` |
| **Ghidra name** | `FUN_008aa560` |
| **Address** | `0x008aa560` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `missions-progression` / mission dialog chrome |
| **Classification** | leaf |
| **Completion status** | **Dual A/B sealed** (WQ7R-C 2026-08-04) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (no Launcher) |

## Alias / rejected plates

| Name | Status |
|---|---|
| `FUN_008aa560` | Ghidra default — keep as twin |
| `MissionDialog_ClearResponseButtonSlots_Inferred` | **Preferred** structural |
| `Named_CalleeOf_Mission_i_d_npc_2d_btn_response_xml_008aa560` | Scaffold caller plate — not product English |

## Purpose

Clear mission-dialog **response button** chrome capacity (**8** fixed slots):

1. Each TFID pair at `dialog+0x518 + i*8` ← `(−1, −1)`.
2. Each widget at `dialog+0x708 + i*4`: if non-null, call host **vtbl+0xBC**(widget), then zero.

Sole caller `FUN_008ac110` (`Mission_i_d_npc_2d_btn_response_xml`) invokes this as **pre-rebuild wipe** before allocating new `i_d_npc_2d_btn_response.xml` children into `+0x708`.

Does **not** write chrome mode `+0x510`, turn-in `+0x64c`, reward banks, or send packets.

## Signature (sealed)

```c
// EBX = MissionDialogHost*; no stack args; plain RET
void MissionDialog_ClearResponseButtonSlots_Inferred(void);
```

| Item | Value |
|---|---|
| Body | `0x008aa560`–`0x008aa5a6` exclusive (**70 B** / `0x46`) |
| Full hex | see raw WQ7R-C append |

## Layout (dialog host)

| Offset | Type | Role |
|---|---|---|
| +0x518 | `int32[8][2]` | response TFID pairs (cleared to −1) |
| +0x708 | `void*[8]` | response button widgets (destroyed) |
| +0x510 | `int` | live button count (read by caller rebuild; **not** written here) |

## Callers / callees

| Direction | Target |
|---|---|
| Caller (1) | `FUN_008ac110` @ `0x008ac138` (`MOV EBX,EDI` then CALL) |
| Callees | host virtual `vtbl+0xBC` only (no direct FUN_*) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_008aa560_FUN_008aa560.md`
- Annotated: `docs/reconstruction/raw/aa_008aa560_FUN_008aa560.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/MissionDialog_ClearResponseButtonSlots_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_008aa560.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_008aa560_MissionDialog_ClearResponseButtonSlots_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_008aa560_MissionDialog_ClearResponseButtonSlots_Inferred.md`
- Scratch: `docs/reconstruction/tmp/a_008aa560.md`
- Agent report: `docs/agents/task-dual-ab-008aab00-008aa560-wq7rc-report.md`

## Confidence

| Claim | Level |
|---|---|
| EBX ABI + 8-slot clear | **High** |
| Offsets +0x518 / +0x708 | **High** (bytes `lea …+0x518/+0x708`) |
| vtbl+0xBC destroy role | **Inferred** High as destroy/release; product name open |
| Fixed 8 capacity vs live count at +0x510 | **High** (clear always 8; rebuild uses count) |

## Gaps

1. Product/PDB name.
2. Product name for vtbl+0xBC.
3. Exact TFID pair semantics at +0x518 (HandleButton consumer external).
4. Runtime / bit-exact / differential.
