# Function record: AuthClient_OnLoginOk

| Field | Value |
|---|---|
| **Stable ID** | `aa_007280f0` |
| **Canonical name** | `AuthClient_OnLoginOk` |
| **Address** | `0x007280f0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | auth |
| **Completion status** | **String-renamed scaffold** - clean named twin + FUN_ retained; refine + dual review still open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Original / decompiler: `FUN_007280f0`
- Prior auto-slug names (if any): leave on disk; canonical is `AuthClient_OnLoginOk`

## Purpose

Inbound AuthServer LoginOk handler - credentials accepted.

## String evidence

`FUN_00727b70("LoginOk","AuthServer")`

## Signature (decompiler-derived)

```c
uint32_t /* width from decompiler */ __thiscall AuthClient_OnLoginOk(int param_1,int param_2)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_007280f0_FUN_007280f0.md`
- Annotated: `docs/reconstruction/raw/aa_007280f0_FUN_007280f0.annotated.md`
- Clean (canonical): `docs/reconstruction/reconstructed-exact/AuthClient_OnLoginOk.cpp`
- Clean (FUN scaffold retained): `docs/reconstruction/reconstructed-exact/FUN_007280f0.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Naming from string literals | High |
| Parameter semantic names | Probable / Tentative |
| Types | Tentative |
