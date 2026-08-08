# Review A (reconstruction fidelity): `aa_00941f50` Client_UseInventoryItemByCoid

| Field | Value |
|---|---|
| **Stable ID** | `aa_00941f50` |
| **VA** | `0x00941f50` |
| **Canonical name** | `Client_UseInventoryItemByCoid` |
| **Review date** | `2026-08-04` (WQ8R-I dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00941f50_Client_UseInventoryItemByCoid.md` |
| **System** | inventory-transfer / skills-abilities |
| **Scratch** | `tmp/a_00941f50.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Client helper: **cargo-grid FindItemByCoid → Client_UseInventoryItem_Inferred**. Bridges UI/scripts that hold item COIDs into the sealed use/equip pipeline (including **C2S 0x2045** skill-use arm).

WQ-008 residual: UI/skill-adjacent inventory consumer.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | Ghidra `batch_decompile` `0x00941f50` |
| Full body image | `read_memory` 96B @`0x00941f50` — entire function + pad |
| Xref | `get_function_xrefs` / `get_assembly_context` @`0x0086152C` |
| Downstream dual | `Client_UseInventoryItem_Inferred` `aa_00941d50` (0x2045 sealed) |
| Grid plate | Collect/Drop: cargo = `char+0x250` host, `host+0x2B0` grid |
| Raw / clean / record | updated WQ8R-I |

**Not performed:** `disassemble_bytes`; Launcher runtime; defining orphan UI function in Ghidra.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| EAX = client (`mov esi,eax`) | **High** | entry bytes + call site loads `DAT_00D1A840` into EAX |
| `ret 0x0C` three stack args | **High** | all exits |
| Null char / null host → AL=0 | **High** | early outs |
| `(coidLo & coidHi) == -1` → AL=0 | **High** | `and`/`cmp -1`/`xor al,al` |
| **Not** `return host & 0xffffff00` | **High** | decompiler wrong; bytes clear AL |
| ECX Find = `*(host+0x2B0)` cargo | **High** | `mov ecx,[eax+0x2B0]` |
| Tail `00941d50` with EDI=item ESI=client | **High** | `mov edi,eax; push mode; call` |
| Sole static CALL `0x0086152C` | **High** | xrefs |
| Skill-bit gate at call site | **High** | `cloneMeta+0x3F2` shr7 test1 |
| Name | **Probable** | structure; no PDB |
| Find-null → Use(EDI=0) | **Gap** | no check in this leaf |
| Runtime / bit-exact | **Open** | |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Client/char/host guards | **Yes** |
| Invalid COID → 0 | **Yes** (bytes correct decompiler) |
| Cargo FindItemByCoid | **Yes** |
| UseInventoryItem tail | **Yes** |

---

## 5. Gaps

1. Orphan UI function body containing `0x0086152C` not defined in Ghidra (site sealed; owner CF partial).
2. Null item after Find.
3. PDB/product symbol.
4. Runtime wire of resulting 0x2045 path (owned by `aa_00941d50` dual).

**Verdict:** **accept-with-gaps** — full leaf ABI + cargo COID→use path **sealed**.
