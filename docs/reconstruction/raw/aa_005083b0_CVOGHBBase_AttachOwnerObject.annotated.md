# Annotated low-level: CVOGHBBase_AttachOwnerObject

| Field | Value |
|---|---|
| Stable ID | `aa_005083b0` |
| VA | `0x005083b0` |
| System | heartbeat / timed-action infrastructure |
| Date | 2026-07-23; machine seal 2026-07-29 |

## Machine-level notes

- Source: raw capture for `aa_005083b0` + `read_memory` body seal.
- Prefer assembly when decompiler conflicts — **callee this is listMgr, not HB**.
- `owner+0xB0` loads a pointer used as ECX for list insert/remove helpers.
- Convention: `__thiscall`, 1 stack arg, `ret 4`.

## Pseudocode (decompiler — CF only)

```c
void __thiscall CVOGHBBase_AttachOwnerObject(void *this, void *pOwnerObject)
{
  if ((*(int *)((int)this + 0x18) != 0) &&
      (*(int *)(*(int *)((int)this + 0x18) + 0xb0) != 0)) {
    FUN_005085b0(this);   // DECOMPILER LIE: actual this = *(oldOwner+0xB0)
  }
  *(void **)((int)this + 0x18) = pOwnerObject;
  if ((pOwnerObject != (void *)0x0) &&
      (*(int *)((int)pOwnerObject + 0xb0) != 0)) {
    FUN_00508490(this);   // DECOMPILER LIE: actual this = *(newOwner+0xB0)
  }
  return;
}
```

## Machine-corrected CF

```
old = *(HB+0x18)
if old && *(old+0xB0):  FUN_005085b0(ECX=*(old+0xB0), arg=HB)
*(HB+0x18) = pOwnerObject          // always
if pOwner && *(pOwner+0xB0): FUN_00508490(ECX=*(pOwner+0xB0), arg=HB)
ret 4
```

## Body bytes (60)

`56 8b f1 8b 46 18 85 c0 74 12 8b 80 b0 00 00 00 85 c0 74 08 56 8b c8 e8 e4 01 00 00 8b 44 24 08 85 c0 89 46 18 74 12 8b 80 b0 00 00 00 85 c0 74 08 56 8b c8 e8 a7 00 00 00 5e c2 04 00`

## Open questions

- Canonical names for list insert/remove helpers.
- Which owner types install list manager at +0xB0.
- Owner polymorphic type (not only SimpleObject).

## Human refine

- 2026-07-23 priority_014: pOwner +0x18, +0xB0 gate, detach/attach helpers
- 2026-07-29 dual A/B: machine seal; callee this = listMgr; clean corrected
