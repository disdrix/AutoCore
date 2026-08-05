# Function record: Client_OnReverseEngineerFailure

| Field | Value |
|---|---|
| **Stable ID** | `aa_0080df40` |
| **Canonical name** | `Client_OnReverseEngineerFailure` |
| **Address** | `0x0080df40` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer |
| **Completion status** | **String-renamed scaffold** - clean named twin + FUN_ retained; refine + dual review still open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Original / decompiler: `FUN_0080df40`
- Prior auto-slug names (if any): leave on disk; canonical is `Client_OnReverseEngineerFailure`

## Purpose

Reverse Engineer result messages: skill, inventory room, craft mats, generic fail.

## String evidence

`"You do not have enough room in your inventory." / Reverse Engineer`

## Signature (decompiler-derived)

```c
void Client_OnReverseEngineerFailure(int param_1,int param_2)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0080df40_FUN_0080df40.md`
- Annotated: `docs/reconstruction/raw/aa_0080df40_FUN_0080df40.annotated.md`
- Clean (canonical): `docs/reconstruction/reconstructed-exact/Client_OnReverseEngineerFailure.cpp`
- Clean (FUN scaffold retained): `docs/reconstruction/reconstructed-exact/FUN_0080df40.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Naming from string literals | High |
| Parameter semantic names | Probable / Tentative |
| Types | Tentative |
