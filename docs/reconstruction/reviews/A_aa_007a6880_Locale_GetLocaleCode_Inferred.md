# Review A (reconstruction fidelity): `aa_007a6880` Locale_GetLocaleCode_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007a6880` |
| **VA** | `0x007a6880`–`0x007a6882` (3 B) |
| **Canonical name** | `Locale_GetLocaleCode_Inferred` (was `FUN_007a6880`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_007a6880_Locale_GetLocaleCode_Inferred.md` |
| **System** | locale / string-table (cross-cutting UI + chat) |
| **Verdict** | **accept** on CF / offset / ECX ABI; product name **Inferred** |
| **Dual status** | **Present (first full dual)** |

---

## 1. Purpose

**Leaf getter**: return the **locale code** dword at **`this+0x2c`** for the locale string-table object.

```
mov eax, [ecx+0x2c]
ret
```

Default after ctor: **0** (English / base). Consumers map 1/2/3 → fr/de/uk path suffixes (see GetInstance dual / `NDUIWindow_LoadInterfaceFile` notes). Localize path `FUN_007a6de0` also reads `*(this+0x2c)` when mode arg is **−1**.

Does **not** construct the singleton, free buffers, or translate strings.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Function record / raw / annotated / clean | `aa_007a6880_*`, `FUN_007a6880.cpp` |
| Live decompile | Ghidra `batch_decompile` `0x007a6880` |
| Live body bytes | `read_memory` `0x007a6880` length 16 → `8b 41 2c c3` |
| Callers | `FUN_00516720`, `FUN_0057b350`, `FUN_00583fa0` (+ others may load `+0x2c` inline) |
| Sibling duals | GetInstance, ctor, dtor (this batch / prior) |

**Not performed:** runtime locale switch capture; bit-exact; Launcher.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body = load `[ecx+0x2c]` + ret | **Confirmed** | bytes `8b412cc3` |
| ECX = locale object this | **Confirmed** | thiscall/fastcall leaf |
| Return = locale code int | **High** | ctor default 0; consumer path codes |
| Leaf purity | **Confirmed** | no callees |
| Not dtor / not GetInstance | **Confirmed** | size + CF |
| Product name | **Open / Inferred** | |
| Clean ≡ raw ≡ live | **Confirmed** | |

---

## 4. Control flow / assembly

```
007a6880  8b412c          mov  eax, [ecx+0x2c]
007a6883  c3              ret
```

Hex: `8b412cc3`  
Padding: `cc` through next function.

### Recovered CF

```c
// __fastcall / thiscall
int __fastcall Locale_GetLocaleCode_Inferred(const LocaleStringTable *this)
{
    return *(int *)((const char *)this + 0x2c);
}
```

---

## 5. Callers (context only)

| Caller | Role (caller-owned) |
|---|---|
| `FUN_00516720` | After `FUN_007a69d0`, uses code with string path helper |
| `FUN_0057b350` / `FUN_00583fa0` | Same pattern family |

Scaffold `Named_CalleeOf_…_CVOGCreature_PostCreateFromPacket_*` is a **parent seed**, not exclusive ownership.

---

## 6. Gaps

1. Product method name.
2. Full enum documentation of all legal codes beyond 0–3 (consumers cite 0/1/2/3).
3. Whether some sites bypass this leaf and load `+0x2c` inline (yes possible; dual owns this VA only).

**Verdict:** **accept** — sealed 3-byte leaf, ECX this, `+0x2c` locale code return.
