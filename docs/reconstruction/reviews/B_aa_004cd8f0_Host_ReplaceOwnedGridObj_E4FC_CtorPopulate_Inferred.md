# Review B (skeptical / adversarial): `aa_004cd8f0` Host_ReplaceOwnedGridObj_E4FC_CtorPopulate_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cd8f0` |
| **VA** | `0x004cd8f0` |
| **Canonical name** | `Host_ReplaceOwnedGridObj_E4FC_CtorPopulate_Inferred` (**Inferred**) |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_004cd8f0_Host_ReplaceOwnedGridObj_E4FC_CtorPopulate_Inferred.md` |
| **System** | host owned 0x30 grid-list object replace + populate |
| **Live tools** | Independent decompile + `read_memory` + W30-O / W37-L context |
| **Verdict** | **accept-with-gaps** — accept body; reject decompiler missing this= on populate and “always live” without callers |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Decompiler: populate is free function without this | **Falsified** — bytes `mov ecx,eax` before `call 005b3fa0` |
| 2 | Scale is a fifth stack arg from caller | **Falsified** — scale loaded from `*(host+0xe4f8)+0x18` |
| 3 | `ret` bare / void cdecl | **Falsified** — **`ret 0x10`** (4 stack args) |
| 4 | Same as convenience ctor `005b4260` | **Falsified** — this is **host method** replace+store; convenience is on the 0x30 object itself and has zero callers |
| 5 | Same as sibling `004cd9a0` | **Falsified** — different gate (`+0x8c>0x22`) and populate (`005b42f0`) |
| 6 | Confirmed product host name (map/sector/…) | **Rejected** — no plate; `_Inferred` only |
| 7 | Actively called in retail | **Weakened** — **zero** Ghidra CODE/DATA xrefs; body well-formed but entry may be dead or unbound |
| 8 | `FUN_005b3f60()` without this | **Falsified** — `mov ecx,eax` before ctor call |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Body CF / sizes / `ret 0x10` | **High** | Wrong port |
| Slot `+0xe4fc` ownership | **High** | Leak / double free |
| Scale from nested `+0xe4f8+0x18` | **High** | Wrong grid density |
| Populate this = new | **High** | Wrong object filled |
| Live call graph | **Low** | Dead-code cleanup risk |
| Product English | **None** | Registry pollution |

---

## 3. Decompiler pitfalls (must survive port)

1. **Restore ECX** for both ctor and populate — decompile drops this=.  
2. **Do not** invent a fifth stack float for scale — it is nested-host derived.  
3. **Do not** merge with `005b4260` or `004cd9a0`.  
4. Treat **zero xrefs** as open: sealed structure ≠ proven live.

---

## 4. What is safe to claim

| Safe | Unsafe |
|---|---|
| Replace/dtor/new/ctor/store/populate CF | Product host class name |
| `ret 0x10`, SEH `009a1eb7` | That retail always reaches this VA |
| Offsets `+0xe4fc` / `+0xe4f8+0x18` | OOM safety of populate(null) |
| Callees W30-O + W37-L | Scale is definitively float vs int without populate dual |

---

## 5. CF challenge of Review A

- CF/ABI/bytes seal: **agree Confirmed**  
- Populate this restored from bytes: **agree**  
- Zero xrefs as gap (not as proof of live): **agree** — Review A “live structural path” is relative to dead convenience ctor, not proof of runtime hits  
- Verdict accept-with-gaps: **agree**

**Verdict:** **accept-with-gaps**
