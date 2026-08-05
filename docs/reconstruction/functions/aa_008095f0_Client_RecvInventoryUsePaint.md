# Function record: Client_RecvInventoryUsePaint

| Field | Value |
|---|---|
| **Stable ID** | `aa_008095f0` |
| **Canonical name** | `Client_RecvInventoryUsePaint` |
| **Address** | `0x008095f0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer |
| **Completion status** | **Human-refined** — annotated + clean upgraded; dual review still open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

S2C apply vehicle paint / color from inventory-use path. Resolves target TFID, requires clone type 0x0E (vehicle), then applies paint channel helpers and optional local refresh.

## Signature (refined)

```c
void Client_RecvInventoryUsePaint(int pGameState);  /* packet base residual in EDI */
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_008095f0_Client_RecvInventoryUsePaint.md`
- Annotated: `docs/reconstruction/raw/aa_008095f0_Client_RecvInventoryUsePaint.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Client_RecvInventoryUsePaint.cpp`

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Packet / UI offsets in notes | Probable–High |
| Types / names | Probable |
