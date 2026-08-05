# Review B (skeptical / adversarial): `aa_007a69d0` Locale_GetInstance_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007a69d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_007a69d0_Locale_GetInstance_Inferred.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only on **own VA** (+ minimal atexit/dtor bytes for thunk seal). No ledger edits.

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Function **prints** UI/chat strings (args like `"You need…"`) | Body has **zero** string loads; `parameters: []`; plain `RET` | **Falsified** — getter only; string args are sibling `FUN_007a6de0` / toast `FUN_007fdfb0` |
| 2 | `__stdcall` / `__thiscall` with ECX this | No ECX use as this; returns **address of static**, not methods on caller this | **Falsified** — **cdecl void→ptr** |
| 3 | Re-constructs object every call | Once-flag `DAT_00d1f728&1`; cold path only runs ctor+atexit | **Falsified** — Meyers once-init |
| 4 | Returns locale **code** (int 0/1/2/3) | `MOV EAX, imm32 0x00d1f660` always | **Falsified** — returns **object\***; code is `*(obj+0x2c)` via `FUN_007a6880` or direct load |
| 5 | Same role as `FUN_007a6de0` | 6de0 is large thiscall with switch on locale; 69d0 is 90 B getter | **Falsified** — distinct units |
| 6 | atexit points at GetLocale (`0x007a6880`) | Thunk `MOV ECX,&obj; JMP` → **`0x007a6890` dtor** (not `+0x2c` leaf at `6880`) | **Clarify** — dtor free, not locale read |
| 7 | Once-flag is full dword equality | Bytes: `TEST …, AL` / `OR …, EAX` with `EAX=1` → **bit0 only** | **Sealed bit0**; other bits of `DAT_00d1f728` unused here |
| 8 | Object lives at `DAT_00d1f728` | Flag and object are adjacent: object `0x00d1f660`, flag `0x00d1f728` | **Falsified if conflated** |
| 9 | Scaffold name `Named_CalleeOf_Client_LoadVogIniConfig` is exclusive role | 538 xrefs across chat/auth/inventory/skills/UI | **Over-narrow** — LoadVogIni is one caller among many |
| 10 | Decompiler SEH locals change return | Epilogue always loads imm `&DAT_00d1f660` into EAX | **No** — SEH frame only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Singleton address `DAT_00d1f660` | **High** | Ports allocate per-call → leak / lost locale packs |
| Once-flag bit0 @ `DAT_00d1f728` | **High** | Double ctor / double atexit |
| No string side effects in body | **High** | Ports invent toast inside getter |
| Return is pointer not int | **High** | Callers use EAX as code → wrong branch |
| Locale code at `obj+0x2c` (consumer) | **High** for read sites | Mis-align interface path / PAK select |
| Product class name | **Low–Medium** | Doc only (`_Inferred`) |
| Thread-safe init | **None claimed** | Dual init race if multi-thread early boot |

---

## 3. Cross-check against raw / bytes

```
raw decompile:
  if ((DAT_00d1f728 & 1) == 0) {
    DAT_00d1f728 |= 1;
    FUN_007a6910(&DAT_00d1f660);
    atexit(LAB_009c30b0);
  }
  return &DAT_00d1f660;

bytes:
  TEST [00d1f728], 1 ; JNZ skip
  OR   [00d1f728], 1
  CALL 007a6910(&00d1f660)
  CALL atexit(009c30b0)
  MOV  EAX, 00d1f660 ; RET
```

Clean must **not** invent:

- Message formatting / `sprintf` / chat UI
- Stack string parameters
- Returning `*(obj+0x2c)` instead of `obj`
- Re-init without the flag

Prior reconstructed-exact call sites that pass English literals **into** `FUN_007a69d0(...)` are **caller-plate errors**, not this body’s ABI.

---

## 4. Surviving contract for AutoCore

```csharp
// Behavior-exact port of 0x007a69d0
static LocaleStringTable g_locale;          // DAT_00d1f660, size 0xC8
static int g_localeOnce;                   // DAT_00d1f728 — use bit0 only

static LocaleStringTable* Locale_GetInstance()
{
    if ((g_localeOnce & 1) == 0)
    {
        g_localeOnce |= 1;
        LocaleStringTable_Ctor(&g_locale);  // FUN_007a6910
        // register process exit: LocaleStringTable_Dtor(&g_locale) // FUN_007a6890
    }
    return &g_locale;
}

// Callers:
//   var loc = Locale_GetInstance();
//   int code = *(int*)(loc + 0x2c);           // or FUN_007a6880
//   char* s  = Locale_Localize(loc, key, -1); // FUN_007a6de0 — SEPARATE
```

**Port traps to reject:**

- Implementing as “show message box / chat line.”
- Passing `const char*` into this function.
- Treating return as locale enum.
- Constructing a **new** table per call (breaks shared ring buffers + packs).
- Clearing once-flag on logout without matching retail (no evidence in this unit).

---

## 5. Residual gaps (do not block seal)

1. English product name for the class / getter.
2. Full dtor/ctor field duals (`aa_007a6910`, `aa_007a6890`) — separate OWN VAs.
3. Whether `DAT_00d1f728` high bits are used by any other unit.
4. Runtime live hit / bit-exact image.
5. Full 538-caller matrix.

---

## Verdict

**accept** — adversarial review cannot break the Meyers getter kernel. Main falsifications: “message printer with string args,” “returns locale int,” and “re-inits every call.” Name remains **`_Inferred`** until product symbol evidence.
