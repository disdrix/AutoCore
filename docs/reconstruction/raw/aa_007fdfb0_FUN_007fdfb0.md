# Raw capture: FUN_007fdfb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fdfb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007fdfb0` |
| **Canonical name** | `FUN_007fdfb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_007fdfb0(int param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 in_EAX;
  undefined4 unaff_retaddr;
  undefined4 uVar3;
  
  FUN_007fc360();
  piVar1 = *(int **)(param_1 + 0xf40);
  if ((piVar1 != (int *)0x0) && (*piVar1 != 0)) {
    (**(code **)(*(int *)*piVar1 + 0x3ec))();
    (**(code **)(*(int *)**(undefined4 **)(param_1 + 0xf40) + 0x3f4))(1);
    (**(code **)(*(int *)**(undefined4 **)(param_1 + 0xf40) + 0xa8))
              (*(undefined4 *)(param_1 + 0x1118));
    *(undefined4 *)(**(int **)(param_1 + 0xf40) + 0x514) =
         *(undefined4 *)(**(int **)(param_1 + 0xf40) + 0x498);
    *(undefined4 *)(**(int **)(param_1 + 0xf40) + 0x498) = in_EAX;
    *(undefined4 *)(**(int **)(param_1 + 0xf40) + 0x518) =
         *(undefined4 *)(**(int **)(param_1 + 0xf40) + 0x49c);
    if (param_3 < 0) {
      *(undefined4 *)(**(int **)(param_1 + 0xf40) + 0x49c) = in_EAX;
    }
    else {
      *(int *)(**(int **)(param_1 + 0xf40) + 0x49c) = param_3;
    }
    if (*(int **)(param_1 + 0x1118) == (int *)0x0) {
      FUN_007a4480(0,"VOG_DEBUG_STOP");
    }
    else {
      (**(code **)(**(int **)(param_1 + 0x1118) + 0x43c))();
      FUN_008a7090();
      iVar2 = **(int **)(param_1 + 0x1118);
      uVar3 = 0xffffffff;
      FUN_007a69d0(unaff_retaddr,0xffffffff);
      uVar3 = FUN_007a6de0(unaff_retaddr,uVar3);
      (**(code **)(iVar2 + 0x444))(uVar3);
      FUN_008a7150();
      FUN_008a7100();
      FUN_008a6fd0(param_2);
      (**(code **)(**(int **)(param_1 + 0x1118) + 0x34c))();
    }
    piVar1 = *(int **)(param_1 + 0xf38);
    if (piVar1 != (int *)0x0) {
      if (*(char *)(param_1 + 0x31d9) != '\0') {
        *(undefined1 *)(param_1 + 0x31d8) = *(undefined1 *)((int)piVar1 + 0x493);
        (**(code **)(*piVar1 + 0x3c4))(1);
        return;
      }
      *(undefined1 *)(param_1 + 0x31d8) = 1;
      (**(code **)(*piVar1 + 0x3c4))(1);
    }
  }
  return;
}
```

# Raw capture append: FUN_007fdfb0 / Client_ShowModalPrompt (UF-009 seal)

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fdfb0` |
| **VA** | `0x007fdfb0` |
| **Capture** | `2026-07-29` UF-009 pairing seal |
| **Tool** | Ghidra MCP `decompile_function` + `get_assembly_context` (autoassault.exe) |
| **Integrity** | Append-only; original 2026-07-23 body above remains authoritative for scaffold |

---

## Version 2026-07-29 — dual-id store + abandon caller EAX

### Prologue (asm)

```
007fdfb0  PUSH EBX
007fdfb1  MOV  EBX, [ESP+0x8]     ; param_1 = game/client root
007fdfb5  PUSH EBP
007fdfb6  MOV  EBP, [ESP+0x14]    ; param_3 = secondary button / cancel id (stack)
007fdfba  PUSH EDI
007fdfbb  MOV  EDI, EAX            ; EDI = primary / OK id from EAX at call
007fdfbd  MOV  EAX, EBX
007fdfbf  CALL FUN_007fc360       ; dismiss any prior modal first
```

### Dual-id assignment (asm, modal object = *game+0xf40)

```
; backup previous OK id
MOV  EDX, [modal+0x498]
MOV  [modal+0x514], EDX
; store primary (EAX / EDI) -> +0x498
MOV  [modal+0x498], EDI

; backup previous secondary id
MOV  ECX, [modal+0x49c]
MOV  [modal+0x518], ECX
; if param_3 (EBP) < 0:  +0x49c = EDI  (single-button; same id both slots)
; else:                  +0x49c = EBP  (dual-button cancel/secondary id)
JGE  store_ebp
MOV  [modal+0x49c], EDI
JMP  cont
store_ebp:
MOV  [modal+0x49c], EBP
```

### Abandon open site (Client_MissionDialogHandleButton @ 0x008ae8ab..0x008ae8c3)

Chronological (addresses ascending):

```
008ae8ab  PUSH 0x0
008ae8ad  PUSH 0x1
008ae8af  PUSH 0x4e47            ; stack param_3 = CANCEL id
008ae8b4  LEA  EDX, [ESP+0x38]   ; abandon sprintf buffer
008ae8b8  PUSH EDX               ; param_2 = message
008ae8b9  PUSH 0x00d1a840        ; param_1 = &DAT_00d1a840
008ae8be  MOV  EAX, 0x4e46       ; EAX = YES / CONFIRM id  *** KEY ***
008ae8c3  CALL FUN_007fdfb0
```

**Decompiler lie:** Ghidra shows `FUN_007fdfb0(&DAT_00d1a840, msg, 0x4e47, 1, 0)` and drops `EAX=0x4e46`. Live asm is authoritative.

### Result for abandon

| Slot | Offset | Value | Dispatch case | Behavior |
|---|---|---|---|---|
| Primary / OK (EAX) | modal `+0x498` | `0x4e46` | `Client_UiModalDispatch` case `0x4e46` | C2S `0x20B2` FailMission size `0x18` |
| Secondary / Cancel (stack) | modal `+0x49c` | `0x4e47` | case `0x4e47` (dismiss family) | `FUN_007fc360` close only |

### Additional dual-button callers (same convention)

| Call site | EAX (primary ? +0x498) | stack param_3 (? +0x49c) |
|---|---|---|
| `0x008ae8c3` abandon | `0x4e46` | `0x4e47` |
| `0x0080fb5c` | `0x4e2c` | `0x4e2d` |
| `0x0080fb92` | `0x4e2c` | `0x4e2d` |
| `0x008638f0` | `0x4e5a` | `0x4e5b` |

Single-button / toast pattern (param_3 = `-1`, both slots = EAX):

| Call site | EAX | param_3 |
|---|---|---|
| `0x008ae9ab` reward toast | `0x4e24` | `-1` (from decompile path) |
| `0x00931f54` | `0x4e24` | stack flags with `-1` |
| `0x00862d07` | `0x4e24` | `-1` |

### Pairing convention (sealed)

```
Client_ShowModalPrompt(game, message, cancelOrSecondaryId, flagA, flagB)
  // with EAX = primaryOrOkId   (custom register arg; not in Ghidra stack prototype)

modal+0x498 = EAX                          // primary / Yes / OK
modal+0x49c = (param_3 < 0) ? EAX : param_3  // secondary / No / Cancel, or same if single
modal+0x514 / +0x518 = previous dual ids (restore backup)

// Abandon:
//   EAX=0x4e46 (Yes?C2S 0x20B2), param_3=0x4e47 (No?close)
```

### Confidence

| Claim | Level |
|---|---|
| Dual-id store +0x498/+0x49c | **High** (asm) |
| Abandon EAX=0x4e46, stack=0x4e47 | **High** (asm at `008ae8be`) |
| Yes=0x4e46 / No=0x4e47 for abandon | **High** (store + dispatch cases) |
| Decompiler missing EAX arg | **High** |
| Physical OK widget always binds +0x498 (vs reverse wire) | **High** for abandon via case semantics; general UI widget source **Probable** residual |


