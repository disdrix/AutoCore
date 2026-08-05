# Raw capture: aa_005532e0 Skill_ValidateTarget_HBSkillListener

| Field | Value |
|---|---|
| **Stable ID** | `aa_005532e0` |
| **VA** | `0x005532e0` – `0x00553384` |
| **Size** | `0xA5` bytes (61 instructions, 10 BBs) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Capture date** | `2026-07-29` |
| **Method** | Ghidra decompile + force_decompile + `read_memory` body + high P-code + RTTI `read_memory` |
| **Three-rep** | (A) decompile, (B) force_decompile (identical CF), (C) raw bytes / P-code RTTI constants |

---

## Live decompile (force refresh, identical to first decompile)

```c
undefined4 Skill_ValidateTarget_HBSkillListener(int param_1, undefined4 *param_2)
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined1 *unaff_retaddr;   // MISIDENTIFIED — is formal #3 char* stopFlag (Stack[0xC])

  if (*(int *)(param_1 + 0x1c) == 1) {
    piVar2 = (int *)__RTDynamicCast(param_1, 0,
                                    &CVOGHBBase::RTTI_Type_Descriptor,
                                    &CVOGHBSkillBase::RTTI_Type_Descriptor, 0);
    if ((char)piVar2[8] == '\0') {          // byte at hb+0x20
      piVar1 = *(int **)(param_2[1] + 0x5f0);
      if (piVar1 == (int *)0x0) {
        FUN_007a4480(1, "Skill found with no base class: %d", piVar2[0x188]); // +0x620
      } else {
        iVar3 = (**(code **)(*piVar1 + 0x44))(*param_2, param_2[1], piVar2);
        if (iVar3 == 1) {
          *(undefined1 *)(param_2 + 2) = 0;  // ctx+8 result=0
          *unaff_retaddr = 1;               // *stop=1
          return 0;                         // AL=0 do not remove
        }
        if (iVar3 == 2) {
          *(undefined1 *)(param_2 + 2) = 1;  // ctx+8 result=1
          *unaff_retaddr = 1;               // *stop=1
          if (*(char *)((int)param_2 + 9) != '\0') {
            (**(code **)(*piVar2 + 0x18))(1, 0);  // thiscall ECX=hb
            return 1;                       // AL=1 remove node
          }
        }
      }
    }
  }
  return 0;
}
```

**Decompiler caveats (asm is authority):**

| Issue | Correction |
|---|---|
| 2 formals + `unaff_retaddr` | **3 stdcall formals** `(payload, ctx, char* stop)`; `ret 0x0C` |
| No null check after cast | Confirmed — type tag `+0x1c==1` is the only pre-cast gate |
| `return` type `undefined4` | Real return is **AL** (0 = keep node, 1 = remove) |
| Virtual call display | ECX = handler; stack `(target, skill, hb)` via `call [vtbl+0x44]` |

---

## Raw body hex (`read_memory` @ `0x005532e0`, 160B; body ends `0x00553384`)

```
8b442404 83781c01 56570f85 8e000000 6a0068ec 8caf0068 988daf00 6a0050e8
a065f3ff 8bf883c4 14807f20 00756f8b 7424108b 46048b88 f0050000 85c97448
8b115750 8b0650ff 524483f8 0175118b 4c2414c6 4608005f 880132c0 5ec20c00
83f80275 398b5424 14c64608 01c60201 807e0900 74288b07 6a006a01 8bcfff50
185fb001 5ec20c00 8b8f2006 00005168 4c259d00 6a01e805 11250083 c40c5f32
c05ec20c 00cc...
```

---

## Assembly reconstruction (authority)

```asm
; __stdcall Skill_ValidateTarget_HBSkillListener(void* hbPayload, ValidateTargetCtx* ctx, char* stop)
005532e0  mov  eax, [esp+4]          ; hbPayload
005532e4  cmp  dword ptr [eax+0x1c], 1   ; TYPE TAG == 1 (skill HB)
005532e8  push esi
005532e9  push edi
005532ea  jnz  ret0                 ; +0x8e → shared ret0

; __RTDynamicCast(hb, 0, CVOGHBBase, CVOGHBSkillBase, 0)
005532f0  push 0
005532f2  push offset CVOGHBSkillBase::RTTI_Type_Descriptor  ; 0x00af8cec
005532f7  push offset CVOGHBBase::RTTI_Type_Descriptor       ; 0x00af8d98
005532fc  push 0
005532fd  push eax
005532fe  call __RTDynamicCast      ; 0x004898a4
00553303  mov  edi, eax             ; CVOGHBSkillBase*
00553305  add  esp, 0x14
00553308  cmp  byte ptr [edi+0x20], 0    ; cStopped / skip flag
0055330c  jnz  ret0

0055330e  mov  esi, [esp+0x10]      ; ctx
00553312  mov  eax, [esi+4]         ; ctx.pSkill
00553315  mov  ecx, [eax+0x5f0]     ; handler
0055331b  test ecx, ecx
0055331d  jz   no_handler

0055331f  mov  edx, [ecx]           ; vtbl; ECX=handler this
00553321  push edi                  ; hb
00553322  push eax                  ; skill
00553323  mov  eax, [esi]           ; ctx.pTarget
00553325  push eax
00553326  call dword ptr [edx+0x44]

00553329  cmp  eax, 1
0055332c  jnz  check_accept
; reject:
0055332e  mov  ecx, [esp+0x14]      ; stop*
00553332  mov  byte ptr [esi+8], 0  ; ctx.result = 0
00553336  pop  edi
00553337  mov  [ecx], al            ; *stop = 1 (AL still 1)
00553339  xor  al, al               ; return 0 (do not remove)
0055333b  pop  esi
0055333c  ret  0x0C

check_accept:
0055333f  cmp  eax, 2
00553342  jnz  ret0
00553344  mov  edx, [esp+0x14]
00553348  mov  byte ptr [esi+8], 1  ; ctx.result = 1
0055334c  mov  byte ptr [edx], 1    ; *stop = 1
0055334f  cmp  byte ptr [esi+9], 0  ; ctx.notifyHB
00553353  jz   ret0
00553355  mov  eax, [edi]
00553357  push 0
00553359  push 1
0055335b  mov  ecx, edi
0055335d  call dword ptr [eax+0x18] ; hb->vtbl+0x18(1,0)
00553360  pop  edi
00553361  mov  al, 1                ; return 1 (remove node)
00553363  pop  esi
00553364  ret  0x0C

no_handler:
00553367  mov  ecx, [edi+0x620]     ; skill id (dword index 0x188)
0055336d  push ecx
0055336e  push offset aSkillFoundWithNoBaseClass  ; 0x009d254c
00553373  push 1
00553375  call FUN_007a4480
0055337a  add  esp, 0x0C
; fallthrough ret0
ret0:
0055337f  pop  edi                  ; (shared; actual labels may merge)
00553380  xor  al, al
00553382  pop  esi
00553383  ret  0x0C
```

Body range from Ghidra: `005532e0`–`00553384`.

---

## RTTI path (sealed via `read_memory`)

| Role | Address | Bytes / name |
|---|---|---|
| **Src type_info** | `0x00af8d98` | `".?AVCVOGHBBase@@"` |
| **Dst type_info** | `0x00af8cec` | `".?AVCVOGHBSkillBase@@"` |
| Cast API | `__RTDynamicCast` @ ~`0x004898a4` | MSVC `(inptr, VfDelta=0, src, dst, isRef=0)` |
| Push order (cdecl, R→L) | — | `isRef=0`, `dst=af8cec`, `src=af8d98`, `VfDelta=0`, `inptr` |

Ctor cross-seal: `CVOGHBSkillBase_ctor` COL `0x00aaede0` → same type_info `0x00af8cec`; writes type tag `this+0x1c = 1`.

---

## String

| Address | Value |
|---|---|
| `0x009d254c` | `"Skill found with no base class: %d"` |

Logged via `FUN_007a4480(1, fmt, skillId)` when `skill+0x5F0` handler is null.

---

## Xrefs

| From | Kind | Parent |
|---|---|---|
| `0x00553684` | DATA (predicate pointer push) | `Skill_ValidateTargetForSkill` @ `0x00553650` |

Sole consumer. Invoked as `CNDDoubleList_InvokePredicateAndRemove_Inferred` callback: `(payload=node[1], ctx, &stop)`.

---

## Type tag seal

| Offset | Value required | Writer | Confidence |
|---|---|---|---|
| HB `+0x1c` (dword) | **`1`** | `CVOGHBSkillBase_ctor` (`self[7]=1`) | **Confirmed** |
| HB `+0x20` (byte) | **`0`** to enter handler path | base field `cStopped` (name High) | **Confirmed** gate; product English High |
| Other type tags | Not handled | — | Non-1 → immediate AL=0 |

---

## ValidateTargetCtx (listener view)

| Off | Field | Listener access |
|---:|---|---|
| `+0` | `pTarget` | passed to handler vcall |
| `+4` | `pSkill` | `+0x5F0` handler load; vcall skill arg |
| `+8` | `result` | written `0` on code 1; `1` on code 2 |
| `+9` | `notifyHB` | gates `hb.vtbl+0x18(1,0)` + remove |

---

## Callees

| Target | Role |
|---|---|
| `__RTDynamicCast` | `CVOGHBBase` → `CVOGHBSkillBase` |
| `FUN_007a4480` | log missing handler |
| handler `vtbl+0x44` | re-probe legality with HB third arg |
| HB `vtbl+0x18` | notify on accept when `notifyHB!=0` |
