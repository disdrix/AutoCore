# Function record: Client_BuildInterfaceOptionsDialog

| Field | Value |
|---|---|
| **Stable ID** | `aa_0081c4d0` |
| **Canonical name** | `Client_BuildInterfaceOptionsDialog` |
| **Address** | `0x0081c4d0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities |
| **Completion status** | **String-renamed scaffold** - clean named twin + FUN_ retained; refine + dual review still open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Original / decompiler: `FUN_0081c4d0`
- Prior auto-slug names (if any): leave on disk; canonical is `Client_BuildInterfaceOptionsDialog`

## Purpose

Builds interface options UI (quickbar drag-shift, auto-set new mission active, etc.).

## String evidence

`"Quickbar Drag Requires Shift" / "Auto-set New Mission Active" / widget xml`

## Signature (decompiler-derived)

```c
void __fastcall Client_BuildInterfaceOptionsDialog(int *param_1)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0081c4d0_FUN_0081c4d0.md`
- Annotated: `docs/reconstruction/raw/aa_0081c4d0_FUN_0081c4d0.annotated.md`
- Clean (canonical): `docs/reconstruction/reconstructed-exact/Client_BuildInterfaceOptionsDialog.cpp`
- Clean (FUN scaffold retained): `docs/reconstruction/reconstructed-exact/FUN_0081c4d0.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Naming from string literals | High |
| Parameter semantic names | Probable / Tentative |
| Types | Tentative |
