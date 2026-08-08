# Function record: FUN_008aa4b0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008aa4b0` |
| **Canonical name** | `MissionDialog_SetNpcObjectAndNameCaption_Inferred` |
| **Ghidra name** | `FUN_008aa4b0` |
| **Address** | `0x008aa4b0`–`0x008aa50e` inclusive (**95 B** / `0x5F`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `missions-progression` |
| **Completion status** | **Dual sealed MEGA-058** — raw re-verify + annotated + clean + A/B; product English open |
| **Bit-for-bit / runtime / diff** | Open (terminal false; no Launcher) |
| **Dual verdict** | **accept-with-gaps** |

## Alias

- Human: `MissionDialog_SetNpcObjectAndNameCaption_Inferred`
- **Retired scaffold:** `Named_CalleeOf_Client_ShowNpcMissionDialogUI_008aa4b0` (incomplete call surface)

## Purpose

Stamp NPC object at `dialog+0x644` and bind/clear NPC-name caption widget at `dialog+0x6d8` (vtbl+0x1d8 / tail JMP +0x34c). Dialog helper before thr/steer park and on ShowNpc present paths.

## Signature (sealed)

```c
// ESI = dialog*; EAX = npcObject* (0 clear); plain RET
void FUN_008aa4b0(void);
```

## Artifacts

- Raw (+ MEGA-058 re-verify): `docs/reconstruction/raw/aa_008aa4b0_FUN_008aa4b0.md`
- Annotated: `docs/reconstruction/raw/aa_008aa4b0_FUN_008aa4b0.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/MissionDialog_SetNpcObjectAndNameCaption_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_008aa4b0.cpp`
- Named record: `docs/reconstruction/functions/aa_008aa4b0_MissionDialog_SetNpcObjectAndNameCaption_Inferred.md`
- Review A: `docs/reconstruction/reviews/A_aa_008aa4b0_MissionDialog_SetNpcObjectAndNameCaption_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_008aa4b0_MissionDialog_SetNpcObjectAndNameCaption_Inferred.md`

## Callers / callees

| Direction | Targets |
|---|---|
| Callers (3) | `Client_ShowNpcMissionDialogUI` @ `0x0094397d`, `0x00943a75`; `FUN_009373e0` @ `0x00937411` |
| Callees | none direct FUN_*; virtual `+0x160` / `+0x1d8` / `+0x34c` only |

## Confidence

| Claim | Level |
|---|---|
| Control flow / ABI / offsets | **Confirmed** (live ≡ raw ≡ bytes) |
| 3-site caller framing | **Confirmed** |
| Product English / vtbl names | **Open** (`_Inferred`) |
| Runtime Confirmed | **Open** |
