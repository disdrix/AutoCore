# Raw capture: FUN_008aa4b0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008aa4b0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008aa4b0` |
| **Canonical name** | `FUN_008aa4b0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_008aa4b0(void)

{
  int *piVar1;
  int iVar2;
  int in_EAX;
  undefined4 uVar3;
  int unaff_ESI;
  
  piVar1 = *(int **)(unaff_ESI + 0x6d8);
  *(int *)(unaff_ESI + 0x644) = in_EAX;
  if (piVar1 != (int *)0x0) {
    if (in_EAX == 0) {
      (**(code **)(*piVar1 + 0x1d8))(&DAT_00a1419b,1,1);
    }
    else {
      iVar2 = *piVar1;
      uVar3 = (**(code **)(*(int *)(*(int *)(*(int *)(in_EAX + 4) + 4) + 4 + in_EAX) + 0x160))(1,1);
      (**(code **)(iVar2 + 0x1d8))(uVar3);
    }
                    /* WARNING: Could not recover jumptable at 0x008aa508. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(unaff_ESI + 0x6d8) + 0x34c))();
    return;
  }
  return;
}
```

---

## MEGA-058 live re-verify (2026-08-05) — APPEND ONLY

| Field | Value |
|---|---|
| **Agent** | OWN-ONLY dual **MEGA-058** |
| **Tools** | Ghidra HTTP `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `disassemble_function` + `read_memory` + `get_function_callers` / `get_function_xrefs` / `get_xrefs_to` + caller `disassemble_function` @ `0x009373e0` + capstone framing @ ShowNpc sites. **No** `disassemble_bytes`. No Launcher. |
| **Program** | `autoassault.exe` image base `0x400000` |
| **Live ≡ scaffold raw** | **Yes** — decompile CF identical to 2026-07-23 capture |

### Body / ABI

| Claim | Evidence |
|---|---|
| Entry `0x008aa4b0` end `0x008aa50e` (RET) | `get_function_by_address`: Body `008aa4b0 - 008aa50e` |
| Size **95 B** / `0x5F` inclusive | `read_memory` 96 B ends `…C3 CC` (pad before sibling `0x008aa510`) |
| Plain **`RET`** (`C3`) | disasm last insn; no `RET n` |
| **ESI** = mission dialog host* | all 3 call sites set ESI before CALL |
| **EAX** = NPC object* (0 = clear) | all 3 call sites load EAX before CALL |
| No stack formals | plain RET; no stack pops in body |

### Full body hex (95 B)

```
8b8ed806000085c9898644060000744e85c0742b8b50048b5204578b398d4402048b106a016a018bc8ff92600100008b8ed806000050ff97d80100005feb118b016a016a01689b41a100ff90d80100008b8ed80600008b11ffa24c030000c3
```

### Live disassembly (authoritative)

```
008aa4b0  MOV ECX,dword ptr [ESI + 0x6d8]
008aa4b6  TEST ECX,ECX
008aa4b8  MOV dword ptr [ESI + 0x644],EAX
008aa4be  JZ 0x008aa50e
008aa4c0  TEST EAX,EAX
008aa4c2  JZ 0x008aa4ef
008aa4c4  MOV EDX,dword ptr [EAX + 0x4]
008aa4c7  MOV EDX,dword ptr [EDX + 0x4]
008aa4ca  PUSH EDI
008aa4cb  MOV EDI,dword ptr [ECX]
008aa4cd  LEA EAX,[EDX + EAX*0x1 + 0x4]
008aa4d1  MOV EDX,dword ptr [EAX]
008aa4d3  PUSH 0x1
008aa4d5  PUSH 0x1
008aa4d7  MOV ECX,EAX
008aa4d9  CALL dword ptr [EDX + 0x160]
008aa4df  MOV ECX,dword ptr [ESI + 0x6d8]
008aa4e5  PUSH EAX
008aa4e6  CALL dword ptr [EDI + 0x1d8]
008aa4ec  POP EDI
008aa4ed  JMP 0x008aa500
008aa4ef  MOV EAX,dword ptr [ECX]
008aa4f1  PUSH 0x1
008aa4f3  PUSH 0x1
008aa4f5  PUSH 0xa1419b
008aa4fa  CALL dword ptr [EAX + 0x1d8]
008aa500  MOV ECX,dword ptr [ESI + 0x6d8]
008aa506  MOV EDX,dword ptr [ECX]
008aa508  JMP dword ptr [EDX + 0x34c]   ; tail-jump refresh (not CALL)
008aa50e  RET
```

### Semantics (sealed)

1. Always store **EAX → `dialog+0x644`** (NPC object stamp; dualed parent ShowNpc compares this to param_2).
2. Load widget **`dialog+0x6d8`**. Null → return (store already done).
3. **EAX == 0 (clear):** widget **vtbl+0x1d8**(`&DAT_00a1419b`, 1, 1) — empty C-string at `0x00a1419b` (`\0`).
4. **EAX != 0 (bind):** COM-style secondary vtbl walk on NPC (`[obj+4]+4` + LEA base) → **vtbl+0x160**(1,1) display-name string; then widget **vtbl+0x1d8**(name) **one stack arg only**.
5. Common tail: **JMP** widget **vtbl+0x34c** (refresh). Decompiler "jumptable" warning is the tail-jump, not a switch.

### Callers / xrefs (3 UNCONDITIONAL_CALL)

| Site | Parent | Framing |
|---|---|---|
| `0x0094397d` | `Client_ShowNpcMissionDialogUI` multi-active journal early path | `MOV EAX,[ESP+0x18]` (param_2 NPC); `MOV ESI,EBX` (dialog) |
| `0x00943a75` | `Client_ShowNpcMissionDialogUI` main present path | `MOV ESI,EBX` earlier; `MOV EAX,[ESP+0x18]` (param_2 NPC) |
| `0x00937411` | `FUN_009373e0` dialog thr/steer/HB park gate | `MOV EAX,[ESP+0x8]` (stack arg); `MOV ESI,[EDI+0x1058]` (dialog from client); then thr0/steer0/HB |

### analyze_function_complete

- classification: **leaf** (no direct FUN_* callees; virtual only)
- callers: `Client_ShowNpcMissionDialogUI`, `FUN_009373e0`
- xref_count: **3**
- return_type decompiler `void` OK (plain RET; EAX not a product return)

### DAT_00a1419b

Shared empty C-string (`00`); widely xreffed as clear-text constant (also header clear paths use 0-push equivalently).

### Name

Canonical (Inferred): **`MissionDialog_SetNpcObjectAndNameCaption_Inferred`**.  
Retire scaffold `Named_CalleeOf_Client_ShowNpcMissionDialogUI_008aa4b0` (incomplete call surface — also `FUN_009373e0`).

