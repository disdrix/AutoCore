# Function record: CVOGHBPendingUseObject_OnHeartBeat_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060b440` |
| **Canonical name** | `CVOGHBPendingUseObject_OnHeartBeat_Inferred` (**Probable**) |
| **Ghidra name** | `FUN_0060b440` |
| **Address** | `0x0060b440`–`0x0060b49f` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | heartbeat / missions-progression |
| **Completion status** | **Full dual seal** (W26-T 2026-07-29) |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

OnHeartBeat: commit pending use-object when secondary still matches; else Remove from HB list.

## Signature

```c
std::uint32_t* __thiscall CVOGHBPendingUseObject_OnHeartBeat_Inferred(
    CVOGHBPendingUseObject* self, std::uint32_t* pOutStatus);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0060b440_FUN_0060b440.md`
- Annotated: `docs/reconstruction/raw/aa_0060b440_FUN_0060b440.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGHBPendingUseObject_OnHeartBeat_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_0060b440.cpp`
- Ghidra record: `docs/reconstruction/functions/aa_0060b440_FUN_0060b440.md`
- Dual A/B: `reviews/A_aa_0060b440_…`, `reviews/B_aa_0060b440_…`

## Confidence

| Claim | Level |
|---|---|
| CF + ABI + Remove token | **High** |
| Product English | **Tentative** (`_Inferred`) |
