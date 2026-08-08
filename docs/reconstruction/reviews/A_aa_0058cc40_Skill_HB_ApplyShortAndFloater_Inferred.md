# Review A (reconstruction fidelity): `aa_0058cc40` Skill_HB_ApplyShortAndFloater_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0058cc40` |
| **VA** | `0x0058cc40`–`0x0058cd54` inclusive (**277 B** / `0x115`) |
| **Canonical name** | `Skill_HB_ApplyShortAndFloater_Inferred` |
| **Ghidra name** | `FUN_0058cc40` |
| **Prior scaffold** | `FUN_0058cc40` (2026-07-23 generic plate) |
| **Rejected misname** | bare permanent `FUN_*`; HP/heat/shield merge; thiscall-on-skill; duration-"short" misread |
| **Review date** | `2026-08-05` (MEGA-008 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_0058cc40_Skill_HB_ApplyShortAndFloater_Inferred.md` |
| **System** | skills-abilities / Skill HB combat pools |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + `get_function_callers` + `get_function_xrefs` + `get_assembly_context` + parent/callee decompile samples. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Skill hardpoint / heartbeat helper that **applies a signed short-pool delta** and **enqueues a combat floater**:

1. Resolve short-host via vtbl **+0x214** (prefer `targetObj`, fallback `sourceOrNull` when target null).
2. Convert float `amount` → integer delta with optional **percent-of-max-short** when `amount ∈ [-1, 1]` (max @ `host+0x12e`).
3. Add delta to current short @ `host+0x12c` through setter vtbl **+0xAC**.
4. Build type-**2** floater blob (source/target colors @ `+0x160`, applied delta).
5. Enqueue via `Client_EnqueueCombatFloater_INFERRED` (`this = *(target+0xA4)+0xE8A4`).
6. Return applied short change (`new - old`), or 0 if host unresolved.

```text
Skill_HB_ApplyShortAndFloater_Inferred(source, target, amount) -> int appliedShort
  host = vtbl+0x214(target)  or  vtbl+0x214(source) if target==null && source!=null
  if host:
    delta = trunc(amount)  or  trunc(maxShort*amount) if |amount|<=1
    setShort(old + delta); applied = new - old
  floater type=2 colors(src/tgt) + applied
  Client_EnqueueCombatFloater(this=target.ctrl+0xE8A4, blob)
  return applied
```

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ 2026-07-23 raw CF (noise corrected via asm) |
| Full body | `disassemble_function` 277 B |
| Constants | `DAT_00aaa668`=-1.0f; `g_flOne`@`00a0f2a0`=1.0f; color `009d4d28..34` |
| Callee | `Client_EnqueueCombatFloater_INFERRED` `0x00402620` |
| Parent | `FUN_0061b6f0` skill HB dispatcher @ `0x0061b8c3` (flag `skill+0x649 & 0x80`) |
| Peer | `FUN_00618270` @ `0x0061862f` |
| Xrefs | 5 UNCONDITIONAL_CALL |
| Family | heat `00589bc0`, HP `00589c70`, shield `00589d90`, multi `0058d8e0` |

---

## 3. Signature (sealed)

```c
// __cdecl; bare RET; caller cleans 0xC
int Skill_HB_ApplyShortAndFloater_Inferred(
    void *sourceOrNull,  // [ESP+4]
    void *targetObj,     // [ESP+8]
    float amount);       // [ESP+C]  +gain / −drain
```

| Formal | Source | Conf |
|---|---|---|
| sourceOrNull | stack `[ESP+4]`; color donor / resolve fallback | **Confirmed** |
| targetObj | stack `[ESP+8]` → EBX; preferred resolve + floater | **Confirmed** |
| amount | stack float `[ESP+0xC]` / MOVSS | **Confirmed** |
| return | EAX = applied short delta or 0 | **Confirmed** |
| cleanup | bare `RET` (`C3`); callers `ADD ESP,0xC` | **Confirmed** |
| convention | **cdecl** (not thiscall) | **Confirmed** |

---

## 4. Control flow (sealed)

| Stage | Match | Conf |
|---|---|---|
| Prolog SUB ESP,0x38 + PUSH EBX/EBP/ESI/EDI | bytes | **Confirmed** |
| target non-null → resolve target vtbl+0x214 | JNZ path | **Confirmed** |
| target null && source non-null → source vtbl+0x214 | dual TEST | **Confirmed** |
| early applied=0 when host null | XOR EDI / JZ | **Confirmed** |
| abs delta: CVTTSS2SI amount | abs path | **Confirmed** |
| percent window COMISS [-1,1] | DAT_00aaa668 / g_flOne | **Confirmed** |
| max short word +0x12e × amount | MOVSX / MULSS | **Confirmed** |
| old short word +0x12c | MOV BP, word | **Confirmed** |
| set short vtbl+0xAC(old+delta) | PUSH / CALL | **Confirmed** |
| applied = new − old | MOVSX / SUB | **Confirmed** |
| source color +0x160 or DAT_009d4d28 | LEA / MOV imm | **Confirmed** |
| target color +0x160 | LEA EBX+0x160 | **Confirmed** |
| floater type dword = 2 | MOV [ESP+0x44],2 | **Confirmed** |
| this = [target+0xA4]+0xE8A4 | MOV / ADD | **Confirmed** |
| CALL 0x00402620 | sole non-virtual CALL | **Confirmed** |
| return EDI; ADD ESP,0x38; RET | epilogue | **Confirmed** |
| Live decompile ≡ raw scaffold CF | re-verify append | **Confirmed** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | worker (skill HB short-pool apply + floater) |
| External callers | **2** named (`FUN_0061b6f0`, `FUN_00618270`) + **5** xrefs total |
| Site role | HB tick short channel; switch-table gain/drain cases |
| Callees | `Client_EnqueueCombatFloater_INFERRED` + virtuals +0x214 / +0xAC |
| Parent gate (0061b6f0) | skill flags `*(byte*)(skill+0x649) & 0x80` then amount `skill[0x6c4]*skill[0x64]` |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Parent is skill HB dispatcher `0x0061b6f0` | **Yes** |
| Mutates 16-bit short field (+0x12c/+0x12e) not HP/heat/shield | **Yes** |
| Always enqueues combat floater type 2 | **Yes** |
| Sibling heat/HP/shield/multi family adjacency | **Yes** |
| Partition hint `Skill_HB_ApplyShortAndFloater` | **Yes** |
| Product demangle / RTTI on this VA | **No** |

**Decision:** promote **`Skill_HB_ApplyShortAndFloater_Inferred`**. `_Inferred` retained (no product symbol string; "Short" = 16-bit pool field role, not proven product English). Reject permanent `FUN_*`, HP/heat/shield merges, and duration-timer misnames. No `Named_CalleeOf_*` scaffold present to retire.

---

## 7. Gaps

- Product English for short pool resource at **+0x12c / +0x12e**.
- Product English for vtbl **+0x214 / +0xAC** and queue base **+0xE8A4**.
- Floater type **2** plate name.
- Runtime / bit-exact / differential.

---

## 8. Verdict

Fidelity path seals CF/ABI/sign/floater/callers with residual product-type English → **accept-with-gaps**.
