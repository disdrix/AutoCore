# Review A (reconstruction fidelity): `aa_00520520` Character_GetReverseEngineerSkillCapacityByTier_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00520520` |
| **VA** | `0x00520520`–`0x005206aa` inclusive (**395 B** / `0x18b`) |
| **Canonical name** | `Character_GetReverseEngineerSkillCapacityByTier_Inferred` |
| **Ghidra name** | `FUN_00520520` |
| **Prior scaffold** | `Named_CalleeOf_Named_CalleeOf_Skill_You_do_not_possess_the_Tink_00520520` (**retired**) |
| **Review date** | `2026-08-05` (R10-033 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00520520_Character_GetReverseEngineerSkillCapacityByTier_Inferred.md` |
| **System** | inventory-transfer / reverse-engineer skill capacity by tier |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + `get_function_callers` + `get_xrefs_to` + `get_function_by_address` + parent call-site bytes. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Integer **skill × tier-multiplier → capacity** helper for reverse engineering:

```text
Character_GetReverseEngineerSkillCapacityByTier_Inferred(character, tier) -> int
  v = character[+0x598]           // uint8 skill
  mult = {3.5, 3.5, 2.8, 2.1, 1.4, 0.7}[tier]  // tier 0..5
  return floor(v * mult)          // tier > 5 → 0
```

Sole parent `Character_ComputeReverseEngineerSuccessFraction_Inferred` (`0x0052e640`) uses the return as:

1. **Budget gate** — if secondary recipe-row cost > capacity → success fraction 0.
2. **Score capacity[t]** — term `(capacity[t] − need[t])` in the weighted RE success formula.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ 2026-07-23 raw CF (switch 0..5 + default 0) |
| Full body | `disassemble_function` `0x00520520`–`0x005206a8` + NOP + jump table |
| Field | `MOVZX …, byte ptr [ECX+0x598]` all case paths |
| Floats | `read_memory` 4 B LE at five DAT addresses |
| Callers | only `FUN_0052e640` @ `0x0052ea2b`, `0x0052ea96` |
| ECX seal | both sites load character* into ECX before CALL |
| Callees | `floor` via IAT `[0x009c6598]` |
| Xrefs | 2 UNCONDITIONAL_CALL |

---

## 3. Signature (sealed)

```c
// ECX = character; stack tier; EAX = capacity; RET 4
int __thiscall Character_GetReverseEngineerSkillCapacityByTier_Inferred(
    void *character,
    unsigned tier);
```

| Formal | Source | Conf |
|---|---|---|
| character | **ECX** (`[ECX+0x598]`) | **Confirmed** |
| tier | stack `[EBP+8]` / parent `PUSH` | **Confirmed** |
| return | **EAX** int capacity | **Confirmed** |
| cleanup | **`RET 4`** all exits | **Confirmed** |
| jump table | `0x005206ac` 6 dwords | **Confirmed** |
| mults | `read_memory` floats | **Confirmed** |

**Note:** Ghidra `analyze` signature display `undefined FUN_00520520(void)` is **incorrect**.

---

## 4. Control flow (sealed)

| Stage | Match | Conf |
|---|---|---|
| Frame + load tier; `CMP 5` / `JA default` | disasm | **Confirmed** |
| Jump table cases 0/1 share target | table dwords identical | **Confirmed** |
| Each case: skill byte × float → floor → int EAX | disasm + decompile | **Confirmed** |
| Default XOR EAX,EAX | `0x005206a3` | **Confirmed** |
| Worker (floor only) | analyze callees | **Confirmed** |
| Product English for `+0x598` | open | **Inferred** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | **worker** (CRT `floor`) |
| External callers | **1** function, **2** call sites |
| Site A role | recipe-row capacity gate (`PUSH row+1`) |
| Site B role | score capacity[t] (`PUSH tier 0..5`) |
| Parent system | inventory-transfer RE (partition R10-033; parent `0x0052e640`) |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Character ECX via parent + `[ECX+0x598]` | **Yes** |
| Tier-scaled capacity math | **Yes** |
| RE parent dual (success fraction / tooltip chain) | **Yes** |
| In-body product string | **No** |
| Named_CalleeOf tinkering plate | **No** — retired scaffold |

**Decision:** promote **`Character_GetReverseEngineerSkillCapacityByTier_Inferred`**. Keep `_Inferred` until field English sealed.

---

## 7. Gaps

- Product English for `character+0x598` (RE skill rank name).
- Designer meaning of tier index vs recipe-row ordinal (`row+1` at site A).
- Runtime / bit-exact / differential.

---

## 8. Verdict

Fidelity path accepts CF/ABI/mult table/call-site ECX with only product-field English residual → **accept-with-gaps**.
