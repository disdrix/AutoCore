# Function record: NDSpecialFX_LivenessDone_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b7330` |
| **Canonical name** | `NDSpecialFX_LivenessDone_Inferred` |
| **Ghidra name** | `FUN_004b7330` |
| **Address** | `0x004b7330` |
| **Body span** | `004b7330`–`004b73bc` (**140 B / `0x8C`**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client-fx / NDSpecialFX lifecycle |
| **Convention** | ECX = fx host; plain `RET` (`C3`); return 0\|1 in AL |
| **Completion status** | **partial** — three-rep + dual A/B sealed 2026-07-29; runtime/diff/bit-exact open |
| **Dual verdict** | **accept** (A+B) |
| **Dual A/B** | `reviews/A_aa_004b7330_NDSpecialFX_LivenessDone_Inferred.md`, `reviews/B_aa_004b7330_NDSpecialFX_LivenessDone_Inferred.md` (2026-07-29 W26-H) |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

NDSpecialFX host **liveness done** probe: residual host flags clear, owned-list children finished (`+0x795`), optional secondary list inactive (`+0x10B`). Sole caller HostTick deactivates when this returns non-zero.

## Signature

```c
// ECX = fx host; plain RET; AL 0|1
uint8_t __fastcall NDSpecialFX_LivenessDone_Inferred(void *fx_host);
// 0 = still live; 1 = done (HostTick → DeactivateClear)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004b7330_FUN_004b7330.md`
- Annotated: `docs/reconstruction/raw/aa_004b7330_FUN_004b7330.annotated.md`
- Clean (mirror): `docs/reconstruction/reconstructed-exact/FUN_004b7330.cpp`
- Named: `docs/reconstruction/reconstructed-exact/NDSpecialFX_LivenessDone_Inferred.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_004b7330_FUN_004b7330.md`
- Review A/B: dual files above

## Callers / callees

| Dir | VA | Name |
|---|---|---|
| Caller | `0x004b8ed0` | `NDSpecialFX_HostTick_Inferred` (site `0x004b8f55`) |
| Callees | — | leaf |

## Confidence

| Claim | Level |
|---|---|
| CF ≡ live decompile | **Confirmed** |
| Leaf / 140 B body | **Confirmed** |
| HostTick polarity (non-zero = done) | **Confirmed** (W24-C dual) |
| Product C++ name | **Inferred** (`_Inferred`) |
| Runtime / differential | **Open** |

## Prior scaffold alias

`Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_004b7330` — superseded.
