# Annotated low-level: AI_CheckSlotTimerReady

| Field | Value |
|---|---|
| Stable ID | `aa_005cced0` |
| VA | `0x005cced0` |
| System | `npc-ai` / HBAI |
| Date | 2026-07-29 (dual A/B strengthen; original capture 2026-07-23) |

## Machine-level notes

- Source: raw capture for `aa_005cced0` + live re-decompile / `read_memory` 2026-07-29.
- Prefer body bytes when decompiler invents formals.
- **`RET 4`**: one stack arg = slot index; `this` in ECX.
- Decomp name `pAiCtx` is a misnomer — always an integer index (`* 0xC`).
- Third formal `nSlotIndex` in raw decomp is **unused** (no load).
- Ready flag algebra: `(i*3 + 0x1e)*4` = `i*0xC + 0x78` (third dword of same slot record).
- Compare: `JBE` → ready only when `elapsed > period` (strict).
- Leaf; ticks from `g_dwClientTickMs` (`0x00b041cc`).
- Callers use AL only (`TEST AL` / byte store).

## Sealed signature

```c
uint8_t /* bool AL */ __thiscall AI_CheckSlotTimerReady(void *this, uint nSlotIndex);
```

## Slot record (`this+0x70`, stride `0x0C`)

| Rel | Abs form | Role |
|---|---|---|
| `+0x00` | `this + i*0xC + 0x70` | last stamp ms |
| `+0x04` | `this + i*0xC + 0x74` | period ms |
| `+0x08` | `this + i*0xC + 0x78` | ready flag (set 1 on pass) |

## Pseudocode (annotated; arity corrected)

```c
// Raw decomp preserved CF; signature corrected from RET 4 + call sites.
uint8_t __thiscall AI_CheckSlotTimerReady(void *this, uint nSlotIndex)
{
  uint elapsed = g_dwClientTickMs - *(int *)((int)this + nSlotIndex * 0xc + 0x70);
  uint period  = *(uint *)((int)this + nSlotIndex * 0xc + 0x74);

  if (period < elapsed) {  // elapsed > period
    // decomp: iVar1 = nSlotIndex*3+0x1e; *(u8*)(this + iVar1*4) = 1
    *(uint8_t *)((int)this + nSlotIndex * 0xc + 0x78) = 1;
    return 1;
  }
  return 0;
}
```

## Raw decomp (historical, 3-arg form)

```c
uint __thiscall AI_CheckSlotTimerReady(void *this,void *pAiCtx,uint nSlotIndex)

{
  int iVar1;
  
  if (*(uint *)((int)this + (int)pAiCtx * 0xc + 0x74) <
      g_dwClientTickMs - *(int *)((int)this + (int)pAiCtx * 0xc + 0x70)) {
    iVar1 = (int)pAiCtx * 3 + 0x1e;
    *(undefined1 *)((int)this + iVar1 * 4) = 1;
    return CONCAT31((int3)((uint)iVar1 >> 8),1);
  }
  return (uint)pAiCtx & 0xffffff00;
}
```

## Callers (summary)

| Function | Slot |
|---|---|
| `CVOGHBAICreatureBase_OnHeartBeat` | EDI |
| `CVOGHBAIDriver_DoLogic` (×2) | 0 |
| `NPC_TryCastSkillFromSet` | 2 |
| `FUN_005d7f70` (×2) | EBX |

## Open questions

- Owning C++ type of `this` (HBAI subclass).
- Writers of last stamp / period / ready clear.
- Full slot index taxonomy beyond observed 0 and 2.
