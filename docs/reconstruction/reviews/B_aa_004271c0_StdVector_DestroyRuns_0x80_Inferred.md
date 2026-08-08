# Review B (skeptical / adversarial): `aa_004271c0` StdVector_DestroyRuns_0x80_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004271c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY MEGA-128) |
| **Counterpart** | `reviews/A_aa_004271c0_StdVector_DestroyRuns_0x80_Inferred.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | `operator_delete` does not return | **Falsified** — `ADD ESP,4; POP EDI;` three MOV zeros; `POP ESI; RET` after delete |
| 2 | thiscall ECX=vector | **Falsified** — only EBX used for shell; ECX loaded from ESI as **elem** for dtor |
| 3 | Element stride 4 / dword vector | **Falsified** — `ADD ESI,0x80` / `81 C6 80 00 00 00` |
| 4 | Full element dtor with vtbl | **Falsified** — only trampoline `ADD ECX,0xC; JMP ~wstring` |
| 5 | Multiple independent product callers | **Weakened** — one CALL + one JMP thunk only |
| 6 | Zeros at +0 of shell / free host layout | **Falsified** — only +4/+8/+0xC written; host free is parent |
| 7 | Named_CalleeOf_VOG_DEBUG_STOP product name | **Rejected** — scaffold noise; body is vector tidy |
| 8 | Product demangle without RTTI | **Rejected** — keep `_Inferred` |
| 9 | Skills/combat ability logic in body | **Falsified** — pure container teardown; system tag is ownership domain only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EBX-this + void RET | **High** | ABI crash / wrong shell |
| stride 0x80 + delete + zero | **High** | leak / UAF |
| ~wstring via 00426f70 | **High** | leak of string buffer |
| "runs" product English | **Low–Med** | naming only |
| Runtime | **Open** | matrix |

---

## 3. Cross-check against raw + bytes + callers

```
// FUN_00797d70 (WQ9L-F dualed)
LEA EBX, [ESI+0x80]
CALL FUN_004271c0

// FUN_004271c0
walk [begin,end) step 0x80; FUN_00426f70(ECX=elem); delete begin; zero

// FUN_00426f70
ADD ECX, 0xC
JMP dword ptr [IAT ~basic_string<wchar_t>]
```

Closes WQ9L-F residual “FUN_004271c0 dual open” / MEGA-128 partition unit.

---

## 4. Surviving contract for AutoCore

```
// Port as EBX-this vector tidy (not thiscall):
// begin@+4 end@+8 cap@+0xC; elem stride 0x80
// For each elem: ~wstring at +0x0C (FUN_00426f70 trampoline)
// Then operator_delete(begin); zero triple.
// Pair with UiTextLayout complete dtor (layout+0x80).
// Do not free host layout inside this helper.
```

---

## 5. Verdict

**accept** — full body sealed; only residual is product element English (non-blocking `_Inferred`).
