# Raw capture: Client_SendInventoryEquipC2S

| Field | Value |
|---|---|
| **Stable ID** | `aa_00931440` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00931440` |
| **Body** | `0x00931440`–`0x009314ec` |
| **Canonical name** | `Client_SendInventoryEquipC2S` |
| **Ghidra name** | `FUN_00931440` |
| **System** | `inventory-transfer` |
| **Capture timestamp** | `2026-07-29` (W19-T dual re-seal) |
| **Tool** | Ghidra MCP `decompile_function` + `read_memory` |
| **Integrity** | Authoritative live decompile for dual seal; scaffold raw retained at `aa_00931440_FUN_00931440.md` |

---

## Raw pseudocode (authoritative decompile 2026-07-29)

```c
undefined4 __thiscall FUN_00931440(int param_1,undefined1 param_2)

{
  int in_EAX;
  undefined4 local_50 [2];
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40 [2];
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 local_8;
  undefined1 local_5;
  
  if (*(int *)(*(int *)(in_EAX + 0xa8) + 0x38) == 0xe) {
    local_48 = *(undefined4 *)(in_EAX + 0x160);
    local_44 = *(undefined4 *)(in_EAX + 0x164);
    local_50[0] = 0x2053;
    if (*(int *)(param_1 + 0xc78) != 0) {
      (**(code **)(**(int **)(param_1 + 0xc78) + 0x18))(0xffffffff,local_50,0x10,0);
      return 0;
    }
  }
  else {
    local_38 = *(undefined4 *)(in_EAX + 0x160);
    local_34 = *(undefined4 *)(in_EAX + 0x164);
    local_30 = *(undefined4 *)(in_EAX + 0x168);
    local_2c = *(undefined4 *)(in_EAX + 0x16c);
    local_40[0] = 0x203c;
    local_8 = 0;
    local_5 = param_2;
    if (*(int *)(param_1 + 0xc78) != 0) {
      (**(code **)(**(int **)(param_1 + 0xc78) + 0x18))(0xffffffff,local_40,0x40,0);
    }
  }
  return 0;
}
```

---

## Entry / body bytes (`read_memory`)

### Prologue @ `0x00931440`

```
8b90 a8000000     mov edx, [eax+0xa8]     ; item clonebase from EAX
83ec 50           sub esp, 0x50
837a 38 0e        cmp dword [edx+0x38], 0xe
...
83b9 780c0000 00  cmp dword [ecx+0xc78], 0 ; client net iface from ECX
```

### Epilogue @ `0x009314e0` region

```
33c0              xor eax, eax            ; return 0
83c4 50           add esp, 0x50
c2 04 00          ret 4                   ; one stack arg (mode)
```

**ABI sealed from bytes:**

| Register / stack | Role |
|---|---|
| **EAX** | item* (`in_EAX` in decompile) |
| **ECX** | client* (`param_1` / this) |
| **`[esp+4]` after call** | mode byte (`param_2`) |
| Return | always **0** in EAX |
| Exit | **`RET 4`** |

Live decompile **≡** 2026-07-23 scaffold raw (no CF delta).
