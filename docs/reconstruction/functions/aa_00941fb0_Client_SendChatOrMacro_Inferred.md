# Function record: Client_SendChatOrMacro_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00941fb0` |
| **Canonical name** | `Client_SendChatOrMacro_Inferred` |
| **Address** | `0x00941fb0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | chat / sector-broadcast |
| **Completion status** | **Human-refined** + dual A/B seal 2026-07-29 (opcode **0x2021** + dual wire paths); runtime open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Ghidra: `FUN_00941fb0`
- Prior scaffold: `Named_CalleeOf_Client_QuickBar_ActivateSlot_00941fb0`
- Product role: chat-line / chat-macro C2S builder (not combat power)

## Purpose

Build and send client chat:

- **Sector** `GameOpcode.Broadcast` **`0x2021`** via `Client_SendSectorPacket` (`client+0xc78`)
- **Global** `GameOpcode.Chat` **`0x8000`** via `FUN_008073b0` (`client+0xc7c`)

Selection is by `ChatType` and (for convoy) a character flag. Quick-bar type-5 macro banks and bound-action macro edges call this unit.

## Signature (listing-sealed)

```c
// MSVC: ECX = recipientName*, EDX = message*, stack: client*, chatType, doFilters
// Epilogue: ret 0x0C
int __fastcall Client_SendChatOrMacro_Inferred(
    char *recipientName,  /* ECX */
    char *message,        /* EDX */
    void *client,         /* [ebp+8]  */
    int chatType,         /* [ebp+0xc] */
    char doFilters        /* [ebp+0x10] */
);
```

## Behavioral notes (sealed)

1. Empty/null `message` → **`0x80070057`**.
2. Gate: `DAT_00af9218 & (1 << (chatType & 31))`; fail → `0`.
3. Dual stack packets prepared every successful entry:
   - **0x2021** buffer (sector) size on send = `strlen(message) + 0x29`
   - **0x8000** buffer (global) size on send = `strlen(message) + 0x31`
4. Type groups: `{1,2,4,13,14,15}` global; `{5,8,9,10}` sector; `{3}` convoy branch; `{6,7,11,12}` no-send.
5. Sector Coid: character multi-inherit adj `+0x164/+0x168` or `-1`.
6. Sector **Sender[17]** not written by this function.
7. Types 5/8/9/10 stamp `client+0x30e8` (tick) and `+0x30ec` (msgLen).

## Packet: sector `0x2021`

| Off | Field |
|----:|-------|
| `+0x00` | `u32` opcode `0x2021` |
| `+0x04` | `u32` ChatType |
| `+0x08` | `u64` SenderCoid |
| `+0x10` | `u8` IsGM `0` |
| `+0x11` | pad |
| `+0x12` | `i16` MessageLength |
| `+0x14` | `char[17]` Sender (**unwritten**) |
| `+0x25` | message + NUL |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00941fb0_FUN_00941fb0.md`
- Annotated: `docs/reconstruction/raw/aa_00941fb0_FUN_00941fb0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Client_SendChatOrMacro_Inferred.cpp`
- Dual reviews: `docs/reconstruction/reviews/A_aa_00941fb0_Client_SendChatOrMacro_Inferred.md`, `B_aa_*`
- Report: `docs/agents/task-dual-ab-00941fb0-send-chat-macro-report.md`

## Callers / callees

| Direction | Address / name | Notes |
|-----------|----------------|-------|
| Caller | `Client_QuickBar_ActivateSlot` `0x009436c0` | type-5 macro bank ×5 phrases |
| Caller | `Client_Input_PollBoundActions` `0x00925d60` | bound chat-macro edges |
| Caller | various UI/command helpers (`FUN_00942720`, `FUN_0094db40`, …) | incomplete parent decomp arg lists |
| Callee | `Client_SendSectorPacket` `0x00807460` | sector `0x2021` |
| Callee | `FUN_008073b0` `0x008073b0` | global `0x8000` |
| Callee | `FUN_0093bd10`, `FUN_00865970` | filter path when `doFilters` |

## Confidence

| Claim | Level |
|---|---|
| Opcode `0x2021` + size formula | **High** |
| Dual path + type map | **High** |
| ABI ECX/EDX+3 stack | **High** |
| Sector Sender fill | **Open** (not written) |
| Prefilter semantics | **Open** |
| Runtime | **Open** |
