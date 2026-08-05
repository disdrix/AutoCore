# Annotated low-level: Mission_EnsureRegionMissions (`FUN_0053fff0`)

| Field | Value |
|---|---|
| Stable ID | `aa_0053fff0` |
| VA | `0x0053fff0` |
| System | `missions-progression` |
| Date | 2026-07-29 (wave3 seal) |
| Dual | A/B accept — see `reviews/A_aa_0053fff0_*` / `B_aa_0053fff0_*` |

---

## Machine-level notes

- Source: raw capture for `aa_0053fff0` + live re-decompile 2026-07-29.
- Prefer assembly when decompiler conflicts (bytes confirm `+0xf18`, `new(0x10)`, ctor call).
- **Return is wrapper\***, not CNDHash\*. Callers must `*wrapper` for primary mission-id table.
- Ctor `FUN_0060b870` = `VOGRegionMissions.cpp` / class **CVOGRegionMissions**.

## Pseudocode (annotated)

```c
// __fastcall ECX = owner
// Returns CVOGRegionMissions* at owner+0xf18 (lazy).
undefined4 __fastcall Mission_EnsureRegionMissions(int owner /* ECX */)
{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a3f90;
  local_c = ExceptionList;
  // SEAL: lazy slot owner+0xf18
  if (*(int *)(owner + 0xf18) == 0) {
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x10);           // SEAL: wrapper size 0x10
    local_4 = 0;
    if (pvVar1 == (void *)0x0) {
      uVar2 = 0;                           // OOM → null
    }
    else {
      // ECX = pvVar1 (bytes: mov ecx,eax)
      uVar2 = FUN_0060b870();              // Mission_VOGRegionMissions ctor
    }
    *(undefined4 *)(owner + 0xf18) = uVar2;
  }
  ExceptionList = local_c;
  return *(undefined4 *)(owner + 0xf18);   // wrapper*, not *wrapper
}
```

## Wrapper layout (sealed via ctor `0x0060b870`)

| Off | Contents |
|---|---|
| `+0x0` | Primary mission-id CNDHash\* (`FUN_0053b0b0(8)`) — **`*wrapper`** |
| `+0x4` | Objective-side CNDHash\* (`FUN_0053b1b0(8)`) |
| `+0x8` | Extended hash 0x38 (`PTR_FUN_009df688`) |
| `+0xC` | Extended hash 0x38 |

## Open questions

- Product method English on owner class.
- Owner type of `DAT_00b041fc`.
- `FUN_0060c010` this-slot and keys `def+0x88` / `def+0x86`.
