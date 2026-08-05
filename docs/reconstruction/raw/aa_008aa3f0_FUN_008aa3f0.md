# Raw capture: FUN_008aa3f0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008aa3f0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008aa3f0` |
| **Canonical name** | `FUN_008aa3f0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_008aa3f0(int param_1)

{
  int in_EAX;
  int iVar1;
  undefined4 *puVar2;
  
  *(undefined4 *)(in_EAX + 0x578) = *(undefined4 *)(in_EAX + 0x558 + param_1 * 8);
  *(undefined4 *)(in_EAX + 0x57c) = *(undefined4 *)(in_EAX + 0x55c + param_1 * 8);
  puVar2 = (undefined4 *)(in_EAX + 0x698);
  iVar1 = 4;
  do {
    (**(code **)(*(int *)*puVar2 + 0x158))(0,in_EAX + 0x594);
    (**(code **)(*(int *)*puVar2 + 0x34c))();
    puVar2 = puVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  (**(code **)(**(int **)(in_EAX + 0x698 + param_1 * 4) + 0x158))(0,in_EAX + 0x5a4);
  (**(code **)(**(int **)(in_EAX + 0x698 + param_1 * 4) + 0x34c))();
  if (*(int **)(in_EAX + 0x708) != (int *)0x0) {
    (**(code **)(**(int **)(in_EAX + 0x708) + 0x308))(&DAT_00a1419b);
  }
  return;
}
```

---

## Version 2026-07-29 — live re-decompile (dual A/B; append only)

| Field | Value |
|---|---|
| **Tool** | Ghidra MCP `decompile_function` + `read_memory` + `get_assembly_context` |
| **Integrity** | Body matches 2026-07-23 raw (no CF delta) |
| **Extra evidence** | Prologue bytes @ `0x008aa3f0`; call sites `0x008aa968`, `0x008aed23` |
| **DAT_00a1419b** | first byte `0x00` (empty C-string) |

### Prologue / selection bytes (hex prefix)

`535556578bf88b4424148b8cc758050000898f780500008b94c75c05000089977c0500008daf940500008db798060000bb04000000`

Decode summary: push EBX/EBP/ESI/EDI; MOV EDI,EAX; MOV EAX,[ESP+0x14]; copy `[EDI+EAX*8+0x558/55c]` ? `[EDI+0x578/57c]`; LEA EBP,[EDI+0x594]; LEA ESI,[EDI+0x698]; MOV EBX,4; then vtbl+0x158 / +0x34c loop.
