# Raw capture: FUN_007fca10

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fca10` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007fca10` |
| **Canonical name** | `FUN_007fca10` |
| **System** | missions-progression (generic UI close; mission Flush invoker) |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_007fca10(void)

{
  int *piVar1;
  char cVar2;
  int *in_EAX;
  int unaff_EBX;
  int *piVar3;
  int iVar4;
  undefined1 uVar5;
  
  if ((*(int *)(unaff_EBX + 0xf40) != 0) && (in_EAX != (int *)0x0)) {
    cVar2 = (**(code **)(*in_EAX + 0x3d8))();
    if (cVar2 != '\0') {
      (**(code **)(*in_EAX + 0x440))();
      if (**(int **)(unaff_EBX + 0xf40) != 0) {
        (**(code **)(*(int *)**(int **)(unaff_EBX + 0xf40) + 0xb0))();
      }
      iVar4 = 0;
      piVar3 = (int *)(unaff_EBX + 0x1030);
      do {
        if ((iVar4 != 0x16) && (piVar1 = (int *)*piVar3, piVar1 != (int *)0x0)) {
          cVar2 = (**(code **)(*piVar1 + 0x3d8))();
          if ((cVar2 != '\0') && (piVar1[0x140] == 1)) goto LAB_007fcac1;
        }
        iVar4 = iVar4 + 1;
        piVar3 = piVar3 + 1;
      } while (iVar4 < 0x3a);
      if (*(int **)(unaff_EBX + 0xf38) != (int *)0x0) {
        if (*(char *)(unaff_EBX + 0x31d9) == '\0') {
          *(undefined1 *)(unaff_EBX + 0x31d8) = 1;
          uVar5 = 1;
        }
        else {
          uVar5 = *(undefined1 *)(unaff_EBX + 0x31d8);
        }
        (**(code **)(**(int **)(unaff_EBX + 0xf38) + 0x3c4))(uVar5);
      }
LAB_007fcac1:
      iVar4 = *(int *)(unaff_EBX + 0x10b0);
      if ((iVar4 != 0) && (*(int *)(iVar4 + 0x664) != 0)) {
                    /* WARNING: Could not recover jumptable at 0x007fcae1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(**(int **)(iVar4 + 0x664) + 0x47c))();
        return;
      }
    }
  }
  return;
}
```

---

## Re-verify 2026-07-29 (wave3 dual strengthen — UF-010 invoker host)

| Field | Value |
|---|---|
| **Tool** | Ghidra MCP `decompile_function` @ `0x007fca10` |
| **Integrity** | Live body **byte-identical** to authoritative raw above (append only) |
| **read_memory** | `0x00a4a95c` dword = `f0 b8 8a 00` LE = **`0x008ab8f0`** (`Client_MissionDialog_FlushPreparedResponse`) |
| **Vtable math** | base `0x00a4a51c` + `0x440` = slot `0x00a4a95c` |
| **Mission flush callers (decompile)** | `FUN_008aec40` @ `0x008aef96` CALL; `FUN_008af020` body CALL after HandleButton success |
| **Xrefs** | Very high fan-in (generic UI close host); mission-dialog force-send path is the dispatch→this→`+0x440` chain |

### Sealed CF summary (when Flush is invoked)

```
Gates (all required before vtbl+0x440):
  1. *(EBX + 0xf40) != 0          // client parent / UI root non-null
  2. EAX != null                  // dialog/UI object to close
  3. (EAX->vtbl+0x3d8)() != 0     // "visible" / live predicate

Then:
  4. (EAX->vtbl+0x440)()          // for mission dialog class @ client+0x1058
                                  //   vtable 0x00a4a51c+0x440 → 0x008ab8f0 Flush
  5. optional parent detach vtbl+0xb0 on *(EBX+0xf40)
  6. scan client dialog table [+0x1030 .. +0x1030+0x3a*4), skip index 0x16
     if other visible + field[0x140]==1 → skip restore; else optional +0xf38+0x3c4
  7. optional *(EBX+0x10b0)+0x664 → vtbl+0x47c
```

**UF-010 relation:** This function is the **static invoker** of FlushPreparedResponse's virtual slot. Not a mission-only helper — any UI object passed in EAX with a non-null `+0x440` method is closed the same way.

**UF-011 relation:** This host does **not** touch `dialog+0x650`. Cancel/close that reaches here with prepared opcode still invokes `+0x440` → Flush may send stale 0x206E. Clear-before-flush is not this function's job.
