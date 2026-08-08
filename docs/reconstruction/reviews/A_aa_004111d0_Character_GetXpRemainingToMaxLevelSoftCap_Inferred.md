# Review A (reconstruction fidelity): `aa_004111d0` Character_GetXpRemainingToMaxLevelSoftCap_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004111d0` |
| **VA** | `0x004111d0` (measured **26 B**) |
| **Canonical name** | `Character_GetXpRemainingToMaxLevelSoftCap_Inferred` |
| **Ghidra name** | `FUN_004111d0` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY MEGA-124) |
| **Counterpart** | `reviews/B_aa_004111d0_Character_GetXpRemainingToMaxLevelSoftCap_Inferred.md` |
| **System** | missions-progression (XP soft-cap remaining) |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` (full body) + callers/xrefs + `get_assembly_context` + `analyze_function_completeness`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Return how much XP remains before the character hits the max-level soft-cap:

```text
threshold(maxLevel@+0xc50) − totalXp@+0x730 − 1
```

`Client_ShowMissionRewardChatToast` uses the result to clamp the scaled mission XP award shown in the "Awarded N …" toast (when `char+0x6b4 < 1` and award ≥ remaining).

Closes MEGA-124 residual: undualed level-cap clamp helper for XP toast.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ MEGA-124 append) | `docs/reconstruction/raw/aa_004111d0_FUN_004111d0.md` |
| Annotated | `docs/reconstruction/raw/aa_004111d0_FUN_004111d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Character_GetXpRemainingToMaxLevelSoftCap_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_004111d0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004111d0_Character_GetXpRemainingToMaxLevelSoftCap_Inferred.md` |
| Threshold helper | `Experience_GetCumulativeThreshold` `aa_0052c860` |
| Soft-cap twin | `CVOGReaction_AddExperience` (writes `threshold−1`) |
| Toast parent | `Client_ShowMissionRewardChatToast` `aa_008ac540` |
| Live | decompile ≡ scaffold; body hex 26 B; 2 call sites; ESI sealed |

---

## 3. Signature (sealed)

```c
// ESI = Character*; EAX = int remaining; bare RET
int Character_GetXpRemainingToMaxLevelSoftCap_Inferred(Character* character /* ESI */);
```

| Formal | Source | Conf |
|---|---|---|
| character* | **ESI** (`MOV AX,[ESI+0xc50]`; callers `MOV ESI,[DAT_00d1b6d8]`) | **High** |
| return | **EAX** after `SUB EAX,1` | **High** |
| cleanup | bare `C3` (no `RET n`) | **High** |

---

## 4. Control flow

| Stage | Match | Conf |
|---|---|---|
| Load maxLevel ushort @ +0xc50 | `66 8B 86 50 0C 00 00` | **High** |
| cdecl call threshold | `PUSH EAX` / `CALL 0x0052c860` / `ADD ESP,4` | **High** |
| Subtract totalXp @ +0x730 | `2B 86 30 07 00 00` | **High** |
| Soft-cap −1 | `83 E8 01` | **High** |
| Single BB, no branches | Ghidra CC=1, edge_count=0 | **High** |
| Live decompile ≡ raw scaffold | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (26 B) — raw MEGA-124 append:

```
668b86500c000050e883b611002b863007000083c40483e801c3
```

Pad `CC`×6 to next function `FUN_004111f0` @ `0x004111f0`.

E8 displacement: `0x004111dd + 0x0011B683 = 0x0052C860` ✓

---

## 6. Call-site clamp (parent evidence; not dualled)

```text
MOV ESI, [DAT_00d1b6d8]
CMP [ESI+0x6b4], 1
MOV EDI, award
JGE skip
CALL 004111d0          ; remaining
CMP EDI, EAX
JL  skip               ; award < remaining
MOV ESI, [DAT_00d1b6d8]
CALL 004111d0
MOV EDI, EAX           ; clamp
```

---

## 7. Gaps

- Product English for caller gate field `char+0x6b4` (specialMode/GM — parent/AddExperience inference).
- No zero-floor if remaining negative (bytes do not clamp).
- Product demangled name open → `_Inferred`.
- Runtime / bit-exact / differential.

---

## Verdict

**accept-with-gaps** — CF/ABI/formula/callers sealed; product English for gate field and runtime open.
