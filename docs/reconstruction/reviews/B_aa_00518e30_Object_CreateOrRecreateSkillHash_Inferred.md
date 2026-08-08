# Review B (skeptical / adversarial): `aa_00518e30` Object_CreateOrRecreateSkillHash_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00518e30` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (WQ9R-J dual) |
| **Counterpart** | `reviews/A_aa_00518e30_Object_CreateOrRecreateSkillHash_Inferred.md` |
| **Verdict** | **accept-with-gaps** on CF/ABI; **reject** soft-ensure-only, owner-as-hash-thiscall, inventory-hash merge |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Soft ensure: no-op when `+0x70` already set | **Falsified** — existing path **always** calls recreate |
| 2 | `FUN_004cbdc0` thiscall ECX is owner | **Falsified** — `mov ecx,[esi+0x70]` before call; method is on hash |
| 3 | Same type as inventory `CNDHash_Recreate` `0x004138d0` | **Falsified as identity** — shared *string* family only; different VA/vtbl/helpers (`004cbdc0` vs `004138d0`) |
| 4 | Returns hash pointer in EAX for callers | **Falsified** — void; `ret 4`; callers do not use EAX (trio loader ignores) |
| 5 | `param_2` is skill id or rank | **Falsified** — log2 size exponent; ctor stores at `hash+0x1c`, sets count `1<<log2` |
| 6 | `new(0x34)` size is skill runtime (0x630) | **Falsified** — hash header sizeof; skill materialize is separate |
| 7 | Sole caller is `FUN_0051b550` | **Partial** — second xref `0x0052a2c5` (push 4); not in a named function |
| 8 | Recreate aborts when traversal-locked | **Falsified for stop** — callee logs `HashError:Recreate…` / `VOG_DEBUG_STOP` but **continues** (same pattern as inventory recreate dual) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Wipe-on-existing | **High** | Port keeps stale skills when "ensure"ing |
| Hash vs owner ECX | **High** | Wrong this pointer → crash/corrupt |
| log2 semantics | **High** | Wrong bucket mask |
| sizeof 0x34 | **High** | Over/under alloc |
| `+0x70` skill slot | **High** | Wire wrong owner field |
| Product type name | Open | Naming only |

---

## 3. Cross-check against related units

| Unit | VA | Relation |
|---|---|---|
| **This** | `0x00518e30` | Create or recreate skill hash at owner+0x70 |
| `FUN_004cbdc0` | `0x004cbdc0` | Recreate (hash this) |
| `FUN_0051dd60` | `0x0051dd60` | Ctor (hash this, log2) |
| `Skill_EnsureLoadedInTree` | `0x0051a980` | Requires hash at +0x70 |
| `Object_LoadCloneBaseSkillTrio_Inferred` | `0x0051b550` | Calls with log2=1 (wipe before defaults) |
| Inventory `CNDHash_Recreate` | `0x004138d0` | Analogous pattern; **not** this symbol |

---

## 4. Surviving contract for AutoCore

```
void Object_CreateOrRecreateSkillHash_Inferred(Owner* owner, uint8_t log2)
{
  CNDHash* h = owner->skillHash; // +0x70
  if (h) {
    SkillCNDHash_Recreate(h, log2);  // FUN_004cbdc0 — may log if locked; still recreates
    return;
  }
  void* mem = operator_new(0x34);
  owner->skillHash = mem ? SkillCNDHash_Ctor(mem, log2) : nullptr; // FUN_0051dd60
}
// ret 4; void — do not return hash*
```

Do **not**:

- soft-skip when hash exists
- pass owner as recreate `this`
- merge with inventory CNDHash type identity
- treat log2 as skill id

---

## 5. Open questions

1. Product name for skill CNDHash vtbl `009ce1b8`.
2. Function identity around orphan call `0x0052a2c5`.
3. Whether freelist/node layout matches inventory family bit-for-bit.

**Verdict:** Create/recreate CF + ABI + sizeof + `+0x70` **sealed**. Soft-ensure and type-merge claims **rejected**. **accept-with-gaps** for residual English only.
