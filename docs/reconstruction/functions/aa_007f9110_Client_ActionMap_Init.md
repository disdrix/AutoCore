# Function record: Client_ActionMap_Init

| Field | Value |
|---|---|
| **Stable ID** | `aa_007f9110` |
| **Canonical name** | `Client_ActionMap_Init` |
| **Address** | `0x007f9110` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | input-drive-control |
| **Completion status** | **Human-refined partial** — sectioned zero-fill + callee chain; dual review not required (thin wrapper) |
| **Bit-for-bit / runtime / diff** | Open |
| **Last refined** | 2026-07-23 |

## Purpose

ActionMap ctor/init: install vtable, zero table regions, call display-name fill then default keybinds, clear status byte `+0x5`.

## Signature

```c
void Client_ActionMap_Init(void)
// ActionMap* arrives in ESI (decomp unaff_ESI → pActionMap)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_007f9110_Client_ActionMap_Init.md`
- Annotated: `docs/reconstruction/raw/aa_007f9110_Client_ActionMap_Init.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Client_ActionMap_Init.cpp`

## Callers / callees

| Dir | Symbol | VA |
|---|---|---|
| Caller | `FUN_009495c0` (bootstrap) | open name |
| Callee | `Client_InitActionDisplayNames` | `0x007f7570` |
| Callee | `Client_InitDefaultKeybinds` | `0x007f8720` |

## Confidence

| Claim | Level |
|---|---|
| Zero-fill loop counts / bases | High |
| Callee order | High |
| Vtable `PTR_LAB_00a84e08` | High (pointer), semantics open |
| Status byte `+0x5` meaning | Tentative |
