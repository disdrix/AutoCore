# Function record: FillPreloadList

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f2540` |
| **Canonical name** | `FillPreloadList` |
| **Ghidra name** | `FUN_004f2540` |
| **Address** | `0x004f2540`–`0x004f26d5` (**406 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client-load / preload pipeline |
| **Completion status** | **Dual reviewed (W32-L)** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open |

See twin record `aa_004f2540_FUN_004f2540.md` for full callers/callees and confidence tables.

## Signature (sealed)

```c
uint8_t __fastcall FillPreloadList(void* self /*ECX*/);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004f2540_FUN_004f2540.md`
- Annotated: `docs/reconstruction/raw/aa_004f2540_FUN_004f2540.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FillPreloadList.cpp`
- Review A/B: `docs/reconstruction/reviews/A_aa_004f2540_FillPreloadList.md`, `B_aa_004f2540_FillPreloadList.md`
