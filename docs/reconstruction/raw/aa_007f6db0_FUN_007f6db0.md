# Raw capture: FUN_007f6db0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007f6db0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007f6db0` |
| **Canonical name** | `FUN_007f6db0` |
| **System** | input-drive-control |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int __fastcall FUN_007f6db0(undefined4 param_1,short param_2)

{
  undefined4 in_EAX;
  short *psVar1;
  int iVar2;
  short unaff_SI;
  int unaff_EDI;
  
  switch(in_EAX) {
  case 0:
    iVar2 = 0;
    psVar1 = (short *)(unaff_EDI + 0x30);
    do {
      if (psVar1[-0x15] == unaff_SI) {
        if (param_2 == 0) {
          if (*psVar1 == 0) goto LAB_007f6dd2;
        }
        else if (*psVar1 != 0) goto LAB_007f6dd2;
        if ((char)psVar1[3] != '\0') {
LAB_007f6dd2:
          return unaff_EDI + 6 + iVar2 * 0x34;
        }
      }
      if (psVar1[-0x14] == unaff_SI) {
        if (param_2 == 0) {
          if (psVar1[1] == 0) goto LAB_007f6e02;
        }
        else if (psVar1[1] != 0) goto LAB_007f6e02;
        if ((char)psVar1[3] != '\0') {
LAB_007f6e02:
          return unaff_EDI + 6 + iVar2 * 0x34;
        }
      }
      iVar2 = iVar2 + 1;
      psVar1 = psVar1 + 0x1a;
    } while (iVar2 < 5);
    break;
  case 1:
    iVar2 = 0;
    psVar1 = (short *)(unaff_EDI + 0x134);
    do {
      if (psVar1[-0x15] == unaff_SI) {
        if (param_2 == 0) {
          if (*psVar1 == 0) goto LAB_007f6e48;
        }
        else if (*psVar1 != 0) goto LAB_007f6e48;
        if ((char)psVar1[3] != '\0') {
LAB_007f6e48:
          return unaff_EDI + 0x10a + iVar2 * 0x34;
        }
      }
      if (psVar1[-0x14] == unaff_SI) {
        if (param_2 == 0) {
          if (psVar1[1] == 0) goto LAB_007f6e7b;
        }
        else if (psVar1[1] != 0) goto LAB_007f6e7b;
        if ((char)psVar1[3] != '\0') {
LAB_007f6e7b:
          return unaff_EDI + 0x10a + iVar2 * 0x34;
        }
      }
      iVar2 = iVar2 + 1;
      psVar1 = psVar1 + 0x1a;
      if (5 < iVar2) {
        return 0;
      }
    } while( true );
  case 2:
    iVar2 = 0;
    psVar1 = (short *)(unaff_EDI + 0x26c);
    do {
      if (psVar1[-0x15] == unaff_SI) {
        if (param_2 == 0) {
          if (*psVar1 == 0) goto LAB_007f6ec4;
        }
        else if (*psVar1 != 0) goto LAB_007f6ec4;
        if ((char)psVar1[3] != '\0') {
LAB_007f6ec4:
          return unaff_EDI + 0x242 + iVar2 * 0x34;
        }
      }
      if (psVar1[-0x14] == unaff_SI) {
        if (param_2 == 0) {
          if (psVar1[1] == 0) goto LAB_007f6ef7;
        }
        else if (psVar1[1] != 0) goto LAB_007f6ef7;
        if ((char)psVar1[3] != '\0') {
LAB_007f6ef7:
          return unaff_EDI + 0x242 + iVar2 * 0x34;
        }
      }
      iVar2 = iVar2 + 1;
      psVar1 = psVar1 + 0x1a;
      if (0x77 < iVar2) {
        return 0;
      }
    } while( true );
  case 3:
    iVar2 = 0;
    psVar1 = (short *)(unaff_EDI + 0x1acc);
    do {
      if (psVar1[-0x15] == unaff_SI) {
        if (param_2 == 0) {
          if (*psVar1 == 0) goto LAB_007f6f41;
        }
        else if (*psVar1 != 0) goto LAB_007f6f41;
        if ((char)psVar1[3] != '\0') {
LAB_007f6f41:
          return unaff_EDI + 0x1aa2 + iVar2 * 0x34;
        }
      }
      if (psVar1[-0x14] == unaff_SI) {
        if (param_2 == 0) {
          if (psVar1[1] == 0) goto LAB_007f6f74;
        }
        else if (psVar1[1] != 0) goto LAB_007f6f74;
        if ((char)psVar1[3] != '\0') {
LAB_007f6f74:
          return unaff_EDI + 0x1aa2 + iVar2 * 0x34;
        }
      }
      iVar2 = iVar2 + 1;
      psVar1 = psVar1 + 0x1a;
      if (0x13 < iVar2) {
        return 0;
      }
    } while( true );
  }
  return 0;
}
```

---

## MEGA-018 live re-verify (2026-08-05) — APPEND ONLY

| Field | Value |
|---|---|
| **Agent** | OWN-ONLY dual **MEGA-018** |
| **Tools** | `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_callers` + `get_function_xrefs` + `get_function_by_address` + `get_assembly_context` + `read_memory` |
| **Forbidden** | `disassemble_bytes` (not used); Launcher (not used) |
| **Decompile ≡ prior raw CF** | **Yes** (identical switch/cases/bounds/returns) |

### Body / range

| Item | Value |
|---|---|
| Entry | `0x007f6db0` |
| Last insn | `0x007f6fa3` `RET` (`C3`) |
| Inclusive size | **756 B** / `0x2F4` |
| Jump table | `0x007f6fa4`–`0x007f6fb3` (4 dwords) |
| Classification | **leaf** (no callees) |

### Jump table (`read_memory` @ `0x007f6fa4`)

```
007f6dbc  case 0
007f6e2f  case 1
007f6eab  case 2
007f6f27  case 3
```

Hex: `bc 6d 7f 00 | 2f 6e 7f 00 | ab 6e 7f 00 | 27 6f 7f 00`

### Prologue / ABI (asm-sealed)

```
007f6db0  CMP EAX, 3
007f6db3  JA  007f6e2c     ; mode > 3 → EAX=0; RET
007f6db5  JMP [EAX*4 + 0x7f6fa4]
...
all exits: RET (C3) — no stack cleanup
```

| Register | Role | Conf |
|---|---|---|
| **EAX** in | mode `0..3` | **High** |
| **EDI** | ActionMap base | **High** |
| **SI** | key code (u16) to match | **High** |
| **DX** | mod state (u16; 0 = unbound, nonzero e.g. `0x2A` LSHIFT) | **High** |
| **EAX** out | slot entry* at **key0** field, or **NULL** | **High** |
| stack | unused; bare **RET** | **High** |

Decompiler `__fastcall(param_1,param_2)` + `in_EAX`/`unaff_SI`/`unaff_EDI` are **phantoms** of the real register ABI above. `param_2` maps to **DX** (mod); `in_EAX` is mode.

### Per-mode tables (bytes)

| Mode | Max (exclusive) | mod0 cursor start | key0 return base | Bounds insn |
|---|---|---|---|---|
| 0 | 5 | `EDI+0x30` | `EDI+0x06` | `CMP ECX,5; JL` |
| 1 | 6 | `EDI+0x134` | `EDI+0x10A` | `CMP ECX,6; JL` |
| 2 | `0x78` | `EDI+0x26C` | `EDI+0x242` | `CMP ECX,0x78; JL` |
| 3 | `0x14` | `EDI+0x1ACC` | `EDI+0x1AA2` | `CMP ECX,0x14; JL` |

- Slot stride: **0x34** (asm: `ECX*8 - ECX; *2; -ECX; *4` → `ECX*0x34`; `ADD EAX,0x34` per iter).
- Primary key: `word [cursor-0x2A]` ≡ key0; primary mod: `word [cursor]`.
- Alt key: `word [cursor-0x28]` ≡ key1; alt mod: `word [cursor+2]`.
- Override flag: `byte [cursor+6]` (key0+0x30).

### Match predicate (both lanes)

```
if keyN == SI:
  if (DX == 0) == (modN == 0):   // same zeroness → direct hit
    return slot_key0
  else if override_flag != 0:
    return slot_key0
// else next lane / next index
```

### Callers / xrefs

| Kind | Value |
|---|---|
| Callers | **1**: `Client_Input_OnKeyDown_MatchAction` @ `0x00911030` |
| Xrefs | **1** UNCONDITIONAL_CALL @ `0x00911429` |
| Callees | **none** |

### Caller site seal (`0x00911429`)

```
... GetAsyncKeyState(0x10/0xA0/0xA1) → BX = 0 or 0x2A (LSHIFT DIK)
... build SI = key from param bytes
MOV EDX, EBX          ; DX = mod state
XOR EAX, EAX          ; mode = 0
MOV EDI, 0x00d1b9ac   ; global ActionMap base
CALL 0x007f6db0
TEST EAX, EAX
JNZ hit_path          ; set held@+4 / edge@+5; FUN_0093a5c0(1)
; else fallback scan mode-2 region DAT_00d1bc18 / DAT_00d1bbee
;   (same map: 0xd1b9ac+0x26c / +0x242) when session ptrs match
```

### Cross-family offsets

Identical mode max / key0 / mod0 bases as dualed **`ActionMap_TrySetSlotBind`** `0x007f72e0` (`kMax`/`kKey0`/`kMod0` tables).

### Named reconstruction

`ActionMap_FindSlotByKeyMod_Inferred` (retire `Named_CalleeOf_Client_Input_OnKeyDown_MatchAction_007f6db0`).

### Gaps (re-verify)

- Product English for four mode groups.
- Product name of override flag byte (key0+0x30).
- Modes 1–3 live call sites (only mode 0 observed from sole caller).
- Runtime / bit-exact / differential (Terminal false).
