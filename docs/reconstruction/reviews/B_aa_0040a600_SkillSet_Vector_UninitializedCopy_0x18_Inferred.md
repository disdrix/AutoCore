# Review B (skeptical / adversarial): `aa_0040a600` SkillSet_Vector_UninitializedCopy_0x18_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040a600` |
| **VA** | `0x0040a600` |
| **Canonical name** | `SkillSet_Vector_UninitializedCopy_0x18_Inferred` |
| **Review date** | `2026-08-05` (MEGA-055 OWN dual) |
| **Reviewer role** | Skeptical naming / anti-overclaim |
| **Counterpart** | `reviews/A_aa_0040a600_SkillSet_Vector_UninitializedCopy_0x18_Inferred.md` |
| **System** | skills-abilities / STL SkillSet vector |
| **Verdict** | **accept-with-gaps** — agree with A |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Skill combat / `Skill_Uses_*` product helper | **Falsified** — pure range copy; sole real parent is vector insert `FUN_00412730` + trampoline; no skill-id / cast logic |
| 2 | `Named_CalleeOf_Skill_Uses_SkillSet_GetEntryCount_*` is correct name | **Falsified** — chain-of-caller scaffold; `SkillSet_GetEntryCount` is a peer of the parent, not a direct caller of this VA |
| 3 | Same function as leaf `SkillSet_UninitializedCopy_0x18` (`0x00442b00`) | **Falsified** — `00442b00` is register-ABI (EAX/ECX/EDX) POD loop without SEH; this unit is SEH + `CALL FUN_00412b10` + cdecl stack |
| 4 | This is Ufill / fill-from-prototype | **Falsified** — range walk of first→end; Ufill sibling is dualed `00406f00` |
| 5 | `__thiscall` with C++ `this` object | **Falsified** — epilogue bare **`RET` (`C3`)**; ECX is **src_end**, not a SkillSet object (no `this+field` loads); callers `ADD ESP,0x10` |
| 6 | `stdcall` / `ret 4` / `ret 8` cleanup | **Falsified** — body `C3`; trampoline `00412a80` is the `RET 8` unit, not this |
| 7 | Stride 0x0c / 0x28 / 0x30 | **Falsified** — both cursors `ADD …,0x18`; callee copies **6** dwords; parent divides by `0x18` |
| 8 | Tree/map rotate or erase helper | **Falsified** — no isnil/color/parent links; linear vector range |
| 9 | Product English / PDB `_Ucopy` proven | **Fails** — keep **`_Inferred`** |
| 10 | Runtime Confirmed | **Fails** — open (no Launcher; Terminal false) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Body 101 B + `RET` cdecl | **Confirmed** | Stack imbalance in ports |
| ECX=end, stack first/dest, EAX=dest_end | **Confirmed** | Wrong register contract |
| Stride 0x18 / 6-dword element | **Confirmed** | Corrupt SkillSet entries |
| SkillSet vector insert family | **High** | Mis-tag system |
| SEH present (not leaf POD copy) | **Confirmed** | Merge with `00442b00` wrongly |
| Product demangle | **Tentative** | Overclaim English |
| Extra 2 stack formals meaning | **Low** | Doc only (body-unused sealed) |

---

## 3. Cross-check against raw / bytes

```text
raw 2026-07-23 CF ≡ live decompile 2026-08-05 ≡ clean named plate
(ABI labels corrected vs Ghidra __thiscall)

55 8B EC 6A FF 68 90 D0 9B 00 64 A1 …   SEH
8B 7D 0C                                 dest ← [EBP+0xc]
8B D9                                    end  ← ECX
8B 75 08                                 first← [EBP+0x8]
…
8B CE 8B C7 E8 …                         ECX=src, EAX=dest; CALL 00412b10
83 C7 18 83 C6 18                        +0x18
…
8B C7 … 5F 5E 5B 8B E5 5D C3             return dest_end; RET

Call sites: ADD ESP,0x10 (cdecl 4×push)
Return store: MOV [EBX+0x8], EAX @ 0x004129b2
```

Reject ports that:

- Name this as skill-cast / Uses_SkillSet product logic.
- Merge with leaf Ucopy `00442b00` or Ufill `00406f00`.
- Use thiscall/stdcall cleanup instead of cdecl.
- Change stride away from 0x18.
- Claim runtime Confirmed without Launcher evidence.

---

## 4. Surviving contract for AutoCore

```csharp
// Retail: MSVC vector _Ucopy for 0x18-byte SkillSet entries (SEH frame).
// Port: Buffer.BlockCopy / span copy of n entries; return dest + n.

static unsafe NPCSkillSetEntry* UninitializedCopy0x18(
    NPCSkillSetEntry* srcEnd,    // ECX
    NPCSkillSetEntry* srcFirst,  // stack
    NPCSkillSetEntry* dest)      // stack
{
    while (srcFirst != srcEnd)
    {
        if (dest != null)
            *dest = *srcFirst; // 0x18 POD-ish assign (FUN_00412b10)
        srcFirst++;
        dest++;
    }
    return dest;
}
```

Pair with:

- dualed count `SkillSet_GetEntryCount` (`0x00402d80`)
- dualed fill `SkillSet_Vector_UninitializedFillN_0x18_Inferred` (`0x00406f00`)
- undualed parent insert `FUN_00412730`
- do **not** merge with leaf `SkillSet_UninitializedCopy_0x18` (`0x00442b00`) without ABI adapter

---

## 5. Agreement with Review A

- CF/ABI/stride/callers/callees: **agree Confirmed/High**
- Name with `_Inferred`: **agree**
- Retire Named_CalleeOf: **agree**
- Gaps (PDB, parent dual, extra stack slots, runtime): **agree open**

---

## 6. Residual risks

- Do not treat trampoline `FUN_00412a80` as this unit.  
- Do not invent SkillSet field English from the 6-dword blob.  
- Parent `FUN_00412730` still open for full insert dual.

**Verdict:** **accept-with-gaps**
