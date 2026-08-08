# Raw capture: FUN_004bae00

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bae00` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004bae00` |
| **Canonical name** | `FUN_004bae00` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall FUN_004bae00(int param_1,char param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if (param_2 == '\0') {
    if ((*(char *)(param_1 + 0xd) != '\0') && (*(int *)(param_1 + 8) != 0)) {
      FUN_00402c40();
      uVar1 = FUN_004bc530(param_3);
      *(undefined1 *)(*(int *)(param_1 + 8) + 0x1d) = 0;
      return uVar1;
    }
  }
  else if ((*(char *)(param_1 + 0xc) != '\0') && (*(int *)(param_1 + 4) != 0)) {
    FUN_00402c40();
    uVar1 = FUN_004bc530(param_3);
    *(undefined1 *)(*(int *)(param_1 + 4) + 0x1d) = 0;
    return uVar1;
  }
  return 0;
}
```

---

## MEGA-011 live re-verify (2026-08-05) -- APPEND ONLY

| Field | Value |
|---|---|
| **Wave** | MEGA-011 OWN-ONLY dual |
| **Tools** | Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_callers` + `get_function_xrefs` + `get_assembly_context` + `read_memory` |
| **Not used** | `disassemble_bytes` primary; Launcher; parent ledgers |
| **Image** | `autoassault.exe` base `0x400000` |
| **Body** | `0x004bae00`-`0x004bae63` inclusive (**100 B** / `0x64`) |
| **Live decompile** | == scaffold CF (flag0 -> host+0xd/+0x8; flag!=0 -> host+0xc/+0x4; lock/walk/unlock) |

### Live decompile (2026-08-05)

```c
undefined4 __thiscall FUN_004bae00(int param_1,char param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if (param_2 == '\0') {
    if ((*(char *)(param_1 + 0xd) != '\0') && (*(int *)(param_1 + 8) != 0)) {
      FUN_00402c40();
      uVar1 = FUN_004bc530(param_3);
      *(undefined1 *)(*(int *)(param_1 + 8) + 0x1d) = 0;
      return uVar1;
    }
  }
  else if ((*(char *)(param_1 + 0xc) != '\0') && (*(int *)(param_1 + 4) != 0)) {
    FUN_00402c40();
    uVar1 = FUN_004bc530(param_3);
    *(undefined1 *)(*(int *)(param_1 + 4) + 0x1d) = 0;
    return uVar1;
  }
  return 0;
}
```

### Assembly seal (`disassemble_function` -- not `disassemble_bytes`)

```text
004bae00  CMP  byte ptr [ESP+4], 0          ; listSelect
004bae05  PUSH ESI
004bae06  MOV  ESI, ECX                    ; host this
004bae08  JZ   004bae34                    ; -> flag==0 path

; ---- listSelect != 0 : host+0xc gate, hash @ host+0x4 ----
004bae0a  CMP  byte ptr [ESI+0xc], 0
004bae0e  JZ   004bae5e                    ; -> return 0
004bae10  MOV  ECX, dword ptr [ESI+0x4]    ; hash*
004bae13  TEST ECX, ECX
004bae15  JZ   004bae5e
004bae17  CALL 00402c40                    ; CNDHash_TraversalLock_Set (ECX=hash)
004bae1c  MOV  EAX, dword ptr [ESP+0xc]    ; cursor* (after PUSH ESI)
004bae20  MOV  ECX, dword ptr [ESI+0x4]
004bae23  PUSH EAX
004bae24  CALL 004bc530                    ; TraverseToNext (ECX=hash, stack cursor*)
004bae29  MOV  ECX, dword ptr [ESI+0x4]
004bae2c  MOV  byte ptr [ECX+0x1d], 0      ; unlock
004bae30  POP  ESI
004bae31  RET  8

; ---- listSelect == 0 : host+0xd gate, hash @ host+0x8 ----
004bae34  CMP  byte ptr [ESI+0xd], 0
004bae38  JZ   004bae5e
004bae3a  MOV  ECX, dword ptr [ESI+0x8]
004bae3d  TEST ECX, ECX
004bae3f  JZ   004bae5e
004bae41  CALL 00402c40
004bae46  MOV  EDX, dword ptr [ESP+0xc]
004bae4a  MOV  ECX, dword ptr [ESI+0x8]
004bae4d  PUSH EDX
004bae4e  CALL 004bc530
004bae53  MOV  ECX, dword ptr [ESI+0x8]
004bae56  MOV  byte ptr [ECX+0x1d], 0
004bae5a  POP  ESI
004bae5b  RET  8

; ---- fail ----
004bae5e  XOR  EAX, EAX
004bae60  POP  ESI
004bae61  RET  8
```

### Entry bytes (`read_memory` 100 B @ `0x004bae00`)

```text
80 7C 24 04 00 56 8B F1 74 2A 80 7E 0C 00 74 4E
8B 4E 04 85 C9 74 47 E8 24 7E F4 FF 8B 44 24 0C
8B 4E 04 50 E8 07 17 00 00 8B 4E 04 C6 41 1D 00
5E C2 08 00 80 7E 0D 00 74 24 8B 4E 08 85 C9 74
1D E8 FA 7D F4 FF 8B 54 24 0C 8B 4E 08 52 E8 DD
16 00 00 8B 4E 08 C6 41 1D 00 5E C2 08 00 33 C0
5E C2 08 00
```

Three exits are **`RET 8`** (`C2 08 00`) -- thiscall with **2 stack args**.

### ABI (sealed)

| Slot | Role | Evidence |
|---|---|---|
| ECX | dual-list **host*** | entry `MOV ESI,ECX`; call sites load host into ECX |
| stack0 `[ESP+4]` | `char listSelect` (0 / non-zero) | entry `CMP [ESP+4],0` |
| stack1 `[ESP+8]` | `int* cursor` (node walk state) | pushed as sole arg to `FUN_004bc530` |
| EAX | object* payload or 0 | `FUN_004bc530` returns node+0xc; fail path `XOR EAX,EAX` |
| cleanup | **`RET 8`** x3 | bytes `C2 08 00` |

### Host layout (sealed)

| Off | Role | Conf |
|----:|------|------|
| `+0x4` | CNDHash* list A (used when `listSelect != 0`) | **High** |
| `+0x8` | CNDHash* list B (used when `listSelect == 0`) | **High** |
| `+0xc` | enable/present byte for list A | **High** |
| `+0xd` | enable/present byte for list B | **High** |

### Hash / node layout (via callees; sealed for this unit)

| Off | Role | Source |
|----:|------|--------|
| hash `+0x14` | ordered-walk head node* | `FUN_004bc530` |
| hash `+0x1d` | TraversalLock flag | set by `00402c40`; cleared here |
| node `+0x20` | next node* | `FUN_004bc530` |
| node `+0x0c` | **payload** (object*) returned | `FUN_004bc530` |

### Callees

| VA | Role | Notes |
|---|---|---|
| `0x00402c40` | `CNDHash_TraversalLock_Set_Inferred` (dualed MEGA-110) | ECX=hash; soft set `+0x1d=1` |
| `0x004bc530` | CNDHash TraverseToNext (payload node+0xc) residual MEGA-029 | ECX=hash; stack cursor*; string `HashError:TraverseToNext, not locked for traversal` @ `0x00a27c9c` |

Decompiler elides ECX into both callees; assembly restores `ECX = [ESI+4|8]` before each CALL.

### Callers (13) / xrefs (28 UNCONDITIONAL_CALL)

| Caller | Sites (sample) | ECX host source |
|---|---|---|
| `FUN_00490070` SelectBestPick | `0x0049010b`, `0x0049048f` | `[Client+0xBC]` |
| `FUN_004ce860` | 2 | `[this+0xE4E8]` |
| `FUN_004ce8d0` | 2 | (same family) |
| `FUN_004cf560` | 2 | |
| `FUN_004d7510` | 2 | |
| `FUN_004d98f0` | 2 | |
| `FUN_004da160` | 4 | `[this+0xE4E8]` flag=1 |
| `FUN_004dc030` | 2 | |
| `FUN_004dd940` | 2 | |
| `FUN_00517df0` | 2 | |
| `FUN_00929cd0` | 2 | |
| `FUN_00943b80` FlushWorldObjectState | `0x00943d38`, `0x00943d55` | `[host+0xD34]` |
| `FUN_00954dc0` | 2 | |

### Call-site pattern (SelectBestPick @ `0x0049010b`)

```text
MOV  ECX, [EDI+0xBC]     ; host
PUSH cursor*
PUSH listSelect          ; 0 then toggled to 1 across two passes
CALL 0x004bae00
MOV  ESI, EAX             ; object*
TEST ESI, ESI
JZ   next_pass / done
; gate bit6 @ obj+0x17c, interact blob vtbl+0x1CC, ...
```

### Semantics (sealed)

Single-step dual-list object enumerator:

1. Select hash by `listSelect` (0 -> `host+8`, !=0 -> `host+4`) gated by enable byte.
2. `TraversalLock_Set(hash)`.
3. `TraverseToNext(hash, cursor)` -> object* or NULL.
4. Clear `hash+0x1d` (inline unlock; not CS-list unlock).
5. Return object*.

Fail paths (enable clear / null hash / exhausted) return 0 without locking.

### Naming (this wave)

| Name | Status |
|---|---|
| `FUN_004bae00` | Ghidra canonical |
| `Named_CalleeOf_Named_CalleeOf_CVOGSectorMap_LoadMapFile_004bae00` | **Retired scaffold** (wrong parent chain) |
| `Host_DualCNDHash_TraverseNextObject_Inferred` | **Preferred** -- dual CNDHash host step; product host English open -> `_Inferred` |

### Gaps remaining

- Product RTTI / English for dual-list host class.
- Full layout of host beyond `+0x4..+0xd`.
- Dual seal of `FUN_004bc530` (MEGA-029 residual).
- Runtime / bit-exact / differential (no Launcher).
