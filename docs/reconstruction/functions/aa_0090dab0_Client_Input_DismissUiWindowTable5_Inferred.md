# Function record: Client_Input_DismissUiWindowTable5_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0090dab0` |
| **Canonical name** | `Client_Input_DismissUiWindowTable5_Inferred` |
| **Ghidra name** | `FUN_0090dab0` |
| **Address** | `0x0090dab0`–`0x0090dad5` (**38 B** / `0x26`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | input-drive-control |
| **Partition** | MEGA-097 — Nested OnKeyDown helper; parent context `0x0090d390` |
| **Completion status** | **Dual sealed MEGA-097** — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (terminal false) |

## Purpose

On ESC UI-cancel, after any of the five global UI window slots is active (`FUN_0090d390`), walk `DAT_00d09a38[5]` and run `FUN_0090d400` per slot (dismiss-if-active + host notify). Custom **EAX = client host**.

## Signature

```c
// Custom EAX-this (not ECX thiscall). Bare RET.
void Client_Input_DismissUiWindowTable5_Inferred(void* /*eax*/ host);
```

## Semantics (sealed)

1. `EDI = EAX` (host).
2. `EBX = &DAT_00d09a38`.
3. Loop while `EBX < 0xd09a4c`: `ESI = *EBX`; `CALL FUN_0090d400`; `EBX += 4`.
4. Return void.

## Parent chain (evidence; parent not dualled here)

```text
Client_Input_OnKeyDown_MatchAction  0x00911030
  if client.vtbl+0x3d8() && key==0x1b:
    if *(client+0x50d)==0:
      *(client+0x50d)=1
      if FUN_0090d390() != 0:          // any active in table
        MOV EAX, EBX                   // host
        CALL Client_Input_DismissUiWindowTable5_Inferred
        return 1
```

## Table

| Slot VA | Init size (FUN_0093e7e0) |
|---|---|
| `DAT_00d09a38` | `0x554` |
| `DAT_00d09a3c` | `0x5d8` |
| `DAT_00d09a40` | `0x604` |
| `DAT_00d09a44` | `0x54c` |
| `DAT_00d09a48` | `0x588` |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0090dab0_FUN_0090dab0.md` |
| Annotated | `docs/reconstruction/raw/aa_0090dab0_FUN_0090dab0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_Input_DismissUiWindowTable5_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0090dab0.cpp` |
| FUN record | `docs/reconstruction/functions/aa_0090dab0_FUN_0090dab0.md` |
| Dual A | `docs/reconstruction/reviews/A_aa_0090dab0_Client_Input_DismissUiWindowTable5_Inferred.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_0090dab0_Client_Input_DismissUiWindowTable5_Inferred.md` |
| Report | `docs/agents/task-dual-ab-0090dab0-mega-097-report.md` |

## Gaps

1. Product English for each of the five window types.
2. Product names for dismiss/notify vtbl slots used by `FUN_0090d400`.
3. Runtime / bit-exact / differential.

## Confidence

| Claim | Level |
|---|---|
| CF / size / RET | **High** |
| EAX-host ABI + call-site reload | **High** |
| 5-slot table bounds | **High** |
| ESC dismiss role | **High** |
| Product names | **Low** |
