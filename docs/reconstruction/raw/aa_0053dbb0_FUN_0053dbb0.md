# Raw capture: FUN_0053dbb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053dbb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0053dbb0` |
| **Canonical name** | `FUN_0053dbb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_0053dbb0(int *param_1,char param_2)



{

  bool bVar1;

  char cVar2;

  int iVar3;

  uint uVar4;

  char *pcVar5;

  uint uVar6;

  

  cVar2 = param_2;

  if (param_1[2] != 0) {

    if (param_2 == '\0') {

      (**(code **)(*param_1 + 0x10))();

    }

    else {

      (**(code **)(*param_1 + 0xc))();

      *(undefined4 *)(param_1[2] + 0x28) = 0x10;

      if (param_1[3] != 0) {

        uVar6 = 0;

        iVar3 = (**(code **)(*(int *)param_1[3] + 0x4c))();

        if (iVar3 != 0) {

          do {

            iVar3 = (**(code **)(*(int *)param_1[3] + 0x50))();

            (**(code **)(**(int **)(iVar3 + uVar6 * 4) + 8))(4);

            uVar6 = uVar6 + 1;

            uVar4 = (**(code **)(*(int *)param_1[3] + 0x4c))();

          } while (uVar6 < uVar4);

        }

      }

    }

    FUN_00560e90(param_1[2],1);

    iVar3 = param_1[2];

    pcVar5 = (char *)FUN_005070b0(&param_2);

    if ((*pcVar5 == '\0') && (*(int *)(iVar3 + 0x44) != 0)) {

      FUN_005070d0();

    }

    (**(code **)(**(int **)(iVar3 + 0x3c) + 0x50))(&DAT_00b04610);

    iVar3 = param_1[2];

    pcVar5 = (char *)FUN_005070b0(&stack0x00000000);

    if ((*pcVar5 == '\0') && (*(int *)(iVar3 + 0x44) != 0)) {

      FUN_005070d0();

    }

    (**(code **)(**(int **)(iVar3 + 0x3c) + 0x54))(&DAT_00b04610);

    iVar3 = param_1[2];

    if (iVar3 != 0) {

      if ((*(char *)(iVar3 + 0x40) == '\0') || (*(int *)(iVar3 + 8) == 0)) {

        bVar1 = true;

      }

      else {

        bVar1 = false;

      }

      bVar1 = !bVar1;

      if (!bVar1) {

        if ((*(char *)(iVar3 + 0x40) == '\0') || (*(int *)(iVar3 + 8) == 0)) {

          bVar1 = true;

        }

        if (bVar1) {

          if (cVar2 == '\0') {

            FUN_005d4440(1);

            return;

          }

          FUN_005d4440(6);

          return;

        }

      }

    }

  }

  return;

}
```


---

## W26-E re-verify (2026-07-29) — live Ghidra seal

| Field | Value |
|---|---|
| **Agent** | W26-E OWN-ONLY dual |
| **Tools** | `decompile_function` + `read_memory` + `analyze_function_complete` + `get_function_by_address` |
| **Forbidden** | `disassemble_bytes` (not used); Launcher (not used) |
| **Program** | `autoassault.exe` base `0x400000` |
| **Body** | `0x0053dbb0`–`0x0053dcf6` inclusive (**327 / `0x147` B**); pad `CC` @ `0x0053dcf7` |
| **Prologue** | `53 56 8B F1 83 7E 08 00 57` — push ebx/esi; `mov esi,ecx`; gate `*(this+8)` |
| **Epilogue** | `5F 5E 5B C2 04 00` — `ret 4`; **tail-call** paths rewrite stack formal then `JMP FUN_005d4440` |
| **ABI** | **thiscall**; ECX = object (`param_1`); stack+4 = **char mode flag** (`param_2`); void |
| **Classification** | worker (vtable method — 8 rdata xrefs, 0 direct function callers) |
| **Vtable xrefs (8)** | `0x009ce828`, `0x009ceb78`, `0x009cfda8`, `0x009d4cd8`, `0x009da720`, `0x009cbe88`, `0x009cd790`, `0x009db938` |
| **Callees** | self vtbl **+0x10** / **+0xc**; child-list vtbl **+0x4c/+0x50** + child vtbl **+8**; `FUN_00560e90` (WorldObj_RebindActivate); `FUN_005070b0`×2; `FUN_005070d0`×2; AI host vtbl **+0x50/+0x54**; tail `FUN_005d4440` (CVOGObject_SwitchHBAIByCode) with code **1** or **6** |
| **Named role (INFERRED)** | `CVOGObject_ApplyModeFlag_RebindSwitchHBAI_Inferred` |
| **Integrity** | Live decompile ≡ 2026-07-23 raw body (identical CF) |

### Live decompile (authoritative 2026-07-29)

```c
void __thiscall FUN_0053dbb0(int *param_1,char param_2)
{
  bool bVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  uint uVar6;
  
  cVar2 = param_2;
  if (param_1[2] != 0) {
    if (param_2 == '\0') {
      (**(code **)(*param_1 + 0x10))();
    }
    else {
      (**(code **)(*param_1 + 0xc))();
      *(undefined4 *)(param_1[2] + 0x28) = 0x10;
      if (param_1[3] != 0) {
        uVar6 = 0;
        iVar3 = (**(code **)(*(int *)param_1[3] + 0x4c))();
        if (iVar3 != 0) {
          do {
            iVar3 = (**(code **)(*(int *)param_1[3] + 0x50))();
            (**(code **)(**(int **)(iVar3 + uVar6 * 4) + 8))(4);
            uVar6 = uVar6 + 1;
            uVar4 = (**(code **)(*(int *)param_1[3] + 0x4c))();
          } while (uVar6 < uVar4);
        }
      }
    }
    FUN_00560e90(param_1[2],1);
    iVar3 = param_1[2];
    pcVar5 = (char *)FUN_005070b0(&param_2);
    if ((*pcVar5 == '\0') && (*(int *)(iVar3 + 0x44) != 0)) {
      FUN_005070d0();
    }
    (**(code **)(**(int **)(iVar3 + 0x3c) + 0x50))(&DAT_00b04610);
    iVar3 = param_1[2];
    pcVar5 = (char *)FUN_005070b0(&stack0x00000000);
    if ((*pcVar5 == '\0') && (*(int *)(iVar3 + 0x44) != 0)) {
      FUN_005070d0();
    }
    (**(code **)(**(int **)(iVar3 + 0x3c) + 0x54))(&DAT_00b04610);
    iVar3 = param_1[2];
    if (iVar3 != 0) {
      if ((*(char *)(iVar3 + 0x40) == '\0') || (*(int *)(iVar3 + 8) == 0)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      bVar1 = !bVar1;
      if (!bVar1) {
        if ((*(char *)(iVar3 + 0x40) == '\0') || (*(int *)(iVar3 + 8) == 0)) {
          bVar1 = true;
        }
        if (bVar1) {
          if (cVar2 == '\0') {
            FUN_005d4440(1);
            return;
          }
          FUN_005d4440(6);
          return;
        }
      }
    }
  }
  return;
}
```

### Machine hex (prologue + tail)

Entry 64 B @ `0x0053dbb0`:
```
53568bf1837e0800570f84320100008a5c241084db744e8b06ff500c8b4e08c7412810000000837e0c00743e8b4e0c8b1133ffff524c85c076308d9b00000000
```
- `8B F1` this in ESI
- `83 7E 08 00` gate `this+8` (`param_1[2]`)
- `8A 5C 24 10` load mode flag after 3 pushes
- Non-zero path: `CALL [eax+0xc]`; `MOV dword [ecx+0x28],0x10`

Tail @ `0x0053dcd0` region (both JMP targets `0x005d4440`):
```
… 5F 5E 5B C7 44 24 04 06 00 00 00 E9 …   ; flag!=0 → SwitchHBAI(6)
… 5F 5E 5B C7 44 24 04 01 00 00 00 E9 …   ; flag==0 → SwitchHBAI(1)
… 5F 5E 5B C2 04 00                           ; plain ret 4
```

### Sealed ABI

```
// __thiscall; ECX=CVOGObject*; stack char modeFlag; ret 4
// Virtual method (installed in multiple rdata vtables)
void CVOGObject_ApplyModeFlag_RebindSwitchHBAI_Inferred(CVOGObject* this /*ECX*/, char modeFlag /*stack+4*/);
```

### Sealed CF stages

1. Early-out if `this[+8] == 0` (no world-obj / host at `param_1[2]`).
2. **modeFlag == 0**: self vtbl **+0x10** only.
3. **modeFlag != 0**: self vtbl **+0xc**; write `*(this[+8]+0x28) = 0x10`; if `this[+0xc]` list non-null, iterate count via list vtbl **+0x4c**, items via **+0x50**, call each child vtbl **+8**(4).
4. `FUN_00560e90(this[+8], 1)` — **WorldObj_RebindActivate** (unbind `0055fbf0` + bind `0055fa40` + flag).
5. Lock pair around AI host `*(worldObj+0x3c)`:
   - `FUN_005070b0` + optional `FUN_005070d0`; AI vtbl **+0x50**(`&DAT_00b04610`)
   - again for vtbl **+0x54**(`&DAT_00b04610`)
6. If worldObj has **not** both (`*(char*)(obj+0x40)!=0` **and** `*(obj+8)!=0`):
   - modeFlag==0 → tail `FUN_005d4440(1)` (normal AI family code 1)
   - modeFlag!=0 → tail `FUN_005d4440(6)` (WalkingCreatureTurreted family)
7. Else leave AI unchanged.

### Bool residual note

Decompiler expands a double-negated predicate that reduces to:
`needsSwitch = (obj+0x40 == 0) || (obj+8 == 0)`.
When `needsSwitch`, pick AICode 1 vs 6 from mode flag. Product English of `obj+0x40` / `obj+8` remains open (shared with bind helper's `obj+0x40` gate).
