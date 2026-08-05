# Raw capture: FUN_007fb7f0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fb7f0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007fb7f0` |
| **Canonical name** | `FUN_007fb7f0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_007fb7f0(void)

{
  char cVar1;
  int in_EAX;
  int *piVar2;
  int unaff_EDI;
  
  piVar2 = *(int **)(unaff_EDI + 0x1124);
  if (in_EAX == 2) {
    piVar2 = *(int **)(unaff_EDI + 0x1128);
  }
  else if (in_EAX == 3) {
    piVar2 = *(int **)(unaff_EDI + 0x112c);
  }
  else if (in_EAX == 4) {
    piVar2 = *(int **)(unaff_EDI + 0x1130);
  }
  else if (in_EAX == 5) {
    piVar2 = *(int **)(unaff_EDI + 0x1134);
  }
  if ((*(int *)(unaff_EDI + 0xf40) != 0) && (piVar2 != (int *)0x0)) {
    cVar1 = (**(code **)(*piVar2 + 0x3d8))();
    if (cVar1 != '\0') {
      (**(code **)(*piVar2 + 0x440))();
      if (**(int **)(unaff_EDI + 0xf40) != 0) {
        (**(code **)(*(int *)**(int **)(unaff_EDI + 0xf40) + 0xb0))(piVar2);
      }
    }
  }
  return;
}
```
