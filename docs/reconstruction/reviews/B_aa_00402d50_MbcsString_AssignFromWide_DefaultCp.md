# Review B (skeptical / adversarial): `aa_00402d50` MbcsString_AssignFromWide_DefaultCp

| Field | Value |
|---|---|
| **Stable ID** | `aa_00402d50` |
| **VA** | `0x00402d50` |
| **Canonical name** | `MbcsString_AssignFromWide_DefaultCp` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00402d50_MbcsString_AssignFromWide_DefaultCp.md` |
| **System** | string / locale / mission UI text |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This **is** `WideCharToMultiByte` | Only thunks into `FUN_00403450` which calls it | **Partial** — unit is object-init + convert, not raw API |
| 2 | Frees previous string | No free/delete in body | **Falsified** free-on-assign |
| 3 | Uses fixed CP 1252 | Calls dynamic `PTR_FUN_00af8c9c` (locale/ACP) | **Falsified** fixed-1252 |
| 4 | Returns converted `char*` only | Returns **this**; data at `*this` | **Falsified** raw-char*-return |
| 5 | Decompiler `FUN_00403450(param_2,uVar1)` shows full args | Missing thiscall `this=ESI` in display | **Noise** — bytes seal 3-arg thiscall |
| 6 | Scaffold invents CF | Live ≡ clean | **Attack fails** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Inline bind `*this=this+4` | **Confirmed** | Wrong SSO |
| Default CP thunk | **Confirmed** | Wrong encoding |
| Convert callee 00403450 | **Confirmed** | Miss heap path |
| Returns this | **Confirmed** | Wrong consume |
| No free of prior | **High** | Leaks if misused on live heap obj |
| Product type name | **Open** | |

---

## 3. Cross-check against raw / live / bytes

```
push esi
mov esi, ecx
lea eax, [esi+4]
mov [esi], eax
call dword ptr [00af8c9c]   ; cp
mov ecx, [esp+8]            ; wide
push eax                    ; cp
push ecx                    ; wide
mov ecx, esi
call FUN_00403450
mov eax, esi
pop esi
ret 4
```

`PTR_FUN_00af8c9c` initially points at `FUN_00404930` which may swap itself for a fast path; fallback `FUN_00404980` uses `GetLocaleInfoA` / `GetACP`.

### Consume trap

Callers use `*FUN_00402d50(wide)` as `char*`. Returning object pointer ≠ returning payload; payload is `*(char**)this` after convert.

### Lifetime trap

Stack objects with inline 0x80-class buffer: free only if `pData != inline` (see UpdateMissionJournal `local_90 != local_8c`). This unit does not free.

---

## 4. Surviving contract for AutoCore

```
MbcsString* MbcsString_AssignFromWide_DefaultCp(self, wide):
  self->p = &self->inline[0]
  cp = DefaultCodePageThunk()
  ConvertWideToMbcs(self, wide, cp)  // may malloc if >0x80
  return self

// typical use:
//   MbcsString tmp; AssignFromWide(&tmp, bstr); use *tmp.p; free if heap

AutoCore must NOT:
  - treat return as char* payload
  - assume CP 1252 always
  - expect this unit to free previous heap pData
```

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| Inline bind + CP + 00403450 | **Agree Confirmed** |
| Returns this | **Agree Confirmed** |
| No free | **Agree High** |
| accept-with-gaps | **Agree** |

---

## 6. Open questions

1. Dual `FUN_00403450` SSO layout.
2. Product class name.
3. Runtime.

**Verdict:** **accept-with-gaps** — agree with A; block free-on-assign and char*-return mistakes.
