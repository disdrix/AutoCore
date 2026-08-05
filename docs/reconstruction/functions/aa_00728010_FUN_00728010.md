# Function record: AuthClient_OnPlayFail

| Field | Value |
|---|---|
| **Stable ID** | `aa_00728010` |
| **Canonical name** | `AuthClient_OnPlayFail` |
| **Address** | `0x00728010` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | auth |
| **Completion status** | **String-renamed scaffold** - clean named twin + FUN_ retained; refine + dual review still open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Original / decompiler: `FUN_00728010`
- Prior auto-slug names (if any): leave on disk; canonical is `AuthClient_OnPlayFail`

## Purpose

Inbound AuthServer PlayFail handler - play/session request rejected.

## String evidence

`FUN_00727b70("PlayFail","AuthServer")`

## Signature (decompiler-derived)

```c
uint32_t /* width from decompiler */ AuthClient_OnPlayFail(int param_1)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00728010_FUN_00728010.md`
- Annotated: `docs/reconstruction/raw/aa_00728010_FUN_00728010.annotated.md`
- Clean (canonical): `docs/reconstruction/reconstructed-exact/AuthClient_OnPlayFail.cpp`
- Clean (FUN scaffold retained): `docs/reconstruction/reconstructed-exact/FUN_00728010.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Naming from string literals | High |
| Parameter semantic names | Probable / Tentative |
| Types | Tentative |
