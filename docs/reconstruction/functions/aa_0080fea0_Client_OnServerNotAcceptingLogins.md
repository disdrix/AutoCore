# Function record: Client_OnServerNotAcceptingLogins

| Field | Value |
|---|---|
| **Stable ID** | `aa_0080fea0` |
| **Canonical name** | `Client_OnServerNotAcceptingLogins` |
| **Address** | `0x0080fea0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | auth |
| **Completion status** | **String-renamed scaffold** - clean named twin + FUN_ retained; refine + dual review still open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Original / decompiler: `FUN_0080fea0`
- Prior auto-slug names (if any): leave on disk; canonical is `Client_OnServerNotAcceptingLogins`

## Purpose

S2C notify: server temporarily not accepting logins.

## String evidence

`"The server is not accepting logins at this time..."`

## Signature (decompiler-derived)

```c
void Client_OnServerNotAcceptingLogins(int param_1)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0080fea0_FUN_0080fea0.md`
- Annotated: `docs/reconstruction/raw/aa_0080fea0_FUN_0080fea0.annotated.md`
- Clean (canonical): `docs/reconstruction/reconstructed-exact/Client_OnServerNotAcceptingLogins.cpp`
- Clean (FUN scaffold retained): `docs/reconstruction/reconstructed-exact/FUN_0080fea0.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Naming from string literals | High |
| Parameter semantic names | Probable / Tentative |
| Types | Tentative |
