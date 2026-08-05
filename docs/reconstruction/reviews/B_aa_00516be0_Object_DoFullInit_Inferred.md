# Review B (skeptical / adversarial): `aa_00516be0` Object_DoFullInit_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00516be0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00516be0_Object_DoFullInit_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Only a skill-refresh wrapper | Virtuals `+0x100` / `+0x48` always in path structure | **Over-narrow** — multi-stage init |
| 2 | Always calls `vtbl+0x100` | Skipped when related non-null **and** `+0x2ac != 0` | **Conditional** |
| 3 | Skill refresh always | Types `0x12` and `0x14` early-out | **Skipped for those types** |
| 4 | `FUN_00516a00(0)` like ActivateEnterWorld | Bytes `push 1` | **Falsified** — param **1** (all active) |
| 5 | Pure `__fastcall` free function | ECX this, ESI save, vtable DATA installs | **Object method / shared thiscall** |
| 6 | Product name sealed as `DoFullInit` | String is on **caller** anim stage, not this body | **Role-inferred** — keep `_Inferred` |
| 7 | Same as entire `CLoadNode::_initFull` | `_initFull` has wait/mark, player gates, extra virtuals | **Subroutine only** |
| 8 | Long Named_CalleeOf_… primary name | Role sealed | **Reject** scaffold alias as primary |
| 9 | Clean invents CF | 80 B; decompile ≡ bytes | **No invention** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Virtual call order / skip gate | **High** | Wrong load order / double-init |
| Offsets `+0x1d4`, `+0x100`, `+0x48`, `+0x2ac`, `+0xa8/+0x38` | **High** | Broken ports |
| Skill param `1` vs `0` | **High** | Miss residual-only skills or over-apply |
| Type skip set {0x12,0x14} | **High** CF / **Medium** English | Wrong entity classes refresh |
| “Full init” English name | **Medium** product | Docs overclaim method name |
| Related = vehicle/body | **Probable** prior art | Wrong object when flag tested |

---

## 3. Cross-check against raw / memory

```
raw:
  r = vtbl+0x1d4()
  if r:
    r = vtbl+0x1d4()
    if *(r+0x2ac) != 0: goto after_100
  vtbl+0x100()
after_100:
  vtbl+0x48()
  if type not in {0x12,0x14}: FUN_00516a00(1)

read_memory 00516be0..:
  push esi; mov esi,ecx
  call [eax+0x1d4]; test; jz do_100
  call [edx+0x1d4]; cmp byte [eax+0x2ac],0; jnz skip_100
do_100:
  call [eax+0x100]
skip_100:
  call [edx+0x48]
  mov eax,[esi+0xa8]; mov eax,[eax+0x38]
  cmp 0x12 / 0x14 → skip
  push 1; call FUN_00516a00
  pop esi; ret
```

Double `+0x1d4` when non-null is **retail** (not clean invention) — second call re-resolves before reading `+0x2ac`.

---

## 4. Surviving contract for AutoCore

```csharp
// Object full-init epilogue (client load / create). Virtual product names open.
void Object_DoFullInit(ClonedObjectBase self)
{
    var related = self.VGetRelated_1d4(); // vtbl+0x1d4
    if (related == null || related.Flag_2ac == 0)
        self.VInitStep_100();             // vtbl+0x100
    self.VFinalize_48();                  // vtbl+0x48
    int type = self.CloneBase.TypeId;     // [+0xa8]+0x38
    if (type != 0x12 && type != 0x14)
        Object_RefreshActiveSkillEffects(self, allActive: true); // FUN_00516a00(1)
}
```

Server port: only if server mirrors client full-init skill reapply and type exceptions; do **not** treat as spawn faction writer (that is `aa_00512460`).

---

## 5. Residual gaps (do not over-seal)

1. Virtual method product names.
2. Meaning of `related+0x2ac` (ready / already-inited / has-anim?).
3. Type 0x12/0x14 product labels and why skills skipped.
4. Full vtable class list.
5. Runtime confirmation on player vs NPC vs vehicle load.

**Verdict:** **accept-with-gaps**
