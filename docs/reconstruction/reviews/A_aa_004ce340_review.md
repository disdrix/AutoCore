# Review A (reconstruction fidelity): `aa_004ce340` CVOGCharacter_WeaponAllowsKillXpBonus

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ce340` |
| **VA** | `0x004ce340` |
| **Canonical name** | `CVOGCharacter_WeaponAllowsKillXpBonus` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw / listing) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004ce340_CVOGCharacter_WeaponAllowsKillXpBonus.md` |
| Annotated | `docs/reconstruction/raw/aa_004ce340_CVOGCharacter_WeaponAllowsKillXpBonus.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGCharacter_WeaponAllowsKillXpBonus.cpp` |
| Function record | `docs/reconstruction/functions/aa_004ce340_CVOGCharacter_WeaponAllowsKillXpBonus.md` |
| Listing | Ghidra `disassemble_function` (not `disassemble_bytes`) @ `0x004ce340` |

---

## 2. Signature

| Claim | Evidence | Match |
|---|---|---|
| `__thiscall`, ECX = object | Listing: all loads from `[ECX+…]`; signature reports `param_count: 0` (no stack args) | **Yes** |
| Returns bool in AL | `MOV AL,1` / `XOR AL,AL` then `RET` | **Yes** |
| Clean `bool __thiscall …(void* thisObject)` | Preserves convention; drops Ghidra `uint3`/`CONCAT31` noise | **Yes** (behavior) |

---

## 3. Control flow

| Stage | Raw / listing | Clean | Match |
|---|---|---|---|
| `this+0xa0` non-null | `LEA EAX,[ECX+0xa0]; TEST; JZ fail` | Same check | **Yes** |
| `*(char*)(this+0x100) == 0` | `CMP byte [ECX+0x100],0; JNZ fail` | Same | **Yes** |
| `*(int*)(this+0xac) != 2` | `CMP dword [ECX+0xac],2; JZ fail` | Same | **Yes** |
| Success / fail returns | AL=1 / AL=0 | `true` / `false` | **Yes** |
| No callees | Listing: 0 calls | Clean: no calls | **Yes** |

---

## 4. State mutations

**None.** Pure predicate on two fields (+ null-ish LEA check). No writes.

---

## 5. Open questions (fidelity scope)

1. Exact C++ type of `this` (Character vs client-mode object) — not required for CF fidelity.
2. Semantic meaning of mode `2` and flag `+0x100` — naming gap, not a clean/raw mismatch.
3. Callers that appear as zero-arg calls rely on ECX already holding the object; clean documents this.

---

## 6. Verdict rationale

Clean preserves the three-way gate and return polarity. Minor gap: object type still INFERRED. **accept-with-gaps.**
