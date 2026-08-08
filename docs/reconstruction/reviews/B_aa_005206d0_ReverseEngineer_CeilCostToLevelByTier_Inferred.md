# Review B (skeptical / adversarial): `aa_005206d0` ReverseEngineer_CeilCostToLevelByTier_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005206d0` |
| **VA** | `0x005206d0`–`0x00520829` |
| **Canonical name** | `ReverseEngineer_CeilCostToLevelByTier_Inferred` |
| **Review date** | `2026-08-05` (R12-019 OWN dual) |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_005206d0_ReverseEngineer_CeilCostToLevelByTier_Inferred.md` |
| **Live tools** | Independent `decompile_function` + `analyze_function_complete` + callers/xrefs + `read_memory` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Same live Ghidra set as A. **No** `disassemble_bytes`. No Launcher / runtime Confirmed.

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This VA **is** the required-level parent / tooltip | **Falsified** — pure switch+ceil; no strings; no character fields; sole consumer is dualed `0x0052e1d0` which itself is only called from tooltip mode 0. |
| 2 | Tinkering-skill helper (`Named_CalleeOf_…Tink…`) | **Falsified** — no strings; only RE required-level parent; tinkering strings live in tooltip modes 4/5. |
| 3 | `__thiscall` / ECX = character or item | **Falsified** — no ECX use; args at `[EBP+8]` / `[EBP+0xC]`; **`RET 8`**. |
| 4 | cdecl plain `RET` / zero stack cleanup | **Falsified** — all exits **`C2 08 00`**. |
| 5 | Returns float / ST0 | **Falsified** — after ceil, FISTP dword → `MOV EAX`; parent uses as int max operand. |
| 6 | Same as capacity twin `0x00520520` | **Falsified** — capacity is **thiscall** skill×**mult** **floor**; this is **stdcall** cost×**inv** **ceil**; different body, ABI, return role. |
| 7 | Same as success-fraction twin `0x0052e640` | **Falsified** — different VA family; fraction returns float; this returns int level candidate. |
| 8 | Mults are capacity mults `{3.5,…}` not inverses | **Falsified** — `read_memory` yields 0.2857…/0.357…/… = **1/3.5, 1/2.8, …**. |
| 9 | Uses `floor` not `ceil` | **Falsified** — IAT call + decompile `ceil`; capacity twin uses `floor`. |
| 10 | Leaf / no callees | **Falsified** — `ceil` each case path. |
| 11 | Default can return non-zero | **Falsified** — `XOR EAX,EAX` then RET 8. |
| 12 | Runtime Confirmed | **Fails** — open (Terminal false). |

---

## 2. Decisive machine dataflow

```text
PUSH EBP / MOV EBP,ESP / AND ESP,-8 / SUB ESP,8
MOV EAX, [EBP+8]              ; tier / row-count
CMP EAX, 5
JA  default_0
JMP [EAX*4 + 0x52082c]        ; cases 0..5 (0 and 1 share)

case_k:
  FILD dword [EBP+0xC]        ; cost
  FMUL float [inv_mult_k]
  CALL ceil                   ; [0x009c6588]
  ; FNSTCW; OR 0x0C; FLDCW; FISTP → EAX
  MOV ESP,EBP / POP EBP / RET 8

default_0:
  XOR EAX,EAX
  MOV ESP,EBP / POP EBP / RET 8
```

Parent sites (dualed `FUN_0052e1d0`, evidence only):

```text
; aggregate
CALL 0x005206d0(row_count, total_cost)   ; max into local_34

; per-tier loop i=1..5
CALL 0x005206d0(i, row_cost[i])          ; max into local_34
```

A ≡ B on live decompile + body + float table + sole-caller xrefs.

---

## 3. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Switch / table CF | **High** | wrong level math |
| stdcall RET 8 / two stack args | **High** | stack smash if ported as thiscall/RET |
| Inv-mult table 1/3.5…1/0.7 | **High** | wrong required levels |
| ceil (not floor) | **High** | off-by-one levels |
| Sole parent RE required-level role | **High** | mis-system placement |
| Product English tier vs row | Medium | naming only |
| Runtime | Open | — |

---

## 4. Naming hostility

| Candidate | Why rejected / kept |
|---|---|
| `Named_CalleeOf_…Tinkering…` | Wrong domain strings |
| `Character_GetReverseEngineerSkillCapacityByTier` | Capacity twin; floor/thiscall |
| `Character_ComputeReverseEngineerRequiredLevel` | Parent only |
| `Item_GetRequiredLevel` | Too generic; no item this |
| `UI_ItemHover_…` | Grandparent role |
| **`ReverseEngineer_CeilCostToLevelByTier_Inferred`** | **Kept** — pure formula + sole parent; `_Inferred` for no PDB |

---

## 5. Residual risk

- Parent secondary-loop FPU noise (owned by R11-002) may affect **when** this helper is called, not the helper math itself.
- Negative cost edge cases not exercised by parent (costs accumulate non-negative / −1 sentinel skipped before call).
- No runtime / differential.

**Does not block accept-with-gaps.**

---

## 6. Surviving contract for AutoCore

```csharp
// Pure RE cost→level map by tier/row-count selector.
// stdcall; two stack args; RET 8; returns int.
int ReverseEngineer_CeilCostToLevelByTier(uint tier, int cost)
{
    float inv = tier switch
    {
        0 or 1 => 1f / 3.5f,
        2 => 1f / 2.8f,
        3 => 1f / 2.1f,
        4 => 1f / 1.4f,
        5 => 1f / 0.7f,
        _ => 0f,
    };
    if (inv == 0f) return 0;
    return (int)Math.Ceiling(cost * inv);
}
```

---

## 7. Verdict

Path A stands under adversarial attack. **accept-with-gaps**.
