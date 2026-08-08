# Review B (skeptical / adversarial): `aa_0051f880` Object_SetHostModeFlag_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051f880` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY WQ9F-I dual B) |
| **Counterpart** | `reviews/A_aa_0051f880_Object_SetHostModeFlag_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Body does more than a store (validate / notify / net dirty) | **Falsified** — 13 B leaf; only load/store/ret |
| 2 | `__cdecl` / no stack cleanup | **Falsified** — `C2 04 00` seals `ret 4` |
| 3 | Flag lives at `+0x6b9` (confuse with enhanced twin) | **Falsified** — imm `0x6b8` in opcode |
| 4 | Sole writers are skill HB | **Partial** — only 2 static xrefs known; dynamic call risk open, not denied |
| 5 | Name is product-confirmed "host mode" | **Overstated** — role High from readers; spelling `_Inferred` |
| 6 | Ghidra empty prototype is authoritative | **Noise** — trust decomp body + bytes |
| 7 | Arg is full dword store | **Falsified for store width** — `mov al` byte path; stack slot still 4 B |
| 8 | Same as enhanced-state flag | **Falsified** — distinct offset; dual polarity with `+0x6b9` |
| 9 | FireTail sets target FX attach flag English | **Over-read** — store only; English from readers not HB body |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ABI thiscall + ret 4 + byte store | **High** | Stack/offset port break |
| Offset `+0x6b8` | **High** | Wrong flag field |
| Role = host-mode / vehicle-host gate | **High** | Misname only if role wrong |
| Product spelling | **Medium** | Naming |
| Exhaustive writers | **Medium** | Miss alternate writers |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
raw/live decompile:
  *(this + 0x6b8) = param_2; return;

bytes:
  8A 44 24 04  88 81 B8 06 00 00  C2 04 00

callers:
  00578c78 in Skill_HB_FireTail: push 1
  00578dd1 in Skill_HB_OnEnd:    push 0
```

Clean **must not**:
- invent null-`this` guards,
- widen store to dword without evidence,
- fold parent ResolveTarget / `vtbl+0x210` into this leaf,
- claim sole-writer exclusivity beyond known xrefs,
- promote product English without PDB/string on this VA.

---

## 4. Surviving contract for AutoCore

```csharp
// Retail aa_0051f880 — Object_SetHostModeFlag_Inferred
// thiscall: this in ECX, fHostMode on stack. ret 4. void.
void SetHostModeFlag(ClonedObject* self, byte fHostMode)
{
    *(byte*)((byte*)self + 0x6B8) = fHostMode;
}
```

---

## 5. Verdict

Adversarial pass **confirms** A on CF/ABI/offset; product spelling remains inferred; writer catalog open → **accept-with-gaps**.
