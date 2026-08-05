# Function record: Client_ShowMissionRewardChatToast

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ac540` |
| **Canonical name** | `Client_ShowMissionRewardChatToast` |
| **Address** | `0x008ac540` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Completion status** | **Human-refined** — annotated + clean upgraded; dual review still open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

After mission turn-in: format XP/credits chat lines ('Awarded N …', 'Earned N clink', or already-received) and push to chat UI.

## Signature (refined)

```c
void Client_ShowMissionRewardChatToast(void *pObjective);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_008ac540_Client_ShowMissionRewardChatToast.md`
- Annotated: `docs/reconstruction/raw/aa_008ac540_Client_ShowMissionRewardChatToast.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Client_ShowMissionRewardChatToast.cpp`

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Packet / UI offsets in notes | Probable–High |
| Types / names | Probable |
