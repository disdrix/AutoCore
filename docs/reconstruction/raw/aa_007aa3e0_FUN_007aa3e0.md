# Raw capture: FUN_007aa3e0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007aa3e0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007aa3e0` |
| **Canonical name** | `FUN_007aa3e0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_007aa3e0(void)

{
  int iVar1;
  int *in_EAX;
  int iVar2;
  int iVar3;
  int *unaff_EDI;
  
  iVar2 = *in_EAX;
  if ((iVar2 < 0x280) || (iVar3 = in_EAX[1], iVar3 < 0x1e0)) {
    *unaff_EDI = DAT_00a1e888;
    unaff_EDI[1] = DAT_00a1e88c;
    return;
  }
  iVar1 = iVar2 * 3;
  if (iVar3 * 4 < iVar1) {
    iVar2 = (iVar3 * 4) / 3;
  }
  else {
    iVar3 = (int)(iVar1 + (iVar1 >> 0x1f & 3U)) >> 2;
  }
  if ((iVar2 < 0x641) && (iVar3 < 0x4b1)) {
    unaff_EDI[1] = iVar3;
    *unaff_EDI = iVar2;
    return;
  }
  *unaff_EDI = DAT_00a1e8a8;
  unaff_EDI[1] = DAT_00a1e8ac;
  return;
}
```
