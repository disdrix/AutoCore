# Review A (reconstruction fidelity): `aa_0042b450` BitStream_GrowForBits

| Field | Value |
|---|---|
| **Stable ID** | `aa_0042b450` |
| **VA** | `0x0042b450` |
| **Canonical name** | `BitStream_GrowForBits` |
| **System** | `network-bitstream` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0042b450_BitStream_GrowForBits.md` |
| **Verdict** | **accept** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_0042b450_BitStream_GrowForBits.md` |
| Raw | `docs/reconstruction/raw/aa_0042b450_FUN_0042b450.md` |
| Annotated | `docs/reconstruction/raw/aa_0042b450_FUN_0042b450.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/BitStream_GrowForBits.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0042b450.cpp` |
| Seal tools | Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (no `disassemble_bytes`) |

---

## 2. Purpose (from unit)

Grow BitStream buffer for additional write bits: compute NewSize with +0x5DC slack, realloc if owned, update bit capacities, return bool.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| EDI = BitStream* this | **High** | `unaff_EDI`; writeBits/writeFlag load EDI=this |
| ECX = extraBits | **High** | writeBits: `bitPos+count-cap`; writeFlag: `1` |
| AL = success bool | **High** | `MOV AL,1` / `XOR AL,AL` |
| NewSize = `((extra+cap+7)>>3)+0x5DC` | **High** | LEA/SHR/ADD sealed |
| Decompiler `>>` parens wrong | **High** | C text vs LEA order |
| +0x14 owns-buffer gate | **High** | `CMP byte [edi+0x14],0` |
| Fail sets +0x1c=1, returns 0 | **High** | |
| Success sets +0x2c/+0x30 = NewSize*8 | **High** | |
| realloc via IAT 0x009C650C | **High** | decomp name + cdecl pushes |
| No NULL check after realloc | **High** | stores EAX unconditionally |
| Control flow clean ≡ bytes | **High** | named plate; twin keeps decomp surface |
| Bit-for-bit / runtime / differential | **Open** | Deferred |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| Compute NewSize from ECX+bitCap | **Yes** (bytes) |
| alloc < NewSize → try grow | **Yes** |
| owns → realloc + caps + return 1 | **Yes** |
| !owns or alloc≥NewSize → stamp +0x10, error, return 0 | **Yes** |
| No other branches | **Yes** (76 B body) |

---

## 5. Gaps

1. Product/TNL symbol name open (`GrowForBits` is role name).
2. Soft meaning of “alloc ≥ NewSize still fails” (defensive; normal path always needs grow).
3. Live realloc-failure / fixed-buffer experiments.
4. Sibling writeBits/writeFlag duals already reference this unit; no need to re-own them.

**Verdict:** **accept** — ABI, formula, and grow/fail CF sealed High from bytes.
