# Function record: CVOGDialog_Ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0087b890` |
| **Canonical name** | `CVOGDialog_Ctor` |
| **Ghidra symbol** | `FUN_0087b890` |
| **Address** | `0x0087b890`–`0x0087b905` (**118 B** / `0x76`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression (partition parent `0x008ac3f0`); shared CVOGDialog base |
| **RTTI** | `.?AVCVOGDialog@@` @ type_info `0x00af8e50` (COL `0x00ab4984`) |
| **Vtbl** | `PTR_FUN_00a58c6c` @ `0x00a58c6c` |
| **Completion status** | **Dual complete (R11-030)** — A/B **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open; Terminal **false** |

## Purpose

Product-class constructor for **CVOGDialog**. Chains CNDUIDialog base ctor `FUN_00792d20`, clears a small mode/flag pack (including overriding base byte `+0x490` from 1→0), installs CVOGDialog vtbl, stores ctor arg at `+0x2A4`. Shared foundation for mission NPC dialog host and many other client dialogs.

## Signature

```c
CVOGDialog* __stdcall CVOGDialog_Ctor(CVOGDialog* self, uint32_t param_2);
// RET 8; returns self in EAX
```

## Sealed field writes

| Offset | Value |
|---|---|
| `+0x00` | vtbl `0x00a58c6c` |
| `+0x2A4` | `param_2` |
| `+0xBF` | byte `0` |
| `+0x490` | byte `0` |
| `+0x4FC`…`+0x508` | dword zeros |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0087b890_FUN_0087b890.md` |
| Annotated | `docs/reconstruction/raw/aa_0087b890_FUN_0087b890.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGDialog_Ctor.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0087b890.cpp` |
| Dual A | `docs/reconstruction/reviews/A_aa_0087b890_CVOGDialog_Ctor.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_0087b890_CVOGDialog_Ctor.md` |
| Ghidra record | `docs/reconstruction/functions/aa_0087b890_FUN_0087b890.md` |
| Report | `docs/agents/task-dual-ab-0087b890-r11-report.md` |

## Confidence

| Claim | Level |
|---|---|
| Role = CVOGDialog ctor | **High** (RTTI + vtbl + base chain) |
| ABI / CF | **High** |
| param_2 English | **None** |
| Runtime | **Open** |
