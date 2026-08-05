# Function record: CVOGHBBase_AppendRemainingText

| Field | Value |
|---|---|
| **Stable ID** | `aa_00578550` |
| **Canonical name** | `CVOGHBBase_AppendRemainingText` |
| **Ghidra name** | `FUN_00578550` |
| **Address** | `0x00578550` |
| **Body range** | `0x00578550`–`0x005786ee` (414 bytes) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `heartbeat` / timed-actions UI tooltip |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF + ABI + thresholds/scales/units sealed; quantize leaf formulas residual |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_00578550_CVOGHBBase_AppendRemainingText.md`, `reviews/B_aa_00578550_CVOGHBBase_AppendRemainingText.md` (2026-07-29 W23-R) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_00578550`
- Scaffold: `Named_CalleeOf_Skill_skills_00578550`
- Enable thunk: `FUN_005786f0` (always passes enable=1)

## Purpose

Append localized **Remaining** time text onto a destination C-string for HB/skill tooltips:

```
"<quantized_value> <unit> Remaining\n"
```

Units by remaining seconds: days / hrs / min / sec. Skips when `enable==0` or `nPeriodCounter==-1000`.

## Signature

```c
uint8_t __thiscall CVOGHBBase_AppendRemainingText(
    CVOGHBBase *self,
    char *dest,
    void *unused_a,
    void *unused_b,
    char enable);
// ret 0x10; AL = 1 if appended
```

## Algorithm

1. Loc context via `FUN_007a69d0`.
2. Gate enable + `nPeriodCounter != -1000`.
3. `rem = CVOGHBBase_GetRemainingSeconds(self)`.
4. Cascade thresholds 86400 / 3600 / 60; scale; quantize; localize unit + "Remaining"; sprintf; strcat to dest.
5. Return 1 (or 0 if gated).

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00578550_FUN_00578550.md`
- Annotated: `docs/reconstruction/raw/aa_00578550_FUN_00578550.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGHBBase_AppendRemainingText.cpp`
- Alias clean: `docs/reconstruction/reconstructed-exact/FUN_00578550.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_00578550_FUN_00578550.md`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-005cc460-00578550-w23r-report.md`

## Callers / callees

| Direction | VA | Name / role |
|---|---|---|
| Callee | `0x00508280` | `CVOGHBBase_GetRemainingSeconds` |
| Callee | `0x007a69d0` | loc context singleton |
| Callee | `0x007a6de0` | localize string |
| Callee | `0x00578140` | day display quantize |
| Callee | `0x00412c60` | hour/min display quantize |
| Callee | `sprintf` | format |
| Caller | `0x005786f0` | enable=1 thunk |
| Callers | `0x00618c80`, `0x00617c10`, `0x00621500`, … | UI / skill tooltip builders |

## Confidence

| Claim | Level |
|---|---|
| Control flow + ABI ret 0x10 | **High** |
| Gate enable + counter==-1000 | **High** |
| Thresholds / scales / unit keys | **High** (read_memory) |
| strcat-on-dest semantics | **High** |
| Quantize leaf exact formulas | **Medium** (helpers residual) |
| Product name | **Open** |
| Runtime / differential | Open |
