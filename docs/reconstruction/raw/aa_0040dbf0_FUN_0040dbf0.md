# Raw capture: FUN_0040dbf0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040dbf0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0040dbf0` |
| **Canonical name** | `FUN_0040dbf0` |
| **System** | util / container (std::vector&lt;dword&gt;) |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_0040dbf0(int param_1,int *param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 == 0) || (*(int *)(param_1 + 8) - iVar1 >> 2 == 0)) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_3 - iVar1 >> 2;
  }
  FUN_004073a0(param_3,1,param_4);
  *param_2 = *(int *)(param_1 + 4) + iVar1 * 4;
  return;
}
```

---

## Live re-decompile (2026-07-29, W16-G)

Tool: Ghidra MCP `decompile_function` @ `0x0040dbf0` program `autoassault.exe`.

**Body ≡ original raw** (control flow identical; Ghidra still elides `this` on the `FUN_004073a0` call site — callee is `__thiscall` with `ECX = param_1`).

```c
void __thiscall FUN_0040dbf0(int param_1,int *param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 == 0) || (*(int *)(param_1 + 8) - iVar1 >> 2 == 0)) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_3 - iVar1 >> 2;
  }
  FUN_004073a0(param_3,1,param_4);
  *param_2 = *(int *)(param_1 + 4) + iVar1 * 4;
  return;
}
```

### Bytes (`read_memory` 70 B @ `0x0040dbf0`)

```
56 57 8B F9 8B 47 04 85 C0 8B 4C 24 10 74 0E 8B 57 08 2B D0 C1 FA 02
89 54 24 10 75 04 33 F6 EB 07 8B F1 2B F0 C1 FE 02 8B 44 24 14 50 6A 01
51 8B CF E8 79 97 FF FF 8B 4F 04 8B 44 24 0C 8D 14 B1 5F 89 10 5E C2 0C 00
```

- Ends **`C2 0C 00`** (`ret 0x0C` — three stack dwords cleaned by callee).
- Count imm **`6A 01`** (`push 1`).
- Call target relative → `FUN_004073a0` (`E8 79 97 FF FF`).
- Rebind: `lea edx,[ecx+esi*4]` then `mov [eax],edx` (`*outIt = begin' + index*4`).
