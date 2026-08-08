# Review B (skeptical / adversarial): `aa_00521f20` Character_ComputeTinkerSuccessChance_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00521f20` |
| **VA** | `0x00521f20` |
| **Canonical name** | `Character_ComputeTinkerSuccessChance_Inferred` |
| **Review date** | `2026-08-05` (R10-035 dual) |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_00521f20_Character_ComputeTinkerSuccessChance_Inferred.md` |
| **Live tools** | Independent `decompile_function` + `read_memory` + analyze/xrefs + `disassemble_function` + caller disasm |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | ECX is **item**; name `Item_*` success chance | **Falsified** — sole caller loads **`ECX = [DAT_00d1b6d8]`** (character); item is **stack** (`PUSH EDI`) |
| 2 | `extraout_DL` is decompiler phantom / unrelated | **Falsified** — `ADD DL,1` before `CALL 00521eb0`; after return `MOVZX DX,DL` uses same need in formula |
| 3 | Compare is “skill+1 vs item tier” with inverted gate | **Falsified** — need = **item slots+1**; tier = `FUN_00521eb0(character)`; `CMP EAX,ESI` / `JGE` → formula iff **tier ≥ need** (matches validate skill gate direction) |
| 4 | Returns percent 0..100 | **Falsified** — returns **fraction**; caller `FMUL [0x00aaa7ac]` (**100.0**) for UI |
| 5 | `__stdcall` / no this / plain `RET` | **Falsified** — `MOV EDI,ECX`; all exits **`RET 8`** |
| 6 | Base table is skill rank | **Falsified** — switch index is **need−1** (slots+1), not skill; higher need → **lower** base (harder next slot) |
| 7 | Linear term uses item `+0x59b` | **Falsified** — `MOVZX CX,[EDI+0x59b]` with EDI = **character this** |
| 8 | Kit not involved | **Falsified** — stack arg2; `ADD CX,[EAX+0xb0]` kit level |
| 9 | Named_CalleeOf skill-string plate is product name | **Falsified** — parent-seed scaffold; no strings in body |
| 10 | Multiple callers | **Falsified** — xref_count **1** |
| 11 | Runtime Confirmed | **Fails** — open (Terminal false) |

---

## 2. Decisive machine dataflow

```text
; entry
MOV EDI, ECX                    ; character
CMP [EDI+0x6b4], 1
JL  normal
FLD [g_flOne] / RET 8           ; 1.0

normal:
MOV ECX, [ESP+0xc]              ; item
CALL [vtbl+0x8c]                ; slots → AX
MOV DX, AX
ADD DL, 1                       ; need
MOV ECX, EDI                    ; character
MOVZX ESI, DL
CALL 0x00521eb0                 ; tier
CMP EAX, ESI
JGE formula
FLD [g_flZero] / RET 8          ; 0.0

formula:
; switch(need-1) → base ∈ {0.4,0.35,0.3,0.25,0.2}
; term = (int16)(char[+0x59b] - 2*need + kit[+0xb0])
; return term * 0.04 + base
```

Sole call site (`FUN_0085f660` @ `0x0085f6a8`–`0x0085f6c6`):

```text
MOV ECX, [0x00d1b6d8]           ; character*
PUSH ESI                        ; kit*
PUSH EDI                        ; item*
CALL 0x00521f20
FMUL [0x00aaa7ac]               ; * 100.0 → percent
```

A ≡ B on live decompile + body listing + float `read_memory` + sole call site.

---

## 3. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Switch / table CF + bases | **High** | wrong chance curve |
| ECX=character; item+kit stack; RET 8 | **High** | wrong object / stack smash |
| need = slots+1; tier gate | **High** | false 0% / wrong gate |
| Formula scale 0.04 + kit+0xb0 | **High** | wrong percent |
| Product field English | Medium | naming only |
| Runtime | Open | — |

---

## 4. Surviving contract for AutoCore

```csharp
// Character-side tinker success fraction for apply UI.
// thiscall ECX=character; stack item, kit; RET 8; float return.
float Character_ComputeTinkerSuccessChance(Character ch, Item item, TinkerKit kit)
{
    if (ch.IntAt(0x6b4) >= 1) return 1.0f;

    int need = (item.VtblCall_0x8c_SlotCount() + 1) & 0xFF;
    int tier = Item_GetTinkerSkillOrCap(ch); // FUN_00521eb0; ECX=character at this site
    if (tier < need) return 0.0f;

    float base = need switch {
        1 => 0.4f, 2 => 0.35f, 3 => 0.3f, 4 => 0.25f, 5 => 0.2f, _ => 0.0f
    };
    short term = (short)(ch.ByteAt(0x59b) - 2 * need + kit.ShortAt(0xb0));
    return term * 0.04f + base;
}
// UI: percent = chance * 100.0f
```

Port notes:

- Do **not** bind ECX as item (item is stack arg1).
- Keep distinct from `Item_ValidateTinkerKitUse` (status codes) — this is the float helper after status 4.
- Preserve `RET 8` / two stack args.
- `extraout_DL` is live **need**, not garbage.

---

## 5. Verdict

Adversarial path falsifies item-this / percent-return / phantom-DL / skill-as-switch-key / multi-caller claims. CF/ABI/formula sealed; product field English residual → **accept-with-gaps**.
