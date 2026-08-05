# Function record: FUN_004cda90

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cda90` |
| **Canonical name** | `FUN_004cda90` |
| **Structural name** | `Client_InitPalantirViewBundle_Inferred` |
| **Address** | `0x004cda90`–`0x004cdc34` exclusive (**420 B** / `0x1A4`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / Palantir graphics + env bootstrap |
| **Completion status** | **Dual sealed W30-F** (**accept-with-gaps**) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Ghidra: `FUN_004cda90`
- Named: `Client_InitPalantirViewBundle_Inferred`
- Legacy scaffold: `Named_CalleeOf_Named_Could_not_get_Palantir_desktop_window_004cda90`

## Purpose

Factory on large client/core parent: allocate+construct GfxView (`0x150`), env host (`0x198`), and `Class_009c7a1c` (`0xC8`); wire view↔env; optional Palantir desktop hook; env phase init; publish global `DAT_00d1a54c`. Returns `1`.

## Signature (sealed)

```c
// __thiscall/__fastcall; ECX=parent*; returns 1; bare RET
uint32_t __fastcall FUN_004cda90(void *parent);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004cda90_FUN_004cda90.md` (+ W30-F append)
- Annotated: `docs/reconstruction/raw/aa_004cda90_FUN_004cda90.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/Client_InitPalantirViewBundle_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_004cda90.cpp`
- Named record: `docs/reconstruction/functions/aa_004cda90_Client_InitPalantirViewBundle_Inferred.md`
- Reviews: `A_aa_004cda90_Client_InitPalantirViewBundle_Inferred.md`, `B_aa_004cda90_Client_InitPalantirViewBundle_Inferred.md`

## Callers / callees

| Direction | VA / name | Notes |
|---|---|---|
| Caller | `FUN_00948530` @ `0x00948aad` | sole; window init path |
| Callee | `FUN_0075ceb0` | GfxView ctor (`gfxView.cpp`) |
| Callee | `FUN_00492dd0` | env host ctor `0x198` |
| Callee | `FUN_00496f70` | `Class_009c7a1c_Ctor` (W29-G) |
| Callee | `FUN_0048fc90` | env sector phases |
| Callee | `FUN_0075b3b0` / `FUN_0075b390` | view near/far floats |
| Callee | `FUN_0074e200` | global slot enable/disable |

## Confidence

| Claim | Level |
|---|---|
| Control flow + three alloc sizes + store offsets | **High** |
| ABI bare RET / return 1 | **High** |
| Sole caller / Palantir desktop context | **High** |
| Product English parent type | **Open** |
| Runtime / bit-exact | Open |
