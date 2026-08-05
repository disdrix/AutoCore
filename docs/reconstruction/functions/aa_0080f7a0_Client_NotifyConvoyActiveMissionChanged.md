# Function record: Client_NotifyConvoyActiveMissionChanged

| Field | Value |
|---|---|
| **Stable ID** | `aa_0080f7a0` |
| **Canonical name** | `Client_NotifyConvoyActiveMissionChanged` |
| **Address** | `0x0080f7a0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Completion status** | **String-renamed scaffold** - clean named twin + FUN_ retained; refine + dual review still open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Original / decompiler: `FUN_0080f7a0`
- Prior auto-slug names (if any): leave on disk; canonical is `Client_NotifyConvoyActiveMissionChanged`

## Purpose

Alternate path for convoy-leader active-mission change notification.

## String evidence

`"has changed your active mission to" / "Your Convoy Leader"`

## Signature (decompiler-derived)

```c
void Client_NotifyConvoyActiveMissionChanged(int param_1)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0080f7a0_FUN_0080f7a0.md`
- Annotated: `docs/reconstruction/raw/aa_0080f7a0_FUN_0080f7a0.annotated.md`
- Clean (canonical): `docs/reconstruction/reconstructed-exact/Client_NotifyConvoyActiveMissionChanged.cpp`
- Clean (FUN scaffold retained): `docs/reconstruction/reconstructed-exact/FUN_0080f7a0.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Naming from string literals | High |
| Parameter semantic names | Probable / Tentative |
| Types | Tentative |
