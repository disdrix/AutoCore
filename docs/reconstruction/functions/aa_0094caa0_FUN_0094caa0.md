# Function record: Client_ShowInventoryFullAcceptMessage

| Field | Value |
|---|---|
| **Stable ID** | `aa_0094caa0` |
| **Canonical name** | `Client_ShowInventoryFullAcceptMessage` |
| **Address** | `0x0094caa0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer |
| **Completion status** | **String-renamed scaffold** - clean named twin + FUN_ retained; refine + dual review still open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Original / decompiler: `FUN_0094caa0`
- Prior auto-slug names (if any): leave on disk; canonical is `Client_ShowInventoryFullAcceptMessage`

## Purpose

Toast when inventory cannot accept an offered/loot item.

## String evidence

`"Your inventory is too full to accept."`

## Signature (decompiler-derived)

```c
void Client_ShowInventoryFullAcceptMessage(void)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0094caa0_FUN_0094caa0.md`
- Annotated: `docs/reconstruction/raw/aa_0094caa0_FUN_0094caa0.annotated.md`
- Clean (canonical): `docs/reconstruction/reconstructed-exact/Client_ShowInventoryFullAcceptMessage.cpp`
- Clean (FUN scaffold retained): `docs/reconstruction/reconstructed-exact/FUN_0094caa0.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Naming from string literals | High |
| Parameter semantic names | Probable / Tentative |
| Types | Tentative |
