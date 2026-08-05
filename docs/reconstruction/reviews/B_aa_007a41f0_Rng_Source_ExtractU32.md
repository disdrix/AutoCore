# Review B (skeptical / adversarial): `aa_007a41f0` Rng_Source_ExtractU32

| Field | Value |
|---|---|
| **Stable ID** | `aa_007a41f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W21-L) |
| **Counterpart** | `reviews/A_aa_007a41f0_Rng_Source_ExtractU32.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This selects a loot vector element / weighted pick | **Falsified** — 7 bytes, no table base/count args |
| 2 | Decompile is complete (`call extract; return`) | **Falsified** — bytes require `[ecx+0x14]` then **jmp** |
| 3 | ECX is the MT state itself | **Falsified** — ECX is source; state at +0x14 loaded to EAX |
| 4 | Tail target is not `00424830` | **Falsified** — rel32 lands on sealed extract |
| 5 | Clean invents temper constants | **Falsified** — temper lives in callee only |
| 6 | Many callers beyond loot | **Falsified** — Ghidra callers list only `005e1030`, `005e1150` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Adapter-only role | **High** | Wrong loot port (implement pick here) |
| +0x14 state offset | **High** | RNG reads wrong memory |
| Dependency on sealed extract | **High** | Divergent temper if reimplemented here |
| Loot integration semantics | Medium | Parent decompile SEH pollution |

---

## 3. Cross-check against raw + bytes

```
mov eax, [ecx+0x14]
jmp Rng_Mt19937_Extract   ; 0x00424830
```

Clean must **not** embed MT temper, twist, or loot indexing.

Prior loot dual notes that treated `007a41f0` as “pick remaining” are **partially wrong**: this unit only supplies entropy; pick math is in the parent (or via RandomUnitScalar + parent).

---

## 4. Surviving contract for AutoCore

```csharp
// Port of Rng_Source_ExtractU32
uint Rng_Source_ExtractU32(RngSource source)
{
    return Rng_Mt19937_Extract(source.MtStateAtPlus0x14);
}
// Do not implement loot indexing inside this function.
```

---

## 5. Open questions

1. Whether server loot should share this exact MT stream or a different PRNG.
2. Field name at +0x14 in product source.

**Verdict:** **accept**
