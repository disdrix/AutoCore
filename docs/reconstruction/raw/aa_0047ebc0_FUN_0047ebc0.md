# Raw capture: FUN_0047ebc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0047ebc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0047ebc0` |
| **Canonical name** | `FUN_0047ebc0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0047ebc0(void)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(in_EAX + 0x16b4);
  *(ushort *)(in_EAX + 0x16b0) = *(ushort *)(in_EAX + 0x16b0) | (ushort)(2 << ((byte)iVar2 & 0x1f));
  if (iVar2 < 0xe) {
    *(int *)(in_EAX + 0x16b4) = iVar2 + 3;
  }
  else {
    *(undefined1 *)(*(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x14)) =
         *(undefined1 *)(in_EAX + 0x16b0);
    *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
    *(undefined1 *)(*(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 8)) =
         *(undefined1 *)(in_EAX + 0x16b1);
    iVar2 = *(int *)(in_EAX + 0x16b4);
    *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
    *(int *)(in_EAX + 0x16b4) = iVar2 + -0xd;
    *(ushort *)(in_EAX + 0x16b0) = 2 >> (0x10U - (char)iVar2 & 0x1f);
  }
  iVar2 = *(int *)(in_EAX + 0x16b4);
  *(ushort *)(in_EAX + 0x16b0) = *(ushort *)(in_EAX + 0x16b0) | (ushort)(0 << ((byte)iVar2 & 0x1f));
  if (iVar2 < 10) {
    *(int *)(in_EAX + 0x16b4) = iVar2 + 7;
  }
  else {
    *(undefined1 *)(*(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x14)) =
         *(undefined1 *)(in_EAX + 0x16b0);
    *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
    *(undefined1 *)(*(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 8)) =
         *(undefined1 *)(in_EAX + 0x16b1);
    iVar2 = *(int *)(in_EAX + 0x16b4);
    *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
    *(int *)(in_EAX + 0x16b4) = iVar2 + -9;
    *(ushort *)(in_EAX + 0x16b0) = 0 >> (0x10U - (char)iVar2 & 0x1f);
  }
  iVar1 = FUN_0047f440();
  iVar2 = *(int *)(iVar1 + 0x16b4);
  if ((*(int *)(iVar1 + 0x16ac) - iVar2) + 0xb < 9) {
    *(ushort *)(iVar1 + 0x16b0) = *(ushort *)(iVar1 + 0x16b0) | (ushort)(2 << ((byte)iVar2 & 0x1f));
    if (iVar2 < 0xe) {
      *(int *)(iVar1 + 0x16b4) = iVar2 + 3;
    }
    else {
      *(undefined1 *)(*(int *)(iVar1 + 8) + *(int *)(iVar1 + 0x14)) =
           *(undefined1 *)(iVar1 + 0x16b0);
      *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x14) + 1;
      *(undefined1 *)(*(int *)(iVar1 + 0x14) + *(int *)(iVar1 + 8)) =
           *(undefined1 *)(iVar1 + 0x16b1);
      iVar2 = *(int *)(iVar1 + 0x16b4);
      *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x14) + 1;
      *(int *)(iVar1 + 0x16b4) = iVar2 + -0xd;
      *(ushort *)(iVar1 + 0x16b0) = 2 >> (0x10U - (char)iVar2 & 0x1f);
    }
    iVar2 = *(int *)(iVar1 + 0x16b4);
    *(ushort *)(iVar1 + 0x16b0) = *(ushort *)(iVar1 + 0x16b0) | (ushort)(0 << ((byte)iVar2 & 0x1f));
    if (9 < iVar2) {
      *(undefined1 *)(*(int *)(iVar1 + 8) + *(int *)(iVar1 + 0x14)) =
           *(undefined1 *)(iVar1 + 0x16b0);
      *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x14) + 1;
      *(undefined1 *)(*(int *)(iVar1 + 0x14) + *(int *)(iVar1 + 8)) =
           *(undefined1 *)(iVar1 + 0x16b1);
      iVar2 = *(int *)(iVar1 + 0x16b4);
      *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x14) + 1;
      *(int *)(iVar1 + 0x16b4) = iVar2 + -9;
      *(ushort *)(iVar1 + 0x16b0) = 0 >> (0x10U - (char)iVar2 & 0x1f);
      iVar2 = FUN_0047f440();
      *(undefined4 *)(iVar2 + 0x16ac) = 7;
      return;
    }
    *(int *)(iVar1 + 0x16b4) = iVar2 + 7;
    iVar1 = FUN_0047f440();
  }
  *(undefined4 *)(iVar1 + 0x16ac) = 7;
  return;
}
```
