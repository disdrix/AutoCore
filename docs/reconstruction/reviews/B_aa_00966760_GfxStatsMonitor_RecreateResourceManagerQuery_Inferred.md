# Review B (skeptical / adversarial): `aa_00966760` GfxStatsMonitor_RecreateResourceManagerQuery_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00966760` |
| **VA** | `0x00966760` |
| **Canonical name** | `GfxStatsMonitor_RecreateResourceManagerQuery_Inferred` (**Inferred**) |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_00966760_GfxStatsMonitor_RecreateResourceManagerQuery_Inferred.md` |
| **System** | graphics / gfxDevice Device Reset (Stats Monitor) |
| **Live tools** | Independent decompile + `read_memory` + parent CF + D3D9 vtable index check |
| **Verdict** | **accept-with-gaps** — accept CF; reject thiscall-ECX / HRESULT-propagate / non-CreateQuery claims |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | `__thiscall` ECX = Stats Monitor | **Falsified** — body never reads ECX; parent sets **EDI**; Ghidra `unaff_EDI` |
| 2 | Returns CreateQuery HRESULT to parent | **Falsified** — `xor eax,eax` always; parent `"Failed…Stats Monitor"` arm **dead** |
| 3 | Vcall is wrapper method at `+0x1d8` on gfx wrapper | **Falsified as complete** — double-load yields **device9**, then `[vtbl+0x1d8]`; method index 118 = **CreateQuery** on IDirect3DDevice9 |
| 4 | Type 5 is occlusion / event query | **Falsified** — D3D9 enum **5 = RESOURCEMANAGER** (not 8/9) |
| 5 | Scaffold `Named_CalleeOf_…gfxDevice…` is product symbol | **Rejected** — parent-seed noise; real role is Stats Monitor query recreate |
| 6 | Has stack formals / `ret N` | **Falsified** — plain `c3` |
| 7 | Function is multi-caller utility | **Falsified** — single CODE xref from Device Reset |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| CreateQuery + type 5 + out `+0x3d4` | **High** | Wrong D3D resource lifecycle |
| Always return 0 | **High** | Porting parent to check HRESULT wrongly "fixes" dead arm |
| EDI host / `device+0x79c` | **High** | Wrong object |
| Stats Monitor log English | **High** (string) | Overclaim full class name |
| Product PDB class | **None** | Registry pollution |
| Flag `+0x3d8` meaning | **Low** | Wrong state machine |

---

## 3. Decompiler pitfalls (must survive port)

1. **`unaff_EDI`** is a real register formal from parent — not dead noise.  
2. **Return type** looks like HRESULT pathway from parent checks — **bytes win** (always 0).  
3. **Double-load `DAT_00d1f044`** — first is wrapper\*, second is device9\*.  
4. Scaffold gfxDevice callee naming — **ignore** for product registry.

---

## 4. What is safe to claim

| Safe | Unsafe |
|---|---|
| CreateQuery(RESOURCEMANAGER) into `host+0x3d4` | Full StatsMonitor C++ type / methods |
| Clear `+0x3d8`; null on fail | Flag English |
| Always return 0; plain RET | Parent fail-string as live path |
| Single Device Reset consumer | Multi-domain utility |

---

## 5. CF challenge of Review A

- Body CF + 47 B + CreateQuery seal: **agree Confirmed**  
- Dead parent fail arm: **agree** (adversarial emphasis)  
- Product class residual: **agree Open**  

**Verdict:** **accept-with-gaps**
