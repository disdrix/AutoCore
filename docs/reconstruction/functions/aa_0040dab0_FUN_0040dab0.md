# Function record: FUN_0040dab0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040dab0` |
| **Canonical name** | `FUN_0040dab0` (Ghidra) / **`Math_RoundFloatToInt_MissionXpBias_Inferred`** (named twin) |
| **Address** | `0x0040dab0`–`0x0040dad7` inclusive (**40 B** / `0x28`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Calling convention** | stack float + plain **`RET`** (`C3`); EAX int; **not** thiscall |
| **Completion status** | **Dual sealed** MEGA-119 (2026-08-05) — CF/ABI/bias/callers sealed |
| **Bit-for-bit / runtime / diff** | Open (no Launcher; Terminal false) |
| **Dual residual** | **accept** (`reviews/A_aa_0040dab0_*`, `B_aa_0040dab0_*`) |

## Alias

| Name | Status |
|---|---|
| `Math_RoundFloatToInt_MissionXpBias_Inferred` | **Canonical Inferred** |
| `Mission_Bulk_0040dab0` | **Retired** (keyword bulk scaffold) |

## Purpose

Leaf SSE helper: convert `float` → `int` with signed half-away-from-zero rounding by applying `g_flMissionXpRoundBias` (0.5001f @ `0x00aaa6d0`) then `CVTTSS2SI` trunc toward zero.

Primary dual parent: `Client_ShowMissionRewardChatToast` rounds scaled objective XP for `"Awarded %d"` chat + combat floater. Also shared by item cycle, conversion_percent, and other float→int consumers — **not** mission-grant authority (`CVOGReaction_AddExperience` path applies ±bias inline).

## Signature

```c
int FUN_0040dab0(float param_1);
// stack [ESP+4]; EAX return; RET (C3)
```

## Behavioral summary

1. Load stack float into XMM0; zero XMM1.
2. If `param < 0`: `XMM0 -= bias`; else `XMM0 += bias`.
3. `EAX = (int)trunc_toward_zero(XMM0)`; return.

## Globals

| Label | VA | Value |
|---|---|---|
| `g_flMissionXpRoundBias` | `0x00aaa6d0` | **0.5001f** (`8e 06 00 3f`) |

## Callers / callees

| Role | Count / target |
|---|---|
| Callees | **none** (leaf) |
| Xrefs TO | **20** UNCONDITIONAL_CALL |
| Named parent | `Client_ShowMissionRewardChatToast` @ `0x008ac624` |
| Other hosts | `FUN_0087d810` (×8), `FUN_00503780` (×4), `FUN_0056a680`, `FUN_0049aa60`, `FUN_005d9290`, `FUN_0054cb10`, orphan sites |

## Artifacts

- Raw (+ re-verify): `docs/reconstruction/raw/aa_0040dab0_FUN_0040dab0.md`
- Annotated: `docs/reconstruction/raw/aa_0040dab0_FUN_0040dab0.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/Math_RoundFloatToInt_MissionXpBias_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0040dab0.cpp`
- Named record: `docs/reconstruction/functions/aa_0040dab0_Math_RoundFloatToInt_MissionXpBias_Inferred.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow / SSE body | **Confirmed** (live decompile ≡ bytes) |
| Bias constant 0.5001f | **Confirmed** (`read_memory`) |
| ABI stack float + RET | **Confirmed** |
| Toast parent path | **High** |
| Product demangle English | **Open** → `_Inferred` |
