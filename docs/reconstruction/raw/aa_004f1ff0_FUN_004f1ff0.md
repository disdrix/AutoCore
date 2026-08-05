# Raw capture: FUN_004f1ff0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f1ff0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004f1ff0` |
| **Canonical name** | `FUN_004f1ff0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_004f1ff0(int param_1,undefined4 param_2)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  undefined1 *puVar7;
  undefined4 uVar8;
  int local_130;
  undefined1 auStack_12c [4];
  undefined1 auStack_128 [4];
  undefined1 auStack_124 [4];
  undefined1 auStack_120 [4];
  undefined1 auStack_11c [4];
  undefined4 local_118;
  undefined1 auStack_114 [3];
  char cStack_111;
  char local_110 [8];
  char local_108 [4];
  char acStack_104 [4];
  char acStack_100 [244];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a2ba9;
  pvStack_c = ExceptionList;
  local_118 = DAT_00d1f040;
  ExceptionList = &pvStack_c;
  FUN_0076cf00("CollectAllGraphicsPreloads");
  local_4 = 0;
  if ((*(byte *)(*(int *)(param_1 + 0x3c) + 0x3f2) & 0x10) != 0) {
    pcVar2 = (char *)(param_1 + 0x188);
    iVar3 = -(int)pcVar2;
    do {
      cVar1 = *pcVar2;
      pcVar2[(int)(local_110 + iVar3)] = cVar1;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    pcVar2 = &cStack_111;
    do {
      pcVar4 = pcVar2;
      pcVar2 = pcVar4 + 1;
    } while (pcVar4[1] != '\0');
    *(undefined4 *)(pcVar4 + 1) = s__tint_dds_009cd060._0_4_;
    pcVar2 = local_110;
    *(undefined4 *)(pcVar4 + 5) = s__tint_dds_009cd060._4_4_;
    uVar8 = 0xffffffff;
    *(undefined2 *)(pcVar4 + 9) = s__tint_dds_009cd060._8_2_;
    FUN_007b6a20(pcVar2,0xffffffff);
    cVar1 = FUN_007b6730(pcVar2,uVar8);
    if (cVar1 != '\0') {
      FUN_00989e00(&local_130,local_110);
      FUN_0043d670(&local_130);
    }
  }
  if ((*(int *)(param_1 + 0x38) == 0xe) ||
     ((*(int *)(param_1 + 0x38) == 0x12 && (*(int *)(*(int *)(param_1 + 0x3c) + 0x4e8) == 1)))) {
    pcVar2 = (char *)(param_1 + 0x188);
    iVar3 = -(int)pcVar2;
    do {
      cVar1 = *pcVar2;
      pcVar2[(int)(local_110 + iVar3)] = cVar1;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    pcVar2 = &cStack_111;
    do {
      pcVar4 = pcVar2;
      pcVar2 = pcVar4 + 1;
    } while (pcVar4[1] != '\0');
    *(undefined4 *)(pcVar4 + 1) = DAT_00a67574;
    pcVar2 = local_110;
    *(undefined4 *)(pcVar4 + 5) = DAT_00a67578;
    uVar8 = 0xffffffff;
    pcVar4[9] = DAT_00a6757c;
    FUN_007b6a20(pcVar2,0xffffffff);
    cVar1 = FUN_007b6730(pcVar2,uVar8);
    if (cVar1 != '\0') {
      FUN_00989e00(&local_130,local_110);
      FUN_0043d670(&local_130);
    }
  }
  if ((*(int *)(param_1 + 0x38) != 0xe) ||
     (iVar3 = FUN_00404d70(*(undefined4 *)(*(int *)(param_1 + 0x3c) + 0x6f4)), local_130 = iVar3,
     iVar3 == 0)) goto LAB_004f24e1;
  FUN_004f1e20(1,1);
  cVar1 = *(char *)(*(int *)(iVar3 + 0x3c) + 0x4ce);
  if (cVar1 == '\x02') {
    pcVar2 = (char *)(param_1 + 0x188);
    iVar3 = -(int)pcVar2;
    pcVar4 = pcVar2;
    do {
      cVar1 = *pcVar4;
      pcVar4[(int)(local_110 + iVar3)] = cVar1;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    pcVar4 = &cStack_111;
    do {
      pcVar5 = pcVar4;
      pcVar4 = pcVar5 + 1;
    } while (pcVar5[1] != '\0');
    *(undefined4 *)(pcVar5 + 1) = DAT_009cd010;
    pcVar4 = local_110;
    *(undefined4 *)(pcVar5 + 5) = DAT_009cd014;
    uVar8 = 0xffffffff;
    *(undefined2 *)(pcVar5 + 9) = DAT_009cd018;
    FUN_007b6a20(pcVar4,0xffffffff);
    cVar1 = FUN_007b6730(pcVar4,uVar8);
    if (cVar1 != '\0') {
      FUN_00989e00(auStack_128,local_110);
      FUN_0043d670(auStack_128);
    }
    do {
      cVar1 = *pcVar2;
      pcVar2[(int)(local_110 + iVar3)] = cVar1;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    pcVar2 = &cStack_111;
    do {
      pcVar4 = pcVar2;
      pcVar2 = pcVar4 + 1;
    } while (pcVar4[1] != '\0');
    *(undefined4 *)(pcVar4 + 1) = DAT_009cd004;
    pcVar2 = local_110;
    *(undefined4 *)(pcVar4 + 5) = DAT_009cd008;
    uVar8 = 0xffffffff;
    *(undefined2 *)(pcVar4 + 9) = DAT_009cd00c;
    FUN_007b6a20(pcVar2,0xffffffff);
    cVar1 = FUN_007b6730(pcVar2,uVar8);
    if (cVar1 != '\0') {
      FUN_00989e00(auStack_120,local_110);
      puVar7 = auStack_120;
LAB_004f24c5:
      FUN_0043d670(puVar7);
    }
  }
  else if (cVar1 == '\x04') {
    pcVar2 = (char *)(param_1 + 0x188);
    pcVar5 = local_110 + -(int)pcVar2;
    pcVar4 = pcVar2;
    do {
      cVar1 = *pcVar4;
      pcVar4[(int)pcVar5] = cVar1;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    pcVar4 = &cStack_111;
    do {
      pcVar6 = pcVar4;
      pcVar4 = pcVar6 + 1;
    } while (pcVar6[1] != '\0');
    *(undefined4 *)(pcVar6 + 1) = s__trdleft_geo_009cd050._0_4_;
    *(undefined4 *)(pcVar6 + 5) = s__trdleft_geo_009cd050._4_4_;
    pcVar4 = local_110;
    *(undefined4 *)(pcVar6 + 9) = s__trdleft_geo_009cd050._8_4_;
    uVar8 = 0xffffffff;
    pcVar6[0xd] = s__trdleft_geo_009cd050[0xc];
    FUN_007b6a20(pcVar4,0xffffffff);
    cVar1 = FUN_007b6730(pcVar4,uVar8);
    pcVar4 = pcVar2;
    if (cVar1 != '\0') {
      FUN_00989e00(auStack_11c,local_110);
      FUN_0043d670(auStack_11c);
    }
    do {
      cVar1 = *pcVar4;
      pcVar4[(int)pcVar5] = cVar1;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    pcVar4 = &cStack_111;
    do {
      pcVar6 = pcVar4;
      pcVar4 = pcVar6 + 1;
    } while (pcVar6[1] != '\0');
    *(undefined4 *)(pcVar6 + 1) = s__trdleft_ai_anm_009cd040._0_4_;
    *(undefined4 *)(pcVar6 + 5) = s__trdleft_ai_anm_009cd040._4_4_;
    pcVar4 = local_110;
    *(undefined4 *)(pcVar6 + 9) = s__trdleft_ai_anm_009cd040._8_4_;
    uVar8 = 0xffffffff;
    *(undefined4 *)(pcVar6 + 0xd) = s__trdleft_ai_anm_009cd040._12_4_;
    FUN_007b6a20(pcVar4,0xffffffff);
    cVar1 = FUN_007b6730(pcVar4,uVar8);
    pcVar4 = pcVar2;
    if (cVar1 != '\0') {
      FUN_00989e00(auStack_124,local_110);
      FUN_0043d670(auStack_124);
    }
    do {
      cVar1 = *pcVar4;
      pcVar4[(int)pcVar5] = cVar1;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    pcVar4 = &cStack_111;
    do {
      pcVar6 = pcVar4;
      pcVar4 = pcVar6 + 1;
    } while (pcVar6[1] != '\0');
    *(undefined4 *)(pcVar6 + 1) = s__trdright_geo_009cd030._0_4_;
    *(undefined4 *)(pcVar6 + 5) = s__trdright_geo_009cd030._4_4_;
    pcVar4 = local_110;
    *(undefined4 *)(pcVar6 + 9) = s__trdright_geo_009cd030._8_4_;
    uVar8 = 0xffffffff;
    *(undefined2 *)(pcVar6 + 0xd) = s__trdright_geo_009cd030._12_2_;
    FUN_007b6a20(pcVar4,0xffffffff);
    cVar1 = FUN_007b6730(pcVar4,uVar8);
    if (cVar1 != '\0') {
      FUN_00989e00(auStack_114,local_110);
      FUN_0043d670(auStack_114);
    }
    do {
      cVar1 = *pcVar2;
      pcVar2[(int)pcVar5] = cVar1;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    pcVar2 = &cStack_111;
    do {
      pcVar4 = pcVar2;
      pcVar2 = pcVar4 + 1;
    } while (pcVar4[1] != '\0');
    *(undefined4 *)(pcVar4 + 1) = s__trdright_ai_anm_009cd01c._0_4_;
    *(undefined4 *)(pcVar4 + 5) = s__trdright_ai_anm_009cd01c._4_4_;
    *(undefined4 *)(pcVar4 + 9) = s__trdright_ai_anm_009cd01c._8_4_;
    pcVar2 = local_110;
    *(undefined4 *)(pcVar4 + 0xd) = s__trdright_ai_anm_009cd01c._12_4_;
    uVar8 = 0xffffffff;
    pcVar4[0x11] = s__trdright_ai_anm_009cd01c[0x10];
    FUN_007b6a20(pcVar2,0xffffffff);
    cVar1 = FUN_007b6730(pcVar2,uVar8);
    if (cVar1 != '\0') {
      FUN_00989e00(auStack_12c,local_110);
      puVar7 = auStack_12c;
      goto LAB_004f24c5;
    }
  }
  FUN_004eb010();
LAB_004f24e1:
  FUN_004eb3b0();
  if (*(int *)(param_1 + 0x88) != 0) {
    FUN_004a04f0(param_2,1,0,0);
  }
  local_4 = 0xffffffff;
  FUN_0076cef0();
  ExceptionList = pvStack_c;
  return;
}
```

---

## W32-H re-verify (2026-07-29) — OWN dual

| Field | Value |
|---|---|
| **Wave** | W32-H |
| **Tools** | `batch_decompile` / `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` + xrefs/callers. **No** `disassemble_bytes`. |
| **Live decompile** | ≡ raw 2026-07-23 CF (timer plate, suffix builds, type gates, clone lookup, tail `004a04f0`) |
| **Body** | `0x004f1ff0`–`0x004f2531` exclusive (**1345 B** / `0x541`); last insn `C2 04 00`; pad `CC` |
| **ABI** | **thiscall** ECX=`this` (object host); stack **`param_2`** (forwarded to `FUN_004a04f0`); **`RET 0x4`**; void |
| **Classification** | worker |
| **Canonical name** | `Object_CollectAllGraphicsPreloads` (plate string `CollectAllGraphicsPreloads`) |
| **Rejected plate** | `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004f1ff0` (scaffold chain) |

### Prologue / epilogue (`read_memory`)

Entry `0x004f1ff0` (48 B):
```
6a ff 68 a9 2b 9a 00 64 a1 00 00 00 00 50 64 89 25 00 00 00 00 81 ec 24 01 00 00 53 8b 1d 40 f0 d1 00 55 57 8b e9 68 6c d0 9c 00 8b cb 89 5c 24
```
SEH; `sub esp,0x124`; `MOV EBP,ECX` (**true thiscall**); profile begin string push.

Epilogue `0x004f2520`:
```
5b 64 89 0d 00 00 00 00 81 c4 30 01 00 00 c2 04 00
```
restore FS; `add esp,0x130`; **`ret 0x4`**; pad `CC`.

### String constants (`read_memory`)

| Addr | Text |
|---|---|
| plate via `FUN_0076cf00` | `"CollectAllGraphicsPreloads"` |
| `0x009cd060` | `"_tint.dds"` |
| `0x00a67574` | `"_tur.geo"` |
| `0x009cd004` | `"_frkb.geo"` |
| `0x009cd010` | `"_frkt.geo"` |
| `0x009cd050` | `"_trdleft.geo"` |
| `0x009cd040` | `"_trdleft_ai.anm"` |
| `0x009cd030` | `"_trdright.geo"` |
| `0x009cd01c` | `"_trdright_ai.anm"` |

### Sealed control flow

```
// ECX = object host; stack = param_2 (preload-root / mission container*); RET 0x4
FUN_0076cf00("CollectAllGraphicsPreloads")  // profile/timer begin
base = this+0x188  // path stem C-string

if (*(byte*)(*(this+0x3c)+0x3f2) & 0x10):
  if file_exists(base + "_tint.dds"): enqueue

if type@this+0x38 == 0x0e  OR  (type==0x12 AND *(this+0x3c)+0x4e8 == 1):
  if file_exists(base + "_tur.geo"): enqueue

if type != 0x0e: goto tail
clone = GameData_LookupCloneBaseByCbid( *( *(this+0x3c)+0x6f4 ) )  // FUN_00404d70
if clone == 0: goto tail
FUN_004f1e20(1,1)  // thiscall on this
kind = *(char*)(*(clone+0x3c)+0x4ce)
if kind == 2:
  enqueue if exists: base+"_frkt.geo", base+"_frkb.geo"
else if kind == 4:
  enqueue if exists: base+"_trdleft.geo", base+"_trdleft_ai.anm",
                     base+"_trdright.geo", base+"_trdright_ai.anm"
FUN_004eb010()  // thiscall residual collect

tail:
FUN_004eb3b0()  // thiscall residual collect
if *(this+0x88) != 0:
  FUN_004a04f0(param_2, 1, 0, 0)  // walks mission map → MissionHost_CollectMediaPreloads (flags partial)
FUN_0076cef0()  // profile/timer end
```

Existence gate pair: `FUN_007b6a20(path, -1)` then `FUN_007b6730(path, -1)`; on true → `FUN_00989e00` + `GuardedVector_PushBack_Thiscall` (`0043d670`).

### Callers / callees

| Direction | Targets |
|---|---|
| Callers (2 / 2 xrefs) | `FUN_004f2540` @ `0x004f25e6`; `FUN_004f26e0` @ `0x004f273e` |
| Callees | `FUN_0076cf00`/`FUN_0076cef0`, `FUN_007b6a20`/`FUN_007b6730`, `FUN_00989e00`, `FUN_0043d670`, `FUN_00404d70`, `FUN_004f1e20`, `FUN_004eb010`, `FUN_004eb3b0`, `FUN_004a04f0` |

### Gaps

- Product English for type codes `0x0e` / `0x12` and kind `2` / `4`.
- `FUN_004eb010` / `FUN_004eb3b0` / `FUN_004f1e20` product roles (not OWN).
- Preload vector ECX identity; runtime / bit-exact.

