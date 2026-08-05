# Review B (skeptical / adversarial): `aa_00735390` PalantirSub10_OwnedElem_CompleteDtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00735390` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY W37-N) |
| **Counterpart** | `reviews/A_aa_00735390_PalantirSub10_OwnedElem_CompleteDtor_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Thiscall complete dtor (ECX=this) | **Falsified** — stack load of ESI; **`RET 4`** |
| 2 | Also frees the element | **Falsified** — no `operator_delete` in body; parent deletes after call |
| 3 | `FUN_00465d70` is argless global | **Weakened** — decompile bare call, but **LEA EBX,[ESI+0x70C]** + callee `unaff_EBX` seal EBX-this |
| 4 | Only one string member | **Falsified** — dtor at +0x1C then +0 |
| 5 | COM slot is not released | **Falsified** — null-checked vtbl+8 Release + zero |
| 6 | Product plate `PalantirElem` without evidence | **Rejected** — kept **Inferred** structural name from sole Palantir+0x10 consumer |
| 7 | Multiple callers | **Falsified** — single xref `0x00964d37` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| stdcall RET 4 void | **High** | ABI crash |
| COM@+0x48 + two strings | **High** | leak / double-free |
| EBX vec@+0x70C | **High** | wrong subobject tidy |
| product class English | **Low** | naming only |
| Runtime | **Open** | matrix |

---

## 3. Cross-check against raw + bytes + callers

```
// FUN_00964d00 (W35-J)
for each non-null elem in vec:
  PUSH elem; CALL FUN_00735390
  PUSH elem; CALL operator_delete

// FUN_00735390
Release([elem+0x48]); FUN_00465d70(EBX=elem+0x70C); ~str(+0x1c); ~str(+0); RET 4

// FUN_00465d70
walk [begin,end) stride 0x24; FUN_00481d80 each; operator_delete(begin)
```

Closes W35-J residual “element product dual open”.

---

## 4. Surviving contract for AutoCore

```
// Port as stdcall complete dtor for Palantir+0x10 owned elements:
void __stdcall PalantirSub10_OwnedElem_CompleteDtor(void* elem) {
  Release_COM_if(elem+0x48);
  Tidy_Vec24_at(elem+0x70C);  // FUN_00465d70 EBX-this
  destroy string at +0x1C;
  destroy string at +0;
}
// Do NOT free elem here. Do NOT use thiscall. Pair with parent delete + CoUninitialize path.
```

---

## 5. Verdict

**accept-with-gaps** — ABI/layout/CF sealed; product English open.
