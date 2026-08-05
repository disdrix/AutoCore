# Raw capture: FUN_008cc5a0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008cc5a0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008cc5a0` |
| **Canonical name** | `FUN_008cc5a0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_008cc5a0(void)

{
  char cVar1;
  int *unaff_ESI;
  char *unaff_EDI;
  
  if (unaff_ESI[0x195] != 0) {
    (**(code **)(*(int *)unaff_ESI[0x195] + 0x268))();
    FUN_008aab00(unaff_ESI[0x195]);
    (**(code **)(*(int *)unaff_ESI[0x195] + 0x34c))();
  }
  cVar1 = (**(code **)(*unaff_ESI + 0x3d8))();
  if (cVar1 != '\0') {
    cVar1 = (**(code **)(*unaff_ESI + 0xd0))();
    if (cVar1 != '\0') {
      if ((unaff_EDI == (char *)0x0) || (*unaff_EDI == '\0')) {
        if (unaff_ESI[400] != 0) {
          (**(code **)(*(int *)unaff_ESI[400] + 4))(0);
        }
        if (unaff_ESI[0x191] != 0) {
          (**(code **)(*(int *)unaff_ESI[0x191] + 4))(0);
        }
        if (unaff_ESI[0x192] != 0) {
          (**(code **)(*(int *)unaff_ESI[0x192] + 4))(0);
        }
        if (unaff_ESI[0x193] != 0) {
          (**(code **)(*(int *)unaff_ESI[0x193] + 4))(0);
        }
        if (unaff_ESI[0x194] != 0) {
          (**(code **)(*(int *)unaff_ESI[0x194] + 4))(0);
        }
        if (unaff_ESI[0x195] != 0) {
          (**(code **)(*(int *)unaff_ESI[0x195] + 4))(0);
        }
      }
      else {
        if (unaff_ESI[400] != 0) {
          (**(code **)(*(int *)unaff_ESI[400] + 0xfc))(1,0x3f000000);
        }
        if (unaff_ESI[0x191] != 0) {
          (**(code **)(*(int *)unaff_ESI[0x191] + 0xfc))(1,0x3f000000);
        }
        if (unaff_ESI[0x192] != 0) {
          (**(code **)(*(int *)unaff_ESI[0x192] + 0xfc))(1,0x3f000000);
        }
        if (unaff_ESI[0x193] != 0) {
          (**(code **)(*(int *)unaff_ESI[0x193] + 0xfc))(1,0x3f000000);
        }
        if (unaff_ESI[0x194] != 0) {
          (**(code **)(*(int *)unaff_ESI[0x194] + 0xfc))(1,0x3f000000);
        }
        if (unaff_ESI[0x195] != 0) {
          (**(code **)(*(int *)unaff_ESI[0x195] + 0xfc))(1,0x3f000000);
          return;
        }
      }
    }
  }
  return;
}
```
