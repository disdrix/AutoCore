# Review B (skeptical / adversarial): `aa_00401c30` StdVector_DwordSize_EaxVec_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00401c30` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY MEGA-082) |
| **Counterpart** | `reviews/A_aa_00401c30_StdVector_DwordSize_EaxVec_Inferred.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Drive / vehicle-name-specific helper (Named_CalleeOf plate) | **Falsified** — 11 multi-domain call sites; body has no plate strings; only parent `FUN_008d4910` holds `"Your Vehicle Name Is Invalid!…"` |
| 2 | Same as dualed `StdVector_DwordSize` `0x004024b0` (mergeable) | **Falsified** — twin uses **ECX**; this uses **EAX** (`MOV ECX,[EAX+4]` vs `MOV EDX,[ECX+4]`) |
| 3 | Capacity = `(cap-begin)>>2` | **Falsified** — only reads +4/+8 |
| 4 | Stride 0x18 / 0x1c / 0x38 | **Falsified** — `SAR 2` only (÷4) |
| 5 | `__thiscall` / ECX this | **Falsified** — bytes and all call sites use EAX |
| 6 | Mutates vector | **Falsified** — pure read leaf |
| 7 | Same as `SkillSet_GetEntryCount` `0x00402d80` | **Falsified** — different VA, different stride (0x18 magic) |
| 8 | Null begin undefined / crash | **Falsified** — explicit `XOR EAX,EAX; RET` |
| 9 | Runtime Confirmed | **Fails** — open (no Launcher) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Size formula `(end-begin)>>2` | **Confirmed** | Off-by-factor loop bounds |
| Null-safe begin | **Confirmed** | Spurious empty / crash |
| EAX ABI | **Confirmed** | Wrong register → garbage size |
| Distinct from ECX twin | **Confirmed** | Accidental merge of two helpers |
| Domain-agnostic helper | **Confirmed** | Over-specializing plate name |
| Product element English | **Low** | Name only (`_Inferred`) |

---

## 3. Cross-check against raw / bytes

```text
raw 2026-07-23 ≡ live decompile 2026-08-05 ≡ clean StdVector_DwordSize_EaxVec_Inferred.cpp

8B 48 04     mov ecx, [eax+4]
85 C9        test ecx, ecx
75 03        jnz short body
33 C0        xor eax, eax
C3           ret
8B 40 08     mov eax, [eax+8]
2B C1        sub eax, ecx
C1 F8 02     sar eax, 2
C3           ret

Body: 0x00401c30–0x00401c42 (19 B); pad CC before next unit.
Call sites: MOV EAX, <vec>; CALL 00401c30  (11× UNCONDITIONAL_CALL)
```

Reject ports that:

- Name this as vehicle-name / drive product logic.
- Use ECX thiscall (that is `004024b0`).
- Treat as capacity or non-4-byte stride.
- Drop the null-begin early return.

---

## 4. Surviving contract for AutoCore

```text
StdVector_DwordSize_EaxVec_Inferred(vec /*EAX*/) → n:
  begin==0 ? 0 : (end-begin)/4

// Keep separate from StdVector_DwordSize(vec /*ECX*/)
// Port either as free function taking vec* or as size() on a vector-like with
// begin/end at +4/+8. Do not invent vehicle-name domain ownership here.
```

---

## 5. Open questions

- Host container product types at each of the 11 sites (caller duals).
- Why two near-identical size helpers (EAX vs ECX) — MSVC emission / inlining residue; both must stay.

**Verdict:** Adversarial pass confirms A on CF/ABI/formula; plate misname and ECX-merge claims falsified → **accept**.
