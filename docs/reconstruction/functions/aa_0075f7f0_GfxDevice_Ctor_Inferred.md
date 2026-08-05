# Function record (named): GfxDevice_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0075f7f0` |
| **Semantic name** | `GfxDevice_Ctor_Inferred` |
| **Ghidra name** | `FUN_0075f7f0` |
| **Address** | `0x0075f7f0`–`0x0075fb87` exclusive (**919 B** / `0x397`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / Palantir graphics device host |
| **Naming basis** | Sole factory arm of gfxAdapter CreateDevice path (`operator_new(0x7b0)`); seeds `DAT_00d1f624` PoolHost + NestedHash 0x30 slot; structural device host for D3D9 |
| **Status** | Dual sealed W35-R (**accept-with-gaps**) |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

See dual report W35-R and scaffold `aa_0075f7f0_FUN_0075f7f0.md`.

## Signature

```c
// ECX = IDirect3D9*; stack self* + IDirect3DDevice9*; RET 8; returns self
void *__thiscall GfxDevice_Ctor_Inferred(void *d3d9, void *self, void *device9);
```

## Artifacts

- Raw / annotated / clean / twin / scaffold record / A+B reviews — see dual report W35-R.
