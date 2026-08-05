# Function record: Client_NotifyActiveMissionChanged

| Field | Value |
|---|---|
| **Stable ID** | `aa_00944770` |
| **Canonical name** | `Client_NotifyActiveMissionChanged` |
| **Address** | `0x00944770` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Completion status** | **String-renamed scaffold** - clean named twin + FUN_ retained; refine + dual review still open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Original / decompiler: `FUN_00944770`
- Prior auto-slug names (if any): leave on disk; canonical is `Client_NotifyActiveMissionChanged`

## Purpose

Chat/toast when convoy leader changes the active mission.

## String evidence

`"has changed your active mission to" / "Your Convoy Leader"`

## Signature (decompiler-derived)

```c
void Client_NotifyActiveMissionChanged(void)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00944770_FUN_00944770.md`
- Annotated: `docs/reconstruction/raw/aa_00944770_FUN_00944770.annotated.md`
- Clean (canonical): `docs/reconstruction/reconstructed-exact/Client_NotifyActiveMissionChanged.cpp`
- Clean (FUN scaffold retained): `docs/reconstruction/reconstructed-exact/FUN_00944770.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Naming from string literals | High |
| Parameter semantic names | Probable / Tentative |
| Types | Tentative |
