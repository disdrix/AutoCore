# Raw capture: CNDHash_Insert

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053c560` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0053c560` |
| **Canonical name** | `CNDHash_Insert` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Generic CNDHash insert(key, value). Used when applying CreateCharacterExtended continent slots
   and UnlockContinentObject. */

int __thiscall CNDHash_Insert(void *this,uint key,void *value,char allowDuplicate)

{
  int iVar1;
  void *pvVar2;
  undefined4 *puVar3;
  
  if (value == (void *)0x0) {
    return -0x7fffbffd;
  }
  if (*(char *)((int)this + 0x1d) != '\0') {
    FUN_007a4480(0,"HashError:insert, already locked for traversal");
    FUN_007a4480(0,"VOG_DEBUG_STOP");
  }
  if (allowDuplicate != '\0') {
    pvVar2 = CNDHash_LookupByKey(this,key);
    if (pvVar2 != (void *)0x0) {
      return 1;
    }
  }
  pvVar2 = CNDHash_LookupByKey(this,key);
  if (pvVar2 != (void *)0x0) {
    FUN_007a4480(0,"Duplicate hash insert %u, failing out",key);
    return -0x7fffbffb;
  }
  puVar3 = (undefined4 *)FUN_0053ada0();
  puVar3[3] = 0;
  *puVar3 = &PTR_FUN_009cefd4;
  puVar3[5] = 0;
  puVar3[6] = 0;
  *(undefined1 *)(puVar3 + 1) = 0;
  puVar3[2] = value;
  puVar3[4] = key;
  iVar1 = *(int *)(*(int *)((int)this + 0x10) + (*(uint *)((int)this + 8) & key) * 4);
  puVar3[3] = *(undefined4 *)(iVar1 + 4);
  *(undefined4 **)(iVar1 + 4) = puVar3;
  FUN_00537d30();
  if (*(int *)((int)this + 0x18) != 0) {
    *(undefined4 **)(*(int *)((int)this + 0x18) + 0x14) = puVar3;
    puVar3[5] = 0;
    puVar3[6] = *(undefined4 *)((int)this + 0x18);
    *(int *)((int)this + 0xc) = *(int *)((int)this + 0xc) + 1;
    *(undefined4 **)((int)this + 0x18) = puVar3;
    return 0;
  }
  *(undefined4 **)((int)this + 0x18) = puVar3;
  *(undefined4 **)((int)this + 0x14) = puVar3;
  puVar3[6] = 0;
  puVar3[5] = 0;
  *(int *)((int)this + 0xc) = *(int *)((int)this + 0xc) + 1;
  return 0;
}
```
