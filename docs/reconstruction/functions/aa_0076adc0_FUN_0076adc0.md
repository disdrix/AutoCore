# Function record: FUN_0076adc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076adc0` |
| **Canonical name** | `FUN_0076adc0` |
| **Preferred inferred** | `Fs_PathIsDirectory_Stat_Inferred` |
| **Address** | `0x0076adc0`–`0x0076ae35` (**118 B** / `0x76`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | filesystem / path probe |
| **Wave** | W33-C OWN-ONLY dual 2026-07-29 |
| **Completion status** | **Reviewed** — dual A/B sealed |
| **Verdict** | **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Human / prior: `Named_CalleeOf_Named_assManager_0076adc0`
- Inferred: `Fs_PathIsDirectory_Stat_Inferred`

## Purpose

CRT `stat`-based **is-directory** probe. Copies path to a 260-byte stack buffer, strips one trailing `\` or `/`, calls `stat`, returns 0 on failure or `(st_mode >> 14) & 1` (`S_IFDIR`) on success.

## Signature (sealed)

```c
// cdecl; bare RET; EAX/AL = 0 or 1
uint32_t FUN_0076adc0(const char* path);
// same as Fs_PathIsDirectory_Stat_Inferred
```

## Callers / callees

| Role | Symbols |
|---|---|
| Callees | `stat` (IAT `0x009c6504`) |
| Callers | `FUN_0076b3f0`, `FUN_0076ba10`, `FUN_0076bc00`, `FUN_0076bc80`, `FUN_007a13e0`, `FUN_007b75b0`, `FUN_009839b0`, `FUN_00984340` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0076adc0_FUN_0076adc0.md`
- Annotated: `docs/reconstruction/raw/aa_0076adc0_FUN_0076adc0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Fs_PathIsDirectory_Stat_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0076adc0.cpp`
- Function named: `docs/reconstruction/functions/aa_0076adc0_Fs_PathIsDirectory_Stat_Inferred.md`
- Dual A: `docs/reconstruction/reviews/A_aa_0076adc0_Fs_PathIsDirectory_Stat_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0076adc0_Fs_PathIsDirectory_Stat_Inferred.md`
- Scratch: `docs/reconstruction/tmp/a_0076adc0.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler ≡ bytes | **High** |
| cdecl 1 formal + bare RET | **High** |
| st_mode @ +6 / S_IFDIR bit test | **High** |
| Fail path XOR AL,AL → 0 | **High** |
| Product / CRT demangle | **Low** |
| Runtime / differential | **Open** |
