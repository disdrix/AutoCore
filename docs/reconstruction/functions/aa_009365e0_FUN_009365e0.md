# Function record: Client_LoadVogIniConfig

| Field | Value |
|---|---|
| **Stable ID** | `aa_009365e0` |
| **Canonical name** | `Client_LoadVogIniConfig` |
| **Address** | `0x009365e0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | auth |
| **Completion status** | **String-renamed scaffold** - clean named twin + FUN_ retained; refine + dual review still open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Original / decompiler: `FUN_009365e0`
- Prior auto-slug names (if any): leave on disk; canonical is `Client_LoadVogIniConfig`

## Purpose

Parses VOG.ini (USERNAME/PASSWORD/AUTHSERVERIP/AUTHSERVERID/display mode, etc.).

## String evidence

`fopen("VOG.ini") / AUTHSERVERIP / AUTHSERVERID`

## Signature (decompiler-derived)

```c
void Client_LoadVogIniConfig(int param_1)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_009365e0_FUN_009365e0.md`
- Annotated: `docs/reconstruction/raw/aa_009365e0_FUN_009365e0.annotated.md`
- Clean (canonical): `docs/reconstruction/reconstructed-exact/Client_LoadVogIniConfig.cpp`
- Clean (FUN scaffold retained): `docs/reconstruction/reconstructed-exact/FUN_009365e0.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Naming from string literals | High |
| Parameter semantic names | Probable / Tentative |
| Types | Tentative |
