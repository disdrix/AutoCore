# Annotated low-level: CVOGCharacter_SetQuickBarSkill

| Field | Value |
|---|---|
| Stable ID | `aa_005208c0` |
| VA | `0x005208c0` |
| Body | `0x005208c0` – `0x005208df` |
| System | skills-abilities |
| Date | 2026-07-29 (dual residual strengthen; prior raw plate 2026-07-23) |

## Machine-level notes

- Source: raw capture for `aa_005208c0` + live Ghidra `decompile_function` + `read_memory` (2026-07-29).
- Prefer assembly bytes when decompiler conflicts (here: no conflict).
- **Sealed bytes:** `cmp al,0x64` / `jae`; store `[ecx+eax*4+0x74c]`; `or [ecx+0x634],2`; `ret 8`.
- No callees. Sibling item setter `0x00520890` shares dirty bit 2 only.
- Empty skill id is **not** validated here (callers pass `0` or `-1`).

## Pseudocode (annotated copy of raw ≡ live)

```c
/* CVOGCharacter_SetQuickBarSkill
   
   Writes one quick-bar skill id into the local player character.
     this+0x74c + slot*4 = int32 skillId  (0 or -1 = empty depending on path)
     this+0x634 |= 2       dirty bit for quick-bar state
   
   slot must be < 100; otherwise no-op.
   CreateCharacterExtended skill array is at absolute packet offset 0x730 (100 x int32).
   Empty check for auto-map uses skillId == -1 AND item COID both half-words == 0xFFFFFFFF.
   
   __thiscall: RET 0x8 (slot + skillId).
   Verified: AutoCore QuickBarUpdate session RE (2026-07); dual residual byte seal 2026-07-29. */

void __thiscall CVOGCharacter_SetQuickBarSkill(void *this,byte slot,int skillId)

{
  if (slot < 100) {
                    /* char+0x74c + slot*4 = skillId int32 */
    *(int *)((int)this + (uint)slot * 4 + 0x74c) = skillId;
    *(uint *)((int)this + 0x634) = *(uint *)((int)this + 0x634) | 2;
  }
  return;
}
```

## Byte decode (`read_memory` @ entry)

```
8a 44 24 04  3c 64  73 15  8b 54 24 08  0f b6 c0
89 94 81 4c 07 00 00  83 89 34 06 00 00 02  c2 08 00
```

## Open questions

- Readers of dirty bit 2 at `+0x634`.
- Live empty-id after clear vs login restore.
