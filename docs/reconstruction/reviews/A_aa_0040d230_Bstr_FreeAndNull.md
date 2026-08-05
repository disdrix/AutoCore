# Review A (reconstruction fidelity): `aa_0040d230` Bstr_FreeAndNull

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040d230` |
| **VA** | `0x0040d230` |
| **Canonical name** | `Bstr_FreeAndNull` (structural) |
| **Ghidra name** | `FUN_0040d230` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_0040d230_Bstr_FreeAndNull.md` |
| **System** | OLE/COM string hygiene (XML / NDUI / mission) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Free a BSTR slot and null it** — two-instruction contract:

1. `SysFreeString((BSTR)*slot)`
2. `*slot = 0`

```c
// void __fastcall / __thiscall (ECX = BSTR*)
void FUN_0040d230(undefined4 *param_1)
{
  SysFreeString((BSTR)*param_1);
  *param_1 = 0;
}
```

Bytes (`read_memory` @ `0x0040d230`):

```
mov esi, ecx
mov eax, [esi]
push eax
call [SysFreeString IAT]
mov dword ptr [esi], 0
ret
```

**Extremely hot helper:** MissionDef EnsureXml after each text tag, NDUIWindow_ApplyXmlNodeAttributes (many sites), objective/UseItem serialize residual, map loaders, etc.

Sibling at `0x0040d240` region is free-without-null (separate unit) — this unit **always nulls**.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_0040d230_*`, `reconstructed-exact/FUN_0040d230.cpp` |
| Named alias | `Named_CalleeOf_CVOGObjectiveRequirement_UseItem_SerializeXml_0040d230.cpp` |
| Function record | `functions/aa_0040d230_FUN_0040d230.md` |
| Fresh decompile | Ghidra `decompile_function` @ `0x0040d230` (2026-07-29) |
| Bytes | `read_memory` 32 B — SysFreeString + store 0 |
| Callers | ≥40 xrefs incl. `FUN_00547920`, `FUN_00547050`, `NDUIWindow_ApplyXmlNodeAttributes`, `FUN_004a34f0`, … |
| Parent examples | MissionDef EnsureXml dual; UseItem_SerializeXml dual |

**Not performed:** SysFreeString null-BSTR behavior golden (OLE allows null).

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| ECX holds `BSTR*` / `wchar_t**` slot | **Confirmed** | |
| SysFreeString then write 0 | **Confirmed** | |
| void; no stack args (`ret`) | **Confirmed** | |
| Safe on null BSTR (OLE) | **High** | API contract; not re-tested here |
| Not a general allocator free | **Confirmed** | no `free`/`delete` |
| Product wrapper name | **Open** | structural FreeAndNull sealed |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| SysFreeString(*p) | Yes |
| *p = 0 | Yes |
| return | Yes |

### Recovered CF

```c
void Bstr_FreeAndNull(BSTR* slot) {
  SysFreeString(*slot);
  *slot = nullptr;
}
```

---

## 5. Callers / callees

| Direction | Symbol | Role |
|---|---|---|
| Caller (many) | MissionDef / NDUI / objective XML | clear temporary BSTRs after use |
| Callee | `SysFreeString` (oleaut32) | free |

---

## 6. Gaps / open

1. None material on CF — residual is only product naming / call-graph English.
2. Runtime deferred (not needed for this unit).

**Verdict:** **accept-with-gaps** — CF Confirmed; only English/type alias Open.
