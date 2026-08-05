# Raw capture: NDUIWindow_ReloadInterface

| Field | Value |
|---|---|
| **Stable ID** | `aa_00792980` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00792980` |
| **Canonical name** | `NDUIWindow_ReloadInterface` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* NDUIWindow_ReloadInterface
   
   thiscall: NDUIWindow_LoadInterfaceFile(path), then clear cached sub-object at +0x12d,
   optionally traverse hash at +0x130 and hide children when path is null. */

void __thiscall NDUIWindow_ReloadInterface(int *param_1,int param_2)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  
  NDUIWindow_LoadInterfaceFile(param_2);
  param_1[0x12e] = 0;
  param_1[0x12f] = 0;
  if ((undefined4 *)param_1[0x12d] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x12d])(1);
  }
  param_1[0x12d] = 0;
  if (param_2 == 0) {
    cVar2 = (**(code **)(*param_1 + 0x3d8))();
    if ((cVar2 != '\0') && (param_1[0x130] != 0)) {
      iVar4 = 0;
      FUN_00411e10();
      while( true ) {
        iVar1 = param_1[0x130];
        if (*(char *)(iVar1 + 0x1d) == '\0') {
          FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");
          FUN_007a4480(0,"VOG_DEBUG_STOP");
        }
        if (iVar4 == 0) {
          iVar4 = *(int *)(iVar1 + 0x14);
        }
        else {
          iVar4 = *(int *)(iVar4 + 0x14);
        }
        if (iVar4 == 0) {
          piVar3 = (int *)0x0;
        }
        else {
          piVar3 = *(int **)(iVar4 + 8);
        }
        if (piVar3 == (int *)0x0) break;
        (**(code **)(*piVar3 + 0x28))(0);
      }
      *(undefined1 *)(param_1[0x130] + 0x1d) = 0;
      (**(code **)(*param_1 + 0x34c))();
    }
  }
  return;
}
```

---

## Append — live re-capture 2026-07-29 (OWN-ONLY dual)

| Field | Value |
|---|---|
| **Tool** | Ghidra MCP `decompile_function` + `read_memory` + callees/callers |
| **Integrity** | Authoritative raw body above unchanged; this section is additive |

### Live decompile

Body re-decompiled at 0x00792980 **matches** the 2026-07-23 pseudocode (same CF, same field indices, same callees/strings). No material drift.

### Prologue bytes (read_memory length 64 @ 0x00792980)

```
53 55 56 8b 74 24 10 56 8b e9 e8 61 e5 01 00
8b 8d b4 04 00 00 33 db 3b cb
89 9d b8 04 00 00 89 9d bc 04 00 00
74 06 8b 01 6a 01 ff 10
3b f3 89 9d b4 04 00 00 0f 85 81 00 00 00 ...
```

Seals: this in EBP; path in ESI; call NDUIWindow_LoadInterfaceFile 0x007b0ef0; zero +0x4B8/+0x4BC; cond vtbl[0](1) on +0x4B4; clear +0x4B4; branch path!=0.

### Callees (Ghidra)

- NDUIWindow_LoadInterfaceFile @ 0x007b0ef0
- FUN_00411e10 @ 0x00411e10
- FUN_007a4480 @ 0x007a4480

### Dual reviews

- reviews/A_aa_00792980_NDUIWindow_ReloadInterface.md
- reviews/B_aa_00792980_NDUIWindow_ReloadInterface.md
- Verdict: **accept-with-gaps**