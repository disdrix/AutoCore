# Raw capture: FUN_008aec40

| Field | Value |
|---|---|
| **Stable ID** | `aa_008aec40` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008aec40` |
| **Canonical name** | `FUN_008aec40` |
| **System** | missions-progression (client mission dialog UI) |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall FUN_008aec40(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  int unaff_EDI;
  float10 fVar7;
  undefined1 auStack_8 [8];
  
  if ((param_3 < 0x9c46) || (0x9c4d < param_3)) {
    if ((0x9c4e < param_3) && (param_2 == 8)) {
      if ((*(int *)(param_1 + 0x72c) != 0) &&
         (param_3 - 0x9c4fU < (uint)(*(int *)(param_1 + 0x730) - *(int *)(param_1 + 0x72c) >> 2))) {
        Client_ShowNpcMissionDialogUI(&DAT_00d1a840,*(undefined4 *)(param_1 + 0x644),0);
      }
      return 1;
    }
  }
  else if (param_2 == 8) {
    cVar1 = Client_MissionDialogHandleButton((int *)(param_3 + -0x9c46),unaff_EDI);
    if (cVar1 == '\0') {
      return 1;
    }
    goto LAB_008aef8f;
  }
  switch(param_3) {
  case 40000:
    if (param_2 == 8) {
LAB_008aef8f:
      FUN_007fca10();
      if (*(int *)(param_1 + 0x648) == 2) {
        FUN_007fef20(0x13,1,0);
      }
      return 1;
    }
    break;
  case 0x9c41:
    if (param_2 == 0x1a) {
      if ((*(int *)(param_1 + 0x700) != 0) && (*(int *)(param_1 + 0x6e0) != 0)) {
        fVar7 = (float10)(**(code **)(**(int **)(param_1 + 0x700) + 0x458))();
        iVar2 = (int)ROUND((float)((float10)*(int *)(param_1 + 0x704) * fVar7 +
                                  (float10)DAT_00aaa664));
        iVar6 = (**(code **)(**(int **)(param_1 + 0x6e0) + 0x218))();
        if (iVar6 != iVar2) {
          (**(code **)(**(int **)(param_1 + 0x6e0) + 0x214))(iVar2);
          (**(code **)(**(int **)(param_1 + 0x6e0) + 0x34c))();
        }
      }
      return 1;
    }
    break;
  case 0x9c42:
  case 0x9c43:
  case 0x9c44:
  case 0x9c45:
    if (param_2 == 5) {
      iVar2 = CVOGReaction_ResolveObjectTarget
                        (1,*(undefined4 *)(param_1 + -0x4dcb8 + param_3 * 8),
                         *(undefined4 *)(param_1 + -0x4dcb4 + param_3 * 8));
      if (iVar2 != 0) {
        puVar3 = (undefined4 *)
                 (**(code **)(**(int **)(param_1 + -0x26a70 + param_3 * 4) + 0x140))(auStack_8,1);
        puVar4 = (undefined4 *)
                 (**(code **)(**(int **)(param_1 + -0x26a70 + param_3 * 4) + 0x120))
                           (&stack0xffffffe8,1,1);
        FUN_007fd420(*puVar4,puVar4[1],*puVar3,puVar3[1]);
        if (((*(int *)(param_1 + -0x4dcb8 + param_3 * 8) != *(int *)(param_1 + 0x578)) ||
            (*(int *)(param_1 + -0x4dcb4 + param_3 * 8) != *(int *)(param_1 + 0x57c))) &&
           (*(char *)(param_1 + 0x64c) != '\0')) {
          (**(code **)(**(int **)(param_1 + -0x26a70 + param_3 * 4) + 0x158))(0,param_1 + 0x584);
          cVar1 = (**(code **)(**(int **)(param_1 + -0x26a70 + param_3 * 4) + 0xf8))();
          if (cVar1 != '\0') {
            *(int *)(*(int *)(param_1 + -0x26a70 + param_3 * 4) + 0xf8) =
                 (int)(*(float *)(param_1 + 0x590) * DAT_00aaa6f8);
          }
          (**(code **)(**(int **)(param_1 + -0x26a70 + param_3 * 4) + 0x34c))();
        }
      }
    }
    else if (param_2 == 6) {
      DAT_00d1d8f4 = 1;
      DAT_00d1d8f5 = 0;
      if (DAT_00d1d8dc != (int *)0x0) {
        (**(code **)(*DAT_00d1d8dc + 4))(0);
      }
      if (((*(int *)(param_1 + -0x4dcb8 + param_3 * 8) != *(int *)(param_1 + 0x578)) ||
          (*(int *)(param_1 + -0x4dcb4 + param_3 * 8) != *(int *)(param_1 + 0x57c))) &&
         (*(char *)(param_1 + 0x64c) != '\0')) {
        (**(code **)(**(int **)(param_1 + -0x26a70 + param_3 * 4) + 0x158))(0,param_1 + 0x594);
        cVar1 = (**(code **)(**(int **)(param_1 + -0x26a70 + param_3 * 4) + 0xf8))();
        if (cVar1 != '\0') {
          *(int *)(*(int *)(param_1 + -0x26a70 + param_3 * 4) + 0xf8) =
               (int)(*(float *)(param_1 + 0x5a0) * DAT_00aaa6f8);
        }
        (**(code **)(**(int **)(param_1 + -0x26a70 + param_3 * 4) + 0x34c))();
        uVar5 = FUN_0087b500(6,param_3);
        return uVar5;
      }
    }
    else if ((param_2 == 8) && (*(char *)(param_1 + 0x64c) != '\0')) {
      FUN_008aa3f0(param_3 + -0x9c42);
      uVar5 = FUN_0087b500(8,param_3);
      return uVar5;
    }
  }
  uVar5 = FUN_0087b500(param_2,param_3);
  return uVar5;
}
```

---

## Live seal append — 2026-07-29 (OWN-ONLY dual A/B W17-A)

| Field | Value |
|---|---|
| **Tool** | Ghidra MCP `decompile_function` + `read_memory` + `get_function_by_address` + `get_function_xrefs` + `get_function_callees` + `get_function_signature` |
| **Program** | `autoassault.exe` |
| **Body span** | `008aec40` – `008aefbb` |
| **Xref** | **DATA** only @ `0x00a4a854` (vtable slot → `0x008aec40`) |
| **Live decompile** | **≡** 2026-07-23 raw body |
| **Signature tool note** | Reports 5 named direct callees (incomplete vs full decompile: also `CVOGReaction_ResolveObjectTarget`, `FUN_007fd420`, `FUN_008aa3f0`, many vtbl) |

### Constants (`read_memory`)

| VA | Bytes (LE) | Value | Role here |
|---|---|---|---|
| `0x00aaa664` | `17 b7 d1 38` | **~1e-4** (`9.9999997e-05`) | ROUND bias on slider/scale path (`case 0x9c41`) |
| `0x00aaa6f8` | `00 00 7f 43` | **255.0f** | UI field scale write to widget `+0xf8` |
| `0x00a4a854` | `40 ec 8a 00 …` | ptr **`0x008aec40`** | vtable DATA install |

### Entry / convention notes (`read_memory` @ `0x008aec40`)

```
83 ec 10          sub esp, 0x10
53                push ebx
8b 5c 24 1c       mov ebx, [esp+0x1c]   ; param_3 = control id
81 fb 46 9c 00 00 cmp ebx, 0x9c46
56 57             push esi, edi
8b f1             mov esi, ecx          ; this = dialog UI object
...
c2 08 00          ret 8                 ; thiscall, 2 stack args (msg, controlId)
```

Button range path (`0x9c46`–`0x9c4d`, msg==8):

```
81 c3 ba 63 ff ff  add ebx, -0x9c46     ; button index 0..7
53                 push ebx
8b c6              mov eax, esi         ; dialog this → EAX for HandleButton
e8 …               call Client_MissionDialogHandleButton
```

**`unaff_EDI` in decompile is a Ghidra artifact** — image pushes only the button index; HandleButton consumes dialog in **EAX** + one stack arg (see `Client_MissionDialogHandleButton` plate).

### Control-id map (this body)

| ID | Hex | Path (when msg matches) |
|---|---|---|
| 40000 | `0x9c40` | msg 8 → close: `FUN_007fca10` (+ abandon chrome `FUN_007fef20(0x13,1,0)` if state `+0x648==2`) |
| 40001 | `0x9c41` | msg `0x1a` → scale/slider sync via vtbl on `+0x700` / `+0x6e0` |
| 40002–40005 | `0x9c42`–`0x9c45` | reward slots: msg 5 focus, 6 drag-ish, 8 click (`FUN_008aa3f0`) |
| 40006–40013 | `0x9c46`–`0x9c4d` | msg 8 → `Client_MissionDialogHandleButton(index)` then maybe close |
| ≥40015 | `≥0x9c4f` | msg 8 + index in table `[+0x72c,+0x730)` → `Client_ShowNpcMissionDialogUI` |

### Indexed reward-slot bases (param_3 in 0x9c42..0x9c45)

| Expression | For id `0x9c42` | Role |
|---|---|---|
| `this - 0x4dcb8 + id*8` | `this+0x558` | TFID lo (hi at +4) |
| `this - 0x26a70 + id*4` | `this+0x698` | widget ptr slot |
