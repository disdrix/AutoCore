# Function record: UI_BuildItemTooltipStats

| Field | Value |
|---|---|
| **Stable ID** | `aa_00847ad0` |
| **Canonical name** | `UI_BuildItemTooltipStats` |
| **Prior names** | `FUN_00847ad0` |
| **Address** | `0x00847ad0` |
| **Body** | `0x00847ad0`–`0x0084af04` (0x3434 bytes) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer / client UI (item tooltips) |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** (2026-07-29); architecture + ABI + type switch + power-plant offsets sealed |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Build **item tooltip stat lines** into a UI text host by item type. Returns **line count** appended. Client-only.

## Signature (sealed shell)

```c
// ECX = tooltip host (this). Stack: item*, char detailA, char detailB.
// Epilogue RET (C3) — caller cleans 3 stack dwords. EAX = int lineCount.
int UI_BuildItemTooltipStats(void *tooltipHost,
                             void *item,
                             char showDetail,
                             char showExtra);
```

## Sealed highlights

- Early: `DAT_00d1b6d8==0` → 0; `FUN_00524520` nonzero → 1 line + return 1.
- Dispatch: `type = *(*(item+0xA8)+0x38)` switch (4,6,8,10,0xC,0xE,0x10,0x1A,0x1C,0x32,0x34,default).
- Power plant (10): HeatMax `+0xB0`, PowerMax `+0xB4`, PowerRegen `+0xB8`, CoolRate `+0xBA`.
- Host vfuncs: primarily `+0x224` append, `+0x250` spacing.
- Callers: `FUN_00843a60`, `FUN_0084b890`, `FUN_0088d980` (4 xrefs).

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00847ad0_FUN_00847ad0.md` (+ live dual append)
- Annotated: `docs/reconstruction/raw/aa_00847ad0_FUN_00847ad0.annotated.md`
- Clean scaffold: `docs/reconstruction/reconstructed-exact/FUN_00847ad0.cpp`
- Clean named: `docs/reconstruction/reconstructed-exact/UI_BuildItemTooltipStats.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00847ad0_UI_BuildItemTooltipStats.md`
- Review B: `docs/reconstruction/reviews/B_aa_00847ad0_UI_BuildItemTooltipStats.md`
- Dual report: `docs/agents/task-dual-ab-00847ad0-ui-builditemtooltipstats-report.md`

Legacy scaffold record: `docs/reconstruction/functions/aa_00847ad0_FUN_00847ad0.md`.

## Confidence

| Claim | Level |
|---|---|
| Control flow architecture from decompiler | **High** |
| ABI shell + return line count | **High** |
| Power plant offsets | **High** |
| Full localization / product type names | Residual |
| Bit-exact body | Open |
