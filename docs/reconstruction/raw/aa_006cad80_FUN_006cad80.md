# Raw capture: FUN_006cad80

| Field | Value |
|---|---|
| **Stable ID** | `aa_006cad80` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006cad80` |
| **Body range** | `0x006cad80`–`0x006cae18` (exclusive end `0x006cae19`) |
| **Canonical name** | `WorldCast_SetupCollectorAndDispatch_Inferred` (structural; Ghidra `FUN_006cad80`) |
| **System** | world / map collision cast |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall
FUN_006cad80(int param_1,int *param_2,undefined4 *param_3,int param_4,undefined4 param_5,
            undefined4 param_6)

{
  int iVar1;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 *local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  *(undefined4 **)(param_1 + 4) = param_3;
  *(undefined4 *)(param_1 + 0xc) = param_6;
  if (param_4 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_4 + 0x14;
  }
  *(int *)(param_1 + 8) = iVar1;
  if (*(char *)(param_3 + 8) == '\0') {
    *(undefined4 *)(param_1 + 0x34) = 0;
  }
  else if (param_4 == 0) {
    *(undefined4 *)(param_1 + 0x34) = 0;
  }
  else {
    *(int *)(param_1 + 0x34) = param_4 + 0x10;
  }
  local_30 = *param_3;
  local_2c = param_3[1];
  local_28 = param_3[2];
  local_24 = param_3[3];
  local_1c = param_3 + 4;
  local_14 = param_5;
  local_20 = 1;
  local_18 = 0x10;
  (**(code **)(*param_2 + 0x30))(&local_30,param_1,0);
  return;
}
```

---

## Live re-verify append (2026-07-29 W19-M)

| Check | Result |
|---|---|
| `decompile_function` @ `0x006cad80` | ≡ raw body above |
| `get_function_by_address` | Body `006cad80`–`006cae18` (excl. `006cae19`) |
| `read_memory` @ entry + epilogue | Prologue `55 8b ec 83 e4 f0 83 ec 2c`; epilogue **`c2 14 00`** (`ret 0x14`) |
| ABI | **`__thiscall`**: ECX=collector; **5 stack dwords** (world*, ray*, filter*, extra, result*); **`ret 0x14`** |
| Callees | Indirect only: `world->vtbl[+0x30]` thiscall with packet + collector + `0` |
| Callers (`get_function_xrefs`) | Sole CODE: `FUN_0055e530` @ `0x0055e565` (`MapCollisionCtx_CastRay`) |
| Byte seal ray flag | `8a 50 20` = load **`ray+0x20`** (decompiler `param_3+8` as `undefined4*` ≡ +0x20) |
| Byte seal vcall | `ff 52 30` = `call [edx+0x30]` after `mov ecx, world` |

**Not** vehicle phantom cast (`TtPhantom::castRay` @ `0x00580ed0`).
