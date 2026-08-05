# Review B (skeptical / adversarial): `aa_00970060` EffectHandle_SetSlot_CoW_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00970060` |
| **VA** | `0x00970060` |
| **Canonical name** | `EffectHandle_SetSlot_CoW_Inferred` (**Inferred**) |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_00970060_EffectHandle_SetSlot_CoW_Inferred.md` |
| **System** | graphics / device-effect parameter slot bind |
| **Live tools** | Independent decompile + `read_memory` + caller/callee bytes |
| **Verdict** | **accept-with-gaps** — accept ESI ABI; reject unaff_ESI garbage and scaffold name |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Decompiler `unaff_ESI` is undefined / garbage | **Falsified** — ESI is deliberate this; all real callers set it (`lea esi,…` / `mov esi,ecx`) |
| 2 | `__cdecl` / no stack cleanup | **Falsified** — **`ret 8`** |
| 3 | `FUN_00448fc0(iVar4)` only (wrong this) | **Falsified** — `mov ecx,esi; push parent; call` |
| 4 | Always rebinds parent after set | **Falsified** — only if status==-1 **and** cowed **and** parent≠self |
| 5 | `007528f0` can return -1 for reasons other than index\<0 | **Weakened** — callee bytes show early `-1` only for index\<0; rest returns 0 (no other -1 found in decompile head) |
| 6 | Scaffold TacArc InitializeMesh chain name | **Rejected** |
| 7 | Same refcount layout as `0096efd0` on the binder | **Partial** — binder uses rc@+4 (`00448fc0` / `0096fdf0`); slot **resources** use iface@+4/rc@+8 inside `007528f0` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ESI this + `ret 8` | **High** | Stack smash / wrong object |
| CoW then set-slot order | **High** | Shared-effect corruption |
| Status passthrough | **High** | Wrong caller branch |
| Fail-path parent rebind meaning | **Medium** | Mis-document rare path |
| Product English | **None** | Registry pollution |

---

## 3. Decompiler pitfalls (must survive port)

1. **Recover ESI this** from callers — never treat as unaff.  
2. **`ret 8`** required.  
3. CoW helper return is **bool in AL**, not full EAX (saved to BL before set-slot overwrites EAX).  
4. Do not invent product “Material”/“Texture” class names without RTTI.

---

## 4. What is safe to claim

| Safe | Unsafe |
|---|---|
| ESI handle + (index, resource) + ret 8 | Product effect class name |
| CoW gate via `0096fdf0` | That -1 path is hot in retail |
| Slot set via `007528f0` | Full slot-table layout (callee OWN elsewhere) |
| Used to clear DiffuseTexture (index, 0) | That resource arg is always texture |

---

## 5. CF challenge of Review A

- Body/ABI/callers: **agree Confirmed**  
- Fail-path rarity gap: **agree** → accept-with-gaps  
- Name structural OK: **agree**  

**Verdict:** **accept-with-gaps**
