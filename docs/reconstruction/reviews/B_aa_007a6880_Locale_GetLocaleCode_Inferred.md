# Review B (skeptical / adversarial): `Locale_GetLocaleCode_Inferred` / `FUN_007a6880` @ `0x007a6880`

| Field | Value |
|---|---|
| **Stable ID** | `aa_007a6880` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_007a6880_Locale_GetLocaleCode_Inferred.md` |
| **Verdict** | **accept** — reject dtor/GetInstance/pointer-return conflations |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Returns singleton object pointer | **Falsified** — loads dword field; GetInstance returns `&DAT_00d1f660` |
| 2 | This is the dtor (`007a6890`) | **Falsified** — 3-byte load vs free loops |
| 3 | Stack formal this | **Falsified** — **ECX** only (`8b 41 2c`) |
| 4 | Offset is `+0x2c` vs something else | **Attack fails** — imm8 `0x2c` sealed |
| 5 | Constructs / atexit | **Falsified** — leaf |
| 6 | Always English (0) | **Overstated** — returns **stored** code; ctor defaults 0 but setters elsewhere can change it |
| 7 | Product enum complete | **Open** beyond observed 0–3 |
| 8 | Exclusive PostCreateFromPacket | **Falsified** as exclusive — multiple callers |
| 9 | Runtime verified | **Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Bytes / offset | **Confirmed** | Wrong language branch |
| ECX this | **Confirmed** | Crash / garbage |
| Semantic = locale code | **High** | Treat as pointer → wild branches |
| Product name | **Open** | Docs |
| Exhaustive code enum | **Medium** | Miss rare codes |

---

## 3. Surviving contract for AutoCore

```
// thiscall ECX = LocaleStringTable*
int GetLocaleCode(const LocaleStringTable* self) {
  return self->localeCode; // +0x2c
}

// Typical use:
//   auto* loc = Locale_GetInstance(); // 007a69d0
//   int code = GetLocaleCode(loc);    // 007a6880  OR  *(int*)(loc+0x2c)
//
// NOT GetInstance. NOT dtor. NOT Localize.
```

---

## 4. Falsification notes

### 4.1 Address neighbor confusion

| VA | Role |
|---|---|
| `007a6880` | **this leaf** — get code |
| `007a6890` | dtor free |
| `007a6910` | ctor |
| `007a69d0` | GetInstance |

Off-by-one naming is the primary documentation risk.

### 4.2 “Always 0”

Ctor sets 0; this leaf **returns current storage**. Ports that hardcode 0 instead of reading break language packs after a set-locale call (setter not owned here).

### 4.3 Scaffold creature alias

`Named_CalleeOf_…_CVOGCreature_PostCreateFromPacket_*` is seed noise for this leaf.

---

## 5. Open questions

1. Product name / full locale enum.
2. Setter VA for `+0x2c` (not this unit).
3. Whether all consumers prefer leaf vs inline load.

**Verdict:** **accept**. Sealed leaf. Reject pointer-return / dtor / GetInstance overclaims.
