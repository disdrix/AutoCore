# Annotated low-level: FUN_004ba0a0 / NDSpecialFX_StopFinalize_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_004ba0a0` |
| VA | `0x004ba0a0`–`0x004ba26d` (461 B / `0x1CD`) |
| System | client-fx / NDSpecialFX lifecycle |
| Date | 2026-07-29 W27-D |
| Preferred name | `NDSpecialFX_StopFinalize_Inferred` |
| Ghidra name | `FUN_004ba0a0` |

## Machine-level notes

- ECX = fx host; `SUB ESP,8`; plain `RET` (`C3`); AL = finalize polarity.
- Re-entry: host`+8` sticky (set 1 mid-body).
- Type at host`+0x28`; case 4 gated by dualed `FUN_004b6a80`.
- List family `+0x1E0/+0x1EC/+0x204/+0x210/+0x21C` shared with HostTick / DeactivateClear / LivenessDone.
- Not DeactivateClear: no staged multi-hit flush / destroy-pending `+0x90e|1` walk.
- Reject keyword name `Mission_Uses_Client_GetMissionCompleteAudioTable_*`.
- Live decompile 2026-07-29 ≡ raw scaffold 2026-07-23 for outer CF.

## Pseudocode (live decompile)

```c
char __fastcall FUN_004ba0a0(int param_1)
{
  int iVar1;
  char cVar2;
  char cVar3;
  uint32_t uVar4;
  int *piVar5;
  int iVar6;
  uint32_t uVar7;
  uint32_t uVar8;
  uint32_t uVar9;
  char local_8;
  uint local_4;

  local_8 = '\x01';
  cVar2 = '\x01';
  if (*(char *)(param_1 + 8) != '\0') {
    return '\x01';
  }
  piVar5 = *(int **)(param_1 + 0x10);
  if (piVar5 != (int *)0x0) {
    switch(*(uint32_t *)(param_1 + 0x28)) {
    case 4:
      cVar3 = FUN_004b6a80();
      if (cVar3 != '\0') break;
    case 5:
    case 6:
    case 0xc:
    case 0xd:
    case 0xe:
    case 0x14:
    case 0x15:
      if (*(char *)(param_1 + 0xb) != '\0') {
        cVar2 = '\0';
        uVar4 = (**(code **)(*piVar5 + 0x1cc))();
        FUN_004b9af0(uVar4);
        FUN_004b9270(param_1);
        local_8 = '\0';
      }
    }
  }
  *(uint8_t *)(param_1 + 8) = 1;
  /* lists +0x1e0 / +0x1ec / +0x204 / +0x210 / +0x21c — see re-verify CF */
  *(uint32_t *)(param_1 + 0x10) = 0;
  return local_8;
}
```

Full body preserved in raw capture and `FUN_004ba0a0.cpp` / named twin.

## Offset map (fx host)

| Offset | Role |
|---|---|
| `+8` | Finalize sticky |
| `+0xB` | Gate type-case early clear |
| `+0x10` | Linked object; cleared at end |
| `+0x28` | FX type dword |
| `+0x2C` | Arg to `FUN_00593e10` |
| `+0x1E0` | List |
| `+0x1EC` | List (sound-active `+0x10B`) |
| `+0x204` | List → `FUN_00593e10` |
| `+0x210` | List (`+0x178\|0x100` when keep) |
| `+0x21C` | List (`00498a90` / `00498ab0`) |

## Open questions

- Product / PDB method name.
- Type-code English; host`+0xB` product meaning.
- Nested helpers `004b9af0` / `004b9270` / `005b8340` / `00593e10` not OWN.
