# Review B (skeptical / adversarial): `aa_00521eb0` Item_GetTinkerSkillOrCap_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00521eb0` |
| **VA** | `0x00521eb0` |
| **Canonical name** | `Item_GetTinkerSkillOrCap_Inferred` |
| **Review date** | `2026-08-05` (MEGA-106 dual) |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_00521eb0_Item_GetTinkerSkillOrCap_Inferred.md` |
| **Live tools** | Independent `decompile_function` + `read_memory` + analyze/xrefs + `disassemble_function` + caller disasm |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | ECX is **character**; name `Character_GetTinkerSkillOrCap` | **Falsified** — both callers `MOV ECX,EDI` with EDI = **item** (`+0x6b4` on same object; `00521f20` this=item) |
| 2 | Function **reads character skill** | **Falsified** — sole memory read is `[ECX+0x59b]`; character skill is parent `CALL [vtbl+0x8c]` |
| 3 | Returns full skill level unbounded | **Falsified** — hard cap **5** via table + default `AND 5` |
| 4 | `__stdcall` / stack args / `RET 4` | **Falsified** — plain **`RET`** (`C3`) all exits; no stack pops of args |
| 5 | Has callees / not a leaf | **Falsified** — no CALL in body; analyze callees empty |
| 6 | Default path can return 0 for v>9 | **Falsified** — for v>9, `CMP 9,AL` sets CF; `SBB EAX,EAX` → `-1`; `AND 5` → **5** |
| 7 | Same as raw `+0x59b` passthrough | **Falsified** — pairs ranks (1–2→1, …) |
| 8 | Named_CalleeOf skill-string plate is product name | **Falsified** — parent-seed scaffold only; no strings in body |
| 9 | Runtime Confirmed | **Fails** — open (Terminal false) |

---

## 2. Decisive machine dataflow

```text
MOV AL, [ECX+0x59b]
TEST AL,AL
JA  non_zero
XOR EAX,EAX
RET                      ; 0

non_zero:
MOVZX ECX, AL
ADD ECX, -1
CMP ECX, 8
JA  default_ge_10
JMP [ECX*4 + 0x521ef8]   ; table → MOV EAX,1..5 / RET

default_ge_10:
MOV CL, 9
CMP CL, AL
SBB EAX, EAX
AND EAX, 5
RET                      ; 5 when AL > 9
```

Call-site A (`FUN_00513c10` @ `0x00513c9f`):

```text
MOV ECX, EDI             ; item (stack param_2)
ADD ESI, 1               ; character skill + 1
CALL 0x00521eb0
CMP EAX, ESI
```

Call-site B (`FUN_00521f20` @ `0x00521f54`):

```text
MOV ECX, EDI             ; item this
CALL 0x00521eb0
CMP EAX, ESI             ; character skill+1
```

A ≡ B on live decompile + body hex + jump table + both call sites.

---

## 3. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Switch / table CF | **High** | wrong tier math |
| ECX=item; +0x59b | **High** | skill gate on wrong object |
| Cap 5 mapping | **High** | false tinker allow/deny |
| Plain RET thiscall | **High** | stack smash if ported as stdcall |
| Product field English | Medium | naming only |
| Runtime | Open | — |

---

## 4. Surviving contract for AutoCore

```csharp
// Item-side tinker skill-tier / cap from byte @ +0x59b
// Returns 0..5. Leaf. thiscall, no stack args.
byte Item_GetTinkerSkillOrCap(Item item)
{
    byte v = item.ByteAt(0x59b);
    if (v == 0) return 0;
    if (v >= 10) return 5;
    // pairs: 1-2→1, 3-4→2, 5-6→3, 7-8→4, 9→5
    return (byte)((v + 1) / 2);
}
```

Port notes:

- Do **not** bind this to character `this`.
- Keep distinct from character vfunc `+0x8c` skill read in parents.
- Pair with validate path `FUN_00513c10` and float helper `FUN_00521f20`.

---

## 5. Verdict

Adversarial path falsifies character-this / unbounded skill / stdcall / non-leaf claims. CF/ABI/mapping sealed; product field English residual → **accept-with-gaps**.
