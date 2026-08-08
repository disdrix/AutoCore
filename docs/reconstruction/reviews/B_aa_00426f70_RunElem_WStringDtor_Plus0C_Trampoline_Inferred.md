# Review B (skeptical / adversarial): `aa_00426f70` RunElem_WStringDtor_Plus0C_Trampoline_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00426f70` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY R10-026) |
| **Counterpart** | `reviews/A_aa_00426f70_RunElem_WStringDtor_Plus0C_Trampoline_Inferred.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Full element / scalar deleting dtor with vtbl | **Falsified** — only `ADD ECX,0xC; JMP IAT`; no vtbl load, no `operator_delete` |
| 2 | Narrow `std::string` / char dtor | **Falsified** — IAT symbol is `~basic_string<wchar_t,...>` |
| 3 | Local CALL + RET epilogue | **Falsified** — `FF 25` tail JMP; no `C3` in body |
| 4 | Decompiler "jumptable" recovery needed | **Falsified** — noise on IAT JMP; 2-insn body complete |
| 5 | EBX-this like parent vector tidy | **Falsified** — only ECX used; parent loads `MOV ECX,ESI` before CALL |
| 6 | Free / zero the vector shell | **Falsified** — parent `004271c0` owns delete+zero; this only destroys one field |
| 7 | Named_CalleeOf_VOG_DEBUG product name | **Rejected** — scaffold noise; body is wstring member trampoline |
| 8 | Product demangle without RTTI | **Rejected** — keep `_Inferred` for "RunElem" English |
| 9 | Skills/combat ability logic in body | **Falsified** — pure MSVC string member dtor glue; system tag is ownership domain only |
| 10 | Multiple independent product roles | **Weakened** — shared trampoline; primary sealed use is 0x80-run vector tidy |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX this + +0x0C adjust | **High** | wrong member / crash |
| IAT ~wstring | **High** | wrong type free |
| Not full element dtor | **High** | leak other fields if assumed complete |
| "RunElem" product English | **Low–Med** | naming only |
| Runtime | **Open** | matrix |

---

## 3. Cross-check against raw + bytes + callers

```
// FUN_004271c0 (MEGA-128 dualed)
MOV ECX, ESI          // elem base
CALL FUN_00426f70
ADD ESI, 0x80

// FUN_00426f70
ADD ECX, 0x0C
JMP DWORD PTR [0x009C62AC]   // PTR_~basic_string<wchar_t,...>

// IAT 0x009c62ac also xref'd from UiTextLayout paths (e.g. 00797e00)
// — consistent with layout owning wstring members.
```

Closes R10 residual dual for trampoline left open by MEGA-128 parent gap #2.

---

## 4. Surviving contract for AutoCore

```
// Port as thiscall member-dtor trampoline:
// ECX = element base (stride 0x80 at vector callers)
// Destroy only basic_string<wchar_t> at +0x0C via MSVC IAT.
// Do NOT free element buffer or zero vector shell here.
// Pair with StdVector_DestroyRuns_0x80_Inferred (004271c0).
```

---

## 5. Verdict

**accept** — full body sealed (9 B); only residual is product element English (non-blocking `_Inferred`).
