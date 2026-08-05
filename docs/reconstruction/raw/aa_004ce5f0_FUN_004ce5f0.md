# Raw capture: FUN_004ce5f0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ce5f0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004ce5f0` |
| **Body range** | `0x004ce5f0`–`0x004ce632` (Ghidra `get_function_by_address`) |
| **Canonical name** | `Character_HostModeGateForObjectV210` (structural; Ghidra `FUN_004ce5f0`) |
| **System** | inventory-transfer / equip / hardpoint gates |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
bool __thiscall FUN_004ce5f0(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 != 0) {
    iVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 4 + param_2) + 0x210))(0);
    if (iVar1 != 0) {
      if (*(char *)(param_1 + 0xf5) != '\0') {
        return true;
      }
      return *(char *)(param_1 + 0x7e) != '\0';
    }
  }
  return false;
}
```

---

## Live re-verify append (2026-07-29 W19-F)

| Check | Result |
|---|---|
| `decompile_function` @ `0x004ce5f0` | **≡** raw CF |
| `get_function_by_address` | Body `004ce5f0`–`004ce632` |
| `read_memory` length 80 | Full body hex sealed (see below); epilogue **`ret 4`** (`c2 04 00`) ×3; trailing `cc` pad |
| ABI | **thiscall**: ECX=`param_1` (host), stack arg0=`param_2` (object); callee cleans 4 |
| Callees | **none** (single indirect vcall only) — classification **leaf** |
| Callers (xrefs, 6) | `FUN_004f6890` `0x004f68b4`; `Character_TryEquipItem`/`FUN_004fabc0` `0x004fad1a`; `FUN_004f6a80` `0x004f6ea7`; `Client_SendInventoryDrop_Hardpoint` `0x008634bf` + `0x008634f8`; `FUN_00941b20` `0x00941b60` |

### Byte seal (`read_memory` @ `0x004ce5f0`)

```
8b 44 24 04          mov eax, [esp+4]        ; object
85 c0                test eax, eax
56                   push esi
8b f1                mov esi, ecx            ; host
74 18                jz → false
8b 48 04             mov ecx, [eax+4]
8b 51 04             mov edx, [ecx+4]
8d 4c 02 04          lea ecx, [edx+eax+4]    ; MI this-adjust
8b 01                mov eax, [ecx]          ; vtbl
6a 00                push 0
ff 90 10 02 00 00    call [eax+0x210]
85 c0                test eax, eax
75 06                jnz → host flags
32 c0                xor al, al
5e                   pop esi
c2 04 00             ret 4                   ; false
80 be f5 00 00 00 00 cmp byte [esi+0xf5], 0
74 06                jz → check +0x7e
b0 01                mov al, 1
5e                   pop esi
c2 04 00             ret 4                   ; true
80 7e 7e 00          cmp byte [esi+0x7e], 0
5e                   pop esi
0f 95 c0             setne al
c2 04 00             ret 4                   ; (host+0x7e)!=0
cc…                  int3 pad
```

### Host/object contract (sealed structure)

1. Null **object** → **false**.
2. Else MI-adjust object: `*( *(obj+4)+4 ) + obj + 4`, vcall **`vtbl+0x210(0)`**.
3. Null vcall result → **false**.
4. Non-null vcall: **true** if `host+0xf5 != 0`, else **true** iff `host+0x7e != 0`.

**Parent-seed** `Named_CalleeOf_Client_ConfirmEquipOrCustomizeItem_004ce5f0` is **incomplete** (also equip type-0xe / type-0x10 helpers, hardpoint drop, confirm UI).
