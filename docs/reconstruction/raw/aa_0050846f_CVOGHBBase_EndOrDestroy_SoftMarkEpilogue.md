# Raw named plate: CVOGHBBase_EndOrDestroy_SoftMarkEpilogue

| Field | Value |
|---|---|
| **Stable ID** | `aa_0050846f` |
| **VA** | `0x0050846f` |
| **Ghidra** | `FUN_0050846f` |
| **Canonical name** | `CVOGHBBase_EndOrDestroy_SoftMarkEpilogue` |
| **System** | heartbeat / CVOGHBBase |
| **Capture** | 2026-07-29 W21-B (named plate over 2026-07-23 scaffold) |

Authoritative decompile body lives in `raw/aa_0050846f_FUN_0050846f.md` (append-only).  
This plate records the inferred product name only.

## Signature (fragment)

```c
// No prologue. Live-in ESI=this, EBX=0, EBP=parent frame. Completes with ret 8.
void CVOGHBBase_EndOrDestroy_SoftMarkEpilogue(void);
```

## Semantics (one-liner)

Soft-mark `HB+0x20=1`, clear `HB+0x18`, restore ExceptionList, epilogue `ret 8`.
