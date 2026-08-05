# Function record: Client_OnRefineryRemoveItemFailure

| Field | Value |
|---|---|
| **Stable ID** | `aa_0080e360` |
| **Canonical name** | `Client_OnRefineryRemoveItemFailure` |
| **Address** | `0x0080e360` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer |
| **Completion status** | **String-renamed scaffold** - clean named twin + FUN_ retained; refine + dual review still open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Original / decompiler: `FUN_0080e360`
- Prior auto-slug names (if any): leave on disk; canonical is `Client_OnRefineryRemoveItemFailure`

## Purpose

Refinery remove-item failure: no space / not found / cannot re-add to inventory.

## String evidence

`"Failed removing item from refinery..." inventory messages`

## Signature (decompiler-derived)

```c
void Client_OnRefineryRemoveItemFailure(void)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0080e360_FUN_0080e360.md`
- Annotated: `docs/reconstruction/raw/aa_0080e360_FUN_0080e360.annotated.md`
- Clean (canonical): `docs/reconstruction/reconstructed-exact/Client_OnRefineryRemoveItemFailure.cpp`
- Clean (FUN scaffold retained): `docs/reconstruction/reconstructed-exact/FUN_0080e360.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Naming from string literals | High |
| Parameter semantic names | Probable / Tentative |
| Types | Tentative |
