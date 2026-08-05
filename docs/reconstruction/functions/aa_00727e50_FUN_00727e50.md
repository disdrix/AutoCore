# Function record: AuthClient_OnServerListFail

| Field | Value |
|---|---|
| **Stable ID** | `aa_00727e50` |
| **Canonical name** | `AuthClient_OnServerListFail` |
| **Address** | `0x00727e50` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | auth |
| **Completion status** | **String-renamed scaffold** - clean named twin + FUN_ retained; refine + dual review still open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Original / decompiler: `FUN_00727e50`
- Prior auto-slug names (if any): leave on disk; canonical is `AuthClient_OnServerListFail`

## Purpose

Inbound AuthServer ServerListFail handler - server list request failed.

## String evidence

`FUN_00727b70("ServerListFail","AuthServer")`

## Signature (decompiler-derived)

```c
uint32_t /* width from decompiler */ AuthClient_OnServerListFail(int param_1)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00727e50_FUN_00727e50.md`
- Annotated: `docs/reconstruction/raw/aa_00727e50_FUN_00727e50.annotated.md`
- Clean (canonical): `docs/reconstruction/reconstructed-exact/AuthClient_OnServerListFail.cpp`
- Clean (FUN scaffold retained): `docs/reconstruction/reconstructed-exact/FUN_00727e50.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Naming from string literals | High |
| Parameter semantic names | Probable / Tentative |
| Types | Tentative |
