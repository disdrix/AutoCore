# Review A (reconstruction fidelity): `aa_004382c0` Struct_TwoBasicString_DefaultCtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004382c0` |
| **VA** | `0x004382c0` |
| **Body** | `0x004382c0`–`0x00438305` inclusive (**70 B** / `0x46`); pad `CC` |
| **Canonical name** | `Struct_TwoBasicString_DefaultCtor_Inferred` (**Inferred**); Ghidra `FUN_004382c0` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_004382c0_Struct_TwoBasicString_DefaultCtor_Inferred.md` |
| **System** | MSVC basic_string composite default ctor |
| **Live tools** | Ghidra `batch_decompile`, `analyze_function_complete`, `read_memory`, xrefs, `get_assembly_context` (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** — dual-string default ctor CF/ABI sealed; product field English open |
| **Dual status** | **Present (W38-G)** |

---

## 1. Purpose

Default-construct a struct of **two** MSVC `basic_string` members:

| Offset | Role |
|---|---|
| `+0x00` | `basic_string` #0 (sizeof **0x1c**) |
| `+0x1c` | `basic_string` #1 (sizeof **0x1c**) |
| total | **0x38** |

```
SEH register (LAB_009bbfb9)
basic_string_default_ctor(this + 0)
SEH state = 0
basic_string_default_ctor(this + 0x1c)
return this
```

**ABI:** stack **this\***; returns **this** in EAX; **`ret 4`**. **Not** ECX-thiscall (`mov esi, [esp+0x14]` after SEH frame).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Fresh decompile | Ghidra `batch_decompile` `0x004382c0` (2026-08-04) — **≡ raw** |
| Complete analysis | 6 xrefs; 4 caller funcs; callee = basic_string default ctor (IAT) |
| Machine | `read_memory` `0x004382c0` length 70 → body **70 B** ends `c2 04 00` |
| IAT | `[0x009c6288]` -> `0x006eb25c` (string default ctor) used twice |
| Caller context | `sub esp,0x38` + push ESP common; often followed by `FUN_00437e40` (vector resize stride **0x38**) |
| Scaffold | `raw/aa_004382c0_*`, prior clean |

**Not performed:** Launcher, runtime golden, bit-exact image diff, parent ledger edits.

---

## 3. Machine seal (`read_memory`)

| Claim | Evidence | Conf |
|---|---|---|
| Stack this | `8b 74 24 14` (`mov esi, [esp+0x14]`) | **Confirmed** |
| First ctor via IAT | `8b ce; ff 15 88 62 9c 00` | **Confirmed** |
| Second at +0x1c | `8d 4e 1c; ff 15 88 62 9c 00` | **Confirmed** |
| SEH state 0 after first | `c7 44 24 0c 00 00 00 00` between calls | **Confirmed** |
| Return this | `8b c6` | **Confirmed** |
| `ret 4` | `c2 04 00` | **Confirmed** |
| Body 70 B | full dump ends at ret | **Confirmed** |

Full hex (70 B):

```
64a1000000006aff68b9bf9b005064892500000000568b7424148bceff1588629c008d4e1cc744240c00000000ff1588629c008b4c24048bc664890d000000005e83c40cc20400
```

---

## 4. Gaps

- Product struct / field English (name+path vs key+value vs other).
- Whether object has more members beyond 0x38 (callers only need dual string span).
- Runtime / bit-exact / differential.

---

## 5. Verdict

**accept-with-gaps** — dual basic_string default construction, stack ABI, and 0x38 footprint sealed; product naming open.
