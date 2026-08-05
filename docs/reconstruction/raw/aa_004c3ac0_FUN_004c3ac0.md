# Raw capture: FUN_004c3ac0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c3ac0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004c3ac0` |
| **Canonical name** | `FUN_004c3ac0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int __fastcall FUN_004c3ac0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 4) + 4);
  if ((*(byte *)(iVar1 + 0xb8 + param_1) & 7) == 0) {
    return param_1 + 0x240;
  }
  if (*(int *)(param_1 + 8) != 0) {
    return *(int *)(*(int *)(param_1 + 8) + 0x3c) + 0xb0;
  }
  return iVar1 + param_1 + 0x84;
}
```

---

## W20-O re-verify (2026-07-29) — append only

**Tools:** `decompile_function` @ `0x004c3ac0` + `read_memory` 128 B @ `0x004c3ac0`. No `disassemble_bytes`. No Launcher.

### Live decompile (matches authoritative body)

```c
int __fastcall FUN_004c3ac0(int param_1)
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 4) + 4);
  if ((*(byte *)(iVar1 + 0xb8 + param_1) & 7) == 0) {
    return param_1 + 0x240;
  }
  if (*(int *)(param_1 + 8) != 0) {
    return *(int *)(*(int *)(param_1 + 8) + 0x3c) + 0xb0;
  }
  return iVar1 + param_1 + 0x84;
}
```

### Byte seal (`read_memory` @ `0x004c3ac0`, 47 body bytes)

```
004c3ac0  8B 41 04              mov  eax, [ecx+4]
004c3ac3  8B 50 04              mov  edx, [eax+4]           ; typeOff
004c3ac6  F6 84 0A B8 00 00 00 07
                              test byte ptr [edx+ecx+0xb8], 7
004c3ace  8D 04 0A              lea  eax, [edx+ecx]         ; this+typeOff
004c3ad1  75 07                 jnz  phys_or_embed
004c3ad3  8D 81 40 02 00 00     lea  eax, [ecx+0x240]       ; local override
004c3ad9  C3                    ret
004c3ada  8B 49 08              mov  ecx, [ecx+8]           ; phys link
004c3add  85 C9                 test ecx, ecx
004c3adf  74 09                 jz   embed
004c3ae1  8B 41 3C              mov  eax, [ecx+0x3c]
004c3ae4  05 B0 00 00 00        add  eax, 0xb0              ; *(phys+0x3c)+0xb0
004c3ae9  C3                    ret
004c3aea  05 84 00 00 00        add  eax, 0x84              ; this+typeOff+0x84
004c3aef  C3                    ret
```

| Field | Value |
|---|---|
| Body range | `0x004c3ac0`–`0x004c3aef` (**48 bytes**; last insn `ret` at `0x004c3aef`) |
| ABI | `__fastcall`/`__thiscall` single arg in **ECX**; bare **`ret`** (no stack cleanup) |
| Leaf | **Yes** — no calls |
| Next code | `0x004c3af0` `push ebx` (sibling body) |

### Callers (`get_function_callers` / xrefs)

| Caller | Sites |
|---|---|
| `FUN_005cd3b0` | `0x005cd51f`, `0x005ce807` |
| `FUN_005cedf0` | `0x005cf08b`, `0x005cf18c` |
| `FUN_005d2800` | `0x005d2d46` |
| `FUN_0060a230` | `0x0060a6f2` |
| `FUN_009190d0` | `0x00919199` |

### Role (sealed)

Three-way **active position source pointer** selector for CVOG object:

1. Component flags `(this+typeOff+0xb8) & 7 == 0` → **`this+0x240`** (local override written by sibling `FUN_004c3a40` / `FUN_004cb3e0`).
2. Else if `*(this+8) != 0` → **`*( *(this+8) + 0x3c ) + 0xb0`** (phys/rigid-body position block).
3. Else → **`this + typeOff + 0x84`** (embedded component pose).

Mask **`7`** (bits 0–2) on read path; sibling setter gate uses **`0xC7`**.

Proposed name: **`CVOGObject_GetActivePositionPtr_Inferred`**.
