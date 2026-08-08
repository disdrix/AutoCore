# Review B (skeptical / adversarial): `aa_00401d30` BasicStringFlag_CtorFromStringAndChar_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00401d30` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY MEGA-065) |
| **Counterpart** | `reviews/A_aa_00401d30_BasicStringFlag_CtorFromStringAndChar_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Mission-dialog / null-dialog UI helper | **Falsified** — body is SEH + string copy + 1-byte store; sole caller is parse/insert residual `FUN_00980160`; no dialog strings or UI vtbl |
| 2 | Plain `basic_string` copy-ctor only (no flag) | **Falsified** — `MOV DL,[ECX]; MOV [ESI+0x1c],DL` after string size 0x1c |
| 3 | `param_3` is `basic_string*` (decompiler typing) | **Falsified** — byte load from `[ECX]`; call site pushes address of single-byte local set to 0 |
| 4 | Same ABI as copy twin `00402040` (EDI src, RET 4) | **Falsified** — this unit has **3 stack formals** and **`RET 0xC`**; copy twin uses EDI + RET 4 |
| 5 | Aggregate thiscall (ECX = dest on entry) | **Falsified** — dest loaded from stack; ECX used only for string IAT thiscall |
| 6 | `__cdecl` (caller cleans) | **Falsified** — `RET 0xC` callee cleans 12 bytes |
| 7 | Merge with / same as `00402040` | **Falsified** — different formals (string+char* vs EDI aggregate); different cleanup |
| 8 | `std::pair` product-demangled name sealed | **Open gap** — layout matches pair-shaped `{string, byte}` but no RTTI/product English for flag → keep `_Inferred` |
| 9 | Runtime Confirmed | **Fails** — open (no Launcher) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| CF SEH → string copy → flag byte | **Confirmed** | Wrong aggregate ctor in ports |
| RET 0xC / 3 stack args | **Confirmed** | Stack imbalance at sole call site |
| Layout string@0 + flag@0x1c | **Confirmed** | Misaligned flag / string overwrite |
| Not mission-dialog specific | **Confirmed** | Misleading system tags / wrong subsystem ownership |
| Twin relationship to `00402040` | **High** | Shared layout; different ABI — must not merge |
| Product flag English | **Low** | Doc only; `_Inferred` required |
| Parent map value_type English | **Low** | Residual parents |

---

## 3. Cross-check against raw / bytes

```text
raw 2026-07-23 ≡ live decompile 2026-08-05 CF ≡ clean BasicStringFlag_CtorFromStringAndChar_Inferred.cpp
  (with ABI correction: param_3 is char*, not basic_string*)

6A FF 68 B9 BF 9B 00 64 A1 … 64 89 25 …   SEH LAB_009bbfb9
FF 15 EC 62 9C 00                          CALL [0x009c62ec] string copy
8A 11 88 56 1C                             MOV DL,[ECX]; MOV [ESI+0x1c],DL
C2 0C 00                                   RET 0xC

Sole xref: 009801af UNCONDITIONAL_CALL from FUN_00980160
  push char*; push string*; push dest*; CALL; MOV EDI,EAX; CALL 00402040
```

Reject ports that:

- Name this as mission-dialog open / null-dialog handler.
- Drop the flag byte or treat param_3 as full string.
- Use thiscall-ECX-aggregate or cdecl without popping 12 bytes.
- Merge body with copy twin `00402040` (EDI/RET4).
- Claim product flag English without further evidence.

---

## 4. Surviving contract for AutoCore

```csharp
// Retail-shaped: construct { string, byte } from separate sources.
// Native: __stdcall 3 args, RET 0xC; managed: ordinary ctor.

sealed class BasicStringFlag
{
    public string Str;   // MSVC basic_string footprint 0x1c at native
    public byte   Flag;  // @ +0x1c — product meaning open

    public BasicStringFlag(string src, byte flag)
    {
        Str = src;
        Flag = flag;
    }
}

// Call pattern (sole parent FUN_00980160):
//   var tmp = new BasicStringFlag(substrResult, 0);
//   var copy = tmp;  // via BasicStringFlag_CopyCtor_EdiSrc_Inferred (00402040)
//   map insert/find peer (00401c50) …
```

---

## 5. Verdict

Adversarial pass confirms A on CF/ABI/layout and rejects mission-dialog / merge-with-copy / decompiler-param3 claims. Product flag + map English residual only → **accept-with-gaps**.
