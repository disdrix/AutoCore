# Function record: Client_RecvInventoryUseItemResponse

| Field | Value |
|---|---|
| **Stable ID** | `aa_00810280` |
| **Canonical name** | `Client_RecvInventoryUseItemResponse` |
| **Address** | `0x00810280` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer |
| **Completion status** | **Human-refined** — annotated + clean upgraded; dual review still open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

S2C use-item response: either consume/update stack counts on resolved item, or run failure UI path. Refreshes open mission windows and optional crafting/use UI.

## Signature (refined)

```c
void Client_RecvInventoryUseItemResponse(int pGameState);  /* packet residual ESI */
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00810280_Client_RecvInventoryUseItemResponse.md`
- Annotated: `docs/reconstruction/raw/aa_00810280_Client_RecvInventoryUseItemResponse.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Client_RecvInventoryUseItemResponse.cpp`

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Packet / UI offsets in notes | Probable–High |
| Types / names | Probable |
