# Function record: Client_OnRefineryAddItemFailure

| Field | Value |
|---|---|
| **Stable ID** | `aa_0080a410` |
| **Canonical name** | `Client_OnRefineryAddItemFailure` |
| **Address** | `0x0080a410` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer |
| **Completion status** | **String-renamed scaffold** - clean named twin + FUN_ retained; refine + dual review still open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Original / decompiler: `FUN_0080a410`
- Prior auto-slug names (if any): leave on disk; canonical is `Client_OnRefineryAddItemFailure`

## Purpose

Refinery add-item failure messages when object missing from inventory.

## String evidence

`"Failed adding item to Refinery (object doesn't exist in inventory)."`

## Signature (decompiler-derived)

```c
void Client_OnRefineryAddItemFailure(void)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0080a410_FUN_0080a410.md`
- Annotated: `docs/reconstruction/raw/aa_0080a410_FUN_0080a410.annotated.md`
- Clean (canonical): `docs/reconstruction/reconstructed-exact/Client_OnRefineryAddItemFailure.cpp`
- Clean (FUN scaffold retained): `docs/reconstruction/reconstructed-exact/FUN_0080a410.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Naming from string literals | High |
| Parameter semantic names | Probable / Tentative |
| Types | Tentative |
