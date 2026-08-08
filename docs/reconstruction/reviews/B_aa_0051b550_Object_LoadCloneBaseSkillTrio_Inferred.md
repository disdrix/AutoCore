# Review B (skeptical / adversarial): `aa_0051b550` Object_LoadCloneBaseSkillTrio_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051b550` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (WQ9R-J dual) |
| **Counterpart** | `reviews/A_aa_0051b550_Object_LoadCloneBaseSkillTrio_Inferred.md` |
| **Verdict** | **accept-with-gaps** on CF/ABI; **reject** bulk-loader alias, ensure-as-return, soft-ensure-hash |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This VA **is** the bulk loadout walker `FUN_004c8a60` | **Falsified** — `004c8a60` **calls** this first, then walks equip tree |
| 2 | Hash call is soft "ensure if null only" | **Falsified** — `0x00518e30` **recreates** when `+0x70` already set (wipe) |
| 3 | Ranks come from clonebase memory next to skill ids | **Falsified** — ranks from **vfunc** returns (`movzx` after `call [vtbl+off]`) |
| 4 | Skill ids from `this` direct fields | **Falsified** — path `this+0xA8 → +0x3C → +0x3BC/C0/C4` |
| 5 | Returns skill pointers / count | **Falsified** — void; bare `C3`; no EAX contract |
| 6 | `vtbl+0x264` is vehicle melee hardpoint field | **Falsified** — here **vtable method offset**, not object field `+0x264` (different domain duals) |
| 7 | Only one caller (static) | **Partial** — one **code** caller; many **vtbl** installs |
| 8 | log2 always 1 is product "two buckets forever" | **Weak** — sealed as imm 1 at this call site only; other site uses 4 |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Wipe-then-load order | **High** | Port keeps old skills + duplicates |
| Three-slot only (not N) | **High** | Miss/extra default skills |
| Void ABI | **High** | Port invents returns |
| Clonebase indirection | **High** | Wrong skill ids every spawn |
| Rank = vfunc byte | **High** | Wrong rank floor on ensure |
| Product English | Open | Naming only |

---

## 3. Cross-check against related units

| Unit | VA | Relation |
|---|---|---|
| **This** | `0x0051b550` | Clonebase trio ensure after hash reset |
| `Object_CreateOrRecreateSkillHash_Inferred` | `0x00518e30` | First callee; hash lifecycle |
| `Skill_EnsureLoadedInTree` | `0x0051a980` | Per-slot ensure (void) |
| `FUN_004c8a60` | `0x004c8a60` | Bulk loadout; calls this then walks `+0x520` tree |
| `Object_RefreshSkillHash_Inferred` | `0x00517400` | Same `+0x70`; refresh existing, not recreate+trio |

---

## 4. Surviving contract for AutoCore

```
void Object_LoadCloneBaseSkillTrio_Inferred(Owner* self)
{
  Object_CreateOrRecreateSkillHash_Inferred(self, /*log2*/ 1);
  auto* cb = *(*(self + 0xA8) + 0x3C);  // clonebase*
  Ensure(self, *(cb + 0x3BC), (uint16)self->vtbl[0x264/4]());
  Ensure(self, *(cb + 0x3C0), (uint16)self->vtbl[0x268/4]());
  Ensure(self, *(cb + 0x3C4), (uint16)self->vtbl[0x26C/4]());
}
// Ensure = Skill_EnsureLoadedInTree — does not return skill*
```

Do **not**:

- treat as full loadout apply
- assume hash soft-ensure (it recreates)
- map vtbl offsets to vehicle hardpoint fields
- return pointers from this unit

---

## 5. Open questions

1. Product names for three clonebase skill columns.
2. Rank vfunc semantics per concrete class.
3. Runtime confirmation that bulk path always wants wipe.

**Verdict:** CF + ABI + wipe-then-trio + callee graph **sealed**. Scaffold bulk-alias and soft-ensure claims **rejected**. **accept-with-gaps** for residual English only.
