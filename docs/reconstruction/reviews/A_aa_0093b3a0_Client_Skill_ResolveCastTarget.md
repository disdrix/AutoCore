# Review A (reconstruction fidelity): `aa_0093b3a0` Client_Skill_ResolveCastTarget

| Field | Value |
|---|---|
| **Stable ID** | `aa_0093b3a0` |
| **VA** | `0x0093b3a0` |
| **Canonical name** | `Client_Skill_ResolveCastTarget` |
| **Review date** | `2026-07-23`; **residual close** `2026-07-29`; **hardpoint strengthen** `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0093b3a0_Client_Skill_ResolveCastTarget.md` |
| **Verdict** | **accept-with-gaps** (static dual residuals closed; hardpoint call-site plate Confirmed; runtime/diff open) |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0093b3a0_Client_Skill_ResolveCastTarget.md` |
| Annotated | `docs/reconstruction/raw/aa_0093b3a0_Client_Skill_ResolveCastTarget.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_Skill_ResolveCastTarget.cpp` |
| Callee | `Skill_ResolveTargetList` @ `0x00550300` (dual-reviewed) |
| Callee | `Skill_FilterTargetForResolveList_Inferred` @ `0x0054ff00` (dual accept) |
| Callee | `Vehicle_ResolveFirstHardpointOccupantTfid_Inferred` @ `0x004f8b80` (dual accept-with-gaps) |
| Callers | `Client_RequestCastSkill`, `Client_QuickBarActivateSkillSlot` (+2 FUN_*) |
| System | `docs/reconstruction/systems/skills-abilities.md` |
| Scratch | `reviews/a_0093b3a0.md` |

**Live re-decompile + hardpoint asm call-site plate + `read_memory` sentinels performed 2026-07-29.**

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Client in EAX; 5 stack formals (`RET 0x14`) | **Confirmed** | asm epilogue |
| Early null `+0xe98` → invalid TFID | **High** | CF match |
| `skill+0x614 == 1` force-seed out | **High** | Direct compare |
| Resolve source = entity dual-base; on-foot selection override | **High** | `+0x6b9` / `+0xa4` |
| `Skill_ResolveTargetList` + `outFlags` | **High** | Sibling dual-reviewed |
| outFlags bits 1/2/4/8 dispatch | **High CF** | bit4/8 writers sealed at filter |
| Related TFID via vtbl `+0x19c` then `+0x164` | **High** | Shared with cast path |
| Failure toasts gated by `bReportFailure` and on-foot | **High** | Strings present |
| Alt helper = hardpoint occupant TFID | **High** | was FUN_004f8b80; dual on `aa_004f8b80` |
| Hardpoint ECX this = `*(char+0x250)` | **Confirmed** | asm `0x0093b570`/`0x0093b576` |
| Hardpoint reloads write_seed EDI/EBP/EBX | **Confirmed** | asm `0x0093b581`..`0x0093b589` |
| Hardpoint miss sentinel content ≡ invalid TFID | **Confirmed** | `read_memory` both 16B |
| `TFID_NotEquals` first arg = `activeBindScratch` | **Confirmed** | asm `0x0093b74d`/`0x0093b75e` |
| Sticky does not promote binding TFID | **Confirmed** | no reload before write_seed |
| write_seed EDI/EBP/EBX plate | **Confirmed** | asm `0x0093b547` |

---

## 3. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Outer null + force-seed | **Yes** |
| Source resolve + ResolveTargetList | **Yes** |
| outFlags ladder + related/alt/fail | **Yes** |
| Hardpoint this + reload + equals | **Yes** (asm plate sealed) |
| Active-bind silent gate | **Yes** (pA fixed in clean) |
| Invalid TFID terminal | **Yes** |

---

## 4. Hardpoint TFID residual (strengthened)

### Gate (bit4 path only)

```
// after outFlags&4, skill+0x614&2 already failed related branch:
0093b56c  TEST AL, 0x8                 ; skill+0x614 bit3
0093b56e  JZ   code_0xe_fail           ; 0x0093b5df
0093b570  MOV  EDX, [ESI + 0xe98]      ; local character
0093b576  MOV  ECX, [EDX + 0x250]      ; vehicle/entity this
0093b57c  CALL Vehicle_ResolveFirstHardpointOccupantTfid_Inferred  ; 0x004f8b80
```

| Claim | Result | Conf |
|---|---|---|
| Priority: related (`&2`) before hardpoint (`&8`) | **Sealed** | **Confirmed** |
| Hardpoint only when bit4 **and** skill bit3 set | **Sealed** | **Confirmed** |
| ECX this = `*(localChar + 0x250)` | **Sealed** | **Confirmed** |
| Sole consumer of helper | **Sealed** | **Confirmed** (`get_function_callers`) |

### Return reload → write_seed plate

```
0093b581  MOV EDI, [EAX]               ; TFID[0]
0093b583  MOV EBP, [EAX+4]             ; TFID[1]
0093b586  MOV EBX, [EAX+8]             ; TFID[2]
0093b589  MOV EAX, [EAX+0xc]           ; TFID[3]
0093b58c  LEA ECX, [ESP+0x18]          ; compare buffer
0093b590  PUSH g_abTfidInvalid_A15870  ; 0x00a15870
0093b595  PUSH ECX
          ; also mirrors EDI/EBP/EBX/EAX into [ESP+0x20..0x2c]
0093b5a6  CALL TFID_EqualsObjectId     ; 0x00404aa0
0093b5ae  TEST AL, AL
0093b5b0  JZ   write_seed              ; AL==0 → not equal to invalid → success
```

`TFID_EqualsObjectId` returns **1** on match, **0** on mismatch (decomp of `0x00404aa0`). So `JZ write_seed` = hardpoint TFID is **valid**.

### Sentinel content equivalence

| Symbol | VA | 16B (`read_memory`) |
|---|---|---|
| `DAT_009cd0f8` (helper empty return) | `0x009cd0f8` | `ff ff ff ff ff ff ff ff 00 00 00 00 00 00 00 00` |
| `g_abTfidInvalid_A15870` (caller compare / write_invalid) | `0x00a15870` | **identical** |

- **Pointer identity:** different addresses (not the same DAT).
- **Content identity:** **Confirmed** — `TFID_EqualsObjectId` on helper empty return always hits the invalid path.
- Equals compares dwords `[0]`/`[4]` and byte `[8]` only; both sentinels match on that prefix.

### Fail UX (hardpoint empty)

```
// AL != 0 (equals invalid):
CMP  bReportFailure, 0
JZ   write_invalid
CMP  char+0x6b9, 0          ; on-foot
JNZ  write_invalid
PUSH "No enemies found."    ; 0x00a2e04c
→ FUN_007a6de0 → FUN_008f8200 channel 0x18 → write_invalid
```

String is **UX only** — not product proof of “enemy search” inside the helper (helper walks slot-table occupants).

### Helper body (consumer contract only)

Owned by `aa_004f8b80`; this unit only needs:

```
walk *(vehicle+0x260)[0..2]; first live object TFID @ object+0x160
else return &DAT_009cd0f8
```

Product table word remains `_Inferred` on the callee dual.

---

## 5. Residuals closed this pass

1. ~~`FUN_004f8b80` identity~~ → `Vehicle_ResolveFirstHardpointOccupantTfid_Inferred`.
2. ~~Active-binding unrecovered register~~ → `activeBindScratch`; silent-invalid semantics sealed.
3. ~~outFlags bit4/8 writers~~ → filter helper (sibling dual).
4. ~~Hardpoint this / reload / sentinel content~~ → **Confirmed** (this strengthen).

## 6. Remaining gaps

1. Runtime cast trace / binary diff.
2. Secondary callers `FUN_00829190` / `FUN_00941d50` roles (not hardpoint-specific).
3. Full `skill+0x614/+0x615` product glossary.
4. Slot-table product English (owned by `aa_004f8b80`).

**Verdict:** Player hop onto ResolveTargetList faithful; hardpoint alt-TFID path fully plate-sealed statically. **accept-with-gaps.**
