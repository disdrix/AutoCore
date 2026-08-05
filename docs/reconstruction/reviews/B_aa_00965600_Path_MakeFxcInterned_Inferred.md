# Review B (skeptical / adversarial): `aa_00965600` Path_MakeFxcInterned_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00965600` |
| **VA** | `0x00965600` |
| **Canonical name** | `Path_MakeFxcInterned_Inferred` (**Inferred**) |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_00965600_Path_MakeFxcInterned_Inferred.md` |
| **System** | Client effects / path → interned string |
| **Live tools** | Independent decompile + `read_memory` + caller context + `FUN_00989e00` decompile |
| **Verdict** | **accept-with-gaps** — accept CF/ABI; reject decompiler 2-arg intern and scaffold product name |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Decompiler `FUN_00989e00(out, c_str)` only | **Falsified** — bytes: `mov ecx, 0x00d1eac8` before call (thiscall mgr) |
| 2 | Signature void / undefined return | **Falsified** — returns `out` in EAX; callers use return / out slot |
| 3 | Three-arg form with `push 1` belonging to this unit | **Falsified** — `push 1` at `0097022e` is for **follow-on** `FUN_00744ea0`; this unit cleans only **8** bytes |
| 4 | Always appends `.fxc` without strip | **Falsified** — `rfind('.')`; found → `substr(0,pos)+.fxc` |
| 5 | Returns full `std::string` by value | **Weakened** — empty path assigns **one dword** handle; intern writes `*out = *node` |
| 6 | Scaffold `Named_CalleeOf_Named_effDeviceEffect_*` | **Rejected** |
| 7 | `param_2` is plain `char*` | **Weakened** — code does `*param_2` as c_str field; treat as path object / `char**` |
| 8 | Empty uses same constant as intern empty | **Open gap** — here `DAT_00d1ed24` vs `FUN_00989e00` empty `DAT_00d1eac0` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| `.fxc` strip/append policy | **High** | Wrong shader path load |
| cdecl 2-arg | **High** | Stack corruption |
| Intern this = `0x00d1eac8` | **High** | Wrong table / crash |
| Empty early handle | **High** | Null vs empty confusion |
| Product English | **None** | Registry pollution |
| Out handle demangle | **Low** | Wrong port type |

---

## 3. Decompiler pitfalls (must survive port)

1. **Missing `this` on `FUN_00989e00`** — always load mgr `0x00d1eac8`.  
2. **Garbled `substr` display** — machine: length = rfind result, start = 0, dest = local temp.  
3. **Do not treat `push 1` at effect-bind site as third arg to this function.**  
4. Scaffold Named_CalleeOf — **ignore**.

---

## 4. What is safe to claim

| Safe | Unsafe |
|---|---|
| Empty → `DAT_00d1ed24`; else build `.fxc` path and intern | Product name of string manager |
| `rfind` / strip-or-append `.fxc` | That out is a full `std::string` object |
| cdecl, return out pointer | Exact equality of empty constants across helpers |
| Used by effect-slot bind debug notify | Full FX pipeline ownership |

---

## 5. CF challenge of Review A

- Empty / no-dot / strip-ext / intern: **agree Confirmed**  
- Decompiler missing this: **agree falsified**  
- Product gaps remain: **agree accept-with-gaps**  

**Verdict:** **accept-with-gaps**
