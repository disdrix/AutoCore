# Raw capture: FUN_008ceab0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ceab0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008ceab0` |
| **Canonical name** | `FUN_008ceab0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_008ceab0(void)

{
  int iVar1;
  int in_EAX;
  
  iVar1 = *(int *)(in_EAX + 0x5a8);
  if (iVar1 == 0) {
    switch(*(undefined4 *)(in_EAX + 0x5ac)) {
    case 0:
      *(undefined4 *)(in_EAX + 0x57c) = 0x26e6;
      *(undefined4 *)(in_EAX + 0x580) = 0x26ef;
      *(undefined4 *)(in_EAX + 0x584) = 0x298d;
      break;
    case 1:
      *(undefined4 *)(in_EAX + 0x57c) = 0x2993;
      *(undefined4 *)(in_EAX + 0x580) = 0x299f;
      *(undefined4 *)(in_EAX + 0x584) = 0x29ab;
      break;
    case 2:
      *(undefined4 *)(in_EAX + 0x57c) = 0x29b1;
      *(undefined4 *)(in_EAX + 0x580) = 0x29bd;
      *(undefined4 *)(in_EAX + 0x584) = 0x29c9;
      break;
    case 3:
      *(undefined4 *)(in_EAX + 0x57c) = 0x29d0;
      *(undefined4 *)(in_EAX + 0x580) = 0x2995;
      *(undefined4 *)(in_EAX + 0x584) = 0x26ea;
      break;
    default:
      goto switchD_008ceae0_default;
    }
    *(undefined4 *)(in_EAX + 0x578) = 0x28;
  }
  else if (iVar1 == 1) {
    switch(*(undefined4 *)(in_EAX + 0x5ac)) {
    case 0:
      *(undefined4 *)(in_EAX + 0x578) = 0x36;
      *(undefined4 *)(in_EAX + 0x57c) = 0x2a16;
      *(undefined4 *)(in_EAX + 0x580) = 0x272c;
      *(undefined4 *)(in_EAX + 0x584) = 0x2738;
      *(undefined4 *)(in_EAX + 0x590) = 0;
      return;
    case 1:
      *(undefined4 *)(in_EAX + 0x578) = 0x36;
      *(undefined4 *)(in_EAX + 0x57c) = 0x2a48;
      *(undefined4 *)(in_EAX + 0x580) = 0x2a54;
      *(undefined4 *)(in_EAX + 0x584) = 0x2a60;
      *(undefined4 *)(in_EAX + 0x590) = 0;
      return;
    case 2:
      *(undefined4 *)(in_EAX + 0x578) = 0x36;
      *(undefined4 *)(in_EAX + 0x57c) = 0x273e;
      *(undefined4 *)(in_EAX + 0x580) = 0x2a18;
      *(undefined4 *)(in_EAX + 0x584) = 0x2a24;
      *(undefined4 *)(in_EAX + 0x590) = 0;
      return;
    case 3:
      *(undefined4 *)(in_EAX + 0x578) = 0x271e;
      *(undefined4 *)(in_EAX + 0x57c) = 0x2a2a;
      *(undefined4 *)(in_EAX + 0x580) = 0x2a36;
      *(undefined4 *)(in_EAX + 0x584) = 0x2a42;
      *(undefined4 *)(in_EAX + 0x590) = 0;
      return;
    }
  }
  else if (iVar1 == 2) {
    switch(*(undefined4 *)(in_EAX + 0x5ac)) {
    case 0:
      *(undefined4 *)(in_EAX + 0x578) = 0x24;
      *(undefined4 *)(in_EAX + 0x57c) = 0x25d4;
      *(undefined4 *)(in_EAX + 0x580) = 0x2935;
      *(undefined4 *)(in_EAX + 0x584) = 0x294b;
      *(undefined4 *)(in_EAX + 0x590) = 0;
      return;
    case 1:
      *(undefined4 *)(in_EAX + 0x578) = 0x25;
      *(undefined4 *)(in_EAX + 0x57c) = 0x25de;
      *(undefined4 *)(in_EAX + 0x580) = 0x25ee;
      *(undefined4 *)(in_EAX + 0x584) = 0x2973;
      *(undefined4 *)(in_EAX + 0x590) = 0;
      return;
    case 2:
      *(undefined4 *)(in_EAX + 0x578) = 0x24;
      *(undefined4 *)(in_EAX + 0x57c) = 0x2965;
      *(undefined4 *)(in_EAX + 0x580) = 0x295d;
      *(undefined4 *)(in_EAX + 0x584) = 0x2941;
      *(undefined4 *)(in_EAX + 0x590) = 0;
      return;
    case 3:
      *(undefined4 *)(in_EAX + 0x578) = 0x24;
      *(undefined4 *)(in_EAX + 0x57c) = 0x291f;
      *(undefined4 *)(in_EAX + 0x580) = 0x25be;
      *(undefined4 *)(in_EAX + 0x584) = 0x292d;
      *(undefined4 *)(in_EAX + 0x590) = 0;
      return;
    }
  }
switchD_008ceae0_default:
  *(undefined4 *)(in_EAX + 0x590) = 0;
  return;
}
```
