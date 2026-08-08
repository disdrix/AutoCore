# Raw capture: FUN_0090cbc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0090cbc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0090cbc0` |
| **Canonical name** | `FUN_0090cbc0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0090cbc0(void)

{
  int iVar1;
  char cVar2;
  int *in_EAX;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  int iStack_4;
  
  iVar1 = DAT_00d1b6d8;
  if ((DAT_00d1b6d8 != 0) && (cVar2 = (**(code **)(*in_EAX + 0x3d8))(), cVar2 != '\0')) {
    FUN_0090c700();
    iVar5 = 0;
    iVar3 = FUN_0090c810();
    if (0 < iVar3) {
      iVar6 = (iVar3 + -0x19) / 3 + 1;
      in_EAX[0x169] = iVar6;
      if (iVar3 < 0x19) {
        in_EAX[0x169] = 0;
        in_EAX[0x143] = 0;
      }
      else if (iVar6 < in_EAX[0x143]) {
        in_EAX[0x143] = iVar6;
      }
      if ((int *)in_EAX[0x168] != (int *)0x0) {
        iVar3 = *(int *)in_EAX[0x168];
        if (in_EAX[0x169] == 0) {
          (**(code **)(iVar3 + 0xcc))(0);
        }
        else {
          (**(code **)(iVar3 + 0xcc))(1);
          (**(code **)(*(int *)in_EAX[0x168] + 0x460))(g_flOne / (float)in_EAX[0x169]);
        }
        (**(code **)(*(int *)in_EAX[0x168] + 0x34c))();
      }
      puVar7 = *(undefined4 **)(iVar1 + 0x574);
      iStack_4 = -1;
      do {
        if (puVar7 == *(undefined4 **)(iVar1 + 0x578)) break;
        iVar3 = FUN_0051a0e0(*puVar7);
        if ((iVar3 != 0) && (iStack_4 = iStack_4 + 1, in_EAX[0x143] * 3 <= iStack_4)) {
          FUN_0090c9a0(iVar3,1);
          iVar5 = iVar5 + 1;
        }
        puVar7 = puVar7 + 1;
      } while (iVar5 < 0x18);
      iVar3 = *(int *)(iVar1 + 0x540);
      iVar6 = 0;
      if (*(char *)(iVar3 + 0x1d) != '\0') {
        FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");
        FUN_007a4480(0,"VOG_DEBUG_STOP");
      }
      *(undefined1 *)(iVar3 + 0x1d) = 1;
      iVar3 = iVar5;
      while (iVar5 < 0x18) {
        iVar4 = *(int *)(iVar1 + 0x540);
        if (*(char *)(iVar4 + 0x1d) == '\0') {
          FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");
          FUN_007a4480(0,"VOG_DEBUG_STOP");
        }
        if (iVar6 == 0) {
          iVar6 = *(int *)(iVar4 + 0x14);
        }
        else {
          iVar6 = *(int *)(iVar6 + 0x14);
        }
        if (iVar6 == 0) {
          iVar4 = 0;
        }
        else {
          iVar4 = *(int *)(iVar6 + 8);
        }
        if (iVar4 == 0) break;
        iVar4 = FUN_0051a0e0(*(undefined4 *)(iVar4 + 0x100));
        if ((iVar4 != 0) && (iStack_4 = iStack_4 + 1, in_EAX[0x143] * 3 <= iStack_4)) {
          FUN_0090c9a0(iVar4,0);
          iVar5 = iVar3 + 1;
          iVar3 = iVar5;
        }
      }
      *(undefined1 *)(*(int *)(iVar1 + 0x540) + 0x1d) = 0;
      return;
    }
    in_EAX[0x143] = 0;
    if ((int *)in_EAX[0x168] != (int *)0x0) {
      (**(code **)(*(int *)in_EAX[0x168] + 4))(0);
    }
  }
  return;
}
```

---

## MEGA-063 live re-verify (2026-08-05) — APPEND ONLY

| Field | Value |
|---|---|
| **Wave** | OWN-ONLY dual **MEGA-063** |
| **Tools** | `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_callers` + `get_function_xrefs` + `get_assembly_context` + `read_memory` + `get_function_signature`. **No** `disassemble_bytes`. |
| **Image** | `autoassault.exe` base `0x400000` |
| **Terminal** | **false** (no Launcher / no runtime Confirmed) |

### Body / size

| Item | Value |
|---|---|
| Start | `0x0090cbc0` |
| End (inclusive last `RET`) | `0x0090cdfe` |
| Size | **575 B** / `0x23F` |
| Next | `CC` pad @ `0x0090cdff`; next prologue `SUB ESP,0x10` @ `0x0090ce00` |
| Signature stats | 171 insns, 40 BBs, 59 edges, cyclomatic **21**, 10 calls |

### Entry / exit bytes (`read_memory`)

**Entry 64 B @ `0x0090cbc0`:**
```
83 EC 0C 53 8B 1D D8 B6 D1 00 85 DB 56 8B F0 89 5C 24 0C 0F 84 20 02 00 00 8B 06 8B CE FF 90 D8 03 00 00 84 C0 0F 84 0E 02 00 00 55 57 8B FE E8 0C FB FF FF 33 ED 89 6C 24 10 E8 11 FC FF FF 8B
```

**Exit @ `0x0090cdfe`:** `C3` (`RET`); pad `CC`.

### Disasm authority (prologue / key branches / epilogues)

```text
0090cbc0  SUB  ESP,0xC
0090cbc3  PUSH EBX
0090cbc4  MOV  EBX,dword ptr [DAT_00d1b6d8]
0090cbca  TEST EBX,EBX
0090cbcc  PUSH ESI
0090cbcd  MOV  ESI,EAX                    ; ABI: EAX = MedalUI host
0090cbcf  MOV  [ESP+0xC],EBX              ; spill manager*
0090cbd3  JZ   0x0090cdf9                 ; epilogue if no manager
0090cbd9  MOV  EAX,[ESI]
0090cbdb  MOV  ECX,ESI
0090cbdd  CALL dword ptr [EAX+0x3d8]      ; host visible/active gate
0090cbe3  TEST AL,AL
0090cbe5  JZ   0x0090cdf9
0090cbeb  PUSH EBP
0090cbec  PUSH EDI
0090cbed  MOV  EDI,ESI                    ; seed EDI for prep clear
0090cbef  CALL FUN_0090c700               ; MedalUI_PrepClearButtonSlots_Inferred
0090cbf4  XOR  EBP,EBP                    ; filledSlots = 0
0090cbf6  MOV  [ESP+0x10],EBP
0090cbfa  CALL FUN_0090c810               ; MedalUI_CountDisplayableEntries (EBX=manager)
0090cbff  MOV  ECX,EAX                    ; count
0090cc01  XOR  EDI,EDI
0090cc03  CMP  ECX,EDI
0090cc05  JLE  0x0090cde1                 ; zero-count path

; page math: maxPage = (count - 0x19) / 3 + 1   via magic 0x55555556
0090cc0b  LEA  EDX,[ECX + -0x19]
0090cc0e  MOV  EAX,0x55555556
0090cc13  IMUL EDX
0090cc15  MOV  EAX,EDX
0090cc17  SHR  EAX,0x1F
0090cc1a  CMP  ECX,0x18
0090cc1d  LEA  EAX,[EDX+EAX*1+0x1]
0090cc21  MOV  dword ptr [ESI+0x5A4],EAX  ; host+0x5a4 = maxPage (dword index 0x169)
0090cc27  JG   0x0090cc37                 ; if count > 24 keep maxPage
0090cc29  MOV  dword ptr [ESI+0x5A4],EDI  ; maxPage = 0
0090cc2f  MOV  dword ptr [ESI+0x50C],EDI  ; pageIndex = 0
0090cc35  JMP  0x0090cc45
0090cc37  CMP  dword ptr [ESI+0x50C],EAX
0090cc3d  JLE  0x0090cc45
0090cc3f  MOV  dword ptr [ESI+0x50C],EAX  ; clamp pageIndex <= maxPage

; scrollbar widget @ host+0x5a0
0090cc45  MOV  ECX,dword ptr [ESI+0x5A0]
0090cc4b  CMP  ECX,EDI
0090cc4d  JZ   0x0090cca0
0090cc4f  CMP  dword ptr [ESI+0x5A4],EDI
0090cc55  MOV  EDX,[ECX]
0090cc57  JZ   0x0090cc8b                 ; maxPage==0 → hide
0090cc59  PUSH 0x1
0090cc5b  CALL dword ptr [EDX+0xCC]       ; show
0090cc61  ... CVTSI2SS / DIVSS g_flOne/maxPage ...
0090cc83  CALL dword ptr [EAX+0x460]      ; set scroll range
0090cc8b  PUSH EDI
0090cc8c  CALL dword ptr [EDX+0xCC]       ; hide (maxPage==0)
0090cc9a  CALL dword ptr [EAX+0x34C]      ; refresh widget

; Loop A: vector [manager+0x574, manager+0x578)
0090cca4  MOV  EDI,[ECX+0x574]
0090ccaa  MOV  [ESP+0x18],0xFFFFFFFF      ; walkIndex = -1
;   resolve FUN_0051a0e0(*it); if non-null && walkIndex >= pageIndex*3:
;     PUSH 1; PUSH medal; MOV EBX,filled; CALL FUN_0090c9a0; filled++
;   while filled < 0x18

; Loop B: hash traverse manager+0x540 (lock byte +0x1d)
;   strings: HashError:TraversalLock / TraverseToNext / VOG_DEBUG_STOP
;   resolve FUN_0051a0e0(*(node+8)+0x100); flag=0 apply
; unlock +0x1d = 0; RET

; Zero-count path 0090cde1:
;   host+0x50c = 0; if scrollbar: vtbl[+4](0) hide/detach
; Common epilogue 0090cdf9: POP ESI; POP EBX; ADD ESP,0xC; RET
```

### ABI (sealed)

| Item | Value | Conf |
|---|---|---|
| Host / this | **EAX** on entry (`MOV ESI,EAX`) | **High** |
| Stack formals | **none** | **High** |
| Return | void; bare **`RET`** (`C3`) ×2 exits | **High** |
| Saved regs | EBX/ESI/(EBP/EDI when deep) | **High** |
| Manager global | `DAT_00d1b6d8` → EBX; spilled `[ESP+local]` | **High** |
| Decompiler `in_EAX` | **real** register this (not phantom for ABI) | **High** |
| Host offsets | `+0x50c` pageIndex; `+0x5a0` scrollbar*; `+0x5a4` maxPage | **High** |
| Slot capacity | **0x18** (24) | **High** |
| Row stride | **3** (pageIndex×3 skip; sibling layout `%3`/`/3`) | **High** |

### Callers / xrefs (live)

| Kind | Value |
|---|---|
| Classification | worker |
| Xrefs | **6** (5 `UNCONDITIONAL_CALL` + 1 `JMP` tail) |
| Callers (functions) | `Client_RecvCompleteDynamicObjective` @ `0080ff00` (call `0081015f`); `FUN_0080ce50` @ `0080ce50` (**JMP** `0080ce87`); `FUN_0090d0d0` @ `0090d0d0` (call `0090d364`); `FUN_00946c00` @ `00946c00` (call `009473a5`); sites `0090ce73`, `00952bb1` |
| Static callees | `FUN_0090c700`, `FUN_0090c810`, `FUN_0051a0e0`, `FUN_0090c9a0`, `FUN_007a4480` |

### Call-site ABI seeds (assembly_context)

```text
; Client_RecvCompleteDynamicObjective 0x2070 force-complete tail:
00810153  MOV  EAX,[EDI+0x1034]
00810159  MOV  EAX,[EAX+0x514]     ; nested MedalUI host
0081015f  CALL FUN_0090cbc0

; FUN_0080ce50 tail:
0080ce70  MOV  ESI,[EAX+0x514]
... gate vtbl+0x3d8 ...
0080ce84  MOV  EAX,ESI
0080ce87  JMP  FUN_0090cbc0        ; tail-call, EAX=host

; FUN_0090d0d0 (achievements window; XML peer i_d_a_2d_wnd_bg_achievements.xml):
0090d362  MOV  EAX,EBX
0090d364  CALL FUN_0090cbc0

; Other CALL sites also MOV EAX,host immediately before CALL.
```

### Semantics (sealed structure)

1. Bail if `DAT_00d1b6d8 == 0` or host `vtbl[+0x3d8]() == 0`.
2. **Prep clear** 24 button slots via dualed `MedalUI_PrepClearButtonSlots_Inferred` (`0090c700`).
3. **Count** displayable medals via `FUN_0090c810` (vector span + hash walk; dual sibling `MedalUI_CountDisplayableEntries_Inferred` when sealed).
4. If count ≤ 0: zero pageIndex; hide scrollbar via `vtbl[+4](0)`; return.
5. If count > 0:
   - Compute **maxPage** = `(count - 25) / 3 + 1`; if count ≤ 24 force maxPage=pageIndex=0; else clamp pageIndex.
   - Update **scrollbar** widget (`+0x5a0`): show/hide (`+0xcc`), range `1.0f/maxPage` (`+0x460`), refresh (`+0x34c`).
   - **Fill ≤ 24 slots** starting at global index `pageIndex * 3`:
     - Loop A: manager vector `[+0x574,+0x578)` → resolve `FUN_0051a0e0` → `FUN_0090c9a0(medal, flag=1)` (XML `i_d_a_2d_btn_achievement.xml` in apply dual).
     - Loop B: hash table at manager `+0x540` (lock `+0x1d`) → resolve id at `node→payload+0x100` → `FUN_0090c9a0(medal, flag=0)`.
   - Unlock hash; return.

### Decompile ≡ raw CF

Live `decompile_function` **matches** prior raw body (2026-07-23). Integer compare `count < 0x19` in decompiler ≡ assembly `CMP count,0x18; JG` (≤24). Magic `0x55555556` signed ÷3 confirmed in disasm. **No raw body wipe.**

### Name proposal

| Field | Value |
|---|---|
| Ghidra | `FUN_0090cbc0` |
| Proposed | `MedalUI_RefreshPagedAchievementSlots_Inferred` |
| Retired scaffold | `Named_VOG_DEBUG_STOP_0090cbc0` (string misname; body is not the debug stop) |
| System | `missions-progression` |
| Partition hint | Post-force-complete medal UI refresh (after S2C `0x2070`) |

### Gaps (open)

- Product English for MedalUI host / manager class / `DAT_00d1b6d8`.
- Product English for vtbl `+0x3d8` / scrollbar `+0xcc` / `+0x460` / `+0x34c` / `+4`.
- Full dual of residual callers `FUN_00946c00` / `0090ce73` owner / `00952bb1` owner (not OWN).
- Runtime / bit-exact / differential.
