# Review B (skeptical / adversarial): `aa_00520520` Character_GetReverseEngineerSkillCapacityByTier_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00520520` |
| **VA** | `0x00520520` |
| **Canonical name** | `Character_GetReverseEngineerSkillCapacityByTier_Inferred` |
| **Review date** | `2026-08-05` (R10-033 dual) |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_00520520_Character_GetReverseEngineerSkillCapacityByTier_Inferred.md` |
| **Live tools** | Independent `decompile_function` + `read_memory` + analyze/xrefs + `disassemble_function` + parent call-site bytes |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | ECX is **item**; name `Item_*Capacity*` | **Falsified** — sole field is `+0x598` on parent’s **character** this; both call sites `MOV ECX, [ESP+…]` from character local; parent free-flag / skill uses same object `+0x6b4` / `+0x598` |
| 2 | Function is tinker-skill related (Named_CalleeOf plate) | **Falsified** — no strings; only caller is RE success-fraction parent dualed under Reverse Engineering tooltip chain |
| 3 | Plain `RET` / no stack args | **Falsified** — all exits **`RET 4`** (`C2 04 00`); tier at `[EBP+8]`; parents `PUSH` before CALL |
| 4 | Leaf / no callees | **Falsified** — `CALL [0x009c6598]` = `floor` each case path; analyze callees `["floor"]` |
| 5 | Returns float / ST0 | **Falsified** — `FISTP` to stack dword → `MOV EAX,…`; int in EAX |
| 6 | Multipliers are skill weights `{2.5,2.0,…}` from parent score | **Falsified** — those are different DATs in parent; this VA’s mults are **3.5/2.8/2.1/1.4/0.7** via own DATs |
| 7 | Default can return non-zero | **Falsified** — `XOR EAX,EAX` then RET 4 |
| 8 | Same as parent’s inline `floor(skill*3.5)` only | **Falsified** — five scales; parent also inlines skill×3.5 for **primary** cost gate separately |
| 9 | Runtime Confirmed | **Fails** — open (Terminal false) |

---

## 2. Decisive machine dataflow

```text
PUSH EBP / MOV EBP,ESP / AND ESP,-8 / SUB ESP,8
MOV EAX, [EBP+8]              ; tier
CMP EAX, 5
JA  default_0
JMP [EAX*4 + 0x5206ac]        ; cases 0..5

case_k:
  MOVZX r32, byte [ECX+0x598]
  FILD skill
  FMUL float [mult_k]
  CALL floor                  ; [0x009c6598]
  ; FNSTCW; OR AH,0xC; FISTP → EAX
  MOV ESP,EBP / POP EBP / RET 4

default_0:
  XOR EAX,EAX
  MOV ESP,EBP / POP EBP / RET 4
```

Call-site A (`FUN_0052e640` @ `0x0052ea2b`):

```text
MOV ECX, [ESP+0x20]           ; character
LEA ESI, [EBP+1]              ; row_index + 1
PUSH ESI
CALL 0x00520520
CMP EDI, EAX                  ; cost > capacity → fail
JG  fail_path
```

Call-site B (`FUN_0052e640` @ `0x0052ea96`):

```text
PUSH EDI                      ; tier 0..5
MOV ECX, [ESP+0x24]           ; character
CALL 0x00520520
; EAX = capacity[tier]
```

A ≡ B on live decompile + body + float table + both call sites.

---

## 3. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Switch / table CF | **High** | wrong capacity math |
| ECX=character; +0x598 | **High** | skill on wrong object |
| Mult table 3.5…0.7 | **High** | wrong budgets / scores |
| RET 4 thiscall + tier stack | **High** | stack smash if ported as plain RET |
| RE capacity role via sole parent | **High** | mis-system placement |
| Product field English | Medium | naming only |
| Runtime | Open | — |

---

## 4. Surviving contract for AutoCore

```csharp
// Character-side RE skill capacity by recipe/score tier.
// thiscall; one stack arg (tier); RET 4; returns int.
int Character_GetReverseEngineerSkillCapacityByTier(Character ch, uint tier)
{
    byte skill = ch.ByteAt(0x598);
    float mult = tier switch
    {
        0 or 1 => 3.5f,
        2 => 2.8f,
        3 => 2.1f,
        4 => 1.4f,
        5 => 0.7f,
        _ => 0f,
    };
    if (mult == 0f) return 0;
    return (int)Math.Floor(skill * mult);
}
```

---

## 5. Verdict

Adversarial path falsifies item/tinker/plain-RET/leaf/float-return misreads. Surviving contract matches Path A → **accept-with-gaps** (product English + runtime open only).
