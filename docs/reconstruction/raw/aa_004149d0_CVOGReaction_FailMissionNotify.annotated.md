# Annotated low-level: CVOGReaction_FailMissionNotify → Vector_PushDword

| Field | Value |
|---|---|
| Stable ID | `aa_004149d0` |
| VA | `0x004149d0` |
| System | container util (cross-cutting) |
| Date | 2026-07-23; residual annotate 2026-07-29 |

## Machine-level notes

- Source: raw capture for `aa_004149d0` + live re-decompile + `read_memory` 2026-07-29.
- **Sealed role:** pure `Vector_PushDword` — historical FailMissionNotify name is call-graph residue.
- Prefer image when naming conflicts with mission semantics.
- Grow path only: `FUN_0040dbf0` → `FUN_004073a0` (`operator_new` dword buffer, ~1.5× capacity).
- Convention: `__thiscall` ECX=vec, stack `uint32_t*`, `RET 4`.
- Triad: `begin=this+4`, `end=this+8`, `cap=this+0xc` (element stride 4).
- Multi-caller: 40 functions / 51 sites — freelist, journal temps, medals, end-quest ids, etc.

## Image spine (authoritative)

```
PUSH ESI
MOV  ESI, [ECX+4]                 ; begin
TEST ESI,ESI / size=(end-begin)>>2 or 0
if begin==0 || size >= capacity:  CALL FUN_0040dbf0; RET 4
*end = *arg0; end += 4; RET 4
```

## Pseudocode (annotated copy of raw)

```c
/* Vector_PushDword — historical name CVOGReaction_FailMissionNotify */
void __thiscall CVOGReaction_FailMissionNotify(int param_1,undefined4 *param_2)
{
  int iVar1;
  undefined4 *puVar2;

  iVar1 = *(int *)(param_1 + 4);                    /* begin */
  if ((iVar1 != 0) &&
     ((uint)(*(int *)(param_1 + 8) - iVar1 >> 2) <  /* size */
      (uint)(*(int *)(param_1 + 0xc) - iVar1 >> 2))) { /* capacity */
    puVar2 = *(undefined4 **)(param_1 + 8);         /* end */
    *puVar2 = *param_2;                             /* append dword */
    *(undefined4 **)(param_1 + 8) = puVar2 + 1;     /* end++ */
    return;
  }
  FUN_0040dbf0(&param_2,*(undefined4 *)(param_1 + 8),param_2); /* grow */
  return;
}
```

## Open questions

- Optional registry/Ghidra rename primary → `Vector_PushDword`.
- Full dual of grow callees; exhaustive 51-site element taxonomy.
