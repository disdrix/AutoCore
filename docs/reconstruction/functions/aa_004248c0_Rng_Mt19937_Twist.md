# Function record: Rng_Mt19937_Twist

| Field | Value |
|---|---|
| **Stable ID** | `aa_004248c0` |
| **Canonical name** | `Rng_Mt19937_Twist` |
| **Address** | `0x004248c0` |
| **Body** | `0x004248c0`–`0x00424965` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | RNG / MT19937 |
| **Completion status** | **accept-with-gaps** — dual A/B W18-K 2026-07-29 |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- `FUN_004248c0`
- `Named_CalleeOf_Named_CalleeOf_CVOGReaction_RandomUnitScalar_004248c0`

## Purpose

MT19937 **twist** over `uint32 mt[624]` in a state object held in **ESI**. Regenerates the full state array using MATRIX_A `0x9908b0df`, then resets extract cursor (`+0x9c0 = &mt[0]`) and remaining count (`+0x9c4 = 624`).

Called from extract-one when remaining hits 0, from table fill, RNG ctor, and other consumers (22 xrefs).

## Signature

```c
// ESI = Mt19937State*; no stack args; near RET
void Rng_Mt19937_Twist(void);
```

## Constants (sealed)

| Name | Value |
|---|---|
| N | `0x270` = 624 |
| M | `0x18d` = 397 |
| N−M (loop1) | `0xe3` = 227 |
| M−1 (loop2) | `0x18c` = 396 |
| MATRIX_A | `0x9908b0df` |

## Layout (partial)

| Off | Role |
|---|---|
| `+0x00` | `mt[624]` |
| `+0x9c0` | cursor `uint32*` → set to state base |
| `+0x9c4` | remaining → set to 624 |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004248c0_FUN_004248c0.md`
- Annotated: `docs/reconstruction/raw/aa_004248c0_Rng_Mt19937_Twist.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Rng_Mt19937_Twist.cpp`
- Scaffold (legacy): `docs/reconstruction/reconstructed-exact/FUN_004248c0.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_004248c0_Rng_Mt19937_Twist.md`
- Dual B: `docs/reconstruction/reviews/B_aa_004248c0_Rng_Mt19937_Twist.md`

## Callers / callees

| Direction | Symbol | Notes |
|---|---|---|
| Callee | *(none)* | leaf |
| Caller | `FUN_00424830` | extract-one |
| Caller | `FUN_007a4200` | 2 MiB tempered table fill |
| Caller | `FUN_007a42d0` | RNG ctor path |
| Caller | `FUN_007212b0`, `FUN_008d7010`, `FUN_009526f0`, `FUN_00952bc0`, `FUN_00955010` | other |

## Confidence

| Claim | Level |
|---|---|
| MT19937 twist CF / constants | **Confirmed** |
| ESI ABI + cursor/remaining writes | **Confirmed** |
| Product English name | **Inferred** |
| Temper / seed (siblings) | **Out of unit** (context High) |
