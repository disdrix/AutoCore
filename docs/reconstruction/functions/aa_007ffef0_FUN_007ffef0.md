# Function record: FUN_007ffef0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007ffef0` |
| **Canonical name** | `FUN_007ffef0` |
| **Preferred name** | `Client_CombatChat_EmitEventLine_Inferred` |
| **Address** | `0x007ffef0`–`0x00800ad1` exclusive |
| **Body size** | **3041 B** (`0xBE1`); `ret 8` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | combat chat UI / skills residual consumer |
| **Completion status** | **Dual sealed** (WQ9D-I 2026-08-04) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

Human name: `Client_CombatChat_EmitEventLine_Inferred`  
Prior: `Named_CalleeOf_Named_CalleeOf_Named_VOGClient_007ffef0`

## Purpose

Client combat-event chat line formatter + `CDlgChatLog_AppendChannelMessage` sink (channels `0x10`–`0x16`). See named record for sealed facts.

## Signature (decompiler-derived)

```c
void FUN_007ffef0(int param_1, TFID_16 *param_2); // ret 8; param_2 is combat-event overlay
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_007ffef0_FUN_007ffef0.md`
- Annotated: `docs/reconstruction/raw/aa_007ffef0_FUN_007ffef0.annotated.md`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_007ffef0.cpp`
- Clean named: `docs/reconstruction/reconstructed-exact/Client_CombatChat_EmitEventLine_Inferred.cpp`
- Named record: `docs/reconstruction/functions/aa_007ffef0_Client_CombatChat_EmitEventLine_Inferred.md`
- Dual A/B: `docs/reconstruction/reviews/A_aa_007ffef0_Client_CombatChat_EmitEventLine_Inferred.md`, `B_aa_007ffef0_…`

## Callers / callees

| Direction | Targets |
|---|---|
| Callers (1) | `FUN_0093ffb0` |
| Callees | TFID helpers, `FUN_0040aff0`, `FUN_005749d0`, `FUN_007a69d0`, `FUN_007a6de0`, `sprintf`, `FUN_008f8200` |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | **Confirmed** (live ≡ raw) |
| Parameter semantic names | **High** host + event blob |
| Product name | **Inferred** |
