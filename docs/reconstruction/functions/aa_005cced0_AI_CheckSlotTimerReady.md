# Function record: AI_CheckSlotTimerReady

| Field | Value |
|---|---|
| **Stable ID** | `aa_005cced0` |
| **Canonical name** | `AI_CheckSlotTimerReady` |
| **Address** | `0x005cced0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Body** | `0x005cced0`–`0x005ccefc` |
| **System** | `npc-ai` / HBAI slot cooldown gate |
| **Completion status** | **Dual sealed accept-with-gaps** (2026-07-29) — CF/signature/layout High; slot taxonomy open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual reviews** | `reviews/A_aa_005cced0_AI_CheckSlotTimerReady.md`, `reviews/B_aa_005cced0_AI_CheckSlotTimerReady.md` |

## Purpose

Gate an HBAI per-slot cooldown: if client tick elapsed since last stamp exceeds the slot period, latch ready-flag=`1` and return true (AL); else return false. Does not restamp last-fire or reseed period.

## Signature (sealed)

```c
uint8_t /* bool AL */ __thiscall AI_CheckSlotTimerReady(void *this, uint nSlotIndex);
// RET 4 — one stack dword; ECX = HBAI owner
```

Prior decompiler form `uint __thiscall (void *this, void *pAiCtx, uint nSlotIndex)` is **wrong**: second formal is the only stack index; third is unused artifact.

## Control flow

```
elapsed = g_dwClientTickMs - *(int*)(this + nSlotIndex*0xC + 0x70)
period  = *(uint*)(this + nSlotIndex*0xC + 0x74)
if (period < elapsed) {                      // strict: elapsed > period
  *(uint8_t*)(this + nSlotIndex*0xC + 0x78) = 1;
  return 1;
}
return 0;
```

## Slot table (`this+0x70`, stride `0x0C`)

| Rel | Abs | Role | Conf |
|---|---|---|---|
| `+0x00` | `+0x70 + i*0xC` | last stamp (ms) | **High** |
| `+0x04` | `+0x74 + i*0xC` | period (ms) | **High** |
| `+0x08` | `+0x78 + i*0xC` | ready flag (set 1 on success only) | **High** |

Decomp write `*(this + (i*3 + 0x1e)*4) = 1` ≡ `this + i*0xC + 0x78`.

## Globals

| Symbol | VA | Role |
|---|---|---|
| `g_dwClientTickMs` | `0x00b041cc` | Client millisecond tick |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005cced0_AI_CheckSlotTimerReady.md`
- Annotated: `docs/reconstruction/raw/aa_005cced0_AI_CheckSlotTimerReady.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/AI_CheckSlotTimerReady.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_005cced0_AI_CheckSlotTimerReady.md`
- Dual B: `docs/reconstruction/reviews/B_aa_005cced0_AI_CheckSlotTimerReady.md`
- Scratch: `tmp/a_005cced0.md`

## Callers / callees

**Callees:** none (leaf).

**Callers (6 xrefs):**

| Site | Function | Slot arg |
|---|---|---|
| `0x005d079d` | `CVOGHBAICreatureBase_OnHeartBeat` | EDI |
| `0x005d7845` | `CVOGHBAIDriver_DoLogic` | imm **0** |
| `0x005d7ac1` | `CVOGHBAIDriver_DoLogic` | imm **0** |
| `0x005d13ee` | `NPC_TryCastSkillFromSet` | imm **2** |
| `0x005d7ffe` | `FUN_005d7f70` | EBX |
| `0x005d8264` | `FUN_005d7f70` | EBX |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler ≡ body bytes | **High** |
| `thiscall` + single stack index + RET 4 | **High** |
| Slot layout +0x70/+0x74/+0x78 stride 0xC | **High** |
| Compare polarity (`elapsed > period`) | **High** |
| AL-only bool contract at call sites | **High** |
| Parameter / slot semantic names (weapon vs skill) | **Medium** (0/2 observed; taxonomy open) |
| Owning C++ type name | **Tentative** (HBAI family) |
| Stamp/period writers | **Open** (out of unit) |
