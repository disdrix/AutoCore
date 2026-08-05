# Raw capture: FUN_0096efd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0096efd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0096efd0` |
| **Canonical name** | `FUN_0096efd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_0096efd0(int *param_1)

{
  int *piVar1;
  int iVar2;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009ac21a;
  pvStack_c = ExceptionList;
  local_4 = 0;
  iVar2 = *param_1;
  ExceptionList = &pvStack_c;
  if (iVar2 != 0) {
    piVar1 = (int *)(iVar2 + 8);
    ExceptionList = &pvStack_c;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      (**(code **)(*(int *)(iVar2 + 4) + 8))();
    }
    *param_1 = 0;
  }
  local_4 = 0xffffffff;
  iVar2 = *param_1;
  if (iVar2 != 0) {
    piVar1 = (int *)(iVar2 + 8);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      (**(code **)(*(int *)(iVar2 + 4) + 8))();
    }
  }
  ExceptionList = pvStack_c;
  return;
}
```
# W38-P re-verify append (2026-08-04) — OWN dual; do not alter scaffold body above

## Machine seal (`read_memory`)

**Body:** `0x0096efd0`–`0x0096f03a` inclusive (**107 B** / `0x6B`); pad `CC`×5 then sibling @ `0x0096f040`.

**Full hex (107 B):**
```
6aff681ac29a0064a100000000506489250000000051568bf189742404c7442410000000008b0685c07414834008ff8d480475058b01ff5008c70600000000c7442410ffffffff8b3685f6740e834608ff8d4e0475058b11ff52088b4c24085e64890d0000000083c410c3
```

## Byte-backed CF (prefer over decompiler dual-release)

```
; SEH prolog: push -1; push LAB_009ac21a; fs:[0] chain; push ecx; push esi
mov  esi, ecx                 ; ESI = handle*
mov  [esp+4], esi
mov  dword [esp+0x10], 0      ; EH state = 0
mov  eax, [esi]               ; payload*
test eax, eax
jz   after_try
add  dword [eax+8], -1        ; refcount--
lea  ecx, [eax+4]             ; this = iface subobject
jnz  null_out
mov  eax, [ecx]
call dword [eax+8]            ; iface vtbl+8 release/destroy
null_out:
mov  dword [esi], 0
after_try:
mov  dword [esp+0x10], -1     ; EH state = done
mov  esi, [esi]               ; reload (0 after null)
test esi, esi
jz   epilog
add  dword [esi+8], -1        ; EH cleanup release (no null)
lea  ecx, [esi+4]
jnz  epilog
mov  edx, [ecx]
call dword [edx+8]
epilog:
; restore fs:[0]; add esp,0x10; ret  (not ret N)
```

## ABI seal

| Item | Value |
|------|-------|
| Convention | `__thiscall` / `__fastcall` single ptr — **ECX = handle\*** |
| Stack formals | none |
| Return | void (EAX scratch); **`ret`** (`c3`) not `ret N` |
| Payload | `+4` = iface\*, `+8` = refcount (int) |
| Release | `--rc; if 0: call (\*(iface)+8)()` with **ECX = payload+4** |
| Null | try path stores `*handle = 0`; EH-cleanup path does not |

## Classification

**Leaf** worker — refcounted handle destructor; peer of sealed `RefCountedPtr_DefaultCtor_Inferred` (`0x0096ef70`, W25-N). Massive call graph (100+ xrefs) including real code + EH Unwind@* thunks.

## Name

`RefCountedPtr_Dtor_Inferred` — **Reject** scaffold `Named_CalleeOf_CVOGTacArc_dtor_helper_0096efd0`.
