# Raw capture: FUN_004f4eb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f4eb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004f4eb0` |
| **Canonical name** | `FUN_004f4eb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_004f4eb0(int param_1)



{

  int iVar1;

  

  iVar1 = 0;

  do {

    if (*(int *)(iVar1 + *(int *)(param_1 + 0x260)) != 0) {

      FUN_0056a260(0);

      FUN_0056b400(0);

      (**(code **)(**(int **)(iVar1 + *(int *)(param_1 + 0x260)) + 0x18))(0);

    }

    iVar1 = iVar1 + 4;

  } while (iVar1 < 0xc);

  return;

}
```


---

## W24-Q re-verify (2026-07-29) — live Ghidra seal

| Field | Value |
|---|---|
| **Agent** | W24-Q OWN-ONLY dual |
| **Tools** | `decompile_function` + `read_memory` + `get_function_by_address` + callers/callees/xrefs + call-site `read_memory` @ `0x00525560` |
| **Forbidden** | `disassemble_bytes` (not used); Launcher (not used) |
| **Program** | `autoassault.exe` base `0x400000` |
| **Body** | `0x004f4eb0`–`0x004f4efe` (**78 B** exclusive end; Ghidra span) |
| **Classification** | worker |
| **Named role (INFERRED)** | `Vehicle_DeactivateHardpointWeapons_Inferred` |

### Live decompile (authoritative 2026-07-29)

Matches scaffold raw body above (no CF drift):

```c
void __fastcall FUN_004f4eb0(int param_1)
{
  int iVar1;
  iVar1 = 0;
  do {
    if (*(int *)(iVar1 + *(int *)(param_1 + 0x260)) != 0) {
      FUN_0056a260(0);
      FUN_0056b400(0);
      (**(code **)(**(int **)(iVar1 + *(int *)(param_1 + 0x260)) + 0x18))(0);
    }
    iVar1 = iVar1 + 4;
  } while (iVar1 < 0xc);
  return;
}
```

### Machine bytes (`read_memory` len 80 @ `0x004f4eb0`)

```
56 57 8b f9 33 f6 eb 08 8d a4 24 00 00 00 00 90
8b 87 60 02 00 00 8b 0c 06 85 c9 74 27 6a 00 e8 8c 53 07 00
8b 8f 60 02 00 00 8b 0c 31 6a 00 e8 1c 65 07 00
8b 97 60 02 00 00 8b 0c 16 8b 01 6a 00 ff 50 18
83 c6 04 83 fe 0c 7c c4 5f 5e c3 cc
```

| Bytes | Decode |
|---|---|
| `56 57 8B F9` | `push esi; push edi; mov edi, ecx` — **thiscall/fastcall vehicle* in ECX** |
| `33 F6` | `xor esi, esi` — slot cursor 0 |
| `8B 87 60 02 00 00` | `mov eax, [edi+0x260]` — hardpoint table* |
| `8B 0C 06` / `85 C9` / `74 27` | load weapon* at table+esi; null skip |
| `6A 00` + call | `Weapon_SetFireFlagPair_Inferred(weapon, 0)` → `0x0056a260` |
| `6A 00` + call | `Weapon_SetSuppressFlag_Cb_Inferred(weapon, 0)` → `0x0056b400` |
| `6A 00 FF 50 18` | `weapon->vtbl[+0x18](0)` deactivate-class vfunc |
| `83 C6 04` / `83 FE 0C` / `7C C4` | esi += 4; while esi < **0xC** (**3** dword slots) |
| `5F 5E C3` | `pop edi; pop esi; ret` — **no stack cleanup** (thiscall, 0 stack args) |
| trailing `CC` | int3 pad after body |

### Call-site seal (caller `FUN_005252f0` @ `0x00525560`)

```
6a 00 ff 52 18              push 0; call [edx+0x18]
8b 8e 50 02 00 00           mov ecx, [esi+0x250]   ; character/session -> vehicle*
e8 40 f9 fc ff              call FUN_004f4eb0
... mov ecx,edi; [edi+0x2ac]=0  (param_2 vehicle path continues)
```

**ECX** at entry = `*(caller_this + 0x250)` — current vehicle object that owns `+0x260` hardpoint table.

### Call surface (live)

| Role | Symbol | VA |
|---|---|---|
| Caller (sole) | `FUN_005252f0` (vehicle switch / switched-vehicles path) | `0x005252f0` @ `0x0052556b` |
| Callee | `Weapon_SetFireFlagPair_Inferred` | `0x0056a260` arg **0** |
| Callee | `Weapon_SetSuppressFlag_Cb_Inferred` | `0x0056b400` arg **0** |
| Vfunc | hardpoint `vtbl+0x18` | arg **0** |
| Sibling (not owned) | `FUN_004f4f00` activate twin (vfunc+0x18(**1**) / full activate) | `0x004f4f00` |

### Named role (INFERRED)

`Vehicle_DeactivateHardpointWeapons_Inferred` — for each non-null hardpoint weapon under `vehicle+0x260` (3 slots x 4 B = 0xC): clear fire-flag pair, clear suppress flag, call deactivate vfunc(+0x18)(0). Product type English open.
