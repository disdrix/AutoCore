# Review B (skeptical / adversarial): `aa_004bb010` Object_ResolveTfIdVtbl1d4_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bb010` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004bb010_Object_ResolveTfIdVtbl1d4_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Identical to `Object_ResolveFromTFID` (`004bb950`) | That unit ends after Resolve; this adds `vtbl+0x1d4` | **Falsified** merge |
| 2 | Same as GetIdentity (`004bb070`, `+0x1d8`) | Slot is `+0x1d4` in bytes | **Falsified** merge |
| 3 | Same as Lookup (`004bb0a0`, `+0x1dc`) | Different slot + this unit takes blob* not free args | **Falsified** merge |
| 4 | Pure “table lookup boolean” | Returns virtual result; CreateVehicle also calls `+0x1d4` on new objects | **Survives** as resolve+get; **falsifies** pure bool |
| 5 | `__stdcall` with no ECX | `RET 4` yes, but Resolve needs ECX; callers set it; body preserves it | **Survives** as ECX passthrough thiscall-class |
| 6 | Reads full TFID_16 | Only +0/+4/+8 in body | **Falsified** full-16 |

---

## 2. Live ≡ raw ≡ bytes

Live decompile matches raw 2026-07-23 body and `read_memory` hex. Callers list matches `get_function_callers` (5). Sole direct callee `0x004bae70`.

---

## 3. Surviving contract

```
// ECX = resolve ctx (caller)
// pBlob → ResolveObjectTarget(bGlobal@+8, lo@+0, hi@+4)
// if null → 0 else → obj->vtbl[0x1d4]()
// RET 4
```

**Gaps kept:** product name of `+0x1d4`; whether return is always identity-equal to `obj`.

**Verdict:** **accept-with-gaps**.
