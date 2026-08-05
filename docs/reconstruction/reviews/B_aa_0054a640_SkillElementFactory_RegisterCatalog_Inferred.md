# Review B (skeptical / adversarial): `aa_0054a640` SkillElementFactory_RegisterCatalog

| Field | Value |
|---|---|
| **Stable ID** | `aa_0054a640` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0054a640_SkillElementFactory_RegisterCatalog_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Runtime cast dispatcher | Only EnsureInitialized caller; no skill id args | **Falsified** — catalog bootstrap |
| 2 | Single factory object | Many `operator_new` + distinct vtables + sequential keys | **Falsified** — multi-type register |
| 3 | All types same size | Sizes 0x6c0 / 0x6d0 / 0x6e0 / 0x6f0 | **Falsified** if claimed uniform |
| 4 | Name implies complete type list sealed | Full unrolled count not independently recounted in this dual | **Gap** — pattern sealed, exact N residual |
| 5 | Null new → skip insert | Still calls `FUN_0054eb20` with null instance | **Clarify** — insert null-capable pair |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Bootstrap-only / no cast path | **High** | Invented runtime dependency |
| typeId → vtable object map | **High** | Broken skill element spawn |
| Two base-ctor families | **High** | Wrong construction |
| Product class names | **Low** | Naming only |
| Exact type count | **Medium** | Incomplete catalog on ports |

---

## 3. Surviving contract for AutoCore

```csharp
void SkillElementFactory_RegisterCatalog()
{
    // For each known skill-element type id:
    //   alloc size class; base construct; stamp vtable; map.insert(id, instance)
    // Called once from SkillDefMap_EnsureInitialized — not per cast
}
```

**Port traps:**

- Lazy-registering only used types without matching retail catalog (missing type ids break load).
- Sharing one vtable across type ids.
- Invoking from RequestCast.

---

## 4. Residual gaps

1. Full typeId→class table from vtables.
2. `FUN_0054eb20` dual.
3. Exact terminal type id.

**Verdict:** **accept-with-gaps** — registration pattern sealed; product type names open.
