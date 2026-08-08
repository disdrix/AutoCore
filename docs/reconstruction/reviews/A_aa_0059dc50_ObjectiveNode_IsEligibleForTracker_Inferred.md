# Review A (reconstruction fidelity): `aa_0059dc50` ObjectiveNode_IsEligibleForTracker_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0059dc50` |
| **VA** | `0x0059dc50`–`0x0059dcb9` inclusive (**106 B** / `0x6A`) |
| **Canonical name** | `ObjectiveNode_IsEligibleForTracker_Inferred` |
| **Ghidra name** | `FUN_0059dc50` |
| **Review date** | `2026-08-05` (MEGA-025 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_0059dc50_ObjectiveNode_IsEligibleForTracker_Inferred.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `analyze_control_flow` + `disassemble_function` + `read_memory` + `get_function_callers` + `get_function_xrefs` + `get_assembly_context`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Boolean **eligibility gate** on an objective node before mission-tracker bind / selection:

```text
if character==null → false
if template.short[+0xf8]!=0 && node.flag[+0x14]==0 → false
if FUN_0059db80(character)==-1 → false
if template.id ∈ [0xdfd,0xe02] && character.vtbl[+0x27c]() < 5 → false
else → true
```

Consumed by dualed `Client_TryBindActiveMissionTracker` (`0x0092fd00`) and four objective-hash walkers.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ MEGA-025 append) | `docs/reconstruction/raw/aa_0059dc50_FUN_0059dc50.md` |
| Annotated | `docs/reconstruction/raw/aa_0059dc50_FUN_0059dc50.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ObjectiveNode_IsEligibleForTracker_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0059dc50.cpp` |
| Function record | `docs/reconstruction/functions/aa_0059dc50_FUN_0059dc50.md` |
| Named record | `docs/reconstruction/functions/aa_0059dc50_ObjectiveNode_IsEligibleForTracker_Inferred.md` |
| Live | decompile ≡ CF; body hex 106 B; 9 CALL xrefs / 5 callers; call-site ECX/PUSH/TEST AL |
| Parent dual | `Client_TryBindActiveMissionTracker` documents this as objective gate |

---

## 3. Signature (sealed)

```c
// ECX = ObjectiveNode*; stack Character*; AL bool; RET 4
uint8_t __thiscall ObjectiveNode_IsEligibleForTracker_Inferred(
    ObjectiveNode* self, Character* character);
```

| Slot | Source | Conf |
|---|---|---|
| self | **ECX** → ESI (`[ESI+0x14c]` template, `[ESI+0x14]` flag) | **High** |
| character | stack `[ESP+0xc]` after 2 pushes → EDI | **High** |
| return | **AL** (`XOR AL,AL` / `MOV AL,1`) | **High** |
| cleanup | **`RET 4`** ×2 exits | **High** |

**Note:** Decompiler shows `undefined4` return — assembly seals **AL** bool. Integer band form `0xdfc < id && id < 0xe03` ≡ inclusive `[0xdfd,0xe02]`.

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| Null character → fail | **Yes** | **High** |
| short@tmpl+0xf8 / flag@node+0x14 gate | **Yes** | **High** |
| CALL `0059db80`; CMP EAX,-1 → fail | **Yes** | **High** |
| id CMP 0xdfd / 0xe02 band | **Yes** (asm inclusive) | **High** |
| this-adjust + CALL `[vtbl+0x27c]`; CMP 5 | **Yes** | **High** |
| pass AL=1 / fail AL=0; RET 4 | **Yes** | **High** |
| Product English for fields/band/vtbl | open | **Inferred** |

Body hex (`read_memory` 106 B) ends `5f b0 01 5e c2 04 00` (pass) and `5f 32 c0 5e c2 04 00` (fail).

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | worker (predicate gate) |
| External callers | 5 functions; **9** UNCONDITIONAL_CALL xrefs |
| Site roles | tracker bind gate; hash-walk last-eligible / next-eligible |
| Callees | `FUN_0059db80`; character virtual `+0x27c` |
| Related dualed parent | `Client_TryBindActiveMissionTracker` `0x0092fd00` |

Call-site sample (`0x0092fd25`):

```text
PUSH ESI              ; character
MOV  ECX, EAX         ; objective node from hash
CALL 0x0059dc50
TEST AL, AL
JNZ  bind_success_path
```

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Bool predicate return | **Yes** |
| Objective node this (+0x14c template) | **Yes** |
| Tracker bind parent dual documents gate | **Yes** |
| Hash-walk callers promote only when true | **Yes** |
| Product English for all fields | **No** → `_Inferred` |
| Named_CalleeOf VOG_DEBUG_STOP scaffold | **Retired** — parent-seed only |

**Name:** `ObjectiveNode_IsEligibleForTracker_Inferred`

---

## 7. Gaps

- Product English for template short@`+0xf8`, node byte@`+0x14`, id band `0xdfd`–`0xe02`, virtual `+0x27c`.
- Sibling `FUN_0059db80` residual (out of OWN scope).
- Runtime / bit-exact / differential.

---

## 8. Verdict

CF/ABI/RET4/caller set/body hex sealed from live Ghidra. Residual product field English → **accept-with-gaps**.
