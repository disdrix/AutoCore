# Function record: Client_WriteJoyCustomIni

| Field | Value |
|---|---|
| **Stable ID** | `aa_0081e700` |
| **Canonical name** | `Client_WriteJoyCustomIni` |
| **Address** | `0x0081e700` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | input-drive-control |
| **Completion status** | **String-renamed scaffold** - clean named twin + FUN_ retained; refine + dual review still open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Original / decompiler: `FUN_0081e700`
- Prior auto-slug names (if any): leave on disk; canonical is `Client_WriteJoyCustomIni`

## Purpose

Writes joy_custom.ini template including Drive axes and QuickBarNext/Prev/Use/Page.

## String evidence

`"joy_custom.ini" / QuickBarNext / Accelerate / Reverse`

## Signature (decompiler-derived)

```c
void Client_WriteJoyCustomIni(int param_1)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0081e700_FUN_0081e700.md`
- Annotated: `docs/reconstruction/raw/aa_0081e700_FUN_0081e700.annotated.md`
- Clean (canonical): `docs/reconstruction/reconstructed-exact/Client_WriteJoyCustomIni.cpp`
- Clean (FUN scaffold retained): `docs/reconstruction/reconstructed-exact/FUN_0081e700.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Naming from string literals | High |
| Parameter semantic names | Probable / Tentative |
| Types | Tentative |
