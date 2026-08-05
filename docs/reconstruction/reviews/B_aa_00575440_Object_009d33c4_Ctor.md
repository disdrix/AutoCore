# Review B (skeptical / adversarial): `aa_00575440` Object_009d33c4_Ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00575440` |
| **VA** | `0x00575440` |
| **Canonical name** | `Object_009d33c4_Ctor` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Adversarial / gap-hunt (OWN-ONLY W29-H) |
| **Counterpart** | `reviews/A_aa_00575440_Object_009d33c4_Ctor.md` |
| **Verdict** | **accept-with-gaps** |

---

## Attacks considered

| Attack | Outcome |
|---|---|
| Not a ctor — factory / reset helper? | **Rejected.** SEH+base-ctor+vtbl install+return this is complete-object ctor idiom; sole twin of sealed complete dtor. |
| `__fastcall` with second register arg? | **Rejected.** Bytes: only ECX used as this (`8B F1`); no EDX formal; bare `RET` not `RET n`. Ghidra `__fastcall` is display for single-reg thiscall. |
| List base is `+0x1E0` not `+0x1DC`? | **Rejected.** `lea edi,[esi+0x1DC]`; stores at `[edi+4]`/`[edi+8]`. Matches `StdList_Destroy_FreeHead` (+4 head, +8 size) and dtor LEA @ +0x1DC. |
| `FUN_00457c60` is thiscall on list? | **Rejected.** Callee is `operator_new(0x18)` + self-links; no ECX use. Result stored as head. |
| Scaffold name `Named_CalleeOf_CVOGReaction_GiveItemByCbid_*` is product? | **Rejected as canonical.** One of two callers only; vtbl-family name is structural. |
| Four −1 pairs are TFID/objectid product type? | **Open gap** — layout sealed, product label not claimed. |
| Incomplete vs base fields? | Base layout owned by `FUN_00518940`; this body only writes derived region + vtbl. Not a defect. |

---

## Residual risks

1. Product English / demangle for derived type.
2. Slot semantics (`+0x198` cluster, `+0x190`, `+0x1E8`, owned `+0x1EC`).
3. No runtime / differential proof that ctor/dtor are exact inverses beyond structural offset match.
4. Second caller `FUN_0094bed0` not owned here — factory shape inferred only.

---

## Port cautions

```
// OK: construct then destroy via complete dtor path
Object_009d33c4_Ctor(mem);
Object_009d33c4_CompleteDtor(mem);

// OK: delete via vtbl[0]
Object_009d33c4_ScalarDeletingDtor(obj, 1);

// BAD: skip base ctor
// BAD: treat as CVOGReaction-only helper
// BAD: put list head at +0x1DC instead of +0x1E0
```

---

## Verdict

No CF/ABI falsifier stands. Gaps are naming/product only → **accept-with-gaps**.
