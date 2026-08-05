
# Raw capture: FUN_0075dae0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0075dae0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0075dae0` |
| **Canonical name** | `FUN_0075dae0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0075dae0(void)

{
  undefined4 *puVar1;
  uint uVar2;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009afe4b;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  FUN_0043c660();
  for (uVar2 = 0; uVar2 != 0; uVar2 = uVar2 + 1) {
    puVar1 = *(undefined4 **)(*(int *)((uVar2 >> 2) * 4) + (uVar2 + (uVar2 >> 2) * -4) * 4);
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(1);
    }
  }
  FUN_0040d9c0();
  ExceptionList = pvStack_c;
  return;
}
```

---

## Re-verify append — 2026-07-29 W30-C (OWN-ONLY)

| Field | Value |
|---|---|
| **Tool** | `decompile_function` + `analyze_function_complete` + `read_memory` (**no** `disassemble_bytes`) |
| **Live decompile** | **broken vs bytes** — loses ECX this, local header, loop bounds (`for (u=0; u!=0; …)` dead), page base (`[ESI+4]`) |
| **Body** | `0x0075dae0`–`0x0075db93` (**180 B** / `0xB4`); pad `CC` then next unit |
| **Full hex** | `6aff684bfe9a0064a100000000506489250000000083ec145333db5657895c2410895c2414895c2418895c241c8bf983c7288d74240c895c2428e841ebcdff8b7c24188d74240ceb078da424000000008b44241c8b4c24188d54240c03c13bf275043bf874338bc7c1e8028d0c85000000008bd18bcf2bca8b56083bd077022bc28b56048b04828b0c883bcb74068b116a01ff1283c701ebb78d74240ce83efecaff8b4c24205f5e5b64890d0000000083c420c3` |
| **ABI sealed** | **ECX = owner object**; no stack formals; SEH frame; epilogue `ADD ESP,0x20; RET` |
| **Local header** | Stack local at `[ESP+0x0C]` after push EBX/ESI/EDI: zeros at `+0x04/+0x08/+0x0c/+0x10` (pages/cap/begin/size) |
| **Steal** | `EDI = ECX+0x28` (B), `ESI = &local` (A) → `CALL FUN_0043c660` / `GuardedVector_ClearAndSwap` (clears A, swaps headers with B under B CS) |
| **Destroy loop** | `EDI = begin` (`local+0x0c`); while `EDI != begin+size`: page=`idx>>2`, sub=`idx&3`, if `capacity <= page` then `page -= capacity`; elem = `pages[page][sub]`; if non-null → `(*vtable)(elem, 1)` scalar deleting dtor; `idx++` |
| **Free** | `ESI = &local` → `CALL FUN_0040d9c0` (spin size→0, `operator_delete` each page + map; zero +4/+8) |
| **Classification** | worker — callees `FUN_0043c660` (ClearAndSwap), `FUN_0040d9c0` (map free), indirect vtable dtor |
| **Callers** | **0** code xrefs in Ghidra (no callers/get_xrefs_to). May be data/vtable-missed or currently unreferenced |
| **Name (inferred)** | `Owner_ClearDestroyGuardedPtrDequeAt28` |
| **Bytes override decompile** | **Mandatory** for loop bounds, ESI page base, ECX this+0x28 |

### Byte CF summary

```
SEH install (handler LAB_009afe4b)
XOR EBX,EBX; zero local +4..+10
MOV EDI, ECX; ADD EDI, 0x28     ; B = owner+0x28
LEA ESI, [local]                ; A = empty local header
CALL 0043c660                   ; ClearAndSwap(A,B)
MOV EDI, [local.begin]
loop:
  end = begin+size
  if EDI == end: break
  page = EDI>>2; sub = EDI - page*4
  if capacity <= page: page -= capacity
  elem = pages[page][sub]
  if elem: CALL [elem->vtbl](1)
  EDI++
LEA ESI, [local]; CALL 0040d9c0
SEH uninstall; ADD ESP,0x20; RET
```

