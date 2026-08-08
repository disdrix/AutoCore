# Raw capture: FUN_004cbee0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cbee0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004cbee0` |
| **Canonical name** | `FUN_004cbee0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_004cbee0(int param_1,undefined4 *param_2,uint *param_3)

{
  undefined4 uVar1;
  bool bVar2;
  uint *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 local_4;
  
  puVar3 = param_3;
  puVar5 = *(undefined4 **)(param_1 + 4);
  bVar2 = true;
  local_4 = 1;
  if (*(char *)((int)puVar5[1] + 0x29) == '\0') {
    puVar4 = (undefined4 *)puVar5[1];
    do {
      puVar5 = puVar4;
      if (((int)puVar5[5] < (int)param_3[1]) ||
         (((int)puVar5[5] <= (int)param_3[1] && ((uint)puVar5[4] <= *param_3)))) {
        puVar4 = (undefined4 *)puVar5[2];
        bVar2 = false;
        local_4 = 0;
      }
      else {
        puVar4 = (undefined4 *)*puVar5;
        bVar2 = true;
        local_4 = 1;
      }
    } while (*(char *)((int)puVar4 + 0x29) == '\0');
  }
  param_3 = puVar5;
  if (bVar2) {
    if (puVar5 == (undefined4 *)**(int **)(param_1 + 4)) {
      puVar5 = (undefined4 *)FUN_004cbb60(&param_3,1,puVar5,puVar3);
      uVar1 = *puVar5;
      *(undefined1 *)(param_2 + 1) = 1;
      *param_2 = uVar1;
      return;
    }
    FUN_004cb4f0();
  }
  if (((int)param_3[5] <= (int)puVar3[1]) &&
     (((int)param_3[5] < (int)puVar3[1] || (param_3[4] < *puVar3)))) {
    puVar5 = (undefined4 *)FUN_004cbb60(&param_3,local_4,puVar5,puVar3);
    *param_2 = *puVar5;
    *(undefined1 *)(param_2 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_2 + 1) = 0;
  *param_2 = param_3;
  return;
}
```

---

## WQ9F-D re-verify (2026-08-04) — append only

| Field | Value |
|---|---|
| **Agent** | OWN-ONLY dual **WQ9F-D** |
| **Tools** | `batch_decompile` / `analyze_function_complete` / `read_memory` / callers+xrefs (**no** `disassemble_bytes`) |
| **Live decompile** | ≡ scaffold raw CF (above) |
| **Body** | `0x004cbee0`–`0x004cbfb2` exclusive (**210 B** / `0xD2`); pad `CC` |
| **ABI** | `__thiscall`; ECX = map shell*; stack `InsertPair* out` @+4, `PairKey* value` @+8; **RET 8** (`C2 08 00` ×3) |
| **isnil / key** | isnil@**+0x29**; pair key: **uint lo** @ node+0x10 / `value[0]`; **signed hi** @ node+0x14 / `value[1]` |
| **Order** | go right when node ≤ key (hi signed primary, lo unsigned secondary); equal → inserted=0 no rewrite |
| **Callees** | `FUN_004cbb60` insert+RB (2); `FUN_004cb4f0` predecessor (1) |
| **Callers / xrefs** | `FUN_004cc220` @ `0x004cc3ae` — **1** UNCONDITIONAL_CALL |
| **Classification** | worker (MSVC map insert-or-find shell, pair key) |
| **Named role** | `StdMap_InsertOrFind_PairKey_Isnil29_Inferred` |
| **Prior alias** | `Named_CalleeOf_…_VOG_DEBUG_ST_004cbee0` — **reject** product |

### Full body hex (210 B)

```
51558b6c241056578bf98b4f048b4104807829008bf1b101884c240c752f8b5504538b5d003b50148bf07f117c053b5810730a8b00b101884c2410eb098b400832c9884c24108078290074d95b84c98bd68954241874338b47043b308d4c2418751f55566a01518bcfe812fcffff8b108b4424145f5ec640040189105d59c20800e88af5ffff8b5424188b42143b45047f307c088b4a103b4d0073268b54240c5556528d442424508bcfe8d1fbffff8b088b4424145f5e8908c64004015d59c208008b4424145f5ec640040089105d59c20800
```

### Byte seal notes

| Item | Evidence |
|---|---|
| Prologue | `51 55 8B 6C 24 10 56 57 8B F9` — EBP=`value*`; EDI=map |
| Pair walk | `8B 55 04` / `8B 5D 00` load hi/lo; `3B 50 14` hi; `JG`/`JL`; `3B 58 10` / `73` lo **unsigned JAE** |
| isnil | `80 78 29 00` |
| Insert / pred / RET8 | same family as `004cbe20`; terminal `C2 08 00` ×3 |
