# Raw capture: FUN_008ac3f0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ac3f0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008ac3f0` |
| **Canonical name** | `FUN_008ac3f0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int * FUN_008ac3f0(int *param_1)

{
  float fVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009b645d;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0087b890(param_1,0);
  fVar1 = g_flOne;
  *param_1 = (int)&PTR_FUN_00a4a51c;
  param_1[0x161] = 0;
  param_1[0x162] = 0;
  param_1[0x163] = 0;
  param_1[0x164] = (int)fVar1;
  param_1[0x165] = 0;
  param_1[0x166] = 0;
  param_1[0x167] = 0;
  param_1[0x168] = (int)fVar1;
  param_1[0x169] = 0;
  param_1[0x16a] = 0;
  param_1[0x16b] = 0;
  param_1[0x16c] = (int)fVar1;
  param_1[0x1cb] = 0;
  param_1[0x1cc] = 0;
  param_1[0x1cd] = 0;
  param_1[0x1cf] = 0;
  param_1[0x1d0] = 0;
  param_1[0x1d1] = 0;
  local_4 = 2;
  param_1[0x13f] = 0xc;
  param_1[0x140] = 1;
  param_1[0x192] = 0;
  param_1[0x143] = 0;
  param_1[399] = 1;
  param_1[400] = 1;
  param_1[0x145] = 0;
  *(undefined1 *)(param_1 + 0x160) = 0;
  param_1[0x1c1] = 0;
  param_1[0x170] = 0;
  param_1[0x16f] = 0;
  FUN_008ab0a0();
  NDUIWindow_ReloadInterface("i_d_npc.xml");
  FUN_008ac110();
  (**(code **)(*param_1 + 0x34c))();
  ExceptionList = local_c;
  return param_1;
}
```

---

## MEGA-107 re-verify (2026-08-05) — APPEND ONLY

| Field | Value |
|---|---|
| **Agent** | OWN-ONLY dual **MEGA-107** |
| **Tools** | Ghidra HTTP `decompile_function`, `analyze_function_complete`, `get_function_by_address`, `get_function_signature`, `get_function_callers`, `get_function_callees`, `get_function_xrefs`, `get_xrefs_to`, `get_function_call_graph`, `read_memory` |
| **Forbidden** | `disassemble_bytes` (not used); Launcher; parent ledgers |
| **Live ≡ raw CF** | **Yes** — decompile body identical to frozen raw pseudocode above |

### Function envelope

| Item | Live seal |
|---|---|
| Entry | `0x008ac3f0` |
| Body end (inclusive last byte of `RET 4`) | `0x008ac53f` |
| Exclusive end (Ghidra Body field) | `0x008ac53f` reported as `008ac3f0 - 008ac53f` |
| Size | **336 B** / `0x150` (`0x008ac53f - 0x008ac3f0 + 1` if inclusive end of C2 04 00; last insn at `0x008ac53d`) |
| Ghidra Body field | `008ac3f0 - 008ac53f` |
| Basic blocks | **1** (straight-line ctor) |
| Cyclomatic | **1** |
| Classification | worker |

### ABI (bytes over decompiler signature)

```
64 a1 00 00 00 00          ; mov eax, fs:[0]
6a ff 68 5d 64 9b 00 50    ; SEH push -1 / LAB_009b645d / old FS
64 89 25 00 00 00 00
53 57                      ; push ebx, edi
8b 7c 24 18                ; EDI = this* from stack (+0x18 after frame)
33 db                      ; EBX = 0
53 57 e8 …                 ; FUN_0087b890(this, 0)
…
8b c7 … c2 04 00           ; EAX = this; RET 4
```

| Claim | Result |
|---|---|
| This pointer | **EDI** after prologue; **stack** arg at entry (not ECX thiscall for *this* body) |
| Extra arg to base | **0** in EBX, pushed before `FUN_0087b890` |
| Return | **EAX = this** |
| Epilogue | **`RET 4`** (`C2 04 00` @ `0x008ac53d`) — cleans 4-byte stack this |
| SEH | `LAB_009b645d`; state 0→1→2→-1 across phases |

### Direct CALL targets (E8 scan of body)

| VA of E8 | Target | Symbol |
|---|---|---|
| `0x008ac40f` | `0x0087b890` | base NDUI ctor family |
| `0x008ac505` | `0x008ab0a0` | mission-dialog field zero/init |
| `0x008ac50f` | `0x00792980` | `NDUIWindow_ReloadInterface` |
| `0x008ac514` | `0x008ac110` | `UI_MissionDialog_BuildResponseButtons_Inferred` |

### Virtual call

```
8b 07          ; eax = *this (vtbl)
8b cf          ; ecx = this
ff 90 4c 03 00 00  ; call [eax+0x34C]
```

| Item | Value |
|---|---|
| Vtable base installed | `*this = 0x00a4a51c` (`C7 07 1C A5 A4 00`) |
| Slot `+0x34C` DATA | `0x00a4a51c + 0x34C = 0x00a4a868` |
| Slot dword (`read_memory`) | **`0x00791dc0`** (`FUN_00791dc0`) |

### String

| Item | Value |
|---|---|
| Push imm before ReloadInterface | `0x00a4b0e0` |
| Bytes | `69 5f 64 5f 6e 70 63 2e 78 6d 6c 00` → **`i_d_npc.xml`** |

### Constants

| Addr | Value | Role |
|---|---|---|
| `0x00a0f2a0` (`g_flOne`) | f32 **1.0** (`00 00 80 3F`) | diagonal of 3×4 transform block |
| `param[0x13f]` / `+0x4FC` | **0x0C** | dialog chrome / table id (imm store) |
| `param[0x140]` / `+0x500` | **1** | flag (EAX=1) |
| `param[399]` / `+0x63C` | **1** | layout flag |
| `param[400]` / `+0x640` | **1** | response **columns** default (peer dual `008ac110`) |
| `param[0x192]` / `+0x648` | **0** | layout mode (peer dual) |

### Transform block (identity-ish 3 rows × xyz1)

Stores via `xorps xmm0` + `movss xmm1,[g_flOne]` then 12 floats starting `this+0x584` (`param_1[0x161]`):

```
row0: 0, 0, 0, 1
row1: 0, 0, 0, 1
row2: 0, 0, 0, 1
```

(Decompiler `param_1[0x161]..[0x16c]` matches offsets `0x584..0x5B0`.)

### Callers / xrefs

| Direction | Live |
|---|---|
| Callers | **`FUN_0093e7e0` only** |
| Xrefs to | `0x0093f420` UNCONDITIONAL_CALL in `FUN_0093e7e0` |
| Caller pattern | `operator_new(0x748)` → push EAX → `FUN_008ac3f0` → store **`client+0x1058`** |

### Callees (analyze + E8)

`FUN_0087b890`, `FUN_008ab0a0`, `NDUIWindow_ReloadInterface` (`0x00792980`), `FUN_008ac110`, virtual `FUN_00791dc0` via vtbl+0x34C.

### Name

| Item | Value |
|---|---|
| Ghidra | `FUN_008ac3f0` |
| Meaningful (inferred) | **`Client_NpcMissionDialogHost_Ctor_Inferred`** |
| Retired scaffold | `Mission_i_d_npc_xml_008ac3f0` (string-only) |
| Product PDB English | **Open** → `_Inferred` |

### Gaps remaining after re-verify

- Product class name / PDB
- Full English map of every zeroed dword in `FUN_008ab0a0` (callee, not OWN)
- Semantics of virtual `FUN_00791dc0` post-XML (not OWN)
- Runtime / bit-exact / differential

**Terminal:** false (no Launcher / no runtime Confirmed).
