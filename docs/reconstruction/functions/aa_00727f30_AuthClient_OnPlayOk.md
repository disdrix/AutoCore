# Function record: AuthClient_OnPlayOk

| Field | Value |
|---|---|
| **Stable ID** | `aa_00727f30` |
| **Canonical name** | `AuthClient_OnPlayOk` |
| **Address** | `0x00727f30` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | auth |
| **Completion status** | **String-renamed scaffold** - clean named twin + FUN_ retained; refine + dual review still open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Original / decompiler: `FUN_00727f30`
- Prior auto-slug names (if any): leave on disk; canonical is `AuthClient_OnPlayOk`

## Purpose

Inbound AuthServer PlayOk handler - character/play session approved.

## String evidence

`FUN_00727b70("PlayOk","AuthServer")`

## Signature (decompiler-derived)

```c
uint32_t /* width from decompiler */ AuthClient_OnPlayOk(int param_1)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00727f30_FUN_00727f30.md`
- Annotated: `docs/reconstruction/raw/aa_00727f30_FUN_00727f30.annotated.md`
- Clean (canonical): `docs/reconstruction/reconstructed-exact/AuthClient_OnPlayOk.cpp`
- Clean (FUN scaffold retained): `docs/reconstruction/reconstructed-exact/FUN_00727f30.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Naming from string literals | High |
| Parameter semantic names | Probable / Tentative |
| Types | Tentative |
