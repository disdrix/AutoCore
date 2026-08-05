# Function record: Outpost_GetPulseXpPercent

| Field | Value |
|---|---|
| **Stable ID** | `aa_006075b0` |
| **Canonical name** | `Outpost_GetPulseXpPercent` |
| **Address** | `0x006075b0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression / outpost XP |
| **Completion status** | **Clean human-refined** — raw/annotated present; clean rewritten with named fields + table layout; dual review still open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Index the true-outpost or non-outpost `fPercentLevelXP` pulse table and return the float percent consumed by `Outpost_ComputePulseXp` (`amount = round(levelSpan * percent * scalar@+0x21c)`). See `docs/XP.md` § Outpost pulse XP.

## Signature (decompiler-derived)

```c
float /*float10*/ __fastcall Outpost_GetPulseXpPercent(void* pOutpost);
```

## Fields

| Offset | Role |
|---|---|
| `+0x220` | `bIsOutpost` (char): non-zero → `DAT_00d029e0`, else `DAT_00d029f0` |
| `+0x23c` | row index into 0x10-byte table (float percent at row+0x08) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_006075b0_Outpost_GetPulseXpPercent.md`
- Annotated: `docs/reconstruction/raw/aa_006075b0_Outpost_GetPulseXpPercent.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Outpost_GetPulseXpPercent.cpp`

## Callers / callees

- Caller: `Outpost_ComputePulseXp` @ `0x00607830`
- Callee: `FUN_00608620` (defensive table accessor; normally unreachable after first bounds check)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Two tables selected by `+0x220` | High |
| Row stride 0x10, float at +0x08 | High |
| Semantic names `bIsOutpost` / index | Probable |
| `FUN_00608620` full signature | Tentative |
