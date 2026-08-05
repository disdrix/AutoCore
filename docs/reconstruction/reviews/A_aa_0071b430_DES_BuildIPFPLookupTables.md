# Review A (reconstruction fidelity): `aa_0071b430` DES_BuildIPFPLookupTables

| Field | Value |
|---|---|
| **Stable ID** | `aa_0071b430` |
| **VA** | `0x0071b430`–`0x0071b59d` exclusive (**365** B) |
| **Canonical name** | `DES_BuildIPFPLookupTables` |
| **Prior / alias** | `FUN_0071b430` |
| **Review date** | `2026-07-29` (W25-Q OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_0071b430_DES_BuildIPFPLookupTables.md` |
| **System** | auth / DES |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `get_function_by_address`, callers (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**DES IP/FP nibble LUT builder** (init-only):

1. Zero `dst` for **0x200 dwords** (**0x800** bytes).
2. Expand a 64-entry 1-based FIPS perm vector into nibble-indexed 8-byte OR-contribution rows.
3. Called twice from `DES_InitializeCipher`: IP (`DAT_00d16ef0` ← `DAT_00afca50`) then FP (`DAT_00d12690` ← `DAT_00afca90`).
4. Leaf — no callees. Consumer is `DES_PermuteBlock`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0071b430_FUN_0071b430.md` (+ W25-Q append) |
| Annotated | `docs/reconstruction/raw/aa_0071b430_FUN_0071b430.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/DES_BuildIPFPLookupTables.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_0071b430.cpp` |
| Function record | `docs/reconstruction/functions/aa_0071b430_DES_BuildIPFPLookupTables.md` |
| Live decompile | ≡ raw (triple loop + four OR legs) |
| Live body bytes | `read_memory` @ `0x0071b430` / epilogue @ `0x0071b580` |
| IP / FP / masks | `read_memory` @ `0x00afca50`, `0x00afca90`, `0x00afcd68`, `0x00afcd88` |
| Parent dual | `aa_0071c000` DES_InitializeCipher |

---

## 3. Byte seal (`read_memory`)

| Claim | Evidence | Conf |
|---|---|---|
| Clear `ecx=0x200` dwords | entry `b9 00 02 00 00` | **High** |
| Bare `ret` after `add esp,8` | epilogue `83 c4 08 c3` | **High** |
| Body span 365 B | meta exclusive end `0071b59d` | **High** |
| IP table FIPS | 64 B exact match | **High** |
| FP table FIPS | 64 B exact match | **High** |
| Masks 0x80..0x01 / 0x08..0x01 | dwords at afcd68 / afcd88 | **High** |
| Decompile ≡ raw ≡ CF intent | three-rep match | **High** |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Zero 0x200 dwords | **Yes** |
| Outer local_4 / iVar4 step 0x10 < 0x100 | **Yes** |
| Mid uVar6 0..15 | **Yes** |
| Inner 64 bits unrolled ×4 | **Yes** |
| Four conditional OR legs | **Yes** |
| Void return; no callees | **Yes** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF algorithm | **High** | sealed three-rep |
| Role = IP/FP LUT **builder** (not apply) | **High** | init-only + consumer |
| FIPS IP/FP source identity | **High** | `read_memory` |
| ABI 2-arg cdecl | **High** | bare ret |
| Product English / PDB spelling | **Low–Med** | role-based name |
| Filled bank ≡ independent expand | **Open** | needs post-init dump |

---

## 6. Gaps

1. No post-`DES_InitializeCipher` dump of `d16ef0` / `d12690` for full KAT.
2. Product/PDB symbol spelling residual.
3. Runtime / bit-exact / differential — open (no Launcher).

**Verdict:** **accept-with-gaps** — CF, FIPS sources, clear size, ABI, sole-caller sealed; bank dump residual.
