# Function record: Client_CombatChat_EmitEventLine_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007ffef0` |
| **Canonical name** | `Client_CombatChat_EmitEventLine_Inferred` |
| **Ghidra name** | `FUN_007ffef0` |
| **Address** | `0x007ffef0`–`0x00800ad1` exclusive |
| **Body size** | **3041 B** (`0xBE1`); `ret 8` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | combat chat UI / skills residual consumer |
| **Completion status** | **Dual sealed** (WQ9D-I 2026-08-04) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (no Launcher; Terminal false) |

## Alias

- Human: `Client_CombatChat_EmitEventLine_Inferred`
- Prior scaffold: `Named_CalleeOf_Named_CalleeOf_Named_VOGClient_007ffef0` / `FUN_007ffef0`

## Purpose

Format combat-event actor/target/amount/flags into a localized chat line and append via `CDlgChatLog_AppendChannelMessage` with channels `0x10`–`0x16`. Relevance + crew filters suppress unrelated spam. Does not apply combat effects.

## Signature

```c
// two stack args; ret 8
void Client_CombatChat_EmitEventLine_Inferred(void* clientHost, void* combatEvent);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_007ffef0_FUN_007ffef0.md`
- Annotated: `docs/reconstruction/raw/aa_007ffef0_FUN_007ffef0.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/Client_CombatChat_EmitEventLine_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_007ffef0.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_007ffef0_Client_CombatChat_EmitEventLine_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_007ffef0_Client_CombatChat_EmitEventLine_Inferred.md`
- Scaffold record: `docs/reconstruction/functions/aa_007ffef0_FUN_007ffef0.md`

## Callers / callees

| Direction | Targets |
|---|---|
| Callers (1) | `FUN_0093ffb0` @ `0x00940e37` |
| Callees | `Object_ResolveFromTFID`, `TFID_EqualsObjectId`, `TFID_NotEquals`, `Object_CopyTfid16At228_Inferred`, `VehicleCrew_ContainsMember_Inferred`, `Locale_GetInstance_Inferred`, `StringPool_ApplyModeAndRingStore_Inferred`, `sprintf`, `CDlgChatLog_AppendChannelMessage` |

## Confidence

| Claim | Level |
|---|---|
| Control flow ≡ live decompile | **Confirmed** |
| ABI ret 8 / two stack args | **Confirmed** |
| Channel + string plate map | **Confirmed** |
| Product English name | **Inferred** |
