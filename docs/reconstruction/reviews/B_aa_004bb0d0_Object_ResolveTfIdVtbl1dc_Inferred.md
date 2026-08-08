# Review B (skeptical / adversarial): `aa_004bb0d0` Object_ResolveTfIdVtbl1dc_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bb0d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_004bb0d0_Object_ResolveTfIdVtbl1dc_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Identical to `Object_ResolveFromTFID` (`004bb950`) | That unit ends after Resolve; this adds `vtbl+0x1dc` | **Falsified** merge |
| 2 | Same as GetIdentity (`004bb070`, `+0x1d8`) | Slot is `+0x1dc` in bytes | **Falsified** merge |
| 3 | Same as Vtbl1d4 (`004bb010`) | Slot `DC 01` vs `D4 01`; otherwise twin | **Falsified** merge; **survives** as sibling |
| 4 | Same as Lookup (`004bb0a0`) | Same slot **but** free 3-arg `RET 0xc` vs blob* `RET 4` | **Falsified** ABI merge; **survives** shared slot role |
| 5 | Pure boolean table hit | Returns virtual result | **Survives** as resolve+get |
| 6 | `__stdcall` with no ECX | `RET 4` yes, but Resolve needs ECX; body preserves caller ECX | **Survives** as ECX passthrough thiscall-class |
| 7 | Reads full TFID_16 | Only +0/+4/+8 in body | **Falsified** full-16 |

---

## 2. Live ≡ raw ≡ bytes

Live decompile matches raw 2026-07-23 body and `read_memory` hex. Xref count **9**. Sole direct callee `0x004bae70`. Virtual encoding `FF 92 DC 01 00 00` sealed.

---

## 3. Surviving contract

```
// ECX = resolve ctx (caller)
// pBlob → ResolveObjectTarget(bGlobal@+8, lo@+0, hi@+4)
// if null → 0 else → obj->vtbl[0x1dc]()
// RET 4
```

**Gaps kept:** product name of `+0x1dc`; whether return is always identity-equal to `obj`; per-caller ECX maps.

**Verdict:** **accept-with-gaps**.
