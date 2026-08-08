# Function record: FUN_0090dab0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0090dab0` |
| **Canonical name** | `FUN_0090dab0` |
| **Named alias** | `Client_Input_DismissUiWindowTable5_Inferred` |
| **Address** | `0x0090dab0`–`0x0090dad5` (**38 B** / `0x26`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | input-drive-control |
| **Completion status** | **Dual sealed MEGA-097** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (terminal false; no Launcher) |

## Alias

- Human: `Client_Input_DismissUiWindowTable5_Inferred`
- Retired scaffold: `Named_CalleeOf_Client_Input_OnKeyDown_MatchAction_0090dab0`

## Purpose

ESC UI-cancel nested helper of `Client_Input_OnKeyDown_MatchAction`: walk 5-slot global UI window table `DAT_00d09a38` and dismiss each active window via `FUN_0090d400`, notifying the client host in **EAX**.

## Signature (disasm-sealed)

```c
// EAX = client host*; no stack args; bare RET
void FUN_0090dab0(void /* host in EAX */);
```

| Formal | Source | Conf |
|---|---|---|
| host | EAX → EDI | High |
| stack | none | High |
| return | void (`C3`) | High |

## Artifacts

- Raw (+ MEGA-097 re-verify): `docs/reconstruction/raw/aa_0090dab0_FUN_0090dab0.md`
- Annotated: `docs/reconstruction/raw/aa_0090dab0_FUN_0090dab0.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/Client_Input_DismissUiWindowTable5_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0090dab0.cpp`
- Named record: `docs/reconstruction/functions/aa_0090dab0_Client_Input_DismissUiWindowTable5_Inferred.md`
- Dual A: `docs/reconstruction/reviews/A_aa_0090dab0_Client_Input_DismissUiWindowTable5_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0090dab0_Client_Input_DismissUiWindowTable5_Inferred.md`

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `Client_Input_OnKeyDown_MatchAction` @ `0x00911030` (xrefs `0x00911075`, `0x00911893`) |
| Callees | `FUN_0090d400` @ `0x0090d400` |

## Confidence

| Claim | Level |
|---|---|
| Control flow (5-slot walk + call) | **High** |
| ABI EAX-host / bare RET | **High** |
| Table bounds / count 5 | **High** |
| ESC parent role | **High** |
| Product window / vtbl English | **Low** (gaps) |
| Runtime | **Open** |
