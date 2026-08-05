# Review B (skeptical / adversarial): `aa_0074e310` LightMgr_ListRegister_PushBack_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0074e310` |
| **VA** | `0x0074e310` |
| **Canonical name** | `LightMgr_ListRegister_PushBack_Inferred` (**Inferred**) |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_0074e310_LightMgr_ListRegister_PushBack_Inferred.md` |
| **System** | Palantir light / effect-list manager |
| **Live tools** | Independent decompile + `read_memory` + peer `0074e0d0`/`0074e260` + caller assembly |
| **Verdict** | **accept-with-gaps** — accept append+bind CF; reject replace-only / no-grow / void-ABI / scaffold name claims |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Decompiler is complete (`FUN_00449440()` no args, no size math) | **Falsified as complete** — bytes compute `size+1` and pass `edx=host+4`; helper resizes vector |
| 2 | Replace-last without append | **Falsified** — resize to size+1 then write `end-4` = new element |
| 3 | Same as `0074e0d0` single-slot setter | **Falsified** — vector push + `vtbl[+0x30]` bind; slot is `+0x3c` only on peer |
| 4 | `ret` / void no stack cleanup | **Falsified** — `C2 04 00` (**ret 4**) |
| 5 | begin/end at `this+4`/`this+8` | **Falsified** — begin@+8 end@+0xC (matches unregister `0074e260`) |
| 6 | Null `obj` is supported end-to-end | **Unsafe** — AddRef gated, but bind `vtbl[+0x30]` has no null guard |
| 7 | Scaffold `Named_CalleeOf_…VOG_DEBUG_STOP…` is product | **Rejected** — parent-seed noise |
| 8 | “LightMgr” is demangled product | **Open** — structural family name only; keep `_Inferred` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| size `>>2` + resize size+1 | **High** | Wrong container math |
| Refcount +4 / vtbl+4/+8 | **High** | UAF / leak |
| Bind vtbl+0x30(*host) | **High** | Miss registration side-effect |
| `ret 4` / one stack arg | **High** | Stack imbalance |
| begin@+8 end@+0xC | **High** | Wrong host layout |
| Product class English | **None** | Registry pollution |
| Null-obj production path | **Low** | Crash if invented |

---

## 3. Decompiler pitfalls (must survive port)

1. **Missing grow math** — always recover `size+1` + `FUN_00449440` from bytes.
2. **Missing this** — callers `mov ecx,[env+4]` then push core.
3. Do **not** merge with `0074e0d0` (slot) or `0074e260` (unregister scan/erase).
4. Scaffold VOG_DEBUG name — **ignore**.

---

## 4. What is safe to claim

| Safe | Unsafe |
|---|---|
| Push-back + AddRef/Release + bind | Product `LightManager::Register` symbol |
| Vector begin/end @ +8/+0xC | Capacity field layout in this body |
| Returns 0 / ret 4 | Null-obj as intentional API |
| Structural `_Inferred` name | PDB demangle without evidence |

---

## 5. CF challenge of Review A

- Body 102 B / ret 4 / append via resize: **agree Confirmed**  
- Refcount idiom shared with `0074e0d0`: **agree**  
- Product host English residual: **agree Open**  
- Bind vtbl+0x30 required: **agree Confirmed**  

**Verdict:** **accept-with-gaps**
