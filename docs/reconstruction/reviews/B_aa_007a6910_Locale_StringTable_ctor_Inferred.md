# Review B (skeptical / adversarial): `Locale_StringTable_ctor_Inferred` / `FUN_007a6910` @ `0x007a6910`

| Field | Value |
|---|---|
| **Stable ID** | `aa_007a6910` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_007a6910_Locale_StringTable_ctor_Inferred.md` |
| **Verdict** | **accept** on CF/layout; reject VOG-parser / localize / thiscall overclaims |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Parses VOG.ini / AUTHSERVERIP | **Falsified** — no file IO; LoadVogIni only may call getter |
| 2 | Localizes English→other languages | **Falsified** — only alloc/zero; localize is `007a6de0` |
| 3 | ECX thiscall ctor | **Falsified** — stack formal `mov ebp,[esp+…]`; singleton pushes address |
| 4 | Sets locale code from OS | **Falsified** — hard store **0** |
| 5 | Ring count ≠ 10 | **Falsified** — loop counter 10; localize wraps at 10 |
| 6 | Buffer size ≠ `0x100` | **Falsified** — `push 0x100` / store cap `0x100` |
| 7 | atexit registered here | **Falsified** — atexit is in GetInstance cold path |
| 8 | Product class name sealed | **Open** — `_Inferred` |
| 9 | Exclusive LoadVogIni helper | **Over-narrow** — process singleton + second caller |
| 10 | Runtime / bit-exact | **Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Vtable / dtor linkage | **Confirmed** | Wrong free path on exit |
| 10×0x100 ring | **Confirmed** | Localize OOB / wrong wrap |
| `+0x2c` default 0 | **Confirmed** | Wrong language path at boot |
| `+0xc0` ring index 0 | **Confirmed** | Stale ring cursor |
| Stack-this ABI | **Confirmed** | Wrong CC crash |
| Product name | **Low–Medium** | Docs only |
| Full pack-table field names | **Medium** | Port incomplete packs |

---

## 3. Surviving contract for AutoCore

```
// placement / pointer ctor — returns this
LocaleStringTable* ctor(LocaleStringTable* self):
  self.vfptr = kVtable_00a96f88
  self.localeCode = 0
  self.ringIndex = 0
  self.flag_0xbc = 1
  self.delim_0xc4 = ','
  for i in 0..9:
    self.ringCap[i] = 0x100
    self.ringBuf[i] = zeroed new byte[0x100]
  clear language-pack pointer tables (5 groups)
  return self

// NOT: LoadVogIni, GetInstance once-flag, Localize, file chat log
```

---

## 4. Falsification notes

### 4.1 Scaffold `Named_CalleeOf_Client_LoadVogIniConfig`

Parent seed only. Primary production path is **GetInstance** cold construct of `DAT_00d1f660`.

### 4.2 Confusing with GetInstance

Ctor has **no** once-flag and **no** atexit. Ports that put once-flag here double-init incorrectly if ctor is also used for non-singleton (`008cd200`).

### 4.3 Vtable first entry

`0x00a96f88` → `0x00424810` → calls dtor `007a6890` then optional `operator_delete` — confirms class identity with cleanup dual.

---

## 5. Open questions

1. Product class name.
2. Whether `008cd200` heap-allocates a second instance.
3. Exact fill of language packs after ctor — other VAs.

**Verdict:** **accept**. Sealed init layout and ring construction. Reject VOG/localize identity and ECX-thiscall misread.
