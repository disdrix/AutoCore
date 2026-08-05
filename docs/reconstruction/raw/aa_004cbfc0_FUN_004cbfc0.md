# Raw capture: FUN_004cbfc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cbfc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004cbfc0` |
| **Canonical name** | `FUN_004cbfc0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_004cbfc0(int param_1,int param_2,uint param_3,undefined4 *param_4)



{

  void *pvVar1;

  undefined1 *puVar2;

  int iVar3;

  uint uVar4;

  void *pvVar5;

  undefined4 uVar6;

  int iVar7;

  int iVar8;

  undefined8 uVar9;

  undefined4 local_24;

  undefined4 local_20;

  undefined4 local_1c;

  undefined4 local_18;

  undefined1 *local_14;

  void *local_10;

  undefined1 *puStack_c;

  undefined4 local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009a1e20;

  local_10 = ExceptionList;

  local_24 = *param_4;

  local_20 = param_4[1];

  local_1c = param_4[2];

  local_18 = param_4[3];

  iVar7 = *(int *)(param_1 + 4);

  local_14 = &stack0xffffffd0;

  if (iVar7 == 0) {

    iVar3 = 0;

  }

  else {

    iVar3 = *(int *)(param_1 + 0xc) - iVar7 >> 4;

  }

  uVar9 = CONCAT44(iVar7,iVar3);

  if (param_3 != 0) {

    if (iVar7 == 0) {

      iVar7 = 0;

    }

    else {

      iVar7 = *(int *)(param_1 + 8) - iVar7 >> 4;

    }

    ExceptionList = &local_10;

    puVar2 = &stack0xffffffd0;

    if (0xfffffffU - iVar7 < param_3) {

      ExceptionList = &local_10;

      uVar9 = FUN_004cb1d0();

      puVar2 = local_14;

    }

    local_14 = puVar2;

    iVar7 = (int)((ulonglong)uVar9 >> 0x20);

    uVar4 = (uint)uVar9;

    if (iVar7 == 0) {

      iVar3 = 0;

    }

    else {

      iVar3 = *(int *)(param_1 + 8) - iVar7 >> 4;

    }

    if (uVar4 < iVar3 + param_3) {

      if (0xfffffff - (uVar4 >> 1) < uVar4) {

        uVar4 = 0;

      }

      else {

        uVar4 = uVar4 + (uVar4 >> 1);

      }

      if (iVar7 == 0) {

        iVar3 = 0;

      }

      else {

        iVar3 = *(int *)(param_1 + 8) - iVar7 >> 4;

      }

      if (uVar4 < iVar3 + param_3) {

        if (iVar7 == 0) {

          iVar7 = 0;

        }

        else {

          iVar7 = *(int *)(param_1 + 8) - iVar7 >> 4;

        }

        uVar4 = iVar7 + param_3;

      }

      pvVar5 = operator_new(uVar4 * 0x10);

      local_8 = 0;

      iVar7 = FUN_005dd920(*(undefined4 *)(param_1 + 4),param_2,pvVar5,param_1,param_2);

      FUN_00608720(iVar7,param_3,&local_24,param_1,param_2);

      FUN_005dd920(param_2,*(undefined4 *)(param_1 + 8),iVar7 + param_3 * 0x10,param_1,param_2);

      pvVar1 = *(void **)(param_1 + 4);

      if (pvVar1 == (void *)0x0) {

        iVar7 = 0;

      }

      else {

        iVar7 = *(int *)(param_1 + 8) - (int)pvVar1 >> 4;

      }

      if (pvVar1 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar1);

      }

      *(void **)(param_1 + 0xc) = (void *)(uVar4 * 0x10 + (int)pvVar5);

      *(void **)(param_1 + 8) = (void *)((param_3 + iVar7) * 0x10 + (int)pvVar5);

      *(void **)(param_1 + 4) = pvVar5;

      ExceptionList = local_10;

      return;

    }

    iVar7 = *(int *)(param_1 + 8);

    if ((uint)(iVar7 - param_2 >> 4) < param_3) {

      iVar3 = param_3 * 0x10;

      FUN_005dd920(param_2,iVar7,iVar3 + param_2,param_1,iVar3);

      local_8 = 2;

      FUN_0041d5a0(*(int *)(param_1 + 8),param_3 - (*(int *)(param_1 + 8) - param_2 >> 4),&local_24)

      ;

      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + iVar3;

      FUN_004cb2e0(param_2,*(int *)(param_1 + 8) + param_3 * -0x10,&local_24);

      ExceptionList = local_10;

      return;

    }

    iVar3 = param_3 * 0x10;

    iVar8 = iVar7 + param_3 * -0x10;

    uVar6 = FUN_005dd920(iVar8,iVar7,iVar7,param_1,iVar3);

    *(undefined4 *)(param_1 + 8) = uVar6;

    FUN_0051b6e0(param_2,iVar8,iVar7,iVar3);

    FUN_004cb2e0(param_2,iVar3 + param_2,&local_24);

  }

  ExceptionList = local_10;

  return;

}
```


---

## W25-M live seal append (2026-07-29)

**Tools:** `decompile_function` + `analyze_function_complete` + `read_memory` (+ helper decompiles). **No** `disassemble_bytes`.
**Program:** `autoassault.exe` base `0x400000`.

### Function bounds

| Item | Value |
|---|---|
| Entry | `0x004cbfc0` |
| Body end | `0x004cc21c` (exclusive) |
| Size | ~0x25C B |
| Ghidra name | `FUN_004cbfc0` |
| Canonical (sealed) | `Vector_InsertN_0x10` |

### Prologue / epilogue bytes

```
004cbfc0: 55 8B EC                 push ebp; mov ebp,esp
004cbfc3: 6A FF                   push -1
004cbfc5: 68 20 1E 9A 00          push LAB_009a1e20   ; SEH
004cbfca: 64 A1 00 00 00 00       mov eax,fs:[0]
004cbfd0: 50                      push eax
004cbfd1: 64 89 25 00 00 00 00    mov fs:[0],esp
004cbfd8: 83 EC 14                sub esp,0x14
004cbfdb: 8B 45 10                mov eax,[ebp+0x10]  ; value*
004cbfe0: 53 56                   push ebx; push esi
004cbfe2: 8B F1                   mov esi,ecx         ; this → ESI
...
004cc210-ish: C2 0C 00            ret 0xc
```

Terminal region (`read_memory` @ `0x004cc1f0`): ends with restore ExceptionList / `mov esp,ebp; pop ebp; **ret 0xc**`.

### Live decompile summary

MSVC-style **`vector<T>::_Insert_n`** for **`sizeof(T) == 0x10`**:

- Layout: `this+4` begin, `this+8` end, `this+0xc` capacity end.
- Args: `insertAt` (ptr into buffer), `count`, `value*` (4 dwords copied to stack temp).
- Early-out if `count == 0`.
- Max elements `0x0fffffff`; overflow → `FUN_004cb1d0` throws **`"vector<T> too long"`**.
- Grow: `new_cap = cap + (cap>>1)`, clamp to fit `size+count`; `operator_new(new_cap * 0x10)`.
- Relocate: `FUN_005dd920` (uninitialized_copy 16-B POD), fill insert range `FUN_00608720`, delete old buffer, rewrite begin/end/cap.
- In-place paths: tail move + fill (`FUN_0041d5a0`, `FUN_004cb2e0`, `FUN_0051b6e0`).

### Helper roles (sealed this unit)

| Callee | Role |
|---|---|
| `FUN_004cb1d0` | throw length_error `"vector<T> too long"` |
| `operator_new` / `operator_delete` | buffer alloc/free |
| `FUN_005dd920` | POD copy loop stride 0x10 (4 dwords) |
| `FUN_00608720` | fill-n same value × count (0x10 elems) |
| `FUN_0041d5a0` | fill remainder on partial in-place |
| `FUN_004cb2e0` | assign/overwrite range with value |
| `FUN_0051b6e0` | overlapping shift helper |

### Callers (analyze)

| Caller | Sites |
|---|---|
| `FUN_006061e0` (`CVOGHBWakeupSkill_ctor`) | `0x006062dd`, `0x00606338` |
| `FUN_004cc470` | `0x004cc4c8` |
| `FUN_005de1b0` | `0x005de1ed` |
| `FUN_005dcc40` | `0x005dcfb6`, `0x005dc77f` |

Element product type often **TFID-sized (16 B)** at call sites (e.g. wake-up skill vector @ object+0x65c) — type English residual.

### ABI

- **thiscall** ECX = vector object* (container with pointers at +4/+8/+0xc).
- Stack: `void* insertAt`, `unsigned count`, `const T* value` → **`ret 0xc`**.
- Return: void (no meaningful EAX).
