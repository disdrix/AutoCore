# Function record: Client_Camera_ModeDispatchUpdate_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0091ce80` |
| **Canonical name** | `Client_Camera_ModeDispatchUpdate_Inferred` |
| **Ghidra name** | `FUN_0091ce80` |
| **Address** | `0x0091ce80` |
| **Body span** | `0091ce80`–`0091d433` (**1459** B / `0x5B3`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client camera / mode dispatch tick |
| **Convention** | **EAX = cam***; stack `dt_or_scale`; `RET 4` |
| **Completion status** | **partial** — three-rep + dual A/B sealed 2026-07-29; runtime/diff open |
| **Dual verdict** | **accept-with-gaps** (A+B) |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

| Name | Status |
|------|--------|
| `FUN_0091ce80` | Ghidra auto / scaffold |
| `Client_Camera_ModeDispatchUpdate_Inferred` | **Canonical** (this dual) |

## Purpose

Client camera **mode dispatcher** tick: resolve focus (prep + pose fallback), gate, compute range pair from cam fields, **switch on `cam[0x331]`** to mode-specific updaters (including dualed default `009168d0` and modes-2/5/7 `0091b1c0`), then build look vector, clamp FOV/distance band onto the camera child object, and optionally scale FOV by vehicle speed.

## Signature

```c
// RET 4; EAX = cam* on entry
void Client_Camera_ModeDispatchUpdate_Inferred(float dt_or_scale);
```

## Mode table (`cam[0x331]` @ +0xCC4)

| Case | Callee |
|---|---|
| 1 | `FUN_00914930` |
| 2, 5, 7 | `Client_Camera_Modes257_ChaseUpdate_Inferred` |
| 3 | `FUN_00914980` |
| default | `Client_Camera_DefaultModeUpdate_Inferred` |
| 8 | `FUN_0091c220` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0091ce80_FUN_0091ce80.md`
- Annotated: `docs/reconstruction/raw/aa_0091ce80_FUN_0091ce80.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_0091ce80.cpp`
- Named: `docs/reconstruction/reconstructed-exact/Client_Camera_ModeDispatchUpdate_Inferred.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_0091ce80_FUN_0091ce80.md`
- Review A: `docs/reconstruction/reviews/A_aa_0091ce80_Client_Camera_ModeDispatchUpdate_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_0091ce80_Client_Camera_ModeDispatchUpdate_Inferred.md`
- Report: `docs/agents/task-dual-ab-0091b1c0-0091ce80-w25b-report.md`
- Default-mode dual: `aa_009168d0` (W24-D)
- Modes 2/5/7 dual: `aa_0091b1c0` (this wave)

## Callers / callees

| Dir | VA | Name |
|---|---|---|
| Caller | site `0x00924283` | tick: `mov eax,edi; call` (containing fn undefined in Ghidra) |
| Callee | `0x0091b1c0` | modes 2/5/7 |
| Callee | `0x009168d0` | default mode (W24-D) |
| Callee | `0x00914930` / `0x00914980` / `0x0091c220` | other modes |
| Callee | `0x00917cd0` / `0x00917700` / `0x009141e0` / `0x0091b0d0` | prep/gate/post |
| Callee | `0x004e88e0` | pose float3 |
| Callee | `D3DXVec3Normalize` | look |

## Confidence

| Claim | Level |
|---|---|
| Body + `ret 4` + EAX cam* | **Confirmed** |
| Mode switch table | **Confirmed** |
| Links to dualed `009168d0` / `0091b1c0` | **Confirmed** |
| Product method / mode enum English | Tentative |
| FOV band product meaning | Tentative |
| Containing caller function | Open |
| Runtime / bit-exact | Open |
