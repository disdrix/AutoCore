# Function record: GfxIndexBufferFactory_PostRestoreDevice

| Field | Value |
|---|---|
| **Stable ID** | `aa_00985610` |
| **Canonical name** | `GfxIndexBufferFactory_PostRestoreDevice` |
| **Ghidra name** | `FUN_00985610` |
| **Address** | `0x00985610`–`0x009857fb` exclusive (**491 B** / `0x1EB`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / Palantir graphics — `gfxIndexBufferFactory.cpp` |
| **Wave** | W38-AC |
| **Verdict** | **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Post-Reset `PostRestoreDevice` for the index-buffer factory: recreate D3D index buffers (`FUN_00743cd0` / `gfxDeviceIB.cpp`) and invoke restore-surface callbacks; return 0 or fail HRESULT; hard-abort on EH_Abort code 3.

## Signature

```c
// EAX = factory*; plain RET; EAX out = 0 / HRESULT < 0
int GfxIndexBufferFactory_PostRestoreDevice(void /*EAX*/);
```

## Product strings

| Line | Text |
|---|---|
| `0x180` | `Failed PostResoreDevice() on Index Buffers` |
| `400` | `RestoreSurfaceCallback Failed on Index Buffer (%d indices)` |

## Artifacts

- Raw / annotated / clean / twin / Ghidra function record — see `aa_00985610_FUN_00985610.md`
- A/B: `A_aa_00985610_GfxIndexBufferFactory_PostRestoreDevice.md`, `B_aa_00985610_GfxIndexBufferFactory_PostRestoreDevice.md`
