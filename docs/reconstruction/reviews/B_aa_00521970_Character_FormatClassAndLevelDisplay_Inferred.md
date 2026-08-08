# Review B (skeptical / adversarial): `aa_00521970` Character_FormatClassAndLevelDisplay_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00521970` |
| **VA** | `0x00521970` |
| **Canonical name** | `Character_FormatClassAndLevelDisplay_Inferred` (**Inferred**) |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_00521970_Character_FormatClassAndLevelDisplay_Inferred.md` |
| **System** | skills-abilities / character display |
| **Live tools** | Independent decompile + `read_memory` + callee decompiles + xref sweeps |
| **Verdict** | **accept-with-gaps** — accept formatter CF/ABI; reject 3-arg lookup, char\* return, product-English-as-sealed, invent-callers |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | `FUN_0051f940` takes 3 args (`…, 0xffffffff`) | **Falsified** — `add esp,8` after call; `-1` is `FUN_007a6de0` length |
| 2 | Function returns `char*` (like `00521900`) | **Falsified** — both exits `sprintf` into stack arg then `RET 4`; void buffer writer |
| 3 | Args are (race, class) not (class, race) | **Falsified** — push class (from `+0x531`) then race (`+0x532`); leaf switches on first as class family |
| 4 | Always includes level | **Falsified** — `jl` path formats `"%s"` only when level vcall < 0 |
| 5 | Self-contained class string table | **Falsified** — only calls dualed leaf; no embedded class strings here |
| 6 | Product/PDB method name known | **Rejected** — role Inferred only; no plate string in body |
| 7 | Direct callers sealed | **Open** — live Ghidra 0 xrefs; pattern scan empty; do not invent |
| 8 | First `FUN_007a69d0()` is dead / ignored | **Falsified** — result kept in EBX as ECX for `"Level"` ring |
| 9 | Same as `Character_GetClassDisplayName_Inferred` | **Falsified** — sibling returns ring `char*`; this sprintf-formats into out buffer with optional level |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Formatter CF / formats / `"Level"` | **High** | Wrong UI label shape |
| ECX-this + `RET 4` out buffer | **High** | Stack imbalance / wrong ABI |
| 2-arg cdecl to `0051f940` | **High** | Wrong class names / stack |
| Class English content | **High** (parent dual leaf) | Mislabel class |
| Product method English | **None** | Overclaim |
| Call sites | **None sealed** | Dead-code or indirect-only residual |

---

## 3. Decompiler pitfalls (must survive port)

1. Strip the phantom third arg to `FUN_0051f940`.
2. Keep argument order **(classId, raceId)**.
3. Preserve **out-buffer sprintf** ABI (`RET 4`); do not port as `char*` return.
4. Keep first TLS pointer for `"Level"` localization (EBX).
5. Do not free ring pointers or assume durable heap strings.
6. Do not invent callers; gap remains open.

---

## 4. What is safe to claim

| Safe | Unsafe |
|---|---|
| thiscall void buffer formatter with optional level | PDB/product method English |
| blob+0x531 class / +0x532 race + leaf lookup | Sealed direct call graph |
| Formats `"%s, %s %i"` / `"%s"` + product `"Level"` | Level vcall product English beyond slot `+0x27c` |
| Role name with `_Inferred` | Claiming dual ownership of class table body (owned by `0051f940`) |

---

## 5. CF challenge of Review A

- Nested path + dual byte loads + level branch: **agree Confirmed**
- cdecl 2-arg + ring + sprintf formats: **agree Confirmed**
- `RET 4` void out-buffer: **agree Confirmed**
- Class table as parent-dual evidence (not re-owned): **agree**
- accept-with-gaps for callers + product English: **agree**

**Verdict:** **accept-with-gaps**
