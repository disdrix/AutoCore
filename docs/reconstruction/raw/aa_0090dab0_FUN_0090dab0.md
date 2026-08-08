# Raw capture: FUN_0090dab0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0090dab0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0090dab0` |
| **Canonical name** | `FUN_0090dab0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0090dab0(void)

{
  undefined4 *puVar1;
  
  puVar1 = &DAT_00d09a38;
  do {
    FUN_0090d400();
    puVar1 = puVar1 + 1;
  } while ((int)puVar1 < 0xd09a4c);
  return;
}
```

---

## MEGA-097 live re-verify (2026-08-05) — APPEND ONLY

| Field | Value |
|---|---|
| **Agent** | OWN-ONLY dual **MEGA-097** |
| **Tools** | Ghidra HTTP `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_by_address` + `get_function_callers` + `get_function_callees` + `get_xrefs_to` + `get_function_xrefs` + `get_function_signature` + `get_function_hash` + `read_memory` |
| **Forbidden** | `disassemble_bytes` (not used); Launcher; parent ledgers; other VAs dualled |
| **Image** | `autoassault.exe` base `0x400000` |
| **Terminal** | **false** |

### Body / size

| Item | Value |
|---|---|
| Entry | `0x0090dab0` |
| Last insn | `0x0090dad5` `RET` (`C3`) |
| Inclusive span | `0x0090dab0`–`0x0090dad5` (**38 B** / `0x26`) |
| Pad | `CC` ×10 @ `0x0090dad6`–`0x0090dadf` before next leaf @ `0x0090dae0` |
| Hash | `85eba3a5607c2d050e7ad06d4d91c1b972c0ad3068bf2b9e0afb7aed66ca8961` |
| Signature tool | `instruction_count=15`, `basic_block_count=3`, `call_count=1`, `param_count=0` (Ghidra prototype incomplete — see ABI) |

### Live decompile (≡ 2026-07-23 raw CF)

```c
void FUN_0090dab0(void)

{
  undefined4 *puVar1;
  
  puVar1 = &DAT_00d09a38;
  do {
    FUN_0090d400();
    puVar1 = puVar1 + 1;
  } while ((int)puVar1 < 0xd09a4c);
  return;
}
```

**Decompiler gap:** omits `MOV EDI,EAX` host capture and `MOV ESI,[EBX]` slot load; callee `FUN_0090d400` consumes **ESI** (window*) + **EDI** (host*). Authority = disassembly + call-site reload.

### Disassembly (authority)

```text
0090dab0  PUSH EBX
0090dab1  PUSH ESI
0090dab2  PUSH EDI
0090dab3  MOV  EDI,EAX          ; host* from EAX (not ECX)
0090dab5  MOV  EBX,0xd09a38     ; DAT_00d09a38 table base
0090daba  LEA  EBX,[EBX]        ; nop-form align
0090dac0  MOV  ESI,dword ptr [EBX]
0090dac2  CALL 0x0090d400       ; dismiss-if-active slot (ESI/EDI)
0090dac7  ADD  EBX,0x4
0090daca  CMP  EBX,0xd09a4c     ; exclusive end (5 dwords)
0090dad0  JL   0x0090dac0
0090dad2  POP  EDI
0090dad3  POP  ESI
0090dad4  POP  EBX
0090dad5  RET                   ; bare C3 — no stack args
```

### Machine bytes (`read_memory` entry, 38 B)

```text
53 56 57 8B F8 BB 38 9A D0 00 8D 9B 00 00 00 00
8B 33 E8 39 F9 FF FF 83 C3 04 81 FB 4C 9A D0 00
7C EE 5F 5E 5B C3
```

### ABI (sealed)

| Formal | Source | Conf |
|---|---|---|
| host / client object | **EAX** → EDI (`8B F8`) | **High** |
| stack args | none | **High** |
| return | void (bare `C3`) | **High** |
| calling convention | custom **EAX-this** (not ECX thiscall) | **High** |

Call-site proof (both UNCONDITIONAL_CALL xrefs):

| Site | Bytes | Decode |
|---|---|---|
| `0x00911070` in `Client_Input_OnKeyDown_MatchAction` | `85 C0 74 13 8B C3 E8 36 CA FF FF … B0 01` | after `FUN_0090d390` TEST EAX; **MOV EAX,EBX**; CALL `0090dab0`; return 1 |
| `0x00911893` | `8B C3 E8 18 C2 FF FF B0 01` | **MOV EAX,EBX**; CALL `0090dab0`; MOV AL,1 |

Parent keeps client host in **EBX**; reloads **EAX=EBX** before each call (return of `0090d390` is only for the null gate, not the host arg).

### Table `DAT_00d09a38` (evidence)

| Item | Value |
|---|---|
| Base | `0x00d09a38` |
| Exclusive end | `0x00d09a4c` |
| Count | **5** dword slots (stride 4) |
| Role | global UI window* table |
| Init (xref WRITE `FUN_0093e7e0`) | five `operator_new` + ctors → `DAT_00d09a38`..`DAT_00d09a48` sizes `0x554/0x5d8/0x604/0x54c/0x588` |
| Sibling finder | `FUN_0090d390` — first non-null slot with vtbl+`0x3d8` true |
| Teardown peer | `FUN_00935a30` walks same range, vcall dtor flags=1, nulls slots |

### Callee `FUN_0090d400` (evidence only; not dualled)

Disasm-sealed contract when ESI≠0 and ESI→vtbl+`0x3d8`():

1. ESI→vtbl+`0xcc`(0)
2. ESI→vtbl+`0x440`()
3. EDI→vtbl+`0xb0`(ESI)  — **PUSH ESI** (decompile wrongly showed 0)
4. if `DAT_00d1b978` active: EDI→vtbl+`0x3bc`(`DAT_00d1b978`)
5. EDI→vtbl+`0x3f4`(-1)

### Callers / xrefs

| Kind | Value |
|---|---|
| Callers (tool) | `Client_Input_OnKeyDown_MatchAction` @ `0x00911030` |
| Xrefs to entry | **2** UNCONDITIONAL_CALL: `0x00911075`, `0x00911893` |
| Callees | `FUN_0090d400` @ `0x0090d400` only |
| Parent path | ESC (`param_2==0x1b`) + client vtbl+`0x3d8` + `*(client+0x50d)==0` → set `+0x50d=1` → if `FUN_0090d390()!=0` → **this** → return 1 |

### analyze_function_complete (summary)

| Field | Value |
|---|---|
| classification | wrapper |
| return_type_warning | `undefined` — void sealed by bare RET + no EAX produce |
| completeness_score | ~4.4 (scaffold; renamed in MEGA-097) |

### Semantics (sealed structural)

For host in EAX: walk 5-slot UI window table `DAT_00d09a38`..`<0xd09a4c`; for each slot invoke `FUN_0090d400` (dismiss-if-active + host notify). Used on ESC UI-cancel path when any table window is active.

### Name (MEGA-097)

`Client_Input_DismissUiWindowTable5_Inferred` (product English for individual window types / vtbl methods open → `_Inferred`). Scaffold `Named_CalleeOf_Client_Input_OnKeyDown_MatchAction_0090dab0` **retired**.
