# Raw capture: Client_LookupObjectByTfid_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bb0a0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004bb0a0` |
| **Canonical name** | `Client_LookupObjectByTfid_Inferred` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Client_LookupObjectByTfid_Inferred — resolve world object by TFID.
   
   Parameters (INFERRED from CharacterLevel dispatch):
     globalFlag (byte), coidLo (uint), coidHi (uint)
   Returns: object* or null.
   
   Called from Client_RecvCharacterLevel before ApplyCharacterLevelPacket vfunc. */

void * __cdecl Client_LookupObjectByTfid_Inferred(byte bGlobal,uint nCoidLo,uint nCoidHi)

{
  int *piVar1;
  void *pvVar2;
  undefined3 in_stack_00000005;
  
  piVar1 = (int *)CVOGReaction_ResolveObjectTarget(_bGlobal,nCoidLo,nCoidHi);
  if (piVar1 != (int *)0x0) {
    pvVar2 = (void *)(**(code **)(*piVar1 + 0x1dc))();
    return pvVar2;
  }
  return (void *)0x0;
}
```
