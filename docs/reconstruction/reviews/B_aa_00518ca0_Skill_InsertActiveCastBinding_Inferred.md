# Review B (skeptical / adversarial): `aa_00518ca0` Skill_InsertActiveCastBinding_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00518ca0` |
| **VA** | `0x00518ca0` |
| **Canonical name** | `Skill_InsertActiveCastBinding_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00518ca0_Skill_InsertActiveCastBinding_Inferred.md` |
| **System** | skills-abilities |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Product name without `_Inferred` | No string/RTTI/plate on body | **Agree** keep `_Inferred` |
| 2 | `FUN_00518c20` takes (out, key) here | Sibling dual: unary getter; staged pushes are for insert | **Falsified** multi-arg getter |
| 3 | No ECX / pure stdcall 5-arg | Body never loads map owner from stack; ECX preserved into getter | **Falsified** no-this |
| 4 | Named_CalleeOf frequency parent is identity | Frequency log is in FireTail period clamp, not this insert | **Falsified** alias |
| 5 | Always overwrites existing binding | `FUN_004cbe20` has existing-key path (`bool=0`, no insert) | **Survives as gap** — insert-or-find, not forced replace |
| 6 | Multiple static callers | Sole xref `0x00578c55` | **Agree** sole |
| 7 | Map is category-cooldown map (+0x6c) | Getter is `FUN_00518c20` → **+0x68** only | **Falsified** wrong slot |
| 8 | Local pack is contiguous 20 B skillId+TFID | Bytes skip store at +4 | **Agree** gap sealed |

---

## 2. Live ≡ raw

```
Live decompile 0x00518ca0 ≡ 2026-07-23 raw (same locals/callees).
read_memory: 83 EC 18 … 83 C4 18 C2 14 00  (body end 00518ce4).
Xref: only FUN_00578b30 @ 00578c55.
```

Call-site seal (FireTail):

```
test vtbl+0x214 result; test HB+0x639 bit 2
sub esp, 0x10          ; TFID16 from HB+0x678
push [HB+0x620]        ; skillId
lea ecx, mapOwner
call 0x00518ca0
```

---

## 3. What is safe / unsafe

| Safe | Unsafe |
|---|---|
| Insert-or-find into +0x68 map | Product method English |
| skillId key + TFID16 value family | Claiming forced overwrite on duplicate key |
| `__thiscall` ret 0x14 | Map owner class name (Character* etc.) |
| Reject frequency Named_CalleeOf | Promoting without `_Inferred` |
| Sole FireTail static caller | Dynamic/vtbl-only other callers without scan |

---

## 4. CF challenge of Review A

- Pack / gap / get / insert / ret 0x14: **agree Confirmed**
- ECX owner: **agree Confirmed**
- Sibling TFID @ +0x18: **agree High**
- `_Inferred` name: **agree** — role High, product Open
- leave-FUN on map getter does **not** force leave-FUN on insert: insert has clearer multi-sibling role (Lookup/Clear/Insert triangle); still no string → keep `_Inferred` not bare product name

---

## 5. Residual risks

1. `FUN_004cbe20` duplicate-key policy (keep old vs undefined).
2. Uninitialized pad @ local+4 / node+0x14.
3. Map owner product type still open (same as `aa_00518c20`).
4. Runtime / bit-exact / differential not run.

**Verdict:** **accept-with-gaps.** Agree with A on ABI, CF, name class, and sole caller.
