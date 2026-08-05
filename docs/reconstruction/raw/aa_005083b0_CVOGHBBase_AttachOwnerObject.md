# Raw capture: CVOGHBBase_AttachOwnerObject

| Field | Value |
|---|---|
| **Stable ID** | `aa_005083b0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005083b0` |
| **Canonical name** | `CVOGHBBase_AttachOwnerObject` |
| **System** | heartbeat / timed-action infrastructure |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* CVOGHBBase_AttachOwnerObject — set pOwnerObject (+0x18), maintain owner link lists.
   
   Parameters:
     this (ECX): CVOGHBBase* [API shows void*]
     pOwnerObject: vehicle/character SimpleObject base
   
   Algorithm: detach prior owner if linked; store new; attach if new has list head at +0xB0.
   
   Returns: void */

void __thiscall CVOGHBBase_AttachOwnerObject(void *this,void *pOwnerObject)

{
  if ((*(int *)((int)this + 0x18) != 0) && (*(int *)(*(int *)((int)this + 0x18) + 0xb0) != 0)) {
    FUN_005085b0(this);
  }
  *(void **)((int)this + 0x18) = pOwnerObject;
  if ((pOwnerObject != (void *)0x0) && (*(int *)((int)pOwnerObject + 0xb0) != 0)) {
    FUN_00508490(this);
  }
  return;
}
```

---

## Versioned append: machine seal 2026-07-29

| Field | Value |
|---|---|
| **Tools** | `decompile_function`, `force_decompile`, `read_memory`, `get_function_by_address`, `get_function_callers` |
| **Body** | `005083b0`–`005083ec` (60 bytes) |
| **Hex** | `568bf18b461885c074128b80b000000085c07408568bc8e8e40100008b44240885c089461874128b80b000000085c07408568bc8e8a70000005ec20400` |

### Machine call shape (corrects decompiler)

Decompiler shows `FUN_005085b0(this)` / `FUN_00508490(this)` with this=HB.  
Machine:

```
; detach
push esi                 ; HB*
mov  ecx, [oldOwner+0xB0]; listMgr this
call FUN_005085b0        ; 0x005085b0

; store always
mov  [esi+0x18], pOwnerObject

; attach
push esi
mov  ecx, [newOwner+0xB0]
call FUN_00508490        ; 0x00508490

pop  esi
ret  4
```

`owner+0xB0` is a **pointer to a list manager object**, not an embedded list head.

### Dual decompile

| Pass | Result |
|---|---|
| A `decompile_function` | body above (gates + store) |
| B `force_decompile` | identical pseudocode |
