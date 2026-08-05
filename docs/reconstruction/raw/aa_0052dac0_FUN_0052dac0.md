# Raw capture: FUN_0052dac0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052dac0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0052dac0` |
| **Canonical name** | `FUN_0052dac0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Type propagation algorithm not settling */

int __thiscall FUN_0052dac0(int param_1,undefined4 param_2,char param_3)

{
  int iVar1;
  int local_34 [12];
  undefined1 local_4;
  
  FUN_00538a40(local_34,&param_2);
  if (local_34[0] != *(int *)(param_1 + 0x50c)) {
    return local_34[0] + 0x18;
  }
  if (param_3 != '\0') {
    local_34[9] = 0xffffffff;
    local_34[10] = 0xffffffff;
    local_34[0xb] = 0xffffffff;
    local_34[1] = 0xffffffff;
    local_34[2] = 0xffffffff;
    local_34[3] = 0xffffffff;
    local_34[4] = 0xffffffff;
    local_34[5] = 0xffffffff;
    local_34[6] = 0xffffffff;
    local_34[7] = 0xffffffff;
    local_34[8] = 0xffffffff;
    local_4 = 0;
    iVar1 = FUN_0052c700(param_2,local_34 + 1);
    return iVar1;
  }
  return 0;
}
```

---

## 2026-07-29 re-verify (append only)

| Tool | Result |
|---|---|
| `decompile_function` | Identical to raw body above |
| `force_decompile` | Identical |
| `batch_decompile` | Identical |
| `read_memory` `0x0052dac0` len 160 | Full body; 3x `c2 08 00` (`ret 8`); ends before `0xcc` padding |

**Assembly corrections (not in decompiler text):**

- Before `FUN_00538a40`: `lea ecx,[esi+0x508]` — map object is `this+0x508`, not `this`.
- Sentinel compare: `[esi+0x50c]`.
- Hit: `add eax,0x18` then ret.
- Miss+flag0: `xor eax,eax` then ret.
- Miss+flag1: `call FUN_0052c700` then ret (EAX from callee).
- `FUN_0052c700` @ `0x0052c700` ends `add eax,0x18` / `mov [eax+0x28],ebp` / `ret 8` — returns region*, not void.

**Xrefs (5):** `0x004d0912`, `0x00943a85`, `0x004d5d20`, `0x004d5e90`, `0x004d63f6`.
