# Raw capture: FUN_008e5ce0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008e5ce0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008e5ce0` |
| **Canonical name** | `FUN_008e5ce0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_008e5ce0(undefined4 param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  if ((param_2 & param_3) == 0xffffffff) {
    FUN_008e5990(0);
    return;
  }
  if (DAT_00d1b6d8 != 0) {
    iVar3 = 0;
    if (((((*(int *)(DAT_00d1b6d8 + 0x250) == 0) ||
          (*(int *)(*(int *)(DAT_00d1b6d8 + 0x250) + 0x2b0) == 0)) ||
         (iVar3 = FUN_00571010(param_2,param_3), iVar3 == 0)) ||
        ((*(uint *)(iVar3 + 0x17c) >> 0x13 & 1) == 0)) &&
       ((*(int *)(DAT_00d1b6d8 + 0xcbc) != 0 && (*(char *)(DAT_00d1b644 + 0xf5) != '\0')))) {
      iVar3 = FUN_00571010(param_2,param_3);
    }
    if ((iVar3 == 0) || ((*(uint *)(iVar3 + 0x17c) >> 0x13 & 1) == 0)) {
      iVar3 = FUN_00522000();
      uVar4 = 0;
      if (iVar3 < 1) {
        return;
      }
      while( true ) {
        uVar1 = *(uint *)(DAT_00d1b6d8 + 0x5a0 + (uVar4 & 0xff) * 8);
        uVar2 = *(uint *)(DAT_00d1b6d8 + 0x5a4 + (uVar4 & 0xff) * 8);
        if ((((uVar1 & uVar2) != 0xffffffff) && (uVar1 == param_2)) && (uVar2 == param_3)) break;
        uVar4 = uVar4 + 1;
        if (iVar3 <= (int)uVar4) {
          return;
        }
      }
      iVar3 = CVOGReaction_ResolveObjectTarget(1,uVar1,uVar2);
    }
    if (iVar3 != 0) {
      FUN_008e5990(iVar3);
    }
  }
  return;
}
```

---

## Re-verify (WQ8R-H, 2026-08-04)

| Field | Value |
|---|---|
| **Tools** | `batch_decompile` + `force_decompile` + `analyze_function_complete` + `read_memory` + `get_assembly_context`. **No** `disassemble_bytes`. |
| **Body** | `0x008e5ce0`–`0x008e5df3` (275 B / `0x113`; pad `CC`) |
| **Prologue hex (64 B)** | `568b742410578b7c24108bc723c683f8ff75108b4c240c6a00e892fcffff5f5ec20c008b0dd8b6d10085c90f84de0000008b895002000033c085c974238b89b0` |
| **ABI (bytes win)** | **stdcall** `RET 0xC` — stack: `host`, `coidLo`, `coidHi`. Prologue maps **EDI**=lo, **ESI**=hi. Invalid TFID (`lo & hi == 0xFFFFFFFF`) → `thiscall FUN_008e5990(host, NULL)`. |
| **force ≡ batch** | Yes. |
| **Callers** | Inside `FUN_008e5e00` @ `008e6345`; second site @ `008e82ef` (panel message path). Both push TFID from widget vtbl+0x44c then host. |

