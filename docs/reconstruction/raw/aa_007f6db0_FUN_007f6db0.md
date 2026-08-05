# Raw capture: FUN_007f6db0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007f6db0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007f6db0` |
| **Canonical name** | `FUN_007f6db0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int __fastcall FUN_007f6db0(undefined4 param_1,short param_2)

{
  undefined4 in_EAX;
  short *psVar1;
  int iVar2;
  short unaff_SI;
  int unaff_EDI;
  
  switch(in_EAX) {
  case 0:
    iVar2 = 0;
    psVar1 = (short *)(unaff_EDI + 0x30);
    do {
      if (psVar1[-0x15] == unaff_SI) {
        if (param_2 == 0) {
          if (*psVar1 == 0) goto LAB_007f6dd2;
        }
        else if (*psVar1 != 0) goto LAB_007f6dd2;
        if ((char)psVar1[3] != '\0') {
LAB_007f6dd2:
          return unaff_EDI + 6 + iVar2 * 0x34;
        }
      }
      if (psVar1[-0x14] == unaff_SI) {
        if (param_2 == 0) {
          if (psVar1[1] == 0) goto LAB_007f6e02;
        }
        else if (psVar1[1] != 0) goto LAB_007f6e02;
        if ((char)psVar1[3] != '\0') {
LAB_007f6e02:
          return unaff_EDI + 6 + iVar2 * 0x34;
        }
      }
      iVar2 = iVar2 + 1;
      psVar1 = psVar1 + 0x1a;
    } while (iVar2 < 5);
    break;
  case 1:
    iVar2 = 0;
    psVar1 = (short *)(unaff_EDI + 0x134);
    do {
      if (psVar1[-0x15] == unaff_SI) {
        if (param_2 == 0) {
          if (*psVar1 == 0) goto LAB_007f6e48;
        }
        else if (*psVar1 != 0) goto LAB_007f6e48;
        if ((char)psVar1[3] != '\0') {
LAB_007f6e48:
          return unaff_EDI + 0x10a + iVar2 * 0x34;
        }
      }
      if (psVar1[-0x14] == unaff_SI) {
        if (param_2 == 0) {
          if (psVar1[1] == 0) goto LAB_007f6e7b;
        }
        else if (psVar1[1] != 0) goto LAB_007f6e7b;
        if ((char)psVar1[3] != '\0') {
LAB_007f6e7b:
          return unaff_EDI + 0x10a + iVar2 * 0x34;
        }
      }
      iVar2 = iVar2 + 1;
      psVar1 = psVar1 + 0x1a;
      if (5 < iVar2) {
        return 0;
      }
    } while( true );
  case 2:
    iVar2 = 0;
    psVar1 = (short *)(unaff_EDI + 0x26c);
    do {
      if (psVar1[-0x15] == unaff_SI) {
        if (param_2 == 0) {
          if (*psVar1 == 0) goto LAB_007f6ec4;
        }
        else if (*psVar1 != 0) goto LAB_007f6ec4;
        if ((char)psVar1[3] != '\0') {
LAB_007f6ec4:
          return unaff_EDI + 0x242 + iVar2 * 0x34;
        }
      }
      if (psVar1[-0x14] == unaff_SI) {
        if (param_2 == 0) {
          if (psVar1[1] == 0) goto LAB_007f6ef7;
        }
        else if (psVar1[1] != 0) goto LAB_007f6ef7;
        if ((char)psVar1[3] != '\0') {
LAB_007f6ef7:
          return unaff_EDI + 0x242 + iVar2 * 0x34;
        }
      }
      iVar2 = iVar2 + 1;
      psVar1 = psVar1 + 0x1a;
      if (0x77 < iVar2) {
        return 0;
      }
    } while( true );
  case 3:
    iVar2 = 0;
    psVar1 = (short *)(unaff_EDI + 0x1acc);
    do {
      if (psVar1[-0x15] == unaff_SI) {
        if (param_2 == 0) {
          if (*psVar1 == 0) goto LAB_007f6f41;
        }
        else if (*psVar1 != 0) goto LAB_007f6f41;
        if ((char)psVar1[3] != '\0') {
LAB_007f6f41:
          return unaff_EDI + 0x1aa2 + iVar2 * 0x34;
        }
      }
      if (psVar1[-0x14] == unaff_SI) {
        if (param_2 == 0) {
          if (psVar1[1] == 0) goto LAB_007f6f74;
        }
        else if (psVar1[1] != 0) goto LAB_007f6f74;
        if ((char)psVar1[3] != '\0') {
LAB_007f6f74:
          return unaff_EDI + 0x1aa2 + iVar2 * 0x34;
        }
      }
      iVar2 = iVar2 + 1;
      psVar1 = psVar1 + 0x1a;
      if (0x13 < iVar2) {
        return 0;
      }
    } while( true );
  }
  return 0;
}
```
