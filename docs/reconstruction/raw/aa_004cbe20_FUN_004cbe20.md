# Raw capture: FUN_004cbe20

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cbe20` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004cbe20` |
| **Canonical name** | `FUN_004cbe20` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_004cbe20(int param_1,undefined4 *param_2,int *param_3)

{
  undefined4 uVar1;
  bool bVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  piVar3 = param_3;
  puVar5 = *(undefined4 **)(param_1 + 4);
  bVar2 = true;
  if (*(char *)((int)puVar5[1] + 0x29) == '\0') {
    puVar4 = (undefined4 *)puVar5[1];
    do {
      puVar5 = puVar4;
      bVar2 = *param_3 < (int)puVar5[4];
      if (bVar2) {
        puVar4 = (undefined4 *)*puVar5;
      }
      else {
        puVar4 = (undefined4 *)puVar5[2];
      }
    } while (*(char *)((int)puVar4 + 0x29) == '\0');
  }
  param_3 = puVar5;
  if (bVar2) {
    if (puVar5 == (undefined4 *)**(int **)(param_1 + 4)) {
      puVar5 = (undefined4 *)FUN_004cbb60(&param_3,1,puVar5,piVar3);
      uVar1 = *puVar5;
      *(undefined1 *)(param_2 + 1) = 1;
      *param_2 = uVar1;
      return;
    }
    FUN_004cb4f0();
  }
  if (param_3[4] < *piVar3) {
    puVar5 = (undefined4 *)FUN_004cbb60(&param_3,bVar2,puVar5,piVar3);
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
| **Body** | `0x004cbe20`–`0x004cbed8` exclusive (**184 B** / `0xB8`); pad `CC` then `FUN_004cbee0` |
| **ABI** | `__thiscall`; ECX = map shell*; stack `InsertPair* out` @+4, `Val* value` @+8; **RET 8** (`C2 08 00` ×3) |
| **isnil / key** | isnil@**+0x29**; signed int key @ node **+0x10** / `*value` (`3B 50 10` / `0F 9C C1` SETL) |
| **Callees** | `FUN_004cbb60` = dualed `StdTree_InsertAndRebalance_Isnil29_Inferred` (2 sites); `FUN_004cb4f0` predecessor (1) |
| **Callers / xrefs** | `FUN_004c9380` @ `0x004c93d1`; `FUN_00518ca0` (`Skill_InsertActiveCastBinding_Inferred`) @ `0x00518cda` — **2** UNCONDITIONAL_CALL |
| **Classification** | worker (MSVC map insert-or-find shell) |
| **Named role** | `StdMap_InsertOrFind_IntKey_Isnil29_Inferred` |
| **Prior alias** | `Named_CalleeOf_…_GetTargetFromAggro_004cbe20` — **reject** product |

### Full body hex (184 B)

```
51558b6c241056578bf98b77048b460480782900b101884c240c75218b5500903b50108bf00f9cc184c9884c240c74048b00eb038b40088078290074e384c98bd68954241874338b47043b308d4c2418751f55566a01518bcfe8e2fcffff8b108b4424145f5ec640040189105d59c20800e85af6ffff8b5424188b42103b45007d268b4c240c5556518d542424528bcfe8abfcffff8b088b4424145f5e8908c64004015d59c208008b4424145f5ec640040089105d59c20800
```

### Byte seal notes

| Item | Evidence |
|---|---|
| Prologue | `51 55 8B 6C 24 10 56 57 8B F9` — push; EBP=`value*`; EDI=ECX map |
| Head/root | `8B 77 04 8B 46 04` — head@map+4; root=head[1] |
| isnil walk | `80 78 29 00` — byte @ node+0x29 |
| Signed key | `3B 50 10` / `0F 9C C1` — cmp key vs node+0x10; **SETL** |
| Leftmost insert | `6A 01` addLeft=1 + `E8` → `FUN_004cbb60` |
| Predecessor | `E8 …` → `FUN_004cb4f0` |
| Equal path | `C6 40 04 00` inserted=0; store node; **no** value rewrite |
| Epilogue | `5F 5E … 5D 59 C2 08 00` — **RET 8** ×3 |
