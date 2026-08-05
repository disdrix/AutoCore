# Function record: Client_ShowVendorBuyFailureMessage

| Field | Value |
|---|---|
| **Stable ID** | `aa_0093c700` |
| **Canonical name** | `Client_ShowVendorBuyFailureMessage` |
| **Address** | `0x0093c700` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer |
| **Completion status** | **String-renamed scaffold** - clean named twin + FUN_ retained; refine + dual review still open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Original / decompiler: `FUN_0093c700`
- Prior auto-slug names (if any): leave on disk; canonical is `Client_ShowVendorBuyFailureMessage`

## Purpose

Vendor buy failure: stock, full inventory, or cannot afford.

## String evidence

`"Your Inventory is too full to buy this item."`

## Signature (decompiler-derived)

```c
uint32_t /* width from decompiler */ Client_ShowVendorBuyFailureMessage(int *param_1,int param_2)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0093c700_FUN_0093c700.md`
- Annotated: `docs/reconstruction/raw/aa_0093c700_FUN_0093c700.annotated.md`
- Clean (canonical): `docs/reconstruction/reconstructed-exact/Client_ShowVendorBuyFailureMessage.cpp`
- Clean (FUN scaffold retained): `docs/reconstruction/reconstructed-exact/FUN_0093c700.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Naming from string literals | High |
| Parameter semantic names | Probable / Tentative |
| Types | Tentative |
