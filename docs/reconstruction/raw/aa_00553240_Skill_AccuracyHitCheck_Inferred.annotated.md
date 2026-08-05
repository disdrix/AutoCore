# Annotated low-level: Skill_AccuracyHitCheck_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_00553240` |
| VA | `0x00553240`–`0x005532ce` |
| System | `skills-abilities` |
| Date | 2026-07-29 |
| Canonical | `Skill_AccuracyHitCheck_Inferred` |

## Machine-level notes

- Source: live Ghidra decompile + assembly context at call sites `00553982` / `0058c9ac`.
- **`__thiscall`**: ECX = **skill**; not caster. Scaffold that treated this as Recv callee naming is obsolete.
- `DAT_00aaa668` = **-1.0f** (`00 00 80 bf`) — accuracy disabled / auto-hit.
- `DAT_00a0f718` = **0.01f** (`0a d7 23 3c`) — scale `roll%100` → fraction.
- Stack buffer ~`0x400` bytes: debug reason string for `FUN_004ceba0` (unused after return by this unit).
- `local_9` written 0, never read (dead).
- FP status merge into `uVar2` before the real branch is decompiler noise; decision is `f != -1` then score compare.
- `roll / 100` does **not** affect hit/miss; only `roll % 100`.

## Pseudocode (annotated)

```c
// __thiscall  ECX = skill
uint Skill_AccuracyHitCheck_Inferred(
    int skill,                 // this
    undefined4 attacker,       // entity*
    undefined4 target,         // entity*
    ushort roll,
    undefined1 *outMissFlagOptional)
{
  float acc = *(float *)(skill + 0x24);
  char debugBuf[0x400];
  // zero debugBuf (0xff dwords + trailing u16) — reason string out for score helper
  memset-like clear;

  if (acc != -1.0f /* DAT_00aaa668 */) {
    // this=skill still; score via attacker/target + skill accuracy float
    float10 score = (float10)FUN_005531d0(attacker, target, &debugBuf);
    // unused for decision: roll / 100
    if (score <= (float10)((uint)roll % 100) * (float10)0.01f /* DAT_00a0f718 */) {
      if (outMissFlagOptional != NULL)
        *outMissFlagOptional = 1;   // miss flag
      return 0;                     // MISS
    }
  }
  return 1;                         // HIT (incl. auto-hit sentinel)
}
```

## Call-site ABI (assembly)

**ApplyEffects `0x00553982`:** `MOV ECX,ESI` (skill); push out=0, roll, target, caster.

**FUN_0058c850 `0x0058c9ac`:** `MOV ECX,EDI` (skill); push &local_c5, roll, target, attacker.

## Open questions

- Product C++ name.
- Full score composition in `FUN_005531d0` / `FUN_004ceba0` (out of unit).
- Typical roll domain from `FUN_0058ab60` table (modulo still seals threshold band 0–99).
