# Review B (skeptical / adversarial): `aa_004c5510` Object_ApplyPrimaryAndLocalMaterialBanks_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c5510` |
| **VA** | `0x004c5510` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (R10-029) |
| **Counterpart** | `reviews/A_aa_004c5510_Object_ApplyPrimaryAndLocalMaterialBanks_Inferred.md` |
| **Tools** | decompile + analyze_function_complete + disassemble_function + read_memory + xrefs/callers + assembly context (no Launcher, no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is a skill-bank / ability cast helper (R10 skills-abilities label) | Partition parent is residual skill wave; callees are Mat* bind path | **Falsified as product domain** — only material apply/bind; no skill id / cast |
| 2 | Decompiler `FUN_0051b310()` means zero-arg free call on unchanged ECX | Assembly rewrites ECX from `this-0x4FC` table before CALL | **Falsified** — **bytes win**; primary this-adjust required |
| 3 | `param_1` is SharedBase / full object origin | Negative field offsets + JMP adjustors with `SUB ECX,0x8A0` / vbtable | **Falsified** — ECX is **MI subobject** this |
| 4 | Sole bank path is local `-0x20C` | Always calls `0051b310` first | **Falsified as single-path** — dual apply |
| 5 | Stack formals / returns value | Bare `C3`; PUSH/POP ECX only | **Falsified** — void thiscall |
| 6 | Ghidra "no callers" means dead code | Two UNCONDITIONAL JMP xrefs from adjustor islands | **Falsified as dead** — virtual MI entry |
| 7 | Arg order to `005194f0` is (bank, host) | PUSH EAX (header) then PUSH EDX (host) before CALL → cdecl right-to-left → `(host, header)` | **Sealed** matches dualed binder contract |
| 8 | Product demangle known | No RTTI/string on this VA | **Open** — keep `_Inferred` |
| 9 | Clean may invent shader writes here | Body only gates + two callees | **Falsified as invention** — writes live in dualed callees |

---

## 2. Surviving contract

```
void Object_ApplyPrimaryAndLocalMaterialBanks_Inferred(void* subThis /* ECX */)
  primary = (subThis - 0x4FC) + *(int32*)(*(void**)(subThis - 0x4FC) + 4)
  Object_ApplyMaterialBank_Inferred(primary)          // FUN_0051b310
  host = *(void**)(subThis - 0x27C)
  if !host: return
  begin = *(void**)(subThis - 0x208); header = subThis - 0x20C
  if !begin: return
  if ((*(void**)(header+8) - begin) >> 4 == 0): return
  Gfx_BindMatDiffuseAmbientEmissive_Inferred(host, header)  // FUN_005194f0
```

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall void + bare RET | **High** | Stack/return corruption |
| Path A primary rewrite offsets | **High** | Apply bank on wrong object |
| Path B host/bank gates + stride 0x10 | **High** | Spurious bind or skip |
| Arg order to binder | **High** | Swapped host/colors |
| MI adjustor entry model | **High** | Miss polymorphic entry |
| Product class English | **Open** | Naming only |
| vbtable vs custom base table | **Tentative** | Port base cast helper shape |
| Runtime | **Open** | |

---

## 4. Naming attack

| Proposed | Status |
|---|---|
| `Object_ApplyPrimaryAndLocalMaterialBanks_Inferred` | **Accept INFERRED** — dual path + dualed Mat* callees |
| permanent bare `FUN_004c5510` | **Reject** as final name |
| `Skill_*` / cast helper | **Reject** — no skill operands |
| `Object_ApplyMaterialBank_Inferred` (merge with `0051b310`) | **Reject** — different VA; orchestrates primary+local |

---

## 5. Cross-check against dualed siblings

| Sibling | Link |
|---|---|
| `aa_0051b310` Object_ApplyMaterialBank_Inferred | Sole code CALL from this body @ `0x004c5524`; review lists this VA as caller |
| `aa_005194f0` Gfx_BindMatDiffuseAmbientEmissive_Inferred | Direct CALL @ `0x004c5553`; review lists this VA as caller; bank header+4/+8 contract matches |

---

## 6. Verdict

**accept-with-gaps** — adversarial review confirms dual-path material apply on MI subobject; skill-domain and decompiler-no-adjust claims falsified; product type open.
