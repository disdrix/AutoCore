# Function record: Client_ShowDriverSitHumorMessages

| Field | Value |
|---|---|
| **Stable ID** | `aa_00951e70` |
| **Canonical name** | `Client_ShowDriverSitHumorMessages` |
| **Address** | `0x00951e70` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | input-drive-control |
| **Completion status** | **String-renamed scaffold** - clean named twin + FUN_ retained; refine + dual review still open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Original / decompiler: `FUN_00951e70`
- Prior auto-slug names (if any): leave on disk; canonical is `Client_ShowDriverSitHumorMessages`

## Purpose

Easter-egg / humor lines for redundant sit/exit/driver seat actions.

## String evidence

`"recline back in the driver's seat" / Wumpus exit humor`

## Signature (decompiler-derived)

```c
uint32_t /* width from decompiler */ __fastcall Client_ShowDriverSitHumorMessages(int param_1)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00951e70_FUN_00951e70.md`
- Annotated: `docs/reconstruction/raw/aa_00951e70_FUN_00951e70.annotated.md`
- Clean (canonical): `docs/reconstruction/reconstructed-exact/Client_ShowDriverSitHumorMessages.cpp`
- Clean (FUN scaffold retained): `docs/reconstruction/reconstructed-exact/FUN_00951e70.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Naming from string literals | High |
| Parameter semantic names | Probable / Tentative |
| Types | Tentative |
