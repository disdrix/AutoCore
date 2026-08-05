# Function record: QuickBar_CycleSelectValidColumn

| Field | Value |
|---|---|
| **Stable ID** | `aa_008a0210` |
| **Canonical name** | `QuickBar_CycleSelectValidColumn` |
| **Ghidra name** | `FUN_008a0210` |
| **Address** | `0x008a0210` |
| **Body range** | `0x008a0210`–`0x008a0368` (exclusive end; **344** B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client UI / quickbar |
| **Completion status** | **partial** — dual A/B **accept**; CF + ABI + column layout sealed; product spelling / runtime open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_008a0210_QuickBar_CycleSelectValidColumn.md`, `reviews/B_aa_008a0210_QuickBar_CycleSelectValidColumn.md` |
| **Last reviewed** | `2026-07-29` (W21-T) |

## Alias

- `FUN_008a0210` (Ghidra)
- Residual: `Named_CalleeOf_Client_Input_PollBoundActions_008a0210` (auto parent-seed — incomplete; also called from SelectPage / skill-train / input binds)

## Purpose

**Cycle selection** among the 10 quickbar column widgets at `host+0x63c`:

1. Locate current selection (`col+0x4fc != 0`).
2. Walk next (`direction != 0`) or prev (`direction == 0`) with wrap, skipping empty columns (`+0x548` is 0 or 6).
3. On hit: `UI_QuickBarSlotButton_SetSelected(current, 0)` then `SetSelected(target, 1)`.
4. If none selected: bootstrap first filled column (inline select tail).

Always returns **AL = 0**.

## Signature

```c
// EBX = CDlgQuickBar* host; stack char direction; ret 4; AL always 0
uint QuickBar_CycleSelectValidColumn(char direction);
```

## Algorithm

See annotated + clean. Callees: `UI_QuickBarSlotButton_SetSelected` (`0x00826780`); bootstrap uses `__RTDynamicCast`, `FUN_0089fef0`, highlight `vtbl+4`.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_008a0210_FUN_008a0210.md`
- Annotated: `docs/reconstruction/raw/aa_008a0210_FUN_008a0210.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/QuickBar_CycleSelectValidColumn.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_008a0210.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-008a0210-008aa320-w21t-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `UI_QuickBarSlotButton_SetSelected` (`FUN_00826780`); `__RTDynamicCast`; `FUN_0089fef0` (bootstrap only) |
| **Callers (8)** | `Client_SkillTrainUiRequest_INFERRED` @ `008972c5`; `QuickBar_SelectPage_Inferred` @ `008a0f6c`; `FUN_008a16b0` @ `008a1e12`; `FUN_009114f0` @ `00911676` (dir=1) / `009116a4` (dir=0); `FUN_009163a0` @ `00916415`; `Client_Input_PollBoundActions` @ `00926451` / `00926489` |

## Confidence

| Claim | Level |
|---|---|
| EBX host; stack direction; ret 4 | **High** |
| 10 columns @ +0x63c; selected +0x4fc; fill +0x548 | **High** |
| Pair deselect/select via SetSelected | **High** (live ECX rewrite) |
| Direction 0=prev / ≠0=next | **High** (call sites push 0 and 1) |
| Always AL=0 | **High** |
| Product/PDB method spelling | Open |
| Runtime / bit-exact | Open |

## Related

- `aa_00826780` UI_QuickBarSlotButton_SetSelected
- `aa_008a0ed0` QuickBar_SelectPage_Inferred
- `aa_00926400` Client_Input_PollBoundActions (caller)
- `DAT_00d1da38` per-page last column; `DAT_00d1b8f0` live host pointer
