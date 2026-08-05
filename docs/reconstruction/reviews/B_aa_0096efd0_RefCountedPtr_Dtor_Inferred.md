# Review B (skeptical / adversarial): `aa_0096efd0` RefCountedPtr_Dtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0096efd0` |
| **VA** | `0x0096efd0` |
| **Canonical name** | `RefCountedPtr_Dtor_Inferred` (**Inferred**) |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_0096efd0_RefCountedPtr_Dtor_Inferred.md` |
| **System** | shared util — refcounted handle destructor |
| **Live tools** | Independent decompile + `read_memory` + peer ctor dual + caller samples |
| **Verdict** | **accept** — reject double-free reading and scaffold Named_CalleeOf |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Decompiler double-release is two live releases | **Falsified** — SEH try (null) + cleanup (no null); happy path cleanup is dead after null |
| 2 | `__fastcall` void with phantom stack args | **Falsified** — ECX only; `ret` / `add esp,0x10` is SEH frame teardown |
| 3 | Refcount at `+4` (COM-style like `00448fc0`) | **Falsified** — bytes use **`+8`**; `+4` is iface this |
| 4 | Scaffold `Named_CalleeOf_CVOGTacArc_dtor_helper_*` product name | **Rejected** — multi-domain leaf (100+ xrefs), not TacArc-specific |
| 5 | Returns meaningful EAX | **Weakened** — void; EAX scratch after epilog |
| 6 | Same layout as binder objects in `0096fdf0` (rc@+4) | **Falsified for this helper** — this dtor is the **resource** layout (iface@+4, rc@+8); binders use COM-style rc@+4 via `00448fc0` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Body size / `ret` | **High** | Wrong next-fn boundary |
| rc@+8 + iface release | **High** | Leak or double-free |
| SEH dual-shape | **High** | Spurious double-release ports |
| Product English | **None** | Registry pollution |
| All 100 xrefs pure dtor (never mid-life clear) | **Medium** | Some sites may re-null live handles (still correct) |

---

## 3. Decompiler pitfalls (must survive port)

1. **Do not** implement two sequential releases on one path.  
2. **Do not** treat `+4` as refcount (that is a different smart-pointer family).  
3. Preserve **ECX = handle\***; no `ret N`.  
4. Ignore TacArc-chained scaffold names.

---

## 4. What is safe to claim

| Safe | Unsafe |
|---|---|
| Handle dtor, rc@+8, iface vtbl+8 | Product class / RTTI |
| Peer of `0096ef70` default ctor | That every payload is a texture |
| SEH try+cleanup shape | That cleanup path is product-visible |

---

## 5. CF challenge of Review A

- Body / ABI / layout: **agree Confirmed**  
- SEH explanation of dual block: **agree**  
- Product gaps: **agree** (no block on accept)  
- Name `RefCountedPtr_Dtor_Inferred`: **agree** structural  

**Verdict:** **accept**
