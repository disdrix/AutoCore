# Review A (reconstruction fidelity): `aa_00530550` CVOGCharacter_AwardMedalById

| Field | Value |
|---|---|
| **Stable ID** | `aa_00530550` |
| **VA** | `0x00530550` |
| **Canonical name** | `FUN_00530550` (proposed: `CVOGCharacter_AwardMedalById`) |
| **Prior names** | `Named_CalleeOf_CVOGReaction_Dispatch_00530550` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw; dual OWN-ONLY) |
| **Counterpart** | `reviews/B_aa_00530550_CVOGCharacter_AwardMedalById.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** (product medal English open; chain `FUN_005304a0` shallow) |

---

## 1. Purpose

Character **medal award by id** on final objective complete (and peer S2C paths):

1. Lookup medal def via `FUN_0051a0e0(medalId)` on global medal hash.
2. Miss → return **0**.
3. Hit → push notify into `this+0x570` via `CVOGReaction_FailMissionNotify` (notify vector; name is historical), dirty `char+0x634 |= 0x20`.
4. Re-lookup; if def `+0x14 != -1`, chain `FUN_005304a0(def+0x14, def+0x18, 0)` with **ECX = character**.
5. Return **1**.

Does **not** write medal ownership maps itself beyond dirty bit + notify + optional skill-chain helper.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00530550_FUN_00530550.md` |
| Annotated | `docs/reconstruction/raw/aa_00530550_FUN_00530550.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00530550.cpp` |
| Function record | `docs/reconstruction/functions/aa_00530550_FUN_00530550.md` |
| Live decompile | Ghidra `batch_decompile` / `analyze_function_complete` `0x00530550` |
| Live listing | `disassemble_function` `0x00530550` |
| Call site | `get_assembly_context` @ `0x0053421d` (CompleteObjective) |
| Parent residual | `reviews/a_00533f90.md` medal FUN seal |
| Parent dual | `A/B_aa_00533f90_CVOGReaction_CompleteObjective` |
| Callee dual | `A/B` pending / present for `FUN_0051a0e0` (this batch) |

**Not performed:** `disassemble_bytes`, Launcher, live medal award capture, deep `FUN_005304a0` dual.

---

## 3. Body (listing seals)

```text
00530550  PUSH ESI / PUSH EDI
00530552  MOV EDI, [ESP+0xC]          ; medalId
00530557  MOV ESI, ECX                ; character
00530559  CALL FUN_0051a0e0(EDI)      ; cdecl; ADD ESP,4
00530561  TEST EAX / JZ → return 0
0053056a  LEA ECX, [ESI+0x570]
00530570  CALL FailMissionNotify(&medalId on stack)
00530575  OR  [ESI+0x634], 0x20
0053057d  CALL FUN_0051a0e0(EDI) again
00530589  MOV ECX, [EAX+0x14]; CMP ECX,-1; JZ skip_chain
00530591  MOV EDX, [EAX+0x18]
00530594  PUSH 0; PUSH EDX; PUSH ECX; MOV ECX,ESI
0053059a  CALL FUN_005304a0
005305a0  MOV AL,1 / RET 4
005305a7  XOR AL,AL / RET 4
```

Live decompile CF ≡ frozen raw.

---

## 4. ABI / signature (High)

```c
uint8_t /* AL */ __thiscall CVOGCharacter_AwardMedalById(
    void* thisCharacter,   // ECX
    uint32_t medalId);     // stack; RET 4
```

| Claim | Evidence | Conf |
|---|---|---|
| `__thiscall` + **RET 4** | listing epilogue both paths | **High** |
| ECX = character | call site `MOV ECX,ESI` (char); body uses `ESI+0x570`, `+0x634` | **High** |
| Return 0/1 in AL | `XOR AL,AL` / `MOV AL,1` | **High** |
| Double lookup intentional | two real CALLs to `0051a0e0` | **High** |

---

## 5. Offsets / callees

| Offset / symbol | Role | Conf |
|---|---|---|
| `char+0x570` | Notify vector this for `FailMissionNotify` | **High** |
| `char+0x634 \|= 0x20` | Dirty bit for medal / related sync | **High** |
| Medal def `+0x14` | Chain skill/id; **-1** = no chain | **High** CF |
| Medal def `+0x18` | Chain secondary arg | **High** CF; English open |
| `FUN_0051a0e0` | Medal def lookup by id | **High** |
| `FUN_005304a0` | Optional rank/skill side effect | **Probable** (boundary only) |

---

## 6. CompleteObjective call site

```text
; EBX = objective; ESI = character; after XP/credits
MOV EAX, [EBX+0x100]     ; obj+0x100 = medal id
CMP EAX, -1
JZ skip
PUSH EAX
MOV ECX, ESI
CALL 0x00530550
```

| Objective field | Role |
|---|---|
| `obj+0x100` (`puVar2[0x40]`) | Medal id; **-1** = none |

Toast path later re-lookups same id via `FUN_0051a0e0` for "Earned the … Medal" string — **separate** from this unit.

---

## 7. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF: lookup → notify → dirty → optional chain → 1/0 | **High** | listing ≡ raw ≡ clean scaffold |
| thiscall character | **High** | |
| Medal id arg | **High** | CompleteObjective + toast string path |
| Product name `AwardMedal` | **Probable** | toast "Medal" / residual; PDB open |
| `FailMissionNotify` English for success notify | **Low** | reuse of fail-notify vector helper |
| Chain `FUN_005304a0` full semantics | **Tentative** | not dualed here |
| Clean ≡ raw CF | **High** | scaffold naming only |

---

## 8. Surviving contract

```
AwardMedalById(character, medalId) -> 0/1
  def = MedalLookup(medalId)          // FUN_0051a0e0 / DAT_00b042e0
  if !def: return 0
  push notify at character+0x570 with medalId
  character.dirty |= 0x20
  def = MedalLookup(medalId) again
  if def && def.chainId(+0x14) != -1:
    FUN_005304a0(character, def+0x14, def+0x18, 0)
  return 1
```
