# Function record: CNDHash_Recreate

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051d230` |
| **Canonical name** | `CNDHash_Recreate` |
| **Address** | `0x0051d230` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | container / missions-progression (medal hash) |
| **Completion status** | **Dual A/B present** (2026-07-29) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

- Ghidra: `FUN_0051d230`
- Prior: `Named_VOG_DEBUG_STOP_0051d230`

## Purpose

Recreate empty CNDHash bucket table: clear via `FUN_0051d150`, set log2 bits, allocate sentinels (`FUN_0051ba40` / vtbl `009ce090`). Sole static caller medal ensure `FUN_00519660` with bits=4 on `DAT_00b042e0`.

## Signature

```c
void __thiscall CNDHash_Recreate(CNDHash *this, byte log2BucketCount); // ret 4
```

## Artifacts

- Dual A: `docs/reconstruction/reviews/A_aa_0051d230_CNDHash_Recreate.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0051d230_CNDHash_Recreate.md`
- Raw: `docs/reconstruction/raw/aa_0051d230_FUN_0051d230.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_0051d230.cpp`
- Legacy record: `docs/reconstruction/functions/aa_0051d230_FUN_0051d230.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow | **Confirmed** |
| Product name from Recreate string | **High** |
| Full clear helper semantics | **Open** |
