# Function record: AuthClient_SendServerListEx

| Field | Value |
|---|---|
| **Stable ID** | `aa_00728840` |
| **Canonical name** | `AuthClient_SendServerListEx` |
| **Address** | `0x00728840` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | auth |
| **Completion status** | **String-renamed scaffold** - clean named twin + FUN_ retained; refine + dual review still open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Original / decompiler: `FUN_00728840`
- Prior auto-slug names (if any): leave on disk; canonical is `AuthClient_SendServerListEx`

## Purpose

Outbound AuthServer ServerListEx request - ask for extended server list.

## String evidence

`FUN_00727b70("ServerListEx","AuthServer")`

## Signature (decompiler-derived)

```c
uint32_t /* width from decompiler */ AuthClient_SendServerListEx(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00728840_FUN_00728840.md`
- Annotated: `docs/reconstruction/raw/aa_00728840_FUN_00728840.annotated.md`
- Clean (canonical): `docs/reconstruction/reconstructed-exact/AuthClient_SendServerListEx.cpp`
- Clean (FUN scaffold retained): `docs/reconstruction/reconstructed-exact/FUN_00728840.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Naming from string literals | High |
| Parameter semantic names | Probable / Tentative |
| Types | Tentative |
