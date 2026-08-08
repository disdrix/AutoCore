# Review B (skeptical / adversarial): `aa_00401bc0` Std_OutOfRange_CtorFromString

| Field | Value |
|---|---|
| **Stable ID** | `aa_00401bc0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY WQ9L-B) |
| **Counterpart** | `reviews/A_aa_00401bc0_Std_OutOfRange_CtorFromString.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Skill/RecvSkillStatusEffect-specific helper | **Falsified** — 25 callers across tree erase/insert; RTTI `out_of_range` |
| 2 | `std::length_error` (same family) | **Falsified** — length_error is `00401a40` / vtbl `009c7634` / ThrowInfo `acc388`; this installs `009c7640` / ThrowInfo `acc34c` |
| 3 | `std::runtime_error` / bare `exception` | **Falsified** — RTTI string is **`out_of_range`**; catchable TD points there |
| 4 | Full ctor embeds string here | **Clarify** — string copy is in base **`FUN_00401aa0`** at `this+0xc`; this unit only vtbl-specializes after base |
| 5 | `__cdecl` / no stack cleanup | **Falsified** — epilogue **`RET 4`** + ECX this |
| 6 | Throws inside this function | **Falsified** — no `_CxxThrowException` in body; parents throw |
| 7 | Same type as `FUN_00401aa0` | **Falsified** — base sets `009c7628`; this overwrites `009c7640` |
| 8 | Runtime Confirmed | **Fails** — open (no Launcher) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| RTTI out_of_range | **Confirmed** | Wrong exception hierarchy in ports |
| thiscall + RET 4 | **Confirmed** | Stack imbalance |
| Base logic_error then vtbl | **Confirmed** | Missing string what() |
| Not skill-specific | **Confirmed** | Misleading system tags |
| ThrowInfo DAT_00acc34c pairing | **High** | Wrong catch type |
| Vtable method names | **Low** | Doc only |

---

## 3. Cross-check against raw / bytes

```text
raw 2026-07-23 ≡ live decompile 2026-08-05 ≡ clean Std_OutOfRange_CtorFromString.cpp

6A FF 68 28 C8 9B 00 64 A1 … 64 89 25 …   SEH
8B F1                                      this → ESI
E8 …                                       CALL FUN_00401aa0
C7 06 40 76 9C 00                          MOV [ESI], 009c7640
C2 04 00                                   RET 4

RTTI: ".?AVout_of_range@std@@" @ 0x00af8b98
CatchableType DAT_00acc36c pType → out_of_range; size 0x28
```

Reject ports that:

- Name this as skill/mission helper.
- Construct length_error / runtime_error without out_of_range type.
- Skip base string embed (what() empty).
- Use cdecl without popping the string arg.

---

## 4. Surviving contract for AutoCore

```csharp
// Retail: std::out_of_range::out_of_range(const std::string& msg)
// Managed port: throw ArgumentOutOfRangeException / similar with message
// when map/set iterator is nil ("invalid map/set<T> iterator").

sealed class StdOutOfRange /* : LogicError : Exception */
{
    public StdOutOfRange(string msg) : base(msg) { }
}

// Call pattern (parents):
//   var ex = new StdOutOfRange("invalid map/set<T> iterator");
//   throw ex;  // ThrowInfo DAT_00acc34c
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/RTTI. Low-priority vtable residual only → **accept**.
