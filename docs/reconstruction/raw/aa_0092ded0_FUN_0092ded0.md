# Raw capture: FUN_0092ded0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0092ded0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0092ded0` |
| **Canonical name** | `FUN_0092ded0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0092ded0(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 *in_EAX;
  char *pcVar4;
  int unaff_ESI;
  undefined4 local_d8 [8];
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_28;
  undefined4 local_24;
  undefined1 local_20;
  uint local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined1 local_10;
  ushort local_e;
  ushort local_c;
  char local_a [10];
  
  local_54 = in_EAX[1];
  local_58 = *in_EAX;
  local_28 = in_EAX[2];
  local_20 = *(undefined1 *)(in_EAX + 10);
  local_24 = in_EAX[3];
  local_1c = (uint)*(ushort *)(in_EAX + 0xb);
  local_18 = in_EAX[0xe];
  local_10 = *(undefined1 *)(in_EAX + 4);
  local_14 = in_EAX[0xf];
  local_d8[0] = 0x9015;
  local_e = (ushort)(*(char *)(in_EAX + 8) != '\0');
  if (*(char *)((int)in_EAX + 0x21) != '\0') {
    local_e = local_e | 2;
  }
  if (*(char *)((int)in_EAX + 0x22) != '\0') {
    local_e = local_e | 4;
  }
  local_c = (ushort)(*(char *)((int)in_EAX + 0x23) != '\0');
  if (*(char *)(in_EAX + 9) != '\0') {
    local_c = local_c | 2;
  }
  if (*(char *)((int)in_EAX + 0x25) != '\0') {
    local_c = local_c | 4;
  }
  if (*(char *)((int)in_EAX + 0x26) != '\0') {
    local_c = local_c | 8;
  }
  pcVar4 = (char *)in_EAX[6];
  if (pcVar4 == (char *)0x0) {
    local_a[0] = '\0';
  }
  else {
    iVar2 = -(int)pcVar4;
    do {
      cVar1 = *pcVar4;
      pcVar4[(int)(local_a + iVar2)] = cVar1;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
  }
  iVar2 = *(int *)(unaff_ESI + 0xe98);
  iVar3 = *(int *)(*(int *)(iVar2 + 4) + 4);
  local_b8 = *(undefined4 *)(iVar3 + 0x164 + iVar2);
  local_b4 = *(undefined4 *)(iVar3 + 0x168 + iVar2);
  if (*(int *)(unaff_ESI + 0xc78) != 0) {
    (**(code **)(**(int **)(unaff_ESI + 0xc78) + 0x18))(0xffffffff,local_d8,0xd8,0);
  }
  return;
}
```
