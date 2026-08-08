# Annotated low-level: Skill_StoreEffectPresenceFlags_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_0054fec0` |
| VA | `0x0054fec0`–`0x0054fef8` |
| Ghidra | `FUN_0054fec0` |
| Named | `Skill_StoreEffectPresenceFlags_Inferred` |
| System | skills-abilities |
| Date | 2026-08-04 (WQ9E-B dual) |

## Machine-level notes

- Source: raw `aa_0054fec0` + live re-verify 2026-08-04.
- **No** `disassemble_bytes`; body sealed via `read_memory` entry hex + control-flow.
- Prefer assembly when decompiler conflicts (none observed for CF).
- Twin: post-Evaluate store inside `Skill_ReevaluateForCurrentRank` is CF-identical (duplicated, not a call).

## ABI

| Item | Value | Evidence |
|---|---|---|
| Convention | `__fastcall` / `__thiscall` | `mov esi,ecx` prologue |
| ECX | skill runtime* | callee `00627be0` sealed skill this; fields `+0x620/+0x624` match Reevaluate |
| Return | void | plain `ret`; no EAX consumer |
| Stack formals | none | |

## Control flow (annotated)

```c
// ECX = pSkill
void __fastcall Skill_StoreEffectPresenceFlags_Inferred(void *pSkill)
{
  // uMask = Skill_ComputeEffectPresenceFlags_Inferred(pSkill)  // ECX preserved via ESI
  uint32_t uMask = Skill_ComputeEffectPresenceFlags_Inferred(pSkill);

  // skill+0x620: pre-existing targeting / capability dword (0 = plain store)
  if (*(uint32_t *)((uint8_t *)pSkill + 0x620) == 0) {
    // skill+0x624 ← pure presence|base mask
    *(uint32_t *)((uint8_t *)pSkill + 0x624) = uMask;
  } else {
    // OR bit 2 (value 4) into stored targeting flags
    *(uint32_t *)((uint8_t *)pSkill + 0x624) = uMask | 4u;
    // skill+0x148: char gate — when zero, raise bit 20 (0x100000) on +0x620
    if (*(uint8_t *)((uint8_t *)pSkill + 0x148) == 0) {
      *(uint32_t *)((uint8_t *)pSkill + 0x620) |= 0x100000u;
    }
  }
}
```

## Bytes ↔ decompile

| Step | Bytes | Decompile |
|---|---|---|
| save this | `push esi; mov esi,ecx` | param_1 retained |
| presence | `call 0x00627be0` | `FUN_00627be0()` |
| test 620 | `mov ecx,[esi+0x620]; test ecx,ecx; jz store_plain` | `if (+0x620==0)` |
| or 4 | `or al,4` | `uVar1 \| 4` (bit 2 only) |
| store 624 | `mov [esi+0x624],eax` | write targeting flags |
| gate 148 | `cmp byte [esi+0x148],0; jnz done` | `if (+0x148==0)` |
| or 100000 | `or ecx,0x100000; mov [esi+0x620],ecx` | `+0x620 \|= 0x100000` |

## Call graph

| Direction | Symbol | VA | Notes |
|---|---|---|---|
| Callee | `Skill_ComputeEffectPresenceFlags_Inferred` | `0x00627be0` | dual sealed WQ9D-E |
| Static callers | *(none)* | — | no xrefs; Reevaluate inlines same store |
| Logical twin | `Skill_ReevaluateForCurrentRank` store tail | `0x00553390` | after Evaluate |

## Open questions

1. Product English for bit `4` on `+0x624` and bit `0x100000` on `+0x620`.
2. Why a standalone helper has zero static callers (dead extract vs dynamic only).
3. Meaning of char gate `skill+0x148`.
