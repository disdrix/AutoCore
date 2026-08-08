# Function record: Client_OnLocalCharacterReady_EnterWorldSetup_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_009430f0` |
| **Canonical name** | `Client_OnLocalCharacterReady_EnterWorldSetup_Inferred` |
| **Ghidra symbol** | `FUN_009430f0` |
| **Address** | `0x009430f0`–`0x009432eb` inclusive (**508 B** / `0x1FC`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client enter-world / local character ready |
| **Completion status** | **Dual sealed (R10-017)** — accept-with-gaps; Terminal false |
| **Bit-for-bit / runtime / diff** | Open |
| **Hash** | `1ad832af581bdcc60c4b4a75caf7bcfa85e02bf1830345b6fdc33c2df2316299` |

## Purpose

Main-client **local character ready / enter-world** orchestrator. After extended CreateCharacter for the local player (or dispatcher case 3 / queue type 0x1e):

1. Scan world-root objects (`FUN_004d9f00`).
2. Set environment active flag (`env+0x8c = 1`).
3. Configure camera/controller at `client+0xf38` (mode **6**, zoom **10.0f** or **~6.7f**).
4. Show first-time tips (0x19, 0x17, 0x31, optional 0x30 via CNDHash).
5. Refresh UI panels (`FUN_009301b0`).
6. Optionally send `//rejoinchat` via `FUN_00941fb0`.
7. Clear/set session flags (`DAT_00d1ad1c`, `client+0xb6/0xb7`).

## Signature

```c
// ESI = client/session host (register this); no stack args; bare RET
void Client_OnLocalCharacterReady_EnterWorldSetup_Inferred(void);
```

## Artifacts

- Raw (+ re-verify): `docs/reconstruction/raw/aa_009430f0_FUN_009430f0.md`
- Annotated: `docs/reconstruction/raw/aa_009430f0_FUN_009430f0.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/Client_OnLocalCharacterReady_EnterWorldSetup_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_009430f0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_009430f0_Client_OnLocalCharacterReady_EnterWorldSetup_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_009430f0_Client_OnLocalCharacterReady_EnterWorldSetup_Inferred.md`
- Scaffold twin: `docs/reconstruction/functions/aa_009430f0_FUN_009430f0.md`

## Callers / callees

| Direction | Target | Notes |
|---|---|---|
| Caller (1) | `Client_RecvCreateCharacter` @ `0x00814959` | extended local create path |
| Caller (2) | `FUN_00946c00` @ `0x00946ceb` | switch case 3 |
| Caller (3) | `FUN_00946c00` @ `0x009477ae` | queue type 0x1e |
| Callee | `FUN_004d9f00` | world-root enter scan |
| Callee | `FUN_004962b0` | optional gate |
| Callee | `FUN_00923c50` | camera enter setup |
| Callee | `Client_MaybeShowFirstTimeTip` | tips |
| Callee | `CNDHash_LookupByKey` | tip 0x30 gate |
| Callee | `FUN_009301b0` | UI panels |
| Callee | `FUN_00941fb0` | `//rejoinchat` |

## Constants

| Symbol | Value |
|---|---|
| `DAT_00a110d8` | 10.0f camera zoom |
| `DAT_00aaaccc` | ~6.7f camera zoom |
| tip ids | 0x19, 0x17, 0x31, 0x30 |
| camera mode | 6 @ `cam+0xcc4` |
| string | `"//rejoinchat"` @ `0x00a2cff8` |

## Confidence

| Claim | Level |
|---|---|
| Body size + bare RET + ESI=host | **Confirmed** (bytes + disasm) |
| Callers / xrefs | **Confirmed** |
| Float zoom constants | **Confirmed** (`read_memory`) |
| Product host/camera English | **Tentative** (`_Inferred`) |
| Undualed helper semantics | **Open** |
| Runtime | **Open** |
