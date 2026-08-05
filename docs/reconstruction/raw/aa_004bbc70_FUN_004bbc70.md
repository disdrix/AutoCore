# Raw capture: FUN_004bbc70

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bbc70` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004bbc70` |
| **Canonical name** | `FUN_004bbc70` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_004bbc70(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  _RTL_CRITICAL_SECTION local_34;
  _RTL_CRITICAL_SECTION local_1c;
  undefined4 local_4;
  
  *param_1 = &PTR_FUN_009cb448;
  iVar2 = 0;
  local_4 = 0xffffffff;
  InitializeCriticalSection(&local_34);
  InitializeCriticalSection(&local_1c);
  iVar1 = param_1[1];
  if (*(char *)(iVar1 + 0x1d) != '\0') {
    FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");
    FUN_007a4480(0,"VOG_DEBUG_STOP");
  }
  *(undefined1 *)(iVar1 + 0x1d) = 1;
  while( true ) {
    iVar1 = param_1[1];
    if (*(char *)(iVar1 + 0x1d) == '\0') {
      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");
      FUN_007a4480(0,"VOG_DEBUG_STOP");
    }
    if (iVar2 == 0) {
      iVar2 = *(int *)(iVar1 + 0x14);
    }
    else {
      iVar2 = *(int *)(iVar2 + 0x20);
    }
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(iVar2 + 0xc);
    }
    if (iVar1 == 0) break;
    if (*(int *)(iVar1 + 0xac) != 0) {
      FUN_004024d0(iVar1);
    }
  }
  *(undefined1 *)(param_1[1] + 0x1d) = 0;
  iVar1 = param_1[2];
  iVar2 = 0;
  if (*(char *)(iVar1 + 0x1d) != '\0') {
    FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");
    FUN_007a4480(0,"VOG_DEBUG_STOP");
  }
  *(undefined1 *)(iVar1 + 0x1d) = 1;
  while( true ) {
    iVar1 = param_1[2];
    if (*(char *)(iVar1 + 0x1d) == '\0') {
      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");
      FUN_007a4480(0,"VOG_DEBUG_STOP");
    }
    if (iVar2 == 0) {
      iVar2 = *(int *)(iVar1 + 0x14);
    }
    else {
      iVar2 = *(int *)(iVar2 + 0x20);
    }
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(iVar2 + 0xc);
    }
    if (iVar1 == 0) break;
    if (*(int *)(iVar1 + 0xac) != 0) {
      FUN_004024d0(iVar1);
    }
  }
  *(undefined1 *)(param_1[2] + 0x1d) = 0;
  iVar1 = FUN_0040b020();
  while (iVar1 != 0) {
    FUN_004bb970(*(undefined1 *)(iVar1 + 0x168),*(undefined4 *)(iVar1 + 0x160),
                 *(undefined4 *)(iVar1 + 0x164));
    iVar1 = FUN_0040b020();
  }
  if ((undefined4 *)param_1[6] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[6])(1);
  }
  param_1[6] = 0;
  if ((undefined4 *)param_1[7] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[7])(1);
  }
  param_1[7] = 0;
  if ((undefined4 *)param_1[8] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[8])(1);
  }
  param_1[8] = 0;
  if ((undefined4 *)param_1[9] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[9])(1);
  }
  param_1[9] = 0;
  if ((undefined4 *)param_1[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[1])(1);
  }
  param_1[1] = 0;
  if ((undefined4 *)param_1[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[2])(1);
  }
  param_1[2] = 0;
  FUN_004bcbf0();
  if ((void *)param_1[0x13] != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    operator_delete((void *)param_1[0x13]);
  }
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  if ((void *)param_1[0xf] != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    operator_delete((void *)param_1[0xf]);
  }
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  if ((void *)param_1[0xb] != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    operator_delete((void *)param_1[0xb]);
  }
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  return;
}
```

---

## Re-verify — 2026-07-29 (W26-J OWN-ONLY dual)

| Field | Value |
|---|---|
| **Tool** | Ghidra `decompile_function` + `read_memory` + callers / callees / xrefs (**no** `disassemble_bytes`) |
| **Live decompile** | **≡** 2026-07-23 raw pseudocode (CF identity) |
| **Body** | `0x004bbc70`–`0x004bbea4` (**565 B** / `0x235`); pad `CC` after final `C3` |
| **Entry hex** | `83 EC 44 53 55 8B 2D EC 61 9C 00 56 57 33 DB … C7 06 48 B4 9C 00` → frame `0x44`; ESI=this; `*this = PTR_FUN_009cb448` |
| **Stack list** | Before ICS: `[esp+list] = PTR_FUN_009cb368` (ThreadSafeObjectList vtbl) + head/tail/count zero + ICS at list+`0x10`/`+0x28` |
| **Exit hex** | `5E 5D 5B 83 C4 44 C3` → restore; `add esp,0x44`; bare `ret` |
| **ABI** | `__thiscall`/`__fastcall` — **ECX = this***; **void** |
| **Class** | **COList** — vtbl rdata strings `Threw error in COList::Insert` / `Threw HRESULT in COList::Insert` @ `0x009cb464+` |
| **Scalar dtor** | `FUN_004bd1b0` = body + optional `operator_delete` if flag&1 (`ret 4`) — vtbl[0] @ `0x009cb448` |
| **Ctor twin** | `FUN_004bbfb0` installs same vtbl; published as `DAT_00b04830 = COList_ctor(5,10)` from `Client_InitInstance` |
| **Caller (1)** | `FUN_004bd1b0` only (scalar-deleting wrapper) |
| **Callees** | `FUN_004024d0` (append), `FUN_0040b020` (PopFront), `FUN_004bb970` (ClonedObjectList_TakeByCoid), `FUN_004bcbf0` (list dtor on **stack** temp), `FUN_007a4480`, `InitializeCriticalSection`, `operator_delete` |
| **CF summary** | Construct stack ThreadSafeObjectList → traverse hashes `this+4` / `this+8` (CNDHash lock@+0x1d) collecting objs with `+0xac≠0` → drain via PopFront calling TakeByCoid → virtual-delete owned slots 6,7,8,9,1,2 → dtor stack list → free vector buffers at dword indices 0x13, 0xf, 0xb |

