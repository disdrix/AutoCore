# Review B (adversarial): `aa_004cbfc0` Vector_InsertN_0x10

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cbfc0` |
| **VA** | `0x004cbfc0`–`0x004cc21c` |
| **Canonical name** | `Vector_InsertN_0x10` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Adversarial / gap hunter (OWN-ONLY W25-M) |
| **Counterpart** | `reviews/A_aa_004cbfc0_Vector_InsertN_0x10.md` |
| **Verdict** | **accept** |

---

## Attack surface

| Claim under test | Attack | Result |
|---|---|---|
| Element size 0x8 / 0x4 | all counts use `>>4` / `*0x10` | **Reject** — 16 B |
| Custom container not STL | throw string exact `"vector<T> too long"` | **Reject** — STL vector |
| thiscall missing | `mov esi,ecx` + field via ESI | **Reject** |
| Always realloc | capacity branch before new[] | **Reject** — in-place paths exist |
| operator_delete noreturn | pointer updates after delete in decomp | **Reject** — Ghidra false warning |
| TFID-only type | multi-caller (wake skill + others) | **Name stays generic** Vector_InsertN_0x10 |

---

## Residual risks

1. **In-place branch fidelity** depends on helper duals (`FUN_004cb2e0`, `FUN_0051b6e0`, `FUN_0041d5a0`) — roles sealed by call shape, not full named bodies.  
2. **Value lifetime**: stack snapshot of 4 dwords means caller's value* need not outlive insert after entry — correct for MSVC insert.  
3. **Empty buffer**: begin==0 treated as size/cap 0 — sealed in decomp.

---

## Port foot-guns

- Preserve **0x10** stride and **+4/+8/+0xc** layout (not `std::vector` MSVC12+ where begin is often `+0`). This binary's vector object has an extra leading field/unused at +0 from this function's perspective.  
- Port must keep **1.5×** grow and **max 0x0fffffff** elements.  
- Do not fold into "append only" — insertAt may be interior.

---

## Verdict

**accept** — adversarial review finds no CF/ABI contradiction. Product T English remains the only material gap and is intentionally not over-claimed.
