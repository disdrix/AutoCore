# Raw capture: FUN_007fecb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fecb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007fecb0` |
| **Canonical name** | `FUN_007fecb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_007fecb0(undefined4 param_1)

{
  int iVar1;
  int in_EAX;
  int unaff_EDI;
  undefined4 uStack_18;
  undefined1 local_8 [8];
  
  iVar1 = *(int *)(unaff_EDI + 0x113c);
  if ((iVar1 != 0) && (in_EAX != 0)) {
    *(int *)(iVar1 + 0x500) = in_EAX;
    *(undefined4 *)(iVar1 + 0x4fc) = 0;
    uStack_18 = 0x7fecdf;
    FUN_0083dae0();
    *(undefined4 *)(*(int *)(unaff_EDI + 0x113c) + 0x508) = param_1;
    uStack_18 = 1;
    (**(code **)(**(int **)(unaff_EDI + 0x113c) + 0x140))(local_8);
    (**(code **)(**(int **)(unaff_EDI + 0x113c) + 0x11c))(&uStack_18);
    iVar1 = *(int *)(unaff_EDI + 0x113c);
    if (*(int *)(iVar1 + 0x2b0) == 0) {
      *(undefined4 *)(**(int **)(unaff_EDI + 0xf40) + 0x514) =
           *(undefined4 *)(**(int **)(unaff_EDI + 0xf40) + 0x498);
      *(undefined4 *)(**(int **)(unaff_EDI + 0xf40) + 0x518) =
           *(undefined4 *)(**(int **)(unaff_EDI + 0xf40) + 0x49c);
      *(undefined4 *)(**(int **)(unaff_EDI + 0xf40) + 0x498) = 0x4e62;
      *(undefined4 *)(**(int **)(unaff_EDI + 0xf40) + 0x49c) = 0x4e63;
    }
    else {
      (**(code **)(**(int **)(iVar1 + 0x2b0) + 0xb0))(iVar1);
    }
    (**(code **)(*(int *)**(undefined4 **)(unaff_EDI + 0xf40) + 0x3ec))();
    (**(code **)(*(int *)**(undefined4 **)(unaff_EDI + 0xf40) + 0x3f4))(1);
    (**(code **)(*(int *)**(undefined4 **)(unaff_EDI + 0xf40) + 0xa8))
              (*(undefined4 *)(unaff_EDI + 0x113c));
    (**(code **)(**(int **)(unaff_EDI + 0x113c) + 4))(1);
    (**(code **)(*(int *)**(undefined4 **)(unaff_EDI + 0xf40) + 0x1c8))(1);
    FUN_0092f000();
    (**(code **)(*(int *)**(undefined4 **)(unaff_EDI + 0xf40) + 0x3bc))
              (*(undefined4 *)(unaff_EDI + 0x113c));
    (**(code **)(**(int **)(unaff_EDI + 0x113c) + 0x334))(1);
    (**(code **)(**(int **)(unaff_EDI + 0x113c) + 0x94))();
  }
  return;
}
```
