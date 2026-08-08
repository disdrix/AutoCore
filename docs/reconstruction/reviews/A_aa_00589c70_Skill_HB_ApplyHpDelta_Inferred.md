# Review A (reconstruction fidelity): `aa_00589c70` Skill_HB_ApplyHpDelta_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00589c70` |
| **VA** | `0x00589c70`–`0x00589d80` inclusive (**273 B** / `0x111`) |
| **Canonical name** | `Skill_HB_ApplyHpDelta_Inferred` |
| **Ghidra name** | `FUN_00589c70` |
| **Prior scaffold** | `FUN_00589c70` (2026-07-23 generic plate) |
| **Rejected misname** | bare `FUN_*` permanent; heat/shield sibling merge; thiscall-on-self |
| **Review date** | `2026-08-05` (MEGA-006 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00589c70_Skill_HB_ApplyHpDelta_Inferred.md` |
| **System** | skills-abilities / Skill HB combat pools |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + `get_function_callers` + `get_function_xrefs` + `get_assembly_context` + parent/callee decompile samples. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Skill hardpoint / heartbeat helper that **applies a signed HP delta** to a resolved combat entity:

1. Resolve entity from preferred `targetObj` (vtbl+0x19C + adjustor / `+0xAC` fallback) or `sourceOrNull`.
2. Convert float `amount` → integer `deltaInt` with optional **percent-of-max-HP** mode when `amount ∈ [-1, 1]`.
3. Optional **leave-1-HP** floor when `allowKill == 0`.
4. Dispatch through `FUN_004d7e30` (combat controller at `entity+0xA4`) for mutation + combat floater path.
5. Return projected HP change (`projected - cur`), or 0 on fail / no-op.

```text
Skill_HB_ApplyHpDelta_Inferred(source, target, amount, allowKill) -> int deltaHp
  resolve entity (vtbl+0x19C / +0xAC)
  deltaInt = -trunc(amount)  or  -trunc(GetMaxHp()*amount) if |amount|<=1
  cur = GetCurrentHp(); projected = cur - deltaInt
  if !allowKill && projected < 1: deltaInt = cur - 1
  FUN_004d7e30(entity->ctrl_0xA4, …, deltaInt, …)
  return (projected == cur) ? 0 : projected - cur
```

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ 2026-07-23 raw CF |
| Full body | `disassemble_function` + `read_memory` 273 B |
| Constants | `DAT_00aaa668`=-1.0f; `g_flOne`@`00a0f2a0`=1.0f; color `009d4d28..34` |
| Callee | `FUN_004d7e30` / nested `FUN_004d78e0` HP apply (`HP' = HP - delta`) |
| Parent | `FUN_0061b6f0` skill HB dispatcher @ `0x0061b854` (flag bit & 2) |
| Peer | `FUN_00618270` @ `0x006185c0` |
| Xrefs | 5 UNCONDITIONAL_CALL |
| Family | heat `00589bc0`, shield `00589d90`, short/floater `0058cc40` |

---

## 3. Signature (sealed)

```c
// __cdecl; bare RET; caller cleans 0x10
int Skill_HB_ApplyHpDelta_Inferred(
    void *sourceOrNull,  // [ESP+4]
    void *targetObj,     // [ESP+8]
    float amount,        // [ESP+C]  +heal / −damage
    char allowKill);     // [ESP+10] 0 = clamp leave-1
```

| Formal | Source | Conf |
|---|---|---|
| sourceOrNull | stack `[ESP+4]` / after prolog `[ESP+0x14]` | **Confirmed** |
| targetObj | stack `[ESP+8]` → EDI | **Confirmed** |
| amount | stack float `[ESP+0xC]` / MOVSS | **Confirmed** |
| allowKill | stack byte `[ESP+0x10]` | **Confirmed** |
| return | EAX = projected−cur or 0 | **Confirmed** |
| cleanup | bare `RET` (`C3`); callers `ADD ESP,0x10` | **Confirmed** |
| convention | **cdecl** (not thiscall) | **Confirmed** |

---

## 4. Control flow (sealed)

| Stage | Match | Conf |
|---|---|---|
| Prolog PUSH EBX/EBP/ESI/EDI | bytes | **Confirmed** |
| target null → use source as entity | JZ path | **Confirmed** |
| vtbl+0x19C + LEA adjustor | both resolve sites | **Confirmed** |
| fallback `[target+0xAC]` | MOV ECX,[EDI+0xAC] | **Confirmed** |
| early ret0 on null entity/iface | 3 JZ → XOR EAX | **Confirmed** |
| abs delta: NEG trunc(amount) | CVTTSS2SI+NEG | **Confirmed** |
| percent window COMISS [-1,1] | DAT_00aaa668 / g_flOne | **Confirmed** |
| GetMaxHp vtbl+0x244 × amount | CALL + MULSS | **Confirmed** |
| GetCurrentHp vtbl+0x23C | CALL | **Confirmed** |
| projected = cur − deltaInt | SUB EDI,EBX | **Confirmed** |
| floor leave-1 when !allowKill | CMP / LEA EBX,[EBP-1] | **Confirmed** |
| FUN_004d7e30 this=`[ESI+0xA4]` | MOV ECX + CALL | **Confirmed** |
| return projected−cur else 0 | SUB / XOR | **Confirmed** |
| Live decompile ≡ raw scaffold CF | re-verify append | **Confirmed** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | worker (skill HB combat apply) |
| External callers | **2** named (`FUN_0061b6f0`, `FUN_00618270`) + **5** xrefs total |
| Site role | HB tick HP channel; switch-table damage/heal cases |
| Callees | `FUN_004d7e30` only |
| Parent gate (0061b6f0) | skill flags `*(byte*)(skill+0x648) & 2` then amount `skill[0x6c4]*skill[0x60]` |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Parent is skill HB dispatcher `0x0061b6f0` | **Yes** |
| HP vtbl GetCurrent/GetMax + apply path | **Yes** |
| Sibling heat/shield/floater family adjacency | **Yes** |
| Partition hint `Skill_HB_ApplyHpDelta` | **Yes** |
| Product demangle / RTTI on this VA | **No** |

**Decision:** promote **`Skill_HB_ApplyHpDelta_Inferred`**. `_Inferred` retained (no product symbol string). Reject permanent `FUN_*` and heat/shield merges.

---

## 7. Gaps

- Product English for vtbl **+0x19C / +0x23C / +0x244** and controller **`+0xA4`**.
- Full dual of `FUN_004d7e30` / `FUN_004d78e0` (shared combat apply).
- Floater color plate name for `DAT_009d4d28`.
- Runtime / bit-exact / differential.

---

## 8. Verdict

Fidelity path seals CF/ABI/sign convention/callers with residual product-type English → **accept-with-gaps**.
