# Review B (skeptical / adversarial): `aa_004bb1c0` Object_ResolveCoidVtbl1e8_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bb1c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004bb1c0_Object_ResolveCoidVtbl1e8_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Identical to `Object_ResolveFromTFID` (`004bb950`) | That unit ends after Resolve; this adds `vtbl+0x1e8` | **Falsified** merge |
| 2 | Same as blob+`+0x1d4` (`004bb010`) | Free triple args + slot `+0x1e8` in bytes | **Falsified** merge |
| 3 | Same as GetIdentity / Lookup (`+0x1d8` / `+0x1dc`) | Slot is `+0x1e8` | **Falsified** merge |
| 4 | Pure “table lookup boolean” | Returns virtual result; callers use pointer chain after non-null | **Survives** as resolve+get; **falsifies** pure bool |
| 5 | `__stdcall` with no ECX | `RET 0xC` yes, but Resolve needs ECX; callers set `host+0xe4e8`; body preserves it | **Survives** as ECX passthrough thiscall-class |
| 6 | Takes TFID blob* like `004bb010` | Body loads three separate stack dwords; no `+8` byte unpack | **Falsified** blob form |

---

## 2. Live ≡ raw ≡ bytes

Live decompile matches raw 2026-07-23 body and `read_memory` hex. Callers list matches `get_function_callers` (9). Sole direct callee `0x004bae70`. Call-site at `0x004cdcc0` seals ECX = `[host+0xe4e8]`.

---

## 3. Surviving contract

```
// ECX = resolve ctx (caller)
// (bGlobal, coidLo, coidHi) → ResolveObjectTarget
// if null → 0 else → obj->vtbl[0x1e8]()
// RET 0xC
```

**Gaps kept:** product name of `+0x1e8`; whether return is always identity-equal to `obj`.

**Verdict:** **accept-with-gaps**.
