# Raw capture: FUN_008ab0a0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ab0a0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008ab0a0` |
| **Canonical name** | `FUN_008ab0a0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_008ab0a0(int param_1)

{
  float fVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  *(undefined4 *)(param_1 + 0x4b8) = 0;
  *(undefined4 *)(param_1 + 0x4bc) = 0;
  *(undefined4 *)(param_1 + 0x4b4) = 0;
  *(undefined4 *)(param_1 + 0x504) = 0;
  *(undefined4 *)(param_1 + 0x508) = 0;
  *(undefined4 *)(param_1 + 0x680) = 0;
  *(undefined4 *)(param_1 + 0x684) = 0;
  *(undefined4 *)(param_1 + 0x688) = 0;
  *(undefined4 *)(param_1 + 0x690) = 0;
  *(undefined4 *)(param_1 + 0x694) = 0;
  *(undefined4 *)(param_1 + 0x6d8) = 0;
  *(undefined4 *)(param_1 + 0x6dc) = 0;
  *(undefined4 *)(param_1 + 0x6e0) = 0;
  *(undefined4 *)(param_1 + 0x68c) = 0;
  *(undefined4 *)(param_1 + 0x6e4) = 0;
  *(undefined4 *)(param_1 + 0x6e8) = 0;
  *(undefined4 *)(param_1 + 0x700) = 0;
  *(undefined4 *)(param_1 + 0x6ec) = 0;
  *(undefined4 *)(param_1 + 0x6f0) = 0;
  *(undefined4 *)(param_1 + 0x6f4) = 0;
  *(undefined4 *)(param_1 + 0x6f8) = 0;
  *(undefined4 *)(param_1 + 0x6fc) = 0;
  *(undefined4 *)(param_1 + 0x644) = 0;
  *(undefined4 *)(param_1 + 0x558) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x55c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x6a8) = 0;
  *(undefined4 *)(param_1 + 0x6b8) = 0;
  *(undefined4 *)(param_1 + 0x6c8) = 0;
  *(undefined4 *)(param_1 + 0x698) = 0;
  *(undefined4 *)(param_1 + 0x560) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x564) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x6ac) = 0;
  *(undefined4 *)(param_1 + 0x6bc) = 0;
  *(undefined4 *)(param_1 + 0x6cc) = 0;
  *(undefined4 *)(param_1 + 0x69c) = 0;
  *(undefined4 *)(param_1 + 0x568) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x56c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x6b0) = 0;
  *(undefined4 *)(param_1 + 0x6c0) = 0;
  *(undefined4 *)(param_1 + 0x6d0) = 0;
  *(undefined4 *)(param_1 + 0x6a0) = 0;
  *(undefined4 *)(param_1 + 0x570) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x574) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x6b4) = 0;
  *(undefined4 *)(param_1 + 0x6c4) = 0;
  *(undefined4 *)(param_1 + 0x6d4) = 0;
  *(undefined4 *)(param_1 + 0x6a4) = 0;
  *(undefined4 *)(param_1 + 0x510) = 0;
  *(undefined4 *)(param_1 + 0x518) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x51c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x708) = 0;
  *(undefined4 *)(param_1 + 0x520) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x524) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x70c) = 0;
  *(undefined4 *)(param_1 + 0x528) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x52c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x710) = 0;
  *(undefined4 *)(param_1 + 0x530) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x534) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x714) = 0;
  *(undefined4 *)(param_1 + 0x538) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x53c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x718) = 0;
  *(undefined4 *)(param_1 + 0x540) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x544) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x71c) = 0;
  *(undefined4 *)(param_1 + 0x548) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x54c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x720) = 0;
  *(undefined4 *)(param_1 + 0x550) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x554) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x724) = 0;
  *(undefined4 *)(param_1 + 0x578) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x57c) = 0xffffffff;
  uVar3 = DAT_00aaa7e8;
  uVar2 = DAT_00a0f71c;
  *(undefined4 *)(param_1 + 0x594) = 0;
  *(undefined4 *)(param_1 + 0x598) = 0;
  *(undefined4 *)(param_1 + 0x59c) = 0;
  fVar1 = g_flOne;
  *(undefined4 *)(param_1 + 0x5a0) = uVar2;
  *(undefined4 *)(param_1 + 0x584) = 0;
  *(float *)(param_1 + 0x588) = fVar1;
  *(undefined4 *)(param_1 + 0x58c) = 0;
  *(undefined4 *)(param_1 + 0x590) = uVar3;
  *(undefined4 *)(param_1 + 0x5a4) = 0;
  *(float *)(param_1 + 0x5a8) = fVar1;
  uVar2 = DAT_00aaa7e4;
  *(undefined4 *)(param_1 + 0x5ac) = 0;
  *(undefined4 *)(param_1 + 0x5b0) = uVar2;
  *(undefined1 *)(param_1 + 0x64c) = 0;
  return;
}
```

---

## R11-035 re-verify append (2026-08-05) — DO NOT WIPE ABOVE

| Field | Value |
|---|---|
| **Agent** | OWN-ONLY dual **R11-035** |
| **Tools** | `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_by_address` + callers/xrefs + `get_assembly_context` + `read_memory` |
| **Live decompile** | **≡** scaffold body above (leaf field pack; no callees) |
| **Body** | `0x008ab0a0`–`0x008ab33d` inclusive (**670 B** / `0x29E`); RET `C3` @ `0x008ab33d`; pad `CC CC` then next `FUN_008ab340` |
| **ABI** | **ECX = NpcMissionDialogHost***; no stack args; plain **`RET`** (`C3`). Frame: `SUB ESP,0x10` / `PUSH ESI` … `POP ESI` / `ADD ESP,0x10` / `RET` |
| **Classification** | **leaf** (no CALL targets) |
| **Call sites** | 1× UNCONDITIONAL_CALL: `Client_NpcMissionDialogHost_Ctor_Inferred` (`FUN_008ac3f0`) @ `008ac505` (`MOV ECX,EDI` @ `008ac4bb` preserved through call) |
| **DATA xref** | `0x00a4a8c8` → ptr `0x008ab0a0` (mission-dialog vtbl `0x00a4a51c` + **0x3AC**) |
| **Globals (read_memory)** | `g_flOne` @ `0x00a0f2a0` = `1.0f`; `DAT_00a0f71c` = `0.6f`; `DAT_00aaa7e8` = `0.157f`; `DAT_00aaa7e4` = `0.549f` |
| **Role** | Mid-ctor **runtime field init/sentinel pack** for NPC mission dialog (`i_d_npc.xml` host): zero widget/chrome ptrs, `−1` TFID/id slots, three float4 defaults, clear turn-in byte `+0x64c` |
| **Name (inferred)** | `Client_NpcMissionDialog_InitRuntimeFields_Inferred` |
| **System** | `missions-progression` |
| **Terminal** | **false** |

### Field groups (sealed offsets)

1. **Zero dword pack:** `+0x4b4/+0x4b8/+0x4bc`, `+0x504/+0x508`, `+0x510`, `+0x644`, chrome/title/list ptrs `+0x680..+0x700` subset, show slots `+0x6f8/+0x6fc`, etc. (see disasm `[ECX+disp],EAX` with `EAX=0`).
2. **4× reward/chrome banks (i=0..3):** pairs `+0x558+i*8` / `+0x55c+i*8` = `−1`; zeros at `+0x698+i*4`, `+0x6a8+i*4`, `+0x6b8+i*4`, `+0x6c8+i*4`.
3. **8× response banks (i=0..7):** TFID pairs `+0x518+i*8` / `+0x51c+i*8` = `−1`; widget slots `+0x708+i*4` = `0`. Extra pair `+0x578/+0x57c` = `−1`.
4. **Float4 defaults (SSE staged via stack):**
   - `+0x594` = `(0, 0, 0, 0.6)` — `DAT_00a0f71c`
   - `+0x584` = `(0, 1.0, 0, 0.157)` — `g_flOne`, `DAT_00aaa7e8`
   - `+0x5a4` = `(0, 1.0, 0, 0.549)` — `g_flOne`, `DAT_00aaa7e4`
5. **Turn-in flag:** `*(uint8_t*)(host+0x64c) = 0` (matches registry `dialogTurnInMode`).

### Assembly seals (no disassemble_bytes)

| Bytes / pattern | Meaning |
|---|---|
| `83 EC 10 56 33 C0` | frame + ESI; EAX=0 |
| `89 81 xx xx 00 00` | store 0 to `[ECX+disp]` |
| `0F 57 C0` | `XORPS XMM0,XMM0` |
| `83 CA FF` | `OR EDX,−1` |
| `89 91 xx xx 00 00` | store `−1` to `[ECX+disp]` |
| `F3 0F 10 0D 1C F7 A0 00` | `MOVSS XMM1,[DAT_00a0f71c]` |
| `F3 0F 10 15 E8 A7 AA 00` | `MOVSS XMM2,[DAT_00aaa7e8]` |
| `F3 0F 10 0D A0 F2 A0 00` | `MOVSS XMM1,[g_flOne]` |
| `F3 0F 10 05 E4 A7 AA 00` | `MOVSS XMM0,[DAT_00aaa7e4]` |
| `88 81 4C 06 00 00` | `MOV [ECX+0x64c],AL` (AL=0) |
| `5E 83 C4 10 C3` | pop ESI; free frame; plain RET |

### Caller seal (`FUN_008ac3f0` @ `008ac505`)

```
008ac4bb  MOV ECX, EDI          ; this = host (EDI)
… stores on [EDI+…] only; ECX preserved …
008ac505  CALL 0x008ab0a0       ; InitRuntimeFields
008ac50a  PUSH 0x00a4b0e0       ; "i_d_npc.xml"
008ac50f  CALL 0x00792980       ; NDUIWindow_ReloadInterface
008ac514  CALL 0x008ac110       ; UI_MissionDialog_BuildResponseButtons_Inferred
```

### Gaps left open

- Product/PDB method name (vtbl+0x3AC English).
- Semantic product names for the three float4 banks (color vs layout).
- Whether vtbl slot is ever dispatched outside ctor path (DATA only sealed).
- Runtime / bit-exact / differential.
