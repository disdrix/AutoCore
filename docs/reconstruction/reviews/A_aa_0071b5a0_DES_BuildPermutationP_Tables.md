# Review A (reconstruction fidelity): `aa_0071b5a0` DES_BuildPermutationP_Tables

| Field | Value |
|---|---|
| **Stable ID** | `aa_0071b5a0` |
| **VA** | `0x0071b5a0` |
| **Canonical name** | `DES_BuildPermutationP_Tables` |
| **System** | auth |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) — OWN-ONLY W19-Q |
| **Counterpart** | `reviews/B_aa_0071b5a0_DES_BuildPermutationP_Tables.md` |
| **Tools** | Ghidra `decompile_function`, `read_memory` (own VA + DAT tables); no `disassemble_bytes`; no Launcher |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra MCP `decompile_function` @ `0x0071b5a0` |
| Entry bytes | `read_memory` @ `0x0071b5a0` len 80 (`rep stosd` clear) |
| P table | `read_memory` @ `0x00afcd48` — FIPS P 32 bytes |
| Masks | `read_memory` @ `0x00afcd68` — 0x80..0x01 dwords |
| BSS banks | `read_memory` @ `0x00d11658` — zeros |
| Xrefs | `get_function_xrefs` → sole `DES_InitializeCipher` |
| Raw / annotated / clean / record | see function record |
| Consumer dual (context) | `DES_CalculatePermutationP` A/B (W19 prior) |

Three-rep **present and sealed this pass**.

---

## 2. Purpose (from unit)

DES init helper: **zero then fill** the four 256×4 P-permutation contribution banks that `DES_CalculatePermutationP` OR-indexes by S-box output bytes. Source specification is the static FIPS P vector at `DAT_00afcd48`.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Clear 0x400 dwords @ `DAT_00d11658` | **High** | decompile loop + `b9 00 04 00 00; bf 58 16 d1 00; f3 ab` |
| Outer bank loop `local_c` 0..0x3ff step 0x100 / `local_4` 0..3 | **High** | body |
| Mid loop input byte 0..0xff | **High** | body |
| Inner bit walk 0..31 unrolled ×4 | **High** | local_8/uVar5/uVar8/uVar6 step +4; bound `< 0x21` |
| P table @ `0xafcd48` is FIPS P | **High** | exact 32-byte match to FIPS 46-3 P |
| Mask table @ `0xafcd68` | **High** | 0x80..0x01 |
| Output banks empty offline | **High** | BSS zero |
| Sole caller `DES_InitializeCipher` | **High** | xrefs |
| Clean ≡ raw ≡ live CF | **High** | sealed this pass |
| Post-init bank contents bit-exact vs hand P | **Open** | no runtime dump |
| Product C++ name | **Inferred-high** | role from tables+consumer; not a string label |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| Zero 0x400 dwords @ d11658 | **Yes** (clean ≡ raw ≡ live) |
| bank loop local_c / local_4 | **Yes** |
| inByte loop 0..0xff | **Yes** |
| bit quartet unroll + four conditional ORs | **Yes** |
| return void | **Yes** |

---

## 5. Gaps

1. No post-`DES_InitializeCipher` dump of the four banks — cannot prove every row ≡ classic bit-walk P without runtime.
2. Sibling `FUN_0071bdd0` (S-box builder) not dualled in this OWN set (owned by other partition).
3. First unrolled leg address form `uVar5+0xafcd47` is decompiler quirk; sealed equivalent to `P[local_8]` for quartet starts.
4. Bit-for-bit / FIPS vector tests deferred (no Launcher).

**Verdict:** **accept-with-gaps**
