# Raw capture: FUN_007b5be0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007b5be0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007b5be0` |
| **Canonical name** | `FUN_007b5be0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_007b5be0(undefined4 *param_1)

{
  void *pvVar1;
  int iVar2;
  undefined4 *puVar3;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009b325c;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_00a960ac;
  local_4 = 1;
  if (param_1[0xac] != 0) {
    FUN_007a4480(0,"VOG_DEBUG_STOP");
    if (param_1[0xa1] == 0) {
      FUN_007a4480(1,"Deleting an unknown window with an owner!");
    }
    else {
      FUN_007a4480(1,"Deleting a window with an owner! (filename: %s)",param_1[0xa1]);
    }
  }
  _DAT_00d17954 = _DAT_00d17954 + -1;
  if (((int *)param_1[0xad] != (int *)0x0) && (*(char *)((int)param_1 + 0xbd) != '\0')) {
    (**(code **)(*(int *)param_1[0xad] + 0xc))(1);
    param_1[0xad] = 0;
    *(undefined1 *)((int)param_1 + 0xbd) = 0;
  }
  FUN_007a8580();
  FUN_007aec70();
  FUN_007aff00();
  pvVar1 = (void *)param_1[0xa3];
  if (pvVar1 != (void *)0x0) {
    FUN_00797d70(pvVar1);
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar1);
  }
  param_1[0xa3] = 0;
  if ((void *)param_1[0xae] != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    operator_delete((void *)param_1[0xae]);
  }
  param_1[0xae] = 0;
  if ((void *)param_1[0x9d] != (void *)0x0) {
    operator_delete__((void *)param_1[0x9d]);
  }
  param_1[0x9d] = 0;
  if ((void *)param_1[0xa0] != (void *)0x0) {
    operator_delete__((void *)param_1[0xa0]);
  }
  param_1[0xa0] = 0;
  if ((void *)param_1[0x9f] != (void *)0x0) {
    operator_delete__((void *)param_1[0x9f]);
  }
  param_1[0x9f] = 0;
  if ((void *)param_1[0x9e] != (void *)0x0) {
    operator_delete__((void *)param_1[0x9e]);
  }
  param_1[0x9e] = 0;
  if ((void *)param_1[0xa1] != (void *)0x0) {
    operator_delete__((void *)param_1[0xa1]);
  }
  param_1[0xa1] = 0;
  if ((void *)param_1[0xa2] != (void *)0x0) {
    operator_delete__((void *)param_1[0xa2]);
  }
  param_1[0xa2] = 0;
  puVar3 = param_1 + 0x117;
  iVar2 = 0xb;
  do {
    if ((void *)*puVar3 != (void *)0x0) {
      operator_delete__((void *)*puVar3);
    }
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  param_1[0x7a] = &PTR_FUN_00a964b8;
  FUN_00424060();
  param_1[0x7a] = &PTR_FUN_00a964ac;
  FUN_00424060();
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x7b));
  local_4 = 0xffffffff;
  FUN_00759de0();
  ExceptionList = pvStack_c;
  return;
}
```

---

## WQ9K-F re-verify (2026-08-05) — append only

| Field | Value |
|---|---|
| **Agent** | OWN-ONLY dual **WQ9K-F** |
| **Tools** | `batch_decompile` + `analyze_function_complete` + `disassemble_function` + `read_memory` + RTTI COL + callers. **No** `disassemble_bytes`. |
| **Live decompile** | ≡ scaffold raw CF; Ghidra **false-noreturn** on `operator_delete` — epilogue after frees reaches `RET` (bytes sealed) |
| **Body** | `0x007b5be0`–`0x007b5dcc` inclusive (**493 B** / `0x1ED`); `CC` pad then next |
| **ABI** | `__thiscall`; entry `MOV ESI,ECX`; SEH `LAB_009b325c`; bare **`RET`** (`C3`); **void** |
| **Classification** | worker (complete dtor body) |
| **Product name** | **`CNDUIWindow_CompleteDtor`** — RTTI sealed |

### Entry + mid + epilogue hex samples (`read_memory`)

Entry 128 B @ `0x007b5be0`:
```
6aff685c329b0064a1000000005064892500000000515355568bf15789742410c706ac60a900bf0100000033db897c241c399eb00200007437684458a10053e85ce8feff8b868402000083c4083bc374115068546fa90057e843e8feff83c40ceb0e68286fa90057e833e8feff83c4088b8eb4020000293d5479d1003bcb741a
```

Epilogue @ `0x007b5d81`–`0x007b5dcc` (from disasm + read):
```
LEA EDI,[ESI+0x1E8]; dual FUN_00424060 with vtbls 00a964b8/00a964ac;
ADD EDI,4; PUSH EDI; CALL [DeleteCriticalSection IAT 009c61f0];
EH=-1; CALL FUN_00759de0; SEH restore; ADD ESP,0x10; RET (C3)
```

### Control flow (bytes authority)

```
SEH prolog LAB_009b325c; ESI = ECX (this); EDI=1; EBX=0
*this = PTR_FUN_00a960ac
if *(this+0x2B0) != 0:               // owner cookie non-null
  FUN_007a4480(0, "VOG_DEBUG_STOP")
  if *(this+0x284)==0: warn unknown owner
  else: warn with filename string at +0x284
_DAT_00d17954 -= 1                    // live window counter
if *(this+0x2B4) && *(byte*)(this+0xBD):
  vcall [*(obj)][+0xC](1); null +0x2B4; clear +0xBD
FUN_007a8580(); FUN_007aec70(); FUN_007aff00()  // thiscall ESI
// free owned blocks (always-null after each free path):
//   +0x28C (FUN_00797d70 + operator_delete)
//   +0x2B8 operator_delete
//   +0x274/+0x280/+0x27C/+0x278/+0x284/+0x288 operator_delete[]
// 11× dword array at +0x45C operator_delete[] each
// nested @ +0x1E8: install vtbls + FUN_00424060 twice; DeleteCriticalSection(+0x1EC)
EH=-1; FUN_00759de0()                 // super-base complete
SEH restore; RET
```

### RTTI / vtbl

| Item | Value |
|---|---|
| Primary vtbl | `PTR_FUN_00a960ac` |
| COL (vtbl−4) | `@0x00a960a8` → `0x00ab75c8` |
| type_info | `0x00afe1ac` → **`.?AVCNDUIWindow@@`** |
| vtbl[0] | dword `@0x00a960ac` = `0x00423e50` (scalar peer) |
| Ctor twin | `FUN_007b5dd0` installs same vtbl (NDUIWindow_BaseCtor_Inferred) |

### Callers (sample; 50+ incl. EH)

| Caller | Role |
|---|---|
| `FUN_0078ca80` / CNDUIWndBuffered complete | base chain |
| `FUN_00832fa0` / CWndWaypointIcon_CompleteDtor | derived complete |
| `FUN_00423e50` | scalar deleting of CNDUIWindow |
| Many UI complete/scalar paths + EH unwinds | fan-in |

### Callees

`FUN_007a4480`, `FUN_007a8580`, `FUN_007aec70`, `FUN_007aff00`, `FUN_00797d70`, `operator_delete`, `operator_delete[]`, `FUN_00424060`×2, `DeleteCriticalSection`, `FUN_00759de0`

### Notes

- Not scalar/vector/host-free: bare RET; host free is scalar peer only.
- False-noreturn on `operator_delete` **falsified** by continuing free chain + base + RET.
- Strings seal window/owner debug path; product class from RTTI is **CNDUIWindow**.
