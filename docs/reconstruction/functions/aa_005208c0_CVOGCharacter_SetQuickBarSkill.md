# Function record: CVOGCharacter_SetQuickBarSkill

| Field | Value |
|---|---|
| **Stable ID** | `aa_005208c0` |
| **Canonical name** | `CVOGCharacter_SetQuickBarSkill` |
| **Address** | `0x005208c0` |
| **Body range** | `0x005208c0` – `0x005208df` (~32 bytes) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities |
| **Calling convention** | MSVC `__thiscall` — `ECX` = `CVOGCharacter*`; stack `byte slot`, `int skillId`; **`ret 8`** |
| **Completion status** | **Human-refined trivial kernel** — CF + layout + convention sealed by dual residual (2026-07-29); empty-sentinel / dirty readers open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A** | `reviews/A_aa_005208c0_CVOGCharacter_SetQuickBarSkill.md` |
| **Dual B** | `reviews/B_aa_005208c0_CVOGCharacter_SetQuickBarSkill.md` |

## Purpose

Bind one quick-bar **skill id** on a character and mark quick-bar state dirty:

1. If `slot >= 100` (unsigned byte): **no-op** (no store, no dirty).
2. Else store `skillId` at **`char + 0x74c + slot * 4`** (int32 array, 100 slots → span `0x74c`..`0x8db`).
3. **`char + 0x634 |= 2`** (shared QB dirty with item setter).

Does **not** send packets, clear item COIDs, or enforce empty-id policy.

## Signature

```c
void __thiscall CVOGCharacter_SetQuickBarSkill(
    void* /*CVOGCharacter**/ this,
    unsigned char slot,
    int skillId);
/* ret 8 */
```

## Behavioral summary

| Branch | Condition | Effect |
|---|---|---|
| No-op | `slot >= 100` | return — flags unchanged |
| Store | `slot < 100` | `qbSkills[slot] = skillId`; `flags \|= 2` |

## Layout

| Offset | Type | Role |
|---:|---|---|
| `+0x74c` | `int32[100]` | Quick-bar skill ids (absolute create-packet skill restore @ `0x730`) |
| `+0x634` | `uint32` flags | Bit **`2`** = quick-bar dirty (shared with `SetQuickBarItem`) |
| `+0x930` | `int64[100]` | Item COIDs — **not written here** (sibling `aa_00520890`) |

## Machine seal (`read_memory` 2026-07-29)

```
005208c0  8a442404           mov  al, [esp+4]              ; slot
005208c4  3c64               cmp  al, 0x64
005208c6  7315               jae  005208dd                 ; skip store+dirty
005208c8  8b542408           mov  edx, [esp+8]             ; skillId
005208cc  0fb6c0             movzx eax, al
005208cf  8994814c070000     mov  [ecx+eax*4+0x74c], edx
005208d6  83893406000002     or   dword ptr [ecx+0x634], 2
005208dd  c20800             ret  8
```

Hex (entry, 32 B body):  
`8a4424043c6473158b5424080fb6c08994814c07000083893406000002c20800`

## Callers (Ghidra, 2026-07-29)

| Caller | Address | Call site | Role |
|---|---:|---:|---|
| `Client_RecvCreateCharacter` | `0x008146b0` | `0x00814916` | Login restore skills from CreateCharacterExtended |
| `Client_SkillTrainUiRequest_INFERRED` | `0x00897170` | `0x00897256` | First-rank auto-map to empty QB skill slot |
| `QuickBar_ClearActiveSlot_INFERRED` | `0x008274c0` | `0x00827535` | Clear active slot skill with **`skillId = -1`** |
| `FUN_00826860` | `0x00826860` | `0x00826914` | QB UI family |
| `FUN_00827670` | `0x00827670` | `0x0082771b` | QB UI family |
| `FUN_008283a0` | `0x008283a0` | `0x00828463` | QB UI family (clear/assign sequences) |
| `FUN_008285a0` | `0x008285a0` | `0x0082866a` | QB UI family |
| (unnamed boundary) | — | `0x008290d1` | Extra xref; function envelope not registered |

## Callees

**None.**

## Related sibling

| Unit | VA | Difference |
|---|---:|---|
| `CVOGCharacter_SetQuickBarItem` | `0x00520890` | int64 COID at `+0x930` stride 8; **`ret 0xC`**; same dirty `\|2` |

## Empty-sentinel note (not body-enforced)

| Producer | Typical empty skillId |
|---|---|
| `QuickBar_ClearActiveSlot_INFERRED` | **`-1`** |
| Server / AutoCore persist defaults | **`0`** (`Character.QuickBarSkills`) |
| CreateCharacterExtended restore | whatever server wrote (often 0 for empty) |

Empty auto-map checks elsewhere: skill `== -1` **and** item COID halves `0xFFFFFFFF` (see UI/train paths) — **outside this unit**.

## Confidence by dimension

| Dimension | Level | Rationale |
|---|---|---|
| Function boundary | **High** | Ghidra body + bytes |
| Signature thiscall + `ret 8` | **High** | Decomp + `c2 08 00` |
| Control flow | **High** | Linear; clean ≡ raw ≡ live |
| Store offset `+0x74c` stride 4 | **High** | Bytes + decomp |
| Dirty `+0x634 \|= 2` | **High** | Bytes + sibling share |
| Parameter names (slot/skillId) | **High** | Callers + plate + product docs |
| Empty-id product English | **Tentative** | Producer-dependent |
| Dirty-bit reader English | **Probable** | Writers sealed; readers open |
| Overall | **High (static kernel)** | Runtime / bit-exact open |

## Open questions

- Readers of `char+0x634` bit `2`.
- Live capture of local `+0x74c` after clear (`-1` vs normalized `0`).
- Optional dual residual on sibling `aa_00520890` to same byte depth (if still thin).

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_005208c0_CVOGCharacter_SetQuickBarSkill.md` |
| Annotated | `raw/aa_005208c0_CVOGCharacter_SetQuickBarSkill.annotated.md` |
| Clean | `reconstructed-exact/CVOGCharacter_SetQuickBarSkill.cpp` |
| Dual A | `reviews/A_aa_005208c0_CVOGCharacter_SetQuickBarSkill.md` |
| Dual B | `reviews/B_aa_005208c0_CVOGCharacter_SetQuickBarSkill.md` |
| Sibling item | `functions/aa_00520890_CVOGCharacter_SetQuickBarItem.md` |
| Product | `docs/skills-quickbar.md` |
