# Review B (skeptical / adversarial): `aa_0051f890` Object_SetEnhancedStateFlag_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051f890` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W28-G dual B) |
| **Counterpart** | `reviews/A_aa_0051f890_Object_SetEnhancedStateFlag_Inferred.md` |
| **Scratch** | `docs/reconstruction/tmp/a_0051f890.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Body does more than a store (validate / notify) | **Falsified** — 13 B leaf; only load/store/ret |
| 2 | `__cdecl` / no stack cleanup | **Falsified** — `C2 04 00` seals `ret 4` |
| 3 | Flag lives at a different offset | **Falsified** — imm `0x6b9` in opcode |
| 4 | Sole writer is ActivatePlayer | **Partial** — second CALL @ `0x0062667b` (clear); containing fn undefined |
| 5 | Name is product-confirmed | **Overstated** — role High from strings/readers; spelling `_Inferred` |
| 6 | Ghidra `undefined FUN_(void)` signature is authoritative | **Noise** — trust decomp body + bytes, not empty prototype |
| 7 | Arg is full dword | **Falsified for store width** — `mov al` byte path; stack slot still 4 B |
| 8 | Enhanced == vehicle only | **Over-read** — prompt says "enhanced state"; multi-system gate |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ABI thiscall + ret 4 + byte store | **High** | Stack/offset port break |
| Offset `+0x6b9` | **High** | Wrong flag field |
| Role = enhanced-state gate | **High** | Misname only if role wrong |
| Product spelling | **Medium** | Naming |
| Exhaustive writers | **Medium** | Miss clear path |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
raw/live decompile:
  *(this + 0x6b9) = param_2; return;

bytes:
  8A 44 24 04  88 81 B9 06 00 00  C2 04 00

callers:
  00626916 in FUN_00626890: push 1
  0062667b: push 0 (no function delimitation)
```

Clean **must not**:
- invent null-`this` guards,
- widen store to dword without evidence,
- fold parent TFID / HB enqueue into this leaf,
- claim sole-writer exclusivity while `0x0062667b` exists.

---

## 4. Surviving contract for AutoCore

```csharp
// Retail aa_0051f890 — Object_SetEnhancedStateFlag_Inferred
// thiscall: this in ECX, fEnhanced on stack. ret 4. void.
void SetEnhancedStateFlag(ClonedObject* self, byte fEnhanced)
{
    *(byte*)((byte*)self + 0x6B9) = fEnhanced;
}
```

---

## 5. Verdict

Adversarial pass **confirms** A on CF/ABI/offset; product spelling remains inferred. Second clear-site is documented, not denied → **accept**.
