# Review B (skeptical / adversarial): `aa_00401a40` Std_LengthError_CtorFromString

| Field | Value |
|---|---|
| **Stable ID** | `aa_00401a40` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00401a40_Std_LengthError_CtorFromString.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Auth-server specific helper | 50+ callers incl. vector/map “too long”; RTTI length_error | **Falsified Auth misname** |
| 2 | `std::runtime_error` | RTTI string is **`length_error`**, not runtime_error | **Falsified** |
| 3 | Full ctor body embeds string here | String copy is in base **`FUN_00401aa0`** at `this+0xc` | **Clarify** — this unit only vtbl-specialize after base |
| 4 | `__cdecl` / no stack cleanup | Epilogue **`RET 4`** + ECX this | **thiscall** |
| 5 | Throws inside this function | No `_CxxThrowException` in body; parents throw | **Ctor only** |
| 6 | Same type as `FUN_00401aa0` | Base sets `009c7628`; this overwrites `009c7634` | **Derived length_error** |
| 7 | Copy ctor | `FUN_00401970` is sibling; this takes string* from stack after ECX this | **From-string ctor** |
| 8 | Object size unknown | CatchableType size field **0x28**; throw sites `local_34[40]` | **0x28 sealed** |
| 9 | Decompiler invented SEH | Bytes match push -1 / FS:[0] / state slots | **No conflict** |
| 10 | Only vector uses it | map/set `"map/set<T> too long"` same ctor+ThrowInfo | **Shared length_error** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| RTTI length_error | **Confirmed** | Wrong exception hierarchy in ports |
| thiscall + RET 4 | **Confirmed** | Stack imbalance |
| Base logic_error then vtbl | **Confirmed** | Missing string what() |
| Not Auth-specific | **Confirmed** | Misleading system tags |
| ThrowInfo DAT_00acc388 pairing | **High** | Wrong catch type |
| Vtable method names | **Low** | Doc only |

---

## 3. Cross-check against raw / bytes

```
raw 2026-07-23 ≡ live decompile 2026-07-29 ≡ clean Std_LengthError_CtorFromString.cpp

6A FF 68 28 C8 9B 00 64 A1 … 64 89 25 …   SEH
8B F1                                      this → ESI
E8 …                                       CALL FUN_00401aa0
C7 06 34 76 9C 00                          MOV [ESI], 009c7634
C2 04 00                                   RET 4

RTTI: 2e 3f 41 56 6c 65 6e 67 74 68 5f 65 72 72 6f 72 40 73 74 64 40 40
      = ".?AVlength_error@std@@"
```

Reject ports that:

- Name this as Auth helper.
- Construct runtime_error / generic exception without length_error type.
- Skip base string embed (what() empty).
- Use cdecl without popping the string arg.

---

## 4. Surviving contract for AutoCore

```csharp
// Retail: std::length_error::length_error(const std::string& msg)
// Managed port: throw new InvalidOperationException / LengthException with message
// when container max-size checks fail (vector/map/set "too long").

sealed class StdLengthError /* : LogicError : Exception */
{
    public StdLengthError(string msg) : base(msg) { }
}

// Call pattern (parents):
//   var ex = new StdLengthError("vector<T> too long");
//   throw ex;   // retail: _CxxThrowException(&ex, &DAT_00acc388)
```

**Port note:** AutoCore C# should **not** reimplement MSVC EH frames; map “too long” guards to managed exceptions with the same plate strings where diagnostics matter.

---

## 5. Verdict

**accept** — adversarial review finds no CF/ABI/type conflict; Auth misname rejected; leaf complete.
