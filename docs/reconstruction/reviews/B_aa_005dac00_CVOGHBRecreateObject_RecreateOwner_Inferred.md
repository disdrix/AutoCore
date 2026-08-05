# Review B (skeptical / adversarial): `aa_005dac00` CVOGHBRecreateObject_RecreateOwner_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005dac00` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005dac00_CVOGHBRecreateObject_RecreateOwner_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Scaffold name “callee of Reaction_SpawnObject” is product role | Primary xrefs: recreate OnHB + RTTI recreate helper only | **Falsified** spawn-factory claim |
| 2 | `this` is the owner entity, not the HB | Field `+0x18` matches HB `pOwnerObject`; callers pass HB | **Falsified** owner-as-this |
| 3 | Always recreates even with null phys body | Explicit `phys==0 \|\| phys[2]==0` early out | **Falsified** always-run |
| 4 | Impulse is non-zero / random kick | `DAT_00bc5670` BSS zero + ApplyImpulseVector | **Falsified** kick claim |
| 5 | `FUN_0053d970(0)` always forces type 6 | Sibling dual: flag0 → soft type **1** | **Falsified** type-6 myth |
| 6 | `__cdecl` multi-arg | Prologue `mov esi,ecx`; plain RET; no stack formals | **Falsified** cdecl |
| 7 | Name `…RecreateOwner_Inferred` wrong | OnHB path labels recreate; RTTI `CVOGHBRecreateObject` | **Survives** structural name |
| 8 | Types 0x12/0x14 are “vehicle only” | Only machine fact is skip of `FUN_00516a00` | **Survives as raw filter** — English open |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| HB this + owner@+0x18 | **High** | Wrong object recreated |
| Dual RTTI gates | **High** | Cast crashes / no-op ports |
| Flag clear + zero impulse | **High** | Sticky soft state / residual velocity |
| Soft body-type call | **High** | Wrong phys mode after recreate |
| Vfunc English | **Open** | Incomplete port of rebind sequence |
| Tail `FUN_004cd540` | **Open** | Missing post-recreate side effects |

---

## 3. Cross-check against raw / bytes

```
raw: if owner; cast Physics; body; refresh; cast Graphics; pose/orient vcalls;
     phys+0x10; 560e90; flag&=~1; soft? 53d970(0); zero impulse; 244/240;
     type∉{0x12,0x14}? 516a00(1); 4cd540(...,1)
bytes: 8B F1; RTTI push descriptors; & FE at +0x181; push DAT_00bc5670 ×2; C3
```

Clean ≡ raw ≡ live decompile. No modernization of CF.

---

## 4. Surviving contract for AutoCore

```csharp
// Called from recreate HB when transform helper reports failure (local_12c==0)
// and from recreate-typed list predicate with flag set.
void RecreateOwner(CvoGhbBase hb)
{
    var owner = hb.Owner; // +0x18
    if (owner == null) return;
    var phys = DynamicCastPhysics(owner);
    if (phys == null || phys.BodyHost == null) return;
    // … full rebind sequence per clean source …
    ClearSoftFlagBit0(phys);           // layout+0x181
    if (!IsSoftReady(phys))
        SetPhysBodyTypeIfNotReady(phys, flag: 0); // → type 1
    ApplyImpulse(phys, Vector3.Zero);
    // type filter 0x12/0x14 then FUN_00516a00; FUN_004cd540 tail
}
```

**Port traps to reject:**

- Treating this as a free spawn factory or Reaction-only helper.
- Passing owner as `this` instead of HB.
- Non-zero impulse “nudge” on recreate.
- Skipping the soft flag clear.

---

## 5. Residual gaps (do not block seal)

1. Product English for graphics/physics vfuncs and `FUN_004cd540` / `FUN_00516a00`.
2. Runtime recreate differential (live HB fire).
3. PDB / retail symbol.

---

## Verdict

**accept-with-gaps** — adversarial review cannot break HB-this, dual RTTI gates, flag clear, or zero-impulse recreate kernel. Main falsifications are spawn-factory scaffold name and type-6 soft-request myth. Gaps are product English + runtime.
