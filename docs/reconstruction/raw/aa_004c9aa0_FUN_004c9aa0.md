# Raw capture: FUN_004c9aa0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c9aa0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004c9aa0` |
| **Canonical name** | `FUN_004c9aa0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * __thiscall FUN_004c9aa0(undefined4 *param_1,int param_2)

{
  float fVar1;
  undefined4 uVar2;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a1d1c;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (param_2 != 0) {
    ExceptionList = &local_c;
    param_1[1] = &DAT_009d4d14;
    param_1[0x11] = &DAT_009d4d0c;
    FUN_00518940();
    local_4 = 0;
  }
  FUN_005c82a0(0);
  uVar2 = DAT_00aaa7a4;
  *param_1 = &PTR_LAB_009cbe74;
  param_1[0x10] = &PTR_CVOGCreature_SetupGraphics_009cbe38;
  *(undefined ***)(*(int *)(param_1[1] + 4) + 4 + (int)param_1) = &PTR_LAB_009cbb74;
  *(int *)(*(int *)(param_1[1] + 4) + (int)param_1) = *(int *)(param_1[1] + 4) + -0x4fc;
  *(undefined1 *)(param_1 + 0x40) = 1;
  param_1[0x42] = DAT_009cb8c0;
  param_1[0x43] = DAT_009cb8c4;
  param_1[0x44] = DAT_009cb8c8;
  uVar5 = DAT_009cb8cc;
  local_4 = 1;
  *(undefined2 *)(param_1 + 0x4f) = 1;
  *(undefined2 *)((int)param_1 + 0x13e) = 1;
  *(undefined2 *)(param_1 + 0x50) = 1;
  *(undefined2 *)((int)param_1 + 0x142) = 1;
  param_1[0x45] = uVar5;
  param_1[0x49] = uVar2;
  fVar1 = g_flOne;
  param_1[0x46] = 0;
  param_1[0x48] = 0;
  param_1[0x4a] = 0xffffffff;
  *(undefined2 *)(param_1 + 0x4b) = 0;
  *(undefined2 *)((int)param_1 + 0x12e) = 10;
  param_1[0x4c] = fVar1;
  param_1[0x4d] = 0;
  param_1[0x4e] = 0;
  *(undefined2 *)(param_1 + 0x51) = 0;
  *(undefined2 *)((int)param_1 + 0x146) = 0;
  *(undefined2 *)(param_1 + 0x52) = 0;
  *(undefined2 *)((int)param_1 + 0x14a) = 0;
  *(undefined1 *)(param_1 + 0x53) = 0;
  param_1[0x54] = 0;
  iVar3 = FUN_0058d9c0();
  param_1[0x56] = iVar3;
  *(undefined1 *)(iVar3 + 0x29) = 1;
  *(undefined4 *)(param_1[0x56] + 4) = param_1[0x56];
  *(undefined4 *)param_1[0x56] = param_1[0x56];
  *(undefined4 *)(param_1[0x56] + 8) = param_1[0x56];
  param_1[0x57] = 0;
  param_1[0x58] = 0;
  param_1[0x6f] = 0;
  param_1[0x70] = 0;
  param_1[0x71] = 0;
  param_1[0x73] = 0;
  param_1[0x74] = 0;
  param_1[0x75] = 0;
  fVar1 = g_flOne;
  param_1[0x76] = 0;
  param_1[0x77] = 0;
  param_1[0x78] = 0;
  param_1[0x79] = 0;
  param_1[0x7a] = fVar1;
  param_1[0x7b] = 0;
  param_1[0x7d] = 0;
  param_1[0x7f] = 0;
  param_1[0x80] = 0;
  *(undefined1 *)(param_1 + 0x81) = 0;
  *(undefined1 *)((int)param_1 + 0x205) = 0;
  *(undefined1 *)((int)param_1 + 0x206) = 0;
  *(undefined1 *)((int)param_1 + 0x207) = 0;
  param_1[0x82] = 0;
  param_1[0x84] = 0xffffffff;
  param_1[0x85] = 0xffffffff;
  param_1[0x86] = 0xffffffff;
  param_1[0x87] = 0xffffffff;
  param_1[0x88] = 0xffffffff;
  param_1[0x89] = 0xffffffff;
  param_1[0x8a] = DAT_009cb8c0;
  param_1[0x8b] = DAT_009cb8c4;
  param_1[0x8c] = DAT_009cb8c8;
  uVar5 = DAT_009cb8cc;
  param_1[0x97] = 0;
  param_1[0x98] = 0;
  param_1[0x99] = 0;
  param_1[0x9a] = 0;
  uVar2 = DAT_00a0f524;
  param_1[0x8d] = uVar5;
  param_1[0x94] = 0;
  param_1[0x95] = 0;
  param_1[0x96] = 0;
  *(undefined1 *)(param_1 + 0x9b) = 0;
  param_1[0x9c] = uVar2;
  param_1[0x9d] = uVar2;
  *(undefined1 *)(param_1 + 0x9e) = 0;
  *(undefined1 *)((int)param_1 + 0x279) = 0;
  param_1[0xb9] = 0;
  param_1[0xba] = 0;
  param_1[0xbb] = 0;
  param_1[0xbe] = 0;
  param_1[0xbf] = 0;
  param_1[0xc0] = 0;
  uVar5 = DAT_00aaaa24;
  local_4._0_1_ = 6;
  *(undefined1 *)(param_1 + 0xc1) = 0;
  *(undefined1 *)((int)param_1 + 0x305) = 0;
  *(undefined1 *)((int)param_1 + 0x306) = 0;
  *(undefined1 *)((int)param_1 + 0x307) = 0;
  *(undefined1 *)(param_1 + 0xc2) = 0;
  *(undefined1 *)((int)param_1 + 0x309) = 1;
  *(undefined1 *)((int)param_1 + 0x30a) = 0;
  *(undefined1 *)((int)param_1 + 0x30b) = 0;
  *(undefined1 *)(param_1 + 0xc3) = 0;
  param_1[0xc4] = uVar5;
  *(undefined1 *)(param_1 + 0xc5) = 0;
  *(undefined1 *)((int)param_1 + 0x315) = 0;
  param_1[0xc6] = 0;
  FUN_0096e0e0();
  param_1[0x90] = 0;
  param_1[0x91] = 0;
  param_1[0x92] = 0;
  param_1[0x93] = 0;
  param_1[0x59] = 0;
  param_1[0x5a] = 0;
  param_1[0x5b] = 0;
  param_1[0x5c] = 0;
  param_1[0x5d] = 0;
  param_1[0x5e] = 0;
  param_1[0x5f] = 0;
  param_1[0x60] = 0;
  param_1[0x61] = 0;
  local_4._0_1_ = 7;
  param_1[0x62] = 0;
  param_1[99] = 0;
  param_1[100] = 0;
  param_1[0x65] = 0;
  param_1[0x66] = 0;
  param_1[0x67] = 0;
  param_1[0x68] = 0;
  param_1[0x69] = 0;
  param_1[0x6a] = 0;
  param_1[0x6b] = 0;
  param_1[0x6c] = 0;
  param_1[0x6d] = 0;
  param_1[199] = 0;
  param_1[200] = 0;
  param_1[0xc9] = 0;
  param_1[0xca] = 0;
  param_1[0xcb] = 0;
  param_1[0xcc] = 0;
  param_1[0xcd] = 0;
  param_1[0xce] = 0;
  param_1[0xcf] = 0;
  param_1[0xd0] = 0;
  param_1[0xd1] = 0;
  param_1[0xd2] = 0;
  param_1[0xd3] = 0;
  param_1[0xd4] = 0;
  param_1[0xd5] = 0;
  param_1[0xd6] = 0;
  param_1[0xd7] = 0;
  param_1[0xd8] = 0;
  param_1[0xd9] = 0;
  param_1[0xda] = 0;
  param_1[0xdb] = 0;
  param_1[0xdc] = 0;
  param_1[0xdd] = 0;
  param_1[0xde] = 0;
  pvVar4 = operator_new(0x60);
  local_4 = CONCAT31(local_4._1_3_,8);
  if (pvVar4 == (void *)0x0) {
    uVar5 = 0;
  }
  else {
    uVar5 = FUN_005d55f0(param_1,0);
  }
  param_1[0x3e] = uVar5;
  param_1[0xb7] = 0xffffffff;
  param_1[0xa0] = 0;
  param_1[0xa1] = 0;
  param_1[0xa2] = 0;
  param_1[0xa3] = 0;
  param_1[0x9f] = 0;
  param_1[0x47] = 0;
  *(undefined1 *)(param_1 + 0x13) = 0;
  param_1[0x2e] = 0;
  puVar6 = param_1 + 0xa4;
  iVar3 = 0x13;
  do {
    puVar6[-0x89] = 0;
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(undefined1 *)(param_1 + 0xbc) = 0;
  ExceptionList = local_c;
  return param_1;
}
```

---

## Live re-capture 2026-07-29 (W21-F dual seal)

| Field | Value |
|---|---|
| **Tool** | Ghidra MCP `decompile_function` + `read_memory` + `get_xrefs_to` + `get_assembly_context` |
| **Program** | `autoassault.exe` |
| **Body** | `0x004c9aa0`–`0x004c9f7b` |
| **Decompile CF** | **≡** 2026-07-23 raw (mostDerived gate, base `FUN_005c82a0(0)`, creature vtbls, field init, `new(0x60)+FUN_005d55f0`, twin zero loop) |
| **Epilogue** | `read_memory` @ `0x004c9f50`: `8B C6 … C2 04 00` — return `this` in EAX; **`ret 4`** |

### Entry image (`read_memory` @ `0x004c9aa0`, 128 bytes) — sealed spine

```
6A FF                 push -1
68 1C 1D 9A 00        push &LAB_009a1d1c   ; EH
64 A1 00 00 00 00     mov eax, fs:[0]
50                    push eax
64 89 25 00 00 00 00  mov fs:[0], esp
83 EC 08              sub esp, 8
53                    push ebx
33 DB                 xor ebx, ebx
56                    push esi
8B F1                 mov esi, ecx           ; this
89 5C 24 08           mov [esp+8], ebx       ; local_4-ish / zero
39 5C 24 20           cmp [esp+0x20], ebx    ; mostDerivedFlag vs 0
57                    push edi
89 74 24 10           mov [esp+0x10], esi
74 28                 jz  skip_mostDerived
8D 8E 00 05 00 00     lea ecx, [esi+0x500]
C7 46 04 14 4D 9D 00  mov dword [esi+4],  DAT_009d4d14
C7 46 44 0C 4D 9D 00  mov dword [esi+0x44], DAT_009d4d0c  ; param_1[0x11]
E8 …                  call FUN_00518940
…
55 53 8B CE E8 …      push/ call FUN_005c82a0(0)  ; parent base ctor
C7 06 74 BE 9C 00     mov [esi], PTR_LAB_009cbe74
C7 46 40 38 BE 9C 00  mov [esi+0x40], PTR_CVOGCreature_SetupGraphics_009cbe38
```

### Factory / call sites (xrefs + assembly context)

| Site | Caller | Pattern |
|---|---|---|
| `0x00564ffe` | `CVOGSpawnPoint_CreateCreature` | `new(0x690)` + `push 1; call` (type **0x12** template arm) |
| `0x0051a3d9` | `CVOGReaction_GiveItemByCbid` | `push 0x690` / `push 1; call` |
| `0x00620574` | `FUN_00620480` Skill_SpawnTemplateAndStartHB | `new(0x690)` + `push 1` |
| `0x005686cc` | `FUN_00568670` | `push 1; call` after `operator_new` |
| `0x00503935` | `FUN_00503780` | `push 1; call` |
| `0x004ca3de` | `FUN_004ca150` | `push 1; call` |
| `0x00855b58` | `FUN_00855810` | `push 1; call` |
| `0x00536976` | `FUN_00536920` CVOGCharacter_ctor | `push 0` (ebx) — **base subobject**, not most-derived |

### Constants (`read_memory`)

| Sym | VA | Bytes / note |
|---|---|---|
| `DAT_009cb8c0..cc` | `0x009cb8c0` | `FF FF FF FF FF FF FF FF 00 00 00 00 00 00 00 00` (quat-ish default) |
| `DAT_00aaa7a4` | `0x00aaa7a4` | `00 00 70 41` = float **15.0f** |
| Vtbl primary | `0x009cbe74` | first slot → `0x004c60a0` |
| SetupGraphics vtbl | `0x009cbe38` | named `PTR_CVOGCreature_SetupGraphics_009cbe38`; slot0 → `0x004c8b60` SetupGraphics |

### Object size (factory sealed)

Heap allocation for most-derived creature instances: **`0x690`** bytes (`operator_new(0x690)` at CreateCreature / GiveItem / Skill spawn).

