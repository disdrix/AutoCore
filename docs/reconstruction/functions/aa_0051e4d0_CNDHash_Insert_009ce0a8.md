# Function record: CNDHash_Insert_009ce0a8

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051e4d0` |
| **Canonical name** | `CNDHash_Insert_009ce0a8` |
| **Address** | `0x0051e4d0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression (medal def table) |
| **Completion status** | **Dual A/B present** (2026-07-29) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

- Ghidra: `FUN_0051e4d0`
- Prior: `Named_VOG_DEBUG_STOP_0051e4d0`

## Purpose

CNDHash insert twin with node vtbl `0x009ce0a8`. Medal table loader inserts MedalDef* keyed by id into `DAT_00b042e0`.

## Signature

```c
int __thiscall CNDHash_Insert_009ce0a8(CNDHash *this, uint key, void *value, char softIfExists); // ret 0x0C
// 0 success; 1 soft-hit; 0x80004003 null; 0x80004005 hard dup
```

## Artifacts

- Dual A: `docs/reconstruction/reviews/A_aa_0051e4d0_CNDHash_Insert_009ce0a8.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0051e4d0_CNDHash_Insert_009ce0a8.md`
- Raw: `docs/reconstruction/raw/aa_0051e4d0_FUN_0051e4d0.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_0051e4d0.cpp`
- Legacy record: `docs/reconstruction/functions/aa_0051e4d0_FUN_0051e4d0.md`

## Confidence

| Claim | Level |
|---|---|
| Insert CF + HRESULTs | **Confirmed** |
| Node vtbl / freelist +0x20 | **Confirmed** |
| Twin ≠ other CNDHash_Insert VAs | **High** |
