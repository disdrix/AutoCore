# Raw capture: FUN_0074bfb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0074bfb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0074bfb0` |
| **Canonical name** | `FUN_0074bfb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 FUN_0074bfb0(void)

{
  float *pfVar1;
  int unaff_EBX;
  float *unaff_ESI;
  
  pfVar1 = (float *)FUN_00972fa0(unaff_EBX);
  if ((pfVar1[2] - unaff_ESI[2]) * (pfVar1[2] - unaff_ESI[2]) +
      (*pfVar1 - *unaff_ESI) * (*pfVar1 - *unaff_ESI) +
      (pfVar1[1] - unaff_ESI[1]) * (pfVar1[1] - unaff_ESI[1]) <=
      *(float *)(unaff_EBX + 0xc) * *(float *)(unaff_EBX + 0xc)) {
    return 1;
  }
  return 0;
}
```
