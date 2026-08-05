# Review B (skeptical / adversarial): `aa_00403450` MbcsString_ConvertFromWide

| Field | Value |
|---|---|
| **Stable ID** | `aa_00403450` |
| **VA** | `0x00403450` |
| **Canonical name** | `MbcsString_ConvertFromWide` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00403450_MbcsString_ConvertFromWide.md` |
| **System** | string / locale / MBCS owned-string |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is only a thin `WideCharToMultiByte` wrapper with no object policy | Body also nulls `*this`, heap-gates at 0x80, throws | **Partial** — API + object store policy |
| 2 | Always allocates | Only when `size > 0x80` | **Falsified** always-malloc |
| 3 | Frees previous heap `*this` before rebinding | No free/delete | **Falsified** free-on-convert |
| 4 | Uses fixed CP 1252 | CP is stack arg (`param_3`) | **Falsified** fixed-CP |
| 5 | Returns converted `char*` | void; payload at `*this` | **Falsified** char*-return |
| 6 | Size is character count for MultiByte | `size=(cch+1)*2` used as **byte** buffer budget / `cbMultiByte` | **Survives** as binary policy (not “char count”) |
| 7 | Scaffold invents CF | Live ≡ raw ≡ clean; `ret 8` sealed | **Attack fails** |
| 8 | Domain-specific connection-terminated only | 30+ callers incl. terrain/mission UI | **Falsified** — shared util |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ABI thiscall + ret 8 | **Confirmed** | Wrong stack / crash |
| Heap threshold 0x80 | **Confirmed** | Buffer overflow / leak models |
| Null-wide clears pointer | **Confirmed** | Stale pointer use |
| Throw on OOM / convert fail | **Confirmed** | Silent fail ports |
| No free of prior | **High** | Double-free if port adds free wrongly |
| Product type name | **Open** | |

---

## 3. Cross-check against raw / live / bytes

```
push ebx
push ebp
mov  ebp, [esp+0x0C]     ; wide
test ebp, ebp
mov  ebx, ecx            ; this
jnz  have_wide
mov  [ebx], ebp          ; *this = 0
pop  ebp
pop  ebx
ret  8

; lstrlenW(wide) → esi = len+1; edi = esi*2
cmp  edi, 0x80
jle  no_malloc
push edi
call [malloc]
...
mov  [ebx], eax
jz   throw_E_OUTOFMEMORY   ; push 0x8007000E; call FUN_004048e0

no_malloc:
; WideCharToMultiByte(cp, 0, wide, len+1, *this, size, 0, 0)
test eax, eax
jnz  done
call FUN_004048c0
done:
pop  edi / esi / ebp / ebx
ret  8
```

### Consume trap (with `00402d50`)

Wrapper returns **object**; payload is `*(char**)obj`. This unit returns **void**. Do not treat either return as “the MBCS char*” without dereference.

### Lifetime trap

Large path overwrites `*this` without freeing old heap. Safe when caller just bound inline (`00402d50`) or object is fresh. Unsafe if port reuses live heap object without free.

### Size trap

`cbMultiByte = (wchar_len+1)*2` is a **binary estimate**, not a general max expansion for all code pages. Port must match this budget, not invent `WideCharToMultiByte` query-size first pass unless proven elsewhere.

---

## 4. Surviving contract for AutoCore

```
MbcsString_ConvertFromWide(self, wide, cp):
  if wide == null:
    self.pData = null
    return
  size = (lstrlenW(wide)+1)*2
  if size > 0x80:
    self.pData = malloc(size) or throw E_OUTOFMEMORY
  // else: write into existing self.pData (must be valid buffer ≥ size)
  if WideCharToMultiByte fails: throw last-error HRESULT

AutoCore must NOT:
  - free prior pData inside this VA
  - assume CP 1252
  - treat return value as char* (void)
  - skip SSO bind on small path
```

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| thiscall; wide+cp; ret 8 | **Agree Confirmed** |
| Heap iff size > 0x80 | **Agree Confirmed** |
| Throw OOM / convert fail | **Agree Confirmed** |
| No free of prior | **Agree High** |
| Product name Open | **Agree** |
| accept-with-gaps | **Agree** |

---

## 6. Open questions

1. Product class name.
2. Full free/dtor ownership elsewhere.
3. Runtime.

**Verdict:** **accept-with-gaps** — agree with A; block free-on-convert, fixed-CP, and char*-return mistakes.
