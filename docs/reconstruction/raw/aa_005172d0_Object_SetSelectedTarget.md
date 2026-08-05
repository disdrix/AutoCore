# Raw capture: Object_SetSelectedTarget

| Field | Value |
|---|---|
| **Stable ID** | `aa_005172d0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005172d0` |
| **Canonical name** | `Object_SetSelectedTarget` |
| **System** | object / combat-target / HB |
| **Capture timestamp** | `2026-07-29` (dual A/B refine; prior scaffold `2026-07-23`) |
| **Tool** | Ghidra MCP `decompile_function` + `read_memory` |
| **Integrity** | Authoritative body below is asm-corrected from live decompile; do not silently overwrite |

---

## Raw pseudocode (live decompile, 2026-07-29)

```c
void __thiscall Object_SetSelectedTarget(int param_1,int param_2)

{
  void *pvVar1;
  CVOGHBBase *pAction;
  CVOGHBBase *pAction_00;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a3570;
  local_c = ExceptionList;
  if (param_2 != *(int *)(param_1 + 0xa0)) {
    pAction_00 = (CVOGHBBase *)0x0;
    if ((*(int *)(param_1 + 0xa4) != 0) && (*(int *)(*(int *)(param_1 + 0xa4) + 0xe4ec) != 0)) {
      ExceptionList = &local_c;
      if (*(void **)(param_1 + 0x14) != (void *)0x0) {
        ExceptionList = &local_c;
        NetObject_SetMaskBits(*(void **)(param_1 + 0x14),4,0);
      }
      if (*(int *)(param_1 + 0xa0) != 0) {
        *(int *)(param_1 + 0xa0) = param_2;
      }
      CNDDoubleList_InvokePredicateAndRemove_Inferred(FUN_005121d0,0,0);
      *(int *)(param_1 + 0xa0) = param_2;
      if ((param_2 != 0) && (param_2 != param_1)) {
        pvVar1 = operator_new(0x28);
        local_4 = 0;
        if (pvVar1 != (void *)0x0) {
          pAction_00 = (CVOGHBBase *)FUN_00512090(param_1);
        }
        local_4 = 0xffffffff;
        pvVar1 = operator_new(0x28);
        local_4 = 1;
        if (pvVar1 == (void *)0x0) {
          pAction = (CVOGHBBase *)0x0;
        }
        else {
          pAction = (CVOGHBBase *)FUN_00604d40(param_2);
        }
        local_4 = 0xffffffff;
        FUN_00604db0(pAction);
        FUN_00604db0(pAction_00);
        CVOGHBList_Enqueue(*(void **)(*(int *)(param_1 + 0xa4) + 0xe4ec),pAction_00);
        CVOGHBList_Enqueue(*(void **)(*(int *)(param_1 + 0xa4) + 0xe4ec),pAction);
      }
    }
  }
  ExceptionList = local_c;
  return;
}
```

### Decompiler defects (sealed by `read_memory`)

1. **`CNDDoubleList_InvokePredicateAndRemove_Inferred` missing `this`**: asm loads **`ECX = *(param_1 + 0xB0)`** at `0x00517333` before the call.
2. **`FUN_00604db0` shown unary**: asm passes partner as stack arg both ways (`self←target`, then `target←self`).
3. Signature was briefly `undefined`/void noise; ABI is **`void __thiscall`**, **`ret 4`**.

---

## Asm summary (authoritative)

```
; ESI=this, EDI=newTarget
cmp  edi, [esi+0xA0]; je done
mov  eax, [esi+0xA4]; test; je done
cmp  [eax+0xE4EC], 0; je done
; optional NetObject_SetMaskBits([esi+0x14], 4, 0)
; if [esi+0xA0]!=0: [esi+0xA0]=edi
mov  ecx, [esi+0xB0]
push 0; push 0; push FUN_005121d0
call CNDDoubleList_InvokePredicateAndRemove_Inferred
mov  [esi+0xA0], edi
; if edi!=0 && edi!=esi: dual new 0x28, ctors, cross FUN_00604db0, dual Enqueue
ret 4
```

Body: `005172d0`–`005173f9`.
