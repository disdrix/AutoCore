# Annotated low-level: FUN_0052ada0

| Field | Value |
|---|---|
| Stable ID | `aa_0052ada0` |
| VA | `0x0052ada0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0052ada0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 __fastcall FUN_0052ada0(int param_1)

{
  int local_4;
  
  local_4 = param_1;
  FUN_00418b80(&local_4,&stack0x00000004);
  if (local_4 == *(int *)(param_1 + 0x588)) {
    return 0xffffffff;
  }
  return *(undefined4 *)(local_4 + 0x10);
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.

---

## Dual residual notes (2026-07-29)

**Sealed (A/B `A_aa_0052ada0_*` / `B_aa_0052ada0_*`):**

- ABI: `__thiscall(Character*, typeId) → int`, epilogue **`RET 4`**
- Ordered map @ char **`+0x584`**, end sentinel **`+0x588`**, balance **`node+0x10`**
- Missing key → **`-1`** (`OR EAX,0xFFFFFFFF`)
- Callee `FUN_00418b80` = ordered-map find (not CNDHash)
- Mission path: Requirements Discipline gate `PUSH [def+0x104]; MOV ECX,char; CALL` @ `0x00546373`
- Live decompile ≡ raw; product English still open
- Many non-mission xrefs (item costs / tooltips) — shared resource map
