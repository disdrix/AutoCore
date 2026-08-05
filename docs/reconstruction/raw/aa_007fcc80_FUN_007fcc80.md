# Raw capture: FUN_007fcc80

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fcc80` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007fcc80` |
| **Canonical name** | `FUN_007fcc80` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_007fcc80(int param_1)

{
  int iVar1;
  int iVar2;
  int in_EAX;
  int *piVar3;
  int iVar4;
  int *unaff_EBX;
  int iVar5;
  float fVar6;
  
  iVar2 = DAT_00a1e868;
  if (*(int *)(in_EAX + 0xde8) == 0) {
    *unaff_EBX = DAT_00a1e868;
    unaff_EBX[1] = DAT_00a1e86c;
    return;
  }
  if (param_1 != 0) {
    if (param_1 != 1) {
      *unaff_EBX = DAT_00a1e868;
      unaff_EBX[1] = DAT_00a1e86c;
      return;
    }
    iVar5 = *(int *)(*(int *)(in_EAX + 0xde8) + 0x2c);
    iVar4 = *(int *)(iVar5 + 0x80);
    iVar5 = *(int *)(iVar5 + 0x84);
    if (*(char *)(in_EAX + 0xa24) == '\0') {
      piVar3 = (int *)FUN_007aa3e0();
      iVar4 = *piVar3;
      iVar5 = piVar3[1];
    }
    else {
      iVar1 = iVar4 * 3;
      if (iVar5 * 4 < iVar1) {
        iVar4 = (iVar5 * 4) / 3;
      }
      else {
        iVar5 = (int)(iVar1 + (iVar1 >> 0x1f & 3U)) >> 2;
      }
      if ((799 < iVar4) && (599 < iVar5)) {
        fVar6 = *(float *)(in_EAX + 0xa20) + g_flOne;
        iVar4 = (int)((float)iVar4 * fVar6 * DAT_00a0f298);
        iVar5 = (int)((float)iVar5 * fVar6 * DAT_00a0f298);
        if ((iVar4 < 800) || (iVar5 < 600)) {
          unaff_EBX[1] = DAT_00a1e86c;
          *unaff_EBX = iVar2;
          return;
        }
      }
    }
    unaff_EBX[1] = iVar5;
    *unaff_EBX = iVar4;
    return;
  }
  FUN_007aa3e0();
  return;
}
```
