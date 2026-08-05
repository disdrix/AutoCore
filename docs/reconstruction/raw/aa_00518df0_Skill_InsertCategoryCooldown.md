# Raw capture: Skill_InsertCategoryCooldown

| Field | Value |
|---|---|
| **Stable ID** | `aa_00518df0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00518df0` |
| **Canonical name** | `Skill_InsertCategoryCooldown` |
| **System** | skills-abilities |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Skill_InsertCategoryCooldown(categoryId, durationMs)
   
   Inserts/updates category cooldown map: start=DAT_00b041cc, duration=param.
   Used for item skills and explicit category recharge; cast-again ctor also inserts. */

void Skill_InsertCategoryCooldown(int nCategoryId,int nDurationMs)

{
  void *in_ECX;
  undefined1 *puVar1;
  int *piVar2;
  undefined1 local_14 [8];
  int nKey;
  uint nStartTick;
  int nDuration;
  
  if (nCategoryId != -1) {
    nStartTick = g_dwClientTickMs;
    piVar2 = &nKey;
    nDuration = nDurationMs;
    puVar1 = local_14;
    nKey = nCategoryId;
    Skill_GetCategoryCooldownMap(in_ECX);
    Skill_CategoryCooldownMap_Insert(puVar1,piVar2);
  }
  return;
}
```

---

## Append — re-verify 2026-07-29 (Ghidra decompile + read_memory)

**Sources:** `decompile_function` / `analyze_function_complete` @ `0x00518df0`; `read_memory` body `0x00518df0` len 80; global `0x00b041cc`; xrefs/callers.

### Live decompile (≡ 2026-07-23 body)

```c
void Skill_InsertCategoryCooldown(int nCategoryId,int nDurationMs)
{
  void *in_ECX;
  undefined1 *puVar1;
  int *piVar2;
  undefined1 local_14 [8];
  int nKey;
  uint nStartTick;
  int nDuration;
  
  if (nCategoryId != -1) {
    nStartTick = g_dwClientTickMs;
    piVar2 = &nKey;
    nDuration = nDurationMs;
    puVar1 = local_14;
    nKey = nCategoryId;
    Skill_GetCategoryCooldownMap(in_ECX);
    Skill_CategoryCooldownMap_Insert(puVar1,piVar2);
  }
  return;
}
```

### Signature (Ghidra)

`void __stdcall Skill_InsertCategoryCooldown(int nCategoryId, int nDurationMs)`  
Params: `Stack[0x4]:4`, `Stack[0x8]:4`. Phantom `in_ECX` (map owner for GetMap).

### Bytes (prologue / arm / epilogue)

```
00518df0  83 EC 14              sub  esp, 0x14
00518df3  56                    push esi
00518df4  8B 74 24 1C           mov  esi, [esp+0x1C]     ; nCategoryId
00518df8  83 FE FF              cmp  esi, -1
00518dfb  74 2B                 je   epilogue            ; skip arm
00518dfd  A1 CC 41 B0 00        mov  eax, [0x00B041CC]   ; g_dwClientTickMs
00518e02  8B 54 24 20           mov  edx, [esp+0x20]     ; nDurationMs
00518e06  89 44 24 10           mov  [esp+0x10], eax     ; entry.start
00518e0a  8D 44 24 0C           lea  eax, [esp+0x0C]     ; &entry
00518e0e  89 54 24 14           mov  [esp+0x14], edx     ; entry.duration
00518e12  50                    push eax                 ; Map_Insert arg: pValue
00518e13  8D 54 24 08           lea  edx, [esp+0x08]     ; &outPair (post-push)
00518e17  52                    push edx                 ; Map_Insert arg: pOutPair
00518e18  89 74 24 14           mov  [esp+0x14], esi     ; entry.key = categoryId
00518e1c  E8 4F FF FF FF        call Skill_GetCategoryCooldownMap  ; 0x00518d70; ECX=owner
00518e21  8B C8                 mov  ecx, eax            ; this = map*
00518e23  E8 C8 44 00 00        call Skill_CategoryCooldownMap_Insert ; 0x0051d2f0; RET 8
00518e28  5E                    pop  esi
00518e29  83 C4 14              add  esp, 0x14
00518e2c  C2 08 00              ret  8                   ; stdcall, 2 dwords
```

### Global

| VA | Symbol | Type | Plate (abbrev) |
|---|---|---|---|
| `0x00b041cc` | `g_dwClientTickMs` | `uint` | Client ms tick (`CVOGHBList_Tick` / GetTickCount or forced delta) |

Static `read_memory` @ `0x00b041cc` → zeros (image not live).

### Xrefs

| From | Function | Kind |
|---|---|---|
| `0x0051ac77` | `Skill_ApplyStatusEffectLocal` | UNCONDITIONAL_CALL |

### Callees

| VA | Name |
|---|---|
| `0x00518d70` | `Skill_GetCategoryCooldownMap` |
| `0x0051d2f0` | `Skill_CategoryCooldownMap_Insert` |
