# Function record: Rng_Mt19937_Extract

| Field | Value |
|---|---|
| **Stable ID** | `aa_00424830` |
| **Canonical name** | `Rng_Mt19937_Extract` |
| **Ghidra name** | `FUN_00424830` |
| **Address** | `0x00424830` |
| **Body range** | `0x00424830`–`0x00424882` (exclusive end; **82** B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | RNG / MT19937 |
| **Completion status** | **accept** — dual A/B sealed; CF + ABI + temper + sibling twist link sealed; runtime vector open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_00424830_Rng_Mt19937_Extract.md`, `reviews/B_aa_00424830_Rng_Mt19937_Extract.md` |
| **Last reviewed** | `2026-07-29` (W20-C) |

## Alias

- `FUN_00424830` (Ghidra)
- `Named_CalleeOf_Client_ShowDriverSitHumorMessages_00424830` (auto parent-seed — partial/misleading)
- `Rng_Mt19937_GenrandInt32` / `Mt19937_NextU32` (descriptive)

## Purpose

**Extract one tempered 32-bit value** from a Mersenne Twister state object:

1. If `remaining(+0x9c4) == 0` → `Rng_Mt19937_Twist` (refill 624, reset cursor).
2. Decrement remaining; load `*cursor`; advance cursor by one dword.
3. Standard MT19937 temper (body uses pre-shift mask form); return in EAX.

## Signature

```c
// EAX = Mt19937State*; bare ret; returns uint32 in EAX
uint32_t Rng_Mt19937_Extract(void);
```

## Constants (sealed)

| Name | Value |
|---|---|
| Temper SHR 1 | 11 |
| Temper SHL 2 | 7; mask `0xff3a58ad` (≡ classic `0x9d2c5680`) |
| Temper SHL 3 | 15; mask `0xffffdf8c` (≡ classic `0xefc60000`) |
| Temper SHR 4 | 18 |
| N (via twist) | 624 |

## Layout (partial)

| Off | Role |
|---|---|
| `+0x00` | `mt[624]` |
| `+0x9c0` | cursor `uint32*` |
| `+0x9c4` | remaining (int) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00424830_FUN_00424830.md`
- Annotated: `docs/reconstruction/raw/aa_00424830_FUN_00424830.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Rng_Mt19937_Extract.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_00424830.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-00606ff0-00424830-w20c-report.md`

## Callers / callees

| Direction | Symbol | Notes |
|---|---|---|
| Callee | `Rng_Mt19937_Twist` `FUN_004248c0` | when remaining==0 |
| Callers | 34 xrefs | sound, humor, UI, `FUN_007a41f0`, … |

## Confidence

| Claim | Level |
|---|---|
| MT19937 extract + temper | **Confirmed** |
| EAX state ABI; result EAX | **Confirmed** |
| cursor@+0x9c0 remaining@+0x9c4 | **Confirmed** |
| Product English name | **Inferred** |
| Runtime vectors | Open |

## Related

- `aa_004248c0` Rng_Mt19937_Twist
- `aa_00424890` Rng_Mt19937_Seed
- `FUN_007a4200` table fill / `FUN_007a41f0` next wrapper
