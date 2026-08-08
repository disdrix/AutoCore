# Raw capture: FUN_0083abf0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0083abf0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0083abf0` |
| **Canonical name** | `FUN_0083abf0` |
| **System** | shopveh list / bind slot from list index |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_0083abf0(int param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  char cVar4;
  int iVar5;
  
  iVar2 = (int)param_3;
  if (((((-1 < param_2) && (*(int *)((int)param_3 + 0x508) != 0)) && (-1 < param_1)) &&
      ((param_1 < 5 && (iVar1 = *(int *)((int)param_3 + 0x50c + param_1 * 4), iVar1 != 0)))) &&
     (*(int *)(*(int *)((int)param_3 + 0x508) + 0x50) != 0)) {
    param_3 = (int *)0x0;
    cVar4 = FUN_00427d20(param_2,&param_3);
    piVar3 = param_3;
    if (((cVar4 != '\0') && (param_3 != (int *)0x0)) &&
       ((iVar5 = (**(code **)(*param_3 + 0x1d4))(), iVar5 != 0 &&
        ((*(int *)(iVar1 + 0x508) == 0 ||
         (iVar1 = *(int *)(iVar1 + 0x50c), iVar5 = (**(code **)(*piVar3 + 0x1d4))(), iVar1 != iVar5)
         ))))) {
      (**(code **)(*piVar3 + 0x1d4))();
      FUN_0083ab90(iVar2);
    }
  }
  return;
}
```

---

## WQ9L-J re-verify append (2026-08-05)

| Item | Value |
|---|---|
| Body | `0x0083abf0`–`0x0083ac89` inclusive (**154 B** / `0x9A`); pad `CC`×6 then parent `FUN_0083ac90` |
| Entry | `85 D2 55 8B 6C 24 08 0F 8C …` — `TEST EDX,EDX`; `PUSH EBP`; `MOV EBP,[ESP+8]` (stack host) |
| Exit | `5E 5F 5B 5D C2 04 00` — pop ESI/EDI/EBX/EBP; **`RET 4`** |
| ABI | **ECX** = slot index [0..4]; **EDX** = list_i; stack **host***; void; **`RET 4`** (MSVC ECX/EDX + 1 stack) |
| Gates | `list_i >= 0`; `host+0x508 != 0`; `slot ∈ [0,5)`; `slots[slot] != 0`; `*(host+0x508)+0x50 != 0` |
| List container | **EDI** = `host+0x508 + 0x2c` for `FUN_00427d20` (index list_i → entity*) |
| Bind condition | lookup ok + entity* + `entity->vtbl+0x1d4() != 0` + (`slot+0x508==0` **OR** `slot+0x50c != entity_id`) |
| Bind action | re-`vtbl+0x1d4` (leaves **EAX**=entity id); `PUSH host`; `MOV ECX,slot_obj`; `CALL FUN_0083ab90` |
| Callers (3 CALL) | `FUN_0083ac90` only @ `0083ad5a`, `0083adb7`, `0083add0` — each `PUSH EBP; MOV ECX,ESI; MOV EDX,EDI` |
| Callees | `FUN_00427d20`, `FUN_0083ab90`, entity vtbl `+0x1d4` (×1–3) |
| Classification | worker |
| Named | `ShopVehList_BindSlotFromListIndexIfMismatch_Inferred` |
| Decompile notes | `FUN_0083ab90(iVar2)` understates ABI — assembly passes **ECX=slot**, **EAX=entity_id**, stack **host**, **RET 4**. `param_3` reused as out-ptr local after gate. |

### Live re-decompile (2026-08-05, matches scaffold)

```c
void __fastcall FUN_0083abf0(int param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  char cVar4;
  int iVar5;
  
  iVar2 = (int)param_3;
  if (((((-1 < param_2) && (*(int *)((int)param_3 + 0x508) != 0)) && (-1 < param_1)) &&
      ((param_1 < 5 && (iVar1 = *(int *)((int)param_3 + 0x50c + param_1 * 4), iVar1 != 0)))) &&
     (*(int *)(*(int *)((int)param_3 + 0x508) + 0x50) != 0)) {
    param_3 = (int *)0x0;
    cVar4 = FUN_00427d20(param_2,&param_3);
    piVar3 = param_3;
    if (((cVar4 != '\0') && (param_3 != (int *)0x0)) &&
       ((iVar5 = (**(code **)(*param_3 + 0x1d4))(), iVar5 != 0 &&
        ((*(int *)(iVar1 + 0x508) == 0 ||
         (iVar1 = *(int *)(iVar1 + 0x50c), iVar5 = (**(code **)(*piVar3 + 0x1d4))(), iVar1 != iVar5)
         ))))) {
      (**(code **)(*piVar3 + 0x1d4))();
      FUN_0083ab90(iVar2);
    }
  }
  return;
}
```

---

## WQ9L-J live dual seal re-confirm (2026-08-05 session)

| Item | Value |
|---|---|
| Tools | `batch_decompile` + `analyze_function_complete` + `disassemble_function` + `read_memory` + `get_assembly_context`. **No** `disassemble_bytes`. |
| Decompile ≡ prior raw body | **Yes** (byte-identical CF) |
| Body hex head | `85 D2 55 8B 6C 24 08 …` ends `… 5E 5F 5B 5D C2 04 00` + `CC`×6 |
| Parent call sites | 3× `PUSH EBP; MOV ECX,ESI; MOV EDX,EDI; CALL 0083abf0` in `FUN_0083ac90` |
| Bind tail | `PUSH EBP; MOV ECX,EBX; CALL 0083ab90` (EAX=entity id from vtbl+0x1d4) |
| Dual A/B | **accept-with-gaps** |

