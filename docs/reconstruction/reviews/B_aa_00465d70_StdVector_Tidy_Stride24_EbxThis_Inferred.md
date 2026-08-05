# Review B (skeptical / adversarial): `aa_00465d70` StdVector_Tidy_Stride24_EbxThis_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00465d70` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY W38-R) |
| **Counterpart** | `reviews/A_aa_00465d70_StdVector_Tidy_Stride24_EbxThis_Inferred.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | `operator_delete` does not return | **Falsified** — POP EDI; three MOV zeros; POP ESI; RET after delete |
| 2 | thiscall ECX=vector | **Falsified** — only EBX used; caller LEA EBX |
| 3 | Element stride 4 / dword vector | **Falsified** — `ADD ESI,0x24` |
| 4 | Full element dtor with vtbl | **Falsified** — only `FUN_00481d80` nested free @+0x18 |
| 5 | Multiple independent callers | **Weakened** — one CALL + one JMP thunk only |
| 6 | Zeros at +0 of shell | **Falsified** — only +4/+8/+0xC written |
| 7 | Product name without evidence | **Rejected** — keep `_Inferred` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EBX-this + void RET | **High** | ABI crash / wrong shell |
| stride 0x24 + delete + zero | **High** | leak / UAF |
| nested free via 00481d80 | **High** | leak of +0x18 buffer |
| product element English | **Low** | naming only |
| Runtime | **Open** | matrix |

---

## 3. Cross-check against raw + bytes + callers

```
// FUN_00735390 (W37-N)
LEA EBX, [ESI+0x70C]
CALL FUN_00465d70

// FUN_00465d70
walk [begin,end) step 0x24; FUN_00481d80(ESI); delete begin; zero

// FUN_00481d80
if [ESI+0x18]: operator_delete; zero +0x18/+0x1c/+0x20
```

Closes W37-N residual “FUN_00465d70 dual open”.

---

## 4. Surviving contract for AutoCore

```
// Port as EBX-this vector tidy (not thiscall):
// begin@+4 end@+8 cap@+0xC; elem stride 0x24
// For each elem: free nested buffer at +0x18 (FUN_00481d80)
// Then operator_delete(begin); zero triple.
// Pair with Palantir elem complete dtor (elem+0x70C).
```

---

## 5. Verdict

**accept** — full body sealed; only residual is product English (non-blocking).
