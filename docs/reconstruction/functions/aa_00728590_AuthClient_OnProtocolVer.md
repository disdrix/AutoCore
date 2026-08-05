# Function record: AuthClient_OnProtocolVer

| Field | Value |
|---|---|
| **Stable ID** | `aa_00728590` |
| **Canonical name** | `AuthClient_OnProtocolVer` |
| **Address** | `0x00728590` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | auth |
| **Completion status** | **String-renamed scaffold** - clean named twin + FUN_ retained; refine + dual review still open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Original / decompiler: `FUN_00728590`
- Prior auto-slug names (if any): leave on disk; canonical is `AuthClient_OnProtocolVer`

## Purpose

Inbound AuthServer ProtocolVer handler - protocol version negotiation.

## String evidence

`FUN_00727b70("ProtocolVer","AuthServer")`

## Signature (decompiler-derived)

```c
uint32_t /* width from decompiler */ __fastcall AuthClient_OnProtocolVer(int param_1,int param_2)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00728590_FUN_00728590.md`
- Annotated: `docs/reconstruction/raw/aa_00728590_FUN_00728590.annotated.md`
- Clean (canonical): `docs/reconstruction/reconstructed-exact/AuthClient_OnProtocolVer.cpp`
- Clean (FUN scaffold retained): `docs/reconstruction/reconstructed-exact/FUN_00728590.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Naming from string literals | High |
| Parameter semantic names | Probable / Tentative |
| Types | Tentative |
