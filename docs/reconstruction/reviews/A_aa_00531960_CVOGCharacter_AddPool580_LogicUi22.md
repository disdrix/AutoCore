# Review A (reconstruction fidelity): `aa_00531960` CVOGCharacter_AddPool580_LogicUi22

| Field | Value |
|---|---|
| **Stable ID** | `aa_00531960` |
| **VA** | `0x00531960` |
| **Canonical name** | `FUN_00531960` (proposed: `CVOGCharacter_AddPool580`; English rep/talent **open**) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00531960_CVOGCharacter_AddPool580_LogicUi22.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept** on CF/ABI/offsets; product pool name **open** |

---

## 1. Purpose

Add a **signed short delta** into character pool at **`+0x580`**, always dirty **`+0x634 |= 1`**, and if delta **> 0** fire LogicUI type **`0x22`** with local player TFID pair via `Client_SendLogicUiPacket`.

Symmetric sibling pattern to skill (`+0x6ce`, LogicUI `0x21`) and attribute (`+0x6cc`, LogicUI `0x23`) pool helpers — this unit is the third pool with UI type **0x22**.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00531960_FUN_00531960.md` |
| Annotated | `docs/reconstruction/raw/aa_00531960_FUN_00531960.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00531960.cpp` |
| Function record | `docs/reconstruction/functions/aa_00531960_FUN_00531960.md` |
| Live listing | `disassemble_function` `0x00531960` |
| Call site | `get_assembly_context` @ `0x0053424b` |
| Parent residual | `reviews/a_00533f90.md` |
| Sibling duals | `A/B` AddSkillPoints / AddAttributePoints / SendLogicUiPacket |

---

## 3. Body (listing)

```text
00531960  SUB ESP, 0x138
00531968  MOV DI, [ESP+0x144]     ; short delta
00531973  MOV ESI, ECX            ; character
00531975  JLE skip_ui             ; if delta <= 0, skip LogicUI only
00531977  ; pack TFID from entity+0x164/0x168, type 0x22
005319a0  ADD ECX, 0xe8b8         ; LogicUI target on entity chain
005319ae  CALL Client_SendLogicUiPacket
005319b3  ADD [ESI+0x580], DI     ; **always** apply delta (including ≤0 path)
005319ba  OR  [ESI+0x634], 1
005319c9  RET 4
```

Live decompile CF ≡ raw. **Important:** add + dirty run even when delta ≤ 0; only UI is gated `> 0`.

---

## 4. ABI

```c
void __thiscall CVOGCharacter_AddPool580(
    void* thisCharacter,  // ECX
    int16_t delta);       // stack; RET 4
```

| Claim | Evidence | Conf |
|---|---|---|
| `__thiscall` RET 4 | listing | **High** |
| Short addend | `MOV DI, word [...]`; `ADD word [ESI+0x580], DI` | **High** |
| UI only if delta > 0 | `TEST DI / JLE` | **High** |
| LogicUI type **0x22** | `MOV [ESP+0x28], 0x22` | **High** |
| Dirty bit **1** | `OR [ESI+0x634], 1` | **High** (same bit as credits path) |

---

## 5. CompleteObjective call site

```text
MOV EAX, [EBX+0x114]    ; obj+0x114
TEST EAX,EAX
JLE skip                 ; skip call entirely if <= 0
PUSH EAX
MOV ECX, ESI
CALL 0x00531960
```

| Objective field | Role |
|---|---|
| `obj+0x114` (`puVar2[0x45]`) | Delta; caller also skips ≤0 |

Caller pre-gate means negative deltas are **not** applied from CompleteObjective even though callee would accept them.

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Pool store `+0x580` short | **High** | |
| LogicUI 0x22 on increase | **High** | |
| Dirty `\|1` always | **High** | |
| Product English (rep / prestige / talent) | **Open** | residual open |
| TFID pack from +0x164/+0x168 | **High** CF | same pattern as other LogicUI sends |
| Clean ≡ raw | **High** | |

---

## 7. Surviving contract

```
AddPool580(character, delta):
  if delta > 0:
    SendLogicUiPacket(type=0x22, localTfid...)
  *(int16*)(character+0x580) += delta
  *(uint32*)(character+0x634) |= 1
```
