# Review A (reconstruction fidelity): `aa_005319d0` CVOGCharacter_TryUseItemObjectiveAction_LogicUi0e_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005319d0` |
| **VA** | `0x005319d0`–`0x00531afd` (**302 B** / `0x12E`) |
| **Canonical name** | `CVOGCharacter_TryUseItemObjectiveAction_LogicUi0e_Inferred` |
| **Ghidra name** | `FUN_005319d0` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY R10-012) |
| **Counterpart** | `reviews/B_aa_005319d0_CVOGCharacter_TryUseItemObjectiveAction_LogicUi0e_Inferred.md` |
| **System** | missions-progression |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`. Parent dual context as call-site evidence only (not dualled here). |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Character helper that **stages a UseItem objective requirement action** (when live-gate `dual+0x7E` is set) and **always on success path** enqueues LogicUI packet type **`0x0E`** with objective key + evaluator index.

Sole code caller: `CVOGObjectiveRequirement_UseItem_ObjectEventDispatch_Inferred` (`0x0060df70`) packet arm (event **9** + `req+0x34≠0`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ R10-012 append) | `docs/reconstruction/raw/aa_005319d0_FUN_005319d0.md` |
| Annotated | `docs/reconstruction/raw/aa_005319d0_FUN_005319d0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGCharacter_TryUseItemObjectiveAction_LogicUi0e_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_005319d0.cpp` |
| Function FUN | `docs/reconstruction/functions/aa_005319d0_FUN_005319d0.md` |
| Function named | `docs/reconstruction/functions/aa_005319d0_CVOGCharacter_TryUseItemObjectiveAction_LogicUi0e_Inferred.md` |
| Live | decompile ≡ original raw CF; body bounds `get_function_by_address`; epilogues `read_memory` |
| Call site | `0x0060e04a` in `FUN_0060df70` |

**Not performed:** `disassemble_bytes`; Launcher runtime Confirmed; parent ledger edits.

---

## 3. Signature (sealed)

```c
// ECX = character*; 6 stack dwords; RET 0x18; AL bool
uint8_t __thiscall CVOGCharacter_TryUseItemObjectiveAction_LogicUi0e_Inferred(
    void* thisCharacter,     // ECX
    uint32_t objectiveKey,   // +0x04  hash key into char+0x548
    int reqIndex,            // +0x08  evaluator index
    uint32_t coid0,          // +0x0C  worldObj+0x160 (caller)
    uint32_t coid1,          // +0x10
    uint32_t coid2,          // +0x14
    uint32_t coid3);         // +0x18
```

| Formal | Source | Conf |
|---|---|---|
| this character | `MOV EDI, ECX` | **High** |
| 6 stack dwords | `RET 0x18` (`C2 18 00`) both exits | **High** |
| AL 0/1 | fail fallthrough; success `B0 01` | **High** |
| frame `SUB ESP, 0x13C` | entry `81 EC 3C 01 00 00` | **High** |

---

## 4. Control flow (decompile + image)

| Stage | Match | Conf |
|---|---|---|
| dual-base `+0x7E == 0` → send without validation | decompile + raw | **High** |
| `CNDHash_LookupByKey(char+0x548, key)` | decompile | **High** |
| evaluator count `(end-begin)>>2` at def `+0x158/+0x15c` | decompile | **High** |
| index OOB / null hash → return 0 | decompile | **High** |
| vtbl `+0x50` type must be `0x0C` | decompile | **High** |
| RTTI cast → `CVOGObjectiveRequirement_UseItem` | decompile symbols | **High** |
| UseItem `+0x34` non-null; `FUN_00522b30` + flag `+0x3c` | decompile | **High** |
| stage fail → return 0 | decompile | **High** |
| LogicUI type `0x0E`; key + CDQ; index @ packet[0] | decompile + bytes `C7 … 0E` | **High** |
| queue this `dual+0xE8B8` | bytes `81 C1 B8 E8 00 00` | **High** |
| return 1 after send | `B0 01` + `RET 0x18` | **High** |

Clean named CF ≡ raw decompile CF ≡ live re-decompile (R10-012).

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | character worker (missions-progression) |
| Code callers | **1** — `FUN_0060df70` @ `0x0060e04a` |
| Parent role | UseItem ObjectEventDispatch packet arm; parent **XOR/clear AL** after call |
| Callees | `CNDHash_LookupByKey`; `__RTDynamicCast`; `FUN_00522b30`; `Client_SendLogicUiPacket` |

---

## 6. Gaps

1. Product English for LogicUI type **0x0E**.
2. Product name / full contract of residual **`FUN_00522b30`** (object stage / channel).
3. UseItem fields **`+0x34`** / **`+0x3c`** product English (target object + flag).
4. Full 0x138 LogicUI element field map beyond type/key/index.
5. Runtime / bit-exact / differential.

→ Name keeps **`_Inferred`**.

---

## 7. Surviving contract

```
TryUseItemObjectiveAction_LogicUi0e(character, key, index, coid0..3):
  dual = *( *( *(character+4)+4 ) + character + 0xA8 )
  if dual[+0x7E] != 0:
    def = CNDHash_LookupByKey(character+0x548, key) or return 0
    req = def.evaluators[index] or return 0
    if req.vtbl[+0x50]() != 0x0C: return 0
    use = dynamic_cast<UseItem>(req)
    if use[+0x34] == 0: return 0
    if !FUN_00522b30(use[+0x34], coid0..3, use[+0x3c]): return 0
  SendLogicUiPacket(dual+0xE8B8, type=0x0E, key, index)
  return 1
```

---

## 8. Verdict

**accept-with-gaps** — CF/ABI/RET0x18/hash+vector/type0xC/RTTI UseItem/LogicUI 0xE/sole caller sealed; product English for UI type + `FUN_00522b30` + field names open.
